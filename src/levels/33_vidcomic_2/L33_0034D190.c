#include "common.h"

INCLUDE_ASM("asm/levels", func_L33_0034D190);

INCLUDE_ASM("asm/levels", func_L33_0034D838);

INCLUDE_ASM("asm/levels", func_L33_0034E8C0);

INCLUDE_ASM("asm/levels", func_L33_0034EA80);

INCLUDE_ASM("asm/levels", func_L33_0034EC28);

INCLUDE_ASM("asm/levels", func_L33_0034EE00);

INCLUDE_ASM("asm/levels", func_L33_0034F250);

INCLUDE_ASM("asm/levels", func_L33_0034F530);

/* localdecomp:start func_L33_0034F910 */
void func_L33_0034F998(void *);
void func_L33_00350378(void *);
void func_L33_00350470(void *);
void func_L33_003505D8(void *);

void func_L33_0034F910(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_L33_00350378(arg0);
        break;
    case 1:
        func_L33_00350470(arg0);
        break;
    case 2:
        func_L33_003505D8(arg0);
        break;
    }
    func_L33_0034F998(arg0);
}
/* localdecomp:end func_L33_0034F910 */

INCLUDE_ASM("asm/levels", func_L33_0034F998);

INCLUDE_ASM("asm/levels", func_L33_0034F9D8);
