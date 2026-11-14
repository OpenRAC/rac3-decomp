#include "common.h"
#include "vu0.h"

/* NTSC-U-only function (flags of its neighbours: @ps2as) */
/* localdecomp:start func_L07_003ADF80 */
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);

/* Aims the object at a point from its sub-struct (z lowered by 0.75): computes yaw and pitch with
 * atan2 and drives rotation fields +0xF8 and +0xF0 toward them with angle_spring. */
void func_L07_003ADF80(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    vu0_v4 v;
    f32 a;
    f32 b;
    f32 c;

    v = *(vu0_v4 *)(sub + 0x30);
    v.z = v.z + -0.75f;
    a = func_00388A28(v.x - *(f32 *)(obj + 0x10), v.y - *(f32 *)(obj + 0x14));
    b = func_003893C8(a, 1.5707964f);
    c = func_00388800(obj + 0x10, &v);
    c = func_00388A28(c, v.z - *(f32 *)(obj + 0x18));
    func_L01_004455F0(obj + 0xF8, b, sub + 0xDC, 0.0005f, 0.01f, 0.0f, 0);
    func_L01_004455F0(obj + 0xF0, c, sub + 0xD8, 0.0005f, 0.01f, 0.0f, 0);
}
/* localdecomp:end func_L07_003ADF80 */
