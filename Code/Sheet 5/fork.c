//
// Created by alexandre on 07-11-2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    for (int i = 0; i < 4; i++) {
        fork();
    }
    printf("%d\n", getpid());
    exit(EXIT_SUCCESS);
}
