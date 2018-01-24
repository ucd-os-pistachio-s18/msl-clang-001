@echo off
cls
gcc main.c file.c tree.c -o msl-clang-001.exe
cd input_output_data_files
..\msl-clang-001.exe %*
cd ..
