//
// Created by Mykyta Maliarenko on 21.05.2020.
//

#include "file_system.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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

void fileSystemCopyFile(char* sourceFile, char* targetFile)
{
    char ch;
    FILE *source, *target;

    source = fopen(sourceFile, "r");
    if( source == NULL )
        return;

    target = fopen(targetFile, "w");
    if(target == NULL)
        return;

    while( ( ch = fgetc(source) ) != EOF )
        fputc(ch, target);

    fclose(source);
    fclose(target);
}

void fileSystemCopyRowsWithoutNumber(char* copyTo, char* copyFrom)
{
    FILE* fpSource = fopen(copyFrom, "r");
    if (fpSource == NULL)
        return;

    FILE* fpTarget = fopen(copyTo, "w");
    if (fpTarget == NULL)
    {
        fclose(fpSource);
        return;
    }

    bool writingFirstTimeToTarget = true;
    char line[128];
    while (fscanf(fpSource, "%s", line) == 1 )
    {
        bool containsDigit = false;
        for (int i = 0; i < 128; i++)
        {
            if (isdigit(line[i]))
            {
                containsDigit = true;
                break;
            }
        }

        if (containsDigit == false)
        {
            if (writingFirstTimeToTarget == true)
            {
                fprintf(fpTarget, "\n%s", line);
                writingFirstTimeToTarget = false;
            }
            else
                fprintf(fpTarget, "\n%s", line);
        }
    }

    fclose(fpSource);
    fclose(fpTarget);
}

int fileSystemCountRowsThatBeginsWith(char* filepath, char symbol)
{
    FILE* fp = fopen(filepath, "r");
    if (filepath == NULL)
        return -1;

    int res = 0;
    char line[128];
    while (fscanf(fp, "%s", line) == 1 )
    {
       if (line[0] == symbol)
           res++;
    }

    return res;
}

void fileSystemDestroyFile(char* path)
{
    remove(path);
}