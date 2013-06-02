#ifndef _FRACTAL_ROUND_STEP_H
#define _FRACTAL_ROUND_STEP_H

#include "fractal_types.h"

typedef enum {FRS_Fail, FRS_LastVertexAdded, FRS_NotLastVertexAdded} fractal_round_step_result_t;

#ifdef __cplusplus
extern "C" {
#endif

fractal_round_step_result_t fractal_round_step (index_t N, between_func_t between, linked_triangle_t* tri, index_t* p_nxt_tri, index_t* edge);

#ifdef __cplusplus
}
#endif

#endif
