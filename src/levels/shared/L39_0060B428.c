#include "common.h"

/* localdecomp:start func_L39_0060B428 */
extern void func_003861F0(void);
extern void func_L39_00587E80(void);
extern void func_L39_0060B478(void);
extern void func_L01_00415728(void);
extern s32 D_L39_001E0448;
extern void (*D_L39_001DA110)(void);
void func_L39_0060B428(void) {
    func_003861F0();
    func_L39_00587E80();
    D_L39_001E0448 = -1;
    if (D_L39_001DA110 != 0) {
        D_L39_001DA110();
    }
    func_L39_0060B478();
    func_L01_00415728();
}
/* localdecomp:end func_L39_0060B428 */

INCLUDE_ASM("asm/levels", func_L39_0060B478);

INCLUDE_ASM("asm/levels", func_L39_0060B4C8);

INCLUDE_ASM("asm/levels", func_L39_0060B560);

INCLUDE_ASM("asm/levels", func_L39_0060B6F8);

INCLUDE_ASM("asm/levels", func_L39_0060B750);
