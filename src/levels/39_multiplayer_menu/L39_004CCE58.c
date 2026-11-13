#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004CCE58);

INCLUDE_ASM("asm/levels", func_L39_004CCF68);

INCLUDE_ASM("asm/levels", func_L39_004CD638);

INCLUDE_ASM("asm/levels", func_L39_004CD8E8);

INCLUDE_ASM("asm/levels", func_L39_004CDA00);

INCLUDE_ASM("asm/levels", func_L39_004CDB18);

INCLUDE_ASM("asm/levels", func_L39_004CDC00);

INCLUDE_ASM("asm/levels", func_L39_004CDCF0);

INCLUDE_ASM("asm/levels", func_L39_004CDDD8);

INCLUDE_ASM("asm/levels", func_L39_004CDEC0);

INCLUDE_ASM("asm/levels", func_L39_004CDFE0);

INCLUDE_ASM("asm/levels", func_L39_004CE100);

INCLUDE_ASM("asm/levels", func_L39_004CE2D0);

INCLUDE_ASM("asm/levels", func_L39_004CE4A0);

INCLUDE_ASM("asm/levels", func_L39_004CE750);

INCLUDE_ASM("asm/levels", func_L39_004CE968);

INCLUDE_ASM("asm/levels", func_L39_004CEA80);

INCLUDE_ASM("asm/levels", func_L39_004CEC98);

INCLUDE_ASM("asm/levels", func_L39_004CEE68);

INCLUDE_ASM("asm/levels", func_L39_004CEFC0);

INCLUDE_ASM("asm/levels", func_L39_004CF1D8);

INCLUDE_ASM("asm/levels", func_L39_004CF508);

INCLUDE_ASM("asm/levels", func_L39_004CF720);

INCLUDE_ASM("asm/levels", func_L39_004CF758);

INCLUDE_ASM("asm/levels", func_L39_004CF890);

INCLUDE_ASM("asm/levels", func_L39_004CFA00);

INCLUDE_ASM("asm/levels", func_L39_004CFBA8);

INCLUDE_ASM("asm/levels", func_L39_004CFE20);

INCLUDE_ASM("asm/levels", func_L39_004CFF30);

INCLUDE_ASM("asm/levels", func_L39_004D0138);

INCLUDE_ASM("asm/levels", func_L39_004D0228);

INCLUDE_ASM("asm/levels", func_L39_004D03B8);

INCLUDE_ASM("asm/levels", func_L39_004D05D8);

INCLUDE_ASM("asm/levels", func_L39_004D0B08);

/* localdecomp:start func_L39_004D0C60 */
__asm__(".extern D_L39_0046A088, 16");
extern unsigned long D_L39_0046A088[];

/* from rac4-decomp's func_003F6170 */
void func_L39_004D0C60(long arg0) {
    D_L39_0046A088[0] = (unsigned long)(arg0 << 32) >> 32;
}
/* localdecomp:end func_L39_004D0C60 */

INCLUDE_ASM("asm/levels", func_L39_004D0C78);

INCLUDE_ASM("asm/levels", func_L39_004D0CE0);

INCLUDE_ASM("asm/levels", func_L39_004D0D68);

INCLUDE_ASM("asm/levels", func_L39_004D0DA8);

INCLUDE_ASM("asm/levels", func_L39_004D0EF8);

INCLUDE_ASM("asm/levels", func_L39_004D0FE8);

INCLUDE_ASM("asm/levels", func_L39_004D1268);

INCLUDE_ASM("asm/levels", func_L39_004D13F8);

INCLUDE_ASM("asm/levels", func_L39_004D1460);

/* localdecomp:start func_L39_004D1480 */
extern s32 func_L39_004F6BF0(s32, s32 *, s32 *, s32, s32, s32);
extern void func_L39_004F4F18(s32 *);

s32 func_L39_004D1480(s32 a0) {
    s32 buf[4];
    s32 v;
    s32 r;

    do {
        r = func_L39_004F6BF0(a0, buf, &v, 0, 0, 0);
    } while (0);
    func_L39_004F4F18(&a0);
    return r;
}
/* localdecomp:end func_L39_004D1480 */

INCLUDE_ASM("asm/levels", func_L39_004D14C8);

INCLUDE_ASM("asm/levels", func_L39_004D14E0);

INCLUDE_ASM("asm/levels", func_L39_004D1630);

INCLUDE_ASM("asm/levels", func_L39_004D1720);

INCLUDE_ASM("asm/levels", func_L39_004D19A0);

INCLUDE_ASM("asm/levels", func_L39_004D1B30);

INCLUDE_ASM("asm/levels", func_L39_004D1B98);

/* localdecomp:start func_L39_004D1BB8 */
extern s32 func_L39_004F6E18(s32, s32 *, s32 *, s32, s32, s32);

s32 func_L39_004D1BB8(s32 a0) {
    s32 buf[4];
    s32 v;
    s32 r;

    do {
        r = func_L39_004F6E18(a0, buf, &v, 0, 0, 0);
    } while (0);
    func_L39_004F4F18(&a0);
    return r;
}
/* localdecomp:end func_L39_004D1BB8 */

INCLUDE_ASM("asm/levels", func_L39_004D1C00);

INCLUDE_ASM("asm/levels", func_L39_004D1C18);

INCLUDE_ASM("asm/levels", func_L39_004D1CA0);

INCLUDE_ASM("asm/levels", func_L39_004D1D28);

INCLUDE_ASM("asm/levels", func_L39_004D1DC8);

INCLUDE_ASM("asm/levels", func_L39_004D1E58);
