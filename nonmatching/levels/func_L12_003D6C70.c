/* NTSC-U draft (Claude wave C4): C of func_L12_003D4ED0, the NTSC-U twin of func_L12_003D6C70, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L12_003D4ED0", whose code is not the PAL one).
 * Worker's note: flags: needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (8 vec ops through the vu0.h helpers + 2 lui/ori/mtc1 constants; the PAL file's STD flag line has neither), so it cannot land even if exact; NEEDS divs row 'func_L12_003D4ED0 ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L12_003D4ED0 */
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    vu0_v4 axis;
    vu0_v4 r[6];
} S_3D4ED0;
extern s32 D_001DF00C_sda;
__asm__(".extern D_001DF00C_sda, 4");
extern f32 D_001DF040_sda;
__asm__(".extern D_001DF040_sda, 4");
extern f32 D_001DF044_sda;
__asm__(".extern D_001DF044_sda, 4");
extern s32 D_001DF010_sda;
__asm__(".extern D_001DF010_sda, 4");
extern f32 D_001DF048_sda;
__asm__(".extern D_001DF048_sda, 4");
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} G_CFEC0;
extern G_CFEC0 D_001CFEC0;
extern u8 D_L12_001E2800[];
extern void func_003A3EF0(s32, u32);
extern void func_003867F8(s32, s32, s32, s32, u32);
extern void func_L12_003D5220(void *, s32, f32, f32);
extern void func_003BFC18(void *, void *, s32);
extern void func_003D3E40(void *, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003CD830(S_3D4ED0 *, vu0_v4 *, s32);

void func_L12_003D4ED0(u8 *o) {
    S_3D4ED0 s;
    u8 *d;
    s32 n;
    s32 col;
    f32 f;
    f32 k;

    d = *(u8 **)(o + 0x68);
    if (D_001DF00C_sda != 0) {
        if (0x3C - *(s32 *)(d + 0x24) < 2 && *(s32 *)(d + 0x34) != 0) {
            func_003A3EF0(0x42, 0x48);
            func_003867F8(0, D_001CFEC0.h152, 0, D_001CFEC0.h150, 0x80808080);
        }
    }
    if (*(s32 *)(d + 0x30) != 0) {
        n = 0x3C - *(s32 *)(d + 0x24);
        if (n < 10) {
            f = D_001DF040_sda + (D_001DF044_sda - D_001DF040_sda) * ((f32)n / 10.0f);
            func_L12_003D5220(o + 0x10, 0x3B, f, 0.5f);
        } else if ((u32)(*(s32 *)(d + 0x24) - 0x2E) < 4) {
            n = *(s32 *)(d + 0x24) - 0x2D;
            f = D_001DF040_sda + (D_001DF044_sda - D_001DF040_sda) * ((f32)n / 10.0f);
            func_L12_003D5220(o + 0x10, 0x3B, f, 0.5f);
        }
    }
    if (D_001DF010_sda != 0) {
        if (*(s32 *)(d + 0x34) != 0) {
            func_003BFC18(o + 0x10, &s.axis, 1);
            f = (f32)*(s32 *)(d + 0x34);
            f = f * D_001DF048_sda;
            func_003D3E40(&s, 0xB, 4, 0x80);
            col = ((s32)(f * 255.0f) << 24) | 0xFFFFFF;
            k = 0.075f;
            s.x50 = 0;
            s.x54 = 0;
            s.x58 = 0;
            s.x5C = 1.0f;
            s.x60 = 1.0f;
            s.c4C = col;
            s.c48 = col;
            s.c44 = col;
            s.c40 = col;
            s.x64 = 0;
            s.x68 = 1.0f;
            s.x6C = 1.0f;
            vec_sub_ab(&s.r[0], o + 0x10, D_L12_001E2800 + D_001D52F0 * 0x460);
            func_00388830(&s.r[1], &s.r[0], 0.1f);
            vec_add_ba(&s.r[2], D_L12_001E2800 + D_001D52F0 * 0x460, &s.r[1]);
            func_00388758(&s.r[3], &s.r[0], &s.axis);
            func_00388830(&s.r[3], &s.r[3], k);
            func_00388758(&s.r[4], &s.r[3], &s.r[0]);
            func_00388830(&s.r[4], &s.r[4], k);
            vec_add_ab(&s.r[5], &s.r[2], &s.r[4]);
            vec_add_ab(&s.m[0], &s.r[5], &s.r[3]);
            vec_sub_ab(&s.m[1], &s.r[5], &s.r[3]);
            vec_sub_ab(&s.r[5], &s.r[2], &s.r[4]);
            vec_add_ba(&s.m[2], &s.r[5], &s.r[3]);
            vec_sub_ab(&s.m[3], &s.r[5], &s.r[3]);
            func_003CD830(&s, 0, 0);
        }
    }
}
/* localdecomp:end func_L12_003D4ED0 */
