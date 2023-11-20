//
// Created by alexandre on 17-10-2023.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int
main(int argc, char *argv[]) {
    const char *fileName1 = argv[1];
    const char *fileName2 = argv[2];

    FILE *file1 = fopen(fileName1, "r");
    if (file1 == NULL) {
        printf("error: could not open %s\n", fileName1);
        exit(EXIT_FAILURE);
    }

    FILE *file2 = fopen(fileName2, "w");
    if (file2 == NULL) {
        printf("File %s does not exist, and could not be created.", fileName2);
    }

    char buffer[MAX_SIZE];
    int nchars = (int)fread(buffer, sizeof(char), MAX_SIZE, file1);
    while (nchars > 0) {
        fwrite(buffer, sizeof(char), nchars, file2);
        nchars = (int)fread(buffer, sizeof(char), MAX_SIZE, file1);
    }
    fclose(file1);
    fclose(file2);

    exit(EXIT_SUCCESS);
}

