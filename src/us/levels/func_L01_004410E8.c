#include "common.h"

/* localdecomp:start func_L01_004410E8 */
extern s32 func_L01_00417EA0(void);
extern void func_003DFF90(s32);
extern u8 D_00142660[];

/* challenge_mult_kill: in challenge mode, bumps a byte counter in the global state each call; when
 * twice the counter reaches the level byte plus 1 it shows the bolts HUD (0xB4), resets the counter
 * and raises the level, up to 20. */
void func_L01_004410E8(void) {
    u8 *state;
    if (func_L01_00417EA0() != 0) {
        state = D_00142660;
        if (state[0x5A] + 1 < 0x14) {
            state[0x5B] = state[0x5B] + 1;
            if (((state[0x5B] & 0xFF) << 1) >= state[0x5A] + 1) {
                func_003DFF90(0xB4);
                state[0x5B] = 0;
                state[0x5A] = state[0x5A] + 1;
            }
        }
    }
}
/* localdecomp:end func_L01_004410E8 */
