cmake_minimum_required(VERSION 3.15)
project(6 C)

set(CMAKE_C_STANDARD 11)

add_executable(6 main.c
        helpers/ConsoleHelpers.c helpers/ConsoleHelpers.h
        helpers/Helpers.c helpers/Helpers.h
        helpers/ArrayHelpers.c helpers/ArrayHelpers.h
        menu/Menu.c menu/Menu.h
        tasks/Task1.h tasks/Task1.c)