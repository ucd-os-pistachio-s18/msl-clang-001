cmake_minimum_required(VERSION 3.6)
project(msl_clang_001)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c tree.h file.h file.c tree.c)

add_executable(msl_clang_001 ${SOURCE_FILES})