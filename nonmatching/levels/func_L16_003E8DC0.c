/* func_L16_003E8DC0: ~145 diff (cascade) with the file's flags. Loop body and constants match; differs in register choice (pos in fp, val in s7 in retail; mine swapped), early lw of p before sb 0xFF/sh, and s1/s2 increment order at loop end. Tried: reuse params as q/r, chained 0xFF store, flag position, increment order. f1 is the 3rd float arg (f14) via an unused middle f32. */
#include "common.h"

#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L16_003E8D20(void *out, void *base, f32 lo, f32 hi);
extern void *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 D_L16_001DF638;
extern f32 D_L16_001DF63C;
__asm__(".extern D_L16_001DF638, 4");
__asm__(".extern D_L16_001DF63C, 4");

typedef struct { vu0_v4 v[4]; vu0_v4 t; f32 r[4]; f32 pad[4]; vu0_v4 e; vu0_v4 d; } L16Sub;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad1[0x10];
    u8 a;
    u8 pad2;
    s16 b;
    u8 pad3[0x34];
    u8 *sub;
} L16Obj;

void *func_L16_003E8DC0(void *pos, u8 *q, f32 *r, u8 tag, s32 val, f32 f0, f32 fu, f32 f1)
{
    L16Obj *o;
    u8 *p;
    s32 i;
    s32 flag;

    o = func_003C24B0(0x1D2C, 0x90);
    if (o == 0) return 0;
    p = o->sub;
    o->b = o->a = 0xFF;
    flag = 1;
    vec_add_ba(&o->pos, pos, q);
    *(vu0_q *)(p + 0x40) = *(vu0_q *)r;
    p[0x6E] = 4;
    *(s32 *)(p + 0x68) = val;
    *(f32 *)(p + 0x64) = f1;
    p[0x6F] = tag;
    *(f32 *)(p + 0x60) = f0;
    q = p;
    r = (f32 *)(p + 0x50);
    for (i = 0; i < 4 && i < p[0x6E]; i++, r++, q += 16) {
        if (i < (s32)(p[0x6E] * 0.5f)) {
            if (i == 0) {
                *(vu0_q *)p = *(vu0_q *)&o->pos;
            } else {
                func_L16_003E8D20(q, pos, 1.5f, f0 * 0.8f);
            }
            ((f32 *)q)[3] = D_L16_001DF638 + func_003824E0(-0.5f, 3.0f);
            *r = func_003824E0(-5.0f, 5.0f);
        } else {
            if (flag) {
                flag = 0;
                vec_sub_ab(p + 0x80, p + 0x10, p);
                func_0038CE20(p + 0x80, p + 0x80, 0.5f);
                vec_add_ab(p + 0x80, p + 0x80, p);
                func_L16_003E8D20(q, p + 0x80, 0.2f, f0 * 0.3f);
            } else {
                func_L16_003E8D20(q, p + 0x70, 0.25f, 0.75f);
            }
            *(vu0_q *)(p + 0x70) = *(vu0_q *)q;
            ((f32 *)q)[3] = D_L16_001DF63C + func_003824E0(0.0f, 0.3f);
            *r = *(f32 *)(p + 0x64) * func_003824E0(0.75f, 0.95f);
        }
    }
    func_L01_004450F0(o, 0, -1);
    return o;
}

INCLUDE_ASM("asm/levels", func_L16_003E8DC0);
