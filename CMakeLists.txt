cmake_minimum_required(VERSION 3.7)
project(theoinf)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c hashing.h hashing.c declaration.h declaration.c helper.c helper.h)
add_executable(theoinf ${SOURCE_FILES})