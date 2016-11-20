#include "fractal_single_step.h"
#include "fractal_aux.h"
#include "fractal_stack_algorithm.h"

fractal_single_step_result_t fractal_single_step (index_t N,
                                                  between_func_t between,
                                                  linked_triangle_t* tri,
                                                  index_t* p_nxt_tri,
                                                  index_t* edge,
                                                  index_t* p_cur_vx,
                                                  notify_func_t notify) {
    fractal_single_step_result_t result;
    index_t cur_vx = *p_cur_vx;
    index_t cur_tri = edge[cur_vx];
    index_t nxt_tri = *p_nxt_tri;
    linked_triangle_t T = tri[cur_tri];
    index_t nxt_vx;
    index_t aux_vx;
    index_t delta;
    index_t new_vx;

    if (cur_vx == T.A) {
        nxt_vx = T.B;
        aux_vx = T.C;
    }
    if (cur_vx == T.B) {
        nxt_vx = T.C;
        aux_vx = T.A;
    }
    if (cur_vx == T.C) {
        nxt_vx = T.A;
        aux_vx = T.B;
    }
    if (nxt_vx != 0) {
        delta = nxt_vx - cur_vx;
    }
    else {
        delta = N - cur_vx;
    }
    if (delta > 1) {
        if (nxt_vx != 0) {
            new_vx = (cur_vx + nxt_vx) / 2;
        }
        else {
            new_vx = (cur_vx + N) / 2;
        }
        if (between(new_vx, aux_vx, cur_vx, nxt_vx)) {
            edge[cur_vx] = nxt_tri;
            edge[new_vx] = nxt_tri;
            fractal_mark_against(&(tri[cur_tri]), aux_vx, nxt_tri);
            T.A = cur_vx;
            T.B = new_vx;
            T.C = nxt_vx;
            T.BC = 0;
            T.CA = cur_tri;
            T.AB = 0;
            tri[nxt_tri++] = T;
            if (notify) {
                notify(FNE_TriangleAdded, tri, nxt_tri);
            }
        }
        else {
            fractal_stack_algorithm_result_t stack_algorithm_result =
                fractal_stack_algorithm(between,
                                        tri,
                                        &nxt_tri,
                                        edge,
                                        cur_vx,
                                        nxt_vx,
                                        new_vx,
                                        aux_vx,
                                        cur_tri,
                                        notify);
            if (stack_algorithm_result == FSA_Fail) {
                return FSS_Fail;
            }
        }
        if (delta > 2) {
            result = FSS_NotLastVertexAdded;
        }
        else {
            result = FSS_LocallyLastVertexAdded;
        }
    }
    else {
        result = FSS_NothingAdded;
    }
    cur_vx = nxt_vx;
    *p_nxt_tri = nxt_tri;
    *p_cur_vx = cur_vx;
    return result;
}
