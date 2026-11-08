/* Near miss for func_L01_003E31A8 (open-rac-engine names it ice_block_spawn), file
   src/levels/shared/L01_003E1F48.c, checked as if that file had @ps2as (its four blocks still
   MATCH with it; under the default assembler a nop follows the mtc1 of 0.75, which retail
   lacks); uses that file's context (its func_003C24B0 declaration):
   tools/check.py nonmatching/levels/func_L01_003E31A8.c func_L01_003E31A8 --as ps2as.
   2 words differ: retail loads the second 0x7F (addiu $a1, $zero, 0x7f, for +0x32) before the
   ori of the mode flags; here the ori comes first. Every order of the five header statements
   (120) and every placement of the matrix/rotation pointer locals gives 2 diff; u16/s16, a
   bitfield and an explicit `x = x | 0x100` don't change it. What did match: the 64-byte
   matrix local after the 16-byte middle (stack order), the matrix and rotation pointers
   (its $s1/$s2), and the three +0x30 stores in the order 0x30, 0x32, 0x31. */
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

extern void func_L01_004CB128(u128_3E31A8 *at, Moby_3E31A8 *target, s32 flag);
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
