#include "common.h"

/* NTSC-U counterpart of func_L39_00587E80 (src/levels/shared/L39_00587E80.c) */
/* localdecomp:start func_L39_00586D40 */
__asm__(".extern D_L39_0024CBD0, 16");
extern u32 *D_L39_0024CBD0;
extern u8 D_001A42E0[];
extern u8 D_001A4250[];
extern s32 D_L39_0025D7C0[];
extern long D_L39_00241330[];
extern u32 *D_L39_0024CBD0_b;
extern void func_00388550(void *, void *, s32);
extern void func_003A3EF0(s32, long);

void func_L39_00586D40(void) {
    D_L39_0024CBD0[0] = 0x30000013;
    D_L39_0024CBD0[1] = (u32)D_001A42E0;
    D_L39_0024CBD0[2] = 0;
    D_L39_0024CBD0[3] = 0x50000013;
    D_L39_0024CBD0 += 4;
    D_L39_0024CBD0[0] = 0x30000009;
    D_L39_0024CBD0[1] = (u32)D_001A4250;
    D_L39_0024CBD0[2] = 0;
    D_L39_0024CBD0[3] = 0x50000009;
    D_L39_0024CBD0 += 4;
    D_L39_0024CBD0[0] = 0x10000003;
    D_L39_0024CBD0[1] = 0;
    D_L39_0024CBD0[2] = 0;
    D_L39_0024CBD0[3] = 0x50000003;
    D_L39_00241330[2] = D_L39_0025D7C0[0x90] | ((long)D_L39_0025D7C0[0x91] << 16) | ((long)D_L39_0025D7C0[0x92] << 32) | ((long)D_L39_0025D7C0[0x93] << 48);
    D_L39_0024CBD0 += 4;
    D_L39_00241330[4] = D_L39_0025D7C0[0x90] | ((long)D_L39_0025D7C0[0x91] << 16) | ((long)D_L39_0025D7C0[0x92] << 32) | ((long)D_L39_0025D7C0[0x93] << 48);
    func_00388550(D_L39_0024CBD0, D_L39_00241330, 0x30);
    D_L39_0024CBD0_b = D_L39_0024CBD0 + 12;
    func_003A3EF0(0x3D, D_L39_0025D7C0[0x94] | ((long)D_L39_0025D7C0[0x95] << 8) | ((long)D_L39_0025D7C0[0x96] << 16));
    func_003A3EF0(0x51, 0);
}
/* localdecomp:end func_L39_00586D40 */
