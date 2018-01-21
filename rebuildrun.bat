@echo off
cls
gcc main.c file.c old_tree.c tests.c -o msl-clang-001.exe
msl-clang-001.exe %*
