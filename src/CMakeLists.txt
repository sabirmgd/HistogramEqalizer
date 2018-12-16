cmake_minimum_required(VERSION 2.8)

#project(${PROJECT_NAME})

find_package( OpenCV REQUIRED core imgproc highgui)
include_directories(${COMMON_INCLUDES})
add_executable( histogram_equalizer histogram_equalizer.h main.cpp histogram_equalizer.cpp )

target_link_libraries( histogram_equalizer ${OpenCV_LIBS} )