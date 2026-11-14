#include "common.h"
#include "vu0.h"

typedef struct Sub_003E2638 {
    u8 pad00[0x10];
    s32 f10;
} Sub_003E2638;
typedef struct Ent_003E2638 {
    u8 pad00[0x24];
    Sub_003E2638 *f24;
    u8 pad28[0x9];
    u8 f31;
    u8 pad32;
    u16 f34;
    u8 pad36[0x62];
    s32 f98;
} Ent_003E2638;
typedef struct Obj_003E2638 {
    u8 pad00[0x68];
    f32 *f68;
    u8 pad6C[0x10];
    u16 f7C;
    u8 pad7E[0x1A];
    s32 f98;
} Obj_003E2638;
typedef struct Q_003E2638 {
    u8 pad00[0x2C];
    f32 f2C;
} Q_003E2638;

/* localdecomp:start func_L16_003E2518 */
/* PAL port of the NTSC-U match src/us/levels/func_L16_003E0740.c */
extern int func_L01_003D5C98(s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, s32);

void func_L16_003E2518(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, u8 a5, u8 a6, f32 f12, f32 f13) {
    func_L01_003D5C98(a0, a1, a4, a6, a2, a3, 1.0f, 0.3f, 0.013f, f12, f13, a5);
}
/* localdecomp:end func_L16_003E2518 */

/* localdecomp:start func_L16_003E2578 */
extern void func_L01_00439880(u8 *, u16 *, u16 *);
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L16_003E2638(u8 *, s32);

void func_L16_003E2578(u8 *a0) {
    u8 *s;
    u16 x;
    s32 w;
    s32 r;
    s32 t;

    t = a0[0x20];
    s = *(u8 **)(a0 + 0x68);
    if (t != 1) {
        if (t < 2) {
            if (t == 0) {
                func_L01_00439880(a0, &x, (u16 *)&w);
                *(u16 *)(a0 + 0x7C) = x;
                *(u16 *)(s + 4) = *(u16 *)(s + 0x40);
                *(f32 *)s = (f32)*(s32 *)(s + 0x40);
                *(u16 *)(s + 0x36) = *(u16 *)&w;
                func_L01_004450F0(a0, 1, -1);
            }
        }
    } else {
        r = func_L01_00447490(a0, 1, 1);
        if (r != 0) {
            func_L16_003E2638(a0, r);
        }
    }
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L16_003E2578 */

/* localdecomp:start func_L16_003E2638 */
extern Ent_003E2638 *func_L01_00452460(Obj_003E2638 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L16_003E26E8(Obj_003E2638 *, Q_003E2638 *);

void func_L16_003E2638(u8 *p0, s32 p1) {
    Obj_003E2638 *a0 = (Obj_003E2638 *)p0;
    Q_003E2638 *a1 = (Q_003E2638 *)p1;
    f32 d;
    s32 id;
    Ent_003E2638 *e;

    d = *a0->f68 - a1->f2C;
    *a0->f68 = d;
    if (d > 0.0f && a0->f7C != 0) {
        func_L16_003E26E8(a0, a1);
        return;
    }
    id = 0x1C7B;
    e = func_L01_00452460(a0, id, 0);
    if (e != 0) {
        Sub_003E2638 *s = e->f24;
        u16 fl = e->f34;
        s32 v = s->f10;
        fl |= 1;
        e->f98 = v;
        e->f34 = fl;
        e->f31 = 0;
    }
    a0->f98 = 0;
    a0->f7C = 0;
    func_L01_004450F0((u8 *)a0, 2, -1);
}
/* localdecomp:end func_L16_003E2638 */

INCLUDE_ASM("asm/levels", func_L16_003E26E8);

/* localdecomp:start func_L16_003E2B18 */
typedef int u128_t __attribute__((mode(TI)));

void func_L16_003E2C28(u8 *, u128_t *, s32);

void func_L16_003E2B18(void *arg0, s32 arg1) {
    vu0_v4 res;
    vu0_v4 tbl[3];

    *(u128_t *)&tbl[0] = 0;
    *(u128_t *)&tbl[1] = 0;
    *(u128_t *)&tbl[2] = 0;
    tbl[0].x = 0.799f;
    tbl[0].y = -0.011f;
    tbl[0].z = 1.179f;
    tbl[1].x = -0.852f;
    tbl[1].y = -0.001f;
    tbl[1].z = 1.174f;
    tbl[2].x = -0.147f;
    tbl[2].y = 0.009f;
    tbl[2].z = 1.185f;
    if (arg1 == 1) {
        vec_add_ba(&res, (u8 *)arg0 + 0x10, &tbl[0]);
    }
    if (arg1 == 2) {
        vec_add_ba(&res, (u8 *)arg0 + 0x10, &tbl[1]);
    }
    if (arg1 == 3) {
        vec_add_ba(&res, (u8 *)arg0 + 0x10, &tbl[2]);
    }
    func_L16_003E2C28(arg0, (u128_t *)&res, 7);
}
/* localdecomp:end func_L16_003E2B18 */

/* localdecomp:start func_L16_003E2C28 */

void func_L16_003E2518(u8 *, u128_t *, s32, s32, s32, s32, s32, f32, f32);

void func_L16_003E2C28(u8 *arg0, u128_t *arg1, s32 arg2) {
    u128_t tmp;
    f32 *fp;

    tmp = *arg1;
    fp = (f32 *)&tmp;
    fp[2] = fp[2] + 0.5f;
    func_L16_003E2518(arg0, &tmp, 0x68, 0x69, arg2, 0, 2, 1.0f, 0.6f);
}
/* localdecomp:end func_L16_003E2C28 */

/* localdecomp:start func_L16_003E2C88 */
/* PAL port of the NTSC-U match src/us/levels/func_L16_003E0EB0.c */
#include "vu0.h"


extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, s32, f32);
extern u8 *D_L16_002206D8[];

void func_L16_003E2C88(u8 *obj, u128_t *vec)
{
    f32 buf[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    s32 a2;
    u8 *r;

    *(u128_t *)pos = *vec;
    pos[2] = *(f32 *)(obj + 0x18) + 1.179f;
    for (i = 1; i >= 0; i--) {
        func_L01_00443B88(buf, 0.040000003f, 0.07000001f);
        f20 = fabs_asm(buf[2]);
        buf[2] = f20 + func_003824E0(1.0f, 2.5f) * 0.020000001f;
        f20 = func_003824E0(0.08f, 0.14f);
        a2 = (func_00382498(0x5A, 0x96) * 5 + 2) / 6;
        r = func_L01_004713C8(pos, buf, a2, 0x827770, -1, 0x7F, 0x7F, f20 * 210000.0f, f20 * 210000.0f, 0, 0.0038400004f);
        if (r != 0) {
            r[2] = D_L16_002206D8[0x61][func_00382468(3) + 0xA];
            r[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L16_003E2C88 */

INCLUDE_ASM("asm/levels", func_L16_003E2E30);

/* localdecomp:start func_L16_003E3068 */
extern void func_L16_003E2B18(void *, s32);

void func_L16_003E3068(char *a, int bit)
{
    *(unsigned short *)(a + 0x7C) &= ~(1 << bit);
    (*(unsigned short **)(a + 0x68))[0x36 / 2]--;
    func_L16_003E2B18(a, bit);
}
/* localdecomp:end func_L16_003E3068 */
