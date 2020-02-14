cmake_minimum_required(VERSION 3.15)
project(3 C)

set(CMAKE_C_STANDARD 11)

add_executable(3 main.c tasks/Task1.h tasks/Task1.c menu/Menu.c menu/Menu.h helpers/Helpers.c
        helpers/ArrayHelpers.c helpers/ArrayHelpers.h helpers/Helpers.h)