#include "common.h"

/* localdecomp:start func_L41_0041B308 */
typedef struct { u8 p0[0x20]; u8 b20; } M_41AA50;
extern void func_L41_0048B8C0(M_41AA50 *, s32);
extern void func_L01_004450F0(M_41AA50 *, s32, s32);

void func_L41_0041B308(M_41AA50 *m) {
    if (m->b20 == 0) {
        func_L41_0048B8C0(m, -1);
        func_L01_004450F0(m, 1, -1);
    }
}
/* localdecomp:end func_L41_0041B308 */

INCLUDE_ASM("asm/levels", func_L41_0041B350);

INCLUDE_ASM("asm/levels", func_L41_0041B578);

INCLUDE_ASM("asm/levels", func_L41_0041B6F0);

INCLUDE_ASM("asm/levels", func_L41_0041B858);

INCLUDE_ASM("asm/levels", func_L41_0041B9C8);

INCLUDE_ASM("asm/levels", func_L41_0041BAF8);

INCLUDE_ASM("asm/levels", func_L41_0041BDD0);

INCLUDE_ASM("asm/levels", func_L41_0041C170);

INCLUDE_ASM("asm/levels", func_L41_0041C1E8);

INCLUDE_ASM("asm/levels", func_L41_0041C2E8);

INCLUDE_ASM("asm/levels", func_L41_0041C328);

INCLUDE_ASM("asm/levels", func_L41_0041C430);

INCLUDE_ASM("asm/levels", func_L41_0041C568);

INCLUDE_ASM("asm/levels", func_L41_0041C778);

LINKER_REMNANT("asm/levels", func_L41_0041CCE0);

INCLUDE_ASM("asm/levels", func_L41_0041CCF8);
