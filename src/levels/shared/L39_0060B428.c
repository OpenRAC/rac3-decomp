#include "common.h"

/* localdecomp:start func_L39_0060B428 */
extern void func_003861F0(void);
extern void func_L39_00587E80(void);
extern void func_L39_0060B478(void);
extern void func_L01_00415728(void);
extern s32 D_L39_0024BB58;
extern void (*D_L39_00245820)(void);
void func_L39_0060B428(void) {
    func_003861F0();
    func_L39_00587E80();
    D_L39_0024BB58 = -1;
    if (D_L39_00245820 != 0) {
        D_L39_00245820();
    }
    func_L39_0060B478();
    func_L01_00415728();
}
/* localdecomp:end func_L39_0060B428 */

INCLUDE_ASM("asm/levels", func_L39_0060B478);

INCLUDE_ASM("asm/levels", func_L39_0060B4C8);

INCLUDE_ASM("asm/levels", func_L39_0060B560);

/* localdecomp:start func_L39_0060B6F8 */
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 D_001FC458[];

void func_L39_0060B6F8(void)
{
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, 0x1000000 | (D_001FC458[0] >> 13));
}
/* localdecomp:end func_L39_0060B6F8 */

INCLUDE_ASM("asm/levels", func_L39_0060B750);
