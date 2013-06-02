#ifndef _FRACTAL_SINGLE_STEP_H
#define _FRACTAL_SINGLE_STEP_H

#include "fractal_types.h"

typedef enum {FSS_Fail, FSS_NothingAdded, FSS_LocallyLastVertexAdded, FSS_NotLastVertexAdded} fractal_single_step_result_t;

#ifdef __cplusplus
extern "C" {
#endif

fractal_single_step_result_t fractal_single_step (index_t N, between_func_t between, linked_triangle_t* tri, index_t* p_nxt_tri, index_t* edge, index_t* p_cur_vx);

#ifdef __cplusplus
}
#endif

#endif
