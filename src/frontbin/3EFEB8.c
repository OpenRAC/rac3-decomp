#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003EFF18();
extern void func_003EFFE8(void *p, f32, f32);
extern void func_003EFFA0(u8 *p, u8, s32);
extern s32 func_003F0BE8(u8 *arg0, s32, s32);
extern void *func_003F0708();
extern void func_003F0980(void *, s32);
extern void func_003F0AC0(u8 *, s32, f32, f32);
extern void func_003F0A70(void *, f32);
extern void func_003F0CD8(void *, s32);
extern void *malloc(s32, s32) __asm__("func_003F2388");
/* --- end of declarations from other files --- */

/* declarations of 3EE160.c's earlier functions */
extern s32 func_0011A264(void *, s32, s32);
extern s32 func_003EDAF8(void *p, s32 mask);
extern void func_003EDB40(void *p, s32 *a, s32 *b);
extern s32 func_003EDBA8(s32 p, s32 k);
extern void func_003EDCF0(void *a, f32 *b);

/* localdecomp:start func_003EFEB8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003EFEB8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003EFEB8 */

LINKER_REMNANT("asm/remnants", func_003EFEE8);

/* localdecomp:start func_003EFF10 */
s32 func_003EFF10(void) {
    return 2;
}
/* localdecomp:end func_003EFF10 */

/* localdecomp:start func_003EFF18 */
extern void func_003ED988_003EFF18(void);
extern u8 D_001D9798[];
void *func_003EFF18(void *arg0) {
    func_003ED988_003EFF18();
    (*(s32 **)((u8 *)arg0 + 8)) = D_001D9798;
    (*(s32 *)((u8 *)arg0 + 0x50)) = 0x80808080;
    (*(s8 *)((u8 *)arg0 + 0x54)) = 0x10;
    (*(s32 *)((u8 *)arg0 + 0x2C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x30)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x38)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x3C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x40)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x44)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x48)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x4C)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x34)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x5C)) = 1.0f;
    (*(f32 *)((u8 *)arg0 + 0x60)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x58)) = 2;
    return arg0;
}
/* localdecomp:end func_003EFF18 */

/* localdecomp:start func_003EFFA0 */
void func_003EFFA0(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
/* localdecomp:end func_003EFFA0 */

/* localdecomp:start func_003EFFD0 */
s32 func_003EFFD0(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003EFFD0 */

/* localdecomp:start func_003EFFE8 */
void func_003EFFE8(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
/* localdecomp:end func_003EFFE8 */

/* localdecomp:start func_003EFFF8 */
void func_003EFFF8(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EFFF8 */

/* localdecomp:start func_003F0038 */
typedef struct { u8 pad[0x20]; void (*f20)(void *, s32, f32 *, s32); } V_3F0038;
typedef struct {
    u8 p0[8]; V_3F0038 *vt; u8 pC[0x14]; f32 f20, f24; u32 f28; u8 p2C[0x10]; s32 f3C; u8 p40[0x10]; u32 f50; u8 p54[8]; f32 f5C, f60;
} O_3F0038;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96B4;
extern void func_0038E7E8_003F0038(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
void func_003F0038(O_3F0038 *p, s32 a1) {
    f32 r[4];
    f32 cy, cx, s, d;
    f32 ox, oy, z;
    s32 has;
    unsigned long a0, a5; s32 a1_; f32 e;
    if (p->f3C == 0) return;
    z = 0.0f; ox = 0.0f; has = 0; oy = 0.0f;
    p->vt->f20(p, a1, r, 1);
    func_003EDCF0(p, r);
    cx = r[0] + (r[2] - r[0]) * 0.5f;
    cy = r[1] + (r[3] - r[1]) * 0.5f;
    if (func_003EDAF8(p, 0x40)) {
        ox = p->f20;
        has = 1;
        oy = p->f24;
    }
    s = p->f60;
    d = D_001D96B4 * s;
    a5 = p->f28; a1_ = p->f3C; e = p->f5C; a0 = p->f50;
    if (has) {
        func_0038E7E8_003F0038(a0, a1_, -1, 1, has, a5,
            (f32)(s32)(cx * D_001D9698), (f32)(s32)((cy - d) * D_001D969C),
            e, s * 1.0769231f, ox * D_001D9698, oy * D_001D969C);
    } else {
        func_0038E7E8_003F0038(a0, a1_, -1, 1, has, a5,
            (f32)(s32)(cx * D_001D9698), (f32)(s32)((cy - d) * D_001D969C),
            e, s * 1.0769231f, z, z);
    }
}
/* localdecomp:end func_003F0038 */

typedef struct {
    void *vt0; void *vt4; s32 (**vt)(); u8 pad0[0x4]; f32 f10, f14, f18, f1C, f20, f24; u32 f28; u8 pad2[0xC]; s32 f38; s32 f3C; u32 f40; u32 f44; u8 pad3[0x4]; u32 f4C; u32 f50; u8 pad4[0x8]; f32 f5C; f32 f60;
} O_3EAAD0;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96B4;
extern void func_003EDCF0();
extern void func_0038E7E8_003EAAD0(unsigned long, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
/* localdecomp:start func_003F0210 */
typedef struct { u8 b[16]; } B16_003F0210;
typedef struct {
    u8 pad0[0x10]; f32 f10, f14, f18, f1C, f20, f24; u8 pad28[0x14]; s32 f3C; u8 pad40[8]; f32 f48, f4C; u8 pad50[8]; s32 f58; f32 f5C, f60;
} O_003F0210;
extern f32 D_001D96B0;
extern f32 D_001D9698_003F0210[];
extern void func_0038E150(s32);
extern s32 func_00390D20_003F0210(s32, s32, f32);
extern f32 func_00390BF8(s32, s32, s32, f32);
extern void func_003E72A0(f32 *, f32 *);
__asm__(".extern D_001D9698, 4");
void func_003F0210(O_003F0210 *o, f32 *p, f32 *out, s32 flag) {
    f32 t[4];
    f32 sy;
    f32 ay;
    f32 sx;
    f32 ax;
    f32 scale;
    f32 m;
    f32 vx, vy;
    f32 w, h, dx, dy;
    f32 x0, y0, x1, y1, nx, ny;
    s32 k1, k2;

    switch (o->f58) {
    case 1:
        func_0038E150(1);
        break;
    case 2:
        func_0038E150(0);
        break;
    case 0:
    default:
        func_0038E150(0);
        break;
    }
    if (o->f3C) {
        scale = (f32)func_00390D20_003F0210(o->f3C, -1, 1.0f) / D_001D9698_003F0210[0];
    } else {
        scale = 0.0f;
    }
    sy = 2.0f;
    ay = 0.0f;
    sx = sy;
    ax = ay;
    if (flag) {
        k1 = 0;
        k2 = 0;
        func_003EDB40(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = -2.0f;
                ax = 1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = -2.0f;
                ay = 1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    }
    o->f5C = o->f18;
    o->f60 = o->f1C;
    if (func_003EFFD0(o, 1)) {
        if (o->f3C) {
            m = func_00390BF8(o->f3C, -1, (s32)(o->f48 * D_001D9698), o->f4C);
        } else {
            m = 0.0f;
        }
        o->f5C *= m;
        o->f60 *= m;
    }
    if (func_003EDAF8(o, 0x2000)) {
        vx = 0.0f;
        vy = 0.0f;
        func_003E72A0(&vx, &vy);
        o->f5C *= vx;
        o->f60 *= vy;
    }
    w = o->f5C * scale / sx;
    h = o->f60 * D_001D96B0 / sy;
    out[0] = (o->f10 - w) + w * ax;
    out[1] = (o->f14 - h) + h * ay;
    out[2] = (o->f10 + w) + w * ax;
    out[3] = (o->f14 + h) + h * ay;
    if (p[0] == 0.0f && p[2] == 1.0f && p[1] == 0.0f && p[3] == 1.0f) {
        return;
    }
    x0 = out[0];
    y0 = out[1];
    x1 = out[2];
    y1 = out[3];
    nx = (p[2] - p[0]) * x0 + p[0];
    out[0] = nx;
    ny = (p[3] - p[1]) * y0 + p[1];
    out[2] = x1 + (nx - x0);
    out[1] = ny;
    out[3] = y1 + (ny - y0);
    if (func_003EDAF8(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_003F0210 *)t = *(B16_003F0210 *)out;
        t[0] += dx;
        t[2] += dx;
        t[1] += dy;
        t[3] += dy;
        out[0] = (t[0] < out[0]) ? t[0] : out[0];
        out[2] = (out[2] < t[2]) ? t[2] : out[2];
        out[3] = (out[3] < t[3]) ? t[3] : out[3];
        out[1] = (t[1] < out[1]) ? t[1] : out[1];
    }
}
/* localdecomp:end func_003F0210 */

/* localdecomp:start func_003F0658 */
s32 func_003F0658(void *p, s32 a) {
    void (*fn)(s32) = *(void (**)(s32))((u8 *)p + 0x34);
    if (fn != 0) {
        fn(a);
    }
    return 0;
}
/* localdecomp:end func_003F0658 */

/* localdecomp:start func_003F0688 */
s32 func_003F0688(s32 p, s32 k) {
    if (k != 2) {
        return func_003EDBA8(p, k);
    }
    return 1;
}
/* localdecomp:end func_003F0688 */

/* localdecomp:start func_003F06B8 */
extern char D_001D9670[];
extern s32 func_003F2380();
void func_003F06B8(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003F06B8 */

LINKER_REMNANT("asm/remnants", func_003F06E8);

/* localdecomp:start func_003F0700 */
s32 func_003F0700(void) {
    return 3;
}
/* localdecomp:end func_003F0700 */

typedef struct {
    s32 f0, f4, f8, fC, f10, f14;
    s16 f18, f1A;
    s32 f1C;
    u8 f20;
    s16 f22;
    f32 f24, f28;
    s32 f2C, f30;
    u32 f34, f38;
    s32 f3C, f40, f44;
    u8 p48[2];
    u8 f4A;
    u8 p4B[0x56 - 0x4B];
    s16 f56;
    u8 p58;
    u8 f59, f5A;
} O_3EB180;
typedef struct { u8 p0[8]; void *f8; u8 pC[0x2C - 0xC]; O_3EB180 *f2C; u8 f30; s32 f34; } T_3EB180;
typedef struct { s32 f0; s32 f4; } S_3EB180;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3EB180;
extern u8 D_001D97C8;
extern S_3EB180 D_001DA938_003F0708[];
extern s32 *func_003E6C08();
extern void *func_003ED988_003F0708();
extern void **func_003E6CC0();
/* localdecomp:start func_003F0708 */
extern u8 D_001D97C8_003F0708[];
extern void *__nw(s32, s32) __asm__("func_003F2388");
extern void func_003F0B00(u8 *, f32);
extern void func_003F0B20(T_3EB180 *, s32);
extern void func_003F0B48(u8 *, s32);
extern void func_003F0B70(u8 *, s32, s32);
void *func_003F0708(T_3EB180 *p) {
    void **t;
    O_3EB180 *o;
    S_3EB180 *q;
    s32 v;
    func_003ED988_003F0708(p);
    {
        S_3EB180 *d;
        p->f2C = 0;
        p->f8 = D_001D97C8_003F0708;
        d = D_001DA938_003F0708;
        v = d->f4;
        q = d;
        if (v == 0) q = (S_3EB180 *)func_003E6C08(q);
    }
    t = func_003E6CC0(q, 1);
    p->f30 = 0;
    p->f34 = 0;
    if (t != 0) {
        v = (s32)*t;
        o = (O_3EB180 *)__nw(0x5C, ((VT_3EB180 *)v)->f8(t, 0x5C));
        o->f34 = 0x80808080;
        o->f0 = 0;
        o->f4 = 0;
        o->f3C = 0;
        o->f40 = 0;
        o->f44 = 0;
        p->f2C = o;
        o->f24 = 1.0f;
        o->fC = 0;
        o->f10 = 0;
        o->f14 = 0;
        o->f18 = 0;
        o->f1C = 0;
        o->f20 = 0;
        o->f22 = 0;
        o->f2C = 0;
        o->f30 = 0;
        o->f8 = 0;
        o->f38 = 0x80808080;
        o->f1A = -1;
        o->f4A = 0x10;
        o->f28 = 1.0f;
        func_003F0980(p, 0x80808080);
        func_003F0AC0((u8 *)p, 1, 0.0f, 0.0f);
        func_003F0BE8((u8 *)p, 0, 0);
        func_003F0A70(p, 0.03846f);
        func_003F0CD8(p, 2);
        func_003F0B00((u8 *)p, 0.0005f);
        func_003F0B20(p, 0);
        func_003F0B48((u8 *)p, 0);
        p->f2C->f56 = 0;
        p->f2C->f59 = 0;
        func_003F0B70((u8 *)p, 4, 0);
        func_003F0B70((u8 *)p, 8, 0);
        func_003F0B70((u8 *)p, 0x10, 0);
        func_003F0B70((u8 *)p, 0x40, 1);
        p->f2C->f5A = 0;
    }
    return p;
}
/* localdecomp:end func_003F0708 */

s32 *func_003E6C08(s32 *);
void **func_003E6CC0(s32 *, s32);
void func_003F2380_003F08E0(void *);
extern u8 D_001D9670_003F08E0;
extern u8 D_001D97C8;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];
