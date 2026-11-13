#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005EAD50);

INCLUDE_ASM("asm/levels", func_L39_005EAE70);

/* localdecomp:start func_L39_005EAF10 */
extern s32 func_L01_00517688(void);
extern s32 func_L39_005EBDA0(void);
extern void func_L39_005EBAF0(s32);
extern void func_L39_005E9FA0(s32);
extern void func_L39_005F3548(s32, s32, s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern void func_L01_00353C80(s32);
extern s32 func_L01_0049F168(s32);
extern void func_L01_00517748(s32);

void func_L39_005EAF10(s32 a0) {
    s32 a;
    s32 b;
    a = func_L01_00517688();
    b = func_L39_005EBDA0();
    func_L39_005EBAF0(b);
    if (b & 0xA040) {
        func_L39_005E9FA0(a0);
    } else if (b & 0x900) {
        func_L39_005F3548(4, 0, 0);
        func_L39_0061C0E0(func_L01_00517688(), 0);
        func_L39_005D6468(func_L01_00517688(), 0);
        func_L01_00353C80(a0);
    } else if (b & 0x910) {
        func_L39_005F3548(4, 0, 0);
        func_L01_00517748(func_L01_0049F168(a));
        func_L01_00353C80(a0);
    }
}
/* localdecomp:end func_L39_005EAF10 */

INCLUDE_ASM("asm/levels", func_L39_005EAFF0);

/* localdecomp:start func_L39_005EB198 */
typedef struct { s32 f0; s32 f4; s32 f8; } S_005EB198;
extern S_005EB198 D_L39_0049A498[];
extern s32 D_L39_002B6988[][3];
extern s32 func_L01_00517688(void);
extern s32 func_L01_00516FD8(s32, s32);

void func_L39_005EB198(void) {
    s32 idx = func_L01_00517688();
    func_L01_00516FD8(0x54000A + 0, D_L39_002B6988[0][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 4, D_L39_002B6988[1][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 8, D_L39_002B6988[2][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 12, D_L39_002B6988[3][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 16, D_L39_002B6988[4][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 20, D_L39_002B6988[5][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 24, D_L39_002B6988[10][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 28, D_L39_002B6988[11][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 32, D_L39_002B6988[8][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 36, D_L39_002B6988[7][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 40, D_L39_002B6988[6][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 44, D_L39_002B6988[9][D_L39_0049A498[idx].f0]);
}
/* localdecomp:end func_L39_005EB198 */

INCLUDE_ASM("asm/levels", func_L39_005EB330);
