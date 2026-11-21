#include "common.h"

/* NTSC-U counterpart of func_L39_00550700 (src/levels/shared/L39_00550700.c) */
typedef int u128_t __attribute__((mode(TI)));
extern s32 *D_001D5A10_sda_0054FDD8;
extern f32 func_L01_0040C018(void *, void *);

/* localdecomp:start func_L39_0054FDD8 */
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

extern E_00550700 D_L39_0049C950[];
extern s32 D_L39_0024B260 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B260, 4");
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L39_005F08F8(void *, s32);
extern void func_L39_005BA378(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00346CF8(void *, void *);
extern void func_L39_00551618(void *);
extern s32 func_L39_00550418(void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_L39_00550D60(void *, void *);
extern void func_L39_00550C98(void *);

O_00550700 *func_L39_0054FDD8(u128_t *a0, u128_t *a1, G_00550700 *a2, s32 a3, s32 a4, s32 a5, u128_t *a6) {
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

    o = (O_00550700 *)func_003BCFB0(0x1097, 0x60);
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
            p->f50 = func_L01_0040C018(pv, &p->v20);
        }
        if (func_L39_00646268((u8 *)a2, 3)) {
            E_00550700 *tbl = D_L39_0049C950;
            e = &tbl[tbl[3].b21];
        } else {
            E_00550700 *tbl = D_L39_0049C950;
            e = &tbl[3];
        }
        k = 190.0f / (e->f24 * 0.016666668f);
        p->h32 = 0x28;
        p->f34 = 0.025f;
        p->b39 = a5;
        p->w4C = a3;
        p->h30 = 0;
        p->b38 = a4;
        p->h42 = k;
        p->f44 = 1.0f / p->h42;
        o->w90 = *(s32 *)a2;
        o->h34 = (o->h34 | 0x41) & ~0x1000;
        o->w98 = 0;
        func_L39_005F08F8(o, 1);
        func_L39_005BA378(&o->pos, &dir, 1);
        func_003886E8(&dir, &dir, -1.0f);
        func_L01_00346CF8(o, &dir);
        if ((u32)D_L39_0024B260 >= 10)
            D_L39_0024B260 = 0;
        p->b3A = D_L39_0024B260;
        n = 10;
        D_L39_0024B260 = (D_L39_0024B260 + 1) % n;
        func_L39_00551618(o);
        if (a4 == 1 || (a2 != 0 && a2->b1A14 == 0)) {
            save = *(vu0_v4 *)a0;
            vec_add_ab(&o->pos, a0, a1);
            if (func_L39_00550418(o, &save))
                o->b20 = 2;
            if (p->b38 != 1 && *D_001D5A10_sda_0054FDD8 == 1) {
                for (i = 0; i < 10; i++) {
                    func_003886C0(&t, &save, &o->pos, (f32)i / n);
                    func_L39_00550D60(o, &t);
                }
            }
            func_L39_00550C98(o);
        }
    }
    return o;
}
/* localdecomp:end func_L39_0054FDD8 */
