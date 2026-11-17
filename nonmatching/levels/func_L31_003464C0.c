/* func_L31_003464C0: 7 diff with the file's flags. The compiled frame is right in size and the call is right, but the variables x and sgn take the other saved registers (retail: sgn in $s2, a1 in $s1; here swapped), and the declaration and branch orders tried did not change that. The wrapper func_L31_00346470 declares this function with seven floats and no pointer, which conflicts with the prototype used here, so placement needs that extern fixed (its caller passes $4 and $5 through). */
#include "vu0.h"

extern f32 func_0038DB00(f32 a, f32 b);
extern void func_L01_00448890(u8 *p, f32 x, s32 a1, f32 e, f32 f, f32 d, s32 sgn);

s32 func_L31_003464C0(u8 *obj, s32 a1, f32 A, f32 B, f32 C, f32 D, f32 E, f32 F, f32 G) {
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
