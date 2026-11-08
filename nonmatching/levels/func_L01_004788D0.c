/* Near miss for func_L01_004788D0 (open-rac-engine names it hud_weapon_fill), file
   src/levels/shared/L01_004783E0.c (no @ps2as); uses that file's context:
   tools/check.py nonmatching/levels/func_L01_004788D0.c func_L01_004788D0.
   11 words differ, all register choices: (1) the D_L01_001E15E0 fallback: retail builds the
   address in $a0 (hi in $v1) and copies it to $v0 in the bnez delay slot, here it is built
   straight into $v0 with a nop there; (2) D_L01_001D6694 == 5: retail lui $v1/lw $v1 then
   li $v0, 5, here li $a0, 5 between; (3) recent_guns[1] is loaded into $v1 in retail, $v0
   here. func_003E6A60 returning s32 fixed the first $v1 (12 -> 11); return types of the
   other callees, if/else and ternary forms of the fallback, a local for the gun, and
   section(".data") for D_L01_001D6694 did not help. */
#include "common.h"

typedef struct {
    u8 pad0[0x38];
    u16 icon;       /* 0x38 */
    u8 pad3A[0x8A - 0x3A];
    u16 max_ammo;   /* 0x8A */
    u8 pad8C[0xF0 - 0x8C];
} GunRow_004788D0;
typedef struct {
    u8 pad0[0x14];
    s32 recent_guns[2]; /* 0x14: recent_guns[1] and [2] */
} Game_004788D0;
extern u8 D_L01_001D8048;
extern u8 D_L01_001D8049;
extern s32 D_L01_001D6694[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142660[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_001E15E0[];
extern void func_003E82F8(void);
extern void *func_003E6C08();
extern s32 func_003E6A60(void *);
extern void *func_003E6518(s32);
extern void func_003E6F18(void *, s32);
extern s32 func_L01_004785E8(void);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);
extern void func_L01_0047C220(s32);

/* hud_weapon_fill: each gameplay frame with a hand item other than the wrench: its icon,
   recent_guns[1] and [2] smaller, the ammo, the XP bar and V label; keeps the weapon HUD
   up for 20 more frames. */
void func_L01_004788D0(void) {
    void *group;
    s32 item;
    Game_004788D0 *game;

    if (D_L01_001D8049 != 0) {
        return;
    }
    func_003E82F8();
    group = D_L01_001E15E0;
    if (*(s32 *)((u8 *)group + 4) == 0) {
        group = func_003E6C08();
    }
    func_003E6A60(group);
    if (D_L01_001D6694[0] != 5 && D_L01_001D8048 == 0) {
        item = func_L01_004785E8();
        if (item != 0) {
            func_L01_0047B798(((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[item]].icon, 0);
            game = (Game_004788D0 *)D_00142660;
            if (game->recent_guns[0] != 0) {
                func_L01_0047B798(((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[game->recent_guns[0]]].icon, 1);
            } else {
                func_L01_0047B798(0, 1);
            }
            game = (Game_004788D0 *)D_00142660;
            if (game->recent_guns[1] != 0) {
                func_L01_0047B798(((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[game->recent_guns[1]]].icon, 2);
            } else {
                func_L01_0047B798(0, 2);
            }
            func_L01_0047B820(D_001427F0[item], ((GunRow_004788D0 *)D_L01_002C5600)[D_001425C0[item]].max_ammo);
            func_L01_0047B9B8(item);
            func_L01_0047C220(8);
        }
    }
    D_L01_001D8048 = 0;
    func_003E6F18(func_003E6518(0), 20);
}
