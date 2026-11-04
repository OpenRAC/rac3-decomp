#include "common.h"

/* localdecomp:start func_L32_003BE008 */
void func_L32_003BE830();
void func_L32_003BED60(void *);
void func_L32_003BE960(void *);
void func_L32_003BE498(void *);
void func_L01_00404A10(void *, void *);
void func_L01_004450F0(void *, s32, s32);

void func_L32_003BE008(void *arg0) {
    u8 a = *(volatile u8 *)((u8 *)arg0 + 0x20);
    u8 t;
    if (a != 0) {
        t = *(u8 *)((u8 *)arg0 + 0x20);
    } else {
        do {
            func_L32_003BE830();
        } while (0);
        func_L01_004450F0(arg0, 1, -1);
        t = *(u8 *)((u8 *)arg0 + 0x20);
    }
    switch (t) {
    case 1:
        func_L32_003BED60(arg0);
        break;
    case 2:
        func_L32_003BE960(arg0);
        break;
    }
    func_L01_00404A10(func_L32_003BE498, arg0);
}
/* localdecomp:end func_L32_003BE008 */

INCLUDE_ASM("asm/levels", func_L32_003BE098);

/* localdecomp:start func_L32_003BE498 */
void func_L32_003BE098(void *);
void func_L32_003BE4E8();

void func_L32_003BE498(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 0xFDU) {
        func_L32_003BE4E8();
        if ((*(u8 *)((u8 *)arg0 + 0x20)) == 2) {
            func_L32_003BE098(arg0);
        }
    }
}
/* localdecomp:end func_L32_003BE498 */

INCLUDE_ASM("asm/levels", func_L32_003BE4E8);

INCLUDE_ASM("asm/levels", func_L32_003BE5E0);

INCLUDE_ASM("asm/levels", func_L32_003BE830);

INCLUDE_ASM("asm/levels", func_L32_003BE8E0);

INCLUDE_ASM("asm/levels", func_L32_003BE960);

INCLUDE_ASM("asm/levels", func_L32_003BED60);
