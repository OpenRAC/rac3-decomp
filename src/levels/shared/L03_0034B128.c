#include "common.h"

typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    int wC;
} Unk34A688;

LINKER_REMNANT("asm/levels", func_L03_0034B128);

/* localdecomp:start func_L03_0034B148 */
f32 func_L03_0034B148(s32 a0, s32 a1, f32 f) {
    f32 t;
    if (a1 <= 0) {
        return 0.0f;
    }
    t = 1.0f - (f32)a0 / (f32)a1;
    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    if (2.0f < f) {
        f = 2.0f;
    }
    return t * (1.0f - f * 0.5f * (1.0f - t));
}
/* localdecomp:end func_L03_0034B148 */

LINKER_REMNANT("asm/levels", func_L03_0034B1F8);

INCLUDE_ASM("asm/levels", func_L03_0034B218);

/* localdecomp:start func_L03_0034B248 */

extern int func_00382498(int, int);
extern void func_L03_00461E88_0034B248(void *, Unk34A688 *, int, int);

void func_L03_0034B248(Unk34A688 *s, void *a1) {
    if (s == 0) {
        return;
    }
    s->f8 += s->f4;
    while (s->f8 > 1.0f) {
        s->f8 -= 1.0f;
        func_L03_00461E88_0034B248(a1, s, func_00382498(s->h2, s->h0), s->wC);
    }
}
/* localdecomp:end func_L03_0034B248 */
