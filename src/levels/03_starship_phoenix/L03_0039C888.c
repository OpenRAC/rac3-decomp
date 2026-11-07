#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0039C888);

INCLUDE_ASM("asm/levels", func_L03_0039D038);

INCLUDE_ASM("asm/levels", func_L03_0039D188);

INCLUDE_ASM("asm/levels", func_L03_0039D380);

/* localdecomp:start func_L03_0039D418 */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_0038CF68(u8 *, u8 *, f32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_001A71A0[];

void func_L03_0039D418(u8 *a0, u8 *a1) {
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 8);
    *(f32 *)(a1 + 0x50) = 0.002f;
    *(f32 *)(a1 + 0x54) = 0.004f;
    *(f32 *)(a1 + 0x58) = 0.0600000024f;
    if (0.0600000024f < *(f32 *)(a1 + 0xE0)) {
        func_0038CF68(a1 + 0xD0, a1 + 0xD0, 0.0600000024f);
        *(f32 *)(a1 + 0xE0) = *(f32 *)(a1 + 0x58);
    }
    func_L01_00459188(a0, D_001A71A0[0], a1 + 0x120);
    func_L01_004450F0(a0, 3, -1);
}
/* localdecomp:end func_L03_0039D418 */

/* localdecomp:start func_L03_0039D4D8 */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_001A71A0[];

void func_L03_0039D4D8(u8 *a0, u8 *a1) {
    if (a0[0x43] != 2) {
        func_003C3A10(a0, 2, 0, 8);
    }
    *(f32 *)(a1 + 0x58) = 0.24000001f;
    *(f32 *)(a1 + 0x50) = 0.0048f;
    *(f32 *)(a1 + 0x54) = 0.006f;
    func_L01_00459188(a0, D_001A71A0[0], a1 + 0x120);
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L03_0039D4D8 */

/* localdecomp:start func_L03_0039D578 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern u8 *D_L03_0021D8C0[];
extern s32 D_00142C14[];
extern s32 D_001DE390_sda;
__asm__(".extern D_001DE390_sda, 4");

void func_L03_0039D578(u8 *a0, u8 *a1) {
    *(u128_t *)(a0 + 0x10) = *(u128_t *)(D_L03_0021D8C0[*(s32 *)(a1 + 0x314)] + 0x10);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    *(f32 *)(a1 + 0x58) = 0.060000002f;
    *(f32 *)(a1 + 0x4C) = 0.12566371f;
    *(f32 *)(a1 + 0x50) = 0.0025132743f;
    *(f32 *)(a1 + 0x54) = 0.0025132743f;
    a1[0x344] = 0xFF;
    *(s16 *)(a1 + 0x338) = 1;
    *(s16 *)(a1 + 0x33A) = 1;
    func_L01_004450F0(a0, 6, -1);
    a0[0x30] = 0x40;
    if (D_00142C14[0] & 0x200000) {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)&D_001DE390_sda;
        *(f32 *)(a0 + 0xF8) = 1.5707964f;
        if (a0[0x43] != 7) func_003C3A10(a0, 7, 0, 0);
        func_L01_004450F0(a0, 12, -1);
    }
}
/* localdecomp:end func_L03_0039D578 */

INCLUDE_ASM("asm/levels", func_L03_0039D6A8);
