#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0063E9E8);

INCLUDE_ASM("asm/levels", func_L39_0063EA20);

/* localdecomp:start func_L39_0063EC20 */
extern void func_L39_0063EA20(u8 *, u8 *);

void func_L39_0063EC20(u8 *a0) {
    s32 i;
    u8 *p = a0 + 1888;

    *(s16 *)(a0 + 9378) = 0;
    for (i = 11; i >= 0; i--) {
        func_L39_0063EA20(a0, p);
        p += 176;
    }
}
/* localdecomp:end func_L39_0063EC20 */

INCLUDE_ASM("asm/levels", func_L39_0063EC78);

INCLUDE_ASM("asm/levels", func_L39_0063ED28);

INCLUDE_ASM("asm/levels", func_L39_0063EE68);

INCLUDE_ASM("asm/levels", func_L39_0063EE70);

INCLUDE_ASM("asm/levels", func_L39_0063EE78);

INCLUDE_ASM("asm/levels", func_L39_0063F0C0);

INCLUDE_ASM("asm/levels", func_L39_0063F0C8);

INCLUDE_ASM("asm/levels", func_L39_0063FC90);

INCLUDE_ASM("asm/levels", func_L39_0063FDA8);

INCLUDE_ASM("asm/levels", func_L39_00640698);

LINKER_REMNANT("asm/levels", func_L39_00640728);

INCLUDE_ASM("asm/levels", func_L39_00640738);

INCLUDE_ASM("asm/levels", func_L39_006439E0);

INCLUDE_ASM("asm/levels", func_L39_00643B98);

INCLUDE_ASM("asm/levels", func_L39_00643F50);

INCLUDE_ASM("asm/levels", func_L39_00644448);
