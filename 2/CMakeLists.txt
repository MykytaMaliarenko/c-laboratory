cmake_minimum_required(VERSION 3.15)
project(2 C)

set(CMAKE_C_STANDARD 11)

add_executable(2 main.c
        tasks/Task1.h tasks/Task1.c
        tasks/Task2.h tasks/Task2.c
        helpers/Helpers.h helpers/Helpers.c
        menu/Menu.h menu/Menu.c
        helpers/ArrayHelpers.h helpers/ArrayHelpers.c helpers/ConsoleHelpers.h helpers/ConsoleHelpers.c)