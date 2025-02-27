#include "arr.h"

void _arr_grow(void **a, size_t n, size_t stride) {
    size_t m = *a ? _arr_cap(*a) * 2 + n : n + 1;
    size_t *b = realloc(*a ? _arr_raw(*a) : NULL, stride * m + sizeof *b * 2);
    b += 2;

    _arr_cap(b) = m;
    if (!*a) _arr_len(b) = 0;

    *a = b;
}
