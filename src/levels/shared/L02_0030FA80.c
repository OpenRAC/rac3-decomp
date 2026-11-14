#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L02_00310838);
