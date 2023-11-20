//
// Created by alexandre on 17-10-2023.
//
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

void
catFile(const char *f_name) {
    FILE *file = fopen(f_name, "r");
    if (file == NULL) {
        printf("error: could not open %s\n", f_name);
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    int nchars = (int)fread(buffer, sizeof(char), BUFFER_SIZE, file);
    while (nchars > 0) {
        fwrite(buffer, sizeof(char), nchars, stdout);
        nchars = (int)fread(buffer, sizeof(char), BUFFER_SIZE, file);
    }
    fclose(file);
}

int
main(int argc, char* argv[]) {
    if (argc == 2) {
        catFile(argv[1]);
    } else if (argc > 2) {
        for (int i = 1; i < argc; i++) {
            catFile(argv[i]);
        }
    }
    exit(EXIT_SUCCESS);
}