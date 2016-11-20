#include <stdarg.h>
#include <stdio.h>

#include <notify.h>

void notify (notify_event_t event, ...) {
    index_t i;
    const linked_triangle_t* tri;
    index_t cur_tri;
    const fractal_stack_record_t* stack;
    index_t SP;

    va_list args;
    va_start(args, event);

    if (FNE_TriangleAdded == event) {
        tri = va_arg(args, const linked_triangle_t*);
        cur_tri = va_arg(args, index_t);

        printf("FNE_TriangleAdded: ");
        for (i = 1; i < cur_tri; ++i) {
            if (i != 1) {
                printf(", ");
            }
            printf("(%d, %d, %d)", tri[i].A, tri[i].B, tri[i].C);
        }
        printf("\n");
    }
    else if (FNE_StackWound == event) {
        tri = va_arg(args, const linked_triangle_t*);
        cur_tri = va_arg(args, index_t);
        stack = va_arg(args, const fractal_stack_record_t*);
        SP = va_arg(args, index_t);

        printf("FNE_StackWound: ");
        for (i = 1; i < cur_tri; ++i) {
            if (i != 1) {
                printf(", ");
            }
            printf("(%d, %d, %d)", tri[i].A, tri[i].B, tri[i].C);
        }
        if (SP != 0) {
            printf(" ");
        }
        else {
            printf(" []");
        }
        for (i = 0; i < SP; ++i) {
            if (i != 0) {
                printf(", ");
            }
            printf("[%d, %d, %d, %d, ", stack[i].T, stack[i].e1, stack[i].e2, stack[i].aux);
            if (FSR_Left == stack[i].dir) {
                printf("FSR_Left");
            }
            else {
                printf("FSR_Right");
            }
            printf("]");
        }
        printf("\n");
    }
    else if (FNE_StackUnwound == event) {
        tri = va_arg(args, const linked_triangle_t*);
        cur_tri = va_arg(args, index_t);

        printf("FNE_StackUnwound: ");
        for (i = 1; i < cur_tri; ++i) {
            if (i != 1) {
                printf(", ");
            }
            printf("(%d, %d, %d)", tri[i].A, tri[i].B, tri[i].C);
        }
        printf("\n");
    }

    va_end(args);
}
