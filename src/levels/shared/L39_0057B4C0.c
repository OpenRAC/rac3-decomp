#include "common.h"

/* localdecomp:start func_L39_0057B4C0 */
/* from this repository's func_L01_003F5AC0 (the same camera reset) */
typedef int u128_0057B4C0 __attribute__((mode(TI)));
extern u8 D_L39_0024DE80[];
extern u8 D_L39_00257C90[];
extern s32 D_L39_00241164;
extern s32 D_L39_0024BF5C;
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_0063B0A8(u8 *);
extern u8 *func_L01_003F34E0(s32, s32);
extern void func_00384498(s32, s32);
extern void func_L01_003F37A0(u8 *);
extern void func_00382A80(s32);
extern void func_L01_003F3068(s32);

void func_L39_0057B4C0(s32 player, s32 reset_timer) {
    u8 *camera = D_L39_0024DE80 + player * 0x460;
    u8 *update;
    u8 *q;
    f32 *update_pos;
    f32 *hero_pos;
    f32 *follow_pos;

    q = func_L39_0061BF38(player);
    if (*(s32 *)(q + 0x2530) != 0) {
        func_L39_0063B0A8(q);
    } else {
        *(s32 *)(camera + 0x240) = D_L39_0024BF5C;
        *(s32 *)(camera + 0x284) = D_L39_00241164;
    }
    if (*(u8 **)(camera + 0x50) != 0) {
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 0;
        *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x7E) = 0;
    }
    *(u8 **)(camera + 0x50) = func_L01_003F34E0(player, 0);
    *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 1;
    *(u8 **)(*(u8 **)(camera + 0x50) + 0x70) = D_L39_00257C90 + player * 0x780;
    *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
    *(s16 *)(camera + 0x2A0) = 0;
    func_00384498(player, 1);
    if (reset_timer) {
        *(s32 *)(camera + 0x454) = 0;
    }
    func_L01_003F37A0(*(u8 **)(camera + 0x50));
    func_00382A80(player);
    update = *(u8 **)(camera + 0x50);
    *(u128_0057B4C0 *)camera = *(u128_0057B4C0 *)(update + 0x30);
    update_pos = (f32 *)(update + 0x64);
    update_pos[0] = ((f32 *)camera)[0];
    update_pos[1] = ((f32 *)camera)[1];
    update_pos[2] = ((f32 *)camera)[2];
    hero_pos = (f32 *)(camera + 0x190);
    follow_pos = (f32 *)(camera + 0x60);
    follow_pos[0] = hero_pos[0];
    follow_pos[1] = hero_pos[1];
    follow_pos[2] = hero_pos[2];
    func_L01_003F3068(player);
}
/* localdecomp:end func_L39_0057B4C0 */

INCLUDE_ASM("asm/levels", func_L39_0057B610);
