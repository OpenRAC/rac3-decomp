#include "common.h"

/* NTSC-U counterpart of func_L11_003AB258 (src/levels/11_obani_moons/L11_003A9E60.c) */
#include "vu0.h"
extern s32 func_L11_003A9580(u8 *);

/* localdecomp:start func_L11_003A9580 */
extern vu0_v4 D_L11_001E84E0_003A9580;
extern void func_003BFC18(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

s32 func_L11_003A9580(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m2[4];
    vu0_q qp, qa, qb;

    func_003BFC18(a0 + 0x10, m, 0);
    func_L01_0044E358(a0 + 0xC0, &m[0], &m[1]);
    *(s16 *)(a0 + 0x7C) = 0xFF;
    func_00388830(&a, a0 + 0xE0, 0.5f);
    func_00388830(&b, a0 + 0xE0, -4.0f);
    /* a + pos and b + pos with one load of the position (VU0) */
    __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qp));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qa));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qp));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(qb));
    if (func_003CE740(&a, &b, 2, a0, 0) != 0) {
        *(vu0_v4 *)(a0 + 0x10) = D_L11_001E84E0_003A9580;
        func_003BFC18(a0 + 0x10, m2, 0);
        func_L01_0044E358(a0 + 0xC0, &m2[0], &m2[1]);
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
    *(f32 *)(v + 0x9C) = 0.0027222224f;
    func_L01_00458A70(a0, 0.0044444446f, 0.10000001f, 0.0069813174f, 0.20943953f);
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
    func_L01_00441FB8(a0, 2, 0);
    if (a0[0x43] != 0) {
        func_003BE4F0(a0, 0, 0, 0);
    }
    if (*(s32 *)(v + 0x2E8) != -1) {
        func_L01_00441FB8(a0, 9, -1);
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 10);
        }
    } else if (*(s32 *)(v + 0x2EC) == 0) {
        func_L01_00441FB8(a0, 10, -1);
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 10);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003A9580 */
