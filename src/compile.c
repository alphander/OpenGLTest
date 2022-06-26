#include <stdio.h>
#include <stdlib.h>

const char* readFile(const char* directory)
{
    FILE* file = fopen(directory, "r");
    
    char* chars = NULL;
    char ch;
    int size = 0;
    while((ch = fgetc(file)) != EOF)
    {
        chars = realloc(chars, size + 1);
        chars[size] = ch;
        size++;
    }

    chars = realloc(chars, size + 1);
    chars[size] = '\0';
    fclose(file);
    return chars;
}

void compile_shaders()
{
    
}