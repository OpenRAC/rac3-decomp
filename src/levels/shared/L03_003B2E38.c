#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B2E38 */
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_003B2E38(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vec_add_ab(v + 0x10, a0 + 0x10, v + 0x20);
    *(f32 *)(v + 8) = *(f32 *)(v + 0xC);
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L03_003B2E38 */
