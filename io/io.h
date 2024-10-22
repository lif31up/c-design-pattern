//
// Created by syona on 2024-10-22.
//

#ifndef C_DESIGN_PATTERN_IO_H
#define C_DESIGN_PATTERN_IO_H

#include <stdio.h>

#define CUT_END_LENGTH 6

typedef struct FileInputInterface_ {
    void (*readFile)(const char *filename);
} FileInputInterface;

void readFileLineByLine_defaultBehavior(char *buffer);
int readFileLineByLine(const char *filename, void (*behavior)());
int readFileEntirely(const char *filename);

#endif //C_DESIGN_PATTERN_IO_H
