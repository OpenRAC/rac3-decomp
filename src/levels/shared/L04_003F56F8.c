#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003F56F8);

/* localdecomp:start func_L04_003F5AF8 */
extern u8 D_001A4BE0[];
extern s32 func_00382380(void *, s32, s32);
extern f32 func_L01_0040E548(void *, void *);

u8 func_L04_003F5AF8(u8 *m) {
    u8 *g = D_001A4BE0;
    u8 *v = *(u8 **)(m + 0x68);
    s32 id;

    if (*(s32 *)(g + 0x360) == 0) {
        return 0;
    }
    id = *(s32 *)(v + 0x14);
    if (id != -1) {
        return func_00382380(g + 0x80, id, 0);
    }
    return func_L01_0040E548(m + 0x10, g + 0x80) < *(f32 *)(v + 0x18) * *(f32 *)(v + 0x18);
}
/* localdecomp:end func_L04_003F5AF8 */

INCLUDE_ASM("asm/levels", func_L04_003F5B78);

INCLUDE_ASM("asm/levels", func_L04_003F5E38);
