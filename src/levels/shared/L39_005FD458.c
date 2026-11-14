#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005FD458);

/* localdecomp:start func_L39_005FD668 */
extern s32 D_L39_0024CAE8;
extern s32 D_L39_0024CAEC;
__asm__(".extern D_L39_0024CAE8, 16");
__asm__(".extern D_L39_0024CAEC, 16");
extern void func_003A9B40(void);
extern void func_003A9C40(void);
extern s32 func_00125F70(s32, void (*)(void), s32);
extern void func_00126E38(s32);

void func_L39_005FD668(void)
{
    if (D_L39_0024CAE8 == 0 && D_L39_0024CAEC == 0) {
        if ((*(volatile u32 *)0x1000E010 & 0x20000) == 0) { /* D_STAT */
            *(u32 *)0x1000E010 = 0x20000;
        }
        D_L39_0024CAE8 = func_00125F70(1, func_003A9B40, 0);
        D_L39_0024CAEC = func_00125F70(0xF, func_003A9C40, 0);
        func_00126E38(1);
    }
}
/* localdecomp:end func_L39_005FD668 */

INCLUDE_ASM("asm/levels", func_L39_005FD6F8);
