#include "common.h"

/* declared by functions of L01_003E1F48.c, which this file was cut from */
typedef int s128_3E0480 __attribute__((mode(TI)));
typedef struct M_003E0480 {
    u8 p0[0x10];
    s128_3E0480 x10;
    u8 p20[0x10];
    u8 x30;
    u8 x31;
    u8 p32[2];
    u16 x34;
    u8 p36[0x68 - 0x36];
    void *x68;
    u8 p6C[0xB8 - 0x6C];
    struct M_003E0480 *xB8;
    u8 pBC[4];
    u8 xC0[0x30];
    s128_3E0480 xF0;
} M_003E0480;
extern M_003E0480 *func_003C24B0(s32, s32);

/* localdecomp:start func_L01_003E30B8 */
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[2];
    u8 f23;
    u8 pad24[68];
    s32 *vars;
} Obj_003E1328;
extern u8 D_L01_001D66B0[];
extern s32 func_0038CAD0(s32 *);
extern void func_003A52A0(s32, s32, Obj_003E1328 *);
extern void func_L01_00451FE0(Obj_003E1328 *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2880(Obj_003E1328 *);
void func_L01_003E30B8(Obj_003E1328 *o) {
    s32 *v;
    v = o->vars;
    if (o->state == 0) {
        v[0]++;
        o->f23 = v[0] * 2;
        if (v[0] >= 30) {
            o->state = 1;
        }
    } else if (o->state == 1) {
        if (func_0038CAD0(v) != 0) {
            func_003A52A0(0, 0, o);
            func_L01_00451FE0(o, 63, D_L01_001D66B0, 255, 300, 0, 0, 35, 0, 3, 1.5f, 3.0f, 1.5f, 3.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            func_003C2880(o);
        }
    }
}
/* localdecomp:end func_L01_003E30B8 */

/* localdecomp:start func_L01_003E31A8 */
typedef int u128_3E31A8 __attribute__((mode(TI)));
typedef struct {
    u8 pad_0[0x24];
    f32 scale;                 /* 0x24: the class's scale */
} MobyClass_3E31A8;
typedef struct {
    u8 pad_0[0x10];
    u128_3E31A8 position;      /* 0x10 */
    s8 state;                  /* 0x20 */
    u8 pad_21[0x23 - 0x21];
    u8 opacity;                /* 0x23 */
    MobyClass_3E31A8 *pclass;  /* 0x24 */
    u8 pad_28[0x2C - 0x28];
    f32 scale;                 /* 0x2C */
    u8 unk_30;
    u8 unk_31;
    u16 unk_32;
    u16 mode_flags;            /* 0x34: 0x100 draw the matrix at +0xC0 as set */
    u8 pad_36[0x68 - 0x36];
    s32 *vars;                 /* 0x68 */
    u8 pad_6C[0xC0 - 0x6C];
    u128_3E31A8 matrix[3];     /* 0xC0 */
    u128_3E31A8 rotation;      /* 0xF0 */
} Moby_3E31A8;
typedef struct {
    u8 pad_0[0x10];
    f32 size;                  /* 0x10 */
} DamageRecord_3E31A8;

/* It returns a value (unused here): as a `void` callee the flags' `ori` is scheduled one
   place earlier than retail has it. */
extern s32 func_L01_004CB128(u128_3E31A8 *at, Moby_3E31A8 *target, s32 flag);
extern void func_0038CF68(u128_3E31A8 *out, u128_3E31A8 *in, f32 length);
extern void func_0038D570(u128_3E31A8 *out, u128_3E31A8 *matrix);
extern void func_003C48A8(u128_3E31A8 *in, u128_3E31A8 *angles);
extern DamageRecord_3E31A8 *func_00382348(Moby_3E31A8 *moby);
extern void func_003C7C38(Moby_3E31A8 *moby);

/* ice_block_spawn: sets a block of class 0x1E52 on a frozen enemy's middle at its matrix,
   1.5 tall, scaled by the class's size x its damage record's size x 0.75 */
Moby_3E31A8 *func_L01_003E31A8(Moby_3E31A8 *enemy) {
    u128_3E31A8 middle[1];      /* the target mark's point: the enemy's middle */
    u128_3E31A8 turn[4];        /* a matrix made from the block's */
    Moby_3E31A8 *block = (Moby_3E31A8 *)func_003C24B0(0x1E52, 0x80);

    if (block != 0) {
        DamageRecord_3E31A8 *record;
        u128_3E31A8 *matrix;
        u128_3E31A8 *rotation;

        block->unk_30 = 0x7F;
        block->unk_32 = 0x7F;
        block->unk_31 = 1;
        block->mode_flags |= 0x100;
        matrix = block->matrix;
        block->opacity = 0;
        rotation = &block->rotation;
        block->vars[0] = 0;
        func_L01_004CB128(middle, enemy, 0);
        block->position = middle[0];
        block->matrix[0] = enemy->matrix[0];
        block->matrix[1] = enemy->matrix[1];
        block->matrix[2] = enemy->matrix[2];
        func_0038CF68(&block->matrix[2], &block->matrix[2], 1.5f);
        block->rotation = block->position;
        func_0038D570(turn, matrix);
        func_003C48A8(turn, rotation);
        record = func_00382348(enemy);
        if (record != 0) {
            block->scale = block->pclass->scale * record->size * 0.75f;
        } else {
            block->scale = block->pclass->scale;
        }
        block->state = 0;
        func_003C7C38(block);
    }
    return block;
}
/* localdecomp:end func_L01_003E31A8 */

/* localdecomp:start func_L01_003E32E8 */
void func_L01_003E32E8(void) {

}
/* localdecomp:end func_L01_003E32E8 */

/* localdecomp:start func_L01_003E32F0 */
void func_L01_003E32F0(void) {

}
/* localdecomp:end func_L01_003E32F0 */
