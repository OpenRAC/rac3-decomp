#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

/* localdecomp:start func_L39_00504B50 */
extern void func_L39_004DE5D0(void);
extern void func_L39_004DE650(void);

/* from rac4-decomp's func_L00_00540960, renamed */
void func_L39_00504B50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg4 < 0) {
        arg4 = arg0[1];
    }
    if (arg4 != 0) {
        func_L39_004DE5D0();
    } else {
        func_L39_004DE650();
    }
}
/* localdecomp:end func_L39_00504B50 */

INCLUDE_ASM("asm/levels", func_L39_00504B90);

INCLUDE_ASM("asm/levels", func_L39_00504C80);

/* localdecomp:start func_L39_00504DF8 */
s32 func_L39_00504DF8(s32 arg0) {
    return arg0 + 0x2C;
}
/* localdecomp:end func_L39_00504DF8 */

INCLUDE_ASM("asm/levels", func_L39_00504E00);
