//
// Created by alexandre on 17-10-2023.
//

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int
main(int argc, char *argv [])
{
    char *string = argv[1];
    char *fileName = argv[2];
    FILE *file = fopen(fileName, "r");
    char buffer[BUFFER_SIZE];
    int nchars = (int)fread(buffer, sizeof(char), BUFFER_SIZE, file);
    while (nchars > 0) {
        int times = 0;
        char *str_ptr = buffer;
        while ((str_ptr = strstr(str_ptr, s1)) != NULL) {
            str_ptr++;
            times++;
        }
    }
}
