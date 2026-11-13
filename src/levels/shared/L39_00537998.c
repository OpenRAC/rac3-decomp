#include "common.h"

/* localdecomp:start func_L39_00537998 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 D_L39_0024AD90;
__asm__(".extern D_L39_0024AD90, 4");
extern s32 D_L39_0024112C;

u8 *func_L39_00537998(s32 a0, u8 *a1, u128_t *a2, u128_t *a3, s32 a4, s32 a5) {
    u8 *p;
    u8 *q;

    p = func_003C24B0(0x1099, 0x80);
    if (p != 0) {
        q = *(u8 **)(p + 0x68);
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0x7F;
        *(s32 *)(p + 0xB8) = a0;
        *(f32 *)(p + 0x2C) *= 0.5f;
        p[0x31] = 1;
        p[0x20] = 0;
        *(s16 *)(q + 0x36) = 0;
        if (a4 != 0) {
            *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * D_L39_0024AD90;
            *(u128_t *)q = *a3;
            q[0x51] = 1;
            *(s32 *)(q + 0x74) = a5;
        }
        *(u16 *)(q + 0x7C) = *(u16 *)(a1 + 0x2544);
        *(s32 *)(p + 0x90) = *(s32 *)a1;
        *(s32 *)(p + 0x78) = 0;
        *(u16 *)(p + 0x34) |= 0x10;
        *(u128_t *)(p + 0x10) = *a2;
        *(f32 *)(q + 0x38) = func_L39_005B4410(0.020943953f, 0.06283186f);
        {
            s32 d;
            f32 t = func_L39_005B4410(0.020943953f, 0.06283186f);
            f32 z = 0.0f;
            d = D_L39_0024112C;
            *(f32 *)(q + 0x64) = z;
            *(f32 *)(q + 0x3C) = t;
            *(f32 *)(q + 0x60) = z;
            *(f32 *)(q + 0x70) = z;
            *(f32 *)(q + 0x6C) = z;
            *(s32 *)(q + 0x5C) = d;
            *(s32 *)(q + 0x68) = -1;
        }
        *(s32 *)(p + 0x98) = 0;
        func_003C7C38(p);
    }
    return p;
}
/* localdecomp:end func_L39_00537998 */

INCLUDE_ASM("asm/levels", func_L39_00537B28);

/* localdecomp:start func_L39_00539268 */
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
} VT_00539268;
typedef struct {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x14 - 4];
    VT_00539268 *vt;
    u8 pad18[0x1A14 - 0x18];
    u8 b1A14;
} T_00539268;
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
    u8 padAC[0xBE - 0xAC];
    u8 bBE;
} O_00539268;
extern s32 func_L39_0061D7B0(void *);
extern s32 func_L39_005B8928(u8 *);

s32 func_L39_00539268(s32 mode, O_00539268 *obj, T_00539268 *t) {
    s32 id;

    if (obj == 0) {
        return 0;
    }
    if (t == 0) {
        t = (T_00539268 *)func_L39_0061D7B0(obj);
        if (t == 0) {
            if (mode == 0 && (obj->bBE & 8)) {
                return 1;
            }
            if (mode == 1 && (obj->bBE & 0x10)) {
                return 1;
            }
            return 0;
        }
    }
    if ((t->b3 & 0xF) == 0 && t->b1A14 == 0) {
        return 0;
    }
    if (t->vt->f1C(t, mode)) {
        return 0;
    }
    if (func_L39_005B8928((u8 *)obj) != 0) {
        return 0;
    }
    id = obj->hAA;
    if (id == 0x107C || id == 0x107E || id == 0x10C2 || id == 0x109D) {
        if (t->vt->f1C(t, -1) != 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00539268 */

INCLUDE_ASM("asm/levels", func_L39_00539398);

/* localdecomp:start func_L39_0053B6B0 */
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");
extern u8 D_L39_0025F760[];
extern s32 func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern s32 func_003D3CB0(f32 *, u8 *, s32, u8 *, s32);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_L39_005FED60(u8 *, f32, u8 *, u8 *, u8 *, u8 *, s32, s32, s32, s32, s32);
extern void func_L39_0053BA68(u8 *);
extern void func_L01_00404808(void *, void *);

s32 func_L39_0053B6B0(u8 *a0, u8 *a1, u8 *a2) {
    u8 *obj = 0;
    s32 r;
    f32 buf[4];
    if (*(u16 *)(a0 + 0x7C) < 8) {
        obj = D_L39_0024CE20[*(s16 *)(a0 + 0x7C)];
    }
    if (obj == 0) {
        return 0;
    }
    if (a1[0x20] != 0) {
        *(s16 *)(a0 + 0x36) = 1;
        return 0;
    }
    r = 0;
    if (obj[0x1A14] != 0) {
        func_L39_00632180(obj, buf, 1, 0.0f, 0.0f, 0.37f);
        if (func_003D3CB0(buf, a2, 0x32, a1, 0) != 0) {
            r = 1;
            func_0038CE20((f32 *)(a0 + 0x20), D_L39_0025F760 + 0x20, 0.0009765625f);
            *(u128_t *)(a0 + 0x10) = *(u128_t *)D_L39_0025F760;
        } else {
            r = func_L39_005FED60(obj, 0.00472f, a2, a0, a0 + 0x10, a0 + 0x20, *(s32 *)(a1 + 0xB8), 1, 0, (s32)(a0 + 0x78), 0);
        }
    }
    if (r != 0) {
        func_L01_00404808(func_L39_0053BA68, a1);
    }
    return r;
}
/* localdecomp:end func_L39_0053B6B0 */

INCLUDE_ASM("asm/levels", func_L39_0053B810);

/* localdecomp:start func_L39_0053BA68 */
extern void func_L39_005FE358(u8 *, u8 *, void *, s32, f32);
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");
extern s32 D_L39_00241118;

void func_L39_0053BA68(u8 *a0) {
    u8 *p;
    u8 *t;
    u16 idx;

    if (a0 == 0 || a0[0x20] == 0xFE) {
        return;
    }
    if (a0[0x20] == 0xFD) {
        return;
    }
    p = *(u8 **)(a0 + 0x68);
    if (p == 0) {
        return;
    }
    idx = *(u16 *)(p + 0x7C);
    t = 0;
    if (idx < 8) {
        t = D_L39_0024CE20[(s16)idx];
    }
    if (t == 0) {
        return;
    }
    if (t[0x24C9] != D_L39_00241118) {
        return;
    }
    if (*(s16 *)(p + 0x36) == 0) {
        func_L39_005FE358(p + 0x10, p + 0x20, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L39_0053BA68 */

INCLUDE_ASM("asm/levels", func_L39_0053BB08);

/* localdecomp:start func_L39_0053BE50 */
extern s16 D_L39_00293F38[][64];
extern u8 *D_L39_0024BF5C;

u8 *func_L39_0053BE50(s32 idx, s32 id) {
    s32 i;
    u8 *m;
    u8 *p;

    for (i = 1; i <= D_L39_00293F38[idx][0]; i++) {
        m = D_L39_0024BF5C + D_L39_00293F38[idx][i] * 256;
        p = *(u8 **)(m + 104);
        if (p != 0 && *(s16 *)(p + 126) == id) {
            return m;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0053BE50 */

INCLUDE_ASM("asm/levels", func_L39_0053BED0);

INCLUDE_ASM("asm/levels", func_L39_0053C110);

/* localdecomp:start func_L39_0053C1E8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_0053C1E8;
extern void func_0038CF68(void *, void *, f32);

void func_L39_0053C1E8(void *a0, void *a1, f32 a2)
{
    u8 *p = *(u8 **)((u8 *)a0 + 0x68);
    V_0053C1E8 *d = a1;
    V_0053C1E8 v;

    if (*(s16 *)(p + 0x36) != -1) {
        d->z += a2;
    } else {
        func_0038CF68(&v, p + 0x20, a2);
        __asm__ __volatile__(
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(*d) : "m"(v));
    }
}
/* localdecomp:end func_L39_0053C1E8 */

INCLUDE_ASM("asm/levels", func_L39_0053C248);

/* localdecomp:start func_L39_0053C2A0 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L39_0053C1E8(void *, void *, f32);

void func_L39_0053C2A0(u8 *a0) {
    f32 v[4];
    u8 *p = *(u8 **)(a0 + 104);
    func_0038CF68(v, p + 32, 1.0f);
    func_L39_0053C1E8(a0, p, -func_0038CE68(p, v));
}
/* localdecomp:end func_L39_0053C2A0 */

INCLUDE_ASM("asm/levels", func_L39_0053C300);

INCLUDE_ASM("asm/levels", func_L39_0053C758);

/* localdecomp:start func_L39_0053CEC0 */
typedef struct { u8 b[8]; } S8_0053CEC0;
extern S8_0053CEC0 D_L39_0024ADF0 __attribute__((section(".data")));
extern void func_L39_005FF198(u8 *, u8 *, f32 *);
extern f32 func_0038CE68(void *, void *);
extern void func_L39_005FE358(u8 *, u8 *, void *, s32, f32);
extern s32 func_L39_00620CF8(u8 *, s32);
extern void func_003C2F58(u8 *, s32, u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern f32 func_L39_005B44C8(void);

void func_L39_0053CEC0(u8 *a0) {
    f32 v[4];
    S8_0053CEC0 loc;
    u8 buf[16];
    u8 *p;
    u8 *q;
    u8 *r;

    if (a0 == 0) {
        return;
    }
    if (*(s16 *)(a0 + 170) != 4261) {
        return;
    }
    if (a0[32] == 254) {
        return;
    }
    if (a0[32] == 253) {
        return;
    }
    p = *(u8 **)(a0 + 104);
    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 80);
    func_L39_005FF198(q, p, v);
    if (func_0038CE68(p + 16, v) <= 0.9f) {
        *(s32 *)(p + 72) = 0;
    } else {
        *(s32 *)(p + 72) = 1;
    }
    loc = D_L39_0024ADF0;
    if (*(s32 *)(p + 68) != 0 && q[6676] != 0) {
        if (*(s32 *)(p + 72) != 0) {
            func_L39_005FE358(p, p + 16, 0, 1, 1.0f);
        } else {
            func_L39_005FE358(p, p + 16, &loc, 1, 1.0f);
        }
    }
    if (func_L39_00620CF8(q, -1) == 0) {
        return;
    }
    r = *(u8 **)(q + 9508);
    if (r == 0) {
        return;
    }
    if (((r[52] ^ 1) & 1) == 0) {
        return;
    }
    if (*(s16 *)(q + 9352) != 0) {
        return;
    }
    func_003C2F58(a0, 1, buf);
    *(f32 *)(p + 84) = func_0038DAB8(*(f32 *)(p + 84), 0.01745329238f);
    func_003D9508(buf, 57, 0x50505050, 1, 0.25f, 0.0f, func_0038DAB8(*(f32 *)(p + 84) * 2.5f, 0.0f));
    func_003D9508(buf, 42, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(-*(f32 *)(p + 84) * 1.5f, 0.0f));
    func_003D9508(buf, 44, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(*(f32 *)(p + 84), 0.0f));
    func_003D9508(buf, 49, 0x30FF7F00, 1, 0.18f, 0.0f, *(f32 *)(p + 84) * 0.5f);
    func_003D9508(buf, 49, 0x30FF7F, 1, 0.18f, 0.0f, *(f32 *)(p + 84) * -0.5f);
    func_003D9508(buf, 47, 0x607F7F7F, 1, 0.06f, 0.0f, func_L39_005B44C8());
}
/* localdecomp:end func_L39_0053CEC0 */

/* localdecomp:start func_L39_0053D1C0 */
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

void func_L39_0053D1C0(u8 *a0, u8 *b) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 *q = *(u8 **)(p + 80);
    s32 d;
    s32 e;
    f32 *v;
    f32 *dst;

    if (q != 0 && q[0x1A14] != 0) {
        e = q[0x44EE];
        d = q[0x44ED];
        if (e == 3) {
            d += 2;
        } else {
            d += 1;
        }
        d = d % 256;
        e = (e + 1) % 4;
        *(s32 *)(b + 8) = (d << 8) | e;
        if (b[3] == 8) {
            v = (f32 *)(p + 32);
            if (0.40000004f < func_0038CEA8(v)) {
                func_0038CF68(v, v, 0.40000004f);
            }
            dst = (f32 *)(b + 24);
            dst[0] = *(f32 *)(p + 32);
            dst[1] = v[1];
            dst[2] = v[2];
        }
    }
}
/* localdecomp:end func_L39_0053D1C0 */

/* localdecomp:start func_L39_0053D2C0 */
typedef int U128_0053D2C0 __attribute__((mode(TI)));
typedef union { U128_0053D2C0 q; f32 f[4]; } Vec4_0053D2C0;

extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern u8 *D_L39_0024BF5C;
extern s32 D_001D72AC_sda;

extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_L03_003DA010(s32);
extern void func_L01_00451290(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L03_003F6A80(void *, void *, void *, s32, s32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L03_00300DA0(void *);
extern void func_L03_00300F50(void *);

void func_L39_0053D2C0(u8 *a0) {
    u8 *p;
    u8 *e;
    s32 i;
    s32 t;
    u16 f;
    Vec4_0053D2C0 v;
    s32 u;
    u8 *g;
    p = *(u8 **)(a0 + 0x68);
    if (D_L39_00241128 == 2) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        f = *(u16 *)(a0 + 0x34) | 0x1000;
        *(u16 *)(a0 + 0x34) = f;
        if (*(s32 *)(p + 0x30) != -1 ||
            !((t = *(s32 *)(p + 0x3C)) == -1 || (e = D_L39_0024BF5C + t * 256) == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD)) {
            a0[0x30] = 0xFF;
            *(u16 *)(a0 + 0x34) = f | 0x41;
            a0[0x20] = 2;
        } else {
            func_L01_0043B9E8(a0, 0xC0, 0xC0, 0xC0);
            for (i = 0; i < 4; i++) {
                func_L03_003DA010(i);
            }
            if (D_001D72AC_sda != 0) {
                *(u16 *)(a0 + 0x34) |= 0x100;
                func_L01_00451290(a0, &v, 1);
                func_L01_004515D8(a0 + 0xC0, &v, 0);
            }
            a0[0x20] = 1;
        }
        break;
    case 1:
        if (*(s16 *)(a0 + 0xAA) == 0x323 || *(s16 *)(a0 + 0xAA) == 0x19C4 || *(s16 *)(a0 + 0xAA) == 0x2F6) {
            *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), 0.062831856f);
        }
        break;
    case 2:
        u = *(s32 *)(p + 0x3C);
        if (u != -1) {
            g = D_L39_0024BF5C + u * 256;
            if (g == 0 || g[0x20] == 0xFE || g[0x20] == 0xFD) {
                *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x1000) & 0xFFBE;
                func_L03_003F6A80(a0, a0 + 0x10, a0 + 0xF0, 0, 0);
                *(s32 *)(p + 0x30) = -1;
                a0[0x20] = 0;
            }
        }
        break;
    }
    v.q = *(U128_0053D2C0 *)(a0 + 0x10);
    v.f[3] = 2.0f;
    if (func_L39_005BE900(&v, 0, 64.0f) > 0) {
        if (*(s16 *)(a0 + 0xAA) != 0x2F6) {
            func_L01_00404A10(func_L03_00300DA0, a0);
        } else {
            func_L01_00404A10(func_L03_00300F50, a0);
        }
    }
}
/* localdecomp:end func_L39_0053D2C0 */
