cmake_minimum_required(VERSION 3.19)
project(Vehicle_Flow_Detection)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vehicle_Flow_Detection main.cpp cardetc.h vid2img.h)

set(SOURCE_FILES main.cpp vid2img.h)
add_executable(opencv3_demo ${SOURCE_FILES} vid2img.h)
find_package(OpenCV REQUIRED)
target_link_libraries(opencv3_demo ${OpenCV_LIBS})
