#include "common.h"

/* localdecomp:start func_L24_0035A908 */
#include "vu0.h"

extern void func_L24_0035A550(void *, f32);

void func_L24_0035A908(u8 *a0, s32 a1) {
    u8 *p;
    if (a1 != 0 || a0[0x20] == 9) {
        p = *(u8 **)(a0 + 0x68);
        vec_add_ab(a0 + 0x10, a0 + 0x10, p + 0x170);
        func_L24_0035A550(a0, -*(f32 *)(p + 0x1BC));
        *(u16 *)(a0 + 0x34) &= 0xFEFF;
    }
}
/* localdecomp:end func_L24_0035A908 */
