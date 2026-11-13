#include "common.h"

/* localdecomp:start func_L39_00587E80 */
__asm__(".extern D_L39_0024CAD0, 16");
extern u32 *D_L39_0024CAD0;
extern u8 D_001A4160[];
extern u8 D_001A40D0[];
extern s32 D_L39_0025D6C0[];
extern long D_L39_002411B0[];
extern u32 *D_L39_0024CAD0_b;
extern void func_0038CC88(void *, void *, s32);
extern void func_003A9440(s32, long);

void func_L39_00587E80(void) {
    D_L39_0024CAD0[0] = 0x30000013;
    D_L39_0024CAD0[1] = (u32)D_001A4160;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000013;
    D_L39_0024CAD0 += 4;
    D_L39_0024CAD0[0] = 0x30000009;
    D_L39_0024CAD0[1] = (u32)D_001A40D0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000009;
    D_L39_0024CAD0 += 4;
    D_L39_0024CAD0[0] = 0x10000003;
    D_L39_0024CAD0[1] = 0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000003;
    D_L39_002411B0[2] = D_L39_0025D6C0[0x90] | ((long)D_L39_0025D6C0[0x91] << 16) | ((long)D_L39_0025D6C0[0x92] << 32) | ((long)D_L39_0025D6C0[0x93] << 48);
    D_L39_0024CAD0 += 4;
    D_L39_002411B0[4] = D_L39_0025D6C0[0x90] | ((long)D_L39_0025D6C0[0x91] << 16) | ((long)D_L39_0025D6C0[0x92] << 32) | ((long)D_L39_0025D6C0[0x93] << 48);
    func_0038CC88(D_L39_0024CAD0, D_L39_002411B0, 0x30);
    D_L39_0024CAD0_b = D_L39_0024CAD0 + 12;
    func_003A9440(0x3D, D_L39_0025D6C0[0x94] | ((long)D_L39_0025D6C0[0x95] << 8) | ((long)D_L39_0025D6C0[0x96] << 16));
    func_003A9440(0x51, 0);
}
/* localdecomp:end func_L39_00587E80 */
