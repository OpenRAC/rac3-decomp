#include "common.h"

/* localdecomp:start func_L01_0050B3C0 */
extern u8 D_001A4BE0[];
extern s32 func_L01_0050B678(s32, s32 *, s32 *);
extern void func_003BE4F0(void *, s32, s32, s32);

/* clank_fidget: blends the two back-item mobys on the hero to the animation values chosen by
 * hero_back_pick, using moby_anim_blend; does nothing unless both exist and the first is in the
 * expected state. */
void func_L01_0050B3C0(void) {
    u8 *base = D_001A4BE0;
    u8 *first = *(u8 **)(base + 4848);
    u8 *second = *(u8 **)(base + 4852);
    s32 values[2];
    if (first == 0 || second == 0 || first[67] != 1) {
        return;
    }
    if (func_L01_0050B678(0, values, values + 1) == 0) {
        return;
    }
    func_003BE4F0(first, values[0], 0, 7);
    func_003BE4F0(second, values[1], 0, 7);
}
/* localdecomp:end func_L01_0050B3C0 */
