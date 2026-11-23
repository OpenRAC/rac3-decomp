#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_003BE5A0 (src/levels/shared/L01_003BE598.c): 60 Hz constants (1/3600, 0.7/60) */
/* localdecomp:start func_L01_003BCD58 */
typedef int s128_003BCD58 __attribute__((mode(TI)));
typedef union { s128_003BCD58 q; f32 f[4]; } V_003BCD58;
typedef struct {
    u8 pad[0x38];
    f32 f38;
    u8 pad3C[0x180 - 0x3C];
    s128_003BCD58 v180;
    s128_003BCD58 v190;
    s128_003BCD58 v1A0;
    u8 pad1B0[0x1D0 - 0x1B0];
    s32 w1D0;
} P_003BCD58;
typedef struct {
    u8 pad[0x10];
    s128_003BCD58 pos;
    u8 pad20[0x68 - 0x20];
    P_003BCD58 *p68;
} M_003BCD58;
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_L01_001DEBC0;
extern f32 D_L01_001DEBC4;
__asm__(".extern D_L01_001DEBC0, 4");
__asm__(".extern D_L01_001DEBC4, 4");
extern s32 D_001A71A0[];
typedef struct { u128_t position, normal; } HitPair_003BCD58;
extern HitPair_003BCD58 D_L01_001EAAB0;
extern vu0_v4 D_L01_001EAAA0;
extern f32 func_00389380(f32, f32);
extern void func_003BFD10(void *, void *, void *, f32);
extern s32 func_L01_003F9498(void *, s32, s32, f32);
extern f32 func_00388730(void *, void *);
extern void func_L01_0040C260(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, M_003BCD58 *, s32);
extern f32 func_00388770(void *);
extern s32 func_00388398(void *);
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_004493C0(u8 *, M_003BCD58 *, void *, void *, void *, void *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L01_00444F38_003BCD58(s32, s32, f32);
extern void func_003BD360(u8 *);
void func_L01_003BCD58(u8 *m) {
    V_003BCD58 a, b;
    u8 *p = *(u8 **)(m + 0x68);
    f32 *velocity;
    u8 *pos;
    u8 *ground_pos;
    u8 *normal;
    f32 fade;
    s32 one = 1;
    u8 *hit;
    M_003BCD58 *object;
    switch (m[0x20]) {
    case 0:
        pos = m + 0x10;
        a.q = *(u128_t *)pos;
        velocity = (f32 *)(p + 0x20);
        *(f32 *)(m + 0xF8) = func_00389380(*(f32 *)(m + 0xF8), *(f32 *)(p + 8));
        vec_add_ab(pos, pos, velocity);
        func_003BFD10(pos, velocity, velocity, D_L01_001DEBC0 * 0.00027777778f);
        if (func_L01_003F9498(pos, 4, D_001A71A0[0], 0.07f)) {
            *(u128_t *)pos = D_L01_001EAAB0.position;
            normal = (u8 *)&D_L01_001EAAB0.normal;
            if (func_00388730(velocity, normal) < 0.0f) {
                func_L01_0040C260(velocity, velocity, normal);
                func_003886E8(velocity, velocity, 0.15f);
            }
            goto speed_check;
        } else if (func_003CE740(&a, pos, 2, 0, 0)) {
            *(u128_t *)pos = *(u128_t *)&D_L01_001EAAA0;
            func_L01_0040C260(velocity, velocity, (u8 *)&D_L01_001EAAA0 + 0x20);
            func_003886E8(velocity, velocity, 0.15f);
speed_check:
            if (func_00388770(velocity) < 0.011666667f) {
                m[0x20] = one;
                break;
            }
        }
        if (func_00388398(p) || *(f32 *)(m + 0x10) < 2.0f || *(f32 *)(m + 0x10) > 1021.0f ||
            *(f32 *)(m + 0x14) < 2.0f || *(f32 *)(m + 0x14) > 1021.0f ||
            *(f32 *)(m + 0x18) < 2.0f) goto destroy;
        if (!(*(f32 *)(m + 0x18) > 1021.0f)) break;
        goto destroy;
    case 1:
        if (func_L01_00452EC8(m)) {
            a.q = *(u128_t *)(m + 0x10);
            a.f[2] += 1.0f;
            b.q = a.q;
            b.f[2] = 0.0f;
            if (func_003CE740(&a, &b, 0, (M_003BCD58 *)m, 0)) *(f32 *)(m + 0x18) = D_L01_001EAAA0.z + 0.057f;
        } else {
            ground_pos = m + 0x10;
            a.q = *(u128_t *)ground_pos;
            a.f[2] += 1.0f;
            b.q = a.q;
            b.f[2] = 0.0f;
            if (func_003CE740(&a, &b, 0, (M_003BCD58 *)m, 0)) {
                /* The collision record starts 0x20 bytes before its position vector. */
                hit = (u8 *)&D_L01_001EAAA0 - 0x20;
                object = *(M_003BCD58 **)(hit + 0x18);
                if (object != 0) func_L01_004493C0(m, object, ground_pos, m + 0xF0, ground_pos, m + 0xF0);
                else *(f32 *)(m + 0x18) = *(f32 *)(hit + 0x28) + 0.057f;
            }
        }
        if (m[0x95] == 1) func_L01_00441FB8(m, 2, -1);
        break;
    case 2:
        if (func_L01_00452EC8(m)) *(u16 *)(m + 0x34) |= 0x2800;
        ground_pos = m + 0x10;
        a.q = *(u128_t *)ground_pos;
        a.f[2] += 1.0f;
        b.q = a.q;
        b.f[2] = 0.0f;
        if (func_003CE740(&a, &b, 0, (M_003BCD58 *)m, 0)) {
            hit = (u8 *)&D_L01_001EAAA0 - 0x20;
            object = *(M_003BCD58 **)(hit + 0x18);
            if (object != 0) func_L01_004493C0(m, object, ground_pos, m + 0xF0, ground_pos, m + 0xF0);
            else *(f32 *)(m + 0x18) = *(f32 *)(hit + 0x28) + 0.057f;
        }
        fade = (f32)*(u16 *)(m + 0x96) / D_L01_001DEBC4;
        fade = 1.0f < fade ? 1.0f : fade;
        m[0x23] = func_L01_00444F38_003BCD58(128, 0, fade);
        if (m[0x23] < 2) {
destroy:
            func_003BD360(m);
            return;
        }
        break;
    }
    (*(u16 *)(m + 0x96))++;
}
/* localdecomp:end func_L01_003BCD58 */
