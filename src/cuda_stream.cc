
#include "cuda_stream.h"


#if TF_NEW

#include "tensorflow/core/framework/op_kernel.h"
#include <cuda.h>

using namespace tensorflow;

// TODO: super hacky, need this because the old way of getting the CUDAStream (see else block) was removed after tf 1.13.x
// Works based on:
//   - https://github.com/petewarden/tensorflow_makefile/blob/master/tensorflow/stream_executor/cuda/cuda_stream.h
//   - https://github.com/tensorflow/tensorflow/blob/master/tensorflow/core/util/gpu_kernel_helper.h#L86
//   - and because cudaStream_t is interchangeable with CUstream (https://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__DRIVER.html)
CUstream get_custream(OpKernelContext* ctx) {
  const CUstream* ptr = reinterpret_cast<const CUstream*>(ctx->op_device_context()->stream()->implementation()->GpuStreamMemberHack());
  
  return *ptr;
}

#else
#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/stream_executor/cuda/cuda_stream.h"

using namespace tensorflow;
using perftools::gputools::cuda::CUDAStream;

CUstream get_custream(OpKernelContext* ctx) {
  return ((CUDAStream*)ctx->op_device_context()->stream()->implementation())->cuda_stream();
}
#endif // TF_NEW