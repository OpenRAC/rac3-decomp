#include "common.h"

/* NTSC-U counterpart of func_L39_00677F28 (src/levels/shared/L39_00677F28.c) */
extern void func_L39_00675540(void);

/* localdecomp:start func_L39_00675540 */
extern void func_L39_005938F0(s32, s32, s32, s32, s32, f32);
extern s32 D_L39_00246798;
__asm__(".extern D_L39_00246798, 4");
extern s32 D_L39_0024679C;
__asm__(".extern D_L39_0024679C, 4");
extern f32 D_L39_002467A0;
__asm__(".extern D_L39_002467A0, 4");
extern s32 D_L39_00246780[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00246780, 4");
extern s32 D_L39_00240480;
extern s32 D_L39_00240484;
extern u8 D_001A5A47[];

void func_L39_00675540(void) {
    s32 col = (D_L39_00246798 << 24) | 0x66CCFF;
    s32 half = D_L39_00240480 >> 1;
    D_L39_00246798 += D_L39_0024679C * 2;
    if (D_L39_00246798 < 32) { D_L39_0024679C = 1; } else if (D_L39_00246798 > 128) { D_L39_0024679C = -1; }
    func_L39_005938F0(half, (s32)(D_L39_002467A0 * (f32)D_L39_00240484), col, D_L39_00246780[D_001A5A47[0]], -1, 1.2f);
}
/* localdecomp:end func_L39_00675540 */
