#include "common.h"

/* localdecomp:start func_L03_0043FC00 */
extern u8 *func_00382348(void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);

void func_L03_0043FC00(void *a0, s32 a1, u8 *a2, s32 a3, s32 a4, f32 f0, f32 f1, f32 f2, f32 f3, u8 a5, f32 f4, f32 f5,
                       s32 a6, s32 a7, f32 f6) {
    u8 *r = func_00382348(a0);
    if (r != 0 && r[0xE] == 2) {
        return;
    }
    func_L01_00451FE0(a0, a1, a2, f0, f1, f2, f3, a5, f4, f5, a6, a7, 0, 0, -1.0f, f6, a3, a4);
}
/* localdecomp:end func_L03_0043FC00 */
