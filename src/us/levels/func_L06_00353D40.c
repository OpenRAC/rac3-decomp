#include "common.h"

/* NTSC-U counterpart of func_L06_00354A40 (src/levels/shared/L06_00351930.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L06_00353D40 */
extern void func_L06_00350930(s32, u8 *, void *, void *);
extern void func_L01_0046A9C8(s32, void *, void *, void *, s32);
extern void func_L06_00353B28(u8 *, u8 *, void *, s32);
__asm__(".extern D_L06_001DD338, 4");
extern u8 D_L06_001DD338;

void func_L06_00353D40(u8 *a0, u8 *a1) {
    u128_t t[3];
    t[2] = *(u128_t *)(a1 + 0x110);
    ((float *)&t[2])[2] += -0.3f;
    func_L06_00350930((s32)a0, a1, &t[0], &t[1]);
    func_L01_0046A9C8(0, &t[0], &t[2], &D_L06_001DD338, 1);
    func_L01_0046A9C8(0, &t[1], &t[2], &D_L06_001DD338, 1);
    func_L06_00353B28(a0, a1, &t[0], 1);
    func_L06_00353B28(a0, a1, &t[1], 1);
}
/* localdecomp:end func_L06_00353D40 */
