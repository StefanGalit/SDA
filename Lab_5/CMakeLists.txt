cmake_minimum_required(VERSION 3.28)
project(Lab_5 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab_5 main.c
        func.h
        func.c
        benchmark.h
        benchmark.c
)
