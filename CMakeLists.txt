cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(DeepProject)

LIST(APPEND CMAKE_PREFIX_PATH "/home/slam-emix/Workspace/lib/libtorch/share/cmake/Torch")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
set(TensorRT_DIR "/home/slam-emix/Workspace/lib/TensorRT-8.5.1.7")

find_package(Torch REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CUDA REQUIRED)

message("Dirs = ${TensorRT_LIBRARIES}")

include_directories(
  include
  ${TORCH_INCLUDE_DIRECTORIES}
  ${OpenCV_INCLUDE_DIRS}
)

#############################################################

add_executable(torch_app 
src/resnet18_test.cpp
src/utils.cpp)
target_link_libraries(torch_app ${TORCH_LIBRARIES} ${OpenCV_LIBS} )
set_property(TARGET torch_app PROPERTY CXX_STANDARD 14)


find_package(TensorRT REQUIRED)
#find_package(torchtrt REQUIRED)
set(TorchTensorRT_INCLUDE_DIR "/home/slam-emix/Workspace/lib/torch_tensorrt/include")
set(TorchTensorRT_LIBS "/home/slam-emix/Workspace/lib/torch_tensorrt/lib/libtorchtrt.so;/home/slam-emix/Workspace/lib/torch_tensorrt/lib/libtorchtrt_plugins.so;/home/slam-emix/Workspace/lib/torch_tensorrt/lib/libtorchtrt_runtime.so")


#############################################################
add_executable(torchRT_app 
src/resnet18rt_test.cpp
src/utils.cpp)

target_include_directories(torchRT_app PUBLIC 
${TorchTensorRT_INCLUDE_DIR})

target_link_libraries(torchRT_app ${TORCH_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(torchRT_app -Wl,--no-as-needed /home/slam-emix/Workspace/lib/torch_tensorrt/lib/libtorchtrt_runtime.so )
target_link_libraries(torchRT_app
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_cpu.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_cuda.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_global_deps.so
/home/slam-emix/Workspace/lib/libtorch/lib/libbackend_with_compiler.so
/home/slam-emix/Workspace/lib/libtorch/lib/libc10.so
/home/slam-emix/Workspace/lib/libtorch/lib/libc10_cuda.so)
set_property(TARGET torchRT_app PROPERTY CXX_STANDARD 14)


#############################################################

add_executable(compiletorchRT_app 
src/optimization_resnet.cpp
src/utils.cpp)

target_include_directories(compiletorchRT_app PUBLIC 
${TorchTensorRT_INCLUDE_DIR})

target_link_libraries(compiletorchRT_app -Wl,--no-as-needed ${TORCH_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(compiletorchRT_app -Wl,--no-as-needed 
/home/slam-emix/Workspace/lib/torch_tensorrt/lib/libtorchtrt.so
/home/slam-emix/Workspace/lib/torch_tensorrt/lib/libtorchtrt_plugins.so)

target_link_libraries(compiletorchRT_app -Wl,--no-as-needed
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_cpu.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_cuda.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_global_deps.so
/home/slam-emix/Workspace/lib/libtorch/lib/libbackend_with_compiler.so
/home/slam-emix/Workspace/lib/libtorch/lib/libc10.so
/home/slam-emix/Workspace/lib/libtorch/lib/libc10_cuda.so)
set_property(TARGET torchRT_app PROPERTY CXX_STANDARD 14)

#############################################################
add_executable(yolo_app 
src/main_detect.cpp
src/detector.cpp
src/utils.cpp)

target_include_directories(yolo_app PUBLIC 
${TorchTensorRT_INCLUDE_DIR})

target_link_libraries(yolo_app ${TORCH_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(yolo_app -Wl,--no-as-needed /home/slam-emix/Workspace/lib/torch_tensorrt/lib/libtorchtrt_runtime.so )
target_link_libraries(yolo_app
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_cpu.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_cuda.so
/home/slam-emix/Workspace/lib/libtorch/lib/libtorch_global_deps.so
/home/slam-emix/Workspace/lib/libtorch/lib/libbackend_with_compiler.so
/home/slam-emix/Workspace/lib/libtorch/lib/libc10.so
/home/slam-emix/Workspace/lib/libtorch/lib/libc10_cuda.so)
set_property(TARGET yolo_app PROPERTY CXX_STANDARD 14)