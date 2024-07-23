#include <stdio.h>
#include <math.h>

void draw_menger(int level, int size);
int is_filled(int x, int y);

void menger(int level) {
    if (level < 0) {
        return;
    }

    int size = pow(3, level);
    draw_menger(level, size);
}

void draw_menger(int level, int size) {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (is_filled(x, y)) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int is_filled(int x, int y) {
    while (x > 0 || y > 0) {
        if (x % 3 == 1 && y % 3 == 1) {
            return 0;
        }
        x /= 3;
        y /= 3;
    }
    return 1;
}
