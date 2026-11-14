#include "common.h"

/* localdecomp:start func_L01_004C57B0 */
extern f32 D_L01_001E11C0_004C57B0;
extern s32 D_L01_001E11C4;

/* shield_charger_absorb: subtracts a damage amount from the shield charge and returns any overshoot
 * below zero (clamping the charge to 0); returns 0 if a cooldown flag is set, and otherwise starts
 * a 15-frame cooldown. */
f32 func_L01_004C57B0(f32 amount) {
    f32 remaining;
    f32 overshoot = 0.0f;
    if (D_L01_001E11C4 != 0) {
        return 0.0f;
    }
    remaining = D_L01_001E11C0_004C57B0 - amount;
    D_L01_001E11C0_004C57B0 = remaining;
    if (remaining < 0.0f) {
        overshoot = -remaining;
        *(s32 *)&D_L01_001E11C0_004C57B0 = 0;
    }
    D_L01_001E11C4 = 15;
    return overshoot;
}
/* localdecomp:end func_L01_004C57B0 */
