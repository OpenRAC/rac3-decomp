#include "common.h"

INCLUDE_ASM("asm/levels", func_L36_003A7F38);

INCLUDE_ASM("asm/levels", func_L36_003A85A8);

INCLUDE_ASM("asm/levels", func_L36_003A86B8);

INCLUDE_ASM("asm/levels", func_L36_003A87C0);

INCLUDE_ASM("asm/levels", func_L36_003A8920);

INCLUDE_ASM("asm/levels", func_L36_003A8AB0);

/* localdecomp:start func_L36_003A8CF8 */
extern f32 D_001DEAEC;
extern u8 D_001A4C60[];
extern u8 *func_00424368(u8 *, s32, s32);
extern void func_004262E0(u8 *, u8 *);
extern void func_00422370(u8 *, s32, s32);
extern f32 func_003ED118(u8 *, u8 *);
void func_L36_003A8CF8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *r = func_00424368(a0, 0x10000, 0);
    f32 f;
    if (r != 0) {
        *(u8 *)(a0 + 0xA8) = 0xFF;
        f = *(f32 *)(r + 0x2C);
        if (0.0f < f) {
            if (*(u8 *)(a0 + 0x20) != 0x42) {
                if (*(s32 *)(s + 0x50) <= 0) {
                    *(s32 *)(s + 0x50) = 0xC;
                    *(u8 *)(s + 0x47) = 0xFF;
                    *(f32 *)s = *(f32 *)s - f;
                    func_004262E0(a0, s + 0x40);
                    if (*(f32 *)s <= 0.0f) {
                        func_00422370(a0, 0x42, -1);
                    }
                }
            }
        }
    }
    if (func_003ED118(D_001A4C60, a0 + 0x10) < D_001DEAEC) {
        if (*(u8 *)(a0 + 0x20) != 0x42) {
            func_00422370(a0, 0x42, -1);
        }
    }
}
/* localdecomp:end func_L36_003A8CF8 */
