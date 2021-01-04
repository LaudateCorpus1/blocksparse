
#ifndef GET_CUSTREAM
#define GET_CUSTREAM
#include "tensorflow/core/framework/op_kernel.h"
#include <cuda.h>

using namespace tensorflow;

CUstream get_custream(OpKernelCtx* ctx);

#endif // GET_CUSTREAM