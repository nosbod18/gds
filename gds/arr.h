#pragma once
#include <stdlib.h>

#define arr(T)              T *
#define arr_grow(a, n)      (!(a) || ((n) > 0 && (size_t)(n) >= _arr_cap(a)) ? _arr_grow((void **)&(a), (n), sizeof *(a)) : 0)
#define arr_free(a)         ((a) ? free(_arr_raw(a)), 0 : 0)

#define arr_len(a)          ((a) ? _arr_len(a) : 0)
#define arr_back(a)         ((a)[_arr_len(a) - 1])

#define arr_clear(a)        ((a) ? _arr_len(a) = 0 : 0)
#define arr_pushn(a, n)     (arr_grow(a, arr_len(a) + (n)), _arr_len(a) += (n), &(a)[_arr_len(a) - (n)])
#define arr_insn(a, i, n)   (arr_pushn(a, n), memmove(&(a)[(i) + (n)], &(a)[i], (arr_len(a) - (n) - (i)) * sizeof *(a)), &(a)[i])
#define arr_remn(a, i, n)   (memmove(&(a)[i], &(a)[(i) + (n)], (arr_len(a) - (n) - (i)) * sizeof *(a)), _arr_len(a) -= (n))
#define arr_ins(a, i, v)    (*arr_insn(a, i, 1) = (v))
#define arr_rem(a, i)       (arr_remn(a, i, 1))
#define arr_push(a, v)      (*arr_pushn(a, 1) = (v))
#define arr_pop(a)          ((a)[--_arr_len(a)])

#define _arr_raw(a)         ((size_t *)(void *)(a) - 2)
#define _arr_cap(a)         (_arr_raw(a)[0])
#define _arr_len(a)         (_arr_raw(a)[1])

void    _arr_grow           (void **a, size_t n, size_t stride);
