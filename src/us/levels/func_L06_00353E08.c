#include "common.h"

/* localdecomp:start func_L06_00353E08 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_L06_00351FA0(u8 *, u8 *);
extern void func_L06_00350930(u8 *, u8 *, f32 *, f32 *);
extern void func_L01_0046A9C8(s32, f32 *, f32 *, s32 *, s32);
extern void func_L06_00353B28(u8 *, u8 *, f32 *, s32);
extern s32 D_L06_001DD348;
__asm__(".extern D_L06_001DD348, 4");

void func_L06_00353E08(u8 *a0, u8 *a1) {
    f32 va[4];
    f32 vb[4];
    f32 vc[4];

    func_L06_00351FA0(a0, a1);
    func_L06_00350930(a0, a1, va, vb);
    *(u128_t *)vc = *(u128_t *)(a1 + 0x110);
    vc[2] += -0.3f;
    func_L01_0046A9C8(0, va, vc, &D_L06_001DD348, 1);
    func_L01_0046A9C8(0, vb, vc, &D_L06_001DD348, 1);
    vc[2] += -0.075f;
    func_L01_0046A9C8(0, va, vc, &D_L06_001DD348, 1);
    func_L01_0046A9C8(0, vb, vc, &D_L06_001DD348, 1);
    func_L06_00353B28(a0, a1, va, 0x14);
    func_L06_00353B28(a0, a1, vb, 0x14);
}
/* localdecomp:end func_L06_00353E08 */
