#include "common.h"

typedef struct { u8 p0[8]; s32 w8; } Cfg_0058B0D8;

/* localdecomp:start func_L39_0058B0D8 */
extern Cfg_0058B0D8 D_001FC450;
extern s16 D_00228580[];
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);

void func_L39_0058B0D8(char *p) {
    if (*(unsigned long *)(p + 8) != 0) {
        func_003A9440(0x42, *(unsigned long *)(p + 8) & 0xFF000000FFUL);
    }
    if (*(s32 *)(p + 4) & 0xFF000000) {
        func_003A9440(0x4E, ((long)(D_001FC450.w8 >> 13) | 0x1000000) | (1L << 32));
        func_0038AF30(0, D_00228580[0xA9], 0, D_00228580[0xA8], *(u32 *)(p + 4));
        func_003A9440(0x4E, (D_001FC450.w8 >> 13) | 0x1000000);
    }
    if (*(unsigned long *)(p + 8) != 0) {
        func_003A9440(0x42, 0x8000000044UL);
    }
}
/* localdecomp:end func_L39_0058B0D8 */

/* localdecomp:start func_L39_0058B1B8 */
__asm__(".extern D_L39_0024CAD0_b, 4");
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_0024CAD0_b;
extern u8 D_1A3800[];

void func_L39_0058B1B8(s32 r, s32 g, s32 b, s32 a) {
    func_003A9440(0x4E, ((long)(D_001FC450.w8 >> 13) | 0x31000000) | (1L << 32));
    func_003A9440(1, r | ((long)g << 8) | ((long)b << 16) | ((long)a << 24));
    D_L39_0024CAD0[0] = 0x30000014;
    D_L39_0024CAD0[1] = (u32)D_1A3800;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000014;
    D_L39_0024CAD0_b = D_L39_0024CAD0 + 4;
    func_003A9440(0x4E, 0x31000000 | (D_001FC450.w8 >> 13));
}
/* localdecomp:end func_L39_0058B1B8 */
