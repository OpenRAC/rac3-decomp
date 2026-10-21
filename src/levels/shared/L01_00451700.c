#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_00451738);

LINKER_REMNANT("asm/levels", func_L01_00451760);

INCLUDE_ASM("asm/levels", func_L01_00451768);
