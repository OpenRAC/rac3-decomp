#include "common.h"

LINKER_REMNANT("asm/levels", func_L40_00490D70);

/* localdecomp:start func_L40_00490D80 */
typedef struct {
    u8 pad0[0x22];
    s16 n0;
    s16 n2;
    s16 n1;
    u8 pad28[0x8];
    s32 *l0;
    s32 *l2;
    s32 *l1;
    u8 pad3C[0x4];
} S_00490D80;

extern S_00490D80 D_L40_002996E0[];
extern s32 func_L40_00491588(void *, s32);
extern s32 func_L40_00491620(void *, s32);
extern s32 func_L40_004916B0(void *, s32);

s32 func_L40_00490D80(void *a0, s32 a1) {
    S_00490D80 *e = &D_L40_002996E0[a1];
    s32 i;

    for (i = 0; i < e->n0; i++) {
        if (func_L40_00491588(a0, e->l0[i])) {
            return 1;
        }
    }
    for (i = 0; i < e->n1; i++) {
        if (func_L40_00491620(a0, e->l1[i])) {
            return 1;
        }
    }
    for (i = 0; i < e->n2; i++) {
        if (func_L40_004916B0(a0, e->l2[i])) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L40_00490D80 */
