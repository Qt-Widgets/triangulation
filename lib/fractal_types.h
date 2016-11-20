#ifndef _FRACTAL_TYPES_H
#define _FRACTAL_TYPES_H

typedef unsigned int index_t;

typedef int (*between_func_t) (index_t, index_t, index_t, index_t);

typedef struct {
    index_t vx1;
    index_t vx2;
    index_t vx3;
} triangle_t;

typedef struct {
    index_t A;
    index_t B;
    index_t C;
    index_t BC;
    index_t CA;
    index_t AB;
} linked_triangle_t;

typedef struct {
    index_t T;
    index_t e1;
    index_t e2;
    index_t aux;
    enum {FSR_Left, FSR_Right} dir;
} fractal_stack_record_t;

typedef enum {
   FNE_TriangleAdded,
   FNE_StackWound,
   FNE_StackUnwound
} notify_event_t;

typedef void (*notify_func_t) (notify_event_t, ...);
/*
FNE_TriangleAdded, const linked_triangle_t* tri, index_t cur_tri
FNE_StackWound, const linked_triangle_t* tri, index_t cur_tri, const fractal_stack_record_t* stack, index_t SP
FNE_StackUnwound, const linked_triangle_t* tri, index_t cur_tri
*/

#endif
