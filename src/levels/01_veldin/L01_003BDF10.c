#include "common.h"

/* localdecomp:start func_L01_003BDF10 */
extern u8 D_L01_001D66B0;
extern void func_L01_00452310(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004443E8(void *, s32, s32);
void func_L01_003BDF10(void *a0) {
    func_L01_00452310(a0, 0x1FE0, &D_L01_001D66B0, 1, 0x19, 0xFF, 0xB4, 0, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L01_003BDF10 */

/* localdecomp:start func_L01_003BDF98 */
typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; u8 *f68; u8 p6C[0x29]; u8 b95; u16 h96; } S_DF98_O;
extern f32 D_L01_001DEA4C, D_L01_001DEA50, D_L01_001DEA54, D_L01_001DEA58, D_L01_001DEA5C;
__asm__(".extern D_L01_001DEA4C, 4");
__asm__(".extern D_L01_001DEA50, 4");
__asm__(".extern D_L01_001DEA54, 4");
__asm__(".extern D_L01_001DEA58, 4");
__asm__(".extern D_L01_001DEA5C, 4");
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_003BE3A0(void *);
void func_L01_003BDF98(S_DF98_O *a0) {
    u8 *d = a0->f68;
    func_L01_0044E850(a0, d + 0x270, 0, 1.0f, 0.0f);
    if (a0->h96 <= 0xFFFE) a0->h96 = a0->h96 + 1;
    func_L01_0044EAE0(a0, d + 0x300, d + 0x304, D_L01_001DEA4C, D_L01_001DEA50 * 0.017453292f * 0.020000001f, -1.0f);
    func_L01_0044EBA0(a0, d + 0x308, d + 0x30C, D_L01_001DEA5C * 0.017453292f, D_L01_001DEA54 * 0.017453292f * 0.020000001f, D_L01_001DEA58 * 0.017453292f * 0.020000001f);
    if (a0->b31 != 0) {
        if (a0->b95 != 0) func_L01_00404808(func_L01_003BE3A0, a0);
    }
}
/* localdecomp:end func_L01_003BDF98 */
