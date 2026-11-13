/* func_L05_003C28C8: near miss (file L05_003C0EA8.c). 29 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as): the float constants of the big state init get other $f registers and stores another schedule (0x194 / 0x190, 0x3E / 0x39); offset-sorted and 30 random store orders tried */
#include "common.h"
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern vu0_v4 D_L05_001EA6E0[];

s32 func_L05_003C28C8(u8 *m) {
    u8 *v;
    vu0_v4 a;
    vu0_v4 b;
    s32 f;

    *(s32 *)(m + 0x78) = 0x7F107F10;
    v = *(u8 **)(m + 0x68);
    *(vu0_q *)(v + 0x340) = *(vu0_q *)(m + 0x10);
    *(vu0_q *)(v + 0x330) = *(vu0_q *)(m + 0xF0);
    if (*(s32 *)(v + 0x2F4) != 0) {
        *(u16 *)(m + 0x34) |= 0x100;
        func_0038CF68(&a, m + 0xE0, -2.0f);
        func_0038CF68(&b, m + 0xE0, 0.5f);
        vec_add_ba(&b, &b, m + 0x10);
        vec_add_ba(&a, &a, m + 0x10);
        if (func_003D3CB0(&b, &a, 0, m, 0) != 0) {
            *(vu0_q *)(m + 0x10) = *(vu0_q *)&D_L05_001EA6E0[0];
            func_L01_004515D8(m + 0xC0, &D_L05_001EA6E0[2], 0);
        }
    }
    f = *(s32 *)(v + 0xA8);
    *(vu0_q *)(v + 0x310) = *(vu0_q *)(m + 0x10);
    v[0x170] = 0xB;
    v[0x1A8] = 3;
    *(f32 *)(v + 0x194) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    v[0x1DB] = 0xFF;
    *(s32 *)(v + 0xA8) = f | 1;
    *(f32 *)(v + 0x70) = 0.45f;
    *(f32 *)(v + 0x74) = 0.1f;
    *(f32 *)(v + 0x7C) = 60.0f;
    *(f32 *)(v + 0x80) = 2.0943952f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x190) = 0.5f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    *(f32 *)(v + 0x78) = 1.0f;
    *(s32 *)(v + 0x9C) = 0;
    if (*(s32 *)(v + 0x2F4) == 0) {
        *(s32 *)(v + 0xA8) = f | 5;
    }
    func_L01_0045BD78(m, 0.0064000003f, 0.100000009f, 0.0100530973f, 0.251327425f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(f32 *)(v + 0x30) = 1.0f;
        *(s16 *)(v + 0x34) = 1;
    }
    v[0x3E] = 1;
    v[0x39] = 1;
    *(f32 *)(v + 0x40) = 0.75f;
    func_L01_004450F0(m, 3, 0);
    if (m[0x43] != 3) {
        func_003C3A10(m, 3, 0, 0);
    }
    if (*(s32 *)(v + 0x2F0) != -1) {
        func_L01_004450F0(m, 1, -1);
    }
    return 0;
}
