#include "fractal_round_step.h"
#include "fractal_single_step.h"

fractal_round_step_result_t fractal_round_step (index_t N, between_func_t between, linked_triangle_t* tri, index_t* p_nxt_tri, index_t* edge) {
    fractal_round_step_result_t result;
    index_t cur_vx = 0;
    int holes = 0;
    do {
        fractal_single_step_result_t single_step_result = fractal_single_step(N, between, tri, p_nxt_tri, edge, &cur_vx);
        switch (single_step_result) {
            case FSS_Fail:
                return FRS_Fail;
            case FSS_NothingAdded:
            case FSS_LocallyLastVertexAdded:
                break;
            case FSS_NotLastVertexAdded:
                ++holes;
                break;
        }
    } while (cur_vx != 0);
    result = holes > 0 ? FRS_NotLastVertexAdded : FRS_LastVertexAdded;
    return result;
}
