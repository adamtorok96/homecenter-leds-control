cmake_minimum_required(VERSION 3.6)
project(homecenter_leds_control)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(homecenter_leds_control ${SOURCE_FILES})