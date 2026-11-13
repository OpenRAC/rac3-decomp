#include "common.h"

/* NTSC-U counterpart of func_L39_0058B1B8 (src/levels/shared/L39_0058B0D8.c) */
typedef struct { u8 p0[8]; s32 w8; } Cfg_0058B0D8;
extern Cfg_0058B0D8 D_L39_001FC5D0;
extern void func_003A3EF0(s32, unsigned long);

/* localdecomp:start func_L39_00589FE8 */
__asm__(".extern D_L39_0024CBD0_b, 4");
extern u32 *D_L39_0024CBD0;
extern u32 *D_L39_0024CBD0_b;
extern u8 D_001A3980[];

void func_L39_00589FE8(s32 r, s32 g, s32 b, s32 a) {
    func_003A3EF0(0x4E, ((long)(D_L39_001FC5D0.w8 >> 13) | 0x31000000) | (1L << 32));
    func_003A3EF0(1, r | ((long)g << 8) | ((long)b << 16) | ((long)a << 24));
    D_L39_0024CBD0[0] = 0x30000014;
    D_L39_0024CBD0[1] = (u32)D_001A3980;
    D_L39_0024CBD0[2] = 0;
    D_L39_0024CBD0[3] = 0x50000014;
    D_L39_0024CBD0_b = D_L39_0024CBD0 + 4;
    func_003A3EF0(0x4E, 0x31000000 | (D_L39_001FC5D0.w8 >> 13));
}
/* localdecomp:end func_L39_00589FE8 */
