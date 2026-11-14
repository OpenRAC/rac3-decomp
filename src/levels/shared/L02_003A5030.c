#include "common.h"


/* localdecomp:start func_L02_003A5030 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_L02_003A3898(void *, void *, f32);
extern u8 D_L02_001E1300[];
extern f32 D_L02_001DDD24, D_L02_001DDD28;
__asm__(".extern D_L02_001DDD24, 4");
__asm__(".extern D_L02_001DDD28, 4");

void func_L02_003A5030(u8 *a0)
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
        if (func_L01_0040E548(D_L02_001E1300, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    func_L01_0044EAE0(a0, p + 0x308, p + 0x30C, D_L02_001DDD24, D_L02_001DDD28 * 0.017453292f * 0.020000001f, -1.0f);
    func_L02_003A3898(a0, p + 0x110, *(f32 *)(p + 0x124));
}
/* localdecomp:end func_L02_003A5030 */
