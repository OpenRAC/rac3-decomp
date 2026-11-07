#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003967C8);

INCLUDE_ASM("asm/levels", func_L03_00396860);

INCLUDE_ASM("asm/levels", func_L03_00396E00);

INCLUDE_ASM("asm/levels", func_L03_00396FF0);

INCLUDE_ASM("asm/levels", func_L03_00397138);

INCLUDE_ASM("asm/levels", func_L03_003971B0);

INCLUDE_ASM("asm/levels", func_L03_00397260);

INCLUDE_ASM("asm/levels", func_L03_00397390);

INCLUDE_ASM("asm/levels", func_L03_003975A8);

INCLUDE_ASM("asm/levels", func_L03_00397608);

/* localdecomp:start func_L03_00397650 */
extern u8 D_001DE308_sda[4];
__asm__(".extern D_001DE308_sda, 4");
extern u8 D_001D5530[8];
s32 func_L03_00397650(s32 i) { return D_001D5530[D_001DE308_sda[i]] != 0; }
/* localdecomp:end func_L03_00397650 */
