#include "common.h"

/* NTSC-U counterpart of func_L05_003CB090 (src/levels/shared/L05_003CB090.c) */
/* localdecomp:start func_L05_003C8EE8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C8EE8;
typedef struct { s32 x, y, z, w; } W4_003C8EE8;
typedef struct { u8 pad[0x24]; f32 f24; } Inner_003C8EE8;
typedef struct { u8 pad[0x24]; Inner_003C8EE8 *f24; u8 pad28[4]; f32 f2C; } Obj_003C8EE8;

extern f32 D_L05_001DF750;
extern s32 D_L05_001DEE5C;
extern f32 D_L05_001DEE60;
extern f32 D_L05_001DEE64;
extern f32 D_L05_001DEE68;
extern s32 D_L05_001DEE6C;
extern s32 D_L05_001DEE70;
extern s32 D_L05_001DEE74;
extern s32 D_L05_001DEE78;
extern s32 D_L05_001DEE7C;
extern s32 D_L05_001DEE80;
extern s32 D_L05_001DEE84;
extern s32 D_L05_001DEE88;
extern s32 D_L05_001DEE8C;
extern s32 D_L05_001DEE90;
extern s32 D_L05_001DEE94;
extern f32 D_L05_001DEE98;
extern s32 D_L05_001DEE9C;
extern s32 D_L05_001DEEA0;
extern f32 D_L05_001DEEA4;
extern f32 D_L05_001DEEA8;
extern f32 D_L05_001DEEAC;
extern f32 D_L05_001DEEB0;
__asm__(".extern D_L05_001DF750, 16");
__asm__(".extern D_L05_001DEE5C, 4");
__asm__(".extern D_L05_001DEE60, 4");
__asm__(".extern D_L05_001DEE64, 4");
__asm__(".extern D_L05_001DEE68, 4");
__asm__(".extern D_L05_001DEE6C, 4");
__asm__(".extern D_L05_001DEE70, 4");
__asm__(".extern D_L05_001DEE74, 4");
__asm__(".extern D_L05_001DEE78, 4");
__asm__(".extern D_L05_001DEE7C, 4");
__asm__(".extern D_L05_001DEE80, 4");
__asm__(".extern D_L05_001DEE84, 4");
__asm__(".extern D_L05_001DEE88, 4");
__asm__(".extern D_L05_001DEE8C, 4");
__asm__(".extern D_L05_001DEE90, 4");
__asm__(".extern D_L05_001DEE94, 4");
__asm__(".extern D_L05_001DEE98, 4");
__asm__(".extern D_L05_001DEE9C, 4");
__asm__(".extern D_L05_001DEEA0, 4");
__asm__(".extern D_L05_001DEEA4, 4");
__asm__(".extern D_L05_001DEEA8, 4");
__asm__(".extern D_L05_001DEEAC, 4");
__asm__(".extern D_L05_001DEEB0, 4");
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_0037E4B8(V4_003C8EE8 *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern Obj_003C8EE8 *func_L01_00329470(V4_003C8EE8 *a, V4_003C8EE8 *b, s32 c, s32 d, s32 e, s32 f, W4_003C8EE8 *g, s32 h, s32 i, s32 j, f32 k, f32 l);
extern u8 *func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);

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
    f32 ang0;
    f32 ang1;
    f32 sc;
    s32 cx;
    f32 spd;
    f32 mid;
    f32 c0;
    V4_003C8EE8 a;
    V4_003C8EE8 b;

    st = *(u8 **)(self + 0x68);
    n = D_L05_001DEE5C;
    if (0.7f < D_L05_001DF750 && D_L05_001DF750 < 0.85f) {
        n = n - 1;
    } else if (0.85f < D_L05_001DF750) {
        n = n - 2;
    }
    {
        for (k = 0; k < n; k++) {
            Obj_003C8EE8 *o;
            ang0 = func_0037E250(0.43633232f, 0.78539819f);
            s4 = 0;
            ang1 = func_0037E2A8();
            spd = func_0037E250(10.0f, 20.0f);
            spd = spd * 0.016666668f;
            func_0037E4B8(&a, spd * D_L05_001DEE60, ang1, ang0);
            *(W4_003C8EE8 *)&b = (W4_003C8EE8){
                ((s32)(f32)D_L05_001DEE78 << 24) | ((s32)(f32)D_L05_001DEE74 << 16) | ((s32)(f32)D_L05_001DEE70 << 8) | (s32)(f32)D_L05_001DEE6C,
                ((s32)((f32)D_L05_001DEE78 * 0.75f) << 24) | ((s32)((f32)D_L05_001DEE74 * 0.75f) << 16) | ((s32)((f32)D_L05_001DEE70 * 0.75f) << 8) | (s32)((f32)D_L05_001DEE6C * 0.75f),
                ((s32)((f32)D_L05_001DEE78 * 0.5f) << 24) | ((s32)((f32)D_L05_001DEE74 * 0.5f) << 16) | ((s32)((f32)D_L05_001DEE70 * 0.5f) << 8) | (s32)((f32)D_L05_001DEE6C * 0.5f),
                ((s32)((f32)D_L05_001DEE78 * 0.25f) << 24) | ((s32)((f32)D_L05_001DEE74 * 0.25f) << 16) | ((s32)((f32)D_L05_001DEE70 * 0.25f) << 8) | (s32)((f32)D_L05_001DEE6C * 0.25f)
            };
            if (*(u8 **)(st + 0x3C) != 0) {
                idx = func_0037E1D8(*(s32 *)(st + 0x38)) * 4;
                c0 = (f32)D_L05_001DEE78;
                cx = ((s32)c0 << 24) | ((s32)(f32)(*(u8 **)(st + 0x3C))[idx + 2] << 16) | ((s32)(f32)(*(u8 **)(st + 0x3C))[idx + 1] << 8) | (s32)(f32)(*(u8 **)(st + 0x3C))[idx + 0];
                s4 = ((*(u8 **)(st + 0x3C))[idx + 3] << 24) | ((*(u8 **)(st + 0x3C))[idx + 2] << 16) | ((*(u8 **)(st + 0x3C))[idx + 1] << 8) | (*(u8 **)(st + 0x3C))[idx + 0];
                ((W4_003C8EE8 *)&b)->x = cx;
                ((W4_003C8EE8 *)&b)->y = ((s32)(c0 * 0.75f) << 24) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 2] * 0.75f) << 16) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 1] * 0.75f) << 8) | (s32)((f32)(*(u8 **)(st + 0x3C))[idx + 0] * 0.75f);
                ((W4_003C8EE8 *)&b)->z = ((s32)(c0 * 0.5f) << 24) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 2] * 0.5f) << 16) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 1] * 0.5f) << 8) | (s32)((f32)(*(u8 **)(st + 0x3C))[idx + 0] * 0.5f);
                ((W4_003C8EE8 *)&b)->w = ((s32)(c0 * 0.25f) << 24) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 2] * 0.25f) << 16) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 1] * 0.25f) << 8) | (s32)((f32)(*(u8 **)(st + 0x3C))[idx + 0] * 0.25f);
            }
            s2 = 0;
            sc = func_0037E250(D_L05_001DEE64, D_L05_001DEE68);
            s0 = 0;
            mid = D_L05_001DEE64 + (D_L05_001DEE68 - D_L05_001DEE64) * 0.5f;
            if (mid < sc || func_0037E1D8(3) == 0) {
                s2 = 1;
                if (func_0037E1D8(3) != 0) {
                    if (D_L05_001DF750 < 0.8f) {
                        s0 = 2;
                    }
                }
            }
            o = func_L01_00329470((V4_003C8EE8 *)(st + 0x10), &a, func_0037E208(0x78, 0x96), s0, s2, s4, (W4_003C8EE8 *)&b, 0, 0x32, 0x78, 1.0f, 14.6f);
            if (o != 0) {
                o->f2C = o->f24->f24 * sc;
            }
        }
    }
    {
        for (i = 0; i < D_L05_001DEE9C; i++) {
            b = (V4_003C8EE8){0.0f, 0.0f, 0.0f, 0.0f};
            b.x = func_0037E250(D_L05_001DEEA4, D_L05_001DEEA8);
            b.y = func_0037E250(D_L05_001DEEA4, D_L05_001DEEA8);
            b.z = func_0037E250(D_L05_001DEEAC, D_L05_001DEEB0);
            a = b;
            func_00388830(&a, &a, D_L05_001DEE98 * 0.016666668f);
            func_L01_00460318(st + 0x10, &a,
                (D_L05_001DEE88 << 24) | (D_L05_001DEE84 << 16) | (D_L05_001DEE80 << 8) | D_L05_001DEE7C,
                (D_L05_001DEE84 << 16) | (D_L05_001DEE80 << 8) | D_L05_001DEE7C,
                D_L05_001DEE8C, D_L05_001DEE90, D_L05_001DEE94, D_L05_001DEEA0);
        }
    }
}
/* localdecomp:end func_L05_003C8EE8 */
