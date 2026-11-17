#include "common.h"

/* NTSC-U counterpart of func_L30_00348C30 (src/levels/30_vidcomic_unnamed/L30_00348868.c) */
extern u8 D_001A4C60[];
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L30_00347EC0 */
#include "vu0.h"
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_00348C30;
extern u8 D_001A4C60[];
extern vu0_v4 D_L30_001E9020_00347EC0;
extern f32 D_L30_001DD348;
__asm__(".extern D_L30_001DD348, 4");
extern void func_003BD9A0(void *, s32, void *);
extern void func_L30_00348780(void *, void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004084B0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L30_00347EC0(u8 *a0) {
    vu0_v4 dir;
    vu0_v4 from;
    S_00348C30 s;
    vu0_v4 mtx[4];
    vu0_v4 hit;
    vu0_v4 vel;
    s32 i;
    f32 r;

    func_003BD9A0(a0, 4, mtx);
    from = mtx[3];
    func_L30_00348780(a0, &dir);
    func_L01_00443628(&s, a0, 1, &dir, 1.0f);
    s.h1A = *(u16 *)(a0 + 0xAA);
    func_00388830(&dir, &dir, D_L30_001DD348);
    vec_add_ab(&dir, &dir, &from);
    from.y = ((f32 *)D_001A4C60)[1];
    dir.y = ((f32 *)D_001A4C60)[1];
    if (func_003CE740(&from, &dir, 0, a0, &s)) {
        for (i = 0; i < 2; i++) {
            hit = D_L30_001E9020_00347EC0;
            func_003BF6A8(&hit, 0.3f);
            vel.x = func_0037E250(0.0f, 1.0f * (1.0f / 60.0f));
            vel.y = func_0037E250(0.0f, 1.0f * (1.0f / 60.0f));
            vel.z = func_0037E250(2.0f * (1.0f / 60.0f), 2.0f * (1.0f / 60.0f) + 5.0f * (1.0f / 60.0f));
            {
                s32 n = func_0037E208(0, 2) - 1;

                r = func_0037E250(0.25f, 1.25f) * 210000.0f;
                func_L01_0046C468(&hit, &vel, 0x2D, 0x808080, n, 0x60, 0, 0, r, r * 0.1f, 0.002f);
            }
        }
    }
    func_L01_004084B0(&from, &hit, 0x15, 1, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0.3f, 1.0f, 0.0f);
    func_L01_004084B0(&from, &hit, 0x15, 1, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0.1f, 1.0f, 0.0f);
}
/* localdecomp:end func_L30_00347EC0 */
