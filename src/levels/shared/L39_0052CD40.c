#include "common.h"

/* declared by functions of L39_0052CB90.c, which this file was cut from */
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);

/* localdecomp:start func_L39_0052CD40 */
/* Log: needs --flags=-mvu0-use-vf0-vf2 --mode S --as ps2as. $gp slots D_L39_0024AAB0/D_L39_0024AAD8 need section(".sdata")
   plus '.extern X, 8'; globals reached by adjacent lui/addiu are declared u8[8] (ps2as 'la' macro; unsized gave hoisted lui).
   vec_add_ba(&v, &v, &self->v10) matches the VU0 sequence (vec_add_ab gave 2 diff). MATCH. */
#include "vu0.h"

typedef struct Aux_0052CD40 {
    u8 pad0[0x1A4];
    u32 w1A4;
} Aux_0052CD40;

typedef struct Sub2_0052CD40 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 pad24CA[0x2534 - 0x24CA];
    Aux_0052CD40 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 w2544;
} Sub2_0052CD40;

typedef struct Sub1_0052CD40 {
    u8 pad0[0x2D8];
    Sub2_0052CD40 *p2D8;
} Sub1_0052CD40;

typedef struct Obj_0052CD40 {
    u8 pad0[0x1F0];
    s32 w1F0;
    u8 pad1F4[4];
    Sub1_0052CD40 *p1F8;
    u8 pad1FC[4];
    u8 b200[1];
} Obj_0052CD40;

typedef struct Self_0052CD40 {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 pad20[0x68 - 0x20];
    Obj_0052CD40 *p68;
    u8 pad6C[0xC0 - 0x6C];
    u8 bC0[1];
} Self_0052CD40;

typedef struct Glob_0052CD40 {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_0052CD40;

extern Glob_0052CD40 D_001A5810;
extern u8 D_L39_00242930[8];
extern f32 D_L39_0024AAB0[] __attribute__((section(".sdata")));
extern f32 D_L39_0024AAD8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AAB0, 8");
__asm__(".extern D_L39_0024AAD8, 8");
extern void func_0038D000(void *, void *, void *);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L39_00595C18(void *, void *, void *, void *, void *, s32, f32);
extern void func_L39_00596E58(void *, s32);

void func_L39_0052CD40(Self_0052CD40 *self) {
    Obj_0052CD40 *o = self->p68;
    Sub2_0052CD40 *m = o->p1F8->p2D8;
    u8 b = D_001A5810.bA4[m->w2544];
    vu0_v4 v;

    if (m != 0 && (m->p2534->w1A4 & 4) != 0) {
        o->w1F0 ^= 1;
    }
    func_0038D000(&v, D_L39_0024AAB0, self->bC0);
    vec_add_ba(&v, &v, &self->v10);
    func_L39_00595C18(o->b200, m->p2534, &v, D_L39_00242930, &v, b, 1.0f);
    if (m->b1A14 != 0) {
        s32 c = o->p1F8->p2D8->b24C9;
        func_L39_00596E58(o->b200, c);
        func_00382810(c, 0, 0, D_L39_0024AAD8[o->w1F0] * 0.017453292f, 0.005f, 0.2f, 0.0f);
    }
}
/* localdecomp:end func_L39_0052CD40 */
