#include <stdio.h>

#include <coord.h>
#include <between.h>
#include <fractal.h>
#include <notify.h>

int main (int argc, char* argv[]) {
    index_t i;
    triangle_t triangulation[SIZE - 2];
    triangle_t T;
    int result = fractal_wn(SIZE, between_R2, triangulation, notify);
    if (result == 0) {
        for (i = 0; i < SIZE - 2; ++i) {
            if (i != 0) {
                printf(", ");
            }
            triangle_t T = triangulation[i];
            printf("(%d, %d, %d)", T.vx1, T.vx2, T.vx3);
        }
        printf("\n");
    }
    return 0;
}
