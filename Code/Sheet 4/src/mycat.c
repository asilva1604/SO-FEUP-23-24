//
// Created by alexandre on 07-11-2023.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

void mycat(char *f_name) {
    int fd = open(f_name, O_RDONLY);
    if (fd == -1) {
        printf("error: cannot open %s\n", f_name);
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    int nbytes = read(fd, buffer, BUFFER_SIZE);
    while (nbytes > 0) {
        write(STDOUT_FILENO, buffer, nbytes);
        nbytes = read(fd, buffer, BUFFER_SIZE);
    }
    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("usage: cat filename\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < argc-1; i++) {
        mycat(argv[i+1]);
    }
    exit(EXIT_SUCCESS);
}