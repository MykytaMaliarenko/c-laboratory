//
// Created by Mykyta Maliarenko on 12.02.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* scan(char* string);

void FindWords()
{
    printf("Input your text:\n");

    char *str;
    str = scan(str);

    //splitting str by space, pointer points to each peace of str
    char *ptr = strtok(str, " ");
    while(ptr != NULL)
    {
        if (ptr[0] == ptr[strlen(ptr) - 1])
            printf("'%s'\n", ptr);
        ptr = strtok(NULL, " ");
    }

    free(str);
}

//dynamically allocating memory while input != '\n'
char* scan(char *string)
{
    int c;
    string = malloc(sizeof(char));

    string[0]='\0';

    for(int i=0; i<100 && (c=getchar())!='\n' && c != EOF ; i++)
    {
        string = realloc(string, (i+2)*sizeof(char));
        string[i] = (char) c;
        string[i+1] = '\0';
    }

    return string;
}