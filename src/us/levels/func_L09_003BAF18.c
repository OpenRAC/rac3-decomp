#include "common.h"

/* NTSC-U counterpart of func_L09_003BC790 (src/levels/09_tyhrranosis/L09_003B8580.c) */
#include "vu0.h"
#include "vu0.h"
extern s32 func_0037E208(s32, s32);
extern void func_L09_003BABD8(u8 *, s32, s32, s32, s32);

/* localdecomp:start func_L09_003BAF18 */
extern void func_L09_003BABD8(u8 *, s32, s32, s32, s32);
extern s32 func_0037E208(s32, s32);

void func_L09_003BAF18(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    func_L09_003BABD8(a0, a1, a2, a3, 0);
    *(s16 *)(p + 0xD38) = (f32)func_0037E208(5, 10) * 60.0f;
}
/* localdecomp:end func_L09_003BAF18 */
