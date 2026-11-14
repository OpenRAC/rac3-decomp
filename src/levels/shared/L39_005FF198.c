#include "common.h"

/* localdecomp:start func_L39_005FF198 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);

void func_L39_005FF198(u8 *a0, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 t0;
    vu0_v4 t1;

    if (a0 != 0 && *(s16 *)(a0 + 0x2D8) != 0) {
        *a2 = *(vu0_v4 *)(*(u8 **)(a0 + 0x2524) + 0xE0);
        func_0038CF68(&t0, a2, 0.1f);
        vec_add_ba(&t0, &t0, a1);
        func_0038CF68(&t1, a2, -6.0f);
        vec_add_ba(&t1, &t1, a1);
        if (func_003D3CB0(&t0, &t1, 2, 0, 0) != 0 && func_003D5630() == 2) {
            return;
        }
    }
    __asm__ __volatile__(
        "vmr32.xyzw $vf1, $vf0\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(a2) : "memory");
}
/* localdecomp:end func_L39_005FF198 */

INCLUDE_ASM("asm/levels", func_L39_005FF270);

LINKER_REMNANT("asm/levels", func_L39_005FF528);
