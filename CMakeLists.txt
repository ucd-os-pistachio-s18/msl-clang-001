cmake_minimum_required(VERSION 3.9)
project(msl_clang_00)

set(CMAKE_CXX_STANDARD 11)

add_executable(msl_clang_001
        file.c
        file.h
        main.c
        tree.c
        tree.h)
