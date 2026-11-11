#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003A7AA8);

INCLUDE_ASM("asm/levels", func_L24_003A7CE8);

INCLUDE_ASM("asm/levels", func_L24_003A7F58);

INCLUDE_ASM("asm/levels", func_L24_003A7FD8);

INCLUDE_ASM("asm/levels", func_L24_003A8118);

INCLUDE_ASM("asm/levels", func_L24_003A8400);

/* localdecomp:start func_L24_003A8530 */
extern void func_L24_003A8400(void *, s32, s32, s32, f32);

void func_L24_003A8530(u8 *a0, f32 f12) {
    s32 t;
    func_L24_003A8400(a0, *(u16 *)(a0 + 0x96), 0x401080, 0x22, f12);
    t = *(u16 *)(a0 + 0x96);
    t += 0x28;
    func_L24_003A8400(a0, t >= 0x168 ? t - 0x168 : t, 0x802040, 0x27, f12);
    t = *(u16 *)(a0 + 0x96);
    t += 0xA0;
    func_L24_003A8400(a0, t >= 0x168 ? t - 0x168 : t, 0x40FF, 0x28, f12);
}
/* localdecomp:end func_L24_003A8530 */
