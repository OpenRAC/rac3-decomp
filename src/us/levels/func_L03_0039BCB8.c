#include "common.h"

/* localdecomp:start func_L03_0039BCB8 */
extern void func_L03_0042EEF8(u8 *, s32, s32, s32);
extern void func_L03_003F9310(u8 *, u8 *, f32);
extern void func_L03_00443538(u8 *, u8 *, u8 *);
extern void func_L03_0042F238(u8 *, s32, s32);
extern u8 *D_001A71A0[];

void func_L03_0039BCB8(u8 *object, u8 *vars) {
    if (object[0x43] != 1) {
        func_L03_0042EEF8(object, 1, 0, 10);
    }
    *(f32 *)(vars + 0x50) = 0.0013888889f;
    *(f32 *)(vars + 0x54) = 0.0027777778f;
    *(f32 *)(vars + 0x58) = 0.050000004f;
    if (0.050000004f < *(f32 *)(vars + 0xE0)) {
        func_L03_003F9310(vars + 0xD0, vars + 0xD0, 0.050000004f);
        *(f32 *)(vars + 0xE0) = *(f32 *)(vars + 0x58);
    }
    func_L03_00443538(object, D_001A71A0[0], vars + 0x120);
    func_L03_0042F238(object, 3, -1);
}
/* localdecomp:end func_L03_0039BCB8 */
