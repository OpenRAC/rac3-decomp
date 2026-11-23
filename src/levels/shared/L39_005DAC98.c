#include "common.h"

/* declared by functions of L39_005DA870.c, which this file was cut from */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00517190(s32, s32);

/* localdecomp:start func_L39_005DAC98 */
__asm__(".extern D_001D7FD0_sda, 4");
extern f32 D_001D7FD0_sda;
extern s32 func_L01_00517190_005DAC98(s32, s32);
extern void func_L01_00516470(s32, f32, f32);

void func_L39_005DAC98(s32 a0, s32 a1, s32 a2) {
    func_L01_00517190_005DAC98(0x20016, a0);
    if (a0 == 0xED36) {
        func_L01_00516470(0x20017, 0.1f, D_001D7FD0_sda + 0.866f);
        func_L01_00516470(0x20018, 0.1f, D_001D7FD0_sda + 0.91f);
    } else if (a0 == 0xED37) {
        func_L01_00516470(0x20017, 0.1f, D_001D7FD0_sda + 0.854f);
        func_L01_00516470(0x20018, 0.1f, D_001D7FD0_sda + 0.89f);
    } else if (a0 == 0xED4B) {
        func_L01_00516470(0x20017, 0.1f, 0.854f);
    }
    if (a1 != 0) {
        func_L01_00516AA0(0x20017, 1, 1);
    }
    if (a2 != 0) {
        func_L01_00516AA0(0x20018, 1, 1);
    }
}
/* localdecomp:end func_L39_005DAC98 */
