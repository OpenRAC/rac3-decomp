#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00451700 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
extern void func_003C5060(s32, Vec4 *, Vec4 *, s32);
extern f32 func_0038D160(f32, f32);
f32 func_L01_00451700(s32 a0, Vec4 *a1, s32 a2) {
    Vec4 t;
    t = *a1;
    func_003C5060(a0, &t, &t, a2);
    return func_0038D160(t.v[0], t.v[1]);
}
/* localdecomp:end func_L01_00451700 */

/* localdecomp:start func_L01_00451738 */
/* func_L01_00451738: from the staged near miss. Retail's abs.s comes after the ld $ra, where
   __builtin_fabsf put it before; include/vu0.h's fabs_asm, the game's fabs, is scheduled as
   retail's. */
f32 func_L01_00451738(s32 a0, Vec4 *a1, s32 a2) {
    Vec4 t;
    f32 r;

    t = *a1;
    r = func_L01_00451700(a0, &t, a2);
    return fabs_asm(r);
}
/* localdecomp:end func_L01_00451738 */

LINKER_REMNANT("asm/levels", func_L01_00451760);

INCLUDE_ASM("asm/levels", func_L01_00451768);
