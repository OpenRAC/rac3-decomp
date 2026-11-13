#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005E6B08);

/* localdecomp:start func_L39_005E6C78 */
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 D_001D8448_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8448_sda, 8");
extern s32 D_001D8458_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8458_sda, 8");
extern s32 D_001D84B8_sda;

void func_L39_005E6C78(void) {
    s32 k = 0;

    switch (func_L01_00517688()) {
    case 0:
        break;
    case 1:
        k = 1;
        break;
    case 2:
        k = 2;
        break;
    case 3:
        k = 3;
        break;
    }
    D_001D8448_sda[func_L01_00517688()] = func_003B9C58(func_003B9BD0(k));
    if (D_001D8458_sda[func_L01_00517688()] != D_001D8448_sda[func_L01_00517688()]) {
        D_001D84B8_sda = 30;
    }
    if (D_001D84B8_sda != 0) {
        D_001D84B8_sda--;
    }
    D_001D8458_sda[func_L01_00517688()] = D_001D8448_sda[func_L01_00517688()];
}
/* localdecomp:end func_L39_005E6C78 */

INCLUDE_ASM("asm/levels", func_L39_005E6D80);
