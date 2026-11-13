#include "common.h"

/* localdecomp:start func_L39_005A5E98 */
typedef struct {
    u8 pad00[0x10];
    s32 f10;
    u8 pad14[0x148 - 0x14];
    s32 f148;
} S_005A5E98;
extern S_005A5E98 D_001A43E0;
extern s32 D_001D799C_sda;
extern s32 D_001D79A0_sda;
extern s32 D_001D79A8_sda;
extern s32 D_001D7994_sda;
extern s32 D_001D7998_sda;
extern s32 D_001D79A4_sda;
extern u8 D_L39_0024BE78_005A5E98 __attribute__((section(".sdata")));
extern u8 D_L39_0024BE70;
__asm__(".extern D_L39_0024BE70, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern void func_0039C028(void);

void func_L39_005A5E98(s32 a0, s32 a1, s32 a2) {
    D_001D799C_sda = a0;
    D_001D79A0_sda = a2;
    D_001A43E0.f148 = 0;
    D_001A43E0.f10 = 0;
    D_001D79A8_sda = a1;
    D_001D7994_sda = 0;
    D_001D7998_sda = 0;
    D_001D79A4_sda = 0;
    D_L39_0024BE78_005A5E98 = 0;
    func_0039C028();
    D_L39_002403FC |= 4;
    D_L39_002403FC &= ~2;
    D_L39_002403FC &= ~0x40;
    D_L39_002403FC &= ~0x10;
    D_L39_0024BE70 = 1;
    D_L39_002403FC &= ~0x4000;
}
/* localdecomp:end func_L39_005A5E98 */
