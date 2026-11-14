#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of the PAL function at the same position (L06 shared, @ps2as) */
/* localdecomp:start func_L06_00353F28 */
extern u8 D_L06_001DD348[0x30] __attribute__((section(".sdata")));
__asm__(".extern D_L06_001DD348, 8");
extern void func_L06_00351FA0(u8 *, u8 *);
extern void func_L06_00350930(u8 *, u8 *, void *, void *);
extern void func_L01_0046A9C8(void *, void *, void *, void *, s32);
extern void func_L06_00353B28(u8 *, u8 *, void *, s32);

void func_L06_00353F28(u8 *obj, u8 *rec) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;

    func_L06_00351FA0(obj, rec);
    func_L06_00350930(obj, rec, &a, &b);
    c = *(vu0_v4 *)(rec + 0x110);
    c.z = c.z + -0.3f;
    func_L01_0046A9C8(0, &a, &c, D_L06_001DD348, 1);
    func_L01_0046A9C8(0, &b, &c, D_L06_001DD348, 1);
    c.z = c.z + -0.075f;
    func_L01_0046A9C8(0, &a, &c, D_L06_001DD348, 1);
    func_L01_0046A9C8(0, &b, &c, D_L06_001DD348, 1);
    func_L06_00353B28(obj, rec, &a, 0x14);
    func_L06_00353B28(obj, rec, &b, 0x14);
}
/* localdecomp:end func_L06_00353F28 */
