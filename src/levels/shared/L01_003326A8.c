#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[148];
    u8 *(*fn)(u8 *);
} Vt00335B98;
typedef void (*Fn_335C70)(u8 *);
typedef struct {
    u8 pad[0x1E];
    u16 flags;
} Obj_003378A0;

INCLUDE_ASM("asm/levels", func_L01_003326A8);

INCLUDE_ASM("asm/levels", func_L01_00333D80);

INCLUDE_ASM("asm/levels", func_L01_00333F18);

INCLUDE_ASM("asm/levels", func_L01_00334188);

/* localdecomp:start func_L01_00334250 */

extern void func_L01_00456C98(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0038CAD0(u8 *);
extern s32 func_00382498(s32, s32);

s32 func_L01_00334250(u8 *a0, u8 *obj, u8 *who, u8 *m, s32 t0, u8 *cfg) {
    if (*(s32 *)(obj + 100) == 0) {
        func_L01_00456C98(who, *(s32 *)(cfg + 80), 0, 0, 1, 1, 3, 0, cfg[156] != 0, 0, *(f32 *)(cfg + 84), 10.0f, 1.0f);
    } else {
        func_L01_00456C98(who, *(s32 *)(cfg + 88), 0, 0, 1, 1, 3, 0, cfg[156] != 0, 0, *(f32 *)(cfg + 92), 10.0f, 1.0f);
    }
    if (*(s16 *)(m + 196) != 1) {
        return func_0038CAD0(obj + 100) ? 0 : 2;
    }
    *(s32 *)(obj + 100) = func_00382498(300, 480);
    *(s128 *)(m + 1184) = *(s128 *)(m + 176);
    return 1;
}
/* localdecomp:end func_L01_00334250 */

INCLUDE_ASM("asm/levels", func_L01_00334358);

INCLUDE_ASM("asm/levels", func_L01_003347C0);

LINKER_REMNANT("asm/levels", func_L01_00334860);

INCLUDE_ASM("asm/levels", func_L01_00334868);

/* localdecomp:start func_L01_00335150 */

extern s32 *D_L01_0021F6C0[];
extern u8 *D_L01_001E0100;
extern u8 *D_L01_001E001C;
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004591B8(void *, void *, void *);
extern void func_L01_00459188(void *, void *, void *);

s32 func_L01_00335150(u8 *a0, s32 a1, u8 *a2, u8 *a3, s32 a4, u8 *a5)
{
    s32 *path;
    f32 d;
    u128_t tmp;

    if (*(s32 *)(a5 + 108) != -1 && a5[153] == 0) {
        path = D_L01_0021F6C0[*(s32 *)(a5 + 108)];
        d = func_0038CF38(a2 + 16, path + 4);
        if (func_0038CF38(a2 + 16, path + path[0] * 4) < d) {
            func_L01_0045C150(a2, path, 0, 0);
        } else {
            func_L01_0045C150(a2, path, path[0] - 1, 0);
        }
    }
    if (a5[16] != 2 && a5[17] != 2) {
        if (*(s32 *)(a5 + 100) != -1) {
            tmp = *(u128_t *)(&D_L01_001E0100[*(s32 *)(a5 + 100) << 7] + 48);
            func_L01_004591B8(a2, &tmp, a3 + 1008);
        } else if (*(s32 *)(a5 + 96) != -1) {
            func_L01_00459188(a2, D_L01_001E001C + *(s32 *)(a5 + 96) * 256, a3 + 1008);
        }
    }
    a0[188] = 0;
    return 0;
}
/* localdecomp:end func_L01_00335150 */

/* localdecomp:start func_L01_003352B8 */

extern void func_L01_00334358(void *, void *, f32);

s32 func_L01_003352B8(void *a, u8 *b, u8 *c, u8 *d) {
    u8 *t = *(u8 **)(d + 0xC0);

    *(u8 **)(d + 0x440) = t;
    *(u128_t *)(d + 0x400) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x3F0) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x410) = *(u128_t *)(t + 0x10);
    func_L01_00334358(c, d, 12.0f);
    *(u128_t *)(b + 0x80) = *(u128_t *)(c + 0x10);
    *(u128_t *)(d + 0x4A0) = *(u128_t *)(d + 0x400);
    return 0;
}
/* localdecomp:end func_L01_003352B8 */

/* localdecomp:start func_L01_00335338 */
extern s32 *D_L01_0021F6C0[];
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);

s32 func_L01_00335338(u8 *a0, u8 *a1, u8 *a2, s32 a3, s32 t0, u8 *t1) {
    s32 i = *(s32 *)(t1 + 108);
    if (i != -1) {
        s32 *s = D_L01_0021F6C0[i];
        f32 d = func_0038CF38(a2 + 16, s + 4);
        if (func_0038CF38(a2 + 16, s + s[0] * 4) < d) {
            func_L01_0045C150(a2, s, 0, 0);
        } else {
            func_L01_0045C150(a2, s, s[0] - 1, 0);
        }
    }
    a0[188] = 0;
    a1[94] = 0;
    return 0;
}
/* localdecomp:end func_L01_00335338 */

INCLUDE_ASM("asm/levels", func_L01_00335418);

INCLUDE_ASM("asm/levels", func_L01_003355B8);

INCLUDE_ASM("asm/levels", func_L01_00335670);

INCLUDE_ASM("asm/levels", func_L01_003357C8);

INCLUDE_ASM("asm/levels", func_L01_00335950);

INCLUDE_ASM("asm/levels", func_L01_00335AD0);

INCLUDE_ASM("asm/levels", func_L01_00335C58);

INCLUDE_ASM("asm/levels", func_L01_00335D60);

/* localdecomp:start func_L01_00335EC0 */
int func_L01_00335EC0(u8 *a0, int a1) {
    int *p = *(int **)(a0 + 104);
    if (a0[149] || a1 == -1) {
        p[28] = -1;
        return 0;
    }
    p[28] = a1;
    a0[149] = 1;
    return 1;
}
/* localdecomp:end func_L01_00335EC0 */

INCLUDE_ASM("asm/levels", func_L01_00335EF8);

/* localdecomp:start func_L01_00335F28 */
void func_L01_00335F28(u8 *a, u8 b) {
    (*(u8 **)(a + 104))[92] = b;
}
/* localdecomp:end func_L01_00335F28 */

/* localdecomp:start func_L01_00335F38 */
void func_L01_00335F38(u8 *a, u8 b) {
    (*(u8 **)(a + 104))[93] = b;
}
/* localdecomp:end func_L01_00335F38 */

INCLUDE_ASM("asm/levels", func_L01_00335F48);

/* localdecomp:start func_L01_003361D8 */
extern Vt00335B98 *func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);
extern void func_003C2880(u8 *a0);
void func_L01_003361D8(u8 *a0) {
    u8 *s0 = *(u8 **)(*(u8 **)(a0 + 184) + 104);
    u8 *r;
    r = func_L01_0043B568(*(s32 *)(s0 + 64), 4, 156)->fn(a0);
    *(s32 *)(r + 1136) = 0;
    *(s32 *)(s0 + 80) = -1;
    *(s32 *)(a0 + 152) = 0;
    *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x43) & 0xEFFF;
    func_L01_004AA7E8(a0, 1);
    if (*(s32 *)(s0 + 72) == -1) {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003361D8 */

/* localdecomp:start func_L01_00336270 */
extern s32 D_L01_001DCF08;
extern s32 D_L01_001DCF18;

void *func_L01_00336270(s32 arg0, s32 arg1, s32 *arg2) {
    switch (arg1) {                                 /* irregular */
    case 0:
        *arg2 = 0x10;
        return &D_L01_001DCF08;
    case 1:
        *arg2 = 0x1C;
        return &D_L01_001DCF18;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_00336270 */

/* localdecomp:start func_L01_003362B0 */
extern Vt00335B98 *func_L01_0043B568(s32 a0, s32 a1, s32 a2);

extern u8 *D_L01_001E001C;
extern Fn_335C70 *func_L01_0043B548(s32, s32);
extern void func_003C2880(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L01_003362B0(u8 *m, s32 flag) {
    u8 *v = *(u8 **)(m + 104);
    u8 *o = 0;
    Fn_335C70 *r;
    Fn_335C70 *t;
    s32 idx;

    r = ((Fn_335C70 * (*)(s32, s32, s32))func_L01_0043B568)(*(s32 *)(v + 64), 4, 156);
    if (*(u8 **)(m + 184) != 0) {
        o = *(u8 **)(*(u8 **)(m + 184) + 104);
    }
    idx = *(s32 *)(v + 80);
    if (idx != -1) {
        r[1](D_L01_001E001C + (idx << 8));
    }
    if (*(s32 *)(v + 48) != 0) {
        t = func_L01_0043B548(6625, 108);
        t[0](m);
        if (flag != 0) {
            t[1](m);
        }
    } else if (o == 0 || *(s16 *)(o + 140) == -1) {
        func_003C2880(m);
    } else {
        *(s32 *)(v + 80) = -1;
        func_L01_004450F0(m, 4, -1);
    }
}
/* localdecomp:end func_L01_003362B0 */

/* localdecomp:start func_L01_003363B0 */
void func_L01_003363B0(u8 *a, u8 *b) {
    u8 *s = *(u8 **)(b + 104);
    u8 *d = *(u8 **)(a + 104);
    *(s32 *)(d + 64) = *(s32 *)(s + 108);
    *(s32 *)(d + 72) = *(s32 *)(s + 124);
    *(s32 *)(d + 68) = *(s32 *)(s + 112);
}
/* localdecomp:end func_L01_003363B0 */

/* localdecomp:start func_L01_003363D8 */
f32 func_L01_003363D8(void) {
    return 0.75f;
}
/* localdecomp:end func_L01_003363D8 */

/* localdecomp:start func_L01_003363E8 */
extern void func_L01_003362B0(u8 *m, s32 flag);
void func_L01_003363E8(void *a0) {
    ((void (*)(void *a0, s32 a1))func_L01_003362B0)(a0, 0);
}
/* localdecomp:end func_L01_003363E8 */

/* localdecomp:start func_L01_00336408 */
void func_L01_00336408(u8 *obj) {
    (*(u8 **)(obj + 104))[120] = 1;
}
/* localdecomp:end func_L01_00336408 */

INCLUDE_ASM("asm/levels", func_L01_00336418);

INCLUDE_ASM("asm/levels", func_L01_00336500);

INCLUDE_ASM("asm/levels", func_L01_00336560);

INCLUDE_ASM("asm/levels", func_L01_003365C0);

INCLUDE_ASM("asm/levels", func_L01_00336D90);

INCLUDE_ASM("asm/levels", func_L01_00337880);

INCLUDE_ASM("asm/levels", func_L01_00337E10);

/* localdecomp:start func_L01_00337EA8 */
extern void *D_L01_001EAA18[];
extern u8 *func_00382348(void *);
s32 func_L01_00337EA8(void) {
    s32 r = 0;
    u8 *v = 0;
    if (D_L01_001EAA18[0] != 0) {
        v = func_00382348(D_L01_001EAA18[0]);
    }
    if (v != 0) {
        r = v[9] == 1;
    }
    return r;
}
/* localdecomp:end func_L01_00337EA8 */

/* localdecomp:start func_L01_00337EF8 */
extern u8 *func_00382348(void *);
extern void *D_L01_001EAA18[];


s32 func_L01_00337EF8(void) {
    Obj_003378A0 *p = ((Obj_003378A0 * (*)(s32))func_00382348)(((s32 *)&D_L01_001EAA18)[0]);
    if (p != 0 && (p->flags & 2)) return 1;
    return 0;
}
/* localdecomp:end func_L01_00337EF8 */

INCLUDE_ASM("asm/levels", func_L01_00337F38);

INCLUDE_ASM("asm/levels", func_L01_00338230);

INCLUDE_ASM("asm/levels", func_L01_003384B0);

INCLUDE_ASM("asm/levels", func_L01_00338628);
