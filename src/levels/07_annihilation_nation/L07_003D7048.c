#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D7048);

INCLUDE_ASM("asm/levels", func_L07_003D7350);

/* localdecomp:start func_L07_003D74A0 */
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003D74A0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 r;

    *(s32 *)(s + 0x14) = 0;
    r = func_003C3BE8(3.1415927f, *(f32 *)(s + 0x14), *(f32 *)(s + 0x14));
    *(f32 *)(a0 + 0xF0) = r;
    *(f32 *)(*(u8 **)(s + 0x10) + 0xF0) = r;
    func_003C7C38(*(void **)(s + 0x10));
    func_L01_004AA760(1, a0);
    s[8] = 1;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L07_003D74A0 */

INCLUDE_ASM("asm/levels", func_L07_003D7520);

/* localdecomp:start func_L07_003D7628 */
extern void func_L07_003D7680(void *, f32, f32, s32);

void func_L07_003D7628(void *arg0) {
    func_L07_003D7680(arg0, 2.5f, 0.0f, 8);
    func_L07_003D7680(arg0, 1.2f, 0.5235988f, 6);
}
/* localdecomp:end func_L07_003D7628 */

INCLUDE_ASM("asm/levels", func_L07_003D7680);
