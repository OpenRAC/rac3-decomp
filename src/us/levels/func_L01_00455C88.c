#include "common.h"

/* NTSC-U counterpart of func_L01_00458F78 (src/levels/shared/L01_00457F00.c): the count limit is 8 instead of 7 */
/* localdecomp:start func_L01_00455C88 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v0;
    Vec4 pos;
    Vec4 v32;
    u8 pad48[32];
    s32 w80;
    u8 pad84[20];
    u8 *pvars;
} Moby_4559A8;

extern void func_L01_004559A8(Moby_4559A8 *moby, Moby_4559A8 *other);
extern s32 func_L01_00455A60(void *, void *);
extern f32 func_00388800(void *, void *);
extern void func_L01_00454C30(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12);

void func_L01_00455C88(u8 *a, u8 *s, s32 a2, s32 a3) {
    u128_t tmp;
    u8 *p;
    u8 *s2;

    *(s32 *)(s + 0x58) = func_L01_00455A60(a, s);
    if (a2 == 0 && a3 == 0) {
        func_L01_004559A8((Moby_4559A8 *)a, (Moby_4559A8 *)s);
    }
    p = *(u8 **)(s + 0x50);
    if (p != 0) {
        *(u128_t *)(s + 0x10) = *(u128_t *)(p + 0x10);
        tmp = *(u128_t *)(p + 0x10);
    } else {
        tmp = *(u128_t *)(s + 0x10);
    }
    if (*(f32 *)(s + 0x10) == 0.0f && *(f32 *)(s + 0x14) == 0.0f) {
        return;
    }
    if (func_00388800(s + 0x20, &tmp) > 1.0f) {
        *(u128_t *)s = *(u128_t *)(s + 0x10);
        *(u128_t *)(s + 0x20) = *(u128_t *)(s + 0x10);
        func_L01_00454C30(a, s, a2, a3, 12.0f);
        *(u128_t *)(s + 0x70) = *(u128_t *)(a + 0x10);
        *(s32 *)(s + 0x40) = 0;
    }
    s2 = a + 0x10;
    if (func_00388800(s2, s) < 0.75f) {
        *(u128_t *)s = *(u128_t *)(s + 0x10);
        *(u128_t *)(s + 0x20) = *(u128_t *)(s + 0x10);
        func_L01_00454C30(a, s, a2, a3, 12.0f);
        *(u128_t *)(s + 0x70) = *(u128_t *)(a + 0x10);
        *(s32 *)(s + 0x40) = 0;
    }
    if (func_00388800(s2, s + 0x70) > 8.0f) {
        *(u128_t *)s = *(u128_t *)(s + 0x10);
        *(u128_t *)(s + 0x20) = *(u128_t *)(s + 0x10);
        func_L01_00454C30(a, s, a2, a3, 12.0f);
        *(u128_t *)(s + 0x70) = *(u128_t *)(a + 0x10);
        *(s32 *)(s + 0x40) = 0;
    }
    if (*(s32 *)(s + 0x40) >= 8) {
        *(u128_t *)s = *(u128_t *)(s + 0x10);
        *(u128_t *)(s + 0x20) = *(u128_t *)(s + 0x10);
        func_L01_00454C30(a, s, a2, a3, 12.0f);
        *(u128_t *)(s + 0x70) = *(u128_t *)(a + 0x10);
        *(s32 *)(s + 0x40) = 0;
    }
}
/* localdecomp:end func_L01_00455C88 */
