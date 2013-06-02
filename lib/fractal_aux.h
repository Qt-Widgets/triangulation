#ifndef _FRACTAL_AUX_H
#define _FRACTAL_AUX_H

#include "fractal_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void fractal_mark_against (linked_triangle_t* T, index_t vertex, index_t neigh);
index_t fractal_get_against (const linked_triangle_t* T, index_t vertex);
index_t fractal_third_vertex (const linked_triangle_t* T, index_t vertex1, index_t vertex2);
void fractal_replace_neigh (linked_triangle_t* T, index_t old_neigh, index_t new_neigh);

#ifdef __cplusplus
}
#endif

#endif
