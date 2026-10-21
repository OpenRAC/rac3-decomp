#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_00451C98);

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

INCLUDE_ASM("asm/levels", func_L01_00451DF8);

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

INCLUDE_ASM("asm/levels", func_L01_00452508);

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

INCLUDE_ASM("asm/levels", func_L01_00452658);

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

INCLUDE_ASM("asm/levels", func_L01_004526E8);

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

INCLUDE_ASM("asm/levels", func_L01_00452818);

INCLUDE_ASM("asm/levels", func_L01_00452860);

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

INCLUDE_ASM("asm/levels", func_L01_00452F30);

/* localdecomp:start func_L01_00452F78 */
extern void func_L01_00452FB0();

void func_L01_00452F78(char *a0, int a1, int a2, int a3) {
    func_L01_00452FB0(a0, *(int *)(*(char **)(a0 + 104) + 16), a1, a2, a3);
}
/* localdecomp:end func_L01_00452F78 */

INCLUDE_ASM("asm/levels", func_L01_00452FB0);

LINKER_REMNANT("asm/levels", func_L01_004536E8);
