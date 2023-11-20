//
// Created by alexandre on 17-10-2023.
//

#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

unsigned int
charCount(FILE *file)
{
    unsigned int size = 0;
    char buffer[BUFFER_SIZE];
    int nchars = (int) fread(buffer, sizeof(char), BUFFER_SIZE, file);
    while (nchars > 0) {
        size = size + nchars;
        nchars = (int) fread(buffer, sizeof(char), BUFFER_SIZE, file);
    }
    return size;
}

unsigned int
wordCount(FILE *file)
{
    unsigned int size = 0;
    char buffer[BUFFER_SIZE];
    int nchars = (int) fread(buffer, sizeof(char), BUFFER_SIZE, file);
    char flag = 0;
    while (nchars > 0) {
        for (int i = 0; i < nchars; i++) {
            char current = buffer[i];
            if (current == ' ' || current == '\t' || current == '\n' || current == '\r') {
                flag = 1;
            } else if (flag == 1) {
                flag = 0;
                size++;
            }
        }
        nchars = (int) fread(buffer, sizeof(char), BUFFER_SIZE, file);
    }
    size++;
    return size;
}

unsigned int
lineCount(FILE *file)
{
    unsigned int res = 0;
    char buffer[BUFFER_SIZE];
    int nchars = (int) fread(buffer, sizeof(char), BUFFER_SIZE, file);
    while (nchars > 0)
    {
        for (int i = 0; i < nchars; i++) {
            if (buffer[i] == '\n')
            {
                res++;
            }
        }
        nchars = (int) fread(buffer, sizeof(char), BUFFER_SIZE, file);
    }
    return res;
}

int
main(int argc, char *argv[])
{
    char *currentMode = argv[1];
    char *fileName = argv[2];

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("File not found.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int res;

    switch (currentMode[1]) {
        case 'c':
            res = charCount(file);
            printf("%d\n", res);
            break;
        case 'w':
            res = wordCount(file);
            printf("%d\n", res);
            break;
        case 'l':
            res = lineCount(file);
            printf("%d\n", res);
            break;
    }
    exit(EXIT_SUCCESS);
}
