#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 64

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *current = (char *) malloc(MAX_SIZE * sizeof(char));
        strcpy(current, argv[1]);
        for (size_t i = 0; i < strlen(argv[1]); i++) {
            current[i] = tolower(current[i]);
        }
        printf("%s\n", current);
    }
    else if (argc == 3) {
        char *s1 = (char *) malloc(MAX_SIZE * sizeof(char));
        char *s2 = (char *) malloc(MAX_SIZE * sizeof(char));
        strcpy(s1, argv[1]);
        strcpy(s2, argv[2]);

        if (strstr(s2, s1) == NULL) {
            printf("The string %s is not found in the string %s.\n", s1, s2);
        }
        else {
            int times = 0;
            char *str_ptr = s2;
            while ((str_ptr = strstr(str_ptr, s1)) != NULL) {
                str_ptr++;
                times++;
            }


            printf("The string %s is found in the string %s %d times.\n", s1, s2, times);
        }
    }
    return 0;
}