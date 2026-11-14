#include "common.h"

/* NTSC-U counterpart of func_L01_0039D818 (src/levels/shared/L01_00396B78.c) */
/* localdecomp:start func_L01_0039C2F8 */
typedef int u128_39D818 __attribute__((mode(TI)));
typedef struct {
    u128_39D818 velocity;
    f32 spin_x;                /* 0x10: radians a frame */
    f32 spin_y;                /* 0x14 */
    s32 unk_18;
    u8 pad_1C[0x30 - 0x1C];
    void *owner;               /* 0x30 */
    s32 unk_34;                /* 0x34: from func_L01_004C4A18 */
} BombVars_39D818;
typedef struct {
    u8 pad_0[0x10];
    u128_39D818 position;
    s8 state;
    u8 pad_21[0x23 - 0x21];
    u8 opacity;
    u8 pad_24[0x2C - 0x24];
    f32 scale;
    u8 unk_30;
    u8 pad_31;
    u16 unk_32;
    u8 pad_34[0x68 - 0x34];
    BombVars_39D818 *vars;
} Moby_39D818;

extern void *func_003BCFB0(s32 class_id, s32 flags);
extern f32 func_0037E250(f32 low, f32 high);
extern s32 func_L01_004C4A18(void *moby, void *a1, f32 a2, f32 a3, f32 a4);
extern void func_003C26C8(void *moby);

Moby_39D818 *func_L01_0039C2F8(void *owner, u128_39D818 *position, u128_39D818 *velocity) {
    Moby_39D818 *bomb = func_003BCFB0(0x1899, 0x80);

    if (bomb != 0) {
        BombVars_39D818 *vars;

        bomb->state = 0;
        bomb->unk_32 = 0xFF;
        bomb->unk_30 = 0xFF;
        vars = bomb->vars;
        bomb->position = *position;
        vars->velocity = *velocity;
        bomb->opacity = 0x28;
        bomb->scale = 0.0125f;
        /* 2 pi / 120 to 2 pi / 60 radians a frame */
        vars->spin_x = func_0037E250(0.0523598827f, 0.104719765f);
        vars->spin_y = func_0037E250(0.0523598827f, 0.104719765f);
        vars->owner = owner;
        vars->unk_18 = 0;
        vars->unk_34 = func_L01_004C4A18(bomb, 0, 1.0f, 1.0f, 1.0f);
        func_003C26C8(bomb);
    }
    return bomb;
}
/* localdecomp:end func_L01_0039C2F8 */
