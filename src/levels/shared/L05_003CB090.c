#include "common.h"

/* localdecomp:start func_L05_003CB090 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CB090;
typedef struct { s32 x, y, z, w; } W4_003CB090;
typedef struct { u8 pad[0x24]; f32 f24; } Inner_003CB090;
typedef struct { u8 pad[0x24]; Inner_003CB090 *f24; u8 pad28[4]; f32 f2C; } Obj_003CB090;

extern f32 D_L05_001DF6D0;
extern s32 D_L05_001DEE1C;
extern f32 D_L05_001DEE20;
extern f32 D_L05_001DEE24;
extern f32 D_L05_001DEE28;
extern s32 D_L05_001DEE2C;
extern s32 D_L05_001DEE30;
extern s32 D_L05_001DEE34;
extern s32 D_L05_001DEE38;
extern s32 D_L05_001DEE3C;
extern s32 D_L05_001DEE40;
extern s32 D_L05_001DEE44;
extern s32 D_L05_001DEE48;
extern s32 D_L05_001DEE4C;
extern s32 D_L05_001DEE50;
extern s32 D_L05_001DEE54;
extern f32 D_L05_001DEE58;
extern s32 D_L05_001DEE5C;
extern s32 D_L05_001DEE60;
extern f32 D_L05_001DEE64;
extern f32 D_L05_001DEE68;
extern f32 D_L05_001DEE6C;
extern f32 D_L05_001DEE70;
__asm__(".extern D_L05_001DF6D0, 16");
__asm__(".extern D_L05_001DEE1C, 4");
__asm__(".extern D_L05_001DEE20, 4");
__asm__(".extern D_L05_001DEE24, 4");
__asm__(".extern D_L05_001DEE28, 4");
__asm__(".extern D_L05_001DEE2C, 4");
__asm__(".extern D_L05_001DEE30, 4");
__asm__(".extern D_L05_001DEE34, 4");
__asm__(".extern D_L05_001DEE38, 4");
__asm__(".extern D_L05_001DEE3C, 4");
__asm__(".extern D_L05_001DEE40, 4");
__asm__(".extern D_L05_001DEE44, 4");
__asm__(".extern D_L05_001DEE48, 4");
__asm__(".extern D_L05_001DEE4C, 4");
__asm__(".extern D_L05_001DEE50, 4");
__asm__(".extern D_L05_001DEE54, 4");
__asm__(".extern D_L05_001DEE58, 4");
__asm__(".extern D_L05_001DEE5C, 4");
__asm__(".extern D_L05_001DEE60, 4");
__asm__(".extern D_L05_001DEE64, 4");
__asm__(".extern D_L05_001DEE68, 4");
__asm__(".extern D_L05_001DEE6C, 4");
__asm__(".extern D_L05_001DEE70, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_00382760(V4_003CB090 *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern Obj_003CB090 *func_L01_003298C8(V4_003CB090 *a, V4_003CB090 *b, s32 c, s32 d, s32 e, s32 f, W4_003CB090 *g, s32 h, s32 i, s32 j, f32 k, f32 l);
extern u8 *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L05_003CB090(u8 *self) {
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
    V4_003CB090 a;
    V4_003CB090 b;

    st = *(u8 **)(self + 0x68);
    n = D_L05_001DEE1C;
    if (0.7f < D_L05_001DF6D0 && D_L05_001DF6D0 < 0.85f) {
        n = n - 1;
    } else if (0.85f < D_L05_001DF6D0) {
        n = n - 2;
    }
    {
        for (k = 0; k < n; k++) {
            Obj_003CB090 *o;
            ang0 = func_003824E0(0.43633232f, 0.78539819f);
            s4 = 0;
            ang1 = func_00382538();
            spd = func_003824E0(10.0f, 20.0f);
            spd = spd * 0.020000001f;
            func_00382760(&a, spd * D_L05_001DEE20, ang1, ang0);
            *(W4_003CB090 *)&b = (W4_003CB090){
                ((s32)(f32)D_L05_001DEE38 << 24) | ((s32)(f32)D_L05_001DEE34 << 16) | ((s32)(f32)D_L05_001DEE30 << 8) | (s32)(f32)D_L05_001DEE2C,
                ((s32)((f32)D_L05_001DEE38 * 0.75f) << 24) | ((s32)((f32)D_L05_001DEE34 * 0.75f) << 16) | ((s32)((f32)D_L05_001DEE30 * 0.75f) << 8) | (s32)((f32)D_L05_001DEE2C * 0.75f),
                ((s32)((f32)D_L05_001DEE38 * 0.5f) << 24) | ((s32)((f32)D_L05_001DEE34 * 0.5f) << 16) | ((s32)((f32)D_L05_001DEE30 * 0.5f) << 8) | (s32)((f32)D_L05_001DEE2C * 0.5f),
                ((s32)((f32)D_L05_001DEE38 * 0.25f) << 24) | ((s32)((f32)D_L05_001DEE34 * 0.25f) << 16) | ((s32)((f32)D_L05_001DEE30 * 0.25f) << 8) | (s32)((f32)D_L05_001DEE2C * 0.25f)
            };
            if (*(u8 **)(st + 0x3C) != 0) {
                idx = func_00382468(*(s32 *)(st + 0x38)) * 4;
                c0 = (f32)D_L05_001DEE38;
                cx = ((s32)c0 << 24) | ((s32)(f32)(*(u8 **)(st + 0x3C))[idx + 2] << 16) | ((s32)(f32)(*(u8 **)(st + 0x3C))[idx + 1] << 8) | (s32)(f32)(*(u8 **)(st + 0x3C))[idx + 0];
                s4 = ((*(u8 **)(st + 0x3C))[idx + 3] << 24) | ((*(u8 **)(st + 0x3C))[idx + 2] << 16) | ((*(u8 **)(st + 0x3C))[idx + 1] << 8) | (*(u8 **)(st + 0x3C))[idx + 0];
                ((W4_003CB090 *)&b)->x = cx;
                ((W4_003CB090 *)&b)->y = ((s32)(c0 * 0.75f) << 24) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 2] * 0.75f) << 16) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 1] * 0.75f) << 8) | (s32)((f32)(*(u8 **)(st + 0x3C))[idx + 0] * 0.75f);
                ((W4_003CB090 *)&b)->z = ((s32)(c0 * 0.5f) << 24) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 2] * 0.5f) << 16) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 1] * 0.5f) << 8) | (s32)((f32)(*(u8 **)(st + 0x3C))[idx + 0] * 0.5f);
                ((W4_003CB090 *)&b)->w = ((s32)(c0 * 0.25f) << 24) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 2] * 0.25f) << 16) | ((s32)((f32)(*(u8 **)(st + 0x3C))[idx + 1] * 0.25f) << 8) | (s32)((f32)(*(u8 **)(st + 0x3C))[idx + 0] * 0.25f);
            }
            s2 = 0;
            sc = func_003824E0(D_L05_001DEE24, D_L05_001DEE28);
            s0 = 0;
            mid = D_L05_001DEE24 + (D_L05_001DEE28 - D_L05_001DEE24) * 0.5f;
            if (mid < sc || func_00382468(3) == 0) {
                s2 = 1;
                if (func_00382468(3) != 0) {
                    if (D_L05_001DF6D0 < 0.8f) {
                        s0 = 2;
                    }
                }
            }
            o = func_L01_003298C8((V4_003CB090 *)(st + 0x10), &a, func_00382498(0x64, 0x7D), s0, s2, s4, (W4_003CB090 *)&b, 0, 0x32, 0x78, 1.0f, 14.6f);
            if (o != 0) {
                o->f2C = o->f24->f24 * sc;
            }
        }
    }
    {
        for (i = 0; i < D_L05_001DEE5C; i++) {
            b = (V4_003CB090){0.0f, 0.0f, 0.0f, 0.0f};
            b.x = func_003824E0(D_L05_001DEE64, D_L05_001DEE68);
            b.y = func_003824E0(D_L05_001DEE64, D_L05_001DEE68);
            b.z = func_003824E0(D_L05_001DEE6C, D_L05_001DEE70);
            a = b;
            func_0038CF68(&a, &a, D_L05_001DEE58 * 0.020000001f);
            func_L01_004637C8(st + 0x10, &a,
                (D_L05_001DEE48 << 24) | (D_L05_001DEE44 << 16) | (D_L05_001DEE40 << 8) | D_L05_001DEE3C,
                (D_L05_001DEE44 << 16) | (D_L05_001DEE40 << 8) | D_L05_001DEE3C,
                D_L05_001DEE4C, D_L05_001DEE50, D_L05_001DEE54, D_L05_001DEE60);
        }
    }
}
/* localdecomp:end func_L05_003CB090 */
