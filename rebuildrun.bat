@echo off
cls
gcc main.c file.c tree.c -o msl-clang-001.exe 
msl-clang-001.exe %*
