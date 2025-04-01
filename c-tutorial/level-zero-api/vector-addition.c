#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <level_zero/ze_api.h>

// Simple kernel source (SPIR-V binary would be loaded here in a real example)
const char* kernel_source = R"(
__kernel void vector_add(__global const int* a, __global const int* b, __global int* c) {
  int id = get_global_id(0);
  c[id] = a[id] + b[id];
}
)";

#define ARRAY_SIZE 1024

int main(){
  // Step 1: Initialize the Level Zero API
  zeInit(0);

  // Step 2: Get the driver
  uint32_t deviceCount = 0;
  zeDriverGet(&driverCount, NULL);
  ze_driver_handle_t driver;
  zeDriverGet(&driverCount, &driver);

  // Step 3: Get the first available GPU device
  uint32_t deviceCount = 0;
  zeDeviceGet(driver, &deviceCount, NULL);
  ze_device_handle_t device;
  zeDeviceGet(driver, &deviceCount, &device);

  // Step 4: Create a context for managing memory allocations
  ze_context_desc_t contextDesc = {ZE_STRUCTURE_TYPE_CONTEXT_DESC, NULL, 0);
  ze_context_handle_t context;
  zeContextCreate(driver, &contextDesc, &context);

  // Step 5: Create a command queue and command list
  ze_command_queue_desc_t queueDesc = {
    ZE_STRUCTURE_TYPE_COMMAND_QUEUE_DESC,
    NULL,
    0, // ordinal
    0, // index
    ZE_COMMAND_QUEUE_MODE_ASYNCHRONOUS,
    ZE_COMMAND_QUEUE_PRIORITY_NORMAL
  };

  ze_command_queue_handle_t commandQueue;
  zeCommandQueueCreate(context, device, &queueDesc, &commandQueue);
  ze_command_list_desc_t listDesc = {ZE_STRUCTURE_TYPE_COMMAND_LIST_DESC, NULL, 0};
  ze_command_lsit_handle_t commandList;
  zeCommandListCreate(context, device, &listDesc, &commandList);

  // Step 6: Allocate device memory for arrays
  size_t dataSize = ARRAY_SIZE * sizeof(int);
  ze_device_mem_alloc_desc_t allocDesc = {ZE_STRUCTURE_TYPE_DEVICE_MEM_ALLOC_DESC, NULL, 0, 0};

  int *d_a, *d_b, *d_c;
  zeMemAllocDevice(context, &allocDesc, dataSize, 1, device, (void**)&d_a);
  zeMemAllocDevice(context, &allocDesc, dataSize, 1, device, (void**)&d_b);
  zeMemAllocDevice(context, &allocDesc, dataSize, 1, device, (void**)&d_c);

  // Step 7: Allocate host memory and initialize data
  int *h_a = (int*)malloc(dataSize);
  int *h_b = (int*)malloc(dataSize);
  int *h_c = (int*)malloc(dataSize);
  for (int i = 0; i < ARRAY_SIZE; i++) {
      h_a[i] = i;
      h_b[i] = i * 2;
  }

  // Step 8: Copy input data to the device
  zeCommandListAppendMemoryCopy(commandList, d_a, h_a, dataSize, NULL, 0, NULL);
  zeCommandListAppendMemoryCopy(commandList, d_b, h_b, dataSize, NULL, 0, NULL);
  zeCommandListClose(commandList);
  zeCommandQueueExecuteCommandList(commandQueue, 1, &commandList, NULL);
  zeCommandQueueSynchronize(commandQueue, UINT64_MAX);

  // Step 9: Load and create the kernel
  // In a real scenario, the SPIR-V binary should be loaded here
  // For simplicity, we assume the kernel is already compiled (not shown)
    
  // Placeholder: Normally, you would create a module and kernel from SPIR-V
  printf("Kernel would be executed here!\n");

  // Step 10: Copy results back from the device
  zeCommandListReset(commandList);
  zeCommandListAppendMemoryCopy(commandList, h_c, d_c, dataSize, NULL, 0, NULL);
  zeCommandListClose(commandList);
  zeCommandQueueExecuteCommandList(commandQueue, 1, &commandList, NULL);
  zeCommandQueueSynchronize(commandQueue, UINT64_MAX);

  // Step 11: Validate results
  int errors = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
      if (h_c[i] != (h_a[i] + h_b[i])) {
          errors++;
      }
  }
  printf("Validation %s\n", (errors == 0) ? "PASSED!" : "FAILED!");

  // Step 12: Cleanup resources
  free(h_a);
  free(h_b);
  free(h_c);
  zeMemFree(context, d_a);
  zeMemFree(context, d_b);
  zeMemFree(context, d_c);
  zeCommandListDestroy(commandList);
  zeCommandQueueDestroy(commandQueue);;
  zeContextDestroy(context);
  
  return 0;
}
