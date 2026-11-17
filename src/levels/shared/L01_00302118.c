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

INCLUDE_ASM("asm/levels", func_L01_00303C00);

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

INCLUDE_ASM("asm/levels", func_L01_00303E30);

/* localdecomp:start func_L01_00304018 */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);
u8 *func_L01_00304018(s32 a0, u128_t *p, u128_t *q, s32 a3, u8 b0, u8 b1, u8 b2, u8 b3, f32 scale) {
    u8 *m;
    u8 *pv;
    Vec4 w;
    Vec4 v;
    m = func_003C24B0(1192, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        v.q = 0;
        v.f[0] = func_003824E0(-3.1415927f, 3.1415927f);
        v.f[1] = func_003824E0(-3.1415927f, 3.1415927f);
        v.f[2] = func_003824E0(-3.1415927f, 3.1415927f);
        w = v;
        m[32] = 0;
        m[35] = b3;
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        func_L01_0043B9E8(m, b0, b1, b2);
        *(f32 *)(pv + 24) = *(f32 *)(m + 44) * scale;
        *(s32 *)(m + 44) = 0;
        *(s32 *)(pv + 16) = a0;
        *(u128_t *)(m + 16) = *p;
        *(u128_t *)pv = *q;
        *(Vec4 *)(m + 240) = w;
        *(s16 *)(pv + 30) = b3;
        *(s32 *)(pv + 20) = a3;
        *(u16 *)(pv + 28) = *(u16 *)(pv + 20);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_00304018 */

INCLUDE_ASM("asm/levels", func_L01_003041A0);
