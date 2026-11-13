#include "common.h"

/* localdecomp:start func_L39_005D7C18 */
typedef struct {
    char pad0[0x20C];
    s32 *tbl;
} S_005D7C18;
extern s32 D_L39_00352B34[];
extern S_005D7C18 D_L39_00352940;

void func_L39_005D7C18(s32 *mode, f32 *a, f32 *b, f32 *c, s32 *n0, s32 *n1) {
    s32 i;
    s32 v;
    s32 t;
    S_005D7C18 *q;
    s32 *t2;

    t = D_L39_00352B34[0];
    *mode = t;
    switch (t) {
    case 4:
        *a = -0.144f;
        *b = 0.06f;
        *c = 0.0718f;
        break;
    case 5:
        *a = -0.151f;
        *b = 0.046f;
        *c = 0.057f;
        break;
    case 6:
        *a = -0.154f;
        *b = 0.0376f;
        *c = 0.047f;
        break;
    default:
        *a = -0.159f;
        *b = 0.03f;
        *c = 0.041f;
        break;
    }
    *n0 = 0;
    *n1 = 0;
    q = &D_L39_00352940;
    for (i = 0; i < 8; i++) {
        t2 = q->tbl + 42;
        v = t2[i];
        if (v == 0) {
            *n0 += 1;
        } else if (v == 1) {
            *n1 += 1;
        }
    }
}
/* localdecomp:end func_L39_005D7C18 */

INCLUDE_ASM("asm/levels", func_L39_005D7D80);
