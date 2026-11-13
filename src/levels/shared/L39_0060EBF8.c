#include "common.h"

/* localdecomp:start func_L39_0060EBF8 */
/* from the same shape as boot_elf's func_003D95A8 */
__asm__(".extern D_001D5DAC_sda, 4");
__asm__(".extern D_L39_002414B0, 16");
__asm__(".extern D_L39_00241474, 16");
__asm__(".extern D_001D5DA8_sda, 4");
extern s32 D_001D5DAC_sda;
extern s32 D_001D5DA8_sda;
extern s32 D_L39_002414B0;
extern s32 D_L39_00241474;
extern s32 D_001FC454[];
extern s32 func_003D6A20(s32 *, s32);
extern void func_003D8FC0(void);
extern void func_003D9100(void);

void func_L39_0060EBF8(void) {
    s32 spv[4];

    spv[0] = 0x37C000;
    D_001D5DAC_sda = func_003D6A20(spv, 0x40000);
    D_L39_002414B0 = func_003D6A20(spv, 0x40000);
    D_001D5DA8_sda = D_001FC454[0];
    func_003D8FC0();
    func_003D9100();
    D_L39_00241474 |= 2;
}
/* localdecomp:end func_L39_0060EBF8 */
