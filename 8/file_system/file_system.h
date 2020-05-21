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


#endif //INC_8_FILE_SYSTEM_DEFAULT_H