#include "common.h"

/* localdecomp:start func_L01_0043A800 */
extern void func_003CA4A0(void *, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L01_0043A800(u8 *a0, s32 a1, void *a2) {
    f32 m[16];
    s32 id;
    f32 s = *(f32 *)(a0 + 44) * 0.0009765625f;
    id = a1;
    func_003CA4A0(a0, 1, &id, m);
    func_0038CE20(a2, &m[12], s);
}
/* localdecomp:end func_L01_0043A800 */

INCLUDE_ASM("asm/levels", func_L01_0043A860);
