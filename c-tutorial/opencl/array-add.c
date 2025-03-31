#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

// OpenCL kernel that performs element-wize addition of two arrays
const char *kernelSource = 
"__kernel void vecAdd(__global float *A, __global float *B, __global float *C, int n) {"
"  int id = get_global_id(0);"
"  if (id < n) {"
"    C[id] = A[id] + B[id];"
"  }"
"}";

#define ARRAY_SIZE 1024

int main(){
  // Allocate memory for arrays
  float A[ARRAY_SIZE], B[ARRAY_SIZE], C[ARRAY_SIZE];
  for (int i = 0; i<ARRAY_SIZE; i++){
    A[i] = i*1.0f;
    B[i] = i*2.0f;
  }

  // Get platform and device information
  cl_platform_id platform;
  cl_device_id device;
  clGetPlatformIDs(1, &platform, NULL);
  clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);

  // Create an OpenCL context
  cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);

  // Create a command queue
  cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, 0, NULL);

  // Create memory buffers on the device
  cl_mem BufferA = clCreateBuffer(context, CL_MEM_READ_ONLY, ARRAY_SIZE * sizeof(float), NULL, NULL);
  cl_mem BufferB = clCreateBuffer(context, CL_MEM_READ_ONLY, ARRAY_SIZE * sizeof(float), NULL, NULL);
  cl_mem bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, ARRAY_SIZE * sizeof(float), NULL, NULL);

  // Copy data to device momory
  clEnqueueWriteBuffer(queue, bufferA, CL_TRUE, 0, ARRAY_SIZE * sizeof(float), A, 0, NULL, NULL);
  clEnqueueWriteBuffer(queue, bufferB, CL_TRUE, 0, ARRAY_SIZE * sizeof(float), B, 0, NULL, NULL);

  // Create a program from kernel source
  cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, NULL);
  clBuildProgram(program, 1, &device, NULL, NULL, NULL);

  // Create the openCL kernel
  cl_kernel kernel = clCreateKernel(program, "vecAdd", NULL);

  //Set kernel arguments
  clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
  clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferB);
  clSetKernelArg(kernel, 2, sizeof(cl_mem), &bufferC);
  clSetKernelArg(kernel, 3, sizeof(int), &ARRAY_SIZE);

  // Execute the kernel
  size_t global_size = ARRAY_SIZE;
  clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &global_size, NULL, 0, NULL, NULL);

  //Read the results from the device
  clEnqueueReadBuffer(queue, bufferC, CL_TRUE, 0, ARRAY_SIZE * sizeof(float), C, 0, NULL, NULL);

  // Print some results
  for(int i = 0; i<10; i++){
    print("C[%d] = %f\n", i, C[i]);
  }

  //Clean up
  clReleaseKernel(kernel);
  clReleaseProgram(program);
  clReleaseMemObject(bufferA);
  clReleaseMemObject(bufferB);
  clReleaseMemObject(bufferC);
  clReleaseCommandQueue(queue);
  clReleaseContext(context);
  return 0;
}
