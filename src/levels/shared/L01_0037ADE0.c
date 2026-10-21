#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0037ADE0);

INCLUDE_ASM("asm/levels", func_L01_0037B6C0);

INCLUDE_ASM("asm/levels", func_L01_0037BCF8);

INCLUDE_ASM("asm/levels", func_L01_0037BE80);

/* localdecomp:start func_L01_0037C208 */
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(u8 *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);

void func_L01_0037C208(u8 *arg0) {
    u8 *sub;

    sub = *(u8 **)(arg0 + 104);
    *(f32 *)(sub + 16) = func_0038DAB8(*(f32 *)(sub + 16), 0.017453292f);
    func_003D9508(arg0 + 16, 57, 0x40505050, 1, 0.5f, 0.08f, func_0038DAB8(*(f32 *)(sub + 16) * 2.5f, 0.0f));
    func_003D9508(arg0 + 16, 42, 0x207F2040, 1, 0.5f, 0.08f, func_0038DAB8(-*(f32 *)(sub + 16) * 1.5f, 0.0f));
    func_003D9508(arg0 + 16, 44, 0x207F2040, 1, 0.5f, 0.08f, func_0038DAB8(*(f32 *)(sub + 16), 0.0f));
    func_003D9508(arg0 + 16, 49, 0x20FF7F00, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * 0.5f);
    func_003D9508(arg0 + 16, 49, 0x0020FF7F, 1, 0.36f, 0.08f, *(f32 *)(sub + 16) * -0.5f);
    func_003D9508(arg0 + 16, 47, 0x507F7F7F, 1, 0.11f, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_0037C208 */

INCLUDE_ASM("asm/levels", func_L01_0037C3C8);

INCLUDE_ASM("asm/levels", func_L01_0037C6E8);

/* localdecomp:start func_L01_0037C720 */
extern s32 D_L01_001E10D0[];
s32 func_L01_0037C720(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_0037C720 */

/* localdecomp:start func_L01_0037C758 */
extern int D_L01_001E10D0[];
int func_L01_0037C758(int a)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (D_L01_001E10D0[i] == a) {
            D_L01_001E10D0[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0037C758 */

INCLUDE_ASM("asm/levels", func_L01_0037C798);

/* localdecomp:start func_L01_0037C7D8 */
void func_L01_0037C7D8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0037C7D8 */

INCLUDE_ASM("asm/levels", func_L01_0037C860);

INCLUDE_ASM("asm/levels", func_L01_0037C978);

LINKER_REMNANT("asm/levels", func_L01_0037CC28);

INCLUDE_ASM("asm/levels", func_L01_0037CC30);

LINKER_REMNANT("asm/levels", func_L01_0037CEC0);

INCLUDE_ASM("asm/levels", func_L01_0037CEC8);

INCLUDE_ASM("asm/levels", func_L01_0037D210);

INCLUDE_ASM("asm/levels", func_L01_0037D358);

INCLUDE_ASM("asm/levels", func_L01_0037D920);

INCLUDE_ASM("asm/levels", func_L01_0037DC70);

INCLUDE_ASM("asm/levels", func_L01_0037E2E8);

INCLUDE_ASM("asm/levels", func_L01_0037E620);

INCLUDE_ASM("asm/levels", func_L01_0037E670);
