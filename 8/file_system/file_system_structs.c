//
// Created by Mykyta Maliarenko on 21.05.2020.
//

#include "file_system_structs.h"

void fileSystemStructsWrite(char* filepath, Humans humans)
{
    FILE* fp = fopen(filepath, "wb");
    if (fp == NULL)
        return;

    fwrite(&humans->size, sizeof(int), 1, fp);
    for (int i = 0; i < humans->size; i++)
    {
        Human* current = listGet(humans, i);
        fwrite(current, sizeof(Human), 1, fp);
    }

    fclose(fp);
}

Humans fileSystemStructsRead(char* filepath)
{
    FILE* fp = fopen(filepath, "rb");
    if (fp == NULL)
        return NULL;

    Humans humans = createList();

    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    if (size == 0)
        return humans;

    rewind(fp);

    int n;
    fread(&n, sizeof(int), 1, fp);

    for (int i = 0;i < n; i++)
    {
        Human* current = calloc(1, sizeof(Human));
        fread(current, sizeof(Human), 1, fp);
        listAdd(humans, current);
    }

    return humans;
}

void fileSystemStructCopyFile(char* source, char* target)
{
    char  buff[BUFSIZ];
    FILE *in, *out;
    size_t n;

    in = fopen( source, "rb" );
    out= fopen( target, "wb" );
    while ( (n=fread(buff,1,BUFSIZ,in)) != 0 ) {
        fwrite( buff, 1, n, out );
    }

    fclose(in);
    fclose(out);
}