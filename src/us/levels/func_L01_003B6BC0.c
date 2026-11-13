#include "common.h"

/* NTSC-U counterpart of func_L01_003B83C0 (src/levels/01_veldin/L01_003B8190.c) */
typedef struct { u8 p0[0x20]; f32 f20; u8 p24[4]; s32 f28; s32 f2C; } S_83C0_G;
typedef struct { u8 p0[0x5F]; u8 b5F; } S_83C0_D;
typedef struct { u8 p0[0x64]; void *f64; S_83C0_D *f68; } S_83C0_R;
typedef struct { u8 p0[0x7C]; u16 h7C; } S_83C0_O;
extern S_83C0_G D_L01_001E2AC0;
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_00388830(f32 *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern S_83C0_R *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_003E1A20(void);
extern void func_003BD360(void *);

/* localdecomp:start func_L01_003B6BC0 */
extern f32 D_001DE7B4_sda;
__asm__(".extern D_001DE7B4_sda, 4");
extern f32 D_001DE7B8_sda;
__asm__(".extern D_001DE7B8_sda, 4");
void func_L01_003B6BC0(S_83C0_O *a0) {
    f32 vec[4];
    u8 *o;
    f32 s;
    S_83C0_R *r;
    o = (u8 *)func_L01_00444358(a0, -1, 0);
    if (o != 0) {
        func_0039FE80(0, 0, a0);
        D_L01_001E2AC0.f20 = 0.2f;
        D_L01_001E2AC0.f28 = 0x96;
        D_L01_001E2AC0.f2C = 0;
        func_00388830(vec, o + 0x10, D_001DE7B4_sda * 0.016666668f);
        s = func_0037E250(12.0f, 16.0f);
        r = func_L01_003F5830(a0, 2, 0x1A54, 0, (u8 *)a0 + 0x10, (u8 *)a0 + 0xF0, vec, 0xFF, s, D_001DE7B8_sda, func_0037E208(0x78, 0xB4), 0, 0x80);
        r->f64 = func_L01_003E1A20;
        a0->h7C &= ~1;
        r->f68->b5F = 5;
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L01_003B6BC0 */
