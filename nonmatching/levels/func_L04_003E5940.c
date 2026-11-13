/* near miss (level 4, Marcadia): 75 differences. Draws the group's quads (state 3 members) with a GIF
   packet laid out like func_L23_003A9D00's. Needs a divs_nops row "func_L04_003E5940 2 2" (not committed)
   and is checked in src/levels/04_marcadia/L04_003E51D0.c (-mvu0-use-vf0-vf2 ... @ps2as).
   Left: retail divides D_L04_001E2680+0x158 before +0x154 (source order of t.x/t.y and of the GIF stores
   did not change it); in the group walk retail keeps self spilled and reads self[0x21] twice in the loop
   test (more register pressure than here), and the corner switch's constants use $a2/$a3 there. The
   four lui/lw colour globals are scalars with `.extern X, 16` (unsized arrays split the lui). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003E5940 */
typedef int u128_t_3E5940 __attribute__((mode(TI)));
typedef struct { f32 x, y; } UV_3E5940;
typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    f32 uv[4][2];
    long gif[4];
} Q_3E5940;
extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;
extern u8 D_L04_001E2680[];
__asm__(".extern D_L04_001DF1D8, 4");
__asm__(".extern D_L04_001DF1DC, 4");
__asm__(".extern D_L04_001DF1E0, 4");
__asm__(".extern D_L04_001DF1E8, 4");
__asm__(".extern D_L04_001DF1F0, 4");
__asm__(".extern D_L04_001DF1F8, 4");
__asm__(".extern D_L04_001DF200, 4");
__asm__(".extern D_L04_001DF208, 4");
__asm__(".extern D_L04_001DF20C, 4");
__asm__(".extern D_L04_001DF210, 4");
__asm__(".extern D_L04_001DF230, 4");
extern s32 D_L04_001DF1D8;
extern s32 D_L04_001DF1DC;
extern f32 D_L04_001DF1E0;
extern s32 D_L04_001DF1E8;
__asm__(".extern D_L04_001DF1EC, 16");
extern s32 D_L04_001DF1EC;
extern s32 D_L04_001DF1F0;
__asm__(".extern D_L04_001DF1F4, 16");
extern s32 D_L04_001DF1F4;
extern s32 D_L04_001DF1F8;
__asm__(".extern D_L04_001DF1FC, 16");
extern s32 D_L04_001DF1FC;
extern s32 D_L04_001DF200;
__asm__(".extern D_L04_001DF204, 16");
extern s32 D_L04_001DF204;
extern s32 D_L04_001DF208;
extern s32 D_L04_001DF20C;
extern f32 D_L04_001DF210;
extern f32 D_L04_001DF214[];
extern f32 D_L04_001DF230;
extern long func_00389598(s32);
extern void func_0038D570(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_0038CE20(f32 *, void *, f32);

void func_L04_003E5940(u8 *self) {
    Q_3E5940 q;
    vu0_v4 m[4];
    UV_3E5940 off;
    UV_3E5940 t;
    vu0_v4 p0;
    vu0_v4 p1;
    u16 *p;
    u8 *e;
    u8 *s;
    u8 *g;
    s32 i;
    s32 j;
    s32 k;
    s32 c;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;

    q.gif[1] = func_00389598(D_L04_001DF1D8);
    g = D_L04_001E2680;
    t.y = *(f32 *)(g + 0x158) / 3.14159f;
    t.x = *(f32 *)(g + 0x154) / 3.14159f;
    q.gif[2] = 0xFF9000000260L;
    q.gif[0] = 0;
    q.gif[3] = ((long)D_L04_001DF208 << 2) | ((long)D_L04_001DF20C << 6) | 0x8000000000L;
    off = t;
    for (i = 0; i < 4; i++) {
        *(u128_t_3E5940 *)&q.v[i] = ((u128_t_3E5940 *)&D_L04_001DF230)[i];
        q.uv[i][0] = (&D_L04_001DF210)[i * 2] + off.x;
        q.uv[i][1] = D_L04_001DF214[i * 2] + off.y;
    }
    for (p = D_L04_0021C9A0[self[0x21]];
         self[0x21] != 0xFF && self[0x21] <= D_L04_001DFDD8 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[self[0x21]]);
         p++) {
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return;
        if (e[0x42] != 3)
            continue;
        func_0038D570(m, e + 0xC0);
        *(u128_t_3E5940 *)&m[3] = *(u128_t_3E5940 *)(e + 0x10);
        m[3].w = 1.0f;
        s = *(u8 **)(e + 0x68);
        c0 = func_0038DBD8(D_L04_001DF1E8, D_L04_001DF1EC, *(f32 *)(s + 0x7C));
        c1 = func_0038DBD8(D_L04_001DF1F0, D_L04_001DF1F4, *(f32 *)(s + 0x7C));
        if (*(f32 *)(s + 0x8C) != 0.0f) {
            c2 = func_0038DBD8(D_L04_001DF1F8, D_L04_001DF1FC, *(f32 *)(s + 0x7C));
            c3 = func_0038DBD8(D_L04_001DF200, D_L04_001DF204, *(f32 *)(s + 0x7C));
            c0 = func_0038DBD8(c0, c2, *(f32 *)(s + 0x8C));
            c1 = func_0038DBD8(c1, c3, *(f32 *)(s + 0x8C));
        }
        for (i = 0; i < 4; i++)
            q.col[i] = c0;
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 4; k++) {
                switch (k) {
                case 0:
                    c = 1;
                    break;
                case 1:
                    c = 3;
                    break;
                case 2:
                    c = 0;
                    break;
                case 3:
                    c = 2;
                    break;
                }
                func_0038D028(&p0, &q.v[k], m);
                func_0038D028(&p1, &q.v[c], m);
                func_L01_0040A8C0(&p0, &p1, D_L04_001DF1DC, 1, c1, c1, c1, c1, D_L04_001DF1E0, 1.0f, 0.0f);
            }
            func_003D2DA0(&q, m, 1);
            func_0038CE20(&m[1].x, &m[1], -1.0f);
        }
    }
}
/* localdecomp:end func_L04_003E5940 */
