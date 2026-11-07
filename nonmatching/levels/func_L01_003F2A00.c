/* near miss (open-rac-engine names it camera_volumes_clear): 2 words differ. The last block
 * schedules `lui $v1` before `sll $v0, $a0, 2`; retail has the sll first. Tried D_L01_001DF900[player],
 * pointer forms, u32 player, s32[1] rows: same. The forward loop (reversed by gcc) gives the loop exactly.
 * Check in L01_003F29F8.c context: tools/check.py nonmatching/levels/func_L01_003F2A00.c func_L01_003F2A00 */
#include "common.h"

/* S_003F2A50 (the 0x40-byte camera volume slot) is in src/levels/shared/L01_003F29F8.c's prelude. */
extern u8 D_L01_001E5C90[];
extern s32 D_L01_001DF900[];

/* camera_volumes_clear: frees all 32 volume slots of a player and sets the active volume to -1. */
void func_L01_003F2A00(s32 player) {
    s32 i;

    for (i = 0; i < 32; i++) {
        ((S_003F2A50 (*)[32])D_L01_001E5C90)[player][i].b29 = 0;
    }
    *(s32 *)((u8 *)D_L01_001DF900 + (player << 2)) = -1;
}
