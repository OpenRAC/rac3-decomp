#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_00302118);

INCLUDE_ASM("asm/levels", func_L01_00303228);

/* localdecomp:start func_L01_00303658 */
extern void *D_L01_001DFC34[];
extern void func_003CD250(void *);
extern void func_003C2880(u8 *);

void func_L01_00303658(u8 *m) {
    void **p = (void **)(*(u8 **)(m + 0x68) + 0x30);
    s32 i;

    for (i = 7; i >= 0; i--, p++) {
        if (*p != 0) {
            func_003CD250(*p);
            *p = 0;
        }
    }
    if (D_L01_001DFC34[0] == m) {
        m[0x20] = 4;
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_00303658 */

INCLUDE_ASM("asm/levels", func_L01_003036D8);

/* localdecomp:start func_L01_00303C00 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern s32 func_L01_0046B9E8(void *, s32, s32, s32, f32, f32);
extern void func_003C7C38(u8 *);

u8 *func_L01_00303C00(u8 *parent, f32 *dir, vu0_q *pos, f32 scale) {
    u8 *p;
    u8 *s;
    f32 a;

    p = func_003C24B0(0x3A6, 0x80);
    if (p != 0) {
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0xFF;
        p[0x31] = 1;
        p[0x20] = 0;
        s = *(u8 **)(p + 0x68);
        *(unsigned long *)(p + 0x38) = *(unsigned long *)(parent + 0x38);
        *(vu0_q *)(p + 0x10) = *pos;
        *(vu0_q *)s = *(vu0_q *)dir;
        *(s32 *)(s + 0x38) = 0xC8;
        *(u8 **)(s + 0x3C) = parent;
        *(f32 *)(s + 0x40) = scale;
        *(f32 *)(p + 0xF8) = func_0038D160(dir[0], dir[1]);
        a = func_0038D160(func_0038CED8(dir), dir[2]);
        *(f32 *)(p + 0xF4) = -a;
        *(s32 *)(s + 0x48) = func_L01_0046B9E8(p, -1, 0xF0208080, 0x60, 0.1f, 0.01f);
        func_003C7C38(p);
        *(u16 *)(p + 0x34) |= 1;
        p[0x31] = 0;
    }
    return p;
}
/* localdecomp:end func_L01_00303C00 */

/* localdecomp:start func_L01_00303D30 */
extern u8 *func_003C24B0(s32, s32);
u8 *func_L01_00303D30(f32 *p, s32 a1) {
    u8 *m;
    m = func_003C24B0(1007, 128);
    if (m != 0) {
        m[48] = 255;
        *(u16 *)(m + 52) |= 65;
        if (p[0] < 2.0f || p[0] > 1021.0f || p[1] < 2.0f || p[1] > 1021.0f || p[2] < 2.0f || p[2] > 1021.0f) {
            *(s32 *)(m + 28) = 0;
            *(f32 *)(m + 16) = 10.0f;
            *(f32 *)(m + 20) = 10.0f;
            *(f32 *)(m + 24) = 10.0f;
        } else {
            *(u128_t *)(m + 16) = *(u128_t *)p;
        }
        m[188] = a1;
    }
    return m;
}
/* localdecomp:end func_L01_00303D30 */
