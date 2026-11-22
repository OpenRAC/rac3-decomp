#include "common.h"
#include "vu0.h"

typedef struct {
    u8 p0[0xE];
    u8 b14;
} T_44F090;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
} E_0044F2E8;
typedef int s128_44FB80 __attribute__((mode(TI)));
typedef union {
    s128_44FB80 q;
    f32 f[4];
} Vec_0044FB80;

INCLUDE_ASM("asm/levels", func_L01_00451A68);

/* localdecomp:start func_L01_00451C98 */
/* m2c3 */
f32 func_L01_00451C98_00451C98(s32 arg0, s32 arg1) __asm__("func_L01_00451C98");
f32 func_L01_00451C98_00451C98(s32 arg0, s32 arg1) {
    return ((2.0f * (f32) (arg0 % arg1) * 3.1415927f) / (f32) arg1) - 3.1415927f;
}
/* localdecomp:end func_L01_00451C98 */

/* localdecomp:start func_L01_00451CD8 */
extern f32 func_L01_00451C98(void *, void *);
extern f32 func_0038D0B0(f32);
extern void func_0038DBD8(void *, void *, f32);

void func_L01_00451CD8(void *a0, void *a1, void *dst, void *arg) {
    f32 t = func_0038D0B0(func_L01_00451C98(a0, a1));
    func_0038DBD8(dst, arg, t * 0.5f + 0.5f);
}
/* localdecomp:end func_L01_00451CD8 */

LINKER_REMNANT("asm/levels", func_L01_00451D30);

/* localdecomp:start func_L01_00451D38 */
extern void func_0038DBD8(void *, void *, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);

void func_L01_00451D38(f32 *a, s32 b, s32 c, f32 step) {
    f32 t;

    t = func_0038D0B0(*a) * 0.5f + 0.5f;
    *a = func_0038DAB8(*a, step);
    ((void (*)(s32, s32, f32))func_0038DBD8)(b, c, t);
}
/* localdecomp:end func_L01_00451D38 */

/* localdecomp:start func_L01_00451DB8 */
extern void func_L01_00451D38(f32 *a, s32 b, s32 c, f32 step);

void func_L01_00451DB8(u8 *o, s32 a, s32 b, s32 c) {
    *(s32 *)(o + 120) = ((s32 (*)(s32 a, s32 b, s32 c))func_L01_00451D38)(a, b, c);
}
/* localdecomp:end func_L01_00451DB8 */

LINKER_REMNANT("asm/levels", func_L01_00451DF0);

/* localdecomp:start func_L01_00451DF8 */
extern u8 D_001D5473 __attribute__((section(".sdata")));
extern void func_L01_0044E850(void *a0, void *a1, int a2, float f12, float f13);

/* from rac2-decomp's func_002B0990 */
void func_L01_00451DF8(void *a0, float *a1, float f12, int a2, int a3)
{
    if (D_001D5473 != 0) {
        a1[28] = f12;
    } else {
        a1[28] = 1.0f;
    }
    if (a3 != 0) {
        if (a1[28] != a1[8]) {
            func_L01_0044E850(a0, a1, a2, 0.0432f, 0.43200004f);
        }
    }
}
/* localdecomp:end func_L01_00451DF8 */

LINKER_REMNANT("asm/levels", func_L01_00451E70);

/* localdecomp:start func_L01_00451E78 */
extern u8 D_001A4C60[];
extern u32 D_001D545C;
extern s32 D_L01_002BBD60[];
extern u8 D_001426BA[];
extern f32 func_0038CF00(void *, void *);
extern void func_L01_0044D360(void *, s32, s32, s32, s32, s32, f32);

void func_L01_00451E78(u8 *a0, s32 a1, f32 f) {
    u8 *g = D_001A4C60;
    s32 k = 1;
    u32 lvl;
    s32 n;
    if (func_0038CF00(a0 + 16, g) < 7.0f) {
        k = 3;
    }
    lvl = D_001D545C;
    if (lvl >= 60) {
        lvl = 59;
    }
    n = (D_L01_002BBD60[lvl] * a1 - 1) * ((D_001426BA[0] + 1) << g[10312]);
    func_L01_0044D360(a0, n, n, k, -1, 0, f);
}
/* localdecomp:end func_L01_00451E78 */

LINKER_REMNANT("asm/levels", func_L01_00451F58);

/* localdecomp:start func_L01_00451F60 */
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00436660(s32, s32, s32);
void func_L01_00451F60(s32 a0, s32 a1, s32 a2) {
    func_0038E150(1);
    func_L01_00436660(func_00381FF0(a0), a1, a2);
}
/* localdecomp:end func_L01_00451F60 */

/* localdecomp:start func_L01_00451FB8 */
extern void func_L01_004365D8_00451FB8();

void func_L01_00451FB8(void) {
    func_L01_004365D8_00451FB8();
}
/* localdecomp:end func_L01_00451FB8 */

LINKER_REMNANT("asm/levels", func_L01_00451FD8);

INCLUDE_ASM("asm/levels", func_L01_00451FE0);

/* localdecomp:start func_L01_00452310 */

extern T_44F090 *func_00382348(void *m);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                          f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                          s32 h, s32 k);

void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                   f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g) {
    T_44F090 *t = func_00382348(m);

    if (t != 0 && t->b14 == 2) {
        return;
    }
    func_L01_00451FE0(m, a, b, x1, x2, x3, x4, e, x5, x6, f, g, c, d, x0, 1.0f, 0, 3);
}
/* localdecomp:end func_L01_00452310 */

LINKER_REMNANT("asm/levels", func_L01_00452448);

/* localdecomp:start func_L01_00452460 */

extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);

u8 *func_L01_00452460(u8 *src, s32 id, s32 type) {
    u8 *m;
    long t;

    m = func_003C24B0(id, 128);
    if (m != 0) {
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        *(f32 *)(m + 44) *= *(f32 *)(src + 44) / *(f32 *)(*(u8 **)(src + 36) + 36);
        *(u128_t *)(m + 16) = *(u128_t *)(src + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(src + 240);
        t = *(long *)(src + 56);
        m[48] = type;
        *(s16 *)(m + 52) = 0;
        *(long *)(m + 56) = t;
        func_003C7C38(m);
        return m;
    }
    return 0;
}
/* localdecomp:end func_L01_00452460 */

/* localdecomp:start func_L01_00452508 */
extern E_0044F2E8 D_L01_002D15F0[];

void func_L01_00452508(void) {
    E_0044F2E8 *e = D_L01_002D15F0;
    if (e->x0 == 0) {
        e->xC += 1;
        if (e->xC > 10) {
            e->xC = 10;
        }
    } else {
        e->xC = 0;
    }
    if (e->x8 != 0) {
        e->x8 -= 1;
        if (e->x8 == 0) {
            e->x0 = 0;
        }
    }
}
/* localdecomp:end func_L01_00452508 */

/* localdecomp:start func_L01_00452560 */

extern E_0044F2E8 D_L01_002D15F0[];

extern s32 func_00381FF0(s32);
extern void func_L01_004366A0(s32, s32);

s32 func_L01_00452560(s32 i, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2) {
    E_0044F2E8 *e = &D_L01_002D15F0[i];

    if (e->x0 == a1 && e->x14 == t1 && e->x18 == t2 && e->x4 == a2) {
        if (a2 != 0) {
            func_L01_004366A0(func_00381FF0(a2), a3);
        }
        e->x8 = a3;
        e->x4 = a2;
        e->x14 = t1;
        e->x18 = t2;
        return 2;
    }
    if (e->x0 == 0) {
        if (a2 != 0) {
            func_L01_004366A0(func_00381FF0(a2), a3);
        }
        e->x8 = a3;
        e->x0 = a1;
        e->x4 = a2;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00452560 */

/* localdecomp:start func_L01_00452658 */
extern E_0044F2E8 D_L01_002D15F0[];
extern void func_L01_004366E0(void);

s32 func_L01_00452658(s32 a0, s32 a1) {
    E_0044F2E8 *e = &D_L01_002D15F0[a0];
    if (e->x0 == a1) {
        e->x8 = 0;
        e->x0 = 0;
        func_L01_004366E0();
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00452658 */

/* localdecomp:start func_L01_004526A0 */
extern u8 D_001426E0[];
extern s32 func_L01_00452740(void);

s32 func_L01_004526A0(s32 n) {
    s32 max = func_L01_00452740();
    s32 v = D_001426E0[69] + n;
    if (max < v) {
        return 0;
    }
    D_001426E0[69] = v;
    return 1;
}
/* localdecomp:end func_L01_004526A0 */

/* localdecomp:start func_L01_004526E8 */
extern u8 D_00142725 __attribute__((section(".data")));

/* from rac2-decomp's func_002B0D60, renamed */
s32 func_L01_004526E8(void) { return D_00142725; }
/* localdecomp:end func_L01_004526E8 */

/* localdecomp:start func_L01_004526F8 */
extern s32 func_L01_00452740(void);
extern s32 func_L01_004526E8(void);

s32 func_L01_004526F8(void) {
    s32 v = func_L01_00452740();
    v -= func_L01_004526E8();
    if (v < 0) {
        v = 0;
    }
    if (v > 40) {
        v = 40;
    }
    return v;
}
/* localdecomp:end func_L01_004526F8 */

/* localdecomp:start func_L01_00452740 */
extern s32 func_L01_004527A0(s32);

s32 func_L01_00452740(void) {
    s32 i;
    s32 sum = 0;
    for (i = 0; i < 37; i++) {
        sum += func_L01_004527A0(i);
    }
    if (sum < 0) {
        sum = 0;
    }
    if (sum > 40) {
        sum = 40;
    }
    return sum;
}
/* localdecomp:end func_L01_00452740 */

/* localdecomp:start func_L01_004527A0 */
extern u8 D_001BBB18[][8];
s32 func_L01_004527A0(s32 a0) {
    u8 *p = D_001BBB18[a0];
    s32 n = 0;
    s32 i;
    for (i = 7; i >= 0; i--) {
        if (*p++) n++;
    }
    if (n < 0) n = 0;
    if (n > 40) n = 40;
    return n;
}
/* localdecomp:end func_L01_004527A0 */

/* localdecomp:start func_L01_004527F0 */
extern s32 D_L01_002E9D30[];

s32 func_L01_004527F0(u32 a0) {
    if (a0 < 36) {
        return D_L01_002E9D30[a0];
    }
    return 0;
}
/* localdecomp:end func_L01_004527F0 */

/* localdecomp:start func_L01_00452818 */
extern u8 D_001D54B0[] __attribute__((section(".sdata")));

/* from rac2-decomp's func_002B0E90, renamed */
int func_L01_00452818(void)
{
    int count = 0;
    int i;
    for (i = 0; i < 32; i++) {
        if (D_001D54B0[i] != 0) {
            count++;
        }
    }
    if (count < 0) {
        count = 0;
    }
    if (count > 30) {
        count = 30;
    }
    return count;
}
/* localdecomp:end func_L01_00452818 */

/* localdecomp:start func_L01_00452860 */
typedef union { u8 b[0x1B0]; u8 *ptr[0x6C]; } T_00452860;
extern T_00452860 D_L01_00221098;
extern s32 D_L01_001D66B0[2];
extern u8 *func_L01_00449020(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446978(void *, void *);
extern s32 func_003C2B88(void *, s32);
extern s32 func_00382468(s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004637C8(void *, void *, u32, u32, s32, s32, s32, s32);
extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);

s32 func_L01_00452860(u8 *self, u8 *e, u8 *o) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 arr[10];
    u8 *p;
    u8 *sc;
    u8 *r;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    f32 f;

    if (e == 0) {
        return 0;
    }
    if (self == 0) {
        return 0;
    }
    p = func_L01_00449020(self);
    if (p == 0 && o == 0) {
        return 0;
    }
    if (o != 0) {
        p = o;
    }
    if (e[0x2F] == 0) {
        return 1;
    }
    *(u16 *)(p + 0x1E) = *(u16 *)(p + 0x1E) + 1;
    if (func_0038CAD0(e + 0x38) != 0) {
        *(u16 *)(p + 0x1E) = 0;
        e[0x35] = 1;
        e[0x2F] = 0;
    }
    if (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) != 0 && *(s16 *)(p + 0x16) == 0) {
        *(s16 *)(p + 0x16) = 1;
    }
    if (*(s16 *)(p + 0x16) > 0 || (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) == 0)) {
        *(u16 *)(p + 0x16) = *(u16 *)(p + 0x16) + 1;
    }
    if (0.0f < *(f32 *)e) {
        if (*(u8 **)(p + 0x10) != 0 && *(s16 *)(*(u8 **)(p + 0x10) + 0xAA) == 0) {
            f = (f32)*(s16 *)(p + 0x16);
            if ((func_003824E0(90.0f, 150.0f) * 5.0f + 2.0f) / 6.0f < f) {
                func_L01_00446748(&a, self, 0x10000, 1500.0f);
                func_L01_00446978(self, &a);
            }
        }
        if (*(f32 *)e <= 1.0f) {
            func_L01_00446748(&a, self, 0x10000, 1500.0f);
            func_L01_00446978(self, &a);
        }
        if (*(s16 *)(p + 0x1E) >= 0xFB) {
            *(f32 *)e = *(f32 *)e - (f32)*(s16 *)(e + 4) * 0.002f;
        }
    } else {
        func_L01_00446748(&a, self, 0x10000, 1500.0f);
        func_L01_00446978(self, &a);
    }
    n = func_003C2B88(self, 0);
    if (n != 0) {
        sc = (u8 *)0x70000000;
        for (i = 0; i < n; i++, sc += 0x20) {
            if (func_00382468(2) == 0) {
                continue;
            }
            if (*(f32 *)(sc + 0x1C) == 0.0f) {
                a = *(vu0_v4 *)sc;
                a.w = 1.0f;
                func_00382580(&b, 0.0f, *(f32 *)(sc + 0xC));
                vec_add_ab(&a, &a, &b);
                r = func_L01_004637C8(&a, D_L01_001D66B0, 0x3005A182, 0x5A182, (func_00382498(10, 0x12) * 5 + 2) / 6, 0x4B, 0x78, 1);
                if (r != 0) {
                    r[3] = 0x44;
                    k = func_00382468(4);
                    if (k == 0) {
                        r[2] = *D_L01_00221098.ptr[0x5C / 4];
                    } else if (k == 1) {
                        r[2] = *D_L01_00221098.ptr[0x1A4 / 4];
                    } else {
                        r[2] = *D_L01_00221098.ptr[0x88 / 4];
                    }
                }
            } else {
                a = *(vu0_v4 *)sc;
                b = *(vu0_v4 *)(sc + 0x10);
                a.w = 1.0f;
                b.w = 1.0f;
                func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
                c.x = c.x + func_003824E0(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                c.y = c.y + func_003824E0(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                c.z = c.z + func_003824E0(-*(f32 *)(sc + 0xC) * 0.4f, *(f32 *)(sc + 0xC) * 0.4f);
                r = func_L01_004637C8(&c, D_L01_001D66B0, 0x3005A182, 0x5A182, (func_00382498(10, 0x12) * 5 + 2) / 6, 0x4B, 0x78, 1);
                if (r != 0) {
                    r[3] = 0x44;
                    k = func_00382468(4);
                    if (k == 0) {
                        r[2] = *D_L01_00221098.ptr[0x5C / 4];
                    } else if (k == 1) {
                        r[2] = *D_L01_00221098.ptr[0x1A4 / 4];
                    } else {
                        r[2] = *D_L01_00221098.ptr[0x88 / 4];
                    }
                }
            }
        }
        return 1;
    }
    n = func_L01_00447938(self, 10, arr, 0xFFFF, 7.0f);
    if (n != 0) {
        for (j = 0; j < n; j++) {
            func_L01_004C7D98(self + 0x10, &a);
            func_0038CE20(&a, &a, func_003824E0(-0.05f, 0.05f));
            r = func_L01_004637C8(&arr[j], &a, 0x3005A182, 0x5A182, (func_00382498(10, 0x19) * 5 + 2) / 6, 0x2D, 0x5A, 1);
            if (r != 0) {
                r[3] = 0x44;
                k = func_00382468(4);
                if (k == 0) {
                    r[2] = *D_L01_00221098.ptr[0x5C / 4];
                } else if (k == 1) {
                    r[2] = *D_L01_00221098.ptr[0x1A4 / 4];
                } else {
                    r[2] = *D_L01_00221098.ptr[0x88 / 4];
                }
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00452860 */

/* localdecomp:start func_L01_00452E60 */


extern s32 func_003D3CB0(Vec_0044FB80 *, Vec_0044FB80 *, s32, u8 *, s32);
extern u16 func_003D5630(void);

void func_L01_00452E60(u8 *m, u8 *o) {
    Vec_0044FB80 top;
    Vec_0044FB80 bot;
    u8 *p;

    *(s16 *)(o + 58) = -1;
    if (o[73] == 0) {
        return;
    }
    p = *(u8 **)(*(u8 **)(m + 104) + 28);
    if (p != 0) {
        if (*(f32 *)(m + 24) - *(f32 *)(p + 144) < 0.5f) {
            *(s16 *)(o + 58) = *(u16 *)(p + 216);
        }
        return;
    }
    bot.q = top.q = *(s128_44FB80 *)(m + 16);
    top.f[2] += 1.0f;
    bot.f[2] -= 0.5f;
    if (func_003D3CB0(&top, &bot, 31, m, 0) != 0) {
        *(s16 *)(o + 58) = func_003D5630();
    }
}
/* localdecomp:end func_L01_00452E60 */

/* localdecomp:start func_L01_00452F30 */
s32 func_L01_00452F30(s32 a0, u8 *a1) {
    s32 s;
    if (a1[0x49] != 0 && *(u16 *)(a1 + 0x4A) != 0) {
        s = *(s16 *)(a1 + 0x3A);
        if (s != -1 && ((*(u16 *)(a1 + 0x4A) >> s) & 1)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00452F30 */

/* localdecomp:start func_L01_00452F78 */
extern void func_L01_00452FB0();

void func_L01_00452F78(char *a0, int a1, int a2, int a3) {
    func_L01_00452FB0(a0, *(int *)(*(char **)(a0 + 104) + 16), a1, a2, a3);
}
/* localdecomp:end func_L01_00452F78 */

INCLUDE_ASM("asm/levels", func_L01_00452FB0);

LINKER_REMNANT("asm/levels", func_L01_004536E8);
