# cmake_minimum_required(VERSION <specify CMake version here>)
project(1 C)

set(CMAKE_C_STANDARD 11)

add_executable(1 main.c tasks/Task1.h tasks/Task1.c menu/Menu.h menu/Menu.c tasks/Task2.h tasks/Task2.c)