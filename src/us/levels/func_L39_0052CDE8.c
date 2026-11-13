#include "common.h"

/* localdecomp:start func_L39_0052CDE8 */
typedef struct Ent_0052CDE8 {
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
} Ent_0052CDE8;

typedef struct Aux_0052CDE8 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 pad24CA[0x2534 - 0x24CA];
    void *p2534;
} Aux_0052CDE8;

typedef struct Sub_0052CDE8 {
    u8 pad0[0x2D8];
    Aux_0052CDE8 *p2D8;
    Aux_0052CDE8 *p2DC;
} Sub_0052CDE8;

typedef struct Obj_0052CDE8 {
    u8 pad0[0x6D0];
    Sub_0052CDE8 *p6D0;
} Obj_0052CDE8;

typedef struct Self_0052CDE8 {
    u8 pad0[0x68];
    Obj_0052CDE8 *p68;
} Self_0052CDE8;

extern Ent_0052CDE8 D_L39_0024DF80[];
extern s32 func_L01_003EFFE0(s32, void *);

void func_L39_0052CDE8(Self_0052CDE8 *self) {
    Obj_0052CDE8 *o = self->p68;
    Aux_0052CDE8 *m = o->p6D0->p2D8;
    s32 idx;

    if (m != 0) {
        if (m->b1A14 != 0) {
            func_L01_003EFFE0(0x12, m->p2534);
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->f20 = 0.3f;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w28 = 0x18;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->f30 = 0.1f;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w38 = 0x18;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->f40 = 0.01f;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w48 = 0x18;
            ((Ent_0052CDE8 *)(m->b24C9 * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
        }
    }
    m = o->p6D0->p2DC;
    idx = -1;
    if (m != 0) {
        if (m->b1A14 != 0) {
            func_L01_003EFFE0(0x12, m->p2534);
            idx = m->b24C9;
        }
    }
    if (idx >= 0) {
        ((Ent_0052CDE8 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w28 = 0x18;
        ((Ent_0052CDE8 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w38 = 0x18;
        ((Ent_0052CDE8 *)(idx * 0x460 + (s32)D_L39_0024DF80))->f20 = 0.3f;
        ((Ent_0052CDE8 *)(idx * 0x460 + (s32)D_L39_0024DF80))->f30 = 0.1f;
        ((Ent_0052CDE8 *)(idx * 0x460 + (s32)D_L39_0024DF80))->f40 = 0.01f;
        ((Ent_0052CDE8 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w48 = 0x18;
        ((Ent_0052CDE8 *)(idx * 0x460 + (s32)D_L39_0024DF80))->w2C = 0;
    }
}
/* localdecomp:end func_L39_0052CDE8 */
