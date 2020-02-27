cmake_minimum_required(VERSION 3.15)
project(5 C)

set(CMAKE_C_STANDARD 11)

add_executable(5 main.c tasks/Task1.h tasks/Task1.c
        helpers/Helpers.h helpers/Helpers.c
        helpers/ConsoleHelpers.h helpers/ConsoleHelpers.c
        menu/Menu.h menu/Menu.c)