#ifndef _FRACTAL_H
#define _FRACTAL_H

#include "fractal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

int fractal (index_t N, between_func_t between, triangle_t* triangulation);

#ifdef __cplusplus
}
#endif

#endif
