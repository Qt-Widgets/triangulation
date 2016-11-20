#include <between.h>
#include <coord.h>

int between_R2 (index_t new_vx, index_t e1_vx, index_t e2_vx, index_t aux_vx) {
    coord_t delta_x = x[e2_vx] - x[aux_vx];
    coord_t delta_y = y[e2_vx] - y[aux_vx];
    coord_t s1 = (x[new_vx] - x[e2_vx]) * delta_y - (y[new_vx] - y[e2_vx]) * delta_x;
    coord_t s2 = (x[e1_vx] - x[e2_vx]) * delta_y - (y[e1_vx] - y[e2_vx]) * delta_x;
    return s1 * s2 <= 0;
}
