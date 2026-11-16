#include "common.h"

/* NTSC-U counterpart of func_L39_00573948 (src/levels/shared/L39_00573580.c) */
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
extern Cam_00573208 D_L39_0024DF80[];
extern s32 D_L39_002412A8;
typedef struct {
    u8 pad0[0x1C];
    u8 *p1C;
    u8 pad20[0x20 - 0x20];
} Slot_005732E0;
extern Slot_005732E0 *D_L39_0024B950;
typedef struct {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0xAA - 0x36];
    s16 hAA;
    u8 padAC[0x100 - 0xAC];
} Ent_00573580;
extern Ent_00573580 *D_L39_0024C05C;
extern Ent_00573580 *D_L39_0024C064;
extern void func_0037E568(s32, s32, s32, f32, f32, f32, f32);

/* localdecomp:start func_L39_00572C20 */
typedef struct {
    u8 pad0[0x7E];
    s16 h7E;
    u8 pad80[4];
    s16 h84;
    u8 pad86[0xE];
    s32 w94;
} Obj_00573948;



extern s32 D_L39_00242A94;
extern f32 D_L39_0024BAD0_00572C20;

void func_L39_00572C20(Obj_00573948 *self) {
    Ent_00573580 *p;
    u8 *t;
    Ent_00573580 *end;
    if (self->w94 > 0) return;
    if (D_L39_002412A8 != 0) return;
    t = D_L39_0024B950[self->h84].p1C;
    if (D_L39_00242A94 != 0) {
        D_L39_0024BAD0_00572C20 = 0.0f;
    } else {
        *(s16 *)(t + 0x44) = 0x1E;
    }
    func_0037E568(0, 0, 0, 1.1100293f, 0.005f, 0.2f, 0.0f);
    self->h7E = 4;
    (D_L39_0024DF80 + self->w94)->w458 = 3;
    for (p = D_L39_0024C05C; p < D_L39_0024C064; p++) {
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
/* localdecomp:end func_L39_00572C20 */
