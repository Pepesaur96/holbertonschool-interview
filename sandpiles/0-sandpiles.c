#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, unstable = 0;

    /* Add grid2 to grid1 */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    /* Check if grid1 is unstable */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid1[i][j] > 3)
                unstable = 1;

    /* If grid1 is unstable, topple it until it becomes stable */
    while (unstable)
    {
        printf("=\n");
        print_grid(grid1);

        int topple[3][3] = {0};

        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (grid1[i][j] > 3)
                {
                    topple[i][j] = 1;
                }

        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (topple[i][j])
                {
                    grid1[i][j] -= 4;
                    if (i > 0)
                        grid1[i - 1][j]++;
                    if (j > 0)
                        grid1[i][j - 1]++;
                    if (i < 2)
                        grid1[i + 1][j]++;
                    if (j < 2)
                        grid1[i][j + 1]++;
                }

        unstable = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (grid1[i][j] > 3)
                    unstable = 1;
    }
}