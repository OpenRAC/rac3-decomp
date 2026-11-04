#include "common.h"

/* localdecomp:start func_L11_003AB590 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(u8 *);
extern u8 D_L11_001E1780[];

void func_L11_003AB590(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 value;

    func_0038CAD0(p + 0x2D0);
    func_0038CB00(p + 0x2D4);
    value = *(u16 *)(a0 + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(a0 + 0x96) = value + 1;
    }
    func_L01_00451DF8(a0, p + 0x240, 1, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L11_001E1780, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 30;
        }
    }
}
/* localdecomp:end func_L11_003AB590 */
