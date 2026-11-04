#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005089B0);

INCLUDE_ASM("asm/levels", func_L39_00508A98);

/* localdecomp:start func_L39_00508B30 */
extern u8 D_L39_0046F030[];

s32 func_L39_00508B30(void **arg0) {
    *arg0 = D_L39_0046F030;
    return 1;
}
/* localdecomp:end func_L39_00508B30 */

INCLUDE_ASM("asm/levels", func_L39_00508B48);

INCLUDE_ASM("asm/levels", func_L39_00508C28);

LINKER_REMNANT("asm/levels", func_L39_00508D38);

INCLUDE_ASM("asm/levels", func_L39_00508D40);

INCLUDE_ASM("asm/levels", func_L39_00508DC0);

/* localdecomp:start func_L39_00508E58 */
extern void func_L39_00511A50(void);
extern void func_L39_00512018(void);
extern void func_L39_005120B0(void);
extern void func_L39_00512BA8(void);
extern void func_L39_00513808(void);
extern void func_L39_00513FA0(void);
extern void func_L39_00512B20(void);

void func_L39_00508E58(void **p, void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6) {
    if (a0) {
        p[0] = a0;
    } else {
        p[0] = (void *)func_L39_00511A50;
    }
    if (a1) {
        p[1] = a1;
    } else {
        p[1] = (void *)func_L39_00512018;
    }
    if (a2) {
        p[2] = a2;
    } else {
        p[2] = (void *)func_L39_005120B0;
    }
    if (a3) {
        p[3] = a3;
    } else {
        p[3] = (void *)func_L39_00512BA8;
    }
    if (a4) {
        p[4] = a4;
    } else {
        p[4] = (void *)func_L39_00513808;
    }
    if (a5) {
        p[5] = a5;
    } else {
        p[5] = (void *)func_L39_00513FA0;
    }
    if (a6) {
        p[6] = a6;
    } else {
        p[6] = (void *)func_L39_00512B20;
    }
}
/* localdecomp:end func_L39_00508E58 */

INCLUDE_ASM("asm/levels", func_L39_00508F08);
