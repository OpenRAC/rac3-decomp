#include "common.h"

/* NTSC-U counterpart of func_L12_003D5D08 (src/levels/shared/L12_003D5D08.c): 60 Hz values (1/60 step, gravity 0.00584 * 25/36, lifetime without the 5/6 scale) */
/* localdecomp:start func_L12_003D4058 */
typedef struct {
    f32 x, y, z, w;
    u8 p10[0x460 - 0x10];
} E_003D4058;
typedef struct {
    u8 p0[0x170];
    u8 *p170;
} T_003D4058;
typedef struct { f32 x, y, z, w; } V_003D4058;
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern E_003D4058 D_L12_001E2800[];
extern T_003D4058 D_L12_00220E58;
extern s32 D_L12_001DEFF4;
__asm__(".extern D_L12_001DEFF4, 4");
extern s32 D_L12_001DEFF8;
__asm__(".extern D_L12_001DEFF8, 4");
extern s32 D_L12_001DEFFC;
__asm__(".extern D_L12_001DEFFC, 4");
extern u32 D_L12_001DF024;
__asm__(".extern D_L12_001DF024, 4");
extern u32 D_L12_001DF028;
__asm__(".extern D_L12_001DF028, 4");
extern u32 D_L12_001DF02C;
__asm__(".extern D_L12_001DF02C, 4");
extern u32 D_L12_001DF030;
__asm__(".extern D_L12_001DF030, 4");
extern f32 func_L12_003D3D70(void);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
/* the same function with its int argument after the floats (EABI: the same registers) */
typedef u8 *(*Spawn_003D4058)(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);

void func_L12_003D4058(void *o, void *unused) {
    u8 *self = o;
    V_003D4058 pos;
    V_003D4058 vel;
    E_003D4058 *p;
    f32 ang;
    f32 a;
    f32 s;
    f32 t;
    s32 n;
    s32 i;
    s32 j;
    s32 life;
    u8 *q;

    p = &D_L12_001E2800[D_001D52F0];
    ang = func_00388A28(p->x - *(f32 *)(self + 0x10), p->y - *(f32 *)(self + 0x14));
    for (i = 0; i < D_L12_001DEFF4; i++) {
        u8 *g = D_L12_00220E58.p0;
        n = func_L01_00440918(2.0f, 5.0f);
        pos.x = *(f32 *)(self + 0x10) + func_L12_003D3D70() * 0.1f * 1.75f;
        pos.y = *(f32 *)(self + 0x14) + func_L12_003D3D70() * 0.1f * 1.75f;
        pos.z = *(f32 *)(self + 0x18) + func_L12_003D3D70() * 0.1f * 1.75f * 0.25f;
        s = func_0037E250(0.6f, 1.0f) * 1.75f;
        t = func_0037E250(9.0f, 12.0f) * 1.75f;
        a = func_00389380(ang, func_L01_00440918(0.0f, 1.3962634f));
        t *= 0.016666668f;
        vel.x = func_00388960(a) * t;
        vel.y = func_00388978(a) * t;
        vel.z = 0.0f;
        t = func_0037E250(0.0f, 12.0f) * 1.75f;
        vel.z = t * 0.016666668f * 0.25f;
        ((Spawn_003D4058)func_L01_0046DCB8)(&pos, &vel, func_0037E208(30, 50), D_L12_001DF024, n, 0x7F, 0x7F,
                          s * 210000.0f, 3675.0f, 0.004055556f, 1);
        n = -(n * 2);
        life = func_0037E208(30, 50);
        s *= 6.0f;
        q = ((Spawn_003D4058)func_L01_0046DCB8)(&pos, &vel, life, D_L12_001DF028, n, 0x30, 0x30,
                              s * 210000.0f, 7350.0f, 0.004055556f, 0);
        if (q != 0) {
            q[2] = (*(u8 **)(g + 0xD4))[0];
        }
    }
    for (j = 0; j < D_L12_001DEFF8; j++) {
        n = func_L01_00440918(2.0f, 5.0f);
        pos.x = *(f32 *)(self + 0x10) + func_L12_003D3D70() * 0.1f * 1.75f;
        pos.y = *(f32 *)(self + 0x14) + func_L12_003D3D70() * 0.1f * 1.75f;
        pos.z = *(f32 *)(self + 0x18) + func_L12_003D3D70() * 0.1f * 1.75f * 0.25f;
        s = func_0037E250(0.75f, 1.5f) * 1.75f;
        t = func_0037E250(9.0f, 12.0f) * 1.75f;
        a = func_00389380(ang, func_L01_00440918(0.0f, 1.3962634f));
        t *= 0.016666668f;
        vel.x = func_00388960(a) * t;
        vel.y = func_00388978(a) * t;
        vel.z = 0.0f;
        t = func_0037E250(0.0f, 12.0f) * 1.75f;
        vel.z = t * 0.016666668f * 0.25f;
        ((Spawn_003D4058)func_L01_0046DCB8)(&pos, &vel, func_0037E208(30, 50), D_L12_001DF02C, n, 0x7F, 0x7F,
                          s * 210000.0f, 3675.0f, 0.004055556f, 5);
    }
    for (j = 0; j < D_L12_001DEFFC; j++) {
        n = func_L01_00440918(2.0f, 5.0f);
        pos.x = *(f32 *)(self + 0x10) + func_L12_003D3D70() * 0.1f * 1.75f;
        pos.y = *(f32 *)(self + 0x14) + func_L12_003D3D70() * 0.1f * 1.75f;
        pos.z = *(f32 *)(self + 0x18) + func_L12_003D3D70() * 0.1f * 1.75f * 0.25f;
        s = func_0037E250(0.6f, 1.0f) * 1.75f;
        t = func_0037E250(9.0f, 12.0f) * 1.75f;
        a = func_00389380(ang, func_L01_00440918(0.0f, 1.3962634f));
        t *= 0.016666668f;
        vel.x = func_00388960(a) * t;
        vel.y = func_00388978(a) * t;
        vel.z = 0.0f;
        t = func_0037E250(0.0f, 12.0f) * 1.75f;
        vel.z = t * 0.016666668f * 0.25f;
        ((Spawn_003D4058)func_L01_0046DCB8)(&pos, &vel, func_0037E208(30, 50), D_L12_001DF030, n, 0x7F, 0x7F,
                          s * 210000.0f, 3675.0f, 0.004055556f, 3);
    }
}
/* localdecomp:end func_L12_003D4058 */
