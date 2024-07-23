#include "slide_line.h"
/**/
void slide_and_combine(int * line, size_t size, int direction){
    if (direction == SLIDE_LEFT) {
        // Slide and combine towards the left
        for (size_t i = 0; i < size; i++) {
            for (size_t j = i + 1; j < size; j++) {
                if (line[i] == 0 && line[j] != 0) {
                    line[i] = line[j];
                    line[j] = 0;
                } else if (line[i] == line[j] && line[i] != 0) {
                    line[i] *= 2;
                    line[j] = 0;
                    break;
                } else if (line[j] != 0) {
                    break;
                }
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        // Slide and combine towards the right
        for (size_t i = size; i > 0; i--) {
            for (size_t j = i - 1; j > 0; j--) {
                if (line[i - 1] == 0 && line[j - 1] != 0) {
                    line[i - 1] = line[j - 1];
                    line[j - 1] = 0;
                } else if (line[i - 1] == line[j - 1] && line[i - 1] != 0) {
                    line[i - 1] *= 2;
                    line[j - 1] = 0;
                    break;
                } else if (line[j - 1] != 0) {
                    break;
                }
            }
        }
    }
}
/*
* slide_line - function that slides and merges an array of integers
* @line: points to an array of integers containing size elements
* @size: size of the array
* @direction: direction to slide
* Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction){
        if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0;
    }
    slide_and_combine(line, size, direction);
    return 1;

}
