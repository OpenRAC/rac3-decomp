#include "common.h"

/* localdecomp:start func_L39_004C6100 */
typedef struct S_004C6100 {
    u8 pad[0xD4];
    s32 fD4;
    s32 fD8;
} S_004C6100;

extern void func_L39_004C6120(S_004C6100 *);

void func_L39_004C6100(S_004C6100 *s, s32 arg1) {
    if (s->fD4 == 0) {
        s->fD8 = arg1;
        s->fD4 = 3;
        func_L39_004C6120(s);
    }
}
/* localdecomp:end func_L39_004C6100 */

INCLUDE_ASM("asm/levels", func_L39_004C6120);

INCLUDE_ASM("asm/levels", func_L39_004C6220);

INCLUDE_ASM("asm/levels", func_L39_004C6250);

INCLUDE_ASM("asm/levels", func_L39_004C63A8);
