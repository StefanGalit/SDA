cmake_minimum_required(VERSION 3.28)
project(SDA C)

set(CMAKE_C_STANDARD 11)

add_executable(SDA main.c
        func.c
        func.h)
