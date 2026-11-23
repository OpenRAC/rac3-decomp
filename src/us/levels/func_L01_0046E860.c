#include "common.h"

/* NTSC-U counterpart of func_L01_00471FB0 (src/levels/shared/L01_00470A28.c) */
#include "vu0.h"
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003883C8(s16 *);
#include "vu0.h"
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);
extern int func_003883C8(short *);
extern f32 func_00388978(f32);
extern s32 func_003883C8(s16 *);

/* localdecomp:start func_L01_0046E860 */
typedef struct {
    vu0_v4 vel;
    s32 w10;
    s32 w14;
} Sub_471FB0;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 h0A;
    u8 pad0C[4];
    vu0_v4 pos;
    Sub_471FB0 s20;
} Obj_471FB0;

extern f32 D_L01_001E2A48[];
extern s32 D_L01_001E0334;
extern s32 D_L01_001E0334_0046E860;
__asm__(".extern D_L01_001E0334_0046E860, 4");
extern f32 D_L01_001E0340;
__asm__(".extern D_L01_001E0340, 16");
extern s32 D_L01_001DFBC0_0046E860;
extern vu0_v4 D_L01_001E2A70;
extern void func_L01_004C6EC8(void *, void *);
extern f32 func_00388978(f32);
extern s32 func_003883C8(s16 *);
extern void func_003C7CE0(Obj *);

void func_L01_0046E860(Obj_471FB0 *o)
{
    Sub_471FB0 *s;
    vu0_v4 tmp;
    s32 n;
    s32 w;
    f32 d;

    s = &o->s20;
    d = o->pos.z - D_L01_001E2A48[0];
    if (d < -7.0f || (s->w14 != 0 && func_003883C8((s16 *)&o->h0A) != 0)) {
        n = s->w10 - 1;
        s->w10 = n;
        if (n <= 0) {
            func_003C7CE0((Obj *)o);
            D_L01_001E0334_0046E860 = D_L01_001E0334 - 1;
            return;
        }
        o->w4 = (o->w4 & 0xFFFFFF) + (n << 24);
    } else {
        w = o->w4;
        if ((w >> 24) < s->w10) {
            o->w4 = w + 0x1000000;
        }
    }
    if (((s32)o & 0x80) == 0) {
        o->b8 = o->b8 + 2;
    } else {
        o->b8 = o->b8 - 2;
    }
    vec_add_ba(&o->pos, &o->pos, &s->vel);
    vec_add_ab(&o->pos, &o->pos, &D_L01_001E0340);
    func_L01_004C6EC8(&o->pos, &o->pos);
    if (s->w14 == 0) {
        d = func_00388978((f32)(D_L01_001DFBC0_0046E860 & (o->h0A - 1)) / (f32)o->h0A * 6.2831855f);
        func_003886E8(&tmp, &D_L01_001E2A70, d * 0.016666668f);
        vec_add_ba(&o->pos, &tmp, &o->pos);
    }
}
/* localdecomp:end func_L01_0046E860 */
