//
// Created by Mykyta Maliarenko on 21.05.2020.
//

#ifndef INC_8_FILE_SYSTEM_DEFAULT_H
#define INC_8_FILE_SYSTEM_DEFAULT_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool fileSystemFileExists(char* filepath);

void fileSystemCreateFile(char* filepath);

void fileSystemPrintFile(char* filepath);

void fileSystemEditFile(char* filepath, char* newContent);

void fileSystemCopyFile(char* copyTo, char* copyFrom);

void fileSystemCopyRowsWithoutNumber(char* copyTo, char* copyFrom);

int fileSystemCountRowsThatBeginsWith(char* filepath, char symbol);

void fileSystemDestroyFile(char* path);

#endif //INC_8_FILE_SYSTEM_DEFAULT_H