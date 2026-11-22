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

/* localdecomp:start func_003825F8 */
extern s32 D_001D9D08;
extern s32 D_001D9A28[2];
extern s32 D_001D9A30[2];
__asm__(".extern D_001D9D08, 16");

u32 func_003825F8(u32 a, u32 b, s32 frames, s32 idx, s32 reset, s32 mode) {
    extern f32 func_0038D098(f32);
    extern void func_0038DBD8(s32, s32, f32);
    s32 *last = &D_001D9A30[idx];
    s32 *count = &D_001D9A28[idx];
    s32 n;
    s32 m;
    f32 t;

    if (*last != D_001D9D08) {
        *last = D_001D9D08;
        (*count)++;
    }
    if (reset) {
        *count = 0;
    }
    n = (frames * 5 + 2) / 6;
    switch (mode) {
    case 0:
        m = *count % (n * 2);
        if (m >= n) {
            t = 1.0f - (f32)(m - n) / (f32)n;
        } else {
            t = (f32)m / (f32)n;
        }
        break;
    case 1:
        t = func_0038D098((f32)(*count % n) / (f32)n * 3.1415925f);
        t = t * t;
        t = t * t;
        break;
    default:
        t = 0.5f;
        break;
    }
    return ((u32 (*)(s32, s32, f32))func_0038DBD8)(b, a, t);
}
/* localdecomp:end func_003825F8 */

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
#include "vu0.h"
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
            { f32 d = v - e->f424, r; r = fabs_asm(d); if (r < 0.0001f) e->b439 = 0; }
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
    var_f13 = fabs_asm(temp_f13);
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
    var_f0 = fabs_asm(temp_f0);
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
/* localdecomp:start func_00382E10 */
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68_xr00382E10;
extern void func_00382A80(s32);
extern void func_00382DC8(u8 *);
extern void func_00382E10(u8 *, s32);

void func_00382E10(u8 *o, s32 a1) {
    s32 idx = *(s32 *)(o + 0x94);
    s32 j = idx;
    u8 *e = (u8 *)D_00222480 + idx * 0x460;
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
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2C8 = f;
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2B8 = 0.018f;
            }
        } else if (m == 5) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 2;
            if (0.0f < f) {
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f324 = f;
            } else {
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f324 = 0x28;
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
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2C8 = f;
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68_xr00382E10 *)((u8 *)D_00222480 + j * 0x460))->f2B8 = 0.018f;
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
    func_0038CD28(D_002251D0 + off, D_002251D0 - 0x280 + off, 0x280);
    *(u8 **)(*(u8 **)(e + 0x54) + 0x70) = D_002251D0 + off;
    *(u8 **)(e + 0x50) = o;
    *(u8 **)(o + 0x70) = D_002251D0 - 0x280 + off;
    q = o;
    *(s32 *)(e + 0x454) = 0;
    func_00382DC8(q);
    func_00382A80(idx);
    *(u128_37EB68 *)e = *(u128_37EB68 *)(q + 0x30);
    {
        f32 *src = (f32 *)(q + 0x30);
        f32 *dst = (f32 *)(q + 0x64);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}
/* localdecomp:end func_00382E10 */

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

/* localdecomp:start func_00383830 */
/* from boot_elf's twin func_00383C10 */
typedef struct { f32 f0,f4,f8,fC,f10,f14,f18,f1C; } Floats_00383830;
typedef struct { s32 pad[3]; s32 ticks; f32 rate; s32 counter; } Rate_00383830;
typedef struct { s16 state; u8 previous, mode; u8 pad[12]; Floats_00383830 a; u128_t q30,q40,q50,q60; Rate_00383830 r; } State_00383830;
extern void func_003836C8(s32);
extern void func_003837A0(s32);
extern void func_003837F8(s32);
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern void func_003834D0();
extern void func_003C47E8(void *, void *);
void func_00383830(u8 *obj) {
    u128_t v[3];
    s32 idx = *(s32 *)(obj+0x94);
    u8 *p = (u8 *)&D_00222480[idx];
    State_00383830 *s = (State_00383830 *)(p+0x2A0);
    if (s->state == 1) {
        if (s->mode == 0) {
            *(u128_t *)(p+0x2F0)=*(u128_t *)(obj+0x30);
            func_003C47E8(p+0x300,obj);
        } else if (s->mode == 2) {
            *(u128_t *)(p+0x360)=*(u128_t *)(obj+0x30);
            func_003C47E8(p+0x370,obj);
            func_003836C8(idx);
        } else {
            func_0038CF68((s32)&v[0],*(s32 *)(p+0x240)+0xC0,1.0f);
            func_0038CF68((s32)&v[1],*(s32 *)(p+0x240)+0xD0,1.0f);
            func_0038CF68((s32)&v[2],*(s32 *)(p+0x240)+0xE0,1.0f);
            func_003834D0(p+0x310,obj+0x30,*(s32 *)(p+0x50)+0x30,&v[0],&v[1],&v[2]);
            func_003C47E8(p+0x350,obj);
            *(u128_t *)(p+0x370)=*(u128_t *)(p+0x350);
        }
    } else {
        if (s->mode==2) {
            func_003837A0(idx);
            func_003836C8(idx);
        } else if (s->mode==1) {
            func_003837A0(idx);
            *(u128_t *)(p+0x350)=*(u128_t *)(p+0x370);
        } else if (s->mode==0) {
            func_003837F8(idx);
        }
    }
    s->state=3;
    s->previous=s->mode;
    if(s->mode==0) {
        Floats_00383830 *a=&s->a;
        a->f10=a->f1C;
        a->f14=a->f18;
        a->f1C=0;
        s->q40=s->q50;
        s->a.f0=a->fC;
        a->fC=0;
        a->f4=a->f8;
        s->q30=s->q60;
    } else {
        Rate_00383830 *r=&s->r;
        r->counter++;
        r->ticks=(r->counter*5+2)/6;
        r->rate=1.0f/r->ticks;
    }
}
/* localdecomp:end func_00383830 */

/* localdecomp:start func_00383A68 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00383A68;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_00383A68;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_00383A68 v20; V_00383A68 v30; V_00383A68 v40; u8 m50[0x40]; } B_00383A68;
typedef struct { V_00383A68 v0; u8 p10[0x1C0 - 0x10]; V_00383A68 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_00383A68;
extern E_00383A68 D_00222480_00383A68[];
extern void func_003C47E8(void *, void *);
extern void func_0038D6C8(void *, void *, void *, f32);
extern void func_0038D830(void *, void *);
extern void func_0038D590(void *, void *);

/* a vector assignment (the vector type's copy) */
static __inline__ void vcopy_00383A68(V_00383A68 *dst, V_00383A68 *src) { *dst = *src; }

/* from boot_elf's draft of its twin func_00383E48 (nonmatching/boot_elf/func_00383E48.c) */
s32 func_00383A68(void *arg, void *state)
{
    f32 v[4] __attribute__((aligned(16)));
    u128_t matrix[4];
    O_00383A68 *m = arg;
    B_00383A68 *d = state;
    f32 t;

    if (d->f10 == 1.0f && d->f0 == 1.0f) return 1;
    t = func_003C3BE8(0.0f, 1.0f, d->f10);
    vec_add_ba(&d->v30, &D_00222480_00383A68[m->f94].v1C0, &d->v30);
    d->v40.x = d->v30.x + (m->f30 - d->v30.x) * t;
    d->v40.y = d->v30.y + (m->f34 - d->v30.y) * t;
    d->v40.z = d->v30.z + (m->f38 - d->v30.z) * t;
    vcopy_00383A68(&D_00222480_00383A68[m->f94].v0, &d->v40);
    func_003C47E8(v, m);
    t = func_003C3BE8(0.0f, 1.0f, d->f0);
    func_0038D6C8(d->m50, &d->v20, v, t);
    func_0038D830(d->m50, matrix);
    func_0038D590(D_00222480_00383A68[m->f94].m380, matrix);
    d->f10 += d->f14 * 1.2f;
    if (d->f10 > 1.0f) d->f10 = 1.0f;
    d->f0 += d->f4 * 1.2f;
    if (d->f0 > 1.0f) d->f0 = 1.0f;
    return 0;
}
/* localdecomp:end func_00383A68 */

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
/* localdecomp:start func_00383C48 */
/* from the boot_elf twin's near miss, nonmatching/boot_elf/func_00384028.c */
#include "vu0.h"
typedef struct { f32 f0, f4, f8; s32 iC; f32 f10; s32 i14; u8 p18[8]; vu0_v4 v20, v30; u8 m40[0x10]; vu0_v4 v50; u8 m60[0x10]; } S_00383C48;
extern u8 D_00222480_00383C48[];
extern void func_0038CE90();
extern void func_0038D810(void *, void *);
extern void func_003C4840(f32 *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_0038CE20(f32 *, void *, f32);
s32 func_00383C48(u8 *obj, S_00383C48 *st) {
    vu0_v4 angles, a, cross, b, base, offset, diff, projected;
    vu0_v4 basis[3], ta, tb, full, rot;
    f32 fraction, delta, angle, sign, step, dot;
    u8 *entry, *model;
    if (st->iC <= 0) return 1;
    entry = D_00222480_00383C48 + *(s32 *)(obj + 0x94) * 0x460;
    fraction = 1.0f / func_003C3BE8(1.0f, (f32)st->i14, (f32)st->iC * st->f10);
    model = entry + 0x150;
    if (entry[0x2A2] == 2) {
        base = *(vu0_v4 *)(entry + 0x190);
        a = st->v20;
        b = st->v30;
        func_0038CE90(&cross, &a, &b);
        func_003834D0(&angles, obj + 0x30, &base, &a, &cross, &b);
    } else {
        base = *(vu0_v4 *)(obj + 0x30);
        func_0038CF68((s32)&a, *(s32 *)(model + 0xF0) + 0xC0, 1.0f);
        func_0038CF68((s32)&b, *(s32 *)(model + 0xF0) + 0xE0, 1.0f);
        angles.z = 0.0f; angles.x = 3.1415927f; angles.y = 0.0f;
    }
    delta = func_0038DB00(angles.x, st->f0);
    st->f0 = ((f32 (*)(f32, f32))func_0038DAB8)(st->f0, delta * fraction);
    st->f4 = ((f32 (*)(f32, f32))func_0038DAB8)(st->f4, func_0038DB00(angles.y, st->f4) * fraction);
    st->f8 += (angles.z - st->f8) * fraction;
    func_0038CF68((s32)&offset, (s32)&a, st->f8);
    func_0038D890(&offset, &offset, &b, st->f0);
    func_0038CE90(&cross, &offset, &b);
    func_0038CF68((s32)&cross, (s32)&cross, 1.0f);
    func_0038D890(&offset, &offset, &cross, st->f4);
    vec_add_ba(&st->v50, &base, &offset);
    *(vu0_v4 *)entry = st->v50;
    func_0038D810(st->m40, basis);
    dot = func_0038CE68(&basis[2], obj);
    func_0038CE20((f32 *)&projected, &basis[2], dot);
    vec_sub_ba(&diff, obj, &projected);
    dot = func_0038CE68(&basis[0], &diff);
    angle = 1.5707964f - func_0038D0C8(dot / func_0038CEA8(&diff));
    sign = func_0038CE68(&diff, &basis[1]) >= 0.0f ? 1.0f : -1.0f;
    angle *= sign;
    if (fabs_asm(delta) > 1.5707964f && ((delta >= 0.0f && sign < 0.0f) || (delta < 0.0f && sign >= 0.0f))) {
        if (angle < 0.0f) angle += 6.2831855f;
        else angle -= 6.2831855f;
    }
    step = angle * fraction;
    if (fabs_asm(step) < 0.00001f) {
        ta = basis[0]; tb = basis[1];
    } else {
        func_003C4840((f32 *)&full, &basis[2], step);
        func_0038D850(&ta, &basis[0], &full);
        func_0038D850(&tb, &basis[1], &full);
    }
    if (fabs_asm(angle) < 0.00001f) full = basis[0];
    else {
        func_003C4840((f32 *)&rot, &basis[2], angle);
        func_0038D850(&full, &basis[0], &rot);
    }
    angle = 1.5707964f - func_0038D0C8(func_0038CE68(&full, obj));
    dot = func_0038CE68(&full, obj + 0x20);
    sign = -1.0f;
    if (dot >= 0.0f) sign = 1.0f;
    angle *= sign;
    func_0038D890(&ta, &ta, &tb, angle * fraction);
    func_0038CF68((s32)(entry + 0x380), (s32)&ta, 1.0f);
    func_0038CE90(entry + 0x390, entry + 0x380, model + 0x80);
    func_0038CF68((s32)(entry + 0x390), (s32)(entry + 0x390), -1.0f);
    func_0038CE90(entry + 0x3A0, entry + 0x390, entry + 0x380);
    func_003C47E8(st->m60, entry + 0x380);
    func_003C47E8(st->m40, entry + 0x380);
    func_0038CAD0(&st->iC);
    return 0;
}
/* localdecomp:end func_00383C48 */

extern u8 D_00222720[];
extern u8 D_00222480_003841B8[];
extern s32 func_00383C48();
/* localdecomp:start func_003841B8 */
typedef int Q_003841B8 __attribute__((mode(TI)));
extern u8 D_00222480_003841B8[];
extern s32 func_00383A68(void *, void *);
extern s32 func_00383C48();

void func_003841B8(u8 *arg) {
    u8 *p = D_00222480_003841B8 + 0x2A0 + *(s32 *)(arg + 0x94) * 0x460;
    s32 ok;
    if (p[2] == 0) ok = func_00383A68(arg, p + 0x10);
    else ok = func_00383C48(arg, p + 0x70);
    if (ok) {
        u8 *q = D_00222480_003841B8 + *(s32 *)(arg + 0x94) * 0x460;
        *(Q_003841B8 *)(q + 0x380) = *(Q_003841B8 *)(arg + 0);
        *(Q_003841B8 *)(q + 0x390) = *(Q_003841B8 *)(arg + 0x10);
        *(Q_003841B8 *)(q + 0x3A0) = *(Q_003841B8 *)(arg + 0x20);
        *(Q_003841B8 *)(q) = *(Q_003841B8 *)(arg + 0x30);
        *(s16 *)p = 0;
        p[2] = 0;
    }
}
/* localdecomp:end func_003841B8 */

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
/* localdecomp:start func_00384498 */
/* from boot_elf's twin func_00384878 (src/boot_elf/text/384878.c) */
__asm__(".extern D_001D57B8, 4");
__asm__(".extern D_001D57BC, 4");
__asm__(".extern D_001D57C4, 4");
void func_00384498(s32 idx,s32 reset) {
 E_3801C0 *e=&D_00222480_00384498[idx];
 A_3801C0 *a=&e->a;
 B_3801C0 *b=&e->b;
 U_3801C0 v,t;
 f32 gain,rate;
 s32 i;
 func_0038CF68((s32)&v,(s32)&a->v80,-1.0f);
 e->b.q40=e->b.q30;
 e->b.q30=v.q;
 if(reset) {
  e->b.u20.q=v.q;
  qzero(&e->b.u50);
 } else {
  if(func_0038CE68(&b->u20,&v)<-0.98f) {
   v.v.x+=0.2f;v.v.y+=0.2f;v.v.z+=0.2f;
  }
  rate=D_001D57BC;gain=D_001D57B8;
  if(e->f50->h86==32) rate=gain=D_001D57C4;
  b->u20.v.x=func_00382BC8(&b->u50.v.x,b->u20.v.x,v.v.x,rate,gain,0.0f);
  b->u20.v.y=func_00382BC8(&b->u50.v.y,b->u20.v.y,v.v.y,rate,gain,0.0f);
  b->u20.v.z=func_00382BC8(&b->u50.v.z,b->u20.v.z,v.v.z,rate,gain,0.0f);
  func_0038CF68((s32)&b->u20,(s32)&b->u20,1.0f);
 }
 vec_sub_ba(&b->v70,&a->u40,&b->u60);
 b->fA0=func_0038CEA8(&b->v70);
 b->fA8=func_0038CE68(&b->v70,&v);
 func_0038CF68((s32)&t,(s32)&v,b->fA8);
 b->q90=t.q;
 vec_sub_ba(&b->v80,&b->v70,&t);
 b->fA4=func_0038CEA8(&b->v80);
 func_0038CE20((f32 *)&b->v80,&b->v80,1.0f/b->fA4);
 b->u60.q=a->u40.q;
 if(a->iFC!=80 || a->i100==17) {
  b->f0=a->u40.v.x;
  b->f4=a->u40.v.y;
  b->f8=func_00382BC8(b->f10,b->f8,a->u40.v.z,0.0075f,0.175f,0.0f);
  b->fC=a->u40.v.z;
 } else {b->f0=a->u40.v.x;b->f4=a->u40.v.y;}
 for(i=0;i<4;i++) b->fAC[i]=b->fAC[i+1];
 b->fAC[i]=a->f58;
}
/* localdecomp:end func_00384498 */

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
/* localdecomp:start func_00384D88 */
/* from boot_elf's twin func_00385168 */
typedef int Q_00384D88 __attribute__((mode(TI)));
__asm__(".extern D_001D9B40, 64");
__asm__(".extern D_001D9B00, 32");
extern u8 D_00222480_00384D88[];
extern void func_00384AC8(s32);
extern void func_00384BB8(s32);
extern void func_00383830(u8 *);
extern void func_003841B8(u8 *);
extern void func_00384260(s32, void *, s32);
extern void func_00384778(s32);
extern void func_00384CC8(s32);
void func_00384D88(void) {
    s32 saved[16];
    s32 i;
    {
    s32 j;
    for(j=0;j<16;j++) {
        u8 *moby=D_001D9B40[j];
        if(moby) {
            if(moby[0x20]==0xFE) {
                D_001D9B40[j]=0;
            } else if(moby[0x20]==0xFD) {
                D_001D9B40[j]=0;
            } else {
                saved[j]=*(s32 *)(moby+0x98);
                *(s32 *)(moby+0x98)=0;
            }
        }
    }
    }
    for(i=0;i<=0;i++) {
        u8 *hero=D_00222480_00384D88+i*0x460;
        u8 *state=hero+0x150;
        u8 *matrix;
        if(*(s32 *)(state+0x100)==0x31) {
            u8 *moby=*(u8 **)(state+0xF4);
            if(moby) *(s32 *)(moby+0x98)=0;
        }
        (*(s32 *)(hero+0x454))++;
        func_00384AC8(i);
        func_00384BB8(i);
        func_003848D8(i);
        func_00384498(i,0);
        func_00383380(i);
        matrix=*(u8 **)(hero+0x50);
        if(*(s32 *)(hero+0x458)>0) *(s16 *)(hero+0x2A0)=0;
        if((u32)(*(u16 *)(hero+0x2A0)-1)<2)func_00383830(*(u8 **)(hero+0x54));
        if(*(s16 *)(hero+0x2A0)==3) {
            func_003841B8(matrix);
        } else {
            *(Q_00384D88 *)hero=*(Q_00384D88 *)(matrix+0x30);
            *(Q_00384D88 *)(hero+0x380)=*(Q_00384D88 *)matrix;
            *(Q_00384D88 *)(hero+0x390)=*(Q_00384D88 *)(matrix+0x10);
            *(Q_00384D88 *)(hero+0x3A0)=*(Q_00384D88 *)(matrix+0x20);
        }
        func_003C48A8(hero+0x380,hero+0x10);
        func_00384260(i,hero+0x20,0);
        func_00384260(i,hero+0x30,1);
        func_00384260(i,hero+0x40,2);
        func_00384778(i);
        func_00385EF0(hero);
        func_003828D8(i);
        qzero(hero+0x410);
        if(*(s32 *)(state+0x100)==0x31) {
            u8 *moby=*(u8 **)(state+0xF4);
            if(moby) *(s32 *)(moby+0x98)=*(s32 *)(*(u8 **)(moby+0x24)+0x10);
        }
        *(Q_00384D88 *)(D_001D9B00+i*4)=*(Q_00384D88 *)hero;
        func_0038CAD0(hero+0x458);
    }
    if(!D_001D5B98) {
        D_001D90B0=D_001D90B8;
        func_00384CC8(0);
    }
    {
    s32 k;
    for(k=0;k<16;k++) {
        if(D_001D9B40[k]) *(s32 *)(D_001D9B40[k]+0x98)=saved[k];
    }
    }
}
/* localdecomp:end func_00384D88 */
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
/* localdecomp:start func_00385020 */
void func_00385020(void) {
    f32 scr[2];
    f32 ctr[2];
    f32 d[2];
    f32 o[2];
    f32 p[2];
    f32 dist, a, b, c, half, h;
    s32 i, size, w, col;
    long tex;
    if (D_00222900.state != 1 || (D_00222900.obj->b20 & 0x80)) {
        D_00222900.state = 0;
        return;
    }
    if (D_00222900.f8 <= 0.0f) return;
    dist = func_0038CF00(D_00222480, D_00222900.obj->pos);
    ctr[0] = (f32)D_001D4BC8_00385020;
    ctr[1] = (f32)D_001D4BCC_00385020;
    func_003860A8(scr, D_00222900.obj->pos);
    scr[0] = (scr[0] - (f32)D_001D4BD0_00385020) * 0.0625f;
    scr[1] = (scr[1] - (f32)D_001D4BD4_00385020) * 0.0625f;
    d[0] = ctr[0] - scr[0];
    d[1] = ctr[1] - scr[1];
    for (i = 0; i < 16; i++) {
        tex = func_00389598(D_00222900.h30[i] + 6);
        o[0] = d[0] * D_00222900.f90[i];
        o[1] = d[1] * D_00222900.f90[i];
        p[0] = ctr[0] + o[0];
        p[1] = ctr[1] + o[1];
        size = 0x40;
        if (i != 0) size = 0x20;
        a = dist - 5.0f;
        if (a > 1.0f) a = 1.0f;
        else if (a < 0.0f) a = 0.0f;
        b = __builtin_fabsf(d[0]) / ctr[0] * -5.0f + 5.5f;
        if (b > 1.0f) b = 1.0f;
        else if (b < 0.0f) b = 0.0f;
        c = __builtin_fabsf(d[1]) / ctr[1] * -5.0f + 5.5f;
        if (c > 1.0f) c = 1.0f;
        else if (c < 0.0f) c = 0.0f;
        a *= b * c;
        h = (f32)D_00222900.h10[i];
        col = D_00222900.c50[i] & 0xFFFFFF;
        w = (s32)((f32)size * D_00222900.fD0[i]);
        half = (f32)(w >> 1);
        func_0038B4D0((s32)(p[0] - half), (s32)(p[1] - half), w, w, 0, 0, size, size,
                      ((s32)(a * h) << 24) | col, tex);
    }
    D_00222900.f8 = 0.0f;
}
/* localdecomp:end func_00385020 */

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
/* localdecomp:start func_003856B8 */
__asm__(".extern D_001D57C8, 4");
__asm__(".extern D_001D57CC, 4");
__asm__(".extern D_001D57D0, 4");
__asm__(".extern D_001D57D4, 4");
__asm__(".extern D_001D57D8, 4");
__asm__(".extern D_001D57E8, 4");
__asm__(".extern D_001D57F8, 4");
__asm__(".extern D_001D5804, 4");
__asm__(".extern D_001D5808, 4");
__asm__(".extern D_001D580C, 4");
__asm__(".extern D_001D5810, 4");
__asm__(".extern D_001D5814, 4");
__asm__(".extern D_001D5818, 4");
__asm__(".extern D_001D581C, 4");
__asm__(".extern D_001D5820, 4");
__asm__(".extern D_001D5824, 4");
__asm__(".extern D_001D5828, 4");
__asm__(".extern D_001D582C, 4");
__asm__(".extern D_001D5830, 4");
__asm__(".extern D_001D5834, 4");
void func_003856B8(void) {
    f32 scr[4];
    f32 pos[2];
    V4_3813E0 v;
    s32 rgb4[4];
    s32 clr2[4];
    u8 *obj;
    P_3813E0 *info;
    f32 total, part, zoom, size;
    s32 i;
    if (D_001A4BE0.f1430 == 0 && D_001A4BE0.f1464 == 0.0f) return;
    if (D_001A4BE0.f1430 != (s32)D_001A4BE0.f1460) {
        func_003C4138(&D_001A4BE0.f1464, 0.0f, D_001D57D4 * 0.020000001f);
        if (D_001A4BE0.f1464 <= 0.0f) D_001A4BE0.f1460 = (u8 *)D_001A4BE0.f1430;
    } else if (D_001A4BE0.f1430 != 0 && D_001A4BE0.f1464 < 1.0f) {
        func_003C4138(&D_001A4BE0.f1464, 1.0f, D_001D57D4 * 0.020000001f);
        D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_0038DAB8)(D_001A4BE0.f1468, D_001D5808 * 0.017453292f * 0.020000001f);
    }
    D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_0038DAB8)(D_001A4BE0.f1468, D_001D5808 * 0.017453292f * 0.020000001f);
    obj = D_001A4BE0.f1460;
    if (obj == 0) return;
    if (D_001A4BE0.f1464 == 0.0f) return;
    part = 0.0f;
    info = func_00382348(obj);
    total = part;
    if (info != 0) {
        func_0038CF68((s32)&v, (s32)(obj + 0xE0), info->f10);
        vec_add_ab(&v, &v, obj + 0x10);
        total = (f32)info->h4;
        part = info->f0;
    } else {
        v = *(V4_3813E0 *)(obj + 0x10);
    }
    zoom = 0.75f;
    func_003860A8(scr, &v);
    pos[0] = (scr[0] - (f32)D_001D4BD0_003856B8) * 0.0625f;
    pos[1] = (scr[1] - (f32)D_001D4BD4_003856B8) * 0.0625f;
    if (info != 0) zoom = info->f10;
    if (zoom > 2.0f) zoom = 2.0f;
    size = func_0038D160(func_0038CF00(D_00222480, obj + 0x10), zoom) * D_001D57C8;
    if (size > D_001D57CC) size = D_001D57CC;
    else if (size < D_001D57D0) size = D_001D57D0;
    for (i = 0; i < 3; i++) {
        f32 ang, sc;
        long tex;
        s32 rgba;
        switch (i) {
        case 0: ang = D_001A4BE0.f1468; break;
        case 1: ang = -D_001A4BE0.f1468; break;
        case 2: default: ang = D_001D5804 * 0.017453292f; break;
        }
        tex = func_00389598(i + 0x33);
        rgba = ((s32 (*)(s32, s32, f32))func_0038DBD8)((&D_001D57E8)[i], (&D_001D57D8)[i], D_001A4BE0.f1464);
        sc = (((&D_001D57F8)[i] - 1.0f) * (1.0f - D_001A4BE0.f1464) + 1.0f) * size;
        func_0038BCD8(pos[0], pos[1], sc, sc, ang, 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038BCD8(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_0038DAB8)(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038BCD8(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_0038DAB8)(ang, 3.1415927f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_0038BCD8(pos[0], pos[1], sc, sc, func_0038DB00(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
    }
    if (total != 0.0f) {
        long x, y;
        f32 half;
        f32 half2;
        s32 rgba;
        clr2[0] = D_001D5810;
        clr2[1] = D_001D5814;
        clr2[2] = D_001D5818;
        clr2[3] = D_001D581C;
        rgba = ((s32 (*)(s32, s32, f32))func_0038DBD8)(D_001D5828 & 0xFFFFFF, D_001D5828, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        x = (s32)scr[0];
        y = (s32)scr[1];
        half = D_001D5834 * func_0038D160(D_001D5830, total);
        func_0038C500(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2, D_001D580C, 0x10, half, -half);
        rgba = ((s32 (*)(s32, s32, f32))func_0038DBD8)(D_001D582C & 0xFFFFFF, D_001D582C, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        half2 = half - (half + half) * (part / total);
        func_0038C500(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2, D_001D580C, 0x10, half, half2);
    }
}
/* localdecomp:end func_003856B8 */

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
/* localdecomp:start func_003860A8 */
typedef struct {
    float unk0;
    float unk4;
    float unk8;
} ScreenPoint279BD8_3860A8;
typedef struct {
    char pad_0[0x30];
    float v30;
    float v34;
    float v38;
    char pad_3C[4];
    float v40;
    char pad_44[0x3C];
    char blk80[0x0C];
    float v8C;
    float v90;
    float v94;
    float v98;
    float v9C;
} Locals279BD8_3860A8;


void func_003860A8(f32 *screen_out_f, void *world_pos)
{
    ScreenPoint279BD8_3860A8 *screen_out = (ScreenPoint279BD8_3860A8 *)screen_out_f;
    Locals279BD8_3860A8 L;
    float scale;
    float y;
    float x;
    func_0038D2A0(&L);
    L.v30 = -D_002222C0_003860A8.f140 * 1024.0f;
    L.v34 = -D_002222C0_003860A8.f144 * 1024.0f;
    L.v38 = -D_002222C0_003860A8.f148 * 1024.0f;
    func_0038D640(&L.v40, (char *)&D_002222C0_003860A8 + 0x40, &L);
    func_0038CE20((f32 *)&L.blk80, world_pos, 1024.0f);
    L.v8C = 1.0f;
    func_0038D028(&L.v90, &L.blk80, &L.v40);
    scale = D_00225900_003860A8.f220 / L.v9C;
    x = L.v90 * scale + D_00225900_003860A8.f1A0;
    y = L.v94 * scale + D_00225900_003860A8.f1A4;
    screen_out->unk8 = L.v98 * 0.0009765625f;
    L.v90 = x;
    L.v94 = y;
    screen_out->unk0 = x * 16.0f;
    screen_out->unk4 = y * 16.0f;
}
/* localdecomp:end func_003860A8 */

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
/* localdecomp:start func_003865A0 */
extern unsigned char *D_001D9D40_003865A0 __attribute__((section(".sdata")));


int func_003865A0(int a0, int a1, int a2)
{
    unsigned char *base = D_001D9D40_003865A0;
    unsigned char *end = base + *(int *)base;
    unsigned short *node = (unsigned short *)(base + 4);
    int i2;
    int i1;
    int i0;
    i2 = a2 - node[0];
    if (i2 < 0) return 0;
    if (!(i2 < node[1])) return 0;
    if (!node[i2 + 2]) return 0;
    node = (unsigned short *)(base + node[i2 + 2] * 4);
    i1 = a1 - node[0];
    if (i1 < 0) return 0;
    if (!(i1 < node[1])) return 0;
    if (!node[i1 + 2]) return 0;
    node = (unsigned short *)(base + node[i1 + 2] * 4);
    i0 = a0 - node[0];
    if (i0 < 0 || !(i0 < node[1])) return 0;
    if (node[i0 + 2] == 0xFFFF) return 0;
    return (int)(end + node[i0 + 2] * 128);
}
/* localdecomp:end func_003865A0 */

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

/* localdecomp:start func_003873C0 */
/* from rac2-decomp's func_0027AB40 */
typedef int Q_003873C0 __attribute__((mode(TI)));
typedef union { Q_003873C0 q; f32 f[4]; s32 i[4]; } V_003873C0;
typedef struct {
    s32 fog_color; s32 unk4; s32 unk8; s32 unkC;     /* 0x00 */
    V_003873C0 regs[5];                               /* 0x10 */
    V_003873C0 gif[4];                                /* 0x60 */
    f32 near_clip, far_clip, aspect_x, aspect_y;      /* 0xA0 */
    V_003873C0 fov;                                   /* 0xB0 */
    f32 proj[16];                                     /* 0xC0 */
    f32 proj2[16];                                    /* 0x100 */
    f32 proj3[16];                                    /* 0x140 */
    V_003873C0 inverse_screen_scale;                  /* 0x180 */
    V_003873C0 screen_scale;                          /* 0x190 */
    V_003873C0 screen_bias;                           /* 0x1A0 */
    V_003873C0 inverse_projection_scale;              /* 0x1B0 */
    V_003873C0 viewport_aspect;                       /* 0x1C0 */
    V_003873C0 inverse_viewport_aspect;               /* 0x1D0 */
    V_003873C0 aspect_scale;                          /* 0x1E0 */
    V_003873C0 clip_scale;                            /* 0x1F0 */
    V_003873C0 clip_distances;                        /* 0x200 */
    f32 half_width, half_height, scr_x, scr_y;        /* 0x210 */
    f32 fog_mul, fog_add, fog_near_dist, fog_far_dist; /* 0x220 */
    f32 fog_slope, fog_base, fog_near_int, fog_far_int; /* 0x230 */
    u8 pad240[0x28];
    s32 f268;                                         /* 0x268 */
} S_003873C0;
typedef struct { s32 pal; u8 pad4[0xA9]; u8 fAD; } P_003873C0;
typedef struct { u8 pad[0x28]; s32 mul, max, far_int, near_int; u8 pad38[8]; V_003873C0 scale, bias; } F_003873C0;
typedef struct { u8 pad[0x10]; s32 mul, far_int, near_int; u8 pad1c[0x44]; V_003873C0 constants[3]; u8 pad90[0x10]; s32 x, y; } T_003873C0;

extern S_003873C0 D_00225900_003873C0;
extern P_003873C0 D_00143950_003873C0;
extern s32 D_001D5B98;
extern s32 D_001D5B94;
extern V_003873C0 D_00225BC0[4];
extern f32 D_001D9A10[];
extern f32 D_00335D50[];
extern f32 D_001D7B10;
__asm__(".extern D_001D7B10, 16");
extern F_003873C0 D_00335150;
extern F_003873C0 D_00335100;
extern T_003873C0 D_00334F00;
extern f32 D_001D75A0[4];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern void func_003CEDF8(void);
extern void func_0038CC88();

void func_003873C0(void) {
    S_003873C0 *view;
    S_003873C0 *clip_view;
    f32 depth_scale;
    f32 depth_bias;
    f32 horizontal_clip_scale;
    f32 vertical_clip_scale;
    f32 fog_distance_range;
    f32 fog_intensity_range;
    f32 fog_distance_slope;
    f32 near_clip;
    f32 far_clip;
    f32 fog_multiplier;
    f32 projection_fog_multiplier;
    f32 horizontal_fov;
    f32 vertical_fov;
    f32 viewport_width;
    f32 viewport_height;
    s32 near_bits;
    s32 far_bits;
    s32 mul_bits;

    depth_scale = -8388080.0f;
    depth_bias = 8388112.0f;
    if (D_00143950_003873C0.pal != 0) {
        D_00225900_003873C0.fov.f[1] = D_00225900_003873C0.fov.f[0] * 0.756f;
    } else {
        D_00225900_003873C0.fov.f[1] = D_00225900_003873C0.fov.f[0] * 0.775f;
    }
    if (D_00143950_003873C0.fAD || (D_001D5B98 == 1 && D_00225900_003873C0.f268 != 0)) {
        D_00225900_003873C0.fov.f[1] /= 1.3333333f;
    }
    view = &D_00225900_003873C0;
    view->aspect_x = view->scr_x / view->half_width;
    view->aspect_y = view->scr_y / view->half_height;
    view->fov.f[2] = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[0]));
    view->fov.f[3] = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[1]));
    horizontal_clip_scale = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[0] * view->aspect_x));
    vertical_clip_scale = 1.0f / func_0038D098(func_0038D160(1.0f, view->fov.f[1] * view->aspect_y));
    horizontal_clip_scale /= view->fov.f[2];
    vertical_clip_scale /= view->fov.f[3];
    horizontal_clip_scale += vertical_clip_scale;
    horizontal_clip_scale *= 0.5f;
    if (D_001D5B94 == 2 && view->fov.f[0] < 0.62f)
        horizontal_clip_scale *= 1.15f;
    clip_view = &D_00225900_003873C0;
    clip_view->aspect_scale.f[2] = 1.0f / clip_view->aspect_x;
    clip_view->aspect_scale.f[3] = 1.0f / clip_view->aspect_y;
    clip_view->clip_scale.f[0] = clip_view->fov.f[2];
    clip_view->clip_scale.f[1] = clip_view->fov.f[3];
    clip_view->clip_scale.f[2] = horizontal_clip_scale;
    clip_view->clip_distances.f[0] = clip_view->far_clip;
    clip_view->clip_distances.f[1] = clip_view->near_clip;
    clip_view->aspect_scale.f[0] = clip_view->aspect_x;
    clip_view->aspect_scale.f[1] = clip_view->aspect_y;
    D_00225BC0[0].q = clip_view->fov.q;
    D_00225BC0[1].q = clip_view->aspect_scale.q;
    D_00225BC0[2].q = clip_view->clip_scale.q;
    D_00225BC0[3].q = clip_view->clip_distances.q;

    if (clip_view->fog_far_dist < clip_view->fog_near_dist + 1024.0f)
        clip_view->fog_far_dist = clip_view->fog_near_dist + 1024.0f;

    far_bits = *(s32 *)&clip_view->fog_far_int;
    near_bits = *(s32 *)&clip_view->fog_near_int;
    fog_distance_range = clip_view->fog_far_dist - clip_view->fog_near_dist;
    fog_intensity_range = clip_view->fog_far_int - clip_view->fog_near_int;
    fog_multiplier = fog_intensity_range * clip_view->near_clip / fog_distance_range;
    fog_distance_slope = fog_intensity_range / (fog_distance_range / 1024.0f);
    clip_view->fog_add =
        (clip_view->fog_near_int * clip_view->fog_far_dist - clip_view->fog_far_int * clip_view->fog_near_dist) /
        fog_distance_range;
    clip_view->fog_slope = fog_distance_slope;
    clip_view->fog_base = clip_view->fog_near_int - clip_view->fog_near_dist / 1024.0f * fog_distance_slope;
    clip_view->fog_mul = fog_multiplier;
    D_001D7B10 = fog_multiplier;
    D_00335D50[0] = fog_multiplier;
    D_001D9A10[0] = fog_multiplier;
    mul_bits = *(s32 *)&clip_view->fog_mul;
    D_00334F00.mul = mul_bits;
    D_00334F00.far_int = far_bits;
    D_00334F00.near_int = near_bits;
    D_00335100.mul = mul_bits;
    D_00335100.far_int = far_bits;
    D_00335100.near_int = near_bits;
    D_00335150.mul = mul_bits;
    D_00335150.far_int = far_bits;
    D_00335150.near_int = near_bits;
    D_00335100.max = 0x437EFFFF;
    D_00335150.max = 0x437EFFFF;
    func_003CEDF8();

    near_clip = clip_view->near_clip;
    far_clip = clip_view->far_clip;
    horizontal_fov = clip_view->fov.f[0];
    vertical_fov = clip_view->fov.f[1];
    viewport_width = clip_view->half_width;
    viewport_height = clip_view->half_height;
    projection_fog_multiplier = clip_view->fog_mul;
    D_001D75A0[0] = 0.5f / 210000.0f;
    D_001D75A0[1] = -0.5f / 210000.0f;
    D_001D75A0[2] = 0.5f;
    D_001D75A0[3] = viewport_width / (horizontal_fov * 210000.0f);
    clip_view->proj[0] = viewport_width / (horizontal_fov * near_clip);
    clip_view->proj[1] = 0.0f;
    clip_view->proj[2] = 0.0f;
    clip_view->proj[3] = 0.0f;
    clip_view->proj[4] = 0.0f;
    clip_view->proj[5] = viewport_height / (vertical_fov * near_clip);
    clip_view->proj[6] = 0.0f;
    clip_view->proj[7] = 0.0f;
    clip_view->proj[8] = 0.0f;
    clip_view->proj[9] = 0.0f;
    clip_view->proj[10] = (far_clip + near_clip) / (near_clip * (far_clip - near_clip)) * depth_scale;
    clip_view->proj[11] = 1.0f / near_clip * projection_fog_multiplier;
    clip_view->proj[12] = 0.0f;
    clip_view->proj[13] = 0.0f;
    clip_view->proj[14] = -2.0f * near_clip * far_clip / (near_clip * (far_clip - near_clip)) * depth_scale;
    clip_view->proj[15] = 0.0f;
    func_0038CC88(clip_view->proj2, clip_view->proj, 0x40);
    clip_view->proj2[11] = 1.0f / clip_view->near_clip;
    func_0038CC88(clip_view->proj3, clip_view->proj2, 0x40);
    clip_view->proj3[0] /= clip_view->scr_x;
    clip_view->proj3[5] /= clip_view->scr_y;
    clip_view->proj3[10] /= depth_scale;
    clip_view->proj3[14] /= depth_scale;
    clip_view->inverse_screen_scale.f[0] = 1.0f / clip_view->scr_x;
    clip_view->inverse_screen_scale.f[1] = 1.0f / clip_view->scr_y;
    clip_view->inverse_screen_scale.f[2] = 1.0f / depth_scale;
    clip_view->inverse_screen_scale.f[3] = 1.0f / clip_view->fog_mul;
    clip_view->screen_scale.f[0] = clip_view->scr_x;
    clip_view->screen_scale.f[1] = clip_view->scr_y;
    clip_view->screen_scale.f[2] = depth_scale;
    clip_view->screen_scale.f[3] = clip_view->fog_mul;
    clip_view->inverse_projection_scale.f[0] = clip_view->scr_x / clip_view->proj[0];
    clip_view->inverse_projection_scale.f[1] = clip_view->scr_y / clip_view->proj[5];
    clip_view->inverse_projection_scale.f[2] = depth_scale / clip_view->proj[10];
    clip_view->inverse_projection_scale.f[3] = clip_view->fog_mul;
    clip_view->screen_bias.f[2] = depth_bias;
    clip_view->screen_bias.f[3] = clip_view->fog_add;
    clip_view->viewport_aspect.f[0] = clip_view->scr_x / clip_view->half_width;
    clip_view->viewport_aspect.f[1] = clip_view->scr_y / clip_view->half_height;
    clip_view->viewport_aspect.f[2] = 1.0f;
    clip_view->viewport_aspect.f[3] = 1.0f;
    clip_view->inverse_viewport_aspect.f[0] = 1.0f / clip_view->viewport_aspect.f[0];
    clip_view->inverse_viewport_aspect.f[1] = 1.0f / clip_view->viewport_aspect.f[1];
    clip_view->inverse_viewport_aspect.f[2] = 1.0f;
    clip_view->inverse_viewport_aspect.f[3] = 1.0f;
    clip_view->fog_color = *(s32 *)&clip_view->fog_far_int;
    clip_view->unk4 = 0x103E4000;
    clip_view->unk8 = 0xE;
    clip_view->unkC = 0;

    clip_view->gif[0].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[0].i[1] = 0x303E4000;
    clip_view->gif[0].i[2] = 0x412;
    clip_view->gif[0].i[3] = 0x303EC000;
    clip_view->gif[1].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[1].i[1] = 0x302E4000;
    clip_view->gif[1].i[2] = 0x412;
    clip_view->gif[1].i[3] = 0x302EC000;
    clip_view->gif[2].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[2].i[1] = 0x20364000;
    clip_view->gif[2].i[2] = 0x41;
    clip_view->gif[2].i[3] = 0;
    clip_view->gif[3].i[0] = *(s32 *)&clip_view->fog_mul;
    clip_view->gif[3].i[1] = 0x20264000;
    clip_view->gif[3].i[2] = 0x41;
    clip_view->gif[3].i[3] = 0;
    clip_view->regs[0].q = clip_view->gif[0].q;
    clip_view->regs[1].q = clip_view->viewport_aspect.q;
    clip_view->regs[2].q = clip_view->inverse_screen_scale.q;
    clip_view->regs[3].q = clip_view->screen_scale.q;
    clip_view->regs[4].q = clip_view->screen_bias.q;
    D_00334F00.constants[0].q = clip_view->screen_bias.q;
    D_00334F00.constants[1].q = clip_view->inverse_screen_scale.q;
    D_00334F00.constants[2].q = clip_view->screen_scale.q;
    D_00334F00.x = clip_view->viewport_aspect.i[0];
    D_00334F00.y = clip_view->viewport_aspect.i[1];
    D_00335150.scale.q = clip_view->screen_scale.q;
    D_00335150.bias.q = clip_view->screen_bias.q;
}
/* localdecomp:end func_003873C0 */

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

/* localdecomp:start func_00388258 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00388258;
typedef struct { V_00388258 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_00388258;
typedef struct { u8 p0[0x24]; f32 f24, f28; u8 p2C[8]; f32 f34, f38; s32 f3C; } O_00388258;
extern f32 D_001D59B0, D_001D59B4, D_001D59BC;
extern s32 D_001D59B8;
extern f32 D_001D5948, D_001D5958;
extern f32 D_001D594C, D_001D5950, D_001D5954, D_001D595C, D_001D5960, D_001D5964;
__asm__(".extern D_001D59B0, 4");
__asm__(".extern D_001D59B4, 4");
__asm__(".extern D_001D59B8, 4");
__asm__(".extern D_001D59BC, 4");
__asm__(".extern D_001D5948, 4");
__asm__(".extern D_001D5958, 4");
extern V_00388258 D_00222480_00388258;
extern s32 func_0038CAD0(void *);
extern void func_003C4098_00388258(V_00388258 *, V_00388258, V_00388258, f32);
extern void func_0038CE90_00388258(V_00388258 *, V_00388258, V_00388258);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003D2DA0(void *, s32, s32);
extern s32 func_00382498(s32 lo, s32 hi);
void func_00388258(void *o, void *q, long tex) {
    O_00388258 *obj = o;
    V_00388258 *quad = q;
    P_00388258 p;
    V_00388258 t0, t1;
    V_00388258 n, d;
    f32 s, dot;
    if (func_0038CAD0(&obj->f3C) == 0) {
        return;
    }
    p.c = 0xFF90UL << 32 | 0x260;
    p.tex = tex;
    p.a = 5;
    p.d = 0x8000UL << 24 | 0x44;
    p.rgba[3] = D_001D59B8;
    p.rgba[2] = D_001D59B8;
    p.rgba[1] = D_001D59B8;
    p.rgba[0] = D_001D59B8;
    t0 = quad[0]; t1 = quad[1];
    func_003C4098_00388258(&p.pos[0], t0, t1, obj->f38 - D_001D59B0);
    t0 = quad[0]; t1 = quad[1];
    func_003C4098_00388258(&p.pos[1], t0, t1, obj->f38 + D_001D59B0);
    t0 = quad[2]; t1 = quad[3];
    func_003C4098_00388258(&p.pos[2], t0, t1, obj->f38 - D_001D59B0);
    t0 = quad[2]; t1 = quad[3];
    func_003C4098_00388258(&p.pos[3], t0, t1, obj->f38 + D_001D59B0);
    {
        vu0_q q0, q1, q2, q3, y0, y2;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(quad[1]));
        __asm__("lqc2 %0, %1" : "=j"(q0) : "m"(quad[0]));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(quad[2]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y0) : "j"(q1), "j"(q0));
        __asm__("lqc2 %0, %1" : "=j"(q3) : "m"(quad[0]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y2) : "j"(q2), "j"(q3));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(y0));
        __asm__("sqc2 %1, %0" : "=m"(t1) : "j"(y2));
    }
    func_0038CE90_00388258(&n, t0, t1);
    vec_sub_ba(&d, &D_00222480_00388258, &quad[0]);
    dot = func_0038CE68(&n, &d);
    s = D_001D59BC;
    if (!(dot > 0.0f)) {
        s = -s;
    }
    func_0038CF68((s32)&n, (s32)&n, s);
    vec_add_ab(&p.pos[0], &p.pos[0], &n);
    vec_add_ab(&p.pos[1], &p.pos[1], &n);
    vec_add_ba(&p.pos[2], &p.pos[2], &n);
    vec_add_ab(&p.pos[3], &p.pos[3], &n);
    p.uv[0][0] = obj->f24 * D_001D5948 + 0.5f + D_001D59B4;
    p.uv[1][0] = obj->f24 * D_001D594C + 0.5f + D_001D59B4;
    p.uv[2][0] = obj->f24 * D_001D5950 + 0.5f - D_001D59B4;
    p.uv[3][0] = obj->f24 * D_001D5954 + 0.5f - D_001D59B4;
    p.uv[0][1] = obj->f28 * func_003C4088(D_001D5958, D_001D595C, obj->f38 - D_001D59B0) + 0.5f;
    p.uv[1][1] = obj->f28 * func_003C4088(D_001D595C, D_001D5958, obj->f38 - D_001D59B0) + 0.5f;
    p.uv[2][1] = obj->f28 * func_003C4088(D_001D5960, D_001D5964, obj->f38 - D_001D59B0) + 0.5f;
    p.uv[3][1] = obj->f28 * func_003C4088(D_001D5964, D_001D5960, obj->f38 - D_001D59B0) + 0.5f;
    func_003D2DA0(&p, 0, 0);
    obj->f38 += obj->f34;
    if (obj->f34 > 0.0f) {
        if (obj->f38 >= 1.0f - D_001D59B0) {
            obj->f38 -= 1.0f;
            obj->f3C = (func_00382498(30, 120) * 5 + 2) / 6;
        }
        if (obj->f38 < D_001D59B0) {
            obj->f38 = D_001D59B0;
        }
    } else {
        if (obj->f38 <= D_001D59B0) {
            obj->f38 += 1.0f;
            obj->f3C = (func_00382498(30, 120) * 5 + 2) / 6;
        }
        if (obj->f38 >= 1.0f - D_001D59B0) {
            obj->f38 = 1.0f - D_001D59B0;
        }
    }
}
/* localdecomp:end func_00388258 */

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
/* localdecomp:start func_003886B0 */
typedef int Q_003886B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003886B0;
typedef struct { u8 p[0x34]; u16 flags; u8 tail[0xCA]; } M_003886B0;
typedef struct {
    u128_t pos;
    f32 rot[4];
    Q_003886B0 *verts;
    f32 sx, sy;
    s32 count;
    s32 overlay;
    u8 p34[0xC];
    M_003886B0 *mobys[4];
} O_003886B0;
typedef struct { u8 p[0x50]; O_003886B0 *obj; } C_003886B0;
typedef struct { Q_003886B0 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_003886B0;
extern C_003886B0 D_00225700_003886B0;
extern f32 D_00225900_003886B0[];
extern V_003886B0 D_002FF580_003886B0[];
extern V_003886B0 D_001D5970_003886B0[] __attribute__((section(".sdata")));
extern V_003886B0 D_001D5980_003886B0[] __attribute__((section(".sdata")));
extern V_003886B0 D_001D5990_003886B0[] __attribute__((section(".sdata")));
extern V_003886B0 D_001D59A0_003886B0[] __attribute__((section(".sdata")));
extern f32 D_001D5948_003886B0[] __attribute__((section(".sdata")));
extern f32 D_001D5958_003886B0[] __attribute__((section(".sdata")));
extern s32 D_001D59C0;
__asm__(".extern D_001D59C0, 4");
__asm__(".extern D_001D5970_003886B0, 4");
__asm__(".extern D_001D5980_003886B0, 4");
__asm__(".extern D_001D5990_003886B0, 4");
__asm__(".extern D_001D59A0_003886B0, 4");
__asm__(".extern D_001D5948_003886B0, 4");
__asm__(".extern D_001D5958_003886B0, 4");
extern s32 D_001DA49C_003886B0;
__asm__(".extern D_001DA49C_003886B0, 16");
extern long D_001D4C30_003886B0;
__asm__(".extern D_001D4C30_003886B0, 16");
extern void func_00381C98_003886B0(void);
extern s32 func_00381CA0(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_003C3860(void);
extern void func_003C6F90_003886B0(u8 *, s32, s32, s32, s32);
extern void func_003C3780(s32, s32);
extern void func_0012FF40(void *);
extern void func_00130088(void *, void *, f32);
extern void func_00130130(void *, void *, f32);
extern void func_0012FFE0(void *, void *, f32);
extern void func_00388258(void *, void *, long);
extern void func_003A9618(void);
extern void func_003873C0();
extern void func_003881B0(s32, s32);
extern void func_00388238(void);
extern void func_003861F0(void);

/* a vector assignment (the vector type's copy) */
static __inline__ void qcopy_003886B0(Q_003886B0 *dst, Q_003886B0 *src) { *dst = *src; }

void func_003886B0(void) {
    M_003886B0 copies[4];
    f32 saved[16];
    union { u128_t q; f32 f[4]; } pos;
    f32 mat[16];
    P_003886B0 packet;
    O_003886B0 *o;
    M_003886B0 *m;
    M_003886B0 *dst;
    s32 i, n, j, k, v;
    f32 old;

    func_00381C98_003886B0();
    o = D_00225700_003886B0.obj;
    if (o != 0) {
        func_003C36C0();
        n = 0;
        func_003C3638();
        func_003C3660();
        for (i = 0; i < 4; i++) {
            m = o->mobys[i];
            if (m != 0) {
                func_003C6F90_003886B0((u8 *)m, 0x404040, 14, 0, 0);
                n++;
                m->flags |= 1;
            } else {
                break;
            }
        }
        func_003C3780(D_001DA49C_003886B0, -1);
        for (i = 0; i < 4; i++) {
            m = o->mobys[i];
            if (m != 0) {
                m->flags &= ~1;
            } else {
                break;
            }
        }
        func_0038CD28(saved, &D_00222400[2], 0x40);
        pos.q = D_00222400[0];
        old = D_00225900_003886B0[0xB0 / 4];
        ((void (*)(s32, s32, f32))func_003881B0)(8, 8, 1.0f);
        func_0012FF40(mat);
        func_00130088(mat, mat, o->rot[0]);
        func_00130130(mat, mat, o->rot[1]);
        func_0012FFE0(mat, mat, o->rot[2]);
        func_0038CD28(&D_00222400[2], mat, 0x40);
        D_00222400[0] = o->pos;
        func_003861F0();
        D_002FF580_003886B0[0] = D_001D5970_003886B0[0];
        D_002FF580_003886B0[2] = D_001D5980_003886B0[0];
        D_002FF580_003886B0[1] = D_001D5990_003886B0[0];
        D_002FF580_003886B0[3] = D_001D59A0_003886B0[0];
        if (n == 1) {
            func_003C3780((s32)o->mobys[0], 1);
        } else {
            dst = copies;
            for (i = 0; i < 4; i++) {
                m = o->mobys[i];
                if (m != 0) {
                    func_0038CD28(dst, m, 0x100);
                    dst++;
                }
            }
            func_003C3780((s32)copies, n);
        }
        func_00388238();
        D_00225900_003886B0[0xB0 / 4] = old;
        func_003873C0();
        func_0038CD28(&D_00222400[2], saved, 0x40);
        D_00222400[0] = pos.q;
        func_003861F0();
        func_003A9440(0x42, 0x8000000044UL);
        func_003A9440(8, 5);
        func_003A9618();
        func_003C3690();
        func_003C3800();
        j = 0;
        for (k = 0; k < D_00225700_003886B0.obj->count; k++) {
            packet.tex = D_001D4C30_003886B0;
            packet.c = 0xFF9000000260UL;
            packet.a = 5;
            packet.d = 0x8000000044UL;
            packet.rgba[3] = D_001D59C0;
            packet.rgba[2] = D_001D59C0;
            packet.rgba[1] = D_001D59C0;
            packet.rgba[0] = D_001D59C0;
            for (v = 0; v < 4; v++) {
                packet.uv[v][0] = o->sx * D_001D5948_003886B0[v] + 0.5f;
                packet.uv[v][1] = o->sy * D_001D5958_003886B0[v] + 0.5f;
                qcopy_003886B0(&packet.pos[v], &o->verts[j + v]);
            }
            func_003D2DA0(&packet, 0, 0);
            if (o->overlay) {
                func_00388258(o, o->verts + j, D_001D4C30_003886B0);
            }
            j += 4;
        }
    } else {
        func_003C3860();
    }
    func_00381CA0();
}
/* localdecomp:end func_003886B0 */

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
/* localdecomp:start func_00388AF8 */
__asm__(".extern D_001D58D0, 4");
__asm__(".extern D_001D5884, 1");
extern void func_0038C9B0(void);
extern void func_0038A518(void);

void func_00388AF8(s32 arg0) {
    s32 t;
    s32 t2;
    f32 d, n;
    u128_00384420 *src, *dst;

    if (D_001DA5F0 == 0 || D_001DA5F0->x4 != 0 || ((*(u8 *)&D_001D9BC4 ^ 1) & 1)) {
        func_00392350(0);
    }
    func_003861F0();
    func_003C2DC0();
    func_00387218();
    func_00387F68();
    D_001D9D1C = -1;
    D_001D9348 = 0;
    D_001D934C = 0;
    if (D_001DA5F0 != 0 && (D_001D9BC4 & 1)) {
        func_0038C9B0();
    }
    if (D_001D9BC4 & 2) {
        func_003CF0F0();
    }
    func_003A9C70_00388AF8(0x2010000);
    if (D_001D9BC4 & 4) {
        func_003D9CF0();
    }
    func_003A9C70_00388AF8(0x2020000);
    if ((D_001D9BC4 & 0x20) && D_001D9C10_00388AF8 != 0) {
        func_003A96D8();
        func_00389240(1);
        func_00389E28();
        func_00389370();
        func_003A9678();
    }
    if (D_001D9BC4 & 8) {
        func_003DEF28();
    }
    func_003A9C70_00388AF8(0x2040000);
    if (D_001D58D0) {
        func_0038AD40_00388AF8(&D_001D58D0);
    }
    if ((D_001D9BC4 & 0x20) && D_001D9C14_00388AF8 != 0) {
        func_003A96D8();
        func_00389240(1);
        func_00389EA0();
        func_00389370();
        func_003A9678();
    }
    if (D_001D9BC4 & 0x10) {
        if (D_001D5B94 == 2) {
            func_003886B0();
        } else {
            func_003C3860();
        }
    }
    func_003A9C70_00388AF8(0x2080000);
    func_00389240(0);
    if (D_001D9BC4 & 0x20) {
        func_003A96D8();
        if (D_001D9C08_00388AF8 != 0) {
            func_00389DB0();
        }
        func_003A9440(0x42, 0x8000000048);
        func_00385020();
        func_003A96D8();
        func_0038A058();
        func_003A9440(8, 5);
        func_003A96D8();
        func_003A9440(0x47, 0x53001);
        func_11F0A0(0);
        func_003CD3D8();
        D_001D9D1C = 9;
        func_003A9440(0x47, 0x5360B);
        if (D_001D9C0C_00388AF8 != 0) {
            func_003A96D8();
            func_00389F68();
        }
        func_00389370();
        if (D_001D9348 != 0) {
            func_003D85C0_00388AF8(0);
            if (D_001D9348 != 0) {
                func_003D8640();
            }
        }
        if (D_001D9364 != 0) {
            func_003D9260_00388AF8(0);
        }
        t2 = D_001D9364;
        D_001D9364 = 0;
        D_001D9368 = t2;
        func_00389240(0);
        if (D_001D9C38_00388AF8 != 0) {
            func_003A96D8();
            func_00389FE0();
        }
        func_003A9440(0x42, 0x8000000044);
        func_00385D28(arg0);
        func_00389370();
    }
    func_003926E8();
    func_00389240(0);
    func_003A96D8();
    if ((D_001D9BC4 & 0x180) && func_003A0EA8(3) == 0) {
        func_003A9440(0x47, 0x33001);
        func_0038A948();
        if (D_001D9BC4 & 0x80) {
            func_003A9CA8_00388AF8(0);
            func_003AF660();
            t = D_001D9EC0;
            func_00396838();
            D_001D9EC0 = t;
            func_003B30E8();
            func_003B3158(D_001D52F0);
            func_003B3120();
            func_00381D60();
        }
    }
    if (D_001D5B94 == 2) {
        func_0038A518();
    }
    func_00389370();
    if (D_001D9BC4 & 0x40) {
        func_003A9440(0x42, 0x8000000044);
        if (((P_00384420 *)((u8 *)D_00222480_00388AF8 + arg0 * sizeof(P_00384420)))->x450 != 0) {
            func_0038AE20(D_001D5780, D_001D5781, D_001D5782, D_001D5783);
        }
        if (D_001D9BD0 > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD0 > 1.0f) {
                D_001D9BD0 = 1.0f;
            }
            func_0038AE20(0, 0, 0, D_001D9BD0 * 128.0f);
        }
        if (D_001D9BD8[0] > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD8[0] > 1.0f) {
                D_001D9BD8[0] = 1.0f;
            }
            func_0038AE20(0xFF, 0xFF, 0xFF, D_001D9BD8[arg0] * 128.0f);
        }
        if (D_001D5884 && D_001D58B8 != 0) {
            func_0038ABC0();
        }
    }
    func_003A8F90_00388AF8(D_100AE0);
    func_11F0A0(0);
    n = *(volatile u32 *)0x10000800;
    D_001D9D10 = n / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_003A92F0(2);
    if (D_001D9BC4 & 2) {
        func_003D0180(D_002FDC00);
        func_003CF050();
    }
    func_003A92F0(4);
    if (D_001D9BC4 & 4) {
        src = (u128_00384420 *)&D_00225AA0;
        dst = (u128_00384420 *)&D_00334EC0;
        dst[0] = src[0];
        dst[1] = src[-1];
        dst[2] = src[2];
        func_003DD768();
        func_003D9C30();
    }
    func_003A92F0(8);
    if (D_001D9BC4 & 8) {
        func_003E0B10(D_003064C0);
        func_003DEE20();
    }
    func_003A92F0(0x10);
    if (D_001D9BC4 & 0x10) {
        func_003C31B0();
    }
    func_003864C0(arg0);
    D_001D9D50_00388AF8 = 0;
}
/* localdecomp:end func_00388AF8 */

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
/* localdecomp:start func_00389370 */
/* from boot_elf's func_00389750 */
void func_00389370(void) {
    u32 *p = D_001DA050_00389370;
    D_001D9BF8_00389370 = p;
    p += 4;
    D_001DA050_00389370 = p;
    D_001D9BF4_00389370[0] = 0x20000000;
    D_001D9BF4_00389370[1] = (u32)D_001DA050_00389370;
    D_001D9BF4_00389370[2] = 0;
    D_001D9BF4_00389370[3] = 0;
    func_003A02E8();
    func_003A9618_00389370();
    D_001DA050_00389370[0] = 0x20000000;
    D_001DA050_00389370[1] = (u32)(D_001D9BF4_00389370 + 4);
    D_001DA050_00389370[2] = 0;
    D_001DA050_00389370[3] = 0;
    D_001DA050_00389370 += 4;
    D_001D9BF8_00389370[0] = 0x20000000;
    D_001D9BF8_00389370[1] = (u32)D_001DA050_00389370;
    D_001D9BF8_00389370[2] = 0;
    D_001D9BF8_00389370[3] = 0;
}
/* localdecomp:end func_00389370 */

/* localdecomp:start func_00389478 */
extern s8 D_00225B20[];

extern s32 D_001D4BC0;
extern s32 D_001D4BC4;

void func_00389478(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 sp[4];
    s8 *base;
    f32 den;
    f32 temp_f1;
    f32 temp_f2;
    base = (s8 *)D_00222400;
    vec_sub_ba(sp, arg0, base);
    func_0038CE20(sp, sp, 1024.0f);
    sp[3] = 1.0f;
    func_0038D028(sp, sp, base - 0x100);
    den = sp[3];
    func_0038CE20(sp, sp, *(f32 *)D_00225B20 / den);
    temp_f1 = sp[0] + (f32)(D_001D4BC0 >> 1);
    *arg1 = temp_f1;
    *arg1 = temp_f1 / (f32)D_001D4BC0;
    temp_f2 = sp[1] + (f32)(D_001D4BC4 >> 1);
    *arg2 = temp_f2;
    *arg2 = temp_f2 / (f32)D_001D4BC4;
}
/* localdecomp:end func_00389478 */
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
/* localdecomp:start func_00389598 */
extern s32 D_001A1ED0[];
extern s32 D_001D4BB0;
extern s32 D_001D9BFC_00389598;
extern s32 D_001D9C04;
__asm__(".extern D_001D58E0, 8");
__asm__(".extern D_001D58E8, 8");
__asm__(".extern D_001D58F0, 4");
extern unsigned long D_001D58E0;
extern unsigned long D_001D58E8;
extern s32 D_001D58F0;
/* the packet pointer, reloaded after every store */
extern u32 *D_001DA050_00389598[1];
extern u8 D_141AD0[];
extern u8 D_141DC0[];
long func_00389598(s32 i) {
    if (i < 0) {
        if (i == -5) {
            return ((unsigned long)(D_001A1ED0[2] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0x30) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -8) {
            return ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0x1B) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(D_001D58F0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(1) << 61));
        } else if (i == -7) {
            return ((unsigned long)(D_001A1ED0[0] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -6) {
            return ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -2 || i == -1) {
            s32 a;
            unsigned long t;
            if (D_001D58E0 != 0) return D_001D58E0;
            a = (D_001D4BB0 + 0x1FFF) & ~0x1FFF;
            D_001D4BB0 = a + 0x20000;
            D_001DA050_00389598[0][0] = 0x10000003;
            D_001DA050_00389598[0][1] = 0;
            D_001DA050_00389598[0][2] = 0;
            D_001DA050_00389598[0][3] = 0x50000003;
            D_001DA050_00389598[0][4] = 0x8001;
            D_001DA050_00389598[0][5] = 0x20000000;
            D_001DA050_00389598[0][6] = 0xEE;
            D_001DA050_00389598[0][7] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][8] = (long)(a >> 13) | 0x2040000;
            D_001DA050_00389598[0][10] = 0x4D;
            D_001DA050_00389598[0][11] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][12] = ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001DA050_00389598[0][14] = 7;
            D_001DA050_00389598[0][15] = 0;
            D_001DA050_00389598[0][16] = 0x3000002F;
            D_001DA050_00389598[0][17] = (u32)D_141AD0;
            D_001DA050_00389598[0][18] = 0;
            D_001DA050_00389598[0][19] = 0x5000002F;
            t = ((unsigned long)(a >> 8) | ((unsigned long)(4) << 14) | ((unsigned long)(2) << 20) | ((unsigned long)(8) << 26) |
                ((unsigned long)(8) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001D58E0 = t;
            D_001DA050_00389598[0] += 0x14;
            return t;
        } else if (i == -4 || i == -3) {
            s32 a;
            unsigned long t;
            if (D_001D58E8 != 0) return D_001D58E8;
            a = (D_001D4BB0 + 0x1FFF) & ~0x1FFF;
            D_001D4BB0 = a + 0x2000;
            D_001DA050_00389598[0][0] = 0x10000003;
            D_001DA050_00389598[0][1] = 0;
            D_001DA050_00389598[0][2] = 0;
            D_001DA050_00389598[0][3] = 0x50000003;
            D_001DA050_00389598[0][4] = 0x8002;
            D_001DA050_00389598[0][5] = 0x10000000;
            D_001DA050_00389598[0][6] = 0xEE;
            D_001DA050_00389598[0][7] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][8] = (long)(a >> 13) | 0x2010000;
            D_001DA050_00389598[0][10] = 0x4D;
            D_001DA050_00389598[0][11] = 0;
            *(unsigned long *)&D_001DA050_00389598[0][12] = ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001DA050_00389598[0][14] = 7;
            D_001DA050_00389598[0][15] = 0;
            D_001DA050_00389598[0][16] = 0x3000002F;
            D_001DA050_00389598[0][17] = (u32)D_141DC0;
            D_001DA050_00389598[0][18] = 0;
            D_001DA050_00389598[0][19] = 0x5000002F;
            t = ((unsigned long)(a >> 8) | ((unsigned long)(1) << 14) | ((unsigned long)(2) << 20) | ((unsigned long)(6) << 26) |
                ((unsigned long)(6) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001D58E8 = t;
            D_001DA050_00389598[0] += 0x14;
            return t;
        }
    } else {
        T_384EC0 *e = &D_00226000[i];
        if (e->v == 0) {
            s32 base = D_001D4BB0;
            s32 w;
            s32 b0, b1, n;
            unsigned long t;
            w = e->bC;
            w -= 6;
            if (w < 0) w = 0;
            b0 = base >> 8;
            base += 0x400;
            b1 = base >> 8;
            t = ((unsigned long)(b1) | ((unsigned long)(1 << w) << 14) | ((unsigned long)(e->hE) << 20) | ((unsigned long)(e->bC) << 26) |
                ((unsigned long)(e->bD) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(b0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(4) << 61));
            D_001D4BB0 = base + (1 << (e->bC + e->bD));
            e->v = t;
            if (0x3FF000 - D_001D934C < D_001D4BB0) return t;
            n = D_001D9BFC_00389598;
            if (n < 0x40) {
                C_384EC0 *c = &D_00225C00[n];
                c->w0 = D_001D9C04 + (e->hA << 6);
                c->h4 = 0;
                c->h6 = b0;
                D_00225C00[n].w8 = D_001D9C04 + (e->h8 << 6);
                c->bC = e->bC;
                c->bD = e->bD;
                c->hE = b1;
                D_001D9BFC_00389598 = n + 1;
            }
        }
    }
    return D_00226000[i].v;
}
/* localdecomp:end func_00389598 */

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

/* localdecomp:start func_0038A518 */
typedef struct { s16 start, end, text[7]; } R_0038A518;
typedef struct { u8 pad[0x34]; s32 time; u8 pad38[0x14]; u8 *subs; } S_0038A518;
extern S_0038A518 D_00225700_0038A518;
extern u8 D_00143950_0038A518[];
typedef struct { s32 w, h; } Z_0038A518;
extern Z_0038A518 D_001D4BC0_0038A518;
extern void func_00390E60_0038A518(s32, s32, unsigned long, u8 *, s32);
extern void func_00390FB0_0038A518(s32, s32, s32, u8 *, s32);
extern void func_003910C0_0038A518(u16 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00391130_0038A518(u16 *, unsigned long, u8 *, s32);
extern u32 func_11B868_0038A518(u8 *);
extern void func_0038C3B0_0038A518(s32, s32, s32, s32, s32, s32);

void func_0038A518(void) {
    R_0038A518 *end;
    R_0038A518 *p;
    s32 idx;
    s32 ty;
    s32 t, s, e;

    if (!D_00225700_0038A518.subs) return;
    idx = 0;
    if (D_00143950_0038A518[0xB7] == 5) idx = D_00143950_0038A518[0xB7] - 2;
    else if (D_00143950_0038A518[0xB7] == 4) idx = D_00143950_0038A518[0xB7];
    else if (D_00143950_0038A518[0xB7] >= 2 && D_00143950_0038A518[0xB7] < 6) idx = D_00143950_0038A518[0xB7] - 1;

    end = (R_0038A518 *)(D_00225700_0038A518.subs + ((R_0038A518 *)D_00225700_0038A518.subs)->text[0]);
    p = (R_0038A518 *)D_00225700_0038A518.subs;
    ty = 0xD0;
    for (; p < end; p++) {
        t = D_00225700_0038A518.time;
        s = (p->start * 5 + 2) / 6;
        if (t < s) continue;
        e = (p->end * 5 + 2) / 6;
        if (e < t) continue;
        if (!D_00143950_0038A518[6] && D_00225700_0038A518.subs[p->text[idx]] != '*') continue;
        if (D_00225700_0038A518.subs[p->text[idx]] == '*') {
            s32 y = 0x40;
            s32 alpha = 0xB0000000;
            s32 now;
            if (D_00225700_0038A518.subs[p->text[idx] + 1] != '*') y = D_001D4BC0_0038A518.h - 0xC8;
            else if (D_00143950_0038A518[0xAD]) y = 0x18;
            now = D_00225700_0038A518.time;
            if ((p->end * 5 + 2) / 6 - now < 0x12)
                alpha = (s32)((p->end * 5 + 2) / 6 - (long)(now - 1)) << 27;
            else if (now - (p->start * 5 + 2) / 6 < 0x12)
                alpha = (s32)(now - (long)((p->start * 5 + 2) / 6 - 1)) << 27;
            if ((D_00225700_0038A518.subs + p->text[idx])[1] != '*') {
                func_00390E60_0038A518(0x100, ty, alpha | 0xE0E0E0, (D_00225700_0038A518.subs + p->text[idx]) + 1, -1);
                ty += 0x14;
            } else {
                func_00390FB0_0038A518(0x20, y, alpha | 0xE0E0E0, (D_00225700_0038A518.subs + p->text[idx]) + 2, -1);
            }
        } else {
            u16 win[16];
            s32 fade = 0x80;
            s32 c, color, hh, hw, w, n;
            s32 ext = D_001D4BC0_0038A518.h;
            n = D_00143950_0038A518[0xAD] ? ext - 0x36 : ext - 0x64;
            if (e - t < 8) fade = (s32)(e - (long)(t - 1)) << 4;
            else if (t - s < 8) fade = (s32)(t - (long)(s - 1)) << 4;
            func_003910C0_0038A518(win, 0xC8, 0x1A4, 0x28, 0x1D8, 0x100,
                          n, 0x12, 7);
            color = fade + (fade >> 1);
            color = color | (color << 8) | (color << 16) | (fade << 24);
            func_00391130_0038A518(win, color, D_00225700_0038A518.subs + p->text[idx], -1);
            win[5] -= 4;
            hh = ((s16)win[7] >> 1) + 5;
            w = (s16)win[6] >> 1;
            hw = w + 10;
            if ((s16)win[5] + hh > D_001D4BC0_0038A518.h - 0x14)
                win[5] = D_001D4BC0_0038A518.h - (((s16)win[7] >> 1) + 0x19);
            win[9] &= ~4;
            if (func_11B868_0038A518(D_00225700_0038A518.subs + p->text[idx]) < 0x96) {
                func_0038C3B0_0038A518((s16)win[5] - hh, (s16)win[5] + hh, 0x100 - hw, 0x100 + hw,
                              (fade >> 1) + (fade >> 2), 0x40404);
                func_00391130_0038A518(win, color, D_00225700_0038A518.subs + p->text[idx], -1);
            }
            return;
        }
    }
}
/* localdecomp:end func_0038A518 */

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
