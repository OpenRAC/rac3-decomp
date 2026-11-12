#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L09_003DDEE0);

/* localdecomp:start func_L09_003DE200 */
extern void func_00382580(f32 *, f32, f32);
extern void func_L09_003DDEE0(f32 *, s32, f32);
extern void func_003A52A0(s32, s32, s32);

void func_L09_003DE200(u8 *a0, f32 a2, f32 a3, f32 a4, f32 a5, s32 a1) {
    f32 v[4];
    f32 w[4];
    s32 i;
    i = 1;
    func_00382580(v, a3 * 0.8f, a3 * 1.2f);
    v[2] = v[2] + a2;
    vec_add_ab(v, v, a0 + 0x10);
    do {
        func_00382580(w, a4 * 0.75f, a4 * 1.25f);
        i = i - 1;
        vec_add_ab(w, v, w);
        func_L09_003DDEE0(w, a1, a5 * 0.75f);
    } while (i >= 0);
    if (a0[0x20] != 4) {
        func_003A52A0(1, 0x10, (s32)a0);
    }
}
/* localdecomp:end func_L09_003DE200 */

INCLUDE_ASM("asm/levels", func_L09_003DE328);
