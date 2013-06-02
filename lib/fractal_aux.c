#include "fractal_aux.h"

void fractal_mark_against (linked_triangle_t* T, index_t vertex, index_t neigh) {
    if (vertex == T->A) {
        T->BC = neigh;
    }
    if (vertex == T->B) {
        T->CA = neigh;
    }
    if (vertex == T->C) {
        T->AB = neigh;
    }
}

index_t fractal_get_against (const linked_triangle_t* T, index_t vertex) {
    if (vertex == T->A) {
        return T->BC;
    }
    if (vertex == T->B) {
        return T->CA;
    }
    if (vertex == T->C) {
        return T->AB;
    }
}

index_t fractal_third_vertex (const linked_triangle_t* T, index_t vertex1, index_t vertex2) {
    if (vertex1 == T->A) {
        if (vertex2 == T->B) {
            return T->C;
        }
        if (vertex2 == T->C) {
            return T->B;
        }
    }
    if (vertex1 == T->B) {
        if (vertex2 == T->C) {
            return T->A;
        }
        if (vertex2 == T->A) {
            return T->C;
        }
    }
    if (vertex1 == T->C) {
        if (vertex2 == T->A) {
            return T->B;
        }
        if (vertex2 == T->B) {
            return T->A;
        }
    }
}

void fractal_replace_neigh (linked_triangle_t* T, index_t old_neigh, index_t new_neigh) {
    if (old_neigh == T->AB) {
        T->AB = new_neigh;
    }
    if (old_neigh == T->BC) {
        T->BC = new_neigh;
    }
    if (old_neigh == T->CA) {
        T->CA = new_neigh;
    }
}
