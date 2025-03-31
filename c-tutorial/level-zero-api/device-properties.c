#include <stdio.h>
#include <stdlib.h>
#include <level_zero/ze_api.h>

int main() {
  // Step 1: Initialize the Level Zero driver
  ze_result_t result = zeInit(0); // 0 means default initialization
  if(result != ZE_RESULT_SUCCESS) {
    printf("Failed to initialize Level Zero API!\n");
    return 1;
  }
  printf("Level Zero API initialized successfully.\n");

  // Step 2: Discover the available Level Zero drivers
  uint32_t driverCount = 0;
  result = zeDriverGet(&driverCount, NULL); // Query the number of available drivers
  if(result != ZE_RESULT_SUCCESS || driverCount == 0) {
    printf("No Level Zero drivers found!\n");
    return 1;
  }
  printf("Number of Level Zero drivers found: %u\n", driverCount);

  // Step 3: Retrieve the driver handle
  ze_driver_handle_t driver;
  result = zeDriverGet(&driverCount, &driver); // Get the first driver
  if(result != ZE_RESULT_SUCCESS) {
    printf("Failed to get Level Zero driver!\n");
    return 1;
  }

  // Step 4: Discover the available devices under the driver
  uint32_t deviceCount = 0;
  result = zeDeviceGet(driver, &deviceCount, NULL);
  if(result != ZE_RESULT_SUCCESS || deviceCount == 0) {
    printf("No Level Zero devices found!\n");
    return 1;
  }
  printf("Number of Level Zero devices found: %u \n", deviceCount);

  // Step 5: Retrieve the device handle
  ze_device_handle_t device;
  result = zeDeviceGet(driver, &deviceCount, &device); // Get the first available device
  if(result != ZE_RESULT_SUCCESS) {
    printf("Failed to get Level Zero device!\n");
    return 1;
  }

  // Step 6: Get device properties
  ze_device_properties_t deviceProperties;
  deviceProperties.stype = ZE_STRUCTURE_TYPE_DEVICE_PROPERTIES; // Set structure type
  result = zeDeviceGetProperties(device, &deviceProperties);
  if(result != ZE_RESULT_SUCCESS) {
    printf("Failed to get device properties!\n");
    return 1;
  }

  // Print some properties of the selected device
  printf("Device Name: %s\n", deviceProperties.name);
  printf("Device Type: %u (1=GPU, 2=FPGA, 3=CPU, 4=Other)\n", deviceProperties.type);
  printf("Device ID: 0x%x\n", deviceProperties.deviceId);
  printf("Vendor ID: 0x%x\n", device Properties.vendorId);
  return 0;
}
