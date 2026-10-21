#include "common.h"

LINKER_REMNANT("asm/levels", func_L03_004640A0);

/* localdecomp:start func_L03_004640A8 */
typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    s32 count;
    s32 pad[3];
    Vec4 items[1];
} VecList;

extern f32 func_0038CF00(Vec4 *, void *);

s32 func_L03_004640A8(void *a0, VecList *list, f32 target) {
    s32 i;
    s32 best;
    f32 bestVal;
    f32 d;

    best = 0;
    bestVal = 1e11f;
    for (i = 0; i < list->count; i++) {
        d = func_0038CF00(&list->items[i], a0);
        if (__builtin_fabsf(d - target) < bestVal) {
            bestVal = d;
            best = i;
        }
    }
    return best;
}
/* localdecomp:end func_L03_004640A8 */
