#include "common.h"

/* localdecomp:start func_L01_00435FC8 */
extern u8 D_001426E0[];

s32 func_L01_00435FC8(s32 a0) {
    return D_001426E0[(a0 >> 3) + 195] & (1 << (a0 & 7));
}
/* localdecomp:end func_L01_00435FC8 */

/* localdecomp:start func_L01_00435FF0 */
extern unsigned char D_001426E0[];
void func_L01_00435FF0(int a) {
    D_001426E0[(a >> 3) + 195] |= 1 << (a & 7);
}
/* localdecomp:end func_L01_00435FF0 */

/* localdecomp:start func_L01_00436020 */
extern void func_003AC638(char *, unsigned int, unsigned int, float, float, float, float);
extern s32 D_L01_001D67C8;

void func_L01_00436020(s32 arg0, s32 arg1, float top, float bottom, float left, float right) {
    s32 a;
    s32 b;
    a = arg0;
    b = arg1;
    if (D_L01_001D67C8 != 0) {
        func_003AC638((char *)(D_L01_001D67C8 + 0x1FCA8), a, b, top, bottom, left, right);
    }
}
/* localdecomp:end func_L01_00436020 */

LINKER_REMNANT("asm/levels", func_L01_00436068);

INCLUDE_ASM("asm/levels", func_L01_00436070);

INCLUDE_ASM("asm/levels", func_L01_004360B8);

LINKER_REMNANT("asm/levels", func_L01_004360E8);
