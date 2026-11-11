#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L14_0040E918);

/* localdecomp:start func_L14_0040E9D0 */
extern int D_L14_001EEC50[];

int func_L14_0040E9D0(void)
{
    int i;
    int *base = D_L14_001EEC50;
    int *p = base + 4;
    for (i = 0; i < 0x28; i++) {
        if (*p <= 0)
            return i;
        p += 8;
    }
    return -1;
}
/* localdecomp:end func_L14_0040E9D0 */

/* localdecomp:start func_L14_0040EA08 */
extern s32 D_L14_001E64B4[];
extern u8 D_L14_001EF150[];
void func_L14_0040EA08(void) {
    s32 i;
    u8 *p;
    u8 *base;
    if (D_L14_001E64B4[0] == 1) {
        p = (u8 *)D_L14_001EEC50;
        for (i = 39; i >= 0; i--) {
            qzero(p);
            *(s32 *)(p + 0x10) = 0;
            p += 0x20;
        }
        base = D_L14_001EF150;
        for (i = 0; i < 14; i++) {
            p = base + i * 0x30;
            qzero(p);
            qzero(p + 0x10);
            *(s32 *)(p + 0x24) = 0;
        }
    }
}
/* localdecomp:end func_L14_0040EA08 */

INCLUDE_ASM("asm/levels", func_L14_0040EA78);

INCLUDE_ASM("asm/levels", func_L14_0040EC48);

INCLUDE_ASM("asm/levels", func_L14_0040EF88);

INCLUDE_ASM("asm/levels", func_L14_0040F1B8);
