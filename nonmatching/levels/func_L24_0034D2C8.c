/* func_L24_0034D2C8: 186 differences (level 24, file L24_0034CD58.c; its VU0 vsub/vadd need -mvu0-use-vf0-vf2 on that
   file's line, which keeps func_L24_0034D110 matching but is not committed with this near miss; needs a
   config/levels/divs_nops.txt row 'func_L24_0034D2C8 2 2' for its two div.s). The logic is complete (spark trail
   between two points: n = len/0.1 steps of func_L01_0046A610 sparks with random size, colour flag from func_0013D3E0,
   then one func_L01_00465738 flash), but the loop's invariants differ: retail keeps 0.0f/0.02f in $f20/$f21, the step
   vector in $s7 and the constants 0x40 and 6 in saved registers, reloads 1.0f at each use and keeps s in $fp with the
   object spilled; this C also hoists 1.0f (CSE merges its two uses) and spills s, giving a larger frame. Two wordings
   of the colour flag tried. */
#include "common.h"
#include "vu0.h"
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
extern void func_003C4C18(f32 *, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00465738(void *, void *, u32, s32, s32, s32, s32, s32, s32, f32);
extern u8 D_001A4EC0[];
typedef struct {
    u8 p0[0x5C];
    u8 *x5C;
} S_34D2C8;
extern S_34D2C8 D_L24_0021EFD8;
extern u8 *D_L24_0021F0AC[];

void func_L24_0034D2C8(u8 *obj, f32 *from, f32 *to) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 p[4];
    f32 q[4];
    f32 f[4];
    f32 c[4];
    f32 d[4];
    f32 e[4];
    f32 g[4];
    f32 len;
    s32 n;
    s32 cnt;
    s32 k;
    s32 i;
    s32 y;
    u8 *r;
    u32 col;

    *(vu0_q *)p = *(vu0_q *)from;
    *(vu0_q *)q = *(vu0_q *)to;
    len = func_0038CEA8(s);
    n = (s32)(len / 0.1f);
    *(vu0_q *)c = *(vu0_q *)q;
    vec_sub_ab(d, p, q);
    func_0038CF68(d, d, len / (f32)n);
    *(vu0_q *)e = *(vu0_q *)D_001A4EC0;
    if (n > 0) {
        cnt = n;
        do {
            k = (s32)func_L01_00443A18(1.0f, 3.0f);
            func_0038CE20(f, e, -(func_003824E0(0.1f, 0.2f) * 0.020000001f));
            i = func_00382498(2, 4);
            y = 0x60;
            if (func_0013D3E0() & 2) {
                y = 0x40;
            }
            r = func_L01_0046A610(c, f, (i * 5 + 2) / 6, y, 0x7F0000FF, k, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
            vec_add_ab(c, c, d);
            if (r != 0) {
                r[2] = *D_L24_0021EFD8.x5C;
                if (y == 0x40) {
                    r[3] = 0x48;
                } else {
                    r[3] = 0x44;
                }
            }
        } while (--cnt != 0);
    }
    func_0038CE20(g, s, -0.040000003f);
    func_003C4C18(g, 0.040000003f);
    g[2] = g[2] + 0.040000003f;
    col = 0x7F1010FF;
    if (func_00382468(2) != 0) {
        col = 0x7F2020FF;
    }
    r = func_L01_00465738(obj + 0x10, g, col, 0xFF, func_00382498(8, 0x11), 0, -1, -1, 0, 73500.0f);
    if (r != 0) {
        *(f32 *)(r + 0x2C) = 0.0024f;
        r[2] = *D_L24_0021F0AC[0];
    }
}
