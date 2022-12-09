TENSORRT="/home/slam-emix/Workspace/lib/TensorRT-8.5.1.7/lib"
LIB_TORCH="/home/slam-emix/Workspace/lib/libtorch/lib"
TORCH_TENSORRT="/home/slam-emix/Workspace/lib/torch_tensorrt/lib"
CUDA="/usr/local/cuda-11.7/lib64"
#LD_LIBRARY_PATH=$TENSORRT:$LIB_TORCH:$TORCH_TENSORRT:$CUDA:$LD_LIBRARY_PATH

# Minimal path needed to it to work
LD_LIBRARY_PATH=$TORCH_TENSORRT:$LD_LIBRARY_PATH:$TENSORRT

# For cuda memory optimization
CUDA_MODULE_LOADING=LAZY