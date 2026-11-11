#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L11_003A9E60);

/* localdecomp:start func_L11_003AB080 */
extern s32 func_L11_003AB258(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L02_00351780(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L02_003516A8(void *);
extern void func_L01_00404A10(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L11_003AB080(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);

    if (a0[0x20] == 0 && func_L11_003AB258(a0) != 0) {
        return 1;
    }
    if (v[0x3E] == 2) {
        goto die;
    }
    if (func_L01_00452FB0(a0, v + 0x160, 0, 0, 0) != 0) {
        func_003A52A0(3, 0, a0);
        func_L02_00351780(a0);
    }
    func_L01_00452860(a0, v + 0x30, 0);
    if (v[0x5E] != 0) {
die:
        func_L02_003516A8(a0);
        return 1;
    }
    if (v[0x5F] != 0) {
        func_L01_00404A10(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00404A10(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003AB080 */

/* localdecomp:start func_L11_003AB258 */
extern vu0_v4 D_L11_001E84E0;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L11_003AB258(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m2[4];
    vu0_q qp, qa, qb;

    func_003C5180(a0 + 0x10, m, 0);
    func_L01_004515D8(a0 + 0xC0, &m[0], &m[1]);
    *(s16 *)(a0 + 0x7C) = 0xFF;
    func_0038CF68(&a, a0 + 0xE0, 0.5f);
    func_0038CF68(&b, a0 + 0xE0, -4.0f);
    /* a + pos and b + pos with one load of the position (VU0) */
    __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qp));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qa));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qp));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qb));
    if (func_003D3CB0(&a, &b, 2, a0, 0) != 0) {
        *(vu0_v4 *)(a0 + 0x10) = D_L11_001E84E0;
        func_003C5180(a0 + 0x10, m2, 0);
        func_L01_004515D8(a0 + 0xC0, &m2[0], &m2[1]);
    }
    *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(a0 + 0x10);
    v[0x170] = 0xB;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.1f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    *(f32 *)(v + 0x19C) = 0.15f;
    v[0x1DA] = 0;
    v[0x1A8] = 3;
    *(u16 *)(a0 + 0x34) |= 0x100;
    *(f32 *)(v + 0x70) = 0.5f;
    *(f32 *)(v + 0x74) = 0.1f;
    *(f32 *)(v + 0x78) = 0.75f;
    *(f32 *)(v + 0x7C) = 1.25f;
    *(f32 *)(v + 0x80) = 1.553343f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 10;
        *(f32 *)(v + 0x30) = 10.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    v[0x3F] = 0;
    *(f32 *)(v + 0x40) = 1.0f;
    func_L01_004450F0(a0, 2, 0);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    if (*(s32 *)(v + 0x2E8) != -1) {
        func_L01_004450F0(a0, 9, -1);
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
    } else if (*(s32 *)(v + 0x2EC) == 0) {
        func_L01_004450F0(a0, 10, -1);
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003AB258 */
