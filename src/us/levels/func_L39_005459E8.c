#include "common.h"

/* NTSC-U counterpart of func_L39_00546278 (src/levels/shared/L39_00546278.c): 25 -> 30 */
/* localdecomp:start func_L39_005459E8 */
typedef struct Ent_00546278 {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
    f32 f30;
    u8 pad34[4];
    s32 w38;
    u8 pad3C[4];
    f32 f40;
    u8 pad44[4];
    s32 w48;
    u8 pad4C[0x460 - 0x4C];
} Ent_00546278;

typedef struct Aux_00546278 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 pad24CA[0x2534 - 0x24CA];
    void *p2534;
} Aux_00546278;

typedef struct Sub_00546278 {
    u8 pad0[0x2D8];
    Aux_00546278 *p2D8;
    Aux_00546278 *p2DC;
} Sub_00546278;

typedef struct Obj_00546278 {
    u8 pad0[0x384];
    Sub_00546278 *p384;
} Obj_00546278;

typedef struct Self_00546278 {
    u8 pad0[0x68];
    Obj_00546278 *p68;
} Self_00546278;

extern Ent_00546278 D_L39_0024DF80[];
extern s32 func_L01_003EFFE0(s32, void *);
extern s32 func_L39_005F0CE0(s32, s32, void *);

void func_L39_005459E8(Self_00546278 *self) {
    Obj_00546278 *o = self->p68;
    Aux_00546278 *m = o->p384->p2D8;
    s32 idx;

    if (m != 0) {
        if (m->b1A14 != 0) {
            func_L01_003EFFE0(0x12, m->p2534);
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->f20 = 0.5f;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w28 = 0x1E;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->f30 = 0.2f;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w38 = 0x1E;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->f40 = 0.02f;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w48 = 0x1E;
            ((Ent_00546278 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
        }
    }
    m = o->p384->p2DC;
    idx = -1;
    if (m != 0) {
        if (m->b1A14 != 0) {
            func_L01_003EFFE0(0x12, m->p2534);
            idx = m->b24C9;
        }
    }
    if (idx >= 0) {
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w28 = 0x1E;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w38 = 0x1E;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DF80))->f20 = 0.5f;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DF80))->f30 = 0.2f;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DF80))->f40 = 0.02f;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w48 = 0x1E;
        ((Ent_00546278 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
    }
    func_L39_005F0CE0(6, 0, self);
}
/* localdecomp:end func_L39_005459E8 */
