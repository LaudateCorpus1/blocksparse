
#ifndef GET_CUSTREAM
#define GET_CUSTREAM
#include "tensorflow/core/framework/op_kernel.h"
#include <cuda.h>

CUstream get_custream(tensorflow::OpKernelCtx* ctx);

#endif // GET_CUSTREAM