//
// Created by alexandre on 07-11-2023.
//

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>

int size(char *fname) {
    struct stat info;
    int retv = stat(fname, &info);
    if (retv == -1) {
        fprintf(stderr, "fsize: Can’t stat %s\n", fname);
        exit(EXIT_FAILURE);
    }
    return (int)info.st_size;
}

int blocks(char *fname) {
    struct stat info;
    int retv = stat(fname, &info);
    if (retv == -1) {
        fprintf(stderr, "fsize: Can’t stat %s\n", fname);
        exit(EXIT_FAILURE);
    }
    return (int)info.st_blocks;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int tsize = 0;
    int tblocks = 0;
    for (int i = 0; i < argc - 1; i++) {
        struct stat info;
        int retv = stat(argv[i+1], &info);
        if (retv == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[i+1]);
            exit(EXIT_FAILURE);
        }
        tsize = tsize + size(argv[i+1]);
        tblocks = tblocks + blocks(argv[i+1]);
        struct passwd *p;
        p = getpwuid(info.st_uid);
        printf("%s stats: %s last change, %s last owner\n", argv[i+1], ctime(&info.st_mtim.tv_sec),
               p->pw_name);
    }

    printf("total size: %d, total blocks: %d\n", tsize, tblocks);

    exit(EXIT_SUCCESS);
}
