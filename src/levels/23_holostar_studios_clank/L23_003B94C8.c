#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_003B94C8);

INCLUDE_ASM("asm/levels", func_L23_003B98A8);

INCLUDE_ASM("asm/levels", func_L23_003B9940);

INCLUDE_ASM("asm/levels", func_L23_003B9AC0);

INCLUDE_ASM("asm/levels", func_L23_003B9B88);

INCLUDE_ASM("asm/levels", func_L23_003BA3E8);

/* localdecomp:start func_L23_003BA5D8 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];

s32 func_L23_003BA5D8(s32 index) {
    u16 *p = D_L23_001D6764[index];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[index])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CCE)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003BA5D8 */

INCLUDE_ASM("asm/levels", func_L23_003BA670);

INCLUDE_ASM("asm/levels", func_L23_003BAEC8);

/* localdecomp:start func_L23_003BB0B8 */
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u8 *D_L23_001E0014;
__asm__(".extern D_L23_001E0014, 16");
extern s16 D_L23_0023A3C0[];

s32 func_L23_003BB0B8(s32 idx)
{
    u16 *p = D_L23_001D6764[idx];
    u8 *e;

    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[idx])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[e[0x1D]] == 0x1CCF)
            return 1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003BB0B8 */

INCLUDE_ASM("asm/levels", func_L23_003BB150);

INCLUDE_ASM("asm/levels", func_L23_003BB510);

INCLUDE_ASM("asm/levels", func_L23_003BB5A8);

INCLUDE_ASM("asm/levels", func_L23_003BB700);

INCLUDE_ASM("asm/levels", func_L23_003BB7C8);

INCLUDE_ASM("asm/levels", func_L23_003BB8A8);

INCLUDE_ASM("asm/levels", func_L23_003BBCB0);
