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

INCLUDE_ASM("asm/levels", func_L39_0060E3A0);

INCLUDE_ASM("asm/levels", func_L39_0060E6F8);
