FROM tensorflow/tensorflow:1.15.2-gpu-py3
# FROM tensorflow/tensorflow:custom-op-gpu-ubuntu16
# FROM tensorflow/tensorflow:custom-op-gpu-ubuntu16
RUN pip install --upgrade pip
# RUN pip3 install tensorflow-gpu==1.15.2

# Need this to run the tests
RUN pip3 install networkx==2.5


# Hacks link CUDA libraries correctly
# SEE: https://github.com/tensorflow/tensorflow/issues/34428
RUN mkdir -p /usr/local/lib/python3.6/dist-packages/tensorflow_core/include/third_party/gpus/cuda/
RUN ln -s /usr/local/cuda/include /usr/local/lib/python3.6/dist-packages/tensorflow_core/include/third_party/gpus/cuda/



# ENV NCCL_VERSION=2.4.8-1+cuda10.0
# RUN apt-get update && apt-get install -y --no-install-recommends \
#   mpich \
#   libmpich-dev \
#   libnccl2=${NCCL_VERSION} \
#   libnccl-dev=${NCCL_VERSION} \
#   curl

# Make sure the linker knows where to look for things
ENV LD_LIBRARY_PATH="/usr/local/lib:${LD_LIBRARY_PATH}"
