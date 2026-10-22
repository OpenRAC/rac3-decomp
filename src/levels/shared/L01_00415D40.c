#include "common.h"

/* localdecomp:start func_L01_00415D40 */
extern s32 D_L01_001D654C;
extern s32 D_L01_001D6550;
extern s32 D_L01_001D6554;
extern u8 D_L01_001D6558;
void func_L01_00415D40(s32 a, s32 b, s32 c, u8 d) {
    D_L01_001D654C = a;
    D_L01_001D6550 = b;
    D_L01_001D6554 = c;
    D_L01_001D6558 = d;
}
/* localdecomp:end func_L01_00415D40 */

/* localdecomp:start func_L01_00415D58 */
extern s32 D_L01_001EA700[];
s32 func_L01_00415D58(void) {
    return D_L01_001EA700[0];
}
/* localdecomp:end func_L01_00415D58 */

/* localdecomp:start func_L01_00415D68 */
extern s32 D_L01_001EA748[];

s32 func_L01_00415D68(void) {
    return D_L01_001EA748[0];
}
/* localdecomp:end func_L01_00415D68 */

/* localdecomp:start func_L01_00415D78 */
extern s32 D_L01_001EA700[];
extern s32 func_003A0EA8(s32);
extern void func_0013C1D0(s32);
extern void func_003A1D00(void);
extern void func_0013B620(void);
extern void func_L01_004606A8(s32);

void func_L01_00415D78(void) {
    if (func_003A0EA8(3) == 0) {
        func_0013C1D0(77);
        func_003A1D00();
        func_0013B620();
    }
    func_L01_004606A8(0);
    D_L01_001EA700[0] = 0;
}
/* localdecomp:end func_L01_00415D78 */

/* localdecomp:start func_L01_00415DC8 */
extern s32 D_L01_001EA754[];
void func_L01_00415DC8(s32 a0) {
    D_L01_001EA754[0] = a0;
}
/* localdecomp:end func_L01_00415DC8 */

INCLUDE_ASM("asm/levels", func_L01_00415DD8);
