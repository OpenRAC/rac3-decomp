#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005FB708);

/* localdecomp:start func_L39_005FB7D0 */
extern s32  D_L39_0024CAB0;
extern s32  D_L39_0024CAC4;
extern s32  D_L39_0024CAB4;
extern s32  D_L39_0024CAB8;
extern s32  D_L39_0024CABC;
extern s32 D_L39_0024CAC0 __attribute__((section(".sdata")));
extern u8 D_001FE020[];
extern s16 D_002256A8[];
extern void func_001264E0(s32 a);
extern void func_00194BC8(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_L39_0058A5D0(s32 a);
extern void func_L01_0041A6E0(void);
extern void func_L39_005C1E10(void);
extern void func_L39_005F3948(void);

/* from rac2-decomp's func_002F5E20 */
void func_L39_005FB7D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *p;
    p = D_001FE020;
    p[0x43] = p[0x43] | 8;
    func_00194BC8(2, 0, 0, 0, 0);
    func_001264E0(0);
    func_L39_005F3948();
    func_L39_005C1E10();
    D_L39_0024CAB0 = arg0;
    D_L39_0024CAC4 = (s32) D_002256A8[0];
    D_L39_0024CAB4 = arg1;
    D_L39_0024CAB8 = arg2;
    D_L39_0024CABC = arg3;
    D_L39_0024CAC0 = arg4;
    func_L39_0058A5D0(4);
    func_L01_0041A6E0();
}
/* localdecomp:end func_L39_005FB7D0 */

/* localdecomp:start func_L39_005FB8A8 */
extern s32 D_L39_00240468;
extern s32 D_L39_0024CAC4;
extern s32 D_L39_0025F560[];
extern s32 D_L39_00242910;
extern s32 D_L39_002429A8;
extern void (*D_L39_002429A4)(s32);
extern s32 D_001D7298_sda;
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
            D_L39_002429A4(D_001D7298_sda);
            D_L39_002429A4 = 0;
            D_L39_002429A8 = 0;
        }
    }
done:
    ;
}
/* localdecomp:end func_L39_005FB8A8 */

INCLUDE_ASM("asm/levels", func_L39_005FB960);

/* localdecomp:start func_L39_005FBDA0 */
void func_L39_0059A578(s32, s32);
extern s32 D_001A455C[];
extern s16 D_001FC368[];
extern s32 D_001D4D58_sda;

/* from rac4-decomp's func_004E5550 */
void func_L39_005FBDA0(void) {
    D_001FC368[0] = (D_001A455C[0] = 1);
    D_001D4D58_sda = 1;
    func_L39_0059A578(1, 1);
}
/* localdecomp:end func_L39_005FBDA0 */

/* localdecomp:start func_L39_005FBDD8 */
extern s32 D_L39_0024BA08;
extern s32 D_L39_0024BA10;
extern s32 D_L39_0024BA14;
extern s32 D_L39_0024BA0C;
extern s32 D_L39_0024BA38;
extern s32 D_L39_0024BA60;
void func_L39_005FBDD8(void) {
    D_L39_0024BA08 = 0;
    D_L39_0024BA10 = 0;
    D_L39_0024BA14 = 0;
    D_L39_0024BA0C = 0;
    D_L39_0024BA38 = 0;
    D_L39_0024BA60 = 0;
}
/* localdecomp:end func_L39_005FBDD8 */

INCLUDE_ASM("asm/levels", func_L39_005FBE08);
