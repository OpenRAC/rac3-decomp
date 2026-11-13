#include "common.h"

/* NTSC-U counterpart of func_L39_005A5E98 (src/levels/shared/L39_005A5E98.c) */
/* localdecomp:start func_L39_005A4228 */
typedef struct {
    u8 pad00[0x10];
    s32 f10;
    u8 pad14[0x148 - 0x14];
    s32 f148;
} S_005A5E98;
extern S_005A5E98 D_001A4560;
extern s32 D_001D795C_sda;
extern s32 D_001D7960_sda;
extern s32 D_001D7968_sda;
extern s32 D_001D7954_sda;
extern s32 D_001D7958_sda;
extern s32 D_001D7964_sda;
extern u8 D_L39_0024BF78_005A4228 __attribute__((section(".sdata")));
extern u8 D_L39_0024BF70;
__asm__(".extern D_L39_0024BF70, 16");
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024057C, 16");
extern void func_00397238(void);

void func_L39_005A4228(s32 a0, s32 a1, s32 a2) {
    D_001D795C_sda = a0;
    D_001D7960_sda = a2;
    D_001A4560.f148 = 0;
    D_001A4560.f10 = 0;
    D_001D7968_sda = a1;
    D_001D7954_sda = 0;
    D_001D7958_sda = 0;
    D_001D7964_sda = 0;
    D_L39_0024BF78_005A4228 = 0;
    func_00397238();
    D_L39_0024057C |= 4;
    D_L39_0024057C &= ~2;
    D_L39_0024057C &= ~0x40;
    D_L39_0024057C &= ~0x10;
    D_L39_0024BF70 = 1;
    D_L39_0024057C &= ~0x4000;
}
/* localdecomp:end func_L39_005A4228 */
