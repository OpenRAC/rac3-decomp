#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00387268(void);
extern void func_00387F68(void);
extern void func_00388138(void);
/* --- end of declarations from other files --- */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001D9A20;
extern void func_0038D000_00382380(void *, void *, void *);
/* localdecomp:start func_00382380 */
s32 func_00382380(void *a, s32 idx, Q_37E0F0 *out) {
    V4_37E0F0 v;
    V4_37E0F0 r;
    u8 *e;
    Q_37E0F0 p, q, t;
    if (idx == -1) {
        return 0;
    }
    e = D_001D9A20 + idx * 0x80;
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_37E0F0 *)a));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_37E0F0 *)(e + 0x30)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(t));
    v.w = 0.0f;
    func_0038D000_00382380(&r, &v, e + 0x40);
    if (out != 0) {
        *out = *(Q_37E0F0 *)&r;
    }
    if (r.x >= -1.0f && r.x <= 1.0f && r.y >= -1.0f && r.y <= 1.0f && r.z >= -1.0f && r.z <= 1.0f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00382380 */

/* localdecomp:start func_00382468 */
extern s32 func_0013D3E0(void);
s32 func_00382468(s32 a) {
    return func_0013D3E0() % a;
}
/* localdecomp:end func_00382468 */

/* localdecomp:start func_00382498 */
extern s32 func_0013D3E0(void);
s32 func_00382498(s32 lo, s32 hi) {
    return func_0013D3E0() % (hi - lo + 1) + lo;
}
/* localdecomp:end func_00382498 */

/* localdecomp:start func_003824E0 */
extern s32 func_13D3E0(void);
f32 func_003824E0(f32 a, f32 b) {
    return a + (f32)func_13D3E0() * (b - a) * (1.0f / 32768.0f);
}
/* localdecomp:end func_003824E0 */

extern s32 func_0013D3E0(void);
/* localdecomp:start func_00382538 */
extern s32 func_0013D3E0(void);
f32 func_00382538(void) {
    return (f32)(func_0013D3E0() - 0x4000) * 3.1415927f * (1.0f / 16384.0f);
}
/* localdecomp:end func_00382538 */

/* localdecomp:start func_00382580 */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
void func_00382580(s32 a, f32 x, f32 y) {
    f32 p = func_00382538();
    f32 q = func_00382538();
    func_00382760(a, func_003824E0(x, y), p, q);
}
/* localdecomp:end func_00382580 */

INCLUDE_ASM("asm/nonmatchings/text", func_003825F8);

extern s32 D_001D9A28_0037E368[2];
extern s32 D_001D9A30_0037E368[2];
extern s32 D_001D9D08_0037E368;
extern f32 func_0038D098(f32);
extern void func_0038DBD8(s32, s32, f32);

/* localdecomp:start func_00382760 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_00382760(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f22;

    temp_f22 = func_0038D098(fparg2);
    (*(f32 *)((u8 *)(arg0) + 0)) = (f32) (func_0038D098(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 4)) = (f32) (func_0038D0B0(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 8)) = (f32) (func_0038D0B0(fparg2) * fparg0);
}
/* localdecomp:end func_00382760 */

LINKER_REMNANT("asm/remnants", func_003827F0);

typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
extern E_0037E568 D_00222480_00382810[];
/* localdecomp:start func_00382810 */
void func_00382810(s32 idx, s32 b, s32 m, f32 x, f32 y, f32 z, f32 w) {
    E_0037E568 *e = &D_00222480_00382810[idx];
    switch (m) {
    case 0:
        e->f424 = x;
        e->b439 = 1;
        e->b438 = 0;
        break;
    case 1:
    case 2:
        if (b == 0) {
            e->f424 = x;
            e->b438 = 0;
        } else {
            f32 fb = (f32)b;
            e->b438 = m;
            e->f440 = e->f428;
            e->h43A = b;
            e->f43C = 1.0f / fb;
        }
        e->b439 = 1;
        break;
    case 3:
        e->b438 = m;
        e->f424 = x;
        e->b439 = 1;
        e->f42C = y;
        e->f430 = z;
        e->f434 = w;
        break;
    }
}
/* localdecomp:end func_00382810 */

typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222480_003828D8[];
extern f32 D_002259B0[];
extern s32 func_0038CB00(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003873C0();
/* localdecomp:start func_003828D8 */
extern void func_00382C58(f32 *, f32, f32, f32, f32, f32);
void func_003828D8(s32 idx) {
    E_0037E630 *e = &D_00222480_003828D8[idx];
    f32 a; f32 b; f32 v;
    if (e->b439 == 1) {
        switch (e->b438) {
        case 0:
            e->b439 = 0;
            e->f428 = e->f424;
            break;
        case 3:
            v = ((f32 (*)(f32 *, f32, f32, f32, f32, f32))func_00382C58)(&e->f424 - 1, e->f428, e->f424, e->f42C, e->f430, e->f434);
            e->f428 = v;
            { f32 d = v - e->f424, r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(d)); if (r < 0.0001f) e->b439 = 0; }
            break;
        case 1:
            if (func_0038CB00(&e->h43A) != 0) e->b439 = 0;
            { f32 t = (f32)e->h43A * e->f43C; e->f428 = e->f424 + (e->f440 - e->f424) * t; }
            break;
        case 2:
            if (func_0038CB00(&e->h43A) != 0) e->b439 = 0;
            e->f428 = func_003C3BE8(e->f424, e->f440, (f32)e->h43A * e->f43C);
            break;
        }
        a = e->f428 * 0.5f;
        b = func_0038D0B0(a);
        D_002259B0[0] = b / func_0038D098(a);
        func_003873C0();
    }
}
/* localdecomp:end func_003828D8 */

LINKER_REMNANT("asm/remnants", func_00382A70);

/* localdecomp:start func_00382A80 */
void func_0038CD28(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern u8 D_00224B10[];
extern u8 D_00225450[];

void func_00382A80(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s2;

    temp_s2 = (arg0 * 0xB0) + D_00224B10;
    { S_00222500_0037E7D8 *p = &D_00222480[arg0]; func_0038CD28(temp_s2, p->f50, 0xB0); }
    temp_s1 = arg0 * 0x780;
    temp_s0 = temp_s1 + D_00225450;
    func_0038CD28(temp_s0, temp_s1 + (D_00225450 - 0x500), 0x280);
    (*(void **)((u8 *)(temp_s2) + 0x70)) = temp_s0;
}
/* localdecomp:end func_00382A80 */
TEXT_PADDING(2);

extern s32 D_001D9A80[2];
extern void (*D_001D9A40[2])(s32);
/* localdecomp:start func_00382B20 */
extern s32 D_001D9A80_00382B20[1];
extern void (*D_001D9A40_00382B20[1])(s32);
void func_00382B20(s32 a) {
    s32 i;
    for (i = 0; i < D_001D9A80_00382B20[a]; i++) D_001D9A40_00382B20[a * 16 + i](a);
    D_001D9A80_00382B20[a] = 0;
}
/* localdecomp:end func_00382B20 */

/* localdecomp:start func_00382BC8 */
/* PAL candidate for func_00382BC8 (frontbin, 0x382BC8). Plain C only. */

f32 func_00382BC8(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f13;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f13 = fparg1 - fparg0;
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f13) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if ((var_f16 != 0.0f) && ((var_f16 < temp_f1_2) || (var_f16 = -var_f16, (temp_f1_2 < var_f16)))) {
        *arg0 = var_f16;
    }
    temp_f0 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f13) : "f"(temp_f13));
    if ((var_f13 < temp_f0) || (var_f13 = -var_f13, (temp_f0 < var_f13))) {
        *arg0 = var_f13;
    }
    return fparg0 + *arg0;
}
/* localdecomp:end func_00382BC8 */

/* localdecomp:start func_00382C58 */
extern void func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
void func_00382C58(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f0;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f0 = func_0038DB00(fparg1, fparg0);
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f0) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if (var_f16 != 0.0f) {
        if (var_f16 < temp_f1_2) {
            *arg0 = var_f16;
        } else {
            f32 n = -var_f16;
            if (temp_f1_2 < n) {
                *arg0 = n;
            }
        }
    }
    temp_f1_3 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f0) : "f"(temp_f0));
    if ((var_f0 < temp_f1_3) || (var_f0 = -var_f0, (temp_f1_3 < var_f0))) {
        *arg0 = var_f0;
    }
    func_0038DAB8(fparg0, *arg0);
}
/* localdecomp:end func_00382C58 */

LINKER_REMNANT("asm/remnants", func_00382D40);

/* localdecomp:start func_00382D48 */
s32 func_00381D78(void *, s32, s32, s32);           /* extern */
extern void func_003C2880(s32 p);
extern u8 D_002224E0[];

void func_00382D48(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a2;
    void *temp_s0;

    temp_a2 = arg0 * 0x460;
    temp_s0 = temp_a2 + D_002224E0;
    if ((*(s16 *)((u8 *)(arg1) + 0x86)) == 0) {
        if ((*(s32 *)((u8 *)(temp_s0) + 0xC4)) == 0) {
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = func_00381D78(temp_a2 + (D_002224E0 - 0x60), arg0, temp_a2, arg0);
        }
    } else {
        temp_a0 = (*(s32 *)((u8 *)(temp_s0) + 0xC4));
        if (temp_a0 != 0) {
            func_003C2880(temp_a0);
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = 0;
        }
    }
}
/* localdecomp:end func_00382D48 */
TEXT_PADDING(2);

/* localdecomp:start func_00382DC8 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_00380F80[];
void func_00382DC8(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_00380F80[*(s16 *)(p + 0x8C)].c;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_00382DC8 */

typedef int u128_37EB68 __attribute__((mode(TI)));
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68;
extern E_37EB68 D_00222480_00382E10[];
extern u8 *D_001D9A84;
extern u8 D_002251D0[];
INCLUDE_ASM("asm/nonmatchings/text", func_00382E10);

typedef struct { u8 p0[0xC]; s32 fC; u8 p10[0x24 - 0x10]; s32 f24; } T_37EE80;
typedef struct { u8 p0[0x1C]; T_37EE80 *f1C; } R_37EE80;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0x5E0 - 0x5D4]; s32 f5E0; u8 p5E4[0x690 - 0x5E4]; s32 f690; u8 p694[0x6A0 - 0x694]; s32 f6A0; u8 p6A4[0x25CC - 0x6A4]; s32 f25CC; } A_37EE80;
typedef struct { u8 p0[0x24C]; s32 f24C; u8 p250[0x460 - 0x250]; } E_37EE80;
extern u8 *D_001D9A84_00383128;
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } G2_37EE80;
extern G2_37EE80 *D_001D9E50;
extern A_37EE80 D_001A4BE0_00383128;
extern E_37EE80 D_00222480_00383128[];
extern u8 D_002225D0[];
extern s32 func_00382380(void *, s32, s32);
/* localdecomp:start func_00383128 */
s32 func_00383128(s32 idx, u8 *o, u8 *t) {
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
        T_37EE80 *e = ((R_37EE80 *)(D_001D9A84_00383128 + *(s16 *)(o + 0x84) * 32))->f1C;
        if (t != 0 && *(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        { u8 *p = D_002225D0 + idx * 0x460; if (func_00382380(p + 0x40, e->fC, 0) != 0) return 1; }
        break;
    }
    case 7: {
        s32 h = *(s16 *)(o + 0x86);
        T_37EE80 *e;
        s32 a5, a7, k;
        if (h != ((E_37EE80 *)(idx * 0x460 + (s32)D_00222480_00383128))->f24C) break;

        if (*(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        if (h != 3) return 1;
        e = ((R_37EE80 *)((s32)D_001D9A84_00383128 + (*(s16 *)(o + 0x84) << 5)))->f1C;
        if (D_001A4BE0_00383128.f25CC == 0x1A) {
            a5 = D_001A4BE0_00383128.f690;
            a7 = D_001A4BE0_00383128.f6A0;
        } else {
            a5 = D_001A4BE0_00383128.f5D0;
            a7 = D_001A4BE0_00383128.f5E0;
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
/* localdecomp:end func_00383128 */

/* localdecomp:start func_00383338 */
extern S_37D000 D_00380F80[];
void func_00383338(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_00380F80[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_00383338 */

extern u8 D_00222A10_00383380[];
extern u8 D_001D9B10_00383380[8];
extern s32 func_00383128(s32, u8 *, u8 *);
extern void func_00382E10(u8 *, s32);
extern void func_00382B20(s32);
/* localdecomp:start func_00383380 */
s32 func_00383380(s32 a) {
    s32 found = 0;
    s32 i;
    u8 *cur = (u8 *)((S_00222500_0037E7D8 *)(a * 0x460 + (s32)D_00222480))->f50;
    u8 *p;
    u8 *q;
    void (*f)(u8 *);
    f32 *src;
    f32 *dst;
    func_00383338(cur);
    p = (u8 *)(a * 0x2100 + (s32)D_00222A10_00383380);
    q = (u8 *)(a * 0x30 + (s32)D_001D9B10_00383380);
    for (i = 0; i < 48; i++) {
        if (*q != 0 && p != cur && func_00383128(a, p, cur) != 0) {
            cur = p;
            found = 1;
        }
        p += 0xB0;
        q++;
    }
    if (found != 0) {
        func_00382E10(cur, 0);
    }
    f = (void (*)(u8 *))D_00380F80[*(s16 *)(cur + 0x8C)].d;
    func_00382D48(a, cur);
    if (f != 0) {
        f(cur);
    }
    src = (f32 *)(cur + 0x30);
    dst = (f32 *)(cur + 0x64);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    func_00382B20(a);
    return -1;
}
/* localdecomp:end func_00383380 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F228;
typedef int Q_37F228 __attribute__((mode(TI)));
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(s32 a, s32 b, f32 x);
/* localdecomp:start func_003834D0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003834D0;
void func_003834D0(f32 *out, V_003834D0 *a, V_003834D0 *b, V_003834D0 *c, V_003834D0 *d4, V_003834D0 *n) {
    V_003834D0 d, p, e, w, r;
    f32 t, l, ang, h;
    vec_sub_ba(&d, a, b);
    t = func_0038CE68(&d, n);
    func_0038CF68((s32)&p, (s32)n, t);
    vec_sub_ab(&e, &d, &p);
    t = func_0038CE68(c, &e);
    l = func_0038CEA8(&e);
    if (l == 0.0f) l = 0.0001f;
    h = 1.5707964f;
    ang = h - func_0038D0C8(t / l);
    func_0038CF68((s32)&w, (s32)&e, 1.0f);
    if (func_0038CE68(d4, &w) < 0.0f) ang = -ang;
    out[0] = ang;
    func_0038D890(&r, c, n, ang);
    t = func_0038CE68(&r, &d);
    l = func_0038CEA8(&d);
    if (l == 0.0f) l = 0.0001f;
    h = h - func_0038D0C8(t / l);
    func_0038CF68((s32)&w, (s32)&d, 1.0f);
    ang = -h;
    if (func_0038CE68(n, &w) < 0.0f) ang = h;
    out[1] = ang;
    out[2] = func_0038CEA8(&d);
}
/* localdecomp:end func_003834D0 */

/* localdecomp:start func_003836C8 */
typedef int u128_37F420 __attribute__((mode(TI)));
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern void func_003834D0();
extern u8 D_00222480_003836C8[];
void func_003836C8(s32 idx) {
    u128_37F420 v[3];
    u8 *p = D_00222480_003836C8 + idx * 0x460;
    u8 *q = p + 0x150;
    func_0038CF68((s32)&v[0], *(s32 *)(q + 0xF0) + 0xC0, 1.0f);
    func_0038CF68((s32)&v[1], *(s32 *)(q + 0xF0) + 0xD0, 1.0f);
    func_0038CF68((s32)&v[2], *(s32 *)(q + 0xF0) + 0xE0, 1.0f);
    *(u128_37F420 *)(p + 0x330) = v[0];
    *(u128_37F420 *)(p + 0x340) = v[2];
    func_003834D0(p + 0x310, p + 0x360, p + 0x190, &v[0], &v[1], &v[2]);
    *(u128_37F420 *)(p + 0x350) = *(u128_37F420 *)(p + 0x370);
}
/* localdecomp:end func_003836C8 */

/* localdecomp:start func_003837A0 */
typedef int u128_37F4F8 __attribute__((mode(TI)));
typedef struct { u8 p0[2]; u8 b2; u8 b3; u8 p4[0x50 - 4]; u128_37F4F8 q50; u128_37F4F8 q60; u8 p70[0xC0 - 0x70]; u128_37F4F8 qC0; u128_37F4F8 qD0; u8 pE0[0x460 - 0xE0]; } E_37F4F8;
extern E_37F4F8 D_00222720_003837A0[];
void func_003837A0(s32 idx) {
    s32 off = idx * 0x460;
    E_37F4F8 *e = (E_37F4F8 *)((u8 *)D_00222720_003837A0 + off);
    u8 *b;
    if (e->b2 == 0) {
        e->qC0 = e->q50;
        if (e->b3 == 2) {
            b = (u8 *)D_00222720_003837A0 - 0xE0;
            __asm__ __volatile__("lqc2 $vf2, 0xC0(%0)" : : "r"(e));
            __asm__ __volatile__("lqc2 $vf1, 0(%0)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0xC0(%1)" : : "r"((u8 *)(off + (s32)b)), "r"(e) : "memory");
        }
        e->qD0 = e->q60;
    }
}
/* localdecomp:end func_003837A0 */

/* localdecomp:start func_003837F8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00222720[];
void func_003837F8(s32 arg0) {
    u8 *p = D_00222720 + arg0 * 0x460;
    if (p[2] != 0) {
        *(u128_t *)(p + 0x50) = *(u128_t *)(p + 0xC0);
        *(u128_t *)(p + 0x60) = *(u128_t *)(p + 0xD0);
    }
}
/* localdecomp:end func_003837F8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00383830);

INCLUDE_ASM("asm/nonmatchings/text", func_00383A68);

typedef struct { f32 f0, f4, f8, fC, f10, f14, f18, f1C; } A_37F588;
typedef struct { s32 p0[3]; s32 fC; f32 f10; s32 f14; } R_37F588;
typedef struct {
    s16 f0; u8 b2; u8 b3; u8 p4[0xC]; A_37F588 a; u128_t q30; u128_t q40; u128_t q50; u128_t q60; R_37F588 r;
} E_37F588;
extern u8 D_00222480_0037F588[];
extern void func_003C47E8();
typedef int Q_37F7A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F7A8;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_37F7A8 v20; V_37F7A8 v30; u128_t q40; u8 m50[0x40]; } B_37F7A8;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_37F7A8;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_37F7A8 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_37F7A8;
extern E_37F7A8 D_00222480_0037F7A8[];
extern void func_003C47E8(void *, void *);
extern void func_0038D590(void *, void *);
extern void func_0038D6C8_0037F7A8(void *, void *, void *, f32);
extern void func_0038D830_0037F7A8(void *, void *);
extern f32 func_003C3BE8(f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_00383C48);

extern u8 D_00222720[];
extern u8 D_00222480_003841B8[];
extern s32 func_00383C48();
INCLUDE_ASM("asm/nonmatchings/text", func_003841B8);

INCLUDE_ASM("asm/nonmatchings/text", func_00384260);

typedef struct { u8 p0[0x86]; s16 h86; } P_37FF90;
typedef struct { u8 p0[0x50]; P_37FF90 *p50; u8 p54[0x380 - 0x54]; u8 v380[0x20]; u8 v3A0[0x460 - 0x3A0]; } E_37FF90;
typedef struct { f32 f0, f4; s32 f8, fC; } A_37FF90;
extern E_37FF90 D_00222480_0037FF90[];
extern f32 D_001D57B4;
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C4CE8_0037FF90(void *, void *, f32);
extern void func_0038D810_0037FF90(void *, void *);
extern void func_0038D5F0_0037FF90(void *, void *, void *);
typedef int Q_3801C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3801C0;
typedef union { V_3801C0 v; u128_t q; f32 f[4]; } U_3801C0;
typedef struct { u8 p0[0x86]; s16 h86; } P_3801C0;
typedef struct {
    f32 f0, f4, f8, fC;
    f32 f10[4];
    U_3801C0 u20;
    u128_t q30;
    u128_t q40;
    U_3801C0 u50;
    U_3801C0 u60;
    V_3801C0 v70;
    V_3801C0 v80;
    u128_t q90;
    f32 fA0, fA4, fA8;
    f32 fAC[5];
    u8 pC0[0x30];
} B_3801C0;
typedef struct {
    u8 p0[0x40];
    U_3801C0 u40;
    u8 p50[8];
    f32 f58;
    u8 p5C[0x24];
    V_3801C0 v80;
    u8 p90[0x6C];
    s32 iFC;
    s32 i100;
    u8 p104[0x460 - 0x150 - 0x104];
} A_3801C0;
typedef struct {
    u8 p0[0x50];
    P_3801C0 *f50;
    u8 p54[0xC];
    B_3801C0 b;
    A_3801C0 a;
} E_3801C0;
extern f32 D_001D57B8, D_001D57BC, D_001D57C4;
extern E_3801C0 D_00222480_00384498[];
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_00384498);

typedef struct { f32 x, y, z, w; } V_3804A0;
typedef union { u128_t q; V_3804A0 v; } Q_3804A0;
typedef struct { Q_3804A0 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0;
extern E_3804A0 D_00222480_00384778[];
extern s32 D_001D5B94;
extern u128_t D_00227660[];
extern s32 func_003D3CB0();
extern s32 func_003D5630(void);
extern f32 func_003C3EC8_00384778(void *, s32);
/* localdecomp:start func_00384778 */
typedef struct { f32 x, y, z, w; } V_3804A0_00384778;
typedef union { u128_t q; V_3804A0_00384778 v; } Q_3804A0_00384778;
typedef struct { Q_3804A0_00384778 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0_00384778;
extern E_3804A0_00384778 D_00222480_00384778_00384778[];
extern s32 D_001D5B94_00384778;
extern u128_t D_00227660_00384778[];
extern s32 func_003D3CB0_00384778();
extern s32 func_003D5630_00384778(void);
extern f32 func_003C3EC8_00384778_00384778(void *, s32);
void func_00384778(s32 idx) {
    E_3804A0_00384778 *e = &D_00222480_00384778_00384778[idx];
    Q_3804A0_00384778 a, b;
    s32 i;
    if (*(s16 *)(e->f50 + 0x86) == 6 || D_001D5B94_00384778 != 0) {
        e->f450 = 0;
        return;
    }
    a.q = e->q0.q;
    b.q = e->q0.q;
    b.v.z -= 0.75f;
    a.v.z += 0.75f;
    i = 0;
    while (i < 6 && func_003D3CB0_00384778(&a, &b, 0x12, 0, 0)) {
        if (func_003D5630_00384778() == 0) {
            f32 r = func_003C3EC8_00384778_00384778(D_00227660_00384778, 0);
            if (D_00222480_00384778_00384778[idx].q0.v.z < r + 0.04f) {
                D_00222480_00384778_00384778[idx].f450 = 1;
            } else {
                D_00222480_00384778_00384778[idx].f450 = 0;
            }
            return;
        }
        i++;
        a.q = D_00227660_00384778[0];
        a.v.z -= 0.01f;
    }
}
/* localdecomp:end func_00384778 */

typedef struct { u8 p0[8]; f32 f8; u8 pC[0x460 - 0xC]; } E_00380600;
typedef struct { u8 p0[0x40]; f32 f40, f44; u8 p48[0x100 - 0x48]; s32 f100, f104; u8 p108[0x118 - 0x108]; f32 f118; u8 p11C[0x12E - 0x11C]; u8 b12E, b12F, b130, b131, b132; } R_00380600;
typedef struct { u8 p0[0xC0]; s32 fC0; } Q_00380600;
extern E_00380600 D_00222480_003848D8[];
extern s32 D_001D9A90_003848D8[2];
extern s32 D_001D9A98_003848D8[2];
extern s32 D_001D9AA0_003848D8[2];
/* localdecomp:start func_003848D8 */
extern s32 D_001D545C;
void func_003848D8(s32 a) {
    E_00380600 *e = (E_00380600 *)(a * 0x460 + (s32)D_00222480_003848D8);
    R_00380600 *r = (R_00380600 *)((u8 *)e + 0x150);
    Q_00380600 *q = (Q_00380600 *)((u8 *)e + 0x60);
    s32 v;
    s32 *t = &D_001D9A98_003848D8[a];

    *t = 0x14;
    if ((u32)(r->f104 - 0x11) < 2 || r->f100 == 0x75) {
        *t = 0x34;
    }
    if (r->f104 != 0x11 && r->f118 < e->f8) {
        D_001D9A98_003848D8[a] = 0x14;
    }
    if (D_001D545C == 6) {
        if (r->f40 > 485.7f && r->f40 < 570.7f) {
            if (r->f44 > 250.0f && r->f44 < 334.5f) {
                D_001D9A98_003848D8[a] = 0x34;
            }
        }
    }
    v = D_001D9A98_003848D8[a];
    D_001D9A98_003848D8[a] = v | 0x80;
    D_001D9AA0_003848D8[a] = v;
    D_001D9A90_003848D8[a] = 0xB4;
    if (r->b12E != 0) {
        q->fC0 = 0x100;
        D_001D9A90_003848D8[a] = 0x100 | 0xB4;
    } else if (r->b12F != 0) {
        q->fC0 = 0xB00;
        D_001D9A90_003848D8[a] = 0xB00 | 0xB4;
    } else if (r->b130 != 0) {
        q->fC0 = 0x300;
        D_001D9A90_003848D8[a] = 0x300 | 0xB4;
    } else if (r->b131 != 0) {
        q->fC0 = 0xD00;
        D_001D9A90_003848D8[a] = 0xD00 | 0xB4;
    } else if (r->b132 != 0) {
        D_001D9A90_003848D8[a] = 0xB4;
        q->fC0 = 0;
    } else {
        D_001D9A90_003848D8[a] = q->fC0 | 0xB4;
    }
}
/* localdecomp:end func_003848D8 */
TEXT_PADDING(2);

/* localdecomp:start func_00384AC8 */
extern f32 D_001D9BD0_00384AC8; __asm__(".extern D_001D9BD0_00384AC8, 16");
typedef struct { u8 pad[0xC8]; f32 fC8; f32 fCC; u8 fD0[0x460 - 0xD0]; } S_3807F0;
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CAD0(void *);
void func_00384AC8(s32 a) {
    S_3807F0 *s = (S_3807F0 *)(D_002224E0 + a * 0x460);
    if (s->fC8 != 0.0f) {
        func_003C4138(&D_001D9BD0_00384AC8 + a, s->fCC, s->fC8);
        if ((&D_001D9BD0_00384AC8)[a] == s->fCC) {
            if (func_0038CAD0(s->fD0) == 1) {
                s->fCC = 0.0f;
            }
        }
        if (s->fCC <= 0.0f && (&D_001D9BD0_00384AC8)[a] <= 0.0f) {
            s->fC8 = 0.0f;
        }
    }
}
/* localdecomp:end func_00384AC8 */
TEXT_PADDING(2);

/* localdecomp:start func_00384BB8 */
extern f32 D_001D9BD8_00384BB8; __asm__(".extern D_001D9BD8_00384BB8, 16");
typedef struct { u8 pad[0xD4]; f32 fD4; f32 fD8; f32 fDC; u8 fE0[0x460 - 0xE0]; } S_3808E0;
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CAD0(void *);
void func_00384BB8(s32 a) {
    S_3808E0 *s = (S_3808E0 *)(D_002224E0 + a * 0x460);
    if (s->fD4 != 0.0f) {
        if (s->fDC != 0.0f) {
            func_003C4138(&D_001D9BD8_00384BB8 + a, s->fDC, s->fD4);
        } else {
            func_003C4138(&D_001D9BD8_00384BB8 + a, s->fDC, s->fD8);
        }
        if ((&D_001D9BD8_00384BB8)[a] == s->fDC) {
            if (func_0038CAD0(s->fE0) == 1) {
                s->fDC = 0.0f;
            }
        }
        if (s->fDC <= 0.0f && (&D_001D9BD8_00384BB8)[a] <= 0.0f) {
            s->fD4 = 0.0f;
        }
    }
}
/* localdecomp:end func_00384BB8 */

/* localdecomp:start func_00384CC8 */
typedef struct { u128_t q0; u128_t q1; u8 pad[0x360]; f32 f380[4]; f32 f390[4]; f32 f3a0[4]; f32 f3b0[4]; f32 f3c0[4]; f32 f3d0[4]; u128_t q3e0; u8 pad2[0x70]; } E_003809F0;
extern E_003809F0 D_00222480_00384CC8[];
extern u128_t D_00222400[];
extern void func_0038CD28();
void func_00384CC8(s32 idx) {
    E_003809F0 *e = &D_00222480_00384CC8[idx];
    u128_t v;
    e->f3b0[0] = -e->f390[0];
    e->f3c0[0] = -e->f390[1];
    e->f3d0[0] = -e->f390[2];
    e->f3b0[1] = -e->f3a0[0];
    e->f3c0[1] = -e->f3a0[1];
    e->f3d0[1] = -e->f3a0[2];
    e->f3b0[2] = e->f380[0];
    e->f3c0[2] = e->f380[1];
    e->f3d0[2] = e->f380[2];
    v = e->q0;
    e->q3e0 = v;
    D_00222400[0] = v;
    D_00222400[1] = D_00222480_00384CC8[idx].q1;
    func_0038CD28(&D_00222400[2], D_00222480_00384CC8[idx].f380, 0x30);
}
/* localdecomp:end func_00384CC8 */

extern u8 D_00222480_0037F588[];
extern u8 *D_001D9B40[2];
extern s32 D_001D9B00[2];
extern s32 D_001D5B98;
extern s32 D_001D90B8;
extern s32 D_001D90B0;
extern void func_003848D8(s32);
extern void func_00384498(s32, s32);
extern void func_00383380(s32);
extern void func_003C48A8();
extern void func_00385EF0();
extern void func_003828D8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00384D88);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00385000);

typedef struct { u8 p0[0x10]; u8 pos[0x10]; u8 b20; } O_380D48;
typedef struct {
    O_380D48 *obj; s32 state; f32 f8; s32 pC;
    s16 h10[16]; s16 h30[16]; s32 c50[16]; f32 f90[16]; f32 fD0[16];
} S_380D48;
extern S_380D48 D_00222900;
extern s32 D_001D4BC8_00385020, D_001D4BCC_00385020, D_001D4BD0_00385020, D_001D4BD4_00385020;
extern f32 func_0038CF00(void *, void *);
extern void func_003860A8(f32 *, void *);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
INCLUDE_ASM("asm/nonmatchings/text", func_00385020);

typedef struct {
    u8 p0[0x10]; f32 f10; s32 f14; s32 f18; f32 f1C; u8 p20[6]; s16 h26; f32 f28; s32 f2C;
    u8 p30[8]; f32 f38; f32 f3C;
} S_3810C0;
extern void func_0038BCD8(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern long func_00389598(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
/* localdecomp:start func_00385398 */
void func_00385398(S_3810C0 *o, f32 x, f32 y) {
    long tex;
    f32 w, h, a;
    f32 p[4], q[4];
    s32 i;
    if (o == 0) return;
    w = o->f38;
    h = o->f3C;
    tex = func_00389598(o->f18);
    a = o->f1C;
    switch (o->f2C) {
    case 0:
        for (i = 0; i < o->h26; i++) {
            func_0038BCD8(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
            a = ((f32 (*)(f32, f32))func_0038DAB8)(a, o->f28);
        }
        break;
    case 1:
        p[0] = h * func_0038D0B0(a) * o->f10;
        p[1] = h * func_0038D098(a) * o->f10;
        q[0] = w * func_0038D098(a) * o->f10;
        q[1] = -w * func_0038D0B0(a) * o->f10;
        func_0038BCD8(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
        func_0038BCD8(x + q[0], y + q[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 0, 0.0f, 0.0f);
        func_0038BCD8(x - p[0], y - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 1, 0.0f, 0.0f);
        func_0038BCD8(x + q[0] - p[0], y + q[1] - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 1, 0.0f, 0.0f);
        break;
    case 2:
        func_0038BCD8(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.5f, 0.5f);
        break;
    }
}
/* localdecomp:end func_00385398 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3813E0;
typedef int Q_3813E0 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x1430];
    s32 f1430;
    u8 p1434[0x2C];
    u8 *f1460;
    f32 f1464;
    f32 f1468;
} S_3813E0;
typedef struct { f32 f0; s16 h4; u8 p6[0xA]; f32 f10; } P_3813E0;
extern S_3813E0 D_001A4BE0;
extern f32 D_001D57C8, D_001D57CC, D_001D57D0, D_001D57D4, D_001D5804, D_001D5808, D_001D5830, D_001D5834;
extern s32 D_001D57D8, D_001D57E8;
extern f32 D_001D57F8;
extern s32 D_001D580C, D_001D5810, D_001D5814, D_001D5818, D_001D581C, D_001D5820, D_001D5824, D_001D5828, D_001D582C;
extern s32 D_001D4BD0_003856B8, D_001D4BD4_003856B8;
extern P_3813E0 *func_00382348(u8 *);
extern void func_003860A8(f32 *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038BCD8(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern void func_0038C500(s32, s32, s32, s32, s32 *, s32 *, s32, s32, f32, f32);
extern long func_00389598(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003856B8);

LINKER_REMNANT("asm/remnants", func_00385D20);

/* localdecomp:start func_00385D28 */
typedef struct {
    u8 p0[0x20];
    u8 b20;
} H_381A50;

typedef struct {
    u8 p0[0x10];
    f32 f10;
    u8 p14[0xC];
    H_381A50 *f20;
    u8 b24;
    u8 b25;
    u8 p26[0xA];
    f32 f30, f34;
    u8 p38[8];
} E_381A50;

typedef struct {
    E_381A50 e[14];
    s32 n;
} T_381A50;

extern T_381A50 D_00224BC0_00385D28;
extern s32 D_001A71A4_00385D28[];
extern s32 D_001D5B98;
extern s32 D_001D4BC0_00385D28, D_001D4BC4_00385D28;
extern s32 D_001D4BD0_00385D28, D_001D4BD4_00385D28;
extern void func_003856B8(void);
extern void func_003860A8(f32 *, void *);
extern void func_00385398(S_3810C0 *, f32, f32);

void func_00385D28(s32 a) {
    f32 v[2];
    s32 i;
    E_381A50 *p;

    if (D_001A71A4_00385D28[0] == 0x74) {
        D_00224BC0_00385D28.n = 0;
        return;
    }

    func_003856B8();
    if (D_00224BC0_00385D28.n == 0) return;

    for (i = 0; i < D_00224BC0_00385D28.n; i++) {
        p = &D_00224BC0_00385D28.e[i];
        if (p->b25 != a || p->f20 == 0 ||
            p->f20->b20 == 0xFE || p->f20->b20 == 0xFD)
            continue;

        if (p->b24 != 0) {
            func_003860A8(v, p);
            v[0] = (v[0] - (f32)D_001D4BD0_00385D28) * 0.0625f;
            v[1] = (v[1] - (f32)D_001D4BD4_00385D28) * 0.0625f;
        } else {
            v[0] = (f32)D_001D4BC0_00385D28 * p->f30;
            v[1] = (f32)D_001D4BC4_00385D28 * p->f34;
        }

        if (D_001D5B98 != 0) p->f10 *= 0.75f;
        func_00385398((S_3810C0 *)p, v[0], v[1]);
    }

    if (D_001D5B98 == 0) D_00224BC0_00385D28.n = 0;
}
/* localdecomp:end func_00385D28 */

/* PAL candidate for func_00385EF0 (frontbin).
 *
 * Started from the US draft (rac3-uya-decomp func_00381C18, commit 13cf5c5). The US
 * matched it only with @ps2as; here the file's own flags must produce the retail bytes.
 *
 * Retail reaches the seven globals with `lui`/`%lo`, rematerialised at each store
 * (`lui $at, %hi(addr)` + `sb`/`swc1` `%lo(addr)($at)`): the assembler's expansion. A plain
 * sized `extern u8`/`extern f32` would give the `$gp` form and an unsized one gcc's own split,
 * so each is declared sized with an `.extern X, 16` hint (see the block).
 */

/* localdecomp:start func_00385EF0 */
typedef struct {
    u8 p0[0x50];
    s32 f50;
    s32 c0;
    s32 c1;
    f32 f5C, f60, f64, f68;
    f32 f6C, f70, f74, f78;
    u8 p7C[4];
} R_381C18;
extern R_381C18 D_002FE200[];
extern s32 func_003CCE20_00385EF0(void *, f32 *, s32 *);
/* Retail stores these through `lui $at`: the assembler's expansion of a store to a global it
   does not know to be small (SN's single-pass Ps2EeAs had not seen their sizes yet). Each is
   declared sized (gcc leaves the store to the assembler as one macro) with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). */
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
__asm__(".extern D_001D9C44, 16");
__asm__(".extern D_001D9C45, 16");
__asm__(".extern D_001D9C46, 16");
__asm__(".extern D_001D9C48, 16");
__asm__(".extern D_001D9C4C, 16");
__asm__(".extern D_001D9C50, 16");
__asm__(".extern D_001D9C54, 16");

void func_00385EF0(void *pos) {
    f32 t;
    s32 idx;
    R_381C18 *r;
    u32 w1, w0;
    s32 c0, c1;
    f32 u;
    u32 a, b;
    u32 r1, r0, g1, g0, b1, b0;
    f32 p6C, p5C, p74, p64, p70, p60, p78, p68;

    if (func_003CCE20_00385EF0(pos, &t, &idx) == 0) {
        return;
    }
    r = &D_002FE200[idx];
    if (!(r->f50 & 2)) {
        return;
    }
    w1 = (s32)(t * 255.0f);
    w0 = 255 - w1;
    u = 1.0f - t;
    c1 = r->c1;
    c0 = r->c0;
    r1 = (c1 & 0xFF) * w1;
    g1 = ((c1 >> 8) & 0xFF) * w1;
    b1 = (c1 >> 16) & 0xFF;
    r0 = (c0 & 0xFF) * w0;
    g0 = ((c0 >> 8) & 0xFF) * w0;
    b0 = (c0 >> 16) & 0xFF;
    p6C = r->f6C * t;
    p5C = r->f5C * u;
    p74 = r->f74 * t;
    p64 = r->f64 * u;
    p70 = r->f70 * t;
    p60 = r->f60 * u;
    p78 = r->f78 * t;
    p68 = r->f68 * u;
    a = (s32)(r1 + r0) >> 8;
    b = (s32)(g1 + g0) >> 8;
    D_001D9C46 = (s32)(b1 * w1 + b0 * w0) >> 8;
    D_001D9C44 = a;
    D_001D9C45 = b;
    D_001D9C48 = (p6C + p5C) * 1024.0f;
    D_001D9C4C = (p74 + p64) * 1024.0f;
    D_001D9C50 = 255.0f - (p70 + p60) * 255.0f;
    D_001D9C54 = 255.0f - (p78 + p68) * 255.0f;
}
/* localdecomp:end func_00385EF0 */

LINKER_REMNANT("asm/remnants", func_00386068);

typedef struct { u8 p0[0x140]; f32 f140, f144, f148; } S_222340_381DD0;
typedef struct { u8 p0[0x1A0]; f32 f1A0, f1A4; u8 p1A8[0x220 - 0x1A8]; f32 f220; } S_225980_381DD0;
extern S_222340_381DD0 D_002222C0_003860A8;
extern S_225980_381DD0 D_00225900_003860A8;
extern void func_0038D2A0();
extern void func_0038D640();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D028();
INCLUDE_ASM("asm/nonmatchings/text", func_003860A8);

LINKER_REMNANT("asm/remnants", func_003861E8);

typedef struct { f32 x, y, z, w; } V_381F18;
typedef union { u128_t q; V_381F18 v; } Q_381F18;
extern u8 D_002222C0_003861F0[];
extern u8 D_00225900_003861F0[];
extern u8 D_00225B80[];
extern u8 D_001D5477_003861F0;
extern void func_0038CE90();
extern void func_0038CE50_003861F0(void *, void *, f32);
/* localdecomp:start func_003861F0 */
extern R_381C18 D_002FE200_003861F0[];
extern u8 D_001D9C44_003861F0, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48_003861F0, D_001D9C4C, D_001D9C50, D_001D9C54;
extern s32 func_003CD1D8_003862D0(void *, f32 *, s32 *);
typedef struct { u8 p0[0x140]; f32 f140, f144, f148; } S_222340_381DD0_003861F0;
typedef struct { u8 p0[0x1A0]; f32 f1A0, f1A4; u8 p1A8[0x220 - 0x1A8]; f32 f220; } S_225980_381DD0_003861F0;
extern S_222340_381DD0_003861F0 D_002222C0_00386488;
extern S_225980_381DD0_003861F0 D_00225900_00386488;
extern void func_0038D680();
extern void func_0038D640_003861F0();
extern void func_0038CE20_003861F0(f32 *, void *, f32);
extern void func_0038D408();

typedef struct { f32 x, y, z, w; } V_381F18_003861F0;
typedef union { u128_t q; V_381F18_003861F0 v; } Q_381F18_003861F0;
extern u8 D_002222C0_003861F0_003861F0[];
extern u8 D_00225900_003861F0_003861F0[];
extern u8 D_00225B80_003861F0[];
extern u8 D_001D5477_003861F0_003861F0;
extern void func_0038CE90_003861F0();
extern void func_0038CE50_003861F0_003861F0(void *, void *, f32);
void func_003861F0(void) {
    Q_381F18_003861F0 r[4];
    f32 *m;
    f32 sx, sy, sz;
    u8 *s;
    if (D_001D5477_003861F0_003861F0 != 0) {
        func_0038CE90_003861F0(D_002222C0_003861F0_003861F0 + 0x170, D_002222C0_003861F0_003861F0 + 0x180, D_002222C0_003861F0_003861F0 + 0x160);
    }
    r[0].q = *(u128_t *)(D_002222C0_003861F0_003861F0 + 0x160);
    r[1].q = *(u128_t *)(D_002222C0_003861F0_003861F0 + 0x170);
    r[2].q = *(u128_t *)(D_002222C0_003861F0_003861F0 + 0x180);
    m = (f32 *)D_002222C0_003861F0_003861F0;
    m[0] = -r[1].v.x;
    m[4] = -r[1].v.y;
    m[8] = -r[1].v.z;
    m[1] = -r[2].v.x;
    m[5] = -r[2].v.y;
    m[9] = -r[2].v.z;
    m[2] = r[0].v.x;
    m[6] = r[0].v.y;
    m[10] = r[0].v.z;
    m[15] = 1.0f;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    func_0038D640_003861F0(D_002222C0_003861F0_003861F0 + 0x40, D_00225900_003861F0_003861F0 + 0xC0, m);
    func_0038D640_003861F0(D_002222C0_003861F0_003861F0 + 0x80, D_00225900_003861F0_003861F0 + 0x100, m);
    s = D_00225900_003861F0_003861F0;
    sx = *(f32 *)(s + 0x1A0);
    sy = *(f32 *)(s + 0x1A4);
    sz = *(f32 *)(s + 0x1A8);
    m[32] += m[35] * sx;
    m[33] += m[35] * sy;
    m[34] += m[35] * sz;
    m[36] += m[39] * sx;
    m[37] += m[39] * sy;
    m[38] += m[39] * sz;
    m[40] += m[43] * sx;
    m[41] += m[43] * sy;
    m[42] += m[43] * sz;
    m[44] += m[47] * sx;
    m[45] += m[47] * sy;
    m[46] += m[47] * sz;
    func_0038D640_003861F0(D_002222C0_003861F0_003861F0 + 0xC0, D_00225900_003861F0_003861F0 + 0x140, m);
    func_0038CE50_003861F0_003861F0(D_002222C0_003861F0_003861F0 + 0x100, D_00225900_003861F0_003861F0 + 0x140, *(f32 *)(s + 0x1C0));
    func_0038CE50_003861F0_003861F0(D_002222C0_003861F0_003861F0 + 0x110, D_00225900_003861F0_003861F0 + 0x150, *(f32 *)(s + 0x1C4));
    *(u128_t *)((u8 *)m + 0x120) = *(u128_t *)(s + 0x160);
    *(u128_t *)((u8 *)m + 0x130) = *(u128_t *)(s + 0x170);
    func_0038D640_003861F0(D_002222C0_003861F0_003861F0 + 0x100, D_002222C0_003861F0_003861F0 + 0x100, m);
    *(u128_t *)(D_00225B80_003861F0 + 0x00) = *(u128_t *)(D_002222C0_003861F0_003861F0 + 0x00);
    *(u128_t *)(D_00225B80_003861F0 + 0x10) = *(u128_t *)(D_002222C0_003861F0_003861F0 + 0x10);
    *(u128_t *)(D_00225B80_003861F0 + 0x20) = *(u128_t *)(D_002222C0_003861F0_003861F0 + 0x20);
    func_0038CE20_003861F0((f32 *)(D_00225B80_003861F0 + 0x30), D_002222C0_003861F0_003861F0 + 0x140, 1024.0f);
    *(f32 *)(D_00225B80_003861F0 + 0x3C) = 1024.0f;
}
/* localdecomp:end func_003861F0 */

/* localdecomp:start func_003864C0 */
typedef struct {
    u8 pad[0x450];
    s32 f450;
} E_3821E8;

typedef struct {
    u8 p0[0x228];
    f32 f228;
    f32 f22C;
    u8 p230[8];
    f32 f238;
    f32 f23C;
    u8 p240[0x10];
    s32 f250;
    s32 f254;
    s32 f258;
} S_3821E8;

extern u8 D_00222480_003864C0[];
extern S_3821E8 D_00225900;
extern u8 D_001D99AC, D_001D99AD, D_001D99AE;
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D99C4, D_001D99C8, D_001D99CC, D_001D99D0;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern s32 D_001DA5D0, D_001D9C58;
extern void func_003873C0();

void func_003864C0(s32 a) {
    s32 c;

    if (((E_3821E8 *)(a * 0x460 + (s32)D_00222480_003864C0))->f450 != 0) {
        D_00225900.f250 = D_001D99AC;
        D_00225900.f254 = D_001D99AD;
        D_00225900.f258 = D_001D99AE;
        D_00225900.f228 = D_001D99C4;
        D_00225900.f22C = D_001D99C8;
        D_00225900.f238 = D_001D99CC;
        D_00225900.f23C = D_001D99D0;
        c = 0x40000;
    } else {
        D_00225900.f250 = D_001D9C44;
        D_00225900.f254 = D_001D9C45;
        D_00225900.f258 = D_001D9C46;
        D_00225900.f228 = D_001D9C48;
        D_00225900.f22C = D_001D9C4C;
        D_00225900.f238 = D_001D9C50;
        D_00225900.f23C = D_001D9C54;
        c = 0x7D0000;
    }

    D_001DA5D0 = c;
    func_003873C0();
    D_001D9C58 = 0;
}
/* localdecomp:end func_003864C0 */

extern u8 *D_001D9D40[];
INCLUDE_ASM("asm/nonmatchings/text", func_003865A0);

/* localdecomp:start func_00386678 */
extern s32 func_003865A0();
void func_00386678(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0) {
    s32 var_4;
    s32 var_5;
    s32 var_6;

    if (fparg0 < 0.5f) {
        if (((s32 (*)())func_003865A0)() == 0) {
            var_4 = arg3;
            var_5 = arg4;
            var_6 = arg5;
            goto block_5;
        }
    } else if (((s32 (*)())func_003865A0)(arg3, arg4, arg5) == 0) {
        var_4 = arg0;
        var_5 = arg1;
        var_6 = arg2;
block_5:
        ((s32 (*)())func_003865A0)(var_4, var_5, var_6);
    }
}
/* localdecomp:end func_00386678 */

typedef struct { u8 pad[0x140]; f32 x, y, z; } S_382458;
typedef struct { f32 x, y, z, w; u8 d[1][0x80]; } G_382458;
extern S_382458 D_002222C0;
extern G_382458 *D_001D9D44, *D_001D9D48, *D_001D9D4C;
extern u8 *D_001D9D60[2];
extern s32 D_001D9D58;
extern s32 D_001D9D50_00386730;
extern s32 D_001D52F0;
extern u8 D_00227500[];
extern s32 D_00227480[];
extern void func_0038CB78();
extern void func_0038CBA0();
extern void func_0038CD50();
extern f32 func_0038CF38();
extern f32 func_0038D160(f32, f32);
/* localdecomp:start func_00386730 */
extern void func_00386678(s32, s32, s32, s32, s32, s32, f32);

s32 func_00386730(void) {
    f32 v[4];
    f32 d[4];
    s32 x = D_002222C0.x * 0.25f;
    s32 y = D_002222C0.y * 0.25f;
    s32 z = D_002222C0.z * 0.25f;
    u8 *r = (u8 *)func_003865A0(x, y, z);
    if (r != 0) {
        D_001D9D58 = 0;
        func_0038CD28(D_00227480, r, 0x80);
        D_001D9D60[D_001D52F0] = r;
    } else {
        D_001D9D58 = 1;
        if (D_001D9D50_00386730 == 0) {
            s32 a = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_00386678)(x - 1, y, z, x + 1, y, z, D_002222C0.x * 0.25f - x);
            s32 b = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_00386678)(x, y - 1, z, x, y + 1, z, D_002222C0.y * 0.25f - y);
            s32 c = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_00386678)(x, y, z - 1, x, y, z + 1, D_002222C0.z * 0.25f - z);
            if (a != 0 || b != 0 || c != 0) {
                func_0038CBA0(D_00227500, 0x80);
                if (a != 0) func_0038CD50(D_00227500, D_00227500, a, 0x80);
                if (b != 0) func_0038CD50(D_00227500, D_00227500, b, 0x80);
                if (c != 0) func_0038CD50(D_00227500, D_00227500, c, 0x80);
                r = D_00227500;
                D_001D9D60[D_001D52F0] = r;
                func_0038CD28(D_00227480, r, 0x80);
            }
        }
        if (r == 0) {
            switch (D_001D9D50_00386730) {
            case 2:
                if (D_001D9D44 != 0) {
                    G_382458 *p = D_001D9D44;
                    s32 a = D_002222C0.x - p->x > 0.0f;
                    s32 b = D_002222C0.y - p->y > 0.0f;
                    s32 c = D_002222C0.z - p->z > 0.0f;
                    func_0038CD28(D_00227480, p->d[c + b * 2 + a * 4], 0x80);
                    break;
                }
                goto case0;
            case 3:
                if (D_001D9D48 != 0) {
                    s32 idx = 0;
                    v[0] = D_001D9D48->x;
                    v[1] = D_001D9D48->y;
                    v[2] = D_001D9D48->z;
                    v[3] = 0.0f;
                    d[0] = D_002222C0.x - v[0];
                    d[1] = D_002222C0.y - v[1];
                    d[2] = D_002222C0.z - v[2];
                    d[3] = 0.0f;
                    if (d[0] > 0.0f && d[1] > 0.0f) {
                        idx = (s32)(func_0038D160(d[0], d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = func_0038CF38(&D_002222C0.x, v);
                    } else if (d[0] <= 0.0f && d[1] > 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D160(d[1], 0.0f - d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = func_0038CF38(D_00222400, v);
                        }
                    } else if (d[0] < 0.0f && d[1] < 0.0f) {
                        idx = (s32)(func_0038D160(0.0f - d[0], 0.0f - d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = 0.0f - func_0038CF38(D_00222400, v);
                    } else if (d[0] >= 0.0f && d[1] < 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D160(0.0f - d[1], d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = 0.0f - func_0038CF38(D_00222400, v);
                        }
                    }
                    if (d[2] > 0.0f && d[0] > 0.0f) {
                        idx += (s32)(func_0038D160(d[2], d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] <= 0.0f && d[0] > 0.0f) {
                        idx += 0x10;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D160(d[0], 0.0f - d[2]) * 32.0f / 3.1415927f);
                    } else if (d[2] < 0.0f && d[0] <= 0.0f) {
                        idx += 0x20;
                        if (d[0] != 0.0f) idx += (s32)(func_0038D160(0.0f - d[2], 0.0f - d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] >= 0.0f && d[0] < 0.0f) {
                        idx += 0x30;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D160(0.0f - d[0], d[2]) * 32.0f / 3.1415927f);
                    }
                    func_0038CD28(D_00227480, D_001D9D48->d[idx], 0x80);
                    break;
                }
            case0:
            case 0:
                if (D_001D9D60[D_001D52F0] != 0) {
                    func_0038CD28(D_00227480, D_001D9D60[D_001D52F0], 0x80);
                    break;
                }
            case 1:
                func_0038CB78(D_00227480, -1, 0x80);
                break;
            case 4:
                if (D_001D9D4C != 0) {
                    s32 idx = 0;
                    v[0] = D_001D9D4C->x;
                    v[1] = D_001D9D4C->y;
                    v[2] = D_001D9D4C->z;
                    v[3] = 0.0f;
                    d[0] = D_002222C0.x - v[0];
                    d[1] = D_002222C0.y - v[1];
                    d[2] = D_002222C0.z - v[2];
                    d[3] = 0.0f;
                    if (d[0] > 0.0f && d[1] > 0.0f) {
                        idx = (s32)(func_0038D160(d[0], d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = func_0038CF38(&D_002222C0.x, v);
                    } else if (d[0] <= 0.0f && d[1] > 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D160(d[1], 0.0f - d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = func_0038CF38(D_00222400, v);
                        }
                    } else if (d[0] < 0.0f && d[1] < 0.0f) {
                        idx = (s32)(func_0038D160(0.0f - d[0], 0.0f - d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = 0.0f - func_0038CF38(D_00222400, v);
                    } else if (d[0] >= 0.0f && d[1] < 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_0038D160(0.0f - d[1], d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = 0.0f - func_0038CF38(D_00222400, v);
                        }
                    }
                    if (d[2] > 0.0f && d[0] > 0.0f) {
                        idx += (s32)(func_0038D160(d[2], d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] <= 0.0f && d[0] > 0.0f) {
                        idx += 0x10;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D160(d[0], 0.0f - d[2]) * 32.0f / 3.1415927f);
                    } else if (d[2] < 0.0f && d[0] <= 0.0f) {
                        idx += 0x20;
                        if (d[0] != 0.0f) idx += (s32)(func_0038D160(0.0f - d[2], 0.0f - d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] >= 0.0f && d[0] < 0.0f) {
                        idx += 0x30;
                        if (d[2] != 0.0f) idx += (s32)(func_0038D160(0.0f - d[0], d[2]) * 32.0f / 3.1415927f);
                    }
                    func_0038CD28(D_00227480, D_001D9D4C->d[idx], 0x80);
                } else if (D_001D9D60[D_001D52F0] != 0) {
                    func_0038CD28(D_00227480, D_001D9D60[D_001D52F0], 0x80);
                } else {
                    func_0038CB78(D_00227480, -1, 0x80);
                }
                break;
            }
        }
    }
    {
        u8 *q = (u8 *)D_00227480;
        q[0x7F] |= 0x80;
    }
}
/* localdecomp:end func_00386730 */

extern s32 func_00386730();
extern void func_0038CB78();
extern s32 D_001D9D54;
extern s32 D_00227480[];
/* localdecomp:start func_00387218 */
__asm__(".extern D_001D9D54, 16");
extern s32 D_001D9D54;
extern s32 D_00227480[];

extern void func_0038CB78(void *, s32, s32);
extern s32 func_00386730(void);

void func_00387218(void)
{
    if (D_001D9D54 == 0) {
        func_0038CB78(D_00227480, -1, 0x80);
    } else if (D_001D9D54 == 2) {
        func_00386730();
    }
}
/* localdecomp:end func_00387218 */


/* localdecomp:start func_00387268 */
typedef struct {
    u8 p0[0x150];
    u16 f150, f152;
} C_00382F90;

extern C_00382F90 D_001CFEC0_00387268;

typedef struct {
    u8 p0[0xA0]; f32 fA0; f32 fA4; u8 pA8[8]; f32 fB0;
    u8 pB4[0x1A0 - 0xB4]; f32 f1A0; f32 f1A4;
    u8 p1A8[0x210 - 0x1A8]; f32 f210; f32 f214; f32 f218; f32 f21C;
    u8 p220[8]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C;
    s32 f240; s32 f244; s32 f248; s32 f24C; u8 p250[0x18]; s32 f268;
} S_00382F90;

extern S_00382F90 D_00225900_00387268;
extern s32 D_001D4BC0_00387268, D_001D4BC4_00387268;
extern s32 D_001D4BC8_00387268, D_001D4BCC_00387268;
extern s32 D_001D4BD0_00387268, D_001D4BD4_00387268;
extern s32 D_001D4BD8_00387268, D_001D4BDC_00387268;

void func_00387268(void) {
    D_001D4BC0_00387268 = (s16)D_001CFEC0_00387268.f150;
    D_001D4BC4_00387268 = (s16)D_001CFEC0_00387268.f152;
    D_001D4BC8_00387268 = D_001D4BC0_00387268 >> 1;
    D_001D4BCC_00387268 = D_001D4BC4_00387268 >> 1;
    D_001D4BD0_00387268 = (0x800 - D_001D4BC8_00387268) << 4;
    D_001D4BD4_00387268 = (0x800 - D_001D4BCC_00387268) << 4;
    D_001D4BD8_00387268 = (D_001D4BC8_00387268 + 0x800) << 4;
    D_001D4BDC_00387268 = (D_001D4BCC_00387268 + 0x800) << 4;
    D_00225900_00387268.fA0 = 32.0f;
    D_00225900_00387268.fA4 = 1048576.0f;
    D_00225900_00387268.fB0 = 0.62f;
    D_00225900_00387268.f210 = (f32)D_001D4BC0_00387268 * 0.5f;
    D_00225900_00387268.f214 = (f32)D_001D4BC4_00387268 * 0.5f;
    D_00225900_00387268.f1A0 = 2048.0f;
    D_00225900_00387268.f1A4 = 2048.0f;
    D_00225900_00387268.f218 = D_00225900_00387268.f210 * 4.0f;
    D_00225900_00387268.f21C = D_00225900_00387268.f214 * 4.0f;
    D_00225900_00387268.f22C = 524288.0f;
    D_00225900_00387268.f238 = 255.0f;
    D_00225900_00387268.f244 = D_001D4BC0_00387268 - 1;
    D_00225900_00387268.f24C = D_001D4BC4_00387268 - 1;
    D_00225900_00387268.f228 = 0.0f;
    D_00225900_00387268.f23C = 0.0f;
    D_00225900_00387268.f240 = 0;
    D_00225900_00387268.f248 = 0;
    D_00225900_00387268.f268 = 0;
}
/* localdecomp:end func_00387268 */

INCLUDE_ASM("asm/nonmatchings/text", func_003873C0);

INCLUDE_ASM("asm/nonmatchings/text", func_00387B18);

LINKER_REMNANT("asm/remnants", func_00387EE8);

/* PAL: func_00387EF0 zeroes a set of globals.  Retail reaches the twelve
   word-sized ones through lui $at, %hi(X) + sw $zero, %lo(X)($at), the
   assembler's expansion of a store to a global it does not know to be small;
   an unsized symbol would be split by gcc itself into lui $reg / sw %lo($reg)
   with a register of its own, so they are declared sized with an `.extern X, 16` hint (see the block).  The three bytes and the last word are
   small data and go through $gp. */

extern u8 D_001D5884, D_001D58C0, D_001D58D0;
extern s32 D_001D99A8;

/* localdecomp:start func_00387EF0 */
extern u8 D_001D5884, D_001D58C0, D_001D58D0;
extern s32 D_001D99A8;
/* Stored through `lui $at` in retail, as in func_00385EF0: declared sized, then with a section
   attribute that keeps gcc's `.extern` size hint out of the assembly. */
extern s32 D_001D9C08, D_001D9C10, D_001D9C14, D_001D9C0C, D_001D9C38, D_001D9C40;
extern s32 D_001D9BDC, D_001D9BE0, D_001D9D50, D_001D99D4, D_001D99D8, D_001D99C0;
__asm__(".extern D_001D5884, 1");
__asm__(".extern D_001D58C0, 1");
__asm__(".extern D_001D58D0, 1");
__asm__(".extern D_001D9C08, 16");
__asm__(".extern D_001D9C10, 16");
__asm__(".extern D_001D9C14, 16");
__asm__(".extern D_001D9C0C, 16");
__asm__(".extern D_001D9C38, 16");
__asm__(".extern D_001D9C40, 16");
__asm__(".extern D_001D9BDC, 16");
__asm__(".extern D_001D9BE0, 16");
__asm__(".extern D_001D9D50, 16");
__asm__(".extern D_001D99D4, 16");
__asm__(".extern D_001D99D8, 16");
__asm__(".extern D_001D99C0, 16");
void func_00387EF0(void) {
    D_001D9C08 = 0;
    D_001D9C10 = 0;
    D_001D9C14 = 0;
    D_001D9C0C = 0;
    D_001D9C38 = 0;
    D_001D9C40 = 0;
    D_001D9BDC = 0;
    D_001D9BE0 = 0;
    D_001D5884 = 0;
    D_001D58C0 = 0;
    D_001D58D0 = 0;
    D_001D9D50 = 0;
    D_001D99D4 = 0;
    D_001D99D8 = 0;
    D_001D99C0 = 0;
    D_001D99A8 = 0;
}
/* localdecomp:end func_00387EF0 */

/* localdecomp:start func_00387F68 */
extern u32 *D_001DA050_00387F68;
__asm__(".extern D_001DA050_g, 4");
extern u32 *D_001DA050_g;
extern u8 D_001421B0[];
extern u8 D_00142120[];
extern long D_001D5330_00387F68[];
typedef struct { u8 p0[0x240]; s32 f240, f244, f248, f24C, f250, f254, f258; } S_225980_3838C0;
extern S_225980_3838C0 D_00225900_00387F68;
extern void func_0038CC88();
extern void func_003A9440(s32, unsigned long);
void func_00387F68(void) {
    D_001DA050_00387F68[0] = 0x30000013;
    D_001DA050_00387F68[1] = (u32)D_001421B0;
    D_001DA050_00387F68[2] = 0;
    D_001DA050_00387F68[3] = 0x50000013;
    D_001DA050_00387F68 += 4;
    D_001DA050_00387F68[0] = 0x30000009;
    D_001DA050_00387F68[1] = (u32)D_00142120;
    D_001DA050_00387F68[2] = 0;
    D_001DA050_00387F68[3] = 0x50000009;
    D_001DA050_00387F68 += 4;
    D_001DA050_00387F68[0] = 0x10000003;
    D_001DA050_00387F68[1] = 0;
    D_001DA050_00387F68[2] = 0;
    D_001DA050_00387F68[3] = 0x50000003;
    D_001D5330_00387F68[2] = (long)D_00225900_00387F68.f240 | ((long)D_00225900_00387F68.f244 << 16) | ((long)D_00225900_00387F68.f248 << 32) | ((long)D_00225900_00387F68.f24C << 48);
    D_001DA050_00387F68 += 4;
    D_001D5330_00387F68[4] = (long)D_00225900_00387F68.f240 | ((long)D_00225900_00387F68.f244 << 16) | ((long)D_00225900_00387F68.f248 << 32) | ((long)D_00225900_00387F68.f24C << 48);
    func_0038CC88(D_001DA050_00387F68, D_001D5330_00387F68, 0x30);
    D_001DA050_g = (u32 *)((u8 *)D_001DA050_00387F68 + 0x30);
    func_003A9440(0x3D, (long)D_00225900_00387F68.f250 | ((long)D_00225900_00387F68.f254 << 8) | ((long)D_00225900_00387F68.f258 << 16));
    func_003A9440(0x51, 0);
}
/* localdecomp:end func_00387F68 */


/* localdecomp:start func_00388138 */
extern unsigned long D_001CFEC8[];
void func_00388138(void) {
    *(volatile unsigned long *)0x120000E0 = 0;
    *(volatile unsigned long *)0x12000000 = 0xFFA1;
    *(volatile unsigned long *)0x12000020 = D_001CFEC8[0];
    *(volatile unsigned long *)0x12000070 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000090 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000080 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000A0 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000D0 = 0;
}
/* localdecomp:end func_00388138 */

extern void func_00392440(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_00392868(s32, s32);
/* localdecomp:start func_003881B0 */
extern void func_00392440(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_00392868(s32, s32);
void func_003881B0(s32 a0, s32 a1) {
    s32 n = a0 + a1;
    if (n > 16) {
        n = 16;
    }
    func_00392440(a0, a1, ((0x3FF000 - (4 << n)) >> 13) << 13, 1);
    func_003A9440(0x47, 0x30000);
    func_003A9440(0x42, 0x8000000044UL);
    func_00392868(0x100, 0x100);
    func_003A9440(0x42, 0x8000000044UL);
}
/* localdecomp:end func_003881B0 */

/* localdecomp:start func_00388238 */
extern void func_003922B8(void);
void func_00388238(void) {
    func_003922B8();
}
/* localdecomp:end func_00388238 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388258);

typedef int Q_383BB0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_383BB0;
typedef struct { V_383BB0 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_383BB0;
typedef struct { u8 p0[0x24]; f32 f24, f28; u8 p2C[8]; f32 f34, f38; s32 f3C; } O_383BB0;
extern f32 D_001D59B0_00383BB0, D_001D59B4_00383BB0, D_001D59BC_00383BB0;
extern s32 D_001D59B8_00383BB0;
extern f32 D_001D5948_00383BB0, D_001D594C_00383BB0, D_001D5950_00383BB0, D_001D5954_00383BB0;
extern f32 D_001D5958_00383BB0, D_001D595C_00383BB0, D_001D5960_00383BB0, D_001D5964_00383BB0;
extern V_383BB0 D_00222480_00383BB0;
extern s32 func_0038CAD0(void *);
extern void func_003C4098_00383BB0(V_383BB0 *, V_383BB0, V_383BB0, f32);
extern void func_0038CE90_00383BB0(V_383BB0 *, V_383BB0, V_383BB0);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003D2DA0();
INCLUDE_ASM("asm/nonmatchings/text", func_003886B0);

LINKER_REMNANT("asm/remnants", func_00388AF0);

typedef int u128_00384420 __attribute__((mode(TI)));
typedef struct { u8 pad[0x450]; s32 x450; u8 pad454[0xC]; } P_00384420;
typedef struct { u8 pad0[4]; s16 x4; } C_00384420;
typedef struct { u128_00384420 q[4]; } Q_00384420;
extern C_00384420 *D_001DA5F0;
extern s32 D_001D9BC4;
extern s32 D_001D9D1C;
extern s32 D_001D9348;
extern s32 D_001D934C;
extern s32 D_001D9C10_00388AF8;
extern s32 D_001D9C14_00388AF8;
extern u8 D_001D58D0;
extern s32 D_001D5B94;
extern s32 D_001D9C08_00388AF8;
extern s32 D_001D9C0C_00388AF8;
extern s32 D_001D9364;
extern s32 D_001D9368;
extern s32 D_001D9C38_00388AF8;
extern volatile s32 D_001D9EC0;
extern s32 D_001D52F0;
extern P_00384420 D_00222480_00388AF8[];
extern u8 D_001D5780;
extern u8 D_001D5781;
extern u8 D_001D5782;
extern u8 D_001D5783;
extern f32 D_001D9BD0;
extern f32 D_001D9BD8[2];
extern s32 D_001D5B98;
extern u8 D_001D5884;
extern s32 D_001D58B8;
extern u8 D_100AE0[];
extern s32 D_00143950[];
extern f32 D_001D9D10;
extern s32 D_001D9D50_00388AF8;
extern u8 D_002FDC00[];
extern u8 D_003064C0[];
extern Q_00384420 D_00225AA0;
extern Q_00384420 D_00334EC0;
extern void func_00392350(s32);
extern void func_003861F0(void);
extern void func_003C2DC0(void);
extern void func_00387218(void);
extern void func_00387F68(void);
extern void func_003CF0F0(void);
extern void func_003A9C70_00388AF8(s32);
extern void func_003D9CF0(void);
extern void func_003A96D8(void);
extern void func_00389240(s32);
extern void func_00389E28(void);
extern void func_00389370(void);
extern void func_003A9678(void);
extern void func_003DEF28(void);
extern void func_0038AD40_00388AF8(u8 *);
extern void func_00389EA0(void);
extern void func_003886B0(void);
extern void func_003C3860(void);
extern void func_00389DB0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_00385020(void);
extern void func_0038A058(void);
extern void func_11F0A0(s32);
extern void func_003CD3D8(void);
extern void func_00389F68(void);
extern void func_003D85C0_00388AF8(s32);
extern void func_003D8640(void);
extern void func_003D9260_00388AF8(s32);
extern void func_00389FE0(void);
extern void func_00385D28(s32);
extern void func_003926E8(void);
extern s32 func_003A0EA8(s32);
extern void func_0038A948(void);
extern void func_003A9CA8_00388AF8(s32);
extern void func_003AF660(void);
extern void func_00396838(void);
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern void func_00381D60(void);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_0038ABC0(void);
extern void func_003A8F90_00388AF8(void *);
extern void func_003A92F0(s32);
extern void func_003D0180(void *);
extern void func_003CF050(void);
extern void func_003DD768(void);
extern void func_003D9C30(void);
extern void func_003E0B10(void *);
extern void func_003DEE20(void);
extern void func_003C31B0(void);
extern void func_003864C0(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00388AF8);

LINKER_REMNANT("asm/remnants", func_00389220);

extern s32 D_001D9BF4_00389240;
extern s32 D_001DA050_00389240;
extern s32 D_001D9C00;
extern long D_00226000_00389240[];
extern s32 D_001D9EA0_00389240;
extern s32 D_001D9EAC_00389240;
extern volatile s32 D_001D9EB0_00389240;
extern s32 D_001D9BFC;
extern s32 D_001D4BB4_00389240;
extern s32 D_001D4BB0_00389240;
extern unsigned long D_001D58E0, D_001D58E8;
extern s32 D_001D58F0;
extern s32 D_001A1ED0_00389240[];
extern void func_0038E138(void);
/* localdecomp:start func_00389240 */
extern s32 D_001D9BF4_00389240;
extern s32 D_001DA050_00389240;
extern s32 D_001D9C00;
extern long D_00226000_00389240[];
extern s32 D_001D9EA0_00389240;
extern s32 D_001D9EAC_00389240;
extern volatile s32 D_001D9EB0_00389240;
extern s32 D_001D9BFC;
extern s32 D_001D4BB4_00389240;
extern s32 D_001D4BB0_00389240;
extern unsigned long D_001D58E0, D_001D58E8;
extern s32 D_001D58F0;
extern s32 D_001A1ED0_00389240[];

__asm__(".extern D_001D9BFC, 4");
__asm__(".extern D_001D58E0, 8");
__asm__(".extern D_001D58E8, 8");
__asm__(".extern D_001D58F0, 4");

extern void func_0038E138(void);

void func_00389240(s32 a) {
    s32 n;
    s32 t;
    s32 u;
    s32 i;
    s32 c;
    s32 j;
    long *p;

    t = D_001DA050_00389240;
    D_001D9BF4_00389240 = t;
    t += 0x10;
    D_001DA050_00389240 = t;
    u = D_001D4BB4_00389240;
    n = D_001D9C00;
    D_001D4BB0_00389240 = u;
    D_001D9BFC = 0;

    if (n > 0) {
        p = D_00226000_00389240;
        for (c = n; c != 0; c--) {
            *p = 0;
            p += 2;
        }
    }

    D_001D58E0 = 0;
    D_001D58E8 = 0;
    D_001D58F0 = 0;

    if (a == 0) {
        for (i = 0; i < *(s32 *)(D_001D9EA0_00389240 + 0x44); i++) {
            u16 *h = (u16 *)((i << 3) + D_001D9EAC_00389240 + 4);
            if (*h >= (D_001A1ED0_00389240[1] >> 8)) {
                *h = 0;
            }
        }

        for (j = 0; j < *(s32 *)(D_001D9EA0_00389240 + 0x24); j++) {
            *(u16 *)(D_001D9EB0_00389240 + j * 8 + 4) = 0;
        }
    }

    func_0038E138();
}
/* localdecomp:end func_00389240 */

extern u32 *D_001DA050_00389370;
extern u32 *D_001D9BF4_00389370;
extern u32 *D_001D9BF8_00389370;
extern void func_003A02E8();
extern s32 func_003A9618_00389370();
INCLUDE_ASM("asm/nonmatchings/text", func_00389370);

INCLUDE_ASM("asm/nonmatchings/text", func_00389478);
TEXT_PADDING(2);

typedef int Q_384DA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_384DA0;
typedef struct { u8 p0[0x220]; f32 f220; } S_225980_384DA0;
extern V4_384DA0 D_00222400_00384DA0;
extern S_225980_384DA0 D_00225900_00384DA0;
extern s32 D_001D4BC0_00384DA0, D_001D4BC4_00384DA0;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D028();

LINKER_REMNANT("asm/remnants", func_00389588);

typedef struct { unsigned long v; u16 h8; u16 hA; u8 bC; u8 bD; s16 hE; } T_384EC0;
typedef struct { s32 w0; s16 h4; s16 h6; s32 w8; u8 bC; u8 bD; s16 hE; } C_384EC0;
extern T_384EC0 D_00226000[];
extern C_384EC0 D_00225C00[];
extern s32 D_001A1ED0[];
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern s32 D_001D9C04;
extern unsigned long D_001D58E0;
extern unsigned long D_001D58E8;
extern s32 D_001D58F0;
extern u32 *D_001DA050_00389598[1];
extern u8 D_141AD0[];
extern u8 D_141DC0[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389598);

extern s32 D_001D4BB0;
extern s32 D_001DA050;
extern u8 D_003353C0[];
extern u8 D_00335430[];
extern void func_0038CC88();
extern void func_003A9618();
/* localdecomp:start func_00389B10 */
/* rac3 src/boot_elf/text/389978.c: func_00389EF0, matched on master */
extern s32 D_001D4BB0;
extern s32 D_001DA050;
extern u8 D_003353C0[];
extern u8 D_00335430[];
extern void func_0038CC88();
extern void func_003A9618();
s32 func_00389B10(s32 a, s32 p, s32 q, s32 type) {
    s32 e = p - 6;
    s32 v;
    s32 h;
    s32 r;
    u8 *d;
    if (e < 0) e = 0;
    v = (1 << (p + q)) >> 4;
    e = 1 << e;
    if (type == 0x14) {
        v = (1 << (p + q)) >> 5;
        func_0038CC88(D_001DA050, D_003353C0, 0x70);
    } else {
        func_0038CC88(D_001DA050, D_00335430, 0x70);
    }
    h = D_001D4BB0;
    r = h >> 8;
    D_001D4BB0 = h + (v << 4);
    d = (u8 *)D_001DA050;
    *(u8 *)(d + 0x26) = e;
    *(s32 *)(d + 0x64) = a;
    *(s16 *)(d + 0x24) = r;
    *(s32 *)(d + 0x30) = 1 << p;
    *(s32 *)(d + 0x34) = 1 << q;
    *(s32 *)(d + 0x50) = v | 0x8000;
    *(s32 *)(d + 0x60) = v | 0x30000000;
    *(s32 *)(d + 0x6C) = v | 0x50000000;
    D_001DA050 = D_001DA050 + 0x70;
    func_003A9618();
    return r;
}
/* localdecomp:end func_00389B10 */

extern s32 D_001D4BB0;
extern s32 D_001DA050;
extern u8 D_003354A0[];
extern u8 D_00335510[];
extern void func_0038CC88();
extern void func_003A9618();
/* localdecomp:start func_00389C48 */
extern s32 D_001D4BB0;
extern s32 D_001DA050;
extern u8 D_003354A0[];
extern u8 D_00335510[];
extern void func_0038CC88();
extern void func_003A9618();

s32 func_00389C48(s32 a, s32 b) {
    u8 *p;
    s32 h = D_001D4BB0 >> 8;

    if (b == 0x14) {
        func_0038CC88(D_001DA050, D_003354A0, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x100;
    } else {
        func_0038CC88(D_001DA050, D_00335510, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x400;
    }

    p = (u8 *)D_001DA050;
    *(s32 *)(p + 0x64) = a;
    *(s16 *)(p + 0x24) = h;
    D_001DA050 = D_001DA050 + 0x70;
    func_003A9618();
    return h;
}
/* localdecomp:end func_00389C48 */

/* localdecomp:start func_00389D00 */
unsigned long func_00389D00(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 w = c - 6;
    if (w < 0) w = 0;
    w = 1 << w;
    return ((unsigned long)(a) | ((unsigned long)(w) << 14) | ((unsigned long)(e) << 20) | ((unsigned long)(c) << 26) |
        ((unsigned long)(d) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(b) << 37) |
        ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(4) << 61));
}
/* localdecomp:end func_00389D00 */


extern s32 D_001D9C08_00389D60;
extern s32 D_00226800_00389D60[];
extern s32 D_00226900[];
/* localdecomp:start func_00389D60 */
__asm__(".extern D_001D9C08_00389D60, 16");
extern s32 D_001D9C08_00389D60;
extern void (*D_00226800[])(s32);
extern s32 D_00226900[];

void func_00389D60(void (*callback)(s32), s32 argument)
{
    s32 index = D_001D9C08_00389D60;

    if (index < 0x40) {
        D_00226800[index] = callback;
        D_00226900[index] = argument;
        D_001D9C08_00389D60 = index + 1;
    }
}
/* localdecomp:end func_00389D60 */

extern s32 D_001D9C08_00389DB0;
extern void (*D_00226800[])(s32);
extern s32 D_00226900[];
/* localdecomp:start func_00389DB0 */
extern s32 D_001D9C08_00389DB0;
extern void (*D_00226800[])(s32);
extern s32 D_00226900[];

void func_00389DB0(void) {
    s32 i;

    for (i = 0; i < D_001D9C08_00389DB0; i++) {
        D_00226800[i](D_00226900[i]);
    }
}
/* localdecomp:end func_00389DB0 */

extern s32 D_001D9C10_00389E28;
extern void (*D_00226C00[])(s32);
extern s32 D_00226D00[];
/* localdecomp:start func_00389E28 */
extern s32 D_001D9C10_00389E28;
extern void (*D_00226C00[])(s32);
extern s32 D_00226D00[];
void func_00389E28(void) {
    s32 i;
    for (i = 0; i < D_001D9C10_00389E28; i++) D_00226C00[i](D_00226D00[i]);
}
/* localdecomp:end func_00389E28 */


extern s32 D_001D9C14_00389EA0;
extern void (*D_00226E00[])(s32);
extern s32 D_00226F00[];
/* localdecomp:start func_00389EA0 */
extern s32 D_001D9C14_00389EA0;
extern void (*D_00226E00[])(s32);
extern s32 D_00226F00[];

void func_00389EA0(void) {
    s32 i;

    for (i = 0; i < D_001D9C14_00389EA0; i++) {
        D_00226E00[i](D_00226F00[i]);
    }
}
/* localdecomp:end func_00389EA0 */

extern s32 D_001D9C0C_00389F18;
extern s32 D_00226B00[];
extern s32 D_00226A00_00389F18[];
/* localdecomp:start func_00389F18 */
__asm__(".extern D_001D9C0C_00389F18, 16");
extern s32 D_001D9C0C_00389F18;
extern void (*D_00226A00[])(s32);
extern s32 D_00226B00[];

void func_00389F18(void (*callback)(s32), s32 argument)
{
    s32 index = D_001D9C0C_00389F18;

    if (index < 0x40) {
        D_00226A00[index] = callback;
        D_00226B00[index] = argument;
        D_001D9C0C_00389F18 = index + 1;
    }
}
/* localdecomp:end func_00389F18 */

/* PAL candidate for func_00389F68 (frontbin).
   Retail reaches the counter global D_001D9C0C through lui/lw, not through $gp.
   The counter is a small scalar, so gcc addresses it gp-relative; the .extern
   size hint (16 bytes) tells the assembler the global is not small data, so the
   gp-relative macro expands to retail's lui/lw pair (the same pattern the
   matched func_003932C0 uses for D_001D9E98). */

/* localdecomp:start func_00389F68 */
__asm__(".extern D_001D9C0C_00389F68, 16");
extern s32 D_001D9C0C_00389F68;
extern void (*D_00226A00[])(s32);
extern s32 D_00226B00[];
void func_00389F68(void) {
    s32 i;
    for (i = 0; i < D_001D9C0C_00389F68; i++) D_00226A00[i](D_00226B00[i]);
}
/* localdecomp:end func_00389F68 */

extern int D_001D9C38_00389FE0;
extern void (*D_001D9C18[])(int);
extern int D_001D9C28[];
/* localdecomp:start func_00389FE0 */
__asm__(".extern D_001D9C38_00389FE0, 16");
extern s32 D_001D9C38_00389FE0;

/* Aliases for the first entries of the two tables. */
extern void (*D_001D9C18_00389FE0)(s32);
extern s32 D_001D9C28_00389FE0;

void func_00389FE0(void)
{
    s32 index;

    for (index = 0; index < D_001D9C38_00389FE0; index++) {
        (&D_001D9C18_00389FE0)[index](
            (&D_001D9C28_00389FE0)[index]);
    }
}
/* localdecomp:end func_00389FE0 */

typedef struct { f32 x, y, z, w; } V_385980;
typedef union { u128_t q; V_385980 v; } Q_385980;
typedef struct { f32 x, y, u, v; } T_385980;
typedef struct { Q_385980 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_385980;
extern long func_00389598(s32);
extern void func_003D2DA0();
extern s32 D_001D5900[2];
extern s32 D_001D9C40_0038A058;
extern Q_385980 D_00227010[];
/* localdecomp:start func_0038A058 */
typedef struct { f32 x, y, z, w; } V_385980_0038A058;
typedef union { u128_t q; V_385980_0038A058 v; } Q_385980_0038A058;
typedef struct { f32 x, y, u, v; } T_385980_0038A058;
typedef struct { Q_385980_0038A058 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_385980_0038A058;
extern long func_00389598_0038A058(s32);
extern void func_003D2DA0_0038A058();
__asm__(".extern D_001D5900_0038A058, 8");
extern s32 D_001D5900_0038A058[2];
extern s32 D_001D9C40_0038A058_0038A058;
extern Q_385980_0038A058 D_00227010_0038A058[];
void func_0038A058(void) {
    S_385980_0038A058 s;
    Q_385980_0038A058 t;
    s32 i, j, k;
    f32 dot, w;
    if (D_001D9C40_0038A058_0038A058 == 0) return;
    s.f78 = func_00389598_0038A058(0);
    s.f80 = 0xFF9000000260UL;
    s.f70 = 5;
    s.f88 = 0x8000000044UL;
    for (j = 0; j < 4; j++) {
        s.uv[j][0] = ((T_385980_0038A058 *)D_001D5900_0038A058)[j].u;
        s.uv[j][1] = ((T_385980_0038A058 *)D_001D5900_0038A058)[j].v;
        s.col[j] = 0x40808080;
    }
    for (i = 0; i < D_001D9C40_0038A058_0038A058; i++) {
        t.q = D_00227010_0038A058[i * 2].q;
        func_0038CF68((s32)&t, (s32)&t, 1.0f);
        w = ((Q_385980_0038A058 *)((u8 *)D_00227010_0038A058 + i * 32 - 16))->v.w;
        for (k = 0; k < 4; k++) {
            T_385980_0038A058 *src = &((T_385980_0038A058 *)D_001D5900_0038A058)[k];
            dot = src->x * t.v.x + src->y * t.v.y;
            s.v[k].q = ((Q_385980_0038A058 *)((u8 *)D_00227010_0038A058 + i * 32 - 16))->q;
            s.v[k].v.x += (src->x - t.v.x * dot) * w;
            s.v[k].v.y += (src->y - t.v.y * dot) * w;
            s.v[k].v.z -= t.v.z * dot * w;
        }
        func_003D2DA0_0038A058(&s, 0, 0);
    }
}
/* localdecomp:end func_0038A058 */

extern u32 *D_001DA050_0038A238;
extern u32 *D_001DA050_g;
extern s32 D_001D9BC8_g;
extern s32 D_001D9BC8_0038A238;
extern u8 D_00141990[];
extern void func_003A92F0(s32);
extern s32 func_12C908(s32);
extern void func_003A9108(void);
extern void func_003A91D0(void);
extern void func_003A9150();
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
/* localdecomp:start func_0038A238 */
extern u32 *D_001DA050_0038A238;
__asm__(".extern D_001DA050_g, 4");
extern u32 *D_001DA050_g;
__asm__(".extern D_001D9BC8_g, 4");
extern s32 D_001D9BC8_g;
extern s32 D_001D9BC8_0038A238;
extern u8 D_00141990[];
extern void func_003A92F0(s32);
extern s32 func_12C908(s32);
extern void func_003A9108(void);
extern void func_003A91D0(void);
extern void func_003A9150();
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);

void func_0038A238(s32 arg0) {
    s32 i;
    s32 t;

    func_003A92F0(1);
    i = arg0 - 1;
    func_12C908(0);
    D_001D9BC8_g = D_001D9BC8_0038A238 + 1;
    func_003A9108();

    while (i >= 0) {
        func_003922B8();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_003A9440(1, (long)(0x80 - t) << 24);

        D_001DA050_0038A238[0] = 0x30000014;
        D_001DA050_0038A238[1] = (u32)D_00141990;
        D_001DA050_0038A238[2] = 0;
        D_001DA050_0038A238[3] = 0x50000014;
        D_001DA050_g = D_001DA050_0038A238 + 4;

        func_003A92F0(1);
        func_12C908(0);
        D_001D9BC8_g = D_001D9BC8_0038A238 + 1;
        func_003A91D0();
        func_003A9150();
    }

    func_003A92F0(1);
    func_12C908(0);
    D_001D9BC8_g = D_001D9BC8_0038A238 + 1;
    func_003A9108();
    func_003922B8();
    func_00392350(1);
}
/* localdecomp:end func_0038A238 */

extern s32 D_001D4D40_0038A3B8;
extern s32 D_00225734_0038A3B8[];
extern s32 D_001D55E8_0038A3B8;
extern s32 D_00143950[];
extern f32 func_0038D098(f32);
extern void func_0038DBD8(s32, s32, f32);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0038A3B8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
/* localdecomp:start func_0038A3B8 */
extern s32 D_001D4D40_0038A3B8;
extern s32 D_00225734_0038A3B8[];
extern s32 D_001D55E8_0038A3B8;
extern s32 D_00143950[];
extern f32 func_0038D098(f32);
extern void func_0038DBD8(s32, s32, f32);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0038A3B8(
    f32, f32, f32, unsigned long, s32, s32,
    f32, s32, s32, unsigned long, f32, f32
);

void func_0038A3B8(void) {
    f32 f, y;
    s32 old, n;

    if (D_001D4D40_0038A3B8 == 1) {
        n = ((u8 *)D_00143950)[0xAD] ? 0x30 : 0x5A;
        f = (f32)(D_00225734_0038A3B8[0] % 100) / 50.0f - 1.0f;
        if (f < -1.0f) f = -1.0f;
        if (1.0f < f) f = 1.0f;

        y = n;
        f = func_0038D098(f * 3.1415927f);
        n = ((s32 (*)(s32, s32, f32))func_0038DBD8)(
            0x7FE0E0E0, 0x5F66CCFF, (f + 1.0f) * 0.5f
        );

        old = D_001D55E8_0038A3B8;
        func_0038E150(0);
        func_0038E7E8_0038A3B8(
            480.0f, y, 1.0f, n, func_00381FF0(0x244), -1,
            1.0f, 2, 1, 0x80000000, 1.0f, 1.0f
        );
        func_0038E150(old);
    }
}
/* localdecomp:end func_0038A3B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038A518);

extern s32 D_001D9BE0_0038A948;
extern s32 D_001D9BDC_0038A948;
extern s32 D_001D4BD0_0038A948;
extern s32 D_001D4BD4_0038A948;
extern s32 D_001D4BD8;
extern s32 D_001D4BDC;
extern u8 D_001439FD[];
extern u8 D_001D76A0[];
extern u8 D_001D76B0[];
/* localdecomp:start func_0038A948 */
extern s32 D_001D9BE0_0038A948_0038A948;
extern s32 D_001D9BDC_0038A948_0038A948;
extern s32 D_001D4BD0_0038A948_0038A948;
extern s32 D_001D4BD4_0038A948_0038A948;
extern s32 D_001D4BD8_0038A948;
extern s32 D_001D4BDC_0038A948;
extern u8 D_001439FD_0038A948[];
extern u8 D_001D76A0_0038A948[];
extern u8 D_001D76B0_0038A948[];
void func_0038A948(void) {
    s32 n, t, n4;
    u8 *r;
    u8 *p;
    u8 *q0;
    u8 *s;
    u8 *u;
    u8 *q;
    if (D_001D9BDC_0038A948_0038A948 != 0) {
        if (D_001D9BE0_0038A948_0038A948 < 0x34) D_001D9BE0_0038A948_0038A948 = D_001D9BE0_0038A948_0038A948 + 1;
    } else {
        if (D_001D9BE0_0038A948_0038A948 == 0) return;
        D_001D9BE0_0038A948_0038A948 = D_001D9BE0_0038A948_0038A948 - 1;
    }
    n = D_001D9BE0_0038A948_0038A948;
    if (n == 0) return;
    if (D_001439FD_0038A948[0] != 0) return;
    *(s32 *)(D_001DA050 + 0) = 0x10000007;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000007;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001D76A0_0038A948;
    *(s16 *)D_001DA050 = -0x7FFF;
    p = (u8 *)D_001DA050;
    q0 = p + 0x10;
    D_001DA050 = (s32)q0;
    *(long *)(p + 0x10) = 0x104;
    *(long *)(q0 + 8) = 0x80000000UL;
    s = (u8 *)D_001DA050;
    D_001DA050 = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001D76B0_0038A948;
    *(s16 *)D_001DA050 = -0x7FF8;
    n4 = n << 4;
    u = (u8 *)D_001DA050;
    q = u + 0x10;
    D_001DA050 = (s32)q;
    *(long *)(u + 0x10) = D_001D4BD0_0038A948_0038A948 | ((long)D_001D4BD4_0038A948_0038A948 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 8) = D_001D4BD0_0038A948_0038A948 | ((long)(D_001D4BD4_0038A948_0038A948 + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x10) = D_001D4BD8_0038A948 | ((long)D_001D4BD4_0038A948_0038A948 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x18) = D_001D4BD8_0038A948 | ((long)(D_001D4BD4_0038A948_0038A948 + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x20) = D_001D4BD8_0038A948 | ((long)D_001D4BDC_0038A948 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x28) = D_001D4BD8_0038A948 | ((long)(D_001D4BDC_0038A948 - n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x30) = D_001D4BD0_0038A948_0038A948 | ((long)D_001D4BDC_0038A948 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x38) = D_001D4BD0_0038A948_0038A948 | ((long)(D_001D4BDC_0038A948 - n4) << 16) | 0xFFFFF300000000UL;
    D_001DA050 = D_001DA050 + 0x40;
}
/* localdecomp:end func_0038A948 */

/* localdecomp:start func_0038ABC0 */
typedef struct {
    s32 f0;
    u32 f4;
    unsigned long f8;
    s32 f10;
    u32 f14;
    unsigned long f18;
    s32 f20;
    u32 f24;
    unsigned long f28;
} P_00386488;

__asm__(".extern D_001D58B8_0038ABC0, 4");
extern P_00386488 *D_001D58B8_0038ABC0;
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);

typedef struct {
    u8 p0[0x150];
    s16 f150, f152;
} C_00386488;

extern C_00386488 D_001CFEC0_0038ABC0;

void func_0038ABC0(void) {
    s32 i = 0;
    s32 h = D_001CFEC0_0038ABC0.f152;
    s32 y;

    if (D_001D58B8_0038ABC0->f8) {
        func_003A9440(0x42, D_001D58B8_0038ABC0->f8 & 0xFF000000FFUL);
    }
    if (D_001D58B8_0038ABC0->f4 & 0xFF000000) {
        func_0038AF30(
            0, h, 0, D_001CFEC0_0038ABC0.f150,
            D_001D58B8_0038ABC0->f4
        );
    }

    if (h > 0) {
        do {
            if (D_001D58B8_0038ABC0->f18) {
                func_003A9440(
                    0x42, D_001D58B8_0038ABC0->f18 & 0xFF000000FFUL
                );
            }
            if (D_001D58B8_0038ABC0->f14 & 0xFF000000) {
                y = (i + D_001D58B8_0038ABC0->f10 >= h - 1)
                    ? h - 1 : i + D_001D58B8_0038ABC0->f10;
                func_0038AF30(
                    i, y, 0, D_001CFEC0_0038ABC0.f150,
                    D_001D58B8_0038ABC0->f14
                );
            }
            i += D_001D58B8_0038ABC0->f10;

            if (D_001D58B8_0038ABC0->f28) {
                func_003A9440(
                    0x42, D_001D58B8_0038ABC0->f28 & 0xFF000000FFUL
                );
            }
            if (D_001D58B8_0038ABC0->f24 & 0xFF000000) {
                y = (i + D_001D58B8_0038ABC0->f20 >= h - 1)
                    ? h - 1 : i + D_001D58B8_0038ABC0->f20;
                func_0038AF30(
                    i, y, 0, D_001CFEC0_0038ABC0.f150,
                    D_001D58B8_0038ABC0->f24
                );
            }
            i += D_001D58B8_0038ABC0->f20;
        } while (i < h);
    }
}
/* localdecomp:end func_0038ABC0 */

extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s32 D_001A1ED0[];
extern s16 D_001CFEC0[];
/* localdecomp:start func_0038AD40 */
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s32 D_001A1ED0[];
extern s16 D_001CFEC0[];

typedef struct {
    s32 f0;
    u32 f4;
    unsigned long f8;
} S;

void func_0038AD40(S *a) {
    if (a->f8) {
        func_003A9440(0x42, a->f8 & 0xFF000000FFUL);
    }

    if (a->f4 & 0xFF000000) {
        func_003A9440(
            0x4E,
            ((D_001A1ED0[2] >> 13) | 0x1000000) | 0x100000000UL
        );
        func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], a->f4);
        func_003A9440(0x4E, 0x1000000 | (D_001A1ED0[2] >> 13));
    }

    if (a->f8) {
        func_003A9440(0x42, 0x8000000044UL);
    }
}
/* localdecomp:end func_0038AD40 */

extern u32 *D_001DA050_0038AE20;
extern u8 D_00141850[];
/* localdecomp:start func_0038AE20 */
extern void func_003A9440(s32, unsigned long);
extern s32 D_001A1ED0[];
extern u32 *D_001DA050_0038AE20;
extern u8 D_00141850[];

void func_0038AE20(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_003A9440(
        0x4E,
        ((D_001A1ED0[2] >> 13) | 0x31000000) | (0x8000UL << 17)
    );
    func_003A9440(
        1,
        (long)a0 | ((long)a1 << 8) | ((long)a2 << 16) | ((long)a3 << 24)
    );

    D_001DA050_0038AE20[0] = 0x30000014;
    D_001DA050_0038AE20[1] = (u32)D_00141850;
    D_001DA050_0038AE20[2] = 0;
    D_001DA050_0038AE20[3] = 0x50000014;
    D_001DA050_0038AE20 += 4;

    func_003A9440(0x4E, 0x31000000 | (D_001A1ED0[2] >> 13));
}
/* localdecomp:end func_0038AE20 */

extern s32 D_001D4BD0_0038AF30;
extern s32 D_001D4BD4_0038AF30;
extern u8 D_001D76A0[];
extern u8 D_001D76B0[];
/* localdecomp:start func_0038AF30 */
extern s32 D_001D4BD0_0038AF30_0038AF30;
extern s32 D_001D4BD4_0038AF30_0038AF30;
extern u8 D_001D76A0_0038AF30[];
extern u8 D_001D76B0_0038AF30[];
void func_0038AF30(s32 y0, s32 y1, s32 x0, s32 x1, unsigned long c) {
    u8 *r;
    u8 *p;
    u8 *q;
    u8 *s;
    u8 *t;
    u8 *q0;
    *(s32 *)(D_001DA050 + 0) = 0x10000005;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000005;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001D76A0_0038AF30;
    *(s16 *)D_001DA050 = -0x7FFF;
    p = (u8 *)D_001DA050;
    q0 = p + 0x10;
    D_001DA050 = (s32)q0;
    *(long *)(p + 0x10) = 0x144;
    *(unsigned long *)(q0 + 8) = c;
    s = (u8 *)D_001DA050;
    D_001DA050 = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001D76B0_0038AF30;
    *(s16 *)D_001DA050 = -0x7FFC;
    t = (u8 *)D_001DA050;
    q = t + 0x10;
    D_001DA050 = (s32)q;
    *(long *)(t + 0x10) = ((x0 << 4) + D_001D4BD0_0038AF30_0038AF30 - 8) | ((long)((y0 << 4) + D_001D4BD4_0038AF30_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 8) = ((x1 << 4) + D_001D4BD0_0038AF30_0038AF30 - 8) | ((long)((y0 << 4) + D_001D4BD4_0038AF30_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x10) = ((x0 << 4) + D_001D4BD0_0038AF30_0038AF30 - 8) | ((long)((y1 << 4) + D_001D4BD4_0038AF30_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x18) = ((x1 << 4) + D_001D4BD0_0038AF30_0038AF30 - 8) | ((long)((y1 << 4) + D_001D4BD4_0038AF30_0038AF30 - 8) << 16) | 0xFFFFF000000000UL;
    D_001DA050 = D_001DA050 + 0x20;
}
/* localdecomp:end func_0038AF30 */

LINKER_REMNANT("asm/remnants", func_0038B118);

typedef int Q_3869E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3869E8;
extern s32 D_001DA050;
extern Q_3869E8 D_001D76C0_0038B120[];
extern s32 D_001D4BD0_0038B120, D_001D4BD4_0038B120;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038B120);

extern s32 D_001D4BD0_0038B4D0;
extern s32 D_001D4BD4_0038B4D0;
extern u8 D_001D76C0[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038B4D0);

LINKER_REMNANT("asm/remnants", func_0038B660);

extern s32 D_001D4BD0_0038B670, D_001D4BD4_0038B670;
extern s32 D_001DA050;
/* localdecomp:start func_0038B670 */
extern s32 D_001D4BD0_0038B670, D_001D4BD4_0038B670;
extern s32 D_001DA050;

s32 func_0038B670(s32 u, s32 v, s32 w, s32 h,
                  long t0, long t1, s32 flag,
                  f32 x, f32 y, f32 fw, f32 fh) {
    s32 u1 = u + w;
    s32 v1 = v + h;
    s32 x0 = (s32)(x * 16.0f) + D_001D4BD0_0038B670 - 8;
    s32 x1 = (s32)((x + fw) * 16.0f) + D_001D4BD0_0038B670 - 9;
    s32 y0 = (s32)(y * 16.0f) + D_001D4BD4_0038B670 - 8;
    s32 y1 = (s32)((y + fh) * 16.0f) + D_001D4BD4_0038B670 - 9;
    s32 u4 = u << 4;
    s32 uw4 = u1 << 4;
    long *p;

    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000)
        return 0;

    if (flag) {
        x0 = (x0 & 0xFFF0) + 8;
        x1 = (x1 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }

    p = (long *)D_001DA050;
    p[0] = t1;
    p[1] = 0x154;
    p[2] = 0xA | (long)u << 4 | (long)(u1 - 1) << 14
               | (long)v << 24 | (long)(v1 - 1) << 34;
    p[3] = t0;
    p[4] = (v << 20) + u4;
    p[5] = (long)x0 | (long)y0 << 16;
    p[6] = (v << 20) + uw4;
    p[7] = (long)x1 | (long)y0 << 16;
    p[8] = (v1 << 20) + u4;
    p[9] = (long)x0 | (long)y1 << 16;
    p[10] = (v1 << 20) + uw4;
    p[11] = (long)x1 | (long)y1 << 16;
    D_001DA050 += 0x60;
    return 1;
}
/* localdecomp:end func_0038B670 */

extern s32 D_001D4BD0_0038B850, D_001D4BD4_0038B850;
extern s32 D_001DA050;
/* localdecomp:start func_0038B850 */
extern s32 D_001D4BD0_0038B850, D_001D4BD4_0038B850;
extern s32 D_001DA050;

s32 func_0038B850(s32 u, s32 v, s32 w, s32 h,
                  long *c, long t1, s32 flag,
                  f32 x, f32 y, f32 fw, f32 fh) {
    s32 u1 = u + w;
    s32 v1 = v + h;
    s32 x0 = (s32)(x * 16.0f) + D_001D4BD0_0038B850 - 8;
    s32 x1 = (s32)((x + fw) * 16.0f) + D_001D4BD0_0038B850 - 9;
    s32 y0 = (s32)(y * 16.0f) + D_001D4BD4_0038B850 - 8;
    s32 y1 = (s32)((y + fh) * 16.0f) + D_001D4BD4_0038B850 - 9;
    s32 u4 = u << 4;
    s32 uw4 = u1 << 4;
    long *p;

    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000)
        return 0;

    if (flag) {
        x0 = (x0 & 0xFFF0) + 8;
        x1 = (x1 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }

    p = (long *)D_001DA050;
    p[0] = t1;
    p[1] = 0x154;
    p[2] = 0xA | (long)u << 4 | (long)(u1 - 1) << 14
               | (long)v << 24 | (long)(v1 - 1) << 34;
    p[3] = c[0];
    p[4] = (v << 20) + u4;
    p[5] = (long)x0 | (long)y0 << 16;
    p[6] = c[1];
    p[7] = (v << 20) + uw4;
    p[8] = (long)x1 | (long)y0 << 16;
    p[9] = c[2];
    p[10] = (v1 << 20) + u4;
    p[11] = (long)x0 | (long)y1 << 16;
    p[12] = c[3];
    p[13] = (v1 << 20) + uw4;
    p[14] = (long)x1 | (long)y1 << 16;
    p[15] = 0;
    D_001DA050 += 0x80;
    return 1;
}
/* localdecomp:end func_0038B850 */

extern s32 D_001D4BD0_0038BA30;
extern s32 D_001D4BD4_0038BA30;
/* localdecomp:start func_0038BA30 */
extern s32 D_001D4BD0_0038BA30;
extern s32 D_001D4BD4_0038BA30;
extern s32 D_001DA050;
s32 func_0038BA30(s32 x, s32 y, s32 w, s32 h, long t0, long t1, long t2, s32 snap,
                  f32 sx, f32 sy, f32 sw, f32 sh, f32 dx, f32 dy) {
    s32 x2, y2;
    s32 U0, U1, V0, V1, U0d, U1d, V0d, V1d;
    long clamp;
    long *p;
    s32 ox, oy, ddx, ddy;
    s32 tx0, tx1;
    f32 ex, ey;
    ex = sx + sw;
    dy = dy * 16.0f;
    dx = dx * 16.0f;
    ox = D_001D4BD0_0038BA30;
    U0 = (s32)(sx * 16.0f) + ox - 8;
    ddx = (s32)dx;
    tx0 = x << 4;
    U0d = U0 + ddx;
    U1 = (s32)(ex * 16.0f) + ox - 8;
    oy = D_001D4BD4_0038BA30;
    U1d = U1 + ddx;
    ddy = (s32)dy;
    x2 = x + w;
    ey = sy + sh;
    V0 = (s32)(sy * 16.0f) + oy - 8;
    y2 = y + h;
    V1 = (s32)(ey * 16.0f) + oy - 8;
    V0d = V0 + ddy;
    V1d = V1 + ddy;
    tx1 = x2 << 4;
    if (U0 > 0x9000 || U1 < 0x7000 || V0 > 0x9000 || V1 < 0x7000) return 0;
    if (snap) {
        U0 = (U0 & 0xFFF0) + 8;
        U1 = (U1 & 0xFFF0) + 8;
        V0 = (V0 & 0xFFF0) + 8;
        V1 = (V1 & 0xFFF0) + 8;
        U0d = (U0d & 0xFFF0) + 8;
        U1d = (U1d & 0xFFF0) + 8;
        V0d = (V0d & 0xFFF0) + 8;
        V1d = (V1d & 0xFFF0) + 8;
    }
    clamp = 0xA | ((long)x << 4) | ((long)(x2 - 1) << 14) | ((long)y << 24) | ((long)(y2 - 1) << 34);
    p = (long *)D_001DA050;
    p[0] = t2;
    p[1] = 0x154;
    p[2] = clamp;
    p[3] = t1;
    p[4] = (y << 20) + tx0;
    p[5] = (long)U0d | ((long)V0d << 16);
    p[6] = (y << 20) + tx1;
    p[7] = (long)U1d | ((long)V0d << 16);
    p[8] = (y2 << 20) + tx0;
    p[9] = (long)U0d | ((long)V1d << 16);
    p[10] = (y2 << 20) + tx1;
    p[11] = (long)U1d | ((long)V1d << 16);
    p[12] = t2;
    p[13] = 0x154;
    p[14] = clamp;
    p[15] = t0;
    p[16] = (y << 20) + tx0;
    p[17] = (long)U0 | ((long)V0 << 16);
    p[18] = (y << 20) + tx1;
    p[19] = (long)U1 | ((long)V0 << 16);
    p[20] = (y2 << 20) + tx0;
    p[21] = (long)U0 | ((long)V1 << 16);
    p[22] = (y2 << 20) + tx1;
    p[23] = (long)U1 | ((long)V1 << 16);
    D_001DA050 += 0xC0;
    return 1;
}
/* localdecomp:end func_0038BA30 */

typedef int Q_3875A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3875A0;
extern s32 D_001D4BD0_0038BCD8;
extern s32 D_001D4BD4_0038BCD8;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038BCD8);

typedef int u128_387A00 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7770[];
/* localdecomp:start func_0038C138 */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9A40[2])(s32);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9C18[])(int);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern u8 D_001D7770[];
extern s32 D_001DA050;

void func_0038C138(long *a, s32 *b, s32 *c, long d, s32 e) {
    u8 *r;
    u8 *p;
    u8 *q;
    *(s32 *)(D_001DA050 + 0) = 0x10000009;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000009;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_387A00 *)(r + 0x10) = *(u128_387A00 *)D_001D7770;
    p = (u8 *)D_001DA050;
    q = p + 0x10;
    D_001DA050 = (s32)q;
    if (e) {
        *(long *)(p + 0x10) = 5;
    } else {
        *(long *)(p + 0x10) = 0;
    }
    *(long *)(q + 8) = d;
    *(long *)(q + 0x10) = 0x154;
    *(long *)(q + 0x18) = c[0];
    *(long *)(q + 0x20) = b[0];
    *(long *)(q + 0x28) = a[0];
    *(long *)(q + 0x30) = c[1];
    *(long *)(q + 0x38) = b[1];
    *(long *)(q + 0x40) = a[1];
    *(long *)(q + 0x48) = c[2];
    *(long *)(q + 0x50) = b[2];
    *(long *)(q + 0x58) = a[2];
    *(long *)(q + 0x60) = c[3];
    *(long *)(q + 0x68) = b[3];
    *(long *)(q + 0x70) = a[3];
    *(long *)(q + 0x78) = 0;
    D_001DA050 = D_001DA050 + 0x80;
}
/* localdecomp:end func_0038C138 */

typedef int u128_387B10 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7740[];
/* localdecomp:start func_0038C248 */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9A40[2])(s32);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9C18[])(int);
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern s32 D_001DA050;
extern u8 D_001D7740[];

void func_0038C248(long *a, s32 *b) {
    u8 *p;
    u8 *q;
    u8 *r;
    *(s32 *)(D_001DA050 + 0) = 0x10000005;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000005;
    r = (u8 *)D_001DA050;
    D_001DA050 = (s32)r + 0x10;
    *(u128_387B10 *)(r + 0x10) = *(u128_387B10 *)D_001D7740;
    p = (u8 *)D_001DA050;
    q = p + 0x10;
    D_001DA050 = (s32)q;
    *(long *)(p + 0x10) = 0x4C;
    *(long *)(q + 8) = b[0];
    *(long *)(q + 0x10) = a[0];
    *(long *)(q + 0x18) = a[2];
    *(long *)(q + 0x20) = b[1];
    *(long *)(q + 0x28) = a[1];
    *(long *)(q + 0x30) = a[3];
    *(long *)(q + 0x38) = 0;
    D_001DA050 = D_001DA050 + 0x40;
}
/* localdecomp:end func_0038C248 */

extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern void func_0038C248(unsigned long *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038C310);

/* localdecomp:start func_0038C3B0 */
void func_0038C3B0(s32 x, s32 y, s32 w, s32 z, s32 a, s32 b) {
    s32 c = (a << 24) | b;
    func_0038AF30(x, y, w, z, c);
    func_0038AF30(x + 1, y - 1, w - 2, w, c);
    func_0038AF30(x + 2, y - 2, w - 3, w - 2, c);
    func_0038AF30(x + 4, y - 4, w - 4, w - 3, c);
    func_0038AF30(x + 1, y - 1, z, z + 2, c);
    func_0038AF30(x + 2, y - 2, z + 2, z + 3, c);
    func_0038AF30(x + 4, y - 4, z + 3, z + 4, c);
}
/* localdecomp:end func_0038C3B0 */

LINKER_REMNANT("asm/remnants", func_0038C4F0);

typedef struct { f32 x, y, z, w; } V_387DC8;
extern void func_0038C138(long *, s32 *, s32 *, long, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038C500);
TEXT_PADDING(2);

typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018;
extern f32 D_001D5880;
extern s32 D_001D9D1C;
extern S_388018 D_00225900_0038C750;
extern long D_001D5330[];
extern u8 D_0010F500[];
extern void func_0038D2D0_0038C750(f32 *, f32);
extern u16 D_0010F4F0[];
extern void func_003A9338(s32, u32);
extern void func_003A9740(void);
/* localdecomp:start func_0038C750 */
typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018_0038C750;
__asm__(".extern D_001D5880_0038C750, 4");
extern f32 D_001D5880_0038C750;
extern s32 D_001D9D1C_0038C750;
extern S_388018_0038C750 D_00225900_0038C750_0038C750;
extern long D_001D5330_0038C750[];
extern u8 D_0010F500_0038C750[];
extern void func_0038D2D0_0038C750_0038C750(f32 *, f32);
extern u16 D_0010F4F0_0038C750[];
extern void func_003A9338_0038C750(s32, u32);
extern void func_003A9740_0038C750(void);
void func_0038C750(void) {
    f32 m[12];
    f32 v[4];
    u8 *p;
    u8 *q;
    u8 *d;
    S_388018_0038C750 *s;
    func_0038D2D0_0038C750_0038C750(m, 1024.0f);
    func_0038CE20(v, D_00222400, -1024.0f);
    v[3] = 1.0f;
    if (D_001D9D1C_0038C750 != 8) {
        func_003A9338_0038C750((s32)D_0010F500_0038C750, D_0010F4F0_0038C750[0]);
        D_001D9D1C_0038C750 = 8;
    }
    *(s32 *)(D_001DA050 + 0) = 0x10000000;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0x11000000;
    *(s32 *)(D_001DA050 + 0xC) = 0x1000404;
    p = (u8 *)D_001DA050;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x1C) = 0x6C0C43A4;
    q = p + 0x20;
    func_0038D640(q, (u8 *)D_00222400 - 0x100, m);
    *(f32 *)(q + 0x38) += D_001D5880_0038C750;
    q = p + 0x60;
    func_0038D640(q, (u8 *)D_00222400 - 0x80, m);
    *(f32 *)(q + 0x38) += D_001D5880_0038C750;
    s = &D_00225900_0038C750_0038C750;
    *(s32 *)(p + 0xA0) = 0x8000;
    *(s32 *)(p + 0xA4) = 0x303EC000;
    *(s32 *)(p + 0xA8) = 0x412;
    *(f32 *)(p + 0xAC) = s->f220;
    *(u128_t *)(p + 0xB0) = s->q190;
    *(u128_t *)(p + 0xC0) = s->q1A0;
    *(f32 *)(p + 0xD0) = s->f23C;
    *(f32 *)(p + 0xD4) = s->f238;
    *(s32 *)(p + 0xE0) = 0x3000000;
    *(s32 *)(p + 0xE4) = 0x20001D2;
    *(s32 *)(p + 0xE8) = 0x15000000;
    *(s32 *)(p + 0xD8) = 0;
    *(s32 *)(p + 0xDC) = 0;
    *(s32 *)(p + 0xEC) = 0;
    q = p + 0xF0;
    d = (u8 *)D_001DA050;
    *(s32 *)d |= ((q - d) >> 4) - 1;
    D_001DA050 = (s32)q;
    D_001D5330_0038C750[2] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    D_001D5330_0038C750[4] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    func_003A9740_0038C750();
}
/* localdecomp:end func_0038C750 */

LINKER_REMNANT("asm/remnants", func_0038C990);

/* localdecomp:start func_0038C9B0 */
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_0038C9B0(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_0038C9B0 */
