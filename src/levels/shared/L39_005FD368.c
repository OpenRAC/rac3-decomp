#include "common.h"

/* localdecomp:start func_L39_005FD368 */
__asm__(".extern D_L39_0024CAD0, 16");
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_005FD368 __attribute__((section(".sdata")));
extern u8 D_001A40D0[];
extern u8 D_002411B0[];
extern void func_0038CC88(u32 *, u8 *, s32);

void func_L39_005FD368(void) {
    D_L39_0024CAD0[0] = 0x30000009;
    D_L39_0024CAD0[1] = (u32)D_001A40D0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000009;
    D_L39_0024CAD0 += 4;
    D_L39_0024CAD0[0] = 0x10000003;
    D_L39_0024CAD0[1] = 0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000003;
    D_L39_0024CAD0_005FD368 = D_L39_0024CAD0 + 4;
    func_0038CC88(D_L39_0024CAD0_005FD368, D_002411B0, 0x30);
    D_L39_0024CAD0 += 12;
}
/* localdecomp:end func_L39_005FD368 */
