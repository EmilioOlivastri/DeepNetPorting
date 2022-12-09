TENSORRT="/home/slam-emix/Workspace/lib/TensorRT-8.5.1.7/lib"
TORCH_TENSORRT="/home/slam-emix/Workspace/lib/torch_tensorrt/lib"

# Minimal path needed to it to work
LD_LIBRARY_PATH=$TORCH_TENSORRT:$LD_LIBRARY_PATH:$TENSORRT

# For cuda memory optimization
CUDA_MODULE_LOADING=LAZY