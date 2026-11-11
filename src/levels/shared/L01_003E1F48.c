#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003E1F48);

INCLUDE_ASM("asm/levels", func_L01_003E1F68);

/* localdecomp:start func_L01_003E21C8 */
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

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 p10[0x10];
    M_003E0480 *x20[4];
    s32 x30[4];
    s32 x40[4];
} V_003E0480;

extern M_003E0480 *func_003C24B0(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_004450F0(M_003E0480 *, s32, s32);
extern s32 func_L01_0044E7D8(M_003E0480 *);
extern void func_0038D308(void *, void *);
extern M_003E0480 **func_L01_00448FB8(M_003E0480 *);
extern void func_L01_003E2418(M_003E0480 *, V_003E0480 *);

s32 func_L01_003E21C8(M_003E0480 *m, s128_3E0480 *pos, s128_3E0480 *rot, M_003E0480 **list, s32 n) {
    M_003E0480 *o;
    V_003E0480 *v;
    M_003E0480 *e;
    M_003E0480 **l;
    s32 i;
    s32 j;

    o = func_003C24B0(7721, 128);
    if (o != 0) {
        v = o->x68;
        func_0038CB78(v, 0, 80);
        v->x8 = 0;
        func_L01_004450F0(o, 1, -1);
        o->xB8 = m;
        o->x30 = 255;
        o->x10 = *pos;
        v->x0 = m->x34;
        v->x4 = func_L01_0044E7D8(m);
        m->x10 = *pos;
        m->xF0 = *rot;
        func_0038D308(m->xC0, &m->xF0);
        if (n >= 5) {
            n = 4;
        }
        m->x31 = 0;
        m->x34 |= 1;
        v->xC = n;
        for (i = 0; i < n; i++) {
            e = list[i];
            v->x20[i] = e;
            v->x30[i] = e->x34;
            v->x40[i] = func_L01_0044E7D8(e);
            e->x31 = 0;
            e->x34 |= 1;
        }
        if (v->xC < 4) {
            l = func_L01_00448FB8(m);
            if (l != 0) {
                for (j = 0; j < 4; j++) {
                    if (l[j] != 0) {
                        e = l[j];
                        v->x20[v->xC] = e;
                        v->x30[v->xC] = e->x34;
                        v->x40[v->xC] = func_L01_0044E7D8(e);
                        e->x31 = 0;
                        e->x34 |= 1;
                        if (++v->xC == 4) {
                            break;
                        }
                    }
                }
            }
        }
        func_L01_003E2418(o, v);
        return 1;
    }
    m->x10 = *pos;
    m->xF0 = *rot;
    func_0038D308(m->xC0, &m->xF0);
    m->x31 = 1;
    m->x34 &= ~1;
    return 0;
}
/* localdecomp:end func_L01_003E21C8 */

INCLUDE_ASM("asm/levels", func_L01_003E2418);

INCLUDE_ASM("asm/levels", func_L01_003E25B8);

INCLUDE_ASM("asm/levels", func_L01_003E2BD8);

INCLUDE_ASM("asm/levels", func_L01_003E2DB8);

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
