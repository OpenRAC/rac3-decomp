/* functional: high. Written from PAL asm, every block read against it (init with owner modes 2/4/0x42, per-frame gravity/drift, alpha/size/shrink). Needs file flag -mvu0-use-vf0-vf2; not byte-identical (217 diffs, same frame size). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) PV4;
static void pv_add(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] + q[0], y = p[1] + q[1], z = p[2] + q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
static void pv_sub(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] - q[0], y = p[1] - q[1], z = p[2] - q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
#include "common.h"

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 D_L33_001DDB98;
extern f32 D_L33_001DDB9C;
extern f32 D_L33_001DDBCC;
extern f32 D_L33_001DDBC8;
extern f32 D_L33_001DDAE0[];
extern f32 D_L33_001DD964;
extern s32 D_L33_001DDBA0;
extern s32 D_L33_001DDBA4;
extern f32 D_L33_001DDBB0;
extern f32 D_L33_001DDBAC;
extern f32 D_L33_001DDBBC;
extern f32 D_L33_001DDBA8;

void func_L33_003523C0(u8 *a, u8 *b) {
    u8 *c;
    u8 *st;
    u16 hw;
    s32 mode;
    s32 mag;
    f32 k, e, h, x, ang, rnd, len, r;
    f32 t[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));

    if (b == 0) {
        return;
    }
    c = *(u8 **)b;
    if (c == 0) {
        return;
    }
    st = *(u8 **)(c + 0x68);
    if (*(s32 *)(b + 4) == 0) {
        return;
    }
    if (*(u16 *)(b + 0xA) & 1) {
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        rnd = func_003824E0(0.0f, 1.0f);
        len = D_L33_001DDB98 * *(f32 *)(c + 0xC) * rnd * 0.0009765625f;
        func_003C2F58(c, 2, a + 0x10);
        t[0] = func_0038D098(ang) * len;
        t[2] = func_0038D0B0(ang) * len;
        t[1] = 0.0f;
        pv_add(a + 0x10, a + 0x10, t);
        r = func_003824E0(-D_L33_001DDBCC, D_L33_001DDBCC);
        *(f32 *)(a + 0x14) += r;
        mode = c[0x20];
        if (mode == 2 || mode == 4) {
            r = func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f);
            *(f32 *)(b + 0x10) = *(f32 *)(st + 0x60) * D_L33_001DDB9C * r;
            r = func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f);
            *(f32 *)(b + 0x14) = *(f32 *)(st + 0x68) * D_L33_001DDB9C * r;
        } else if (mode == 0x42) {
            r = func_003824E0(1.0f - D_L33_001DDBC8, D_L33_001DDBC8 + 1.0f);
            func_0038CF68(v, t, D_L33_001DDAE0[0x1761 - *(s16 *)(c + 0xAA)] * r);
            *(f32 *)(b + 0x10) = v[0] + D_L33_001DD964 * *(f32 *)(st + 0x60);
            *(f32 *)(b + 0x14) = v[2] + D_L33_001DD964 * *(f32 *)(st + 0x68);
        }
        if (*(s32 *)(st + 0xA8) != 0) {
            *(s32 *)(a + 4) = 0x80000000;
        } else {
            *(s32 *)(a + 4) = func_L30_0034DBA0(D_L33_001DDBA0, D_L33_001DDBA4);
        }
        *(f32 *)(a + 0xC) = func_003824E0(D_L33_001DDBB0, D_L33_001DDBAC);
    }
    mag = (*(s16 *)(b + 0xC) & 0xFF00) >> 8;
    *(f32 *)(b + 0x14) -= D_L33_001DDBBC * ((f32)mag * 0.00390625f);
    *(f32 *)(a + 0x10) += *(f32 *)(b + 0x10);
    *(f32 *)(a + 0x18) += *(f32 *)(b + 0x14);
    *(s32 *)(a + 4) = (*(s32 *)(a + 4) & 0xFFFFFF) |
        ((s32)((f32)*(s16 *)(a + 0xA) * 128.0f / (f32)*(s16 *)(b + 8)) << 24);
    hw = *(u16 *)(b + 0xE);
    k = D_L33_001DDBA8 * (f32)*(s16 *)(b + 8) * (f32)(hw >> 8) * 0.00390625f;
    e = (f32)(hw & 0xFF);
    h = e + k;
    x = func_L03_0034B148(*(s16 *)(a + 0xA), *(s16 *)(b + 8), 0.0f);
    *(s8 *)(a + 8) = (s32)func_003C4088(e, h, x);
    *(f32 *)(a + 0xC) = *(f32 *)(a + 0xC) * ((f32)*(s16 *)(a + 0xA) / (f32)(*(s16 *)(a + 0xA) + 1));
}
