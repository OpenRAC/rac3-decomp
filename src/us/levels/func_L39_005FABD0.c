#include "common.h"

/* NTSC-U counterpart of func_L39_005FD368 (src/levels/shared/L39_005FD368.c) */
/* localdecomp:start func_L39_005FABD0 */
__asm__(".extern D_L39_0024CBD0, 16");
extern u32 *D_L39_0024CBD0;
extern u32 *D_L39_0024CBD0_005FABD0 __attribute__((section(".sdata")));
extern u8 D_001A4250[];
extern u8 D_L39_00241330[];
extern void func_00388550(u32 *, u8 *, s32);

void func_L39_005FABD0(void) {
    D_L39_0024CBD0[0] = 0x30000009;
    D_L39_0024CBD0[1] = (u32)D_001A4250;
    D_L39_0024CBD0[2] = 0;
    D_L39_0024CBD0[3] = 0x50000009;
    D_L39_0024CBD0 += 4;
    D_L39_0024CBD0[0] = 0x10000003;
    D_L39_0024CBD0[1] = 0;
    D_L39_0024CBD0[2] = 0;
    D_L39_0024CBD0[3] = 0x50000003;
    D_L39_0024CBD0_005FABD0 = D_L39_0024CBD0 + 4;
    func_00388550(D_L39_0024CBD0_005FABD0, D_L39_00241330, 0x30);
    D_L39_0024CBD0 += 12;
}
/* localdecomp:end func_L39_005FABD0 */
