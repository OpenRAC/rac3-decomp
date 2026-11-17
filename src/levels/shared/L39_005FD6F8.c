#include "common.h"

/* declared by functions of L39_005FD458.c, which this file was cut from */
extern s32 D_L39_0024CAE8;
extern s32 D_L39_0024CAEC;

/* localdecomp:start func_L39_005FD6F8 */
extern s32 D_L39_0024CAE8;
extern s32 D_L39_0024CAEC;
__asm__(".extern D_L39_0024CAE8, 16");
__asm__(".extern D_L39_0024CAEC, 16");
extern void func_00125F90(s32, s32);
extern void func_00126DD0(s32);

void func_L39_005FD6F8(void)
{
    if (*(volatile u32 *)0x1000E010 & 0x20000) { /* D_STAT */
        *(volatile u32 *)0x1000E010 = 0x20000;
    }
    func_00125F90(1, D_L39_0024CAE8);
    func_00125F90(0xF, D_L39_0024CAEC);
    func_00126DD0(1);
    D_L39_0024CAE8 = 0;
    D_L39_0024CAEC = 0;
}
/* localdecomp:end func_L39_005FD6F8 */
