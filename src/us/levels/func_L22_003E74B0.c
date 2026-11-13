#include "common.h"

/* NTSC-U counterpart of func_L22_003E94D8 (src/levels/22_mylon/L22_003E94D8.c) */
/* localdecomp:start func_L22_003E74B0 */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern void func_003BF838(void *, void *, void *, void *);
void func_L22_003E74B0(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    f32 a[4];
    f32 b[4];
    func_00388830(a, self + 0xD0, -0.10000001f);
    vec_add_ba(a, a, self + 0x10);
    vec_sub_ba(b, a, self + 0x10);
    func_003BF838(p + 0x30, b, self + 0xF0, self + 0xF0);
}
/* localdecomp:end func_L22_003E74B0 */
