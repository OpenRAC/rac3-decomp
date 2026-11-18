#include "common.h"

/* localdecomp:start func_L31_00346470 */
extern f32 D_001A4C60[];
extern s32 func_L31_003464C0(u8 *, f32, f32, f32, s32, f32, f32, f32, f32);

void func_L31_00346470(u8 *obj, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    func_L31_003464C0(obj, D_001A4C60[0], a, b, a1, c, d, e, f);
}
/* localdecomp:end func_L31_00346470 */

/* localdecomp:start func_L31_003464C0 */
#include "vu0.h"

extern f32 func_0038DB00(f32, f32);
extern void func_L01_00448890(u8 *, f32, s32, f32, f32, f32, s32);

s32 func_L31_003464C0(u8 *obj, f32 A, f32 B, f32 C, s32 a1, f32 D, f32 E, f32 F, f32 G) {
    f32 x;
    s32 sgn;
    f32 r;

    if (*(f32 *)(obj + 0x10) < A) {
        x = C;
        sgn = 1;
    } else {
        x = B;
        sgn = -1;
    }
    r = func_0038DB00(*(f32 *)(obj + 0xF8), x);
    if (G < fabs_asm(r)) {
        func_L01_00448890(obj + 0xF8, x, a1, E, F, D, sgn);
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L31_003464C0 */
