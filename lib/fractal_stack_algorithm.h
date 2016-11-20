#ifndef _FRACTAL_STACK_ALGORITHM_H
#define _FRACTAL_STACK_ALGORITHM_H

#include "fractal_types.h"

typedef enum {FSA_Fail, FSA_Success} fractal_stack_algorithm_result_t;

#ifdef __cplusplus
extern "C" {
#endif

fractal_stack_algorithm_result_t fractal_stack_algorithm (between_func_t between,
                                                          linked_triangle_t* tri,
                                                          index_t* p_nxt_tri,
                                                          index_t* edge,
                                                          index_t cur_vx,
                                                          index_t nxt_vx,
                                                          index_t new_vx,
                                                          index_t aux_vx,
                                                          index_t cur_tri,
                                                          notify_func_t notify);

#ifdef __cplusplus
}
#endif

#endif
