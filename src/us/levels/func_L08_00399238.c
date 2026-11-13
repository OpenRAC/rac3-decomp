#include "common.h"

/* NTSC-U counterpart of func_L08_0039AC38 (src/levels/08_aquatos/L08_0039A9D8.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
/* localdecomp:start func_L08_00399238 */
extern u8 D_001D5471;
__asm__(".extern D_001D5471, 16");
void func_L08_0042E4E0(void *, void *, s32, s32);
void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L08_00399238(u8 *a0) {
    u8 *p;

    if (a0[0x20] != 0) {
        p = *(u8 **)(a0 + 0x68);
        *(u8 *)(a0 + 0xA8) = 0xFF;
        if (D_001D5471 != 0) {
            *(f32 *)(p + 0x5C0) = 2.75f;
        }
        func_L08_0042E4E0(a0, p + 0x280, 2, 3);
        func_L01_0044B5C8(a0, p + 0x4D0, 4, 0.0299999993f, 0.300000012f);
    }
}
/* localdecomp:end func_L08_00399238 */
