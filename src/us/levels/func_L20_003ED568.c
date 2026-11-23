#include "common.h"

/* NTSC-U counterpart of func_L20_003EF550 (src/levels/20_final_boss/L20_003EEB40.c) */
#include "vu0.h"
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x450];
} C_003EEB40;
extern s32 D_001D52F0;
extern C_003EEB40 D_L20_001E2E80_003ED568[];
extern f32 D_L20_002C51D0_003ED568[];
extern u8 D_L20_00220258_003ED568[];
extern s32 D_L20_001DF378;
extern f32 func_00388A28(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

/* localdecomp:start func_L20_003ED568 */
#include "vu0.h"

__asm__(".extern D_L20_001DF378, 4");
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L01_004562A0(void *, s32, f32);
extern void func_L01_00300650(u8 *, u8 *, s32, s32);
extern void func_L20_003EDFA0(u8 *, f32);
extern u8 D_L20_002C5180_003ED568[];

typedef struct {
    u8 pad0[0xC];
    f32 scale;
    u8 pad10[0x20 - 0x10];
    s32 n20;
    s32 n24;
    s32 n28;
    u8 pad2C[0x40 - 0x2C];
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    s32 w54;
    u8 pad58[0x6C - 0x58];
    f32 f6C;
} S_003EF550;

typedef struct {
    u8 pad0[0x20];
    vu0_v4 v20;
} T_003EF550;

void func_L20_003ED568(u8 *a0, void *a1, vu0_v4 *a2, f32 f12) {
    vu0_v4 v1;
    vu0_v4 v2;
    S_003EF550 *s = *(S_003EF550 **)(a0 + 0x68);
    u8 *e;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 t;
    f32 ang;
    f32 a;
    f32 b;
    f32 c;
    f32 sx;
    f32 sy;

    sx = s->scale * 3.0f * 210000.0f;
    sy = s->scale * 4.5f * 210000.0f;
    e = func_L01_0046C468(a0 + 0x10, a2, 0x1E, s->w40, 0, 0x64, 0,
                          sx, sy, 0, 0.0f);
    if (e != 0) {
        e[2] = **(u8 **)(D_L20_00220258_003ED568 + 0x170);
    }
    e = func_L01_0046C468(a0 + 0x10, a2, 0x1E, s->w44, 0, 0x64, 0,
                          sx, sy, 0, 0.0f);
    if (e != 0) {
        e[3] = 0x44;
        e[2] = **(u8 **)(D_L20_00220258_003ED568 + 0x170);
    }
    for (i = 0; i < 2; i++) {
        u8 *g = D_L20_00220258_003ED568;
        e = func_L01_0046C468(a0 + 0x10, a2, 0x1E, s->w40, 0, 0x7F, 0,
                              sx, sy, 0, 0.0f);
        if (e != 0) {
            e[2] = (*(u8 **)(g + 0x170))[5];
        }
    }
    for (j = 0; j < 2; j++) {
        u8 *g = D_L20_00220258_003ED568;
        e = func_L01_0046C468(a0 + 0x10, a2, 0x1E, s->w40, 0, 0x7F, 0,
                              sx, sy, 0, 0.0f);
        if (e != 0) {
            e[2] = (*(u8 **)(g + 0x170))[6];
        }
    }
    ang = func_00388A28(D_L20_001E2E80_003ED568[D_001D52F0].pos.x - ((vu0_v4 *)(a0 + 0x10))->x,
                        D_L20_001E2E80_003ED568[D_001D52F0].pos.y - ((vu0_v4 *)(a0 + 0x10))->y);
    for (k = 0; k < s->n20; k++) {
        s32 n;
        u8 *q;

        n = func_L01_00440918(2.0f, 5.0f);
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        a = func_0037E250(0.6f, 1.0f) * s->scale;
        b = func_0037E250(9.0f, 12.0f) * s->scale;
        c = func_00389380(ang, func_L01_00440918(0.0f, 1.3962634f));
        b *= 0.016666668f;
        v2.x = func_00388960(c) * b;
        v2.y = func_00388978(c) * b;
        v2.z = 0.0f;
        b = func_0037E250(0.0f, 12.0f) * s->scale;
        v2.z = b * 0.016666668f;
        vec_add_ba(&v2, &v2, a2);
        q = func_L01_0046DCB8(&v1, &v2, func_0037E208(30, 50), a * 210000.0f, s->w48, n,
                              0x7F, 0x7F, s->scale * 0.01f * 210000.0f, 0.004055556f, 1);
        if (q != 0) {
            u8 *g = D_L20_00220258_003ED568;
            q[3] = 0x44;
            q[2] = **(u8 **)(g + 0xD4);
        }
        n *= -2;
        q = func_L01_0046DCB8(&v1, &v2, func_0037E208(30, 50), a * 6.0f * 210000.0f, s->w4C, n,
                              0x30, 0x30, s->scale * 0.02f * 210000.0f, 0.004055556f, 0);
        if (q != 0) {
            u8 *g = D_L20_00220258_003ED568;
            q[3] = 0x44;
            q[2] = **(u8 **)(g + 0xD4);
        }
    }
    for (m = 0; m < s->n24; m++) {
        s32 n;

        n = func_L01_00440918(2.0f, 5.0f);
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        a = func_0037E250(0.75f, 1.5f) * s->scale;
        b = func_0037E250(9.0f, 12.0f) * s->scale;
        c = func_00389380(ang, func_L01_00440918(0.0f, 1.3962634f));
        b *= 0.016666668f;
        v2.x = func_00388960(c) * b;
        v2.y = func_00388978(c) * b;
        v2.z = 0.0f;
        b = func_0037E250(0.0f, 12.0f) * s->scale;
        v2.z = b * 0.016666668f;
        vec_add_ba(&v2, &v2, a2);
        func_L01_0046DCB8(&v1, &v2, func_0037E208(30, 50), a * 210000.0f, s->w50, n,
                          0x7F, 0x7F, s->scale * 0.01f * 210000.0f, 0.004055556f, 5);
    }
    for (t = 0; t < s->n28; t++) {
        s32 n;

        n = func_L01_00440918(2.0f, 5.0f);
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        D_L20_001DF378 = (D_L20_001DF378 + 1) % 44;
        v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L20_002C51D0_003ED568[D_L20_001DF378] * 0.1f * s->scale;
        a = func_0037E250(0.6f, 1.0f) * s->scale;
        b = func_0037E250(9.0f, 12.0f) * s->scale;
        c = func_00389380(ang, func_L01_00440918(0.0f, 1.3962634f));
        b *= 0.016666668f;
        v2.x = func_00388960(c) * b;
        v2.y = func_00388978(c) * b;
        v2.z = 0.0f;
        b = func_0037E250(0.0f, 12.0f) * s->scale;
        v2.z = b * 0.016666668f;
        vec_add_ba(&v2, &v2, a2);
        func_L01_0046DCB8(&v1, &v2, func_0037E208(30, 50), a * 210000.0f, s->w54, n,
                          0x7F, 0x7F, s->scale * 2100.0f, 0.004055556f, 3);
    }
    if (0.0f < f12) {
        v1 = *(vu0_v4 *)(a0 + 0x10);
        v1.w = s->scale * 3.0f;
        if (func_L01_004562A0(&v1, 0, 96.0f) > 0) {
            T_003EF550 *p = (T_003EF550 *)D_L20_002C5180_003ED568;
            p->v20.y = f12;
            p->v20.z = f12;
            p->v20.x = f12;
            func_L01_00300650((u8 *)p, a0 + 0x10, 0, 0);
        }
    }
    if (0.0f < s->f6C) {
        func_L20_003EDFA0(a0, s->f6C);
    }
}
/* localdecomp:end func_L20_003ED568 */
