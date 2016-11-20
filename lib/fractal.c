#include <stdlib.h>

#include "fractal.h"
#include "fractal_round_step.h"

int fractal (index_t N, between_func_t between, triangle_t* triangulation) {
    return fractal_wn(N, between, triangulation, 0);
}

int fractal_wn (index_t N, between_func_t between, triangle_t* triangulation, notify_func_t notify) {
    linked_triangle_t* tri = malloc((N - 1) * sizeof(linked_triangle_t));
    linked_triangle_t T;
    index_t nxt_tri = 1;
    index_t* edge = malloc(N * sizeof(index_t));
    fractal_round_step_result_t step_result;
    index_t i;
    edge[0] = nxt_tri;
    edge[N / 3] = nxt_tri;
    edge[2 * N / 3] = nxt_tri;
    T.A = 0;
    T.B = N / 3;
    T.C = 2 * N / 3;
    T.BC = 0;
    T.CA = 0;
    T.AB = 0;
    tri[nxt_tri++] = T;
    do {
        step_result = fractal_round_step(N, between, tri, &nxt_tri, edge, notify);
    } while (step_result == FRS_NotLastVertexAdded);
    free(edge);
    if (step_result != FRS_Fail) {
        for (i = 1; i < nxt_tri; ++i) {
            triangulation[i - 1].vx1 = tri[i].A;
            triangulation[i - 1].vx2 = tri[i].B;
            triangulation[i - 1].vx3 = tri[i].C;
        }
    }
    free(tri);
    return step_result != FRS_Fail ? 0 : -1;
}
