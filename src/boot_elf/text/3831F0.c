#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 382780.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001D9A20;
extern void func_0038D3E0_00382760(void *, void *, void *);
extern s32 func_0013D3E0(void);
extern s32 func_0013D3E0(void);
extern s32 func_13D3E0(void);
extern s32 func_0013D3E0(void);
extern f32 func_00382918(void);
extern f32 func_003828C0(f32, f32);
extern void func_00382B40(void *, f32, f32, f32);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
extern E_0037E568 D_00222480_00382BF0[];
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222480_00382CB8[];
extern f32 D_002259B0[];
extern void func_00383038(f32 *, f32, f32, f32, f32, f32);
extern s32 func_0038CEE0(void *);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_003C3FA0(f32, f32, f32);
extern void func_003877A0();
void func_0038D108(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern u8 D_00224B10[];
extern u8 D_00225450[];
extern s32 D_001D9A80[2];
extern void (*D_001D9A40[2])(s32);
extern void func_0038DE98(f32, f32);
extern f32 func_0038DEE0(f32, f32);
s32 func_00381C88(void *, s32, s32, s32);
extern void func_003C2C38(s32 p);
extern u8 D_002224E0[];
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_00380F80[];

/* localdecomp:start func_003831F0 */
typedef int u128_37EB68 __attribute__((mode(TI)));
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68;
extern E_37EB68 D_00222480_003831F0[];
extern u8 *D_001D9A84;
extern u8 D_002251D0[];
extern void func_00382E60(s32);
extern void func_003831A8(u8 *);
void func_003831F0(u8 *o, s32 a1) {
    s32 idx = *(s32 *)(o + 0x94);
    s32 j = idx;
    u8 *e = (u8 *)D_00222480_003831F0 + idx * 0x460;
    u8 *q = *(u8 **)(e + 0x50);
    s32 k = *(s16 *)(q + 0x7E);
    u8 *t;
    s32 m;
    s32 off;
    f32 f;
    if (a1 != 0 || *(s32 *)(e + 0x458) > 0) k = 4;
    t = *(u8 **)((u8 *)((*(s16 *)(o + 0x84) << 5) + (s32)D_001D9A84) + 0x1C);
    m = 0;
    if (t != 0) m = t[0x1D];
    if (k == 4) {
        *(s16 *)(e + 0x2A0) = 0;
        *(s16 *)(o + 0x8E) = 1;
    } else if (k == 2 || m == 1 || m == 5) {
        if (m == 1) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 0;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2C8 = f;
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2B8 = 0.018f;
            }
        } else if (m == 5) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 2;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f324 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f324 = 0x28;
            }
        }
        if (*(s16 *)(e + 0x2A0) == 0) {
            *(s16 *)(e + 0x2A0) = 1;
        } else {
            *(s16 *)(e + 0x2A0) = 2;
        }
    } else if (*(s16 *)(q + 0x7E) == 3 || *(s16 *)(q + 0x7E) == 5 || m == 3 || m == 6) {
        *(u128_37EB68 *)(o + 0x30) = *(u128_37EB68 *)(q + 0x30);
        *(u128_37EB68 *)(o + 0x00) = *(u128_37EB68 *)(q + 0x00);
        *(u128_37EB68 *)(o + 0x10) = *(u128_37EB68 *)(q + 0x10);
        *(u128_37EB68 *)(o + 0x20) = *(u128_37EB68 *)(q + 0x20);
        o[0x7D] = 2;
        if (*(s16 *)(q + 0x7E) == 5 || m == 6) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 0;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2C8 = f;
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68 *)((u8 *)D_00222480_003831F0 + j * 0x460))->f2B8 = 0.018f;
            }
        }
    } else {
        *(s16 *)(o + 0x8E) = 1;
    }
    off = j * 0x780;
    *(s16 *)(q + 0x7E) = 0;
    q[0x7D] = 0;
    *(s16 *)(q + 0x8E) = 0;
    *(u8 **)(e + 0x54) = q;
    func_0038D108(D_002251D0 + off, D_002251D0 - 0x280 + off, 0x280);
    *(u8 **)(*(u8 **)(e + 0x54) + 0x70) = D_002251D0 + off;
    *(u8 **)(e + 0x50) = o;
    *(u8 **)(o + 0x70) = D_002251D0 - 0x280 + off;
    q = o;
    *(s32 *)(e + 0x454) = 0;
    func_003831A8(q);
    func_00382E60(idx);
    *(u128_37EB68 *)e = *(u128_37EB68 *)(q + 0x30);
    {
        f32 *src = (f32 *)(q + 0x30);
        f32 *dst = (f32 *)(q + 0x64);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}
/* localdecomp:end func_003831F0 */

/* localdecomp:start func_00383508 */
typedef struct { u8 p0[0xC]; s32 fC; u8 p10[0x24 - 0x10]; s32 f24; } T_37EE80;
typedef struct { u8 p0[0x1C]; T_37EE80 *f1C; } R_37EE80;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0x5E0 - 0x5D4]; s32 f5E0; u8 p5E4[0x690 - 0x5E4]; s32 f690; u8 p694[0x6A0 - 0x694]; s32 f6A0; u8 p6A4[0x25CC - 0x6A4]; s32 f25CC; } A_37EE80;
typedef struct { u8 p0[0x24C]; s32 f24C; u8 p250[0x460 - 0x250]; } E_37EE80;
extern u8 *D_001D9A84_00383508;
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } G2_37EE80;
extern G2_37EE80 *D_001D9E50;
extern A_37EE80 D_001A4BE0_00383508;
extern E_37EE80 D_00222480_00383508[];
extern u8 D_002225D0[];
extern s32 func_00382760(void *, s32, s32);
s32 func_00383508(s32 idx, u8 *o, u8 *t) {
    u8 *s = o + 0x74;
    s32 (*f)(u8 *, u8 *);
    s32 r;
    if (o[0x7C] == 0) return 0;
    f = (s32 (*)(u8 *, u8 *))D_00380F80[*(s16 *)(o + 0x8C)].b;
    if (f != 0) {
        r = f(o, t);
        if (r == -1) return 0;
        if (r == 1) return 1;
    }
    switch (*(s32 *)s) {
    case 1:
    case 2:
        if (s[9] == 0) break;
    case 0:
        if (t == 0) return 1;
        if (*(s16 *)(t + 0x7E) != 0) return 1;
        if (s[8] > t[0x7C]) return 1;
        break;
    case 4: {
        T_37EE80 *e = ((R_37EE80 *)(D_001D9A84_00383508 + *(s16 *)(o + 0x84) * 32))->f1C;
        if (t != 0 && *(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        { u8 *p = D_002225D0 + idx * 0x460; if (func_00382760(p + 0x40, e->fC, 0) != 0) return 1; }
        break;
    }
    case 7: {
        s32 h = *(s16 *)(o + 0x86);
        T_37EE80 *e;
        s32 a5, a7, k;
        if (h != ((E_37EE80 *)(idx * 0x460 + (s32)D_00222480_00383508))->f24C) break;

        if (*(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        if (h != 3) return 1;
        e = ((R_37EE80 *)((s32)D_001D9A84_00383508 + (*(s16 *)(o + 0x84) << 5)))->f1C;
        if (D_001A4BE0_00383508.f25CC == 0x1A) {
            a5 = D_001A4BE0_00383508.f690;
            a7 = D_001A4BE0_00383508.f6A0;
        } else {
            a5 = D_001A4BE0_00383508.f5D0;
            a7 = D_001A4BE0_00383508.f5E0;
        }
        k = e->f24;
        if (k < 0) return 1;
        if (a5 != D_001D9E50[k].f10) break;
        if (a7 == 0) return 1;
        break;
    }
    }
    return 0;
}
/* localdecomp:end func_00383508 */

extern S_37D000 D_00380F80[];
/* localdecomp:start func_00383718 */
void func_00383718(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_00380F80[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_00383718 */

/* localdecomp:start func_00383760 */
extern u8 D_00222A10_00383760[];
extern u8 D_001D9B10_00383760[8];
extern void func_00383718(u8 *);
extern s32 func_00383508(s32, u8 *, u8 *);
extern void func_003831F0(u8 *, s32);
extern void func_00383128(s32, void *);
extern void func_00382F00(s32);
s32 func_00383760(s32 a) {
    s32 found = 0;
    s32 i;
    u8 *cur = (u8 *)((S_00222500_0037E7D8 *)(a * 0x460 + (s32)D_00222480))->f50;
    u8 *p;
    u8 *q;
    void (*f)(u8 *);
    f32 *src;
    f32 *dst;
    func_00383718(cur);
    p = (u8 *)(a * 0x2100 + (s32)D_00222A10_00383760);
    q = (u8 *)(a * 0x30 + (s32)D_001D9B10_00383760);
    for (i = 0; i < 48; i++) {
        if (*q != 0 && p != cur && func_00383508(a, p, cur) != 0) {
            cur = p;
            found = 1;
        }
        p += 0xB0;
        q++;
    }
    if (found != 0) {
        func_003831F0(cur, 0);
    }
    f = (void (*)(u8 *))D_00380F80[*(s16 *)(cur + 0x8C)].d;
    func_00383128(a, cur);
    if (f != 0) {
        f(cur);
    }
    src = (f32 *)(cur + 0x30);
    dst = (f32 *)(cur + 0x64);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    func_00382F00(a);
    return -1;
}
/* localdecomp:end func_00383760 */

/* localdecomp:start func_003838B0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F228;
typedef int Q_37F228 __attribute__((mode(TI)));
extern f32 func_0038D248(void *, void *);
extern f32 func_0038D288(void *);
extern f32 func_0038D4A8(f32);
extern void func_0038DC70(void *, void *, void *, f32);
extern void func_0038D348(s32 a, s32 b, f32 x);
void func_003838B0(f32 *out, V_37F228 *a, V_37F228 *b, V_37F228 *c, V_37F228 *d4, V_37F228 *n) {
    V_37F228 d, p, e, w, r;
    f32 t, l, ang, h;
    {
        Q_37F228 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    }
    t = func_0038D248(&d, n);
    func_0038D348((s32)&p, (s32)n, t);
    {
        Q_37F228 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(x));
    }
    t = func_0038D248(c, &e);
    l = func_0038D288(&e);
    if (l == 0.0f) l = 0.0001f;
    h = 1.5707964f;
    ang = h - func_0038D4A8(t / l);
    func_0038D348((s32)&w, (s32)&e, 1.0f);
    if (func_0038D248(d4, &w) < 0.0f) ang = -ang;
    out[0] = ang;
    func_0038DC70(&r, c, n, ang);
    t = func_0038D248(&r, &d);
    l = func_0038D288(&d);
    if (l == 0.0f) l = 0.0001f;
    h = h - func_0038D4A8(t / l);
    func_0038D348((s32)&w, (s32)&d, 1.0f);
    ang = -h;
    if (func_0038D248(n, &w) < 0.0f) ang = h;
    out[1] = ang;
    out[2] = func_0038D288(&d);
}
/* localdecomp:end func_003838B0 */
