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

/* localdecomp:start func_L03_00397608 */
extern u8 D_001DE308_sda[4];
__asm__(".extern D_001DE308_sda, 4");
extern void *D_001DE310_sda;
__asm__(".extern D_001DE310_sda, 8");
extern s32 D_00142C10[];
extern void func_L03_0034B348(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_00397608(s32 idx) {
    if (D_00142C10[0] & 0x80000) {
        func_L03_0034B348(D_001DE308_sda[idx]);
        func_L01_004450F0(D_001DE310_sda, 3, 0);
    }
}
/* localdecomp:end func_L03_00397608 */

/* localdecomp:start func_L03_00397650 */
extern u8 D_001DE308_sda[4];
__asm__(".extern D_001DE308_sda, 4");
extern u8 D_001D5530[8];
s32 func_L03_00397650(s32 i) { return D_001D5530[D_001DE308_sda[i]] != 0; }
/* localdecomp:end func_L03_00397650 */
