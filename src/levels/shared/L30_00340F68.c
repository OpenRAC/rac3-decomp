#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_00340F68 */
extern void func_003C5180(void *, void *, s32);
extern s32 func_00382468(s32);
extern void func_L30_00340BA8(u8 *);
extern void func_L30_003410F0(u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_003C2880(u8 *);
extern s32 func_0038CAD0(void *);

void func_L30_00340F68(u8 *obj) {
    u128_t loc[3];
    u8 *pl = *(u8 **)(obj + 0x68);
    u128_t *pos = (u128_t *)(obj + 0x10);

    *pos = **(u128_t **)(pl + 0x24);
    loc[0] = *pos;
    func_003C5180(pos, &loc[1], 1);
    loc[2] = *pos;
    switch (obj[0x20]) {
    case 0:
        obj[0x20] = 1;
        *(u16 *)(obj + 0x34) |= 0x41;
        *(u16 *)(obj + 0x96) = func_00382468(0xFFFF);
        break;
    case 1:
        func_L30_00340BA8(obj);
        func_L01_00404A10(func_L30_003410F0, obj);
        break;
    }
    if (*(float *)(obj + 0x10) < 2.0f || *(float *)(obj + 0x10) > 1021.0f
        || *(float *)(obj + 0x14) < 2.0f || *(float *)(obj + 0x14) > 1021.0f
        || *(float *)(obj + 0x18) < 2.0f || *(float *)(obj + 0x18) > 1021.0f
        || *(s32 *)(pl + 0x2C) == 0) {
        func_003C2880(obj);
    } else {
        u16 *cp = (u16 *)(obj + 0x96);
        *cp = *cp + 1;
        if (*cp > 0xFFFE) {
            *cp = 0;
        }
        if (*(s32 *)(pl + 0x2C) != -1) {
            func_0038CAD0(pl + 0x2C);
        }
    }
}
/* localdecomp:end func_L30_00340F68 */

/* localdecomp:start func_L30_003410F0 */
void func_L30_00341218(void *, int, int, int, float, float, float, int, int);
void func_L30_003410F0(int *a) {
    S *s = *(S **)((char *)a + 0x68);
    if (s != 0) {
        if (s->f2A == 0) {
            func_L30_00341218(s->f30, s->f28, s->f29, 5, s->f10, s->f14, s->f18, s->f0, s->f4);
        } else {
            if (s->f2B != 0) {
                func_L30_00341218(s->f30, s->f28, s->f29, 5, s->f10, s->f14, s->f18, 0xBFBFBF, 0xBFBFBF);
            } else {
                func_L30_00341218(s->f30, s->f28, s->f29, 5, s->f10, s->f14, s->f18, s->f0, s->f4);
            }
            func_L30_00341218(s->f30, s->f28 << 1, s->f29 << 1, 5, s->f10 * 0.0001f, s->f14 + s->f14, s->f18 * 1.15f, s->f0, s->f4);
        }
    }
}
/* localdecomp:end func_L30_003410F0 */

INCLUDE_ASM("asm/levels", func_L30_00341218);
