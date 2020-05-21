//
// Created by Mykyta Maliarenko on 21.05.2020.
//

#include "file_system.h"
#include <stdbool.h>
#include <string.h>


void fileSystemCreateFile(char* filepath)
{
    FILE* fp = fopen(filepath, "w");
    fclose(fp);
}

bool fileSystemFileExists(char* filepath)
{
    FILE* fp;
    if ((fp = fopen(filepath, "r")) == NULL)
        return false;
    else
    {
        fclose(fp);
        return true;
    }
}

void fileSystemPrintFile(char* filepath)
{
    FILE* file = fopen(filepath, "r");
    if (file)
    {
        char c = fgetc(file);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(file);
        }

        fclose(file);
    }
}

void fileSystemEditFile(char* filepath, char* newContent)
{
    FILE* file = fopen(filepath, "w");
    fwrite(newContent, sizeof(char), strlen(newContent), file);
    fclose(file);
}