/* NTSC-U draft (Claude wave K): C of func_L05_003C8EE8, the NTSC-U twin of func_L05_003CB090, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L05_003C8EE8", whose code is not the PAL one).
 * Worker's note: Whole function decoded and written (draft near/func_L05_003C8EE8.medium.c): 433 words = retail 433, frame 0xA0, same calls, no extra flags besides @ps2as; aligned diff TOTAL 139 (raw diff is shifted), all of it register naming / schedule order, no structure ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L05_003CB090 (src/levels/shared/L05_003CA628.c) */
/* localdecomp:start func_L05_003C8EE8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C8EE8;
typedef struct { s32 x, y, z, w; } W4_003C8EE8;
typedef struct { u8 pad[0x24]; f32 f24; } Inner_003C8EE8;
typedef struct { u8 pad[0x24]; Inner_003C8EE8 *f24; u8 pad28[4]; f32 f2C; } Obj_003C8EE8;

extern f32 D_L05_001DF750;
extern f32 D_001DF750_sda;
extern s32 D_001DEE5C_sda;
extern f32 D_001DEE60_sda;
extern f32 D_001DEE64_sda;
extern f32 D_001DEE68_sda;
extern s32 D_001DEE6C_sda;
extern s32 D_001DEE70_sda;
extern s32 D_001DEE74_sda;
extern s32 D_001DEE78_sda;
extern s32 D_001DEE7C_sda;
extern s32 D_001DEE80_sda;
extern s32 D_001DEE84_sda;
extern s32 D_001DEE88_sda;
extern s32 D_001DEE8C_sda;
extern s32 D_001DEE90_sda;
extern s32 D_001DEE94_sda;
extern f32 D_001DEE98_sda;
extern s32 D_001DEE9C_sda;
extern s32 D_001DEEA0_sda;
extern f32 D_001DEEA4_sda;
extern f32 D_001DEEA8_sda;
extern f32 D_001DEEAC_sda;
extern f32 D_001DEEB0_sda;
__asm__(".extern D_L05_001DF750, 16");
__asm__(".extern D_001DF750_sda, 4");
__asm__(".extern D_001DEE5C_sda, 4");
__asm__(".extern D_001DEE60_sda, 4");
__asm__(".extern D_001DEE64_sda, 4");
__asm__(".extern D_001DEE68_sda, 4");
__asm__(".extern D_001DEE6C_sda, 4");
__asm__(".extern D_001DEE70_sda, 4");
__asm__(".extern D_001DEE74_sda, 4");
__asm__(".extern D_001DEE78_sda, 4");
__asm__(".extern D_001DEE7C_sda, 4");
__asm__(".extern D_001DEE80_sda, 4");
__asm__(".extern D_001DEE84_sda, 4");
__asm__(".extern D_001DEE88_sda, 4");
__asm__(".extern D_001DEE8C_sda, 4");
__asm__(".extern D_001DEE90_sda, 4");
__asm__(".extern D_001DEE94_sda, 4");
__asm__(".extern D_001DEE98_sda, 4");
__asm__(".extern D_001DEE9C_sda, 4");
__asm__(".extern D_001DEEA0_sda, 4");
__asm__(".extern D_001DEEA4_sda, 4");
__asm__(".extern D_001DEEA8_sda, 4");
__asm__(".extern D_001DEEAC_sda, 4");
__asm__(".extern D_001DEEB0_sda, 4");
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_0037E4B8(V4_003C8EE8 *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern Obj_003C8EE8 *func_L01_00329470(V4_003C8EE8 *a, V4_003C8EE8 *b, s32 c, s32 d, s32 e, s32 f, W4_003C8EE8 *g, s32 h, s32 i, s32 j, f32 k, f32 l);
extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L05_003C8EE8(u8 *self) {
    u8 *st;
    s32 n;
    s32 k;
    s32 i;
    s32 s0;
    s32 s2;
    s32 s4;
    s32 idx;
    f32 d;
    f32 f20;
    f32 f21;
    f32 spd;
    f32 mid;
    f32 c0;
    V4_003C8EE8 a;
    V4_003C8EE8 b;
    u8 *tab;

    st = *(u8 **)(self + 0x68);
    n = D_001DEE5C_sda;
    if (0.7f < D_L05_001DF750 && D_L05_001DF750 < 0.85f) {
        n = n - 1;
    } else if (0.85f < D_L05_001DF750) {
        n = n - 2;
    }
    {
        for (k = n; k > 0; k--) {
            Obj_003C8EE8 *o;
            f21 = func_0037E250(0.43633232f, 0.78539819f);
            s4 = 0;
            f20 = func_0037E2A8();
            spd = func_0037E250(10.0f, 20.0f);
            spd = spd * 0.0166666675f;
            func_0037E4B8(&a, spd * D_001DEE60_sda, f20, f21);
            *(W4_003C8EE8 *)&b = (W4_003C8EE8){
                ((s32)(f32)D_001DEE78_sda << 24) | ((s32)(f32)D_001DEE74_sda << 16) | ((s32)(f32)D_001DEE70_sda << 8) | (s32)(f32)D_001DEE6C_sda,
                ((s32)((f32)D_001DEE78_sda * 0.75f) << 24) | ((s32)((f32)D_001DEE74_sda * 0.75f) << 16) | ((s32)((f32)D_001DEE70_sda * 0.75f) << 8) | (s32)((f32)D_001DEE6C_sda * 0.75f),
                ((s32)((f32)D_001DEE78_sda * 0.5f) << 24) | ((s32)((f32)D_001DEE74_sda * 0.5f) << 16) | ((s32)((f32)D_001DEE70_sda * 0.5f) << 8) | (s32)((f32)D_001DEE6C_sda * 0.5f),
                ((s32)((f32)D_001DEE78_sda * 0.25f) << 24) | ((s32)((f32)D_001DEE74_sda * 0.25f) << 16) | ((s32)((f32)D_001DEE70_sda * 0.25f) << 8) | (s32)((f32)D_001DEE6C_sda * 0.25f)
            };
            if (*(u8 **)(st + 0x3C) != 0) {
                idx = func_0037E1D8(*(s32 *)(st + 0x38)) * 4;
                c0 = (f32)D_001DEE78_sda;
                tab = *(u8 **)(st + 0x3C) + idx;
                ((W4_003C8EE8 *)&b)->x = ((s32)c0 << 24) | ((s32)(f32)tab[2] << 16) | ((s32)(f32)tab[1] << 8) | (s32)(f32)tab[0];
                s4 = (tab[3] << 24) | (tab[2] << 16) | (tab[1] << 8) | tab[0];
                tab = *(u8 **)(st + 0x3C) + idx;
                ((W4_003C8EE8 *)&b)->y = ((s32)(c0 * 0.75f) << 24) | ((s32)((f32)tab[2] * 0.75f) << 16) | ((s32)((f32)tab[1] * 0.75f) << 8) | (s32)((f32)tab[0] * 0.75f);
                tab = *(u8 **)(st + 0x3C) + idx;
                ((W4_003C8EE8 *)&b)->z = ((s32)(c0 * 0.5f) << 24) | ((s32)((f32)tab[2] * 0.5f) << 16) | ((s32)((f32)tab[1] * 0.5f) << 8) | (s32)((f32)tab[0] * 0.5f);
                tab = *(u8 **)(st + 0x3C) + idx;
                ((W4_003C8EE8 *)&b)->w = ((s32)(c0 * 0.25f) << 24) | ((s32)((f32)tab[2] * 0.25f) << 16) | ((s32)((f32)tab[1] * 0.25f) << 8) | (s32)((f32)tab[0] * 0.25f);
            }
            s2 = 0;
            f20 = func_0037E250(D_001DEE64_sda, D_001DEE68_sda);
            s0 = 0;
            mid = D_001DEE64_sda + (D_001DEE68_sda - D_001DEE64_sda) * 0.5f;
            if (mid < f20 || func_0037E1D8(3) == 0) {
                s2 = 1;
                if (func_0037E1D8(3) != 0) {
                    if (D_001DF750_sda < 0.8f) {
                        s0 = 2;
                    }
                }
            }
            o = func_L01_00329470((V4_003C8EE8 *)(st + 0x10), &a, func_0037E208(0x78, 0x96), s0, s2, s4, (W4_003C8EE8 *)&b, 0, 0x32, 0x78, 1.0f, 14.6f);
            if (o != 0) {
                o->f2C = o->f24->f24 * f20;
            }
        }
    }
    {
        for (i = 0; i < D_001DEE9C_sda; ) {
            i = i + 1;
            b = (V4_003C8EE8){0.0f, 0.0f, 0.0f, 0.0f};
            b.x = func_0037E250(D_001DEEA4_sda, D_001DEEA8_sda);
            b.y = func_0037E250(D_001DEEA4_sda, D_001DEEA8_sda);
            b.z = func_0037E250(D_001DEEAC_sda, D_001DEEB0_sda);
            a = b;
            func_00388830(&a, &a, D_001DEE98_sda * 0.0166666675f);
            func_L01_00460318(st + 0x10, &a,
                (D_001DEE88_sda << 24) | (D_001DEE84_sda << 16) | (D_001DEE80_sda << 8) | D_001DEE7C_sda,
                (D_001DEE84_sda << 16) | (D_001DEE80_sda << 8) | D_001DEE7C_sda,
                D_001DEE8C_sda, D_001DEE90_sda, D_001DEE94_sda, D_001DEEA0_sda);
        }
    }
}
/* localdecomp:end func_L05_003C8EE8 */
