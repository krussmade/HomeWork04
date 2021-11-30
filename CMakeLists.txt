cmake_minimum_required(VERSION 3.20)
project(Animals)

set(CMAKE_CXX_STANDARD 17)

enable_language(ASM_NASM)

add_executable(Animals main.cpp
        task_functions.asm
        source/animal.cpp
        headers/container.h
        source/container.cpp
        headers/animal.h
        headers/constants.h
        headers/utils.h
        source/utils.cpp)
