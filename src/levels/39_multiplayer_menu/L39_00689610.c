#include "common.h"

/* localdecomp:start func_L39_00689610 */
extern s32 D_L39_003D2880[];
extern void func_L01_00516AA0();
void func_L39_00689610(void) {
    s32 i;
    s32 *p;
    if (D_L39_003D2880[0x260 / 4] > 0) {
        p = &D_L39_003D2880[0x260 / 4];
        for (i = 5; i >= 0; i--) {
            func_L01_00516AA0(*p, 1, 0);
            p++;
        }
    }
}
/* localdecomp:end func_L39_00689610 */

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
