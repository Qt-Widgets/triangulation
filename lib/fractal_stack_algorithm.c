#include <stdlib.h>

#include "fractal_stack_algorithm.h"

fractal_stack_algorithm_result_t fractal_stack_algorithm (between_func_t between,
                                                          linked_triangle_t* tri,
                                                          index_t* p_nxt_tri,
                                                          index_t* edge,
                                                          index_t cur_vx,
                                                          index_t nxt_vx,
                                                          index_t new_vx,
                                                          index_t aux_vx,
                                                          index_t cur_tri,
                                                          notify_func_t notify) {
    index_t nxt_tri = *p_nxt_tri;
    fractal_stack_record_t* stack = malloc(nxt_tri * sizeof(fractal_stack_record_t));
    index_t SP = 0;
    fractal_stack_record_t record;
    index_t e1_vx = cur_vx;
    index_t e2_vx = nxt_vx;
    int outl;
    int outr;
    index_t neigh_tri;
    index_t lastl;
    index_t lastr;
    linked_triangle_t T = tri[cur_tri];
    do {
        outl = between(new_vx, e2_vx, e1_vx, aux_vx);
        outr = between(new_vx, e1_vx, e2_vx, aux_vx);
        if (outl && outr) {
            free(stack);
            return FSA_Fail;
        }
        if (outl || outr) {
            record.T = cur_tri;
            record.e1 = e1_vx;
            record.e2 = e2_vx;
            record.aux = aux_vx;
            record.dir = outl ? FSR_Left : FSR_Right;
            stack[SP++] = record;
            if (outl) {
                cur_tri = fractal_get_against(&T, e1_vx);
            }
            else {
                cur_tri = fractal_get_against(&T, e2_vx);
            }
            if (cur_tri != 0) {
                T = tri[cur_tri];
                if (outl) {
                    e2_vx = aux_vx;
                    aux_vx = fractal_third_vertex(&T, e1_vx, aux_vx);
                }
                else {
                    e1_vx = aux_vx;
                    aux_vx = fractal_third_vertex(&T, e2_vx, aux_vx);
                }
            }
            else {
                free(stack);
                return FSA_Fail;
            }
        }
    } while (outl || outr);
    neigh_tri = fractal_get_against(&(tri[cur_tri]), e2_vx);
    if (neigh_tri != 0) {
        fractal_replace_neigh(&(tri[neigh_tri]), cur_tri, nxt_tri);
    }
    if (edge[aux_vx] == cur_tri) {
        edge[aux_vx] = nxt_tri;
    }
    T.A = new_vx;
    T.B = aux_vx;
    T.C = e1_vx;
    T.BC = neigh_tri;
    T.AB = cur_tri;
    lastl = nxt_tri;
    tri[nxt_tri] = T;
    neigh_tri = fractal_get_against(&(tri[cur_tri]), e1_vx);
    T.B = e2_vx;
    T.C = aux_vx;
    T.BC = neigh_tri;
    T.CA = nxt_tri;
    lastr = cur_tri;
    tri[cur_tri] = T;
    ++nxt_tri;
    if (notify) {
        notify(FNE_StackWound, tri, nxt_tri, stack, SP);
    }
    while (SP > 0) {
        record = stack[--SP];
        cur_tri = record.T;
        aux_vx = record.aux;
        switch (record.dir) {
            case FSR_Left:
                neigh_tri = fractal_get_against(&(tri[cur_tri]), record.e1);
                T.B = record.e2;
                T.C = aux_vx;
                T.BC = neigh_tri;
                T.CA = lastr;
                tri[lastr].AB = cur_tri;
                lastr = cur_tri;
                break;
            case FSR_Right:
                neigh_tri = fractal_get_against(&(tri[cur_tri]), record.e2);
                T.B = aux_vx;
                T.C = record.e1;
                T.BC = neigh_tri;
                T.AB = lastl;
                tri[lastl].CA = cur_tri;
                lastl = cur_tri;
                break;
        }
        tri[cur_tri] = T;
    }
    free(stack);
    tri[lastl].CA = 0;
    tri[lastr].AB = 0;
    if (notify) {
        notify(FNE_StackUnwound, tri, nxt_tri);
    }
    edge[cur_vx] = lastl;
    edge[new_vx] = lastr;
    if (edge[nxt_vx] == cur_tri) {
        edge[nxt_vx] = lastr;
    }
    if (edge[aux_vx] == cur_tri) {
        edge[aux_vx] = lastl;
    }
    *p_nxt_tri = nxt_tri;
    return FSA_Success;
}
