#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void readFileLineByLine_defaultBehavior(char *buffer) {
    printf("%s", buffer);
} // readFileLineByLine_defaultBehavior()
int readFileLineByLine(const char *filename, void (*behavior)()) {
    int return_value = -1;

    FILE *file = fopen(filename ,"r");
    if (file == NULL) {
        printf("error at opening %s\n", filename);
        return return_value;
    } // if

    char buffer[256];
    if (!behavior) behavior = readFileLineByLine_defaultBehavior;
    while (fgets(buffer, sizeof(buffer), file)) {
        behavior(buffer);
    } // while
    fclose(file); return_value = 0;

    return return_value;
} // readFileLineByLine()

int readFileEntirely(const char *filename) {
    int return_value = -1;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("error at opening %s\n", filename);
        return return_value;
    } // if

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(filesize + 1);
    fread(buffer, 1, filesize, file);
    buffer[filesize - CUT_END_LENGTH] = '\0'; // null-character

    printf("%s", buffer);
    fclose(file); free(buffer);
    return_value = 0;

    return return_value;
} // readFileEntirely()