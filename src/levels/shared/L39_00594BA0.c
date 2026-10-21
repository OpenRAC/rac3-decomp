#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00594BA0);

/* localdecomp:start func_L39_00594C00 */
extern s32 D_L39_001D5D60;
extern void func_0038E150(s32);
extern void func_0038E7E8(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
void func_L39_00594C00(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_L39_001D5D60;
    func_0038E150(1);
    func_0038E7E8(c, d, e, 2, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_0038E150(save);
}
/* localdecomp:end func_L39_00594C00 */
