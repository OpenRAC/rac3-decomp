#include "common.h"

struct S { char pad[0x164]; int a; int b; };

INCLUDE_ASM("asm/levels", func_L39_005E2E30);

/* localdecomp:start func_L39_005E2F10 */
extern struct S D_001A43E0;
void func_L39_005E2F10(void)
{
    if (D_001A43E0.a < 0) {
        D_001A43E0.b = 0;
        D_001A43E0.a = 0x20;
    }
}
/* localdecomp:end func_L39_005E2F10 */
