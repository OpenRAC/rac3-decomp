#include "common.h"

/* declared by functions of L39_00550638.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
extern s32 *D_001D5A10_sda;
extern f32 func_L01_0040E548(void *, void *);

/* localdecomp:start func_L39_00550700 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[2];
    f32 f24;
    u8 pad28[0x80 - 0x28];
} E_00550700;

typedef struct {
    u8 pad0[0x1A14];
    u8 b1A14;
} G_00550700;

typedef struct {
    u128_t v0;
    u128_t v10;
    u128_t v20;
    s16 h30;
    s16 h32;
    f32 f34;
    u8 b38;
    u8 b39;
    u8 b3A;
    u8 pad3B;
    G_00550700 *g;
    s16 h40;
    s16 h42;
    f32 f44;
    u8 pad48[4];
    s32 w4C;
    f32 f50;
} P_00550700;

typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 b20;
    u8 pad21[0x30 - 0x21];
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x68 - 0x36];
    P_00550700 *p;
    u8 pad6C[0x90 - 0x6C];
    s32 w90;
    u8 pad94[4];
    s32 w98;
} O_00550700;

extern E_00550700 D_L39_0049C890[];
extern s32 D_L39_0024B150 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B150, 4");
extern u8 *func_003C24B0(s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00347640(void *, void *);
extern void func_L39_00551F68(void *);
extern s32 func_L39_00550D48(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L39_005516B0(void *, void *);
extern void func_L39_005515E8(void *);

O_00550700 *func_L39_00550700(u128_t *a0, u128_t *a1, G_00550700 *a2, s32 a3, s32 a4, s32 a5, u128_t *a6) {
    O_00550700 *o;
    P_00550700 *p;
    E_00550700 *e;
    s32 n;
    s32 k;
    s32 i;
    u128_t *pv;
    vu0_v4 dir;
    vu0_v4 save;
    vu0_v4 t;

    o = (O_00550700 *)func_003C24B0(0x1097, 0x60);
    if (o != 0) {
        p = o->p;
        pv = &p->v10;
        p->g = a2;
        o->b30 = 0xFF;
        o->h32 = 0xFF;
        o->b31 = 1;
        o->pos = *a0;
        o->b20 = 0;
        p->v0 = *a1;
        *pv = *a0;
        if (a6 != 0) {
            p->h40 = 1;
            p->v20 = *a6;
            p->f50 = func_L01_0040E548(pv, &p->v20);
        }
        if (func_L39_00648AE0((u8 *)a2, 3)) {
            E_00550700 *tbl = D_L39_0049C890;
            e = &tbl[tbl[3].b21];
        } else {
            E_00550700 *tbl = D_L39_0049C890;
            e = &tbl[3];
        }
        k = 190.0f / (e->f24 * 0.0200000014156103134155273437f) + 0.5f;
        p->h32 = 0x21;
        p->f34 = 0.030303031f;
        p->b39 = a5;
        p->w4C = a3;
        p->h30 = 0;
        p->b38 = a4;
        p->h42 = k;
        p->f44 = 1.0f / p->h42;
        o->w90 = *(s32 *)a2;
        o->h34 = (o->h34 | 0x41) & ~0x1000;
        o->w98 = 0;
        func_L39_005F2FF8(o, 1);
        func_L39_005BC330(&o->pos, &dir, 1);
        func_0038CE20(&dir, &dir, -1.0f);
        func_L01_00347640(o, &dir);
        if ((u32)D_L39_0024B150 >= 10)
            D_L39_0024B150 = 0;
        p->b3A = D_L39_0024B150;
        n = 10;
        D_L39_0024B150 = (D_L39_0024B150 + 1) % n;
        func_L39_00551F68(o);
        if (a4 == 1 || (a2 != 0 && a2->b1A14 == 0)) {
            save = *(vu0_v4 *)a0;
            vec_add_ab(&o->pos, a0, a1);
            if (func_L39_00550D48(o, &save))
                o->b20 = 2;
            if (p->b38 != 1 && *D_001D5A10_sda == 1) {
                for (i = 0; i < 10; i++) {
                    func_0038CDF8(&t, &save, &o->pos, (f32)i / n);
                    func_L39_005516B0(o, &t);
                }
            }
            func_L39_005515E8(o);
        }
    }
    return o;
}
/* localdecomp:end func_L39_00550700 */

/* localdecomp:start func_L39_00550A28 */
#include "vu0.h"

__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern void func_L39_005514A0(void *, s32);
extern void func_L39_005515E8(void *);
extern s32 func_L39_00550D48(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L39_005516B0(void *, void *);
extern s32 func_0038CB00(void *);

/* from rac2-decomp's func_L00_003F4EC8 */
void func_L39_00550A28(u8 *a0) {
    vu0_v4 old;
    vu0_v4 pt;
    u8 *o;
    s32 i;

    o = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 2) {
        u8 *p = *(u8 **)(o + 0x3C);
        if (p != 0 && p[0x1A14] != 0 && o[0x39] != 0 && o[0x3B] == 0) {
            func_L39_005514A0(a0, 0);
        }
        func_L39_005515E8(a0);
        return;
    }
    old = *(vu0_v4 *)(a0 + 0x10);
    vec_add_ab(a0 + 0x10, a0 + 0x10, o);
    if (*(f32 *)(a0 + 0x10) < 2.0f || 1021.0f < *(f32 *)(a0 + 0x10)
        || *(f32 *)(a0 + 0x14) < 2.0f || 1021.0f < *(f32 *)(a0 + 0x14)
        || *(f32 *)(a0 + 0x18) < 2.0f || 1021.0f < *(f32 *)(a0 + 0x18)) {
        if (*(f32 *)(a0 + 0x10) < 5.0f) *(f32 *)(a0 + 0x10) = 5.0f;
        if (*(f32 *)(a0 + 0x14) < 5.0f) *(f32 *)(a0 + 0x14) = 5.0f;
        if (*(f32 *)(a0 + 0x18) < 5.0f) *(f32 *)(a0 + 0x18) = 5.0f;
        {
            f32 hi = 1016.0f;
            if (*(f32 *)(a0 + 0x10) > hi) *(f32 *)(a0 + 0x10) = hi;
            if (*(f32 *)(a0 + 0x14) > hi) *(f32 *)(a0 + 0x14) = hi;
            if (*(f32 *)(a0 + 0x18) > hi) *(f32 *)(a0 + 0x18) = hi;
        }
        a0[0x20] = 2;
        return;
    }
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
    }
    if (func_L39_00550D48(a0, &old) != 0) {
        a0[0x20] = 2;
    }
    if (o[0x38] != 1 && *D_L39_00241120 == 1) {
        for (i = 0; i < 10; i++) {
            func_0038CDF8(&pt, &old, a0 + 0x10, (f32)i / 10.0f);
            func_L39_005516B0(a0, &pt);
        }
    }
    func_L39_005515E8(a0);
    if (func_0038CB00(o + 0x42) != 0) {
        a0[0x20] = 2;
    }
}
/* localdecomp:end func_L39_00550A28 */
