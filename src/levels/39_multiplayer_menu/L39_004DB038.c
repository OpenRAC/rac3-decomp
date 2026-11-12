#include "common.h"

/* localdecomp:start func_L39_004DB038 */
s32 func_L39_004DB038(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x18));
}
/* localdecomp:end func_L39_004DB038 */

INCLUDE_ASM("asm/levels", func_L39_004DB040);

INCLUDE_ASM("asm/levels", func_L39_004DB090);

INCLUDE_ASM("asm/levels", func_L39_004DB0D8);

/* localdecomp:start func_L39_004DB110 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_L39_004BEED8(s32 arg0);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Type1;

/* from rac4-decomp's func_L00_00516F10, renamed */
void *func_L39_004DB110(void) {
    Type1 *p = (Type1 *)func_L39_004BEED8(0xC);
    if (p != 0) {
        p->f0 = 0;
        p->f8 = 0;
        p->f4 = 0;
        return p;
    }
    func_L39_004BC6C8(7, 0x65, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DB110 */

INCLUDE_ASM("asm/levels", func_L39_004DB168);

INCLUDE_ASM("asm/levels", func_L39_004DB1C0);
