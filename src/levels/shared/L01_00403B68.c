#include "common.h"

/* localdecomp:start func_L01_00403B68 */
extern s32 D_L01_001DF944;
extern void func_00388AF8(s32);

void func_L01_00403B68(void) {
    D_L01_001DF944 = 0x100FF;
    func_00388AF8(0);
}
/* localdecomp:end func_L01_00403B68 */

/* localdecomp:start func_L01_00403B90 */
extern s32 D_L01_001DF944;
extern void func_00388AF8(s32);

void func_L01_00403B90(void) {
    D_L01_001DF944 = 80;
    func_00388AF8(0);
}
/* localdecomp:end func_L01_00403B90 */

/* localdecomp:start func_L01_00403BB8 */
extern s32 D_L01_001DF944;
extern void func_00392350(s32);
extern void func_00388AF8(s32);

void func_L01_00403BB8(void) {
    func_00392350(0);
    D_L01_001DF944 = 127;
    func_00388AF8(0);
}
/* localdecomp:end func_L01_00403BB8 */

INCLUDE_ASM("asm/levels", func_L01_00403BE8);

/* localdecomp:start func_L01_00403C48 */
extern s32 D_L01_001DF944;
extern void func_00392350(s32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_00388AF8(s32);

void func_L01_00403C48(void) {
    func_00392350(0);
    func_0038AE20(0, 0, 0, 128);
    D_L01_001DF944 = 240;
    func_00388AF8(0);
}
/* localdecomp:end func_L01_00403C48 */

/* localdecomp:start func_L01_00403C88 */
extern void func_L01_004CB540_00403C88(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_00389240(s32);
extern void func_L01_0047E4C0(void);
extern void func_L01_00478AA0(void);
extern void func_003B3158(s32);
extern void func_L01_00478AD8(void);
extern void func_00389370(void);

void func_L01_00403C88(void) {
    func_L01_004CB540_00403C88(0);
    func_003A9440(71, 0x33001UL);
    func_00389240(0);
    func_L01_0047E4C0();
    func_L01_00478AA0();
    func_003B3158(0);
    func_L01_00478AD8();
    func_00389370();
}
/* localdecomp:end func_L01_00403C88 */
