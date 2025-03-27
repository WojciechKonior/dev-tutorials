#define CL_USE_DEPRECATED_OPENCL_2_0_APIS

#include <CL/cl.hpp>

__kernel void function(__global int* data){
  data[get_global_id(0)] *= 2*get_local_id(0);
}

int main(){
  std::vector<cl::Platform> platforms;
  cl::Platform::get(&platforms);

  _ASSERT(platforms.size() > 0);

  auto platform = platforms.front();
  std::vector<cl::Device> devices;
  platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);

  __ASSERT(devices.size() > 0);

  auto device = devices.front();
  auto vendor = device.getInfo<CL_DEVICE_VENDOR>();
  auto version = device.getInfo<CL_DEVICE_VERSION>();

  device = devices[1];
  vendor = device.getInfo<CL_DEVICE_VENDOR>();
  version = device.getInfo<CL_DEVICE_VERSION>();
}
