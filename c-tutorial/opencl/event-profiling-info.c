#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

// Define the size of the vectors
#define VECTOR_SIZE 1024

// OpenCL kernel for vector addition
const char *kernelSource = 
"__kernel void vector_add(__global const float *A, __global const float *B, __global float *C) { \n"
"  int id = get_global_id(0);  // Get index of this work-item\n"
"  C[id] = A[id] + B[id];      // Perform vector addition\n"
"}\n"

int main(){
  // Step 1: Initialize OpenCL
  cl_platform_id platform;
  cl_device_id device;
  cl_context context;
  cl_command_queue queue;
  cl_program program;
  cl_kernel kernel;
  cl_int err;

  // Get the first available OpenCL platform
  err = clGetPlatformIDs(1, &platform, NULL);
  if(err != CL_SUCCESS) { printf("Error: Failed to find a platform!\n"; return EXIT_FAILURE; }

  // Get the first available GPU device
  err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
  if(err != CL_SUCCESS) { printf("Error: Failed to find a GPU device!\n"); return EXIT_FAILURE; }

  // Create an OpenCL context
  context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
  if(!context) { printf("Error: Failed to create a context!\n"); return EXIT_FAILURE; }

  // Create a command queue with profiling enabled
  queue = clCreateCommandQueueWithProperties(context, device, (cl_queue_properties[]){CL_QUEUE_PROFILING_ENABLE, 0}, &err);
  if(!queue) { printf("Error: Failed to create a command queue!\n"); return EXIT_FAILURE; }

  //Step 2: Allocate and initialize host memory
  float *A = (float*)malloc(sizeof(float)*VECTOR_SIZE);
  float *B = (float*)malloc(sizeof(float)*VECTOR_SIZE);
  float *C = (float*)malloc(sizeof(float)*VECTOR_SIZE);
  for(int i = 0; i<VECTOR_SIZE; i++) {
    A[i] = i*1.0f;
    B[i] = i*2.0f;
  }

  // Step 3: Create OpenCL buffers
  cl_mem d_A = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * VECTOR_SIZE, A, &err);
  cl_mem d_B = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * VECTOR_SIZE, B, &err);
  cl_mem d_C = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(float) * VECTOR_SIZE, NULL, &err);

  // Step 4: Create and build OpenCL program
  program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, &err);
  clBuildProgram(program, 1, &device, NULL, NULL, NULL);
  kernel = clCreateKernel(program, "vector_add", &err);

  // Step 5: Set kernel arguments
  clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_A);
  clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_B);
  csSetKernelArg(kernel, 2, sizeof(cl_mem), &d_C);

  // Step 6: Define work size and execute kernel
  size_t globalSize = VECTOR_SIZE;
  cl_event kernel_event; // Event for profiling

  err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, &kernel_event);
  if(err != CL_SUCCESS) { printf("Error: Failed to execute kernel!\n"); return EXIT_FAILURE; }

  // Step 7a: Insert a marker event after the kernel execution
  cl_event marker_event;
  err = clEnqueueMarkerWithWaitList(queue, 1, &kernel_event, &marker_event);
  // err = clEnqueueMarker(queue, &marker_event);
  if (err != CL_SUCCESS) { print("Error: Failed to enqueue marker event!\n"); return EXIT_FAILURE; }
  
  // Step 7b: Wait for kernel to finish and measure time
  clWaitForEvents(1, &marker_event);

  // Query the profiling information
  cl_ulong start, end;
  clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &start, NULL);
  clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &start, NULL);

  double execution_time = (end - start) / 1e6; //Convert nanoseconds to milliseconds
  printf("Kernel execution time: %0.3f ms\n", execution_time);

  // Step 8: Read back results
  clEnqueueReadBuffer(queue, d_C, CL_TRUE, 0, sizeof(float) * VECTOR_SIZE, C, 0, NULL, NULL);

  // Print first 5 results for verification
  printf("Sample Results:\n");
  for(int i = 0; i<5; i++) {
    printf("C[%d] = %0.1f\n", i, C[i]);
  }

  // Step 9: Cleanup
  clReleaseEvent(kernel_event);
  clReleaseEvent(marker_event);
  clReleaseKernel(kernel);
  clReleaseProgram(program);
  clReleaseMemObject(d_A);
  clReleaseMemObject(d_B);
  clReleaseMemObject(d_C);
  clReleaseCommandQueue(queue);
  clReleaseContext(context);
  free(A);
  free(B);
  free(C);
  
  return EXIT_STATUS;
}
