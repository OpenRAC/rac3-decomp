/* NTSC-U draft (Claude wave K): C of func_L39_00645FE0, the NTSC-U twin of func_L39_00648840, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 16 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00645FE0", whose code is not the PAL one).
 * Worker's note: Best 16 diff lines / 25 of 35 insns align (build/us-waves/K/near/func_L39_00645FE0.high.c), ~45 compiles, stopped. Same instruction set as retail; what differs is only scheduling and register choice: retail starts block 3 with 'addiu a2,0x1F0' (the mult ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_00648840 (src/levels/shared/L39_006487E8.c) */
/* localdecomp:start func_L39_00645FE0 */
extern u8 D_001A5995[];
extern s32 D_001D72F4_sda;
__asm__(".extern D_001D72F4_sda, 4");
extern s32 D_L39_002404F0[];
extern u8 D_L39_001FC830[];

s32 func_L39_00645FE0(u8 *a0, s32 a1) {
    s32 off;
    if (a0[0x1A14] == 0 || D_001A5995[0] == 0) {
        return 1;
    }
    if (D_001D72F4_sda != 0) {
        return 1;
    }
    off = D_L39_002404F0[a0[0x24C9]] * 0x1F0 + (a1 / 32) * 4 + 0xF0;
    return *(u32 *)(D_L39_001FC830 + off) & (1 << a1);
}
/* localdecomp:end func_L39_00645FE0 */
