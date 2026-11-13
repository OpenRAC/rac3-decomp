#include "common.h"

/* NTSC-U counterpart of func_L01_003B8190 (src/levels/01_veldin/L01_003B8190.c): 0.02 -> 0.0166667; 125 -> 150 */
/* localdecomp:start func_L01_003B6990 */
typedef struct { u8 p0[0x20]; f32 f20; u8 p24[4]; s32 f28; s32 f2C; } S_83C0_G;
typedef struct { u8 p0[0x5F]; u8 b5F; } S_83C0_D;
typedef struct { u8 p0[0x64]; void *f64; S_83C0_D *f68; } S_83C0_R;
typedef struct { u8 p0[0x7C]; u16 h7C; } S_83C0_O;
extern S_83C0_G D_L01_001E2AC0;
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(f32 *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern S_83C0_R *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_003E1A20(void);
extern void func_003C2880(void *);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_8190;
typedef struct { Q_8190 q; void *a; s32 b; s32 c; f32 d; s32 e; s32 pad[3]; } S_8190_X;
extern u8 D_L01_001D66B0_003B6990;
extern f32 D_L01_001DE7A0, D_L01_001DE7A4, D_L01_001DE7A8, D_L01_001DE7AC, D_L01_001DE7B0;
__asm__(".extern D_L01_001DE7A0, 4");
__asm__(".extern D_L01_001DE7A4, 4");
__asm__(".extern D_L01_001DE7A8, 4");
__asm__(".extern D_L01_001DE7AC, 4");
__asm__(".extern D_L01_001DE7B0, 4");
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003D4D00(f32 *, s32, f32, void *, void *);
void func_L01_003B6990(S_83C0_O *a0) {
    f32 vec[4];
    S_8190_X x;
    Q_8190 vec2;
    u8 *o;
    f32 s;
    S_83C0_R *r;
    o = (u8 *)func_L01_00444358(a0, -1, 0);
    if (o != 0) {
        func_003A52A0(0, 0, a0);
        D_L01_001E2AC0.f20 = 0.2f;
        D_L01_001E2AC0.f28 = 0x96;
        D_L01_001E2AC0.f2C = 0;
        func_0038CF68(vec, o + 0x10, D_L01_001DE7A0 * 0.0166666675f);
        s = func_003824E0(8.0f, 12.0f);
        r = func_L01_003F5830(a0, 2, 0x1A53, 0, (u8 *)a0 + 0x10, (u8 *)a0 + 0xF0, vec, 0xFF, s, D_L01_001DE7A4, func_00382498(0x78, 0xB4), 0, 0x80);
        r->f64 = func_L01_003E1A20;
        a0->h7C &= ~1;
        r->f68->b5F = 8;
        s = func_003824E0(10.0f, 20.0f);
        func_L01_0044ED60(a0, 0x1FE, &D_L01_001D66B0_003B6990, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, D_L01_001DE7A8 * 0.6f, D_L01_001DE7A8, D_L01_001DE7AC * 0.5f, D_L01_001DE7AC, s, -1.0f, 1.0f, 1.0f);
        x.q = *(Q_8190 *)((u8 *)a0 + 0xC0);
        x.a = a0;
        x.d = 2.0f;
        x.e = 0;
        func_0038CF68(&vec2.x, (u8 *)a0 + 0xE0, 0.5f);
        vec2 = *(Q_8190 *)((u8 *)a0 + 0x10);
        x.b = 0x8000000;
        vec2.z += D_L01_001DE7B0;
        func_003D4D00(&vec2.x, 0x10, 10.0f, a0, &x);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003B6990 */
