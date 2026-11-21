#include "common.h"

/* NTSC-U counterpart of func_L39_00532BE0 (src/levels/shared/L39_00532550.c) */
#include "vu0.h"
extern vu0_v4 D_L39_002440A0_00532550 __attribute__((section(".sdata")));
extern void func_003886E8(void *, void *, f32);
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
} M_00532698;
typedef struct {
    u8 pad0[0x18];
    M_00532698 *f18;
    u8 pad1C[0x4];
    vu0_v4 f20;
    u8 pad30[0x10];
    vu0_v4 f40;
} G_00532698;
typedef struct {
    u8 pad0[0x300];
    u8 b300;
    u8 pad301[7];
    f32 f308;
} S_00532698;
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L39_00532580 */
typedef int u128_00532BE0 __attribute__((mode(TI)));

__asm__(".extern D_L39_0024AD90_00532580, 4");
extern f32 D_L39_0024AD90_00532580;
__asm__(".extern D_L39_0024AD94_00532580, 4");
extern f32 D_L39_0024AD94_00532580;
__asm__(".extern D_L39_0024AD9C_00532580, 4");
extern f32 D_L39_0024AD9C_00532580;
__asm__(".extern D_L39_0024ADB0_00532580, 4");
extern f32 D_L39_0024ADB0_00532580;
__asm__(".extern D_L39_0024ADB4, 4");
extern f32 D_L39_0024ADB4;
__asm__(".extern D_L39_0024ADB8, 4");
extern f32 D_L39_0024ADB8;
__asm__(".extern D_L39_0024ADBC, 4");
extern f32 D_L39_0024ADBC;
__asm__(".extern D_L39_0024ADC0, 4");
extern f32 D_L39_0024ADC0;
__asm__(".extern D_L39_0024ADC4, 4");
extern f32 D_L39_0024ADC4;
__asm__(".extern D_L39_0024ADC8, 4");
extern f32 D_L39_0024ADC8;
__asm__(".extern D_L39_0024ADD8, 4");
extern f32 D_L39_0024ADD8;
__asm__(".extern D_L39_0024ADDC, 4");
extern f32 D_L39_0024ADDC;
__asm__(".extern D_L39_0024ADE0_00532580, 4");
extern f32 D_L39_0024ADE0_00532580;
__asm__(".extern D_L39_0024ADE4, 4");
extern f32 D_L39_0024ADE4;
__asm__(".extern D_L39_0024ADE8, 4");
extern f32 D_L39_0024ADE8;
__asm__(".extern D_L39_0024ADEC, 4");
extern f32 D_L39_0024ADEC;
__asm__(".extern D_L39_0024ADF4, 4");
extern f32 D_L39_0024ADF4;
__asm__(".extern D_L39_0024ADF8, 4");
extern f32 D_L39_0024ADF8;
__asm__(".extern D_L39_0024ADFC, 4");
extern f32 D_L39_0024ADFC;

extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388A28(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L01_0040C1F8(void *, void *, f32);
extern void func_L01_0040C188(void *, void *, f32);
extern void func_L39_00531EF0(u8 *);
extern s32 func_L39_00532038(u8 *, S_00532698 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, s32 *, f32, f32, f32);
extern void func_L39_005BA7E0(void *, void *, void *, void *, f32, f32, f32);
extern void func_L39_00667AC0(void *, f32);

void func_L39_00532580(u8 *a0) {
    s32 back = 0;
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q = *(u8 **)(p + 0x160);
    f32 t0 = *(f32 *)(q + 0x310);
    u8 *g = *(u8 **)(q + 0x2D8);
    vu0_v4 v;
    struct {
        u128_00532BE0 a;
        u128_00532BE0 pos;
    } out;
    s32 k;
    u8 *pp;
    f32 x;
    f32 ang;
    f32 rot;
    f32 roll;

    k = 0;
    if (t0 < -0.0083333338f) {
        back = 1;
    }
    out.pos = *(u128_00532BE0 *)(a0 + 0x10);
    x = D_L39_0024AD90_00532580;
    if (g != 0) {
        f32 t = *(f32 *)(*(u8 **)(g + 0x2534) + 0x10C);
        if (t < 0.0f) {
            x *= -t;
        } else {
            x = D_L39_0024AD94_00532580 * -t;
        }
        if (x != 0.0f) {
            func_L01_00445168((f32 *)(q + 0x310), (f32 *)(p + 0x148), x * 0.016666668f, D_L39_0024ADB8,
                              D_L39_0024ADBC, D_L39_0024ADB4 * 0.00027777778f);
        } else {
            func_L01_00445168((f32 *)(q + 0x310), (f32 *)(p + 0x148), 0.0f, D_L39_0024ADC4,
                              D_L39_0024ADC8, D_L39_0024ADC0 * 0.00027777778f);
        }
    } else {
        func_L01_00445168((f32 *)(q + 0x310), (f32 *)(p + 0x148), 0.0f, D_L39_0024ADDC,
                          D_L39_0024ADE0_00532580, D_L39_0024ADD8 * 0.00027777778f);
    }
    {
        f32 t = *(f32 *)(q + 0x310);
        if (t < 0.0f) {
            ang = -t;
        } else {
            ang = t;
        }
    }
    if (g != 0) {
        roll = *(f32 *)(g + 0x110) * D_L39_0024ADB0_00532580;
        if (back) {
            *(f32 *)(a0 + 0xF8) = func_003893C8(*(f32 *)(a0 + 0xF8), roll * 0.017453292f * 0.016666668f);
        } else {
            *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), roll * 0.017453292f * 0.016666668f);
        }
    }
    roll = 0.0f;
    if (q[0x300] != 0) {
        rot = func_00388A28(*(f32 *)(q + 0x270), *(f32 *)(q + 0x274));
    } else {
        roll = -*(f32 *)(a0 + 0xF4);
        if (back) {
            rot = func_00389380(*(f32 *)(a0 + 0xF8), 3.1415927f);
        } else {
            rot = *(f32 *)(a0 + 0xF8);
        }
    }
    func_0037E4B8(&v, ang, rot, roll);
    pp = q + 0x270;
    func_003886E8(&v, &v, D_L39_0024AD9C_00532580);
    vec_add_ab(q + 0x270, q + 0x270, &v);
    if (q[0x300] != 0) {
        *(f32 *)(q + 0x278) = *(f32 *)(p + 0xF8) - D_L39_0024ADE4 * 0.00027777778f;
        func_L01_0040C1F8(pp, pp, ang);
    } else {
        func_L01_0040C188(pp, pp, ang);
    }
    func_L39_00531EF0(a0);
    if (q[0x300] == 0) {
        func_L39_005BA7E0(a0 + 0xC0, a0 + 0xF0, q + 0x284, p + 0x100, D_L39_0024ADF4, D_L39_0024ADF8,
                          D_L39_0024ADFC);
    } else {
        *(u128_00532BE0 *)(p + 0x100) = *(u128_00532BE0 *)&D_L39_002440A0_00532550;
        func_L39_005BA7E0(a0 + 0xC0, a0 + 0xF0, q + 0x284, p + 0x100, D_L39_0024ADF4, D_L39_0024ADF8,
                          D_L39_0024ADFC);
    }
    *(u128_00532BE0 *)(p + 0xF0) = *(u128_00532BE0 *)(q + 0x270);
    if (q[0x300] != 0) {
        (*(u16 *)(q + 0x302))++;
    } else {
        *(u16 *)(q + 0x302) = 0;
        *(f32 *)(p + 0x144) = *(f32 *)(a0 + 0x18);
    }
    func_L39_00532038(a0, (S_00532698 *)q, (vu0_v4 *)(a0 + 0x10), (vu0_v4 *)pp, (vu0_v4 *)&out, &k,
                      fabs_asm(*(f32 *)(q + 0x310)), D_L39_0024ADE8, D_L39_0024ADEC);
    if (g != 0) {
        *(u128_00532BE0 *)(*(u8 **)(g + 0x2524) + 0x10) = *(u128_00532BE0 *)(a0 + 0x10);
        *(u128_00532BE0 *)(*(u8 **)(g + 0x2524) + 0xF0) = *(u128_00532BE0 *)(a0 + 0xF0);
    }
    func_L39_00667AC0(q, 50.0f);
    *(u128_00532BE0 *)(q + 0x230) = *(u128_00532BE0 *)(a0 + 0x10);
    *(u128_00532BE0 *)(q + 0x240) = *(u128_00532BE0 *)(a0 + 0xF0);
    *(u128_00532BE0 *)(q + 0x250) = *(u128_00532BE0 *)(a0 + 0x10);
    *(u128_00532BE0 *)(q + 0x260) = *(u128_00532BE0 *)(a0 + 0xF0);
}
/* localdecomp:end func_L39_00532580 */
