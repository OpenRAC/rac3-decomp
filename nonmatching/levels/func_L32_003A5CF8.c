/* func_L32_003A5CF8: 41 diff with the file's flags. Register assignment is swapped (retail keeps obj in $s0, p in $s1), the comparison with the -0.06 constant uses c.olt.s where retail uses c.lt.s, and the 0.0f/-0.06 constant registers are laid out differently. Tried: nested if/else for the flag test and the 0x48 store (b, 63 diff). */
#include "common.h"
extern f32 func_L32_00348900(u8 *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L32_00349630(void *, void *, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);
extern f32 D_L32_001DE8E8;
extern f32 D_L32_001DE928;
extern f32 D_L32_001DE92C;
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DE920;
extern f32 D_L32_001DE91C;
extern f32 D_L32_001DE918;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA40;

void func_L32_003A5CF8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    f32 f21;
    f32 v;

    f21 = func_L32_00348900(obj);
    if (func_L01_004561B8(obj) != 0) {
        v = D_L32_001DE928;
        if (*(f32 *)(obj + 0xF8) == D_L32_001DE8E8) {
            v = -v;
        }
        *(f32 *)(p + 0x90) = v;
        *(f32 *)(p + 0x98) = D_L32_001DE92C;
    }
    func_L32_00349630(obj, obj + 0x10, D_L32_001DE9D4, *(f32 *)(p + 0x98), *(f32 *)(p + 0x148),
                      D_L32_001DE920, D_L32_001DE91C, 0.0f, -1.0f);
    if (obj[0x42] != obj[0x43] || f21 < D_L32_001DE91C) {
        v = D_L32_001DE928;
    } else {
        v = 0.0f;
    }
    *(s32 *)(p + 0x110) = func_L30_0034D1E8(obj, obj + 0x10, p + 0x90, p + 0x140, D_L32_001DE9D4, D_L32_001DE9D4,
                                             D_L32_001DEA88, v, 0.0f, D_L32_001DEA40, 1, 1, 1, 0);
    if ((obj[0x60] & 2) || D_L32_001DE918 <= f21) {
        *(f32 *)(obj + 0x48) = 0.0f;
        func_L32_003A52A8(obj, 0x42);
    }
}
