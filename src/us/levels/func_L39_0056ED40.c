#include "common.h"

/* NTSC-U counterpart of func_L39_0056FA38 (src/levels/shared/L39_0056FA38.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x200];
    u8 b200[0x30];
    u128_t q230;
    u8 p240[0x2A0 - 0x240];
    s16 h2A0;
    u8 p2A2[0x2C0 - 0x2A2];
    f32 f2C0;
    u8 p2C4[0x460 - 0x2C4];
} E_0056F820;
extern E_0056F820 D_L39_0024DF80[];

/* localdecomp:start func_L39_0056ED40 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0056FA38;
typedef struct {
    V_0056FA38 pos;
    u8 p10[0x7C - 0x10];
    u8 b7C;
    u8 p7D[0x84 - 0x7D];
    s16 h84;
    s16 h86;
    u8 p88[0x94 - 0x88];
    s32 w94;
} M_0056FA38;
typedef struct {
    u8 p0[0xC0];
    V_0056FA38 vC0;
} T_0056FA38;
typedef struct {
    u8 p0[0x40];
    u128_t q40;
    u8 p50[0x58 - 0x50];
    f32 f58;
    u8 p5C[0xF0 - 0x5C];
    T_0056FA38 *pF0;
    u8 pF4[0xFC - 0xF4];
    s32 wFC;
} F_0056FA38;
typedef struct {
    u8 p0[0x50];
    M_0056FA38 *p50;
    M_0056FA38 *p54;
    u8 p58[0x90 - 0x58];
    V_0056FA38 v90;
    u8 pA0[0x150 - 0xA0];
    F_0056FA38 f150;
    u8 p250[0x460 - 0x250];
} E_0056FA38;
typedef struct {
    u8 p0[0x20];
    s16 h20[4];
    s16 h28[4];
    s16 h30[4];
    u8 p38[4];
    u8 b3C[4];
} R_0056FA38;
typedef struct {
    u8 p0[0x1C];
    R_0056FA38 *r;
} Row_0056FA38;
typedef struct {
    u8 p0[0x198];
    u16 h198;
    u16 p19A;
    u32 w19C;
    u32 w1A0;
} St_0056FA38;
typedef struct {
    u8 p0[0x18];
    s32 w18;
} H_0056FA38;


extern Row_0056FA38 *D_L39_0024B950_rows;
extern s32 D_L39_0024B850_0056ED40[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B850_0056ED40, 4");
extern St_0056FA38 D_L39_00200420;
extern s32 D_L39_00240508_0056ED40;
extern s32 D_L39_0024145C;
extern H_0056FA38 *func_L01_003F51A8(void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388770(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388990(f32);
extern s32 func_003883C8(void *);
extern void func_L01_003E73D0(s32, f32 *, f32, f32);
extern void func_L39_0057A518(s32, s32);

s32 func_L39_0056ED40(M_0056FA38 *o, M_0056FA38 *a) {
    V_0056FA38 v;
    V_0056FA38 d1;
    V_0056FA38 d2;
    E_0056FA38 *e;
    F_0056FA38 *f;
    R_0056FA38 *r;
    M_0056FA38 *p;
    s32 *slot;
    f32 len;
    s32 n;

    e = (E_0056FA38 *)&D_L39_0024DF80[o->w94];
    slot = &D_L39_0024B850_0056ED40[o->w94];
    r = D_L39_0024B950_rows[o->h84].r;
    f = &e->f150;
    if (*slot != 0) {
        *slot = 0;
        return 0;
    }
    *slot = 0;
    if (f->wFC == o->h86 || f->wFC == 0x51) {
        p = e->p50;
        if ((a->h86 == 0x20 || a->h86 == 0 || a->h86 == 10 || a->h86 == 14 || a->h86 == 2) &&
            (a->h86 == 0x20 || p->h86 == 0 || p->h86 == 10 || p->h86 == 14 || p->h86 == 2)) {
            H_0056FA38 *h;
            *(u128_t *)&v = f->q40;
            h = func_L01_003F51A8(&v, 0.25f);
            if (h != 0 && (h->w18 & 1)) {
                return 0;
            }
            r->h28[o->w94] = 1;
            r->h30[o->w94] = 0;
            r->h20[o->w94]++;
            if (r->h20[o->w94] >= 7) {
                if ((e->p54 != 0 && e->p54->h86 == 0x20) || p->h86 == 0x20) {
                    r->b3C[o->w94] = 1;
                    return 1;
                }
                if (p->h86 == 0) {
                    o->b7C = 5;
                }
                return 1;
            }
            if ((e->p54 != 0 && e->p54->h86 == 0x20) || p->h86 == 0x20) {
                r->b3C[o->w94] = 1;
                return 1;
            }
            v.x = func_00388960(f->f58);
            v.y = func_00388978(f->f58);
            v.z = 0.0f;
            func_L01_003E73D0(o->w94, &v.x, 0.06981317f, v.z);
        } else {
            r->h20[o->w94] = 0;
            r->h28[o->w94] = 0;
        }
    } else {
        r->h20[o->w94] = 0;
        if (r->h28[o->w94] != 0) {
            r->h28[o->w94] = 0;
            if (e->p50->h86 == 0) {
                if (D_L39_00200420.h198 < 0xFFFF) {
                    D_L39_00200420.h198++;
                }
                n = D_L39_00240508_0056ED40;
                if (D_L39_00200420.w19C < n) {
                    D_L39_00200420.w19C = n;
                }
                D_L39_00200420.w1A0 = D_L39_00200420.w1A0 | (1 << D_L39_0024145C) | 0x80000000;
                func_003886E8(&v, &e->v90, func_00388730(&e->v90, e->p50));
                vec_sub_ba(&d1, &e->p50->pos, &v);
                func_003886E8(&v, &e->v90, func_00388730(&e->v90, &f->pF0->vC0));
                vec_sub_ba(&d2, &f->pF0->vC0, &v);
                len = func_00388770(&d2);
                if (len != 0.0f) {
                    len *= func_00388770(&d1);
                }
                if (len != 0.0f) {
                    if (1.5707964f - func_00388990(func_00388730(&d2, &d1) / len) >= 1.3962634f) {
                        func_L39_0057A518(o->w94, 1);
                        return 0;
                    }
                }
                r->h30[o->w94] = 0x1E;
            }
        }
    }
    if (r->h30[o->w94] != 0 && e->p50->h86 != 0x20 && (e->p54 == 0 || e->p54->h86 == 0x20)) {
        func_003883C8(&r->h30[o->w94]);
        v.x = func_00388960(f->f58);
        v.y = func_00388978(f->f58);
        v.z = 0.0f;
        func_L01_003E73D0(o->w94, &v.x, 0.13962634f, v.z);
    }
    return 0;
}
/* localdecomp:end func_L39_0056ED40 */
