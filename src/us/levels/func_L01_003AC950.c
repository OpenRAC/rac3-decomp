#include "common.h"

/* localdecomp:start func_L01_003AC950 */
extern s32 D_L01_001DE4E0;
__asm__(".extern D_L01_001DE4E0, 4");
extern s32 D_L01_001DE4F0;
__asm__(".extern D_L01_001DE4F0, 4");
extern s32 D_L01_001DE4F4;
__asm__(".extern D_L01_001DE4F4, 4");
extern s32 func_00388398(void *);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_003894A0(s32, s32, f32);

void func_L01_003AC950(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (func_00388398(p + 0x10)) {
        *(s32 *)(p + 0x10) = D_L01_001DE4E0;
        func_L01_004A72A8(0, 0, a0, 0x1960);
    }
    *(s32 *)(a0 + 0x78) = func_003894A0(D_L01_001DE4F0, D_L01_001DE4F4,
                                        (f32)*(s32 *)(p + 0x10) / (f32)D_L01_001DE4E0);
}
/* localdecomp:end func_L01_003AC950 */
