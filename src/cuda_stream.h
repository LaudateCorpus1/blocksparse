// SUPER HACKY, replicate https://github.com/petewarden/tensorflow_makefile/blob/master/tensorflow/stream_executor/cuda/cuda_stream.h
// since it was removed after 1f 1.13.x
#if TF_NEW

#include <cuda.h>

// TODO: super hacky,
// Works based on:
//   - https://github.com/petewarden/tensorflow_makefile/blob/master/tensorflow/stream_executor/cuda/cuda_stream.h
//   - https://github.com/tensorflow/tensorflow/blob/master/tensorflow/core/util/gpu_kernel_helper.h#L86
//   - and because cudaStream_t is interchangeable with CUstream (https://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__DRIVER.html)
CUstream* get_custream(OpKernelContext* ctx) {
  const CUstream* ptr = CHECK_NOTNULL(reinterpret_cast<const CUstream*>(ctx->op_device_context()->stream()->implementation()->GpuStreamMemberHack()));
  
  return *ptr;
}

#else
#include "tensorflow/stream_executor/cuda/cuda_stream.h"

using perftools::gputools::cuda::CUDAStream;

CUstream* get_custream(OpKernelContext* ctx) {
  return ((CUDAStream*)ctx->op_device_context()->stream()->implementation())->cuda_stream();
}

#endif // TF_NEW