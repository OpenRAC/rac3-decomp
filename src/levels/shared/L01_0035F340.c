#include "common.h"

/* localdecomp:start func_L01_0035F340 */
#include "structs/moby.h"
#include "structs/weapon.h"
typedef int u128_35F340 __attribute__((mode(TI)));
/* The Nitro blast's pvars (class 0x1858; open-rac-engine docs/research/weapons.md, "The blast":
   12 frames of flash, then 20 of a ball growing from 2 to 6 u, pushing at 1.5). The Eruptor's blast
   (func_L01_0038B9A8) starts the same fields 0x10 later; unk_ fields are ones not read yet. */
typedef struct {
    u128_35F340 velocity;          /* 0x00 */
    s32 unk_10;                    /* 0x10: 0 */
    s32 unk_14;                    /* 0x14: 83 */
    f32 push;                      /* 0x18: 1.5 */
    s32 unk_1C;                    /* 0x1C: 17 */
    s32 unk_20;                    /* 0x20: 60 */
    f32 unk_24;                    /* 0x24: 1.0 */
    struct Moby *owner;            /* 0x28 */
    u8 pad_2C[0x34 - 0x2C];
    s32 unk_34;                    /* 0x34: 0 */
    s32 unk_38;                    /* 0x38: the spawner's last argument */
} NitroBlast_35F340;
__asm__(".extern D_L01_001DD708, 4");
__asm__(".extern D_L01_001DD70C, 4");
__asm__(".extern D_L01_001DD704, 4");
__asm__(".extern D_L01_001DD710, 4");
extern s32 D_L01_001DD708, D_L01_001DD70C;
extern f32 D_L01_001DD704, D_L01_001DD710;
extern f32 D_L01_001E1AA0, D_L01_001E1AA4, D_L01_001E1AA8, D_L01_001E1AAC, D_L01_001E1AB0, D_L01_001E1AB4;
extern u8 D_00142A60[];
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
/* nitro_blast_spawn: spawns the Nitro blast (class 0x1858) and sets the Nitro's acid mod
   (item_flags bit 3) from V2 (its weapon row's level above 0). Arguments 3 to 9 are not read. */
struct Moby *func_L01_0035F340(struct Moby *owner, u128_35F340 *position, u128_35F340 *velocity, s32 unused_3, s32 unused_4, s32 unused_5, s32 unused_6, s32 unused_7, s32 unused_8, s32 unused_9, s32 unk_38)
{
    extern struct Moby *func_003C24B0_0035E638(s32, s32);
    extern f32 func_00382538(void);
    struct Moby *blast = func_003C24B0_0035E638(0x1858, 0x80);
    NitroBlast_35F340 *vars;
    if (blast != 0) {
        *(u128_35F340 *)&blast->position = *position;
        vars = blast->pvar;
        ((u8 *)blast)[0x30] = 255;
        blast->draw_dist = 255;
        blast->state = 0;
        vars->unk_14 = 83;
        vars->push = 1.5f;
        vars->unk_1C = 17;
        vars->unk_10 = 0;
        D_L01_001DD708 = 0;
        D_L01_001DD70C = 0;
        vars->unk_20 = 60;
        vars->unk_24 = 1.0f;
        D_L01_001DD704 = 1.0f;
        vars->owner = owner;
        vars->velocity = *velocity;
        D_L01_001DD710 = 1.0f;
        vars->unk_38 = unk_38;
        vars->unk_34 = 0;
        D_L01_001E1AA0 = func_00382538();
        D_L01_001E1AA4 = func_00382538();
        D_L01_001E1AA8 = func_00382538();
        D_L01_001E1AAC = func_00382538();
        D_L01_001E1AB0 = func_00382538();
        D_L01_001E1AB4 = func_00382538();
        if (D_L01_002C5600[D_001425C0[0x77]].level != 0) D_00142A60[0x77] |= 8;
    }
    return blast;
}
/* localdecomp:end func_L01_0035F340 */
