/* func_L01_0035F340 (level 01, 0x0035F340, 0x140 bytes), shared by 34 levels.
 *
 * Spawns a 0x1858-byte object with the 0x80-byte "kind 0x1858" allocator, stores the
 * caller's position and velocity quads into it and fills the object at +0x68 with a
 * descriptor (83/1.5f/17/0/60/1.0f, the owner, the passed value), zeroes four
 * $gp floats and seeds six $gp floats from func_00443A78. When the player's current
 * weapon row has a non-zero kind byte it sets bit 3 of D_00142A60+0x77.
 *
 * Retail saves $s0-$s3 and $ra with sq in ascending 16-byte slots (frame 0x50), so it
 * is a config/levels/sq_ra_funcs.txt entry (tools/asm_filter.py, sq_rewrite) compiled
 * without -fopt-stack; see docs/wiki/Matching-Patterns.md, "Functions that save $ra
 * with sq". All 16-byte copies are the u128(TI) assignment the doc's recipe uses.
 */
#include "common.h"
/* localdecomp:start func_L01_0035F340 */
typedef int u128_0035F340 __attribute__((mode(TI)));

/* Descriptor allocated by the spawn call; m+0x68 points at it. */
typedef struct {
    u128_0035F340 velocity; /* 0x00 */
    s32 x10;                /* 0x10 */
    s32 x14;                /* 0x14 */
    f32 x18;                /* 0x18 */
    s32 x1c;                /* 0x1c */
    s32 x20;                /* 0x20 */
    f32 x24;                /* 0x24 */
    s32 owner;              /* 0x28 */
    s32 x2c;                /* 0x2c */
    s32 x30;                /* 0x30 */
    s32 x34;                /* 0x34 */
    s32 x38;                /* 0x38 */
} Vars_0035F340;

/* One 0xF0-byte player-weapon row; byte 1 is its kind. */
typedef struct {
    u8 x0, kind;
    u8 pad[0xee];
} Gun_0035F340;

/* $gp slots: 0x1DC8B0 (level 1 gp) + 0xE54/0xE58/0xE5C/0xE60. */
__asm__(".extern D_L01_001DD704, 4");
__asm__(".extern D_L01_001DD708, 4");
__asm__(".extern D_L01_001DD70C, 4");
__asm__(".extern D_L01_001DD710, 4");
extern f32 D_L01_001DD704, D_L01_001DD710;
extern s32 D_L01_001DD708, D_L01_001DD70C;
extern f32 D_L01_001E1AA0, D_L01_001E1AA4, D_L01_001E1AA8, D_L01_001E1AAC, D_L01_001E1AB0,
    D_L01_001E1AB4;
extern u8 D_00142A60[];
extern u8 D_00142637[];
extern Gun_0035F340 D_L01_002C5600_0035F340[];

u8 *func_L01_0035F340(s32 owner, u128_0035F340 *position, u128_0035F340 *velocity, s32 unused4,
                      s32 unused5, s32 unused6, s32 unused7, s32 unused8, s32 unused9,
                      s32 unused10, s32 value)
{
    extern u8 *func_003C24B0_0035E638(s32, s32);
    extern f32 func_00382538(void);
    u8 *m = func_003C24B0_0035E638(0x1858, 0x80);
    Vars_0035F340 *v;

    if (m != 0) {
        *(u128_0035F340 *)(m + 0x10) = *position;
        v = *(Vars_0035F340 **)(m + 0x68);
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x20] = 0;
        v->x14 = 0x53;
        v->x18 = 1.5f;
        v->x1c = 0x11;
        v->x10 = 0;
        D_L01_001DD708 = 0;
        D_L01_001DD70C = 0;
        v->x20 = 0x3C;
        v->x24 = 1.0f;
        D_L01_001DD704 = 1.0f;
        v->owner = owner;
        v->velocity = *velocity;
        D_L01_001DD710 = 1.0f;
        v->x38 = value;
        v->x34 = 0;
        D_L01_001E1AA0 = func_00382538();
        D_L01_001E1AA4 = func_00382538();
        D_L01_001E1AA8 = func_00382538();
        D_L01_001E1AAC = func_00382538();
        D_L01_001E1AB0 = func_00382538();
        D_L01_001E1AB4 = func_00382538();
        if (((Gun_0035F340 *)((s32)D_L01_002C5600_0035F340
                              + D_00142637[0] * 0xF0))->kind != 0) {
            D_00142A60[0x77] |= 8;
        }
    }
    return m;
}
/* localdecomp:end func_L01_0035F340 */
