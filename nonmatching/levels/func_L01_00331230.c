/* Matches PAL byte for byte with check.py at its 34 places (round 30), but the full level build rejects it:
 * func_L01_00331230, its word at +0x22C: the instruction differs (15 levels; the others are not built with it).
 * check.py masks relocated fields; tools/level_symbols.py compares them with the real symbols of each level: a callee or global
 * name (or its address) used at +0x22C is wrong. Compare the retail word with the C there before spending more compiles.
 */
/* localdecomp:start func_L01_00331230 */
#include "vu0.h"

extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00459590(void *, s32, f32);
extern void func_L01_003006C0(u8 *, u8 *, s32, s32);
extern void func_L01_00331D28_00331230(u8 *, f32);
extern void func_L01_002F9578(f32, void *, void *, void *, s32, u8, u8, u8, u8);
extern u8 D_L01_002AF3C0[];
extern s32 D_L01_001D52F0;

typedef struct {
    u8 pad0[0xC];
    f32 scale;
    u8 pad10[0xC];
    s16 h1C;
    u8 pad1E[2];
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
    u8 pad58[4];
    s32 w5C;
    u8 pad60[0x6C - 0x60];
    f32 f6C;
} S_00331230;

typedef struct {
    u8 pad0[0x20];
    vu0_v4 v20;
} T_00331230;

void func_L01_00331230(u8 *a0, void *a1, vu0_v4 *a2, f32 f12) {
    vu0_v4 v1;
    vu0_v4 v2;
    S_00331230 *s = *(S_00331230 **)(a0 + 0x68);
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
    e = func_L01_0046FB40(a0 + 0x10, a2, 0x19, s->w40, 0, 0x64, 0,
                          sx, sy, 0, 0.0f);
    if (e != 0) {
        e[2] = **(u8 **)(D_L01_00221098 + 0x170);
    }
    e = func_L01_0046FB40(a0 + 0x10, a2, 0x19, s->w44, 0, 0x64, 0,
                          sx, sy, 0, 0.0f);
    if (e != 0) {
        e[2] = **(u8 **)(D_L01_00221098 + 0x170);
    }
    for (i = 0; i < 2; i++) {
        u8 *g = D_L01_00221098;
        e = func_L01_0046FB40(a0 + 0x10, a2, 0x19, s->w40, 0, 0x7F, 0,
                              sx, sy, 0, 0.0f);
        if (e != 0) {
            e[2] = (*(u8 **)(g + 0x170))[5];
        }
    }
    for (j = 0; j < 2; j++) {
        u8 *g = D_L01_00221098;
        e = func_L01_0046FB40(a0 + 0x10, a2, 0x19, s->w40, 0, 0x7F, 0,
                              sx, sy, 0, 0.0f);
        if (e != 0) {
            e[2] = (*(u8 **)(g + 0x170))[6];
        }
    }
    ang = func_0038D160(D_L01_001E2A40_00330820[D_L01_001D52F0].pos.x - ((vu0_v4 *)(a0 + 0x10))->x,
                        D_L01_001E2A40_00330820[D_L01_001D52F0].pos.y - ((vu0_v4 *)(a0 + 0x10))->y);
    for (k = 0; k < s->n20; k++) {
        s32 n;
        u8 *q;
        u8 *g;

        n = func_L01_00443A18(2.0f, 5.0f);
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        a = func_003824E0(0.6f, 1.0f) * s->scale;
        b = func_003824E0(9.0f, 12.0f) * s->scale;
        c = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        b *= 0.020000001f;
        v2.x = func_0038D098(c) * b;
        v2.y = func_0038D0B0(c) * b;
        v2.z = 0.0f;
        b = func_003824E0(0.0f, 12.0f) * s->scale;
        v2.z = b * 0.020000001f;
        vec_add_ba(&v2, &v2, a2);
        func_L01_004713C8(&v1, &v2, (func_00382498(30, 50) * 5 + 2) / 6, a * 210000.0f, s->w48, n,
                          0x7F, 0x7F, s->scale * 0.01f * 210000.0f, 0.00584f, 1);
        g = D_L01_00221098;
        n *= -2;
        q = func_L01_004713C8(&v1, &v2, (func_00382498(30, 50) * 5 + 2) / 6, (a *= 6.0f) * 210000.0f, s->w4C, n,
                              0x30, 0x30, s->scale * 0.02f * 210000.0f, 0.00584f, 0);
        if (q != 0) {
            q[2] = **(u8 **)(g + 0xD4);
        }
    }
    for (m = 0; m < s->n24; m++) {
        s32 n;

        n = func_L01_00443A18(2.0f, 5.0f);
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        a = func_003824E0(0.75f, 1.5f) * s->scale;
        b = func_003824E0(9.0f, 12.0f) * s->scale;
        c = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        b *= 0.020000001f;
        v2.x = func_0038D098(c) * b;
        v2.y = func_0038D0B0(c) * b;
        v2.z = 0.0f;
        b = func_003824E0(0.0f, 12.0f) * s->scale;
        v2.z = b * 0.020000001f;
        vec_add_ba(&v2, &v2, a2);
        func_L01_004713C8(&v1, &v2, (func_00382498(30, 50) * 5 + 2) / 6, a * 210000.0f, s->w50, n,
                          0x7F, 0x7F, s->scale * 0.01f * 210000.0f, 0.00584f, 5);
    }
    for (t = 0; t < s->n28; t++) {
        s32 n;

        n = func_L01_00443A18(2.0f, 5.0f);
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        D_L01_001DCF00 = (D_L01_001DCF00 + 1) % 44;
        v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L01_002AF410[D_L01_001DCF00] * 0.1f * s->scale;
        a = func_003824E0(0.6f, 1.0f) * s->scale;
        b = func_003824E0(9.0f, 12.0f) * s->scale;
        c = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        b *= 0.020000001f;
        v2.x = func_0038D098(c) * b;
        v2.y = func_0038D0B0(c) * b;
        v2.z = 0.0f;
        b = func_003824E0(0.0f, 12.0f) * s->scale;
        v2.z = b * 0.020000001f;
        vec_add_ba(&v2, &v2, a2);
        func_L01_004713C8(&v1, &v2, (func_00382498(30, 50) * 5 + 2) / 6, a * 210000.0f, s->w54, n,
                          0x7F, 0x7F, s->scale * 2100.0f, 0.00584f, 3);
    }
    if (s->h1C != 0) {
        s32 col;
        s32 c1;
        s32 c2;
        s32 c3;
        *(vu0_q *)&v2 = 0;
        v2.z = s->scale * 8.0f * 0.020000001f;
        *(vu0_q *)&v1 = *(vu0_q *)&v2;
        vec_add_ba(&v1, &v1, a2);
        col = s->w5C;
        c2 = col >> 16;
        c1 = col >> 8;
        c3 = col >> 24;
        func_L01_002F9578(s->scale * 3.5f, a0, a0 + 0x10, &v1, 0xD, col & 0xFF, c1 & 0xFF, c2 & 0xFF, c3 & 0xFF);
    }
    if (0.0f < f12) {
        v1 = *(vu0_v4 *)(a0 + 0x10);
        v1.w = s->scale * 3.0f;
        if (func_L01_00459590(&v1, 0, 96.0f) > 0) {
            T_00331230 *p = (T_00331230 *)D_L01_002AF3C0;
            p->v20.y = f12;
            p->v20.z = f12;
            p->v20.x = f12;
            func_L01_003006C0((u8 *)p, a0 + 0x10, 0, 0);
        }
    }
    if (0.0f < s->f6C) {
        func_L01_00331D28_00331230(a0, s->f6C);
    }
}
/* localdecomp:end func_L01_00331230 */
