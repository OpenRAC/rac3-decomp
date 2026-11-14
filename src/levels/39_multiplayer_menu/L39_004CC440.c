#include "common.h"

/* localdecomp:start func_L39_004CC440 */
typedef struct { s32 n; void *p; } S_004CC440;
extern void *func_0011D534(void *, s32, u32);

void func_L39_004CC440(S_004CC440 *arg0) {
    if (arg0 != 0 && arg0->n > 0) {
        func_0011D534(arg0->p, 0, arg0->n * 4);
        arg0->n = 0;
    }
}
/* localdecomp:end func_L39_004CC440 */

INCLUDE_ASM("asm/levels", func_L39_004CC480);

/* localdecomp:start func_L39_004CC510 */
extern void func_L39_004CC480(void *);
extern void func_L39_004CC538(void *);

void func_L39_004CC510(void *arg0) {
    func_L39_004CC480(arg0);
    func_L39_004CC538(arg0);
}
/* localdecomp:end func_L39_004CC510 */

INCLUDE_ASM("asm/levels", func_L39_004CC538);

INCLUDE_ASM("asm/levels", func_L39_004CC5B8);

INCLUDE_ASM("asm/levels", func_L39_004CC718);

INCLUDE_ASM("asm/levels", func_L39_004CC7A8);

/* localdecomp:start func_L39_004CC800 */
typedef struct S_004CC800_inner {
    u8 pad0[0x14];
    s32 field14;
} S_004CC800_inner;

typedef struct S_004CC800 {
    s32 pad0;
    S_004CC800_inner *field4;
} S_004CC800;

s32 func_L39_004CC800(S_004CC800 *arg0) {
    return arg0->field4->field14;
}
/* localdecomp:end func_L39_004CC800 */

INCLUDE_ASM("asm/levels", func_L39_004CC810);

INCLUDE_ASM("asm/levels", func_L39_004CCBD8);

INCLUDE_ASM("asm/levels", func_L39_004CCD18);
