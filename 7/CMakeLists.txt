cmake_minimum_required(VERSION 3.15)
project(7 C)

set(CMAKE_C_STANDARD 11)

add_executable(7 main.c
        LinkedList/LinkedList.h LinkedList/LinkedList.c
        Train/Train.h Train/Train.c
        Tasks/Task1.c Tasks/Task1.h
        Helpers/Helpers.h Helpers/Helpers.c
        Helpers/ConsoleHelpers.h Helpers/ConsoleHelpers.c
        Menu/Menu.h Menu/Menu.c
        Tasks/Task2.c Tasks/Task2.h
        LinkedList/LinkeListFuncsForLab.c LinkedList/LinkeListFuncsForLab.h)