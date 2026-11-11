#include "common.h"

typedef struct {
    s32 f0;
    u8 pad[16];
} S_003F38D0;

/* localdecomp:start func_L01_003F5A78 */
extern S_003F38D0 D_L01_002F7680[];
s32 func_L01_003F5A78(s32 id) {
    s32 i;
    for (i = 0; D_L01_002F7680[i].f0 != -1 && D_L01_002F7680[i].f0 != id; i++) {
    }
    return i;
}
/* localdecomp:end func_L01_003F5A78 */

/* localdecomp:start func_L01_003F5AC0 */
typedef int u128_003F5AC0 __attribute__((mode(TI)));
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001E5510[];
extern void func_L01_004E1F00(s32);
extern u8 *func_L01_003F34E0(s32, s32);
extern void func_L01_003F4E70(s32, s32);
extern void func_L01_003F37A0(u8 *);
extern void func_L01_003F3398(s32);
extern void func_L01_003F3068(s32);

/* camera_reset_follow: makes the follow camera current with no blend and re-initialises it. */
void func_L01_003F5AC0(s32 player, s32 reset_timer) {
    u8 *camera = D_L01_001E2A40 + player * 0x460; /* GameCamera, 0x460 per player */
    u8 *update;
    f32 *update_pos;
    f32 *hero_pos;
    f32 *follow_pos;

    func_L01_004E1F00(0); /* camera_hero_copy */
    /* end the current camera: active (+0x8E), asked_for (+0x7D), ending (+0x7E) */
    if (*(u8 **)(camera + 0x50) != 0) {
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 0;
        *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
        *(s16 *)(*(u8 **)(camera + 0x50) + 0x7E) = 0;
    }
    /* the follow camera (class 0) becomes current, with player's follow block (0x780 each) */
    *(u8 **)(camera + 0x50) = func_L01_003F34E0(player, 0);
    *(s16 *)(*(u8 **)(camera + 0x50) + 0x8E) = 1;
    *(u8 **)(*(u8 **)(camera + 0x50) + 0x70) = D_L01_001E5510 + player * 0x780;
    *(u8 *)(*(u8 **)(camera + 0x50) + 0x7D) = 0;
    *(s16 *)(camera + 0x2A0) = 0; /* blend_state: no blend */
    func_L01_003F4E70(player, 1);
    if (reset_timer) {
        *(s32 *)(camera + 0x454) = 0;
    }
    func_L01_003F37A0(*(u8 **)(camera + 0x50));
    func_L01_003F3398(player);
    /* the camera takes the follow camera's position */
    update = *(u8 **)(camera + 0x50);
    *(u128_003F5AC0 *)camera = *(u128_003F5AC0 *)(update + 0x30);
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
/* localdecomp:end func_L01_003F5AC0 */

INCLUDE_ASM("asm/levels", func_L01_003F5BE0);

INCLUDE_ASM("asm/levels", func_L01_003F5E88);

INCLUDE_ASM("asm/levels", func_L01_003F5EE0);

INCLUDE_ASM("asm/levels", func_L01_003F5F10);

INCLUDE_ASM("asm/levels", func_L01_003F5FC0);

INCLUDE_ASM("asm/levels", func_L01_003F6048);

LINKER_REMNANT("asm/levels", func_L01_003F6208);
