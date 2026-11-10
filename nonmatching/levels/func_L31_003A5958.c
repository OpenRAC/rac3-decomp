/* Near miss of func_L31_003A5958: tools/check.py reports 56 diff.
   What differs: the object-
   creation skeleton is right (allocate, copy the vector with `lq`/`sq`, set the fields, convert
   ints to floats) but the order of the stores and the register of the data pointer (`$t0` for
   `$a3`) differ. */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p0[4]; s16 h4; u8 p6[0xE]; u8 b14; u8 p15[0x37]; s16 h4C; s16 h4E; u8 p50[0x120]; s32 f170; u8 p174[0x3C]; s32 f1B0; u8 p1B4[4]; s32 f1B8; u8 p1BC[4]; s32 f1C0; u8 p1C4[4]; s32 f1C8; u8 p1CC[8]; s32 f1D4; } S_5958_D;
typedef struct { u8 p0[0x24]; f32 f24; } S_5958_P;
typedef struct { u8 p0[0x10]; u128_t v10; u8 p20[4]; S_5958_P *f24; u8 p28[4]; f32 f2C; u8 b30; u8 p31; s16 h32; u8 p34[0x34]; S_5958_D *f68; } S_5958_O;
extern S_5958_O *func_L31_0040F7B0(s32, s32);
extern void func_L31_003A55A0(S_5958_O *, s32);
S_5958_O *func_L31_003A5958(u128_t *a0, s32 a1) {
    S_5958_O *o = func_L31_0040F7B0(0x1A9A, 0x1E0);
    S_5958_D *d;
    if (o == 0) return 0;
    o->b30 = 0xFF;
    o->h32 = 0x40;
    o->v10 = *a0;
    d = o->f68;
    o->f2C = o->f24->f24 * 1.4f;
    if ((f32)d->h4 <= 0.0f) d->h4 = 3;
    *(f32 *)d = (f32)d->h4;
    if ((f32)d->b14 <= 0.0f) d->b14 = 10;
    d->h4E = 15;
    d->f170 = 3;
    d->f1D4 = 1;
    d->h4C = 4;
    d->f1B8 = a1;
    d->f1B0 = -1;
    d->f1C0 = 0;
    d->f1C8 = 0;
    func_L31_003A55A0(o, 0);
    return o;
}
