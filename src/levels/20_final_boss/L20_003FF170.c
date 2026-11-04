#include "common.h"

/* localdecomp:start func_L20_003FF170 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern s32 func_003D3CB0(u8 *a, u8 *b, s32 flags, u8 *moby, s32 e);
extern u8 *D_L20_001E9BD8[];

s32 func_L20_003FF170(u8 *a0) {
    u8 buf[16];
    u8 *s1;
    u8 *p;

    s1 = *(u8 **)(a0 + 104);
    func_003C2F58(*(u8 **)(s1 + 0x3EC), 0, buf);
    if (func_003D3CB0(buf, s1 + 0x220, 0, a0, 0) == 0) {
        return 1;
    }
    p = D_L20_001E9BD8[0];
    if (p == 0) {
        return 1;
    }
    if (*(s16 *)(p + 0xAA) != 0x1E02) {
        return 1;
    }
    return (s32)p == *(s32 *)(s1 + 0x230);
}
/* localdecomp:end func_L20_003FF170 */

INCLUDE_ASM("asm/levels", func_L20_003FF1F8);

INCLUDE_ASM("asm/levels", func_L20_003FF358);

INCLUDE_ASM("asm/levels", func_L20_003FF448);
