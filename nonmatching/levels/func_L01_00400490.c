/* near miss (open-rac-engine names it help_checkpoint_refund): 13 words differ, register allocation only:
 * retail keeps the area in $a2 and the level in $a1, and loads the level before the 40 constant.
 * Also needs a lui read of D_001D545C while func_L01_00400430 in the same file reads it through $gp
 * (sized extern), so this uses an unsized alias D_001D545C_00400490 (no symbol address for it yet). */
#include "common.h"

/* WeightTap_00400390 is in src/levels/shared/L01_003FE908.c's prelude. */
extern u8 D_00142692[];
extern s32 D_001D545C_00400490[]; /* the level number, read with lui here (the file's other blocks read it via $gp) */
extern WeightTap_00400390 D_L01_002C0160[][16][10];

/* help_checkpoint_refund: 100 / the area's first help weight, rounded up; 0 in challenge mode. */
s32 func_L01_00400490(s32 area) {
    WeightTap_00400390 *tap;
    s32 level;
    s32 refund;

    if (D_00142692[0] != 0) {
        return 0;
    }
    level = D_001D545C_00400490[0];
    tap = D_L01_002C0160[level][area];
    refund = 100 / tap->weight;
    if (100 % tap->weight != 0) {
        return refund + 1;
    }
    return refund;
}
