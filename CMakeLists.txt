cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(DeepProject)

LIST(APPEND CMAKE_PREFIX_PATH "/home/slam-emix/Workspace/lib/libtorch/share/cmake/Torch")

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

find_package(OpenCV REQUIRED)


include_directories(
  include
  ${TORCH_INCLUDE_DIRECTORIES}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(deep_app src/resnet18_test.cpp)
target_link_libraries(deep_app ${TORCH_LIBRARIES} ${OpenCV_LIBS})
set_property(TARGET deep_app PROPERTY CXX_STANDARD 14)
