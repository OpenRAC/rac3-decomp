#include "common.h"

/* NTSC-U counterpart of func_L09_003BEF00 (src/levels/09_tyhrranosis/L09_003B8580.c) */
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(void *, s32);
extern s32 func_003883C8(void *);
extern f32 func_00388800(void *, void *);
extern s32 func_L09_003BAF18(void *, s32, s32, s32, s32);
extern s32 func_L09_003BBCE8(void *, s32, s32, s32, s32);

/* localdecomp:start func_L09_003BD680 */
extern u8 D_001A4C60[];

s32 func_L09_003BD680(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s16 *h = (s16 *)(p + 0xD34);

    if (*(unsigned long *)(p + 0xD40) & 0x50000) {
        p[0xD42] &= 0xFE;
        func_L01_00441FB8(a0, 0xD, -1);
        func_L01_00442050(a0, 1);
        return 0;
    }
    if (func_003883C8(p + 0xD38)) {
        func_L09_003BAF18(a0, a1, a2, a3, 1);
        return 0;
    }
    if (func_00388800(a0 + 0x10, D_001A4C60) > 25.0f) {
        *h = 0;
        return 1;
    }
    if ((*h)++ >= 600) {
        *h = 0;
        return 1;
    }
    if (p[0xD42] & 2) {
        func_L09_003BBCE8(a0, a1, a2, a3, 1);
    }
    return 0;
}
/* localdecomp:end func_L09_003BD680 */
