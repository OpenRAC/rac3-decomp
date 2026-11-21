#include "common.h"

/* NTSC-U counterpart of func_L12_003D6C70 (src/levels/shared/L12_003D5D08.c) */
typedef struct {
    f32 x, y, z, w;
    u8 p10[0x460 - 0x10];
} E_003D63D8;
extern s32 D_001D52F0;
extern E_003D63D8 D_L12_001E2800[];
#include "vu0.h"
extern s32 D_001D52F0;
extern E_003D63D8 D_L12_001E2800[];
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L12_003D4ED0(u8 *);

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
} S_3D6C70;
extern s32 D_L12_001DF00C;
__asm__(".extern D_L12_001DF00C, 4");
extern f32 D_L12_001DF040_003D4ED0;
__asm__(".extern D_L12_001DF040_003D4ED0, 4");
extern f32 D_L12_001DF044_003D4ED0;
__asm__(".extern D_L12_001DF044_003D4ED0, 4");
extern s32 D_L12_001DF010;
__asm__(".extern D_L12_001DF010, 4");
extern f32 D_L12_001DF048;
__asm__(".extern D_L12_001DF048, 4");
__asm__(".extern D_001D52F0, 16");
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} G_3D6C70;
extern G_3D6C70 D_001CFEC0;
extern void func_003A3EF0(s32, u32);
extern void func_003867F8(s32, s32, s32, s32, unsigned long);
extern void func_L12_003D5220(void *, s32, f32, f32);
extern void func_003BFC18(void *, void *, s32);
extern void func_003D3E40(void *, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003CD830(S_3D6C70 *, vu0_v4 *, s32);

void func_L12_003D4ED0(u8 *o) {
    S_3D6C70 s;
    u8 *d;
    s32 n;
    s32 col;
    f32 f;
    f32 k;

    d = *(u8 **)(o + 0x68);
    if (D_L12_001DF00C != 0) {
        if (0x3C - *(s32 *)(d + 0x24) < 2 && *(s32 *)(d + 0x34) != 0) {
            func_003A3EF0(0x42, 0x48);
            func_003867F8(0, D_001CFEC0.h152, 0, D_001CFEC0.h150, (s32)0x80808080);
        }
    }
    if (*(s32 *)(d + 0x30) != 0) {
        n = 0x3C - *(s32 *)(d + 0x24);
        if (n < 10) {
            f = D_L12_001DF040_003D4ED0 + (D_L12_001DF044_003D4ED0 - D_L12_001DF040_003D4ED0) * ((f32)n / 10.0f);
            func_L12_003D5220(o + 0x10, 0x3B, f, 0.5f);
        } else if ((u32)(*(s32 *)(d + 0x24) - 0x2E) < 4) {
            n = *(s32 *)(d + 0x24) - 0x2D;
            f = D_L12_001DF040_003D4ED0 + (D_L12_001DF044_003D4ED0 - D_L12_001DF040_003D4ED0) * ((f32)n / 10.0f);
            func_L12_003D5220(o + 0x10, 0x3B, f, 0.5f);
        }
    }
    if (D_L12_001DF010 != 0) {
        if (*(s32 *)(d + 0x34) != 0) {
            func_003BFC18(o + 0x10, &s.axis, 1);
            f = (f32)*(s32 *)(d + 0x34);
            f = f * D_L12_001DF048;
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
            vec_sub_ab(&s.r[0], o + 0x10, &D_L12_001E2800[D_001D52F0]);
            func_00388830(&s.r[1], &s.r[0], 0.1f);
            vec_add_ba(&s.r[2], &D_L12_001E2800[D_001D52F0], &s.r[1]);
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
