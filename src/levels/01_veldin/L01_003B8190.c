#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003B8190);

/* localdecomp:start func_L01_003B83C0 */
typedef struct { u8 p0[0x20]; f32 f20; u8 p24[4]; s32 f28; s32 f2C; } S_83C0_G;
typedef struct { u8 p0[0x5F]; u8 b5F; } S_83C0_D;
typedef struct { u8 p0[0x64]; void *f64; S_83C0_D *f68; } S_83C0_R;
typedef struct { u8 p0[0x7C]; u16 h7C; } S_83C0_O;
extern S_83C0_G D_L01_001E2A40;
extern f32 D_L01_001DE774, D_L01_001DE778;
__asm__(".extern D_L01_001DE774, 4");
__asm__(".extern D_L01_001DE778, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(f32 *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern S_83C0_R *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_003E37F0(void);
extern void func_003C2880(void *);
void func_L01_003B83C0(S_83C0_O *a0) {
    f32 vec[4];
    u8 *o;
    f32 s;
    S_83C0_R *r;
    o = (u8 *)func_L01_00447490(a0, -1, 0);
    if (o != 0) {
        func_003A52A0(0, 0, a0);
        D_L01_001E2A40.f20 = 0.2f;
        D_L01_001E2A40.f28 = 0x7D;
        D_L01_001E2A40.f2C = 0;
        func_0038CF68(vec, o + 0x10, D_L01_001DE774 * 0.020000001f);
        s = func_003824E0(12.0f, 16.0f);
        r = func_L01_003F79D8(a0, 2, 0x1A54, 0, (u8 *)a0 + 0x10, (u8 *)a0 + 0xF0, vec, 0xFF, s, D_L01_001DE778, func_00382498(0x78, 0xB4), 0, 0x80);
        r->f64 = func_L01_003E37F0;
        a0->h7C &= ~1;
        r->f68->b5F = 5;
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003B83C0 */
