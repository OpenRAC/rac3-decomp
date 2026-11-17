/* near miss (level 13: the C is retail's, every instruction matches; the level build fails on the fill after it, see nonmatching/README.md) */
#include "common.h"

/* localdecomp:start func_L13_003D2690 */
typedef struct {
    char _p0[0x28];
    f32 f28;
    s32 f2C;
} S_003D2690b;
typedef struct {
    s16 f0;
    char _p2[6];
    S_003D2690b *f8;
    char _pC[0x90 - 0xC];
} S_003D2690;

extern S_003D2690 *D_001A316C __attribute__((section(".data")));

void func_L13_003D2690(s32 a0, s32 a1, s32 a2) {
    S_003D2690 *p = &D_001A316C[a0];

    if (p->f0 == 10 && a1 < 4) {
        S_003D2690b *q = p->f8;

        q->f2C = a1;
        q->f28 = a2;
    }
}
/* localdecomp:end func_L13_003D2690 */
