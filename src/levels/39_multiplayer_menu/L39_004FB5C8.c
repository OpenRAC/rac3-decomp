#include "common.h"

/* declared by functions of L39_004F9B38.c, which this file was cut from */
extern void func_L39_004BC6C8(int, int, int, int, int);

/* localdecomp:start func_L39_004FB5C8 */
typedef struct {
    s32 f0;
    s32 f4;
} S_4FB5C8;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_005373D8 */
void *func_L39_004FB5C8(void) {
    S_4FB5C8 *p = func_L39_004BEED8(8);
    if (p == 0) {
        s32 err[12];
        err[11] = 0xD6;
        func_L39_004BC6C8(0xD, 0x77, 0x21, 0, 0);
        return 0;
    }
    p->f0 = -1;
    p->f4 = 0;
    return p;
}
/* localdecomp:end func_L39_004FB5C8 */

INCLUDE_ASM("asm/levels", func_L39_004FB620);
