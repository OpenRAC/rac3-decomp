#include "common.h"

/* localdecomp:start func_L39_0060E0C0 */
extern s32 D_L39_001FC450[];
#define PUT(v) (*(*pp)++ = (unsigned long)(v))

/* from rac4-decomp's func_L00_0068A708 */
void func_L39_0060E0C0(unsigned long **pp, s32 w, s32 h, s32 fbw, s32 x0, s32 y0, s32 x1, s32 y1) {
    PUT(0x7000000000000001UL);
    PUT(0xEEEEEEEEEEEEEEEEUL);
    PUT(0);
    PUT(0x3F);
    PUT(0);
    PUT(0x19);
    PUT(((unsigned long)(w - 1) << 16) | ((unsigned long)(h - 1) << 48));
    PUT(0x41);
    PUT((unsigned long)(D_L39_001FC450[2] >> 13) | ((unsigned long)fbw << 16) | (1UL << 24) | (0xFF000000UL << 32));
    PUT(0x4D);
    PUT(0x30802);
    PUT(0x48);
    PUT((unsigned long)(D_L39_001FC450[2] >> 13) | (0x31UL << 24) | (1UL << 32));
    PUT(0x4F);
    PUT(0x80000000A4UL);
    PUT(0x43);
    PUT(0x4400000000000001UL);
    PUT(0x5510);
    PUT(0x346);
    PUT(0xFFFFFFFFUL);
    PUT((unsigned long)x0 | ((unsigned long)y0 << 16));
    PUT((unsigned long)x1 | ((unsigned long)y1 << 16));
    PUT(0x3000000000000001UL);
    PUT(0xEEEEEEEEEEEEEEEEUL);
    PUT(0);
    PUT(0x3F);
    PUT((unsigned long)(D_L39_001FC450[2] >> 13) | (0x31UL << 24));
    PUT(0x4F);
    PUT(0);
    PUT(0x3F);
}
/* localdecomp:end func_L39_0060E0C0 */

/* localdecomp:start func_L39_0060E3A0 */
/* same code as func_003D8D50 in src/boot_elf/text/3D80E8.c (the steps are long locals kept in registers, as there) */
void func_L39_0060E3A0(unsigned long **pp, s32 flag) {
    s32 i;
    s32 x0, x1;
    long step0, step1;
    PUT(0x8000000000000001UL);
    PUT(0xEEEEEEEEEEEEEEEEUL);
    PUT((unsigned long)(D_L39_001FC450[1] >> 13) | 0x2080000 | 0x3FFF00000000UL);
    PUT(0x4D);
    PUT((unsigned long)(D_L39_001FC450[2] >> 13) | 0x31000000 | 0x100000000UL);
    PUT(0x4F);
    PUT(0x30000);
    PUT(0x48);
    PUT(0);
    PUT(0x19);
    PUT(0x33F000001FF0000UL);
    PUT(0x41);
    PUT(0);
    PUT(0x3F);
    PUT(0);
    PUT(0x15);
    if (flag) {
        PUT((unsigned long)(D_L39_001FC450[2] >> 8) | 0x2B220000 | 0x680000000UL);
        PUT(7);
    } else {
        PUT(7);
        PUT((unsigned long)(D_L39_001FC450[2] >> 8) | 0x2B220000 | 0xE80000000UL);
    }
    PUT(0x2400000000000001UL);
    PUT(1);
    if (flag) PUT(0x3F80000040808080UL);
    else PUT(0x3F80000080808080UL);
    PUT(0x316);
    PUT(0x4400000000008020UL);
    PUT(0x5353);
    x0 = 8;
    x1 = 8;
    step0 = 0x10;
    step1 = 0x10;
    for (i = 0; i < 32; i++) {
        PUT(((x0 << 4) - 0x78) | 0x80000);
        PUT(x1 << 4);
        PUT(((x0 << 4) + 8) | 0x34080000);
        PUT(((x1 << 4) + 0x80) | 0x34000000);
        x0 += step0;
        x1 += step1;
    }
}
/* localdecomp:end func_L39_0060E3A0 */

INCLUDE_ASM("asm/levels", func_L39_0060E6F8);
