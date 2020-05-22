//
// Created by Mykyta Maliarenko on 21.05.2020.
//

#ifndef INC_8_FILE_SYSTEM_STRUCTS_H
#define INC_8_FILE_SYSTEM_STRUCTS_H

#include "../humans/humans.h"

void fileSystemStructsWrite(char* filepath, Humans humans);

Humans fileSystemStructsRead(char* filepath);

void fileSystemStructCopyFile(char* source, char* target);

#endif //INC_8_FILE_SYSTEM_STRUCTS_H
