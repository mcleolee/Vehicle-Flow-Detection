cmake_minimum_required(VERSION 3.19)
project(Vehicle_Flow_Detection)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vehicle_Flow_Detection main.cpp cardetc.h vid2img.h adconvert.h)

set(SOURCE_FILES main.cpp vid2img.h adconvert.h)
add_executable(Vehicle_Flow_Detection_new ${SOURCE_FILES} vid2img.h)
find_package(OpenCV REQUIRED)
target_link_libraries(Vehicle_Flow_Detection ${OpenCV_LIBS})
