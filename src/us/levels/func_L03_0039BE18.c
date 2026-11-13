#include "common.h"

/* NTSC-U counterpart of func_L03_0039D578 (src/levels/03_starship_phoenix/L03_0039C888.c): 0.00251327 -> 0.00174533; 0.06 -> 0.05; 0.125664 -> 0.10472 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C3A10();
extern void func_L01_00441FB8();
extern void func_L03_0039BE18(u8 *, u8 *);
extern void func_L03_0039BE18();
extern void func_003C3A10();
extern void func_L01_00441FB8();
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);

/* localdecomp:start func_L03_0039BE18 */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern u8 *D_L03_0021D940[];
extern s32 D_00142C14[];
extern s32 D_001DE3D0_sda;
__asm__(".extern D_001DE3D0_sda, 4");

void func_L03_0039BE18(u8 *a0, u8 *a1) {
    *(u128_t *)(a0 + 0x10) = *(u128_t *)(D_L03_0021D940[*(s32 *)(a1 + 0x314)] + 0x10);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    *(f32 *)(a1 + 0x58) = 0.0500000045f;
    *(f32 *)(a1 + 0x4C) = 0.104719765f;
    *(f32 *)(a1 + 0x50) = 0.00174532935f;
    *(f32 *)(a1 + 0x54) = 0.00174532935f;
    a1[0x344] = 0xFF;
    *(s16 *)(a1 + 0x338) = 1;
    *(s16 *)(a1 + 0x33A) = 1;
    func_L01_00441FB8(a0, 6, -1);
    a0[0x30] = 0x40;
    if (D_00142C14[0] & 0x200000) {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)&D_001DE3D0_sda;
        *(f32 *)(a0 + 0xF8) = 1.5707964f;
        if (a0[0x43] != 7) func_003C3A10(a0, 7, 0, 0);
        func_L01_00441FB8(a0, 12, -1);
    }
}
/* localdecomp:end func_L03_0039BE18 */
