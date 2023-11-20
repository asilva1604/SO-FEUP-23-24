//
// Created by alexandre on 07-11-2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    int len;
    if (argc != 2) {
        fprintf (stderr, "usage: %s dirname or %s filename\n", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }
    DIR *q = opendir(argv[1]);
    if (q == NULL) {
        //TODO: treat file
        fprintf (stderr, "cannot open directory: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    printf ("%s/\n", argv[1]);
    struct dirent *p = readdir(q);
    while (p != NULL) {
        struct stat st;
        int a = stat(p->d_name, &st);
        if (a == 0) {
            printf ("\t%d %ld %s\n", st.st_mode, st.st_size, p->d_name);
        }
        p = readdir(q);
    }
    closedir(q);
    exit(EXIT_SUCCESS);
}