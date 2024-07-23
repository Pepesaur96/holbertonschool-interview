#ifndef slide_line_h
#define slide_line_h
#include <stdio.h>
/*macros*/
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1
/*Fucntions Signatures*/
int slide_line(int *line, size_t size, int direction);
void slide_and_combine(int * line, size_t size, int direction);

#endif
