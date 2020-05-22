cmake_minimum_required(VERSION 3.15)
project(8 C)

set(CMAKE_C_STANDARD 11)

add_executable(8 main.c
        file_system/file_system.c file_system/file_system.h file_system/file_sysytem_structs.c file_system/file_sysytem_structs.h
        helpers/helpers.h helpers/helpers.c
        tasks/task_1.c tasks/task_1.h
        helpers/utils.c helpers/utils.h)