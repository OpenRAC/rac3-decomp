#include "common.h"

/* localdecomp:start func_L03_0039BD78 */
extern void func_L03_0042EEF8(u8 *, s32, s32, s32);
extern void func_L03_00443538(u8 *, u8 *, u8 *);
extern void func_L03_0042F238(u8 *, s32, s32);
extern u8 *D_001A71A0[];

/* Switches the object to state 2 if needed, sets three float parameters in its vars, calls
 * func_L03_00443538 with the first table entry, then func_L03_0042F238 with 2 and -1. */
void func_L03_0039BD78(u8 *object, u8 *vars) {
    if (object[0x43] != 2) {
        func_L03_0042EEF8(object, 2, 0, 10);
    }
    *(f32 *)(vars + 0x58) = 0.20000002f;
    *(f32 *)(vars + 0x50) = 0.0033333334f;
    *(f32 *)(vars + 0x54) = 0.004166667f;
    func_L03_00443538(object, D_001A71A0[0], vars + 0x120);
    func_L03_0042F238(object, 2, -1);
}
/* localdecomp:end func_L03_0039BD78 */
