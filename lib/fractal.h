#ifndef _FRACTAL_H
#define _FRACTAL_H

#include "fractal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

int fractal (index_t N, between_func_t between, triangle_t* triangulation);

int fractal_wn (index_t N, between_func_t between, triangle_t* triangulation, notify_func_t notify);

#ifdef __cplusplus
}
#endif

#endif
