#include "common.h"

/* NTSC-U counterpart of func_L39_00679AE0 (src/levels/shared/L39_00677F28.c) */
extern void func_L39_005938F0(s32, s32, s32, s32, s32, f32);
extern s32 D_L39_00246780[] __attribute__((section(".sdata")));
extern s32 D_L39_00240484;
extern u8 D_001A5A47[];
extern s32 D_L39_00240484;

/* localdecomp:start func_L39_006770E8 */
extern void func_L39_005938F0(s32, s32, s32, s32, s32, f32);
extern s32 D_L39_00246780[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00246780, 4");
extern s32 D_L39_00240484;
extern u8 D_001A5A47[];
extern s32 D_L39_00246820;
__asm__(".extern D_L39_00246820, 4");
extern s32 D_L39_00246824;
__asm__(".extern D_L39_00246824, 4");
extern f32 D_L39_00246828;
__asm__(".extern D_L39_00246828, 4");

void func_L39_006770E8(s32 *p) {
    s32 col = (D_L39_00246820 << 24) | 0x66CCFF;
    D_L39_00246820 += D_L39_00246824 * 2;
    if (D_L39_00246820 < 32) { D_L39_00246824 = 1; } else if (D_L39_00246820 > 128) { D_L39_00246824 = -1; }
    func_L39_005938F0(*p, (s32)(D_L39_00246828 * (f32)D_L39_00240484), col, D_L39_00246780[D_001A5A47[0]], -1, 1.2f);
}
/* localdecomp:end func_L39_006770E8 */
