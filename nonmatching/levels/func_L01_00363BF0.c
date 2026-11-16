/* PAL near miss (Codex wave 6): near miss: 47 words differ with the file's flags.
 * Worker's note: 47 diff: loop invariant 1.4f remains in loop instead of f23; three wordings same bytes; best log build/codex/w281/func_L01_00363BF0.try1.log
 */
#include "common.h"
/* localdecomp:start func_L01_00363BF0 */
extern u8 *D_L01_001E0028;
extern u8 D_L01_0028E430[];
void func_L01_00363BF0(u8 *moby)
{
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_002F8D40(u8 *, u8 *, s32, f32, f32);
    u8 *p = D_L01_001E0028;
    while (p != 0) {
        if (func_0038CF00(p + 0x10, D_L01_0028E430) < 2.5f ||
            func_0038CF00(p + 0x10, D_L01_0028E430 - 0x30) < 1.7f ||
            func_0038CF00(p + 0x10, D_L01_0028E430 - 0x50) < 1.4f ||
            func_0038CF00(p + 0x10, D_L01_0028E430 - 0x70) < 1.2f) {
            if (p != 0 && *(u8 **)(p + 0x24) != 0 &&
                (*(u8 **)(p + 0x24))[0x46] == 0x13 && p[0x20] == 3) {
                f32 x = func_003824E0(-5.0f, 5.0f) * 0.017453292f;
                f32 y = func_003824E0(0.0f, 5.0f) * 0.017453292f;
                func_L01_002F8D40(p, moby, 1, x, y);
            }
        }
        p = *(u8 **)(p + 0x28);
    }
}
/* localdecomp:end func_L01_00363BF0 */
