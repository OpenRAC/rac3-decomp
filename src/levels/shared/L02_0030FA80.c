#include "common.h"
#include "vu0.h"

typedef struct Foo_003102A8 {
    u8 pad30[0x30];
    u8 b30;
    u8 b31;
    u8 b32;
    u8 pad33[0x15];
    f32 f48;
} Foo_003102A8;

typedef struct Gfx_0030FF48 {
    s32 f00;
    u8 pad04[0x20];
    f32 f24;
    u8 pad28[0xB];
    u8 b33;
    u8 pad34[3];
    u8 b37;
    u8 pad38;
    u8 b39;
    u8 b3A;
    u8 b3B;
    u8 b3C;
    u8 pad3D[0x23];
    f32 f60;
    s8 c64;
    s8 c65;
    s8 c66;
    s8 c67;
    s8 c68;
    s8 c69;
    u8 b6A;
} Gfx_0030FF48;
typedef unsigned long UL_0030FF48;

typedef struct Ent_003104A8 {
    f32 f00;
    f32 pad04[2];
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
} Ent_003104A8;

typedef struct Obj_00310838 {
    s32 w0;
    s32 w4;
    u8 pad8[0x1C];
    f32 f24;
    f32 f28;
    f32 f2C;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 pad33;
    u8 b34;
    u8 b35;
    u8 b36;
    u8 pad37[0x15];
    f32 f4C;
    u8 pad50[0x14];
    s8 c64[6];
} Obj_00310838;
typedef struct Stk_00310838 {
    vu0_v4 m[3];
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    vu0_v4 vF0;
    vu0_v4 v100;
    vu0_v4 v110;
} Stk_00310838;

/* localdecomp:start func_L02_0030FA80 */
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_004048D0(void *, void *);
extern void func_L02_00310428(u8*a0);
extern void func_L02_00310838(void *);
extern u8 D_001A4BE0[];
extern u8 D_L02_001E1280[];
extern s32 D_L02_001F1580[];

void func_L02_0030FA80(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (*(s32 *)(s + 0x5C) != -1 && func_00382380(D_L02_001E1280, *(s32 *)(s + 0x5C), 0) == 0) {
        return;
    }
    *(s16 *)(D_001A4BE0 + 0x1FE) = 2;
    if (a0[0x20] == 0) {
        func_L02_00310428(a0);
    }
    if (D_L02_001F1580[0] == *(s32 *)(s + 0x50)) {
        if (func_00382380(D_L02_001E1280, *(s32 *)(s + 0x54), 0) == 0) {
            if (func_00382380(D_L02_001E1280, *(s32 *)(s + 0x58), 0) == 0) {
                func_L01_004048D0(func_L02_00310838, a0);
            }
        }
    }
}
/* localdecomp:end func_L02_0030FA80 */

INCLUDE_ASM("asm/levels", func_L02_0030FB58);

/* localdecomp:start func_L02_0030FC08 */
f32 func_L02_0030FC08(f32 x) {
    if (x < 0.0f) {
        x = -x;
        x = x - (f32)(s32)x;
        return 1.0f - x;
    }
    return x - (f32)(s32)x;
}
/* localdecomp:end func_L02_0030FC08 */

INCLUDE_ASM("asm/levels", func_L02_0030FC68);

/* localdecomp:start func_L02_0030FF48 */
extern UL_0030FF48 D_L02_0026EC60[];
extern s32 D_L02_001E00C4;
extern s32 D_L02_001E00C8;
extern s32 D_L02_001E00CC;
extern s32 D_L02_001E00D0;
extern f32 D_L02_001E5E40[];
extern long func_00389598(s32);
extern f32 func_0038CB30(f32);

void func_L02_0030FF48(Gfx_0030FF48 *s) {
    s32 i;
    s32 mask;
    UL_0030FF48 v;
    UL_0030FF48 t;
    f32 r;

    i = 0;
    D_L02_0026EC60[i++] = 0x1000000000008000UL;
    D_L02_0026EC60[i++] = 0xE;
    D_L02_0026EC60[i++] = ((UL_0030FF48)s->b33 << 32) | (s->b39 ? 0x68 : 0x64);
    D_L02_0026EC60[i++] = 0x42;
    D_L02_0026EC60[i++] = ((UL_0030FF48)s->b37 << 32) | 0x64;
    D_L02_0026EC60[i++] = 0x43;
    D_L02_0026EC60[i++] = 0x50000;
    D_L02_0026EC60[i++] = 0x47;
    D_L02_0026EC60[i++] = 0x51001;
    D_L02_0026EC60[i++] = 0x48;
    D_L02_0026EC60[i++] = 0;
    D_L02_0026EC60[i++] = 8;
    D_L02_0026EC60[i++] = 0;
    D_L02_0026EC60[i++] = 9;
    D_L02_0026EC60[i++] = 0x60;
    D_L02_0026EC60[i++] = 0x15;
    D_L02_0026EC60[i++] = s->b3A | ((UL_0030FF48)s->b3B << 8) | ((UL_0030FF48)s->b3C << 16);
    D_L02_0026EC60[i++] = 0x3D;
    D_L02_001E00C8 = 0;
    D_L02_001E00CC = 0;
    D_L02_001E00D0 = 0;
    mask = 0;
    if (s->f00 >= 0) {
        v = func_00389598(s->f00 + 0x64);
        mask = 1 << (s32)((v >> 26) & 0xF);
        t = (v >> 14) & 0x3F;
        if (s->c64 >= 0) {
            D_L02_001E00C8 = 1;
            t = (t + 1) >> 1;
            D_L02_001E00CC |= (s32)t << 14;
            if (s->c65 >= 0) {
                D_L02_001E00C8 = 2;
                t = (t + 1) >> 1;
                if (s->c66 >= 0) {
                    D_L02_001E00C8 = 3;
                    t = (t + 1) >> 1;
                    if (s->c67 >= 0) {
                        t = (t + 1) >> 1;
                        D_L02_001E00D0 |= (s32)t << 14;
                        D_L02_001E00C8 = 4;
                        if (s->c68 >= 0) {
                            D_L02_001E00C8 = 5;
                            if (s->c69 >= 0) {
                                D_L02_001E00C8 = 6;
                            }
                        }
                    }
                }
            }
        }
    }
    if (D_L02_001E00C8 > 0) {
        s32 sel;
        UL_0030FF48 w;
        UL_0030FF48 c;
        r = func_0038CB30(s->f24 * D_L02_001E5E40[0x84] * 1024.0f /
                          ((f32)mask * D_L02_001E5E40[0x2C] * D_L02_001E5E40[0x28]));
        w = (UL_0030FF48)(s32)((s->f60 - r) * 16.0f) << 32;
        sel = s->b6A ? 5 : 4;
        c = ((UL_0030FF48)sel << 6) | 0x20;
        D_L02_0026EC60[i++] = ((UL_0030FF48)D_L02_001E00C8 << 2) | c | w;
        D_L02_0026EC60[i++] = 0x14;
    } else {
        D_L02_0026EC60[i++] = 0x60;
        D_L02_0026EC60[i++] = 0x14;
    }
    D_L02_0026EC60[0] |= (i >> 1) - 1;
    D_L02_001E00C4 = i >> 1;
}
/* localdecomp:end func_L02_0030FF48 */

/* localdecomp:start func_L02_003102A8 */
extern f32 D_L02_001E00D4;
extern f32 D_L02_001E00D8;

void func_L02_003102A8(Foo_003102A8 *s) {
    Foo_003102A8 *p;
    f32 f2;
    u32 b;
    u32 c;
    u32 m;

    p = s;
    D_L02_001E00D4 = 1.0f;
    m = p->b30;
    b = p->b31;
    c = p->b32;
    if (m < b) {
        m = b;
    }
    if (m < c) {
        m = c;
    }
    if (m >= 0x80) {
        f2 = (f32)(u32)(0xFF - m);
        D_L02_001E00D4 = D_L02_001E00D4 * (f2 * 0.0078125f);
    }
    D_L02_001E00D4 = D_L02_001E00D4 * (p->f48 / D_L02_001E00D8);
}
/* localdecomp:end func_L02_003102A8 */

INCLUDE_ASM("asm/levels", func_L02_00310368);

/* localdecomp:start func_L02_00310428 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L02_0030FC68(void *);
extern void func_L02_003102A8(void *);
extern void func_L02_00310368(void *);
extern void func_L02_0030FF48(void *);

void func_L02_00310428(u8 *a0) {
    u8 *p;

    func_L01_004450F0(a0, 1, -1);
    p = *(u8 **)(a0 + 0x68);
    a0[0x30] = 0xFF;
    if (*(s32 *)p >= 0) {
        if (p[0x33] < 0x10) {
            *(s32 *)p = -1;
        }
    }
    func_L02_0030FC68(p);
    func_L02_003102A8(p);
    func_L02_00310368(p);
    func_L02_0030FF48(p);
}
/* localdecomp:end func_L02_00310428 */

/* localdecomp:start func_L02_003104A8 */
extern Ent_003104A8 D_L02_0026EB80[];
extern f32 D_L02_001E00B8;
extern f32 *D_L02_001E00C0;
extern f32 func_L02_0030FB58(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L02_003104A8(f32 *a, f32 *b, f32 *c, f32 scale) {
    s32 i;
    f32 x, y, r0, r1, r2, r3, r4, r5, r6, r7;
    f32 t, s, g, h;
    f32 *p18;

    for (i = 0; i < 8; i++) {
        s = *(f32 *)((u8 *)D_L02_0026EB80 + i * 0x1C);
        x = D_L02_0026EB80[i].f10;
        y = D_L02_0026EB80[i].f14;
        h = D_L02_0026EB80[i].f0C;
        p18 = &D_L02_0026EB80[0].f18;
        g =*(f32 *)((u8 *)p18 + i * 0x1C);
        t = func_L02_0030FB58(x * a[0] + y * a[1] + g * scale + h);
        r0 = s * func_0038D098(t);
        r1 = s * func_0038D0B0(t);
        t = func_L02_0030FB58(x * b[0] + y * b[1]);
        r2 = func_0038D098(t);
        r3 = func_0038D0B0(t);
        t = func_L02_0030FB58(x * c[0] + y * c[1]);
        r4 = func_0038D098(t);
        r5 = func_0038D0B0(t);
        t = func_L02_0030FB58(D_L02_001E00B8 * (x * b[0] + y * b[1]));
        r6 = func_0038D098(t);
        r7 = func_0038D0B0(t);
        D_L02_001E00C0[i] = r0;
        D_L02_001E00C0[i + 8] = r1;
        D_L02_001E00C0[i + 16] = r2;
        D_L02_001E00C0[i + 24] = r3;
        D_L02_001E00C0[i + 32] = r4;
        D_L02_001E00C0[i + 40] = r5;
        D_L02_001E00C0[i + 48] = -x;
        D_L02_001E00C0[i + 56] = -y;
        D_L02_001E00C0[i + 116] = r6;
        D_L02_001E00C0[i + 124] = r7;
    }
}
/* localdecomp:end func_L02_003104A8 */

INCLUDE_ASM("asm/levels", func_L02_00310730);

/* localdecomp:start func_L02_003107D8 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
void func_L02_003107D8(void *out, f32 *a, f32 *b, f32 t) {
    f32 v[4];
    func_0038CE20(v, b, (t - a[2]) / b[2]);
    vec_add_ba(out, v, a);
}
/* localdecomp:end func_L02_003107D8 */

/* localdecomp:start func_L02_00310838 */
__asm__(".extern D_L02_001DC568, 4");

extern f32 D_L02_001DC568;
extern s32 D_L02_001DE4C0;
extern s32 D_L02_001DE4DC;
extern f32 D_L02_001E00DC;
extern f32 D_L02_001E00E0;
extern f32 D_L02_001E00E4;
extern f32 D_L02_001E00E8;
extern f32 D_L02_001E00EC;
extern f32 D_L02_001E5EF0[];
extern f32 D_L02_001E5EF4[];
extern u32 *D_L02_001DF9E8;
extern u8 D_L02_001E1140[];
extern u8 D_L02_001E1260[];
extern u8 D_L02_001E12B0[];
extern u8 D_00116070[];
extern u16 D_00116060[];
extern u8 D_L02_001D5477;

extern void func_0038CE50(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_003A9338(void *, s32);
extern void func_003A9440(s32, long);
extern void func_L01_0040EE50(void *, void *);
extern void func_L02_00310730(void *, void *, void *, void *, void *);
extern f32 func_L02_0030FC08(f32);
extern void func_L02_003107D8(void *, f32 *, f32 *, f32);
extern void func_L02_003104A8(f32 *, f32 *, f32 *, f32);

#define C0(T, o) (*(T *)((u8 *)D_L02_001E00C0 + (o)))
#define CC(o) (*(f32 *)(c + (o)))

void func_L02_00310838(void *arg) {
    Stk_00310838 s;
    Obj_00310838 *p;
    f32 cur;
    f32 lim;
    f32 f26;
    f32 ang;
    f32 n0;
    f32 n1;
    f32 inv;
    f32 d;
    f32 ox;
    f32 nx;
    f32 q;
    f32 u1;
    f32 t;
    f32 r1;
    f32 r2;
    u32 k;
    long a;
    long b;
    long lo;
    long hi;
    u8 *cam;

    p = *(Obj_00310838 **)((u8 *)arg + 0x68);
    if (D_L02_001D5477) {
        func_0038CE20(D_L02_001E12B0, D_L02_001E12B0, -1.0f);
    }
    cur = p->f4C;
    f26 = (f32)D_L02_001DE4C0 * 0.020000001f;
    cam = D_L02_001E1140;
    lim = *(f32 *)(cam + 0x148);
    if (lim <= cur) {
        return;
    }
    if (lim <= cur + 0.5f) {
        cur = lim - 0.5f;
    }
    cur += D_L02_001E00DC;
    ang = func_0038D160(*(f32 *)(cam + 0x188), *(f32 *)(cam + 0x178));
    n1 = *(f32 *)(cam + 0x160);
    n0 = -*(f32 *)(cam + 0x164);
    inv = 1.0f / sqrt_asm(n1 * n1 + n0 * n0);
    n1 = n1 * inv;
    n0 = n0 * inv;
    func_L01_0040EE50(&s, cam + 0x160);
    ang = ang * 1.2732395f;
    ang = ang + 8.0f;
    s.v40.x = 1.0f;
    k = (s32)ang & 7;
    s.v40.w = 0.0f;
    switch (k) {
    case 0:
    case 1:
        s.v40.y = -D_L02_001E5E40[0x2C];
        s.v40.z = -D_L02_001E5E40[0x2D];
        break;
    case 2:
    case 3:
        s.v40.y = -D_L02_001E5E40[0x2C];
        s.v40.z = D_L02_001E5E40[0x2D];
        break;
    case 4:
    case 5:
        s.v40.y = D_L02_001E5E40[0x2C];
        s.v40.z = D_L02_001E5E40[0x2D];
        break;
    case 6:
    case 7:
        s.v40.y = D_L02_001E5E40[0x2C];
        s.v40.z = -D_L02_001E5E40[0x2D];
        break;
    }
    func_0038D000(&s.v30, &s.v40, D_L02_001E1280 + 0x20);
    if (0.0f <= s.v30.z) {
        return;
    }
    func_L02_003107D8(&s.v50, (f32 *)(D_L02_001E1280), (f32 *)&s.v30, cur);
    s.v80.w = 0.0f;
    switch (k) {
    case 0:
    case 3:
        s.v80.y = -1.0f;
        s.v80.x = D_L02_001E5EF0[0];
        s.v80.z = 0.0f;
        break;
    case 1:
    case 6:
        s.v80.z = -1.0f;
        s.v80.x = D_L02_001E5EF4[0];
        s.v80.y = 0.0f;
        break;
    case 2:
    case 5:
        s.v80.z = 1.0f;
        s.v80.x = D_L02_001E5EF4[0];
        s.v80.y = 0.0f;
        break;
    case 4:
    case 7:
        s.v80.y = 1.0f;
        s.v80.x = D_L02_001E5EF0[0];
        s.v80.z = 0.0f;
        break;
    }
    func_0038D000(&s.v70, &s.v80, D_L02_001E1280 + 0x20);
        s.v110.x = n0;
    s.v110.y = n1;
    s.v110.z = 0.0f;
    s.v110.w = 0.0f;
    func_L02_00310730(&s.v60, &s.v50, &s.v110, D_L02_001E1280, &s.v70);
    d = func_0038CF00(&s.v50, &s.v60);
    vec_add_ab(&s.vD0, &s.v50, &s.v60);
    func_0038CE20(&s.vD0, &s.vD0, 0.5f);
    vec_sub_ab(&s.v100, &s.vD0, D_L02_001E1280);
    func_0038D000(&s.v100, &s.v100, &s.m);
    ox = s.v100.x;
    vec_sub_ba(&s.v100, &s.vD0, D_L02_001E1280);
    s.v100.x = s.v100.x + n1 * 650.0f;
    s.v100.y = s.v100.y + -n0 * 650.0f;
    func_0038D000(&s.v100, &s.v100, &s.m);
    nx = s.v100.x;
    q = d * nx / ox;
    if (d < 32.0f) {
        d = 32.0f;
    }
    D_L02_001E00B8 = (q - d) * D_L02_001DC568 / ((nx - ox) * d);
    s.vD0.z = s.vD0.z - D_L02_001E00DC;
    func_0038CE20(&s.v90, &s.v110, d * 0.015625f);
    switch (k) {
    case 0:
    case 7:
        {
            u8 *c = D_L02_001E1140;
            s.vB0.z = 0.0f;
            s.vB0.x = CC(0x174);
            s.vB0.y = -CC(0x170);
            s.vB0.w = 0.0f;
        }
        break;
    case 1:
    case 2:
        {
            u8 *c = D_L02_001E1140;
            s.vB0.z = 0.0f;
            s.vB0.x = -CC(0x184);
            s.vB0.y = CC(0x180);
            s.vB0.w = 0.0f;
        }
        break;
    case 3:
    case 4:
        {
            u8 *c = D_L02_001E1140;
            s.vB0.z = 0.0f;
            s.vB0.x = -CC(0x174);
            s.vB0.y = CC(0x170);
            s.vB0.w = 0.0f;
        }
        break;
    case 5:
    case 6:
        {
            u8 *c = D_L02_001E1140;
            s.vB0.z = 0.0f;
            s.vB0.x = CC(0x184);
            s.vB0.y = -CC(0x180);
            s.vB0.w = 0.0f;
        }
        break;
    }
    inv = 1.0f / sqrt_asm(s.vB0.x * s.vB0.x + s.vB0.y * s.vB0.y);
    func_0038CE20(&s.vB0, &s.vB0, inv * D_L02_001DC568);
    vec_sub_ab(&s.vE0, &s.vD0, D_L02_001E1280);
    s.vE0.w = 1.0f;
    func_0038CE20(&s.v100, &s.vE0, 1024.0f);
    func_0038D028(&s.vF0, &s.v100, D_L02_001E1280 - 0x40);
    func_0038CE20(&s.v100, &s.v90, 1024.0f);
    func_0038D028(&s.vA0, &s.v100, D_L02_001E1280 - 0x40);
    func_0038CE20(&s.v100, &s.vB0, 1024.0f);
    func_0038D028(&s.vC0, &s.v100, D_L02_001E1280 - 0x40);
    if (D_L02_001DE4DC != 10) {
        func_003A9338(D_00116070, D_00116060[0]);
        D_L02_001DE4DC = 10;
    }
    D_L02_001DF9E8[0] = D_L02_001E00C4 | 0x30000000;
    D_L02_001DF9E8[1] = (u32)D_L02_0026EC60;
    D_L02_001DF9E8[2] = 0x13000000;
    a = 0;
    b = 0;
    D_L02_001DF9E8[3] = D_L02_001E00C4 | 0x50000000;
    D_L02_001DF9E8 = D_L02_001DF9E8 + 4;
    if (p->w0 >= 0) {
        a = func_00389598(p->w0 + 0x64);
        if (D_L02_001E00C8 > 0) {
            lo = D_L02_001E00CC;
            hi = D_L02_001E00D0;
            lo |= func_00389598(p->c64[0] + 0x64) & 0x3FFF;
            if (D_L02_001E00C8 > 1) {
                lo |= (func_00389598(p->c64[1] + 0x64) & 0x3FFF) << 20;
                if (D_L02_001E00C8 > 2) {
                    lo |= (func_00389598(p->c64[2] + 0x64) & 0x3FFF) << 40;
                    if (D_L02_001E00C8 > 3) {
                        hi |= func_00389598(p->c64[3] + 0x64) & 0x3FFF;
                        if (D_L02_001E00C8 > 4) {
                            hi |= (func_00389598(p->c64[4] + 0x64) & 0x3FFF) << 20;
                            if (D_L02_001E00C8 > 5) {
                                hi |= (func_00389598(p->c64[5] + 0x64) & 0x3FFF) << 40;
                            }
                        }
                        func_003A9440(0x36, hi);
                    }
                }
            }
            func_003A9440(0x34, lo);
        }
    }
    if (p->w4 >= 0) {
        b = func_00389598(p->w4 + 0x64);
    }
    D_L02_001DF9E8[0] = 0x1000002B;
    D_L02_001DF9E8[1] = 0;
    D_L02_001DF9E8[2] = 0x1000404;
    D_L02_001DF9E8[3] = 0x6C2B0000;
    {
        u32 *w = D_L02_001DF9E8;
        D_L02_001E00C0 = (f32 *)(w + 4);
        D_L02_001DF9E8 = w + 0xB0;
        w[0xB0] = 0x10000000;
    }
    D_L02_001DF9E8[1] = 0;
    D_L02_001DF9E8[2] = 0x14000000;
    D_L02_001DF9E8[3] = 0x11000000;
    D_L02_001DF9E8 = D_L02_001DF9E8 + 4;
    func_L02_003104A8((f32 *)&s.vD0, (f32 *)&s.v90, (f32 *)&s.vB0, f26);
    C0(f32, 0x160) = (f32)p->b30;
    C0(f32, 0x164) = (f32)p->b31;
    C0(f32, 0x168) = (f32)p->b32;
    C0(f32, 0x16C) = 0.0f;
    C0(vu0_q, 0x100) = *(vu0_q *)&s.vF0;
    C0(vu0_q, 0x110) = *(vu0_q *)&s.vA0;
    C0(vu0_q, 0x120) = *(vu0_q *)&s.vC0;
    u1 = 1.0f / p->f24;
    r1 = func_0038D098(func_L02_0030FB58(p->f28 * 0.017453292f));
    t = p->f2C * r1;
    r2 = func_0038D0B0(func_L02_0030FB58(p->f28 * 0.017453292f));
    C0(f32, 0x130) = func_L02_0030FC08((-s.vD0.y + f26 * (p->f2C * r2)) * u1);
    C0(f32, 0x134) = func_L02_0030FC08((s.vD0.x - f26 * t) * u1);
    C0(f32, 0x138) = 1.0f;
    C0(f32, 0x140) = -s.v90.y * u1;
    C0(f32, 0x144) = s.v90.x * u1;
    C0(f32, 0x150) = -s.vB0.y * u1;
    C0(f32, 0x154) = s.vB0.x * u1;
    C0(f32, 0x118) = D_L02_001E00B8;
    C0(f32, 0x13C) = 0.0f;
    C0(f32, 0x15C) = 1.0f;
    func_0038CE50((u8 *)D_L02_001E00C0 + 0x180, D_L02_001E1260, 1024.0f);
    C0(vu0_q, 0x190) = *(vu0_q *)((u8 *)D_L02_001E5E40 + 0x190);
    C0(f32, 0x190) = C0(f32, 0x190) * D_L02_001E5E40[0x74];
    C0(f32, 0x194) = C0(f32, 0x194) * D_L02_001E5E40[0x75];
    C0(vu0_q, 0x1A0) = *(vu0_q *)((u8 *)D_L02_001E5E40 + 0x1A0);
    C0(s32, 0x1B0) = 0x21;
    C0(s32, 0x1B4) = 0x32;
    C0(s32, 0x1B8) = 0x32;
    C0(s32, 0x1BC) = 5;
    C0(f32, 0x268) = D_L02_001E00E0;
    C0(f32, 0x26C) = D_L02_001E00E4;
    C0(f32, 0x19C) = D_L02_001E00E8;
    C0(f32, 0x1AC) = D_L02_001E00EC;
    C0(s32, 0x1C0) = 0x8000;
    C0(s32, 0x1C4) = p->w0 >= 0 ? 0x303E4000 : 0x30364000;
    C0(s32, 0x1C8) = 0x412;
    C0(s32, 0x1CC) = 0;
    func_0038CE20((u8 *)D_L02_001E00C0 + 0x210, &s.vE0, -1.0f);
    func_0038CE20((u8 *)D_L02_001E00C0 + 0x220, &s.v90, -1.0f);
    func_0038CE20((u8 *)D_L02_001E00C0 + 0x230, &s.vB0, -1.0f);
    C0(f32, 0x22C) = n1 * D_L02_001E00D4;
    C0(f32, 0x21C) = -n0 * D_L02_001E00D4;
    C0(f32, 0x228) = 1.0f;
    C0(s32, 0x240) = p->b34;
    C0(s32, 0x244) = p->b35;
    C0(s32, 0x248) = p->b36;
    C0(s32, 0x250) = 0x8000;
    C0(s32, 0x254) = p->w4 >= 0 ? 0x313E4000 : 0x31364000;
    C0(s32, 0x258) = 0x412;
    C0(s32, 0x25C) = 0;
    switch (k) {
    case 0:
    case 7:
        C0(s32, 0x270) = 0x32;
        C0(s32, 0x274) = 0x31;
        C0(s32, 0x278) = 8;
        break;
    case 1:
    case 2:
        C0(s32, 0x270) = 0x34;
        C0(s32, 0x274) = 0x38;
        C0(s32, 0x278) = 2;
        break;
    case 3:
    case 4:
        C0(s32, 0x270) = 0x31;
        C0(s32, 0x274) = 0x32;
        C0(s32, 0x278) = 4;
        break;
    case 5:
    case 6:
        C0(s32, 0x270) = 0x38;
        C0(s32, 0x274) = 0x34;
        C0(s32, 0x278) = 1;
        break;
    }
    if (D_L02_001D5477) {
        s32 x = C0(s32, 0x274);
        s32 y = C0(s32, 0x270);
        C0(s32, 0x270) = x;
        C0(s32, 0x274) = y;
    }
    C0(s32, 0x280) = 1;
    C0(s32, 0x284) = 0x10000000;
    C0(s32, 0x288) = 0xE;
    C0(s32, 0x28C) = 0;
    C0(long, 0x290) = a;
    C0(s32, 0x298) = 6;
    C0(long, 0x2A0) = b;
    C0(s32, 0x2A8) = 7;
    func_003A9440(0x47, 0x5360B);
    if (D_L02_001D5477) {
        func_0038CE20(D_L02_001E12B0, D_L02_001E12B0, -1.0f);
    }
}
/* localdecomp:end func_L02_00310838 */
