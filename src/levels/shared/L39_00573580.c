#include "common.h"

typedef struct Ent_00573C58 {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00573C58;

/* declared by functions of L39_00573208.c, which this file was cut from */
typedef struct {
    u8 pad0[0xFC];
    s32 wFC;
    s32 w100;
    s32 w104;
} Sub_00573208;
typedef struct {
    u8 pad0[0x150];
    Sub_00573208 sub;
    u8 pad25C[0x2A3 - 0x150 - 0x108];
    u8 b2A3;
    u8 pad2A4[0x2B8 - 0x2A4];
    f32 f2B8;
    u8 pad2BC[0x2C8 - 0x2BC];
    f32 f2C8;
    u8 pad2CC[0x458 - 0x2CC];
    s32 w458;
    u8 pad45C[4];
} Cam_00573208;
extern Cam_00573208 D_L39_0024DE80[];
extern s32 D_L39_00241128;
typedef struct {
    u8 pad0[0x1C];
    u8 *p1C;
    u8 pad20[0x20 - 0x20];
} Slot_005732E0;
extern Slot_005732E0 *D_L39_0024B850;
extern void func_0038CC88(void *, void *, s32);

/* localdecomp:start func_L39_00573580 */
/* LOG: matches (instruction for instruction; only branch offsets differ) with --flags="-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" plus a config/levels/divs_nops.txt row `func_L39_00573580 2 2` (retail has 2 nops before each div.s).
   Levers: D_B9D0 declared as an unsized sdata array (keeps the lhu decrement after the swc1), two float temps v/w (second block gets its own reg), o->h48++ before func_00382810, struct-field store p->h34 |= 1. */
typedef struct {
    u8 pad0[0x40];
    u8 f40[8];
    f32 f48;
    u8 pad4C[0x84 - 0x4C];
    s16 h84;
    u8 pad86[0x94 - 0x86];
    s32 w94;
} Obj_00573580;


typedef struct {
    u8 pad0[0x44];
    s16 h44;
    s16 h46;
    u16 h48;
} Sub_00573580;

typedef struct {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0xAA - 0x36];
    s16 hAA;
    u8 padAC[0x100 - 0xAC];
} Ent_00573580;

extern Ent_00573580 *D_L39_0024BF5C;
extern Ent_00573580 *D_L39_0024BF64;
extern f32 D_L39_0024B9D0[] __attribute__((section(".sdata")));
extern f32 func_0038DAB8(f32, f32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_0038D328(void *, void *);
extern void func_0038CC88(void *, void *, s32);

void func_L39_00573580(Obj_00573580 *self) {
    f32 buf[16];
    Sub_00573580 *o;
    Ent_00573580 *p;
    f32 v;
    f32 w;
    if (self->w94 > 0) return;
    o = (Sub_00573580 *)D_L39_0024B850[self->h84].p1C;
    for (p = D_L39_0024BF5C; p < D_L39_0024BF64; p++) {
        s16 h = p->hAA;
        if (h == 0x171C || h == 0x18CB || h == 0x18CC || h == 0x18CF || h == 0x18CD ||
            h == 0x1ADC || h == 0x16DB || h == 0x1CFC || h == 0x1E68 || h == 0x1E07 ||
            h == 0x1CFB || h == 0x1E77 || h == 0x1E78 || h == 0x1CFD || h == 0x1CFE ||
            h == 0x1E4C || h == 0x1E65 || h == 0x1E4D || h == 0x1E69 || h == 0x1E59 ||
            h == 0x1E7A || h == 0x1E83 || h == 0x109D || h == 0x109A || h == 0x109E ||
            h == 0x109F || h == 0x1A1B || h == 0x1A91 || h == 0x1094 || h == 0x1087 ||
            h == 0x1096 || h == 0x1089 || h == 0x108A || h == 0x18AB || h == 0x18DF ||
            h == 0x1098 || h == 0x1099 || h == 0x10A4 || h == 0x10A5 || h == 0x10A7 ||
            h == 0x1BDD || h == 0x1BDE) {
            p->h34 |= 1;
        }
    }
    self->f48 = func_0038DAB8(self->f48, 0.005235988f);
    o->h48++;
    func_00382810(0, 0, 0, 1.2217305f, 0.005f, 0.2f, 0.0f);
    if (o->h44 >= 0) {
        v = (f32)o->h44 / 25.0f;
        if (v > 1.0f) v = 1.0f;
        if (v < 0.0f) v = 0.0f;
        D_L39_0024B9D0[0] = v;
        o->h44--;
    }
    if (o->h46 >= 0) {
        w = (f32)o->h46 / 25.0f;
        if (w > 1.0f) w = 1.0f;
        if (w < 0.0f) w = 0.0f;
        D_L39_0024B9D0[0] = 1.0f - w;
        o->h46--;
    }
    func_0038D328(buf, self->f40);
    func_0038CC88(self, buf, 0x30);
}
/* localdecomp:end func_L39_00573580 */

/* localdecomp:start func_L39_00573948 */
typedef struct {
    u8 pad0[0x7E];
    s16 h7E;
    u8 pad80[4];
    s16 h84;
    u8 pad86[0xE];
    s32 w94;
} Obj_00573948;



extern s32 D_L39_00242914;
extern f32 D_L39_0024B9D0_00573948;

void func_L39_00573948(Obj_00573948 *self) {
    Ent_00573580 *p;
    u8 *t;
    Ent_00573580 *end;
    if (self->w94 > 0) return;
    if (D_L39_00241128 != 0) return;
    t = D_L39_0024B850[self->h84].p1C;
    if (D_L39_00242914 != 0) {
        D_L39_0024B9D0_00573948 = 0.0f;
    } else {
        *(s16 *)(t + 0x44) = 0x19;
    }
    func_00382810(0, 0, 0, 1.1100293f, 0.005f, 0.2f, 0.0f);
    self->h7E = 4;
    (D_L39_0024DE80 + self->w94)->w458 = 3;
    for (p = D_L39_0024BF5C; p < D_L39_0024BF64; p++) {
        s32 h = p->hAA;
        if (h == 0x171C || h == 0x18CB || h == 0x18CC || h == 0x18CF || h == 0x18CD ||
            h == 0x1ADC || h == 0x16DB || h == 0x1CFC || h == 0x1E68 || h == 0x1E07 ||
            h == 0x1CFB || h == 0x1E77 || h == 0x1E78 || h == 0x1CFD || h == 0x1CFE ||
            h == 0x1E4C || h == 0x1E65 || h == 0x1E4D || h == 0x1E69 || h == 0x1E59 ||
            h == 0x1E7A || h == 0x1E83 || h == 0x109D || h == 0x109A || h == 0x109E ||
            h == 0x109F || h == 0x1A1B || h == 0x1A91 || h == 0x1094 || h == 0x1087 ||
            h == 0x1096 || h == 0x1089 || h == 0x108A || h == 0x18AB || h == 0x18DF ||
            h == 0x1098 || h == 0x1099 || h == 0x10A4 || h == 0x10A5 || h == 0x10A7 ||
            h == 0x1BDD || h == 0x1BDE) {
            if ((*(unsigned long *)((u8 *)p + 0x30) & 0x104000000000L) != 0x4000000000L) {
                p->h34 &= 0xFFFE;
            }
        }
    }
}
/* localdecomp:end func_L39_00573948 */
