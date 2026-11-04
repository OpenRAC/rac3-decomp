#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005FB708);

INCLUDE_ASM("asm/levels", func_L39_005FB7D0);

/* localdecomp:start func_L39_005FB8A8 */
extern s32 D_L39_00240468;
extern s32 D_L39_0024CAC4;
extern s32 D_L39_0025F560[];
extern s32 D_L39_00242910;
extern s32 D_L39_002429A8;
extern void (*D_L39_002429A4)(s32);
extern s32 D_001D7298;
extern u8 D_1FE020[];
extern void func_L39_0058A5D0(s32 a0);
extern void func_L39_005C1AC0(s32 a0, s32 a1, s32 a2);
extern void func_003A1D00(void);
extern void func_003A9108(void);

void func_L39_005FB8A8(void) {
    u8 *p;

    if (D_L39_00240468 == 0) {
        D_L39_00240468 = 1;
    }
    func_L39_0058A5D0(4);
    func_L39_005C1AC0(D_L39_0024CAC4, 1, 0x400);
    func_003A1D00();
    p = D_1FE020;
    p[0x43] |= 0x10;
    func_003A9108();
    if (D_L39_002429A4 != 0) {
        if (D_L39_0025F560[0] == 0) {
            if (D_L39_00242910 == 2)
                goto done;
            if (D_L39_00242910 == 1)
                goto done;
            D_L39_002429A4(D_001D7298);
            D_L39_002429A4 = 0;
            D_L39_002429A8 = 0;
        }
    }
done:
    ;
}
/* localdecomp:end func_L39_005FB8A8 */

INCLUDE_ASM("asm/levels", func_L39_005FB960);

INCLUDE_ASM("asm/levels", func_L39_005FBDA0);

/* localdecomp:start func_L39_005FBDD8 */
extern s32 D_L39_0024BA08;
extern s32 D_L39_0024BA10;
extern s32 D_L39_0024BA14;
extern s32 D_L39_0024BA0C;
extern s32 D_L39_0024BA38;
extern s32 D_L39_001E0350;
void func_L39_005FBDD8(void) {
    D_L39_0024BA08 = 0;
    D_L39_0024BA10 = 0;
    D_L39_0024BA14 = 0;
    D_L39_0024BA0C = 0;
    D_L39_0024BA38 = 0;
    D_L39_001E0350 = 0;
}
/* localdecomp:end func_L39_005FBDD8 */

INCLUDE_ASM("asm/levels", func_L39_005FBE08);
