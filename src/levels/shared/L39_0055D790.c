#include "common.h"

/* declared by functions of L39_0055B418.c, which this file was cut from */
extern s32 D_L39_00242914[];

/* localdecomp:start func_L39_0055D790 */
extern s32 D_L39_00242914[];
extern s32 D_L39_00241118;
extern void func_003C2880(void *);

void func_L39_0055D790(u8 *a0) {
    u8 **p = *(u8 ***)(a0 + 104);
    if (D_L39_00242914[0] != 0 && p != 0 && (*p)[9417] == D_L39_00241118) {
        func_003C2880(a0);
        return;
    }
    *(u16 *)(a0 + 52) &= 0xFFBE;
}
/* localdecomp:end func_L39_0055D790 */
