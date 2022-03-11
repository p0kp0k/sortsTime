cmake_minimum_required(VERSION 3.21)
project(sortMesure C)

set(CMAKE_C_STANDARD 23)

add_executable(sortMesure main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h)
