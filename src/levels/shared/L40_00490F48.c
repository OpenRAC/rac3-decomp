#include "common.h"

/* localdecomp:start func_L40_00490F48 */
typedef int u128_00490F48 __attribute__((mode(TI)));

typedef struct {
    u128_00490F48 pos;
    s16 idx[8];
    s16 x20;
    s16 n0;
    s16 n2;
    s16 n1;
    u8 pad28[0x4];
    s32 *l0;
    s32 *l2;
    s32 *l1;
    s32 x38;
    u8 pad3C[0x4];
} S_00490F48;

extern s32 D_L40_00248630;
extern s32 D_L40_00248628;
extern u8 D_L40_002433F8[];
extern S_00490F48 D_L40_002996E0_00490F48[];
extern u8 D_L40_002926E0_00490F48[];
extern void func_L01_004A0A78_00490F48(u8 *);
extern s32 func_L40_00490D80(void *, s32);

s32 func_L40_00490F48(u128_00490F48 *pos, s16 x20, s32 *l0, s16 n0, s32 *l2, s16 n2, s32 *l1, s16 n1, s32 x38) {
    S_00490F48 *e;
    u8 *p;
    s16 *q;
    s32 i, j, k;

    if (D_L40_00248630 >= 64) {
        func_L01_004A0A78_00490F48(D_L40_002433F8);
    }
    e = &D_L40_002996E0_00490F48[D_L40_00248630++];
    e->pos = *pos;
    e->x20 = x20;
    e->n0 = n0;
    e->n2 = n2;
    e->n1 = n1;
    e->l0 = l0;
    e->l2 = l2;
    e->l1 = l1;
    e->x38 = x38;
    for (k = 0; k < 8; k++) {
        e->idx[k] = -1;
    }
    q = e->idx;
    p = D_L40_002926E0_00490F48;
    j = 0;
    for (i = 0; i < D_L40_00248628; p += 0x60, i++) {
        if (func_L40_00490D80(p, D_L40_00248630 - 1)) {
            *q++ = i;
            if (++j >= 8) {
                break;
            }
        }
    }
    return D_L40_00248630 - 1;
}
/* localdecomp:end func_L40_00490F48 */
