#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00688400);

INCLUDE_ASM("asm/levels", func_L39_00688460);

INCLUDE_ASM("asm/levels", func_L39_006888B8);

INCLUDE_ASM("asm/levels", func_L39_00689420);

INCLUDE_ASM("asm/levels", func_L39_00689570);

INCLUDE_ASM("asm/levels", func_L39_00689610);

INCLUDE_ASM("asm/levels", func_L39_00689670);

/* localdecomp:start func_L39_00689A70 */
void func_L39_006121B0(s32);
extern u8 D_001DC30A_sda;

void func_L39_00689A70(void) {
    func_L39_006121B0(2);
    D_001DC30A_sda = 0;
}
/* localdecomp:end func_L39_00689A70 */

/* localdecomp:start func_L39_00689A90 */
extern char D_001DC310_sda[8];
extern int D_L39_003D28C0[];
extern int func_0038CAD0(char *);
extern void func_L01_00516AA0();
void func_L39_00689A90(void)
{
    if (func_0038CAD0(D_001DC310_sda)) {
        func_L01_00516AA0(D_L39_003D28C0[0], 1, 0);
    }
}
/* localdecomp:end func_L39_00689A90 */

INCLUDE_ASM("asm/levels", func_L39_00689AC8);

/* localdecomp:start func_L39_00689B58 */
extern int D_L39_003D28C0[];
extern void func_L01_00516470(int);

void func_L39_00689B58(void) {
    if (*(unsigned char *)&D_001DC30A_sda != 0)
        func_L01_00516470(D_L39_003D28C0[0]);
}
/* localdecomp:end func_L39_00689B58 */

/* localdecomp:start func_L39_00689B80 */
extern int D_L39_003D28C0[];
extern void func_L01_00516AA0();
__asm__(".extern D_L39_003D28C0, 16");
void func_L39_00689B80(void)
{
    if (D_001DC30A_sda)
        func_L01_00516AA0(D_L39_003D28C0[0], 1, 0);
}
/* localdecomp:end func_L39_00689B80 */

/* localdecomp:start func_L39_00689BB0 */
extern s32 D_L39_003D28B0[];
void func_L01_00516AA0(s32);

void func_L39_00689BB0(void) {
    func_L01_00516AA0(D_L39_003D28B0[0]);
}
/* localdecomp:end func_L39_00689BB0 */

INCLUDE_ASM("asm/levels", func_L39_00689BD8);

INCLUDE_ASM("asm/levels", func_L39_00689D28);

INCLUDE_ASM("asm/levels", func_L39_00689DB8);

INCLUDE_ASM("asm/levels", func_L39_00689E58);
