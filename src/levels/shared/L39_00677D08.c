#include "common.h"

/* localdecomp:start func_L39_00677D08 */
s32 func_L39_005B43C8(s32, s32);
void func_L39_0060AE30(s32, s32);
extern s32 D_L39_0024D028[];
extern s32 D_L39_0024D02C[];
extern s32 D_L39_0024D030[];
extern s32 D_L39_0024D034[];
extern s32 D_L39_0024D038[];
extern f32 D_L39_0024D03C[];

s32 func_L39_00677D08(s32 arg0) {
    D_L39_0024D030[0] = arg0;
    D_L39_0024D03C[0] = 1.0f;
    D_L39_0024D02C[0] = 0x4B;
    D_L39_0024D028[0] = 0;
    D_L39_0024D034[0] = 0;
    D_L39_0024D038[0] = func_L39_005B43C8(0x1A, 0x23);
    func_L39_0060AE30(0, 0);
    return 1;
}
/* localdecomp:end func_L39_00677D08 */

INCLUDE_ASM("asm/levels", func_L39_00677D78);

/* localdecomp:start func_L39_00677EF0 */
extern void func_L39_00589538(s32);
extern void func_L39_00679630(void);
extern void func_L39_00677F28(void);
extern void func_00389370(void);
void func_L39_00677EF0(void) {
    func_L39_00589538(1);
    func_L39_00679630();
    func_L39_00677F28();
    func_00389370();
}
/* localdecomp:end func_L39_00677EF0 */
