FROM tensorflow/tensorflow:1.15.2-gpu-py3
RUN pip install --upgrade pip

# Need this to run the tests
RUN pip3 install networkx==2.5

# Hacks link CUDA libraries correctly
# SEE: https://github.com/tensorflow/tensorflow/issues/34428
RUN mkdir -p /usr/local/lib/python3.6/dist-packages/tensorflow_core/include/third_party/gpus/cuda/
RUN ln -s /usr/local/cuda/include /usr/local/lib/python3.6/dist-packages/tensorflow_core/include/third_party/gpus/cuda/


ENV NCCL_VERSION=2.4.8-1+cuda10.0
RUN apt-get update && apt-get install -y --allow-downgrades --no-install-recommends \
  mpich \
  libmpich-dev \
  libnccl2=${NCCL_VERSION} \
  libnccl-dev=${NCCL_VERSION}

# Need this to run tests, needs to come after we install the mpich and libmpich-dev stuff above
RUN pip3 install mpi4py==3.0.3

# Make sure the linker knows where to look for things
ENV LD_LIBRARY_PATH="/usr/local/lib:${LD_LIBRARY_PATH}"
