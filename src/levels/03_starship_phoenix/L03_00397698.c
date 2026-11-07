#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00397698);

INCLUDE_ASM("asm/levels", func_L03_003979F0);

INCLUDE_ASM("asm/levels", func_L03_00397B38);

INCLUDE_ASM("asm/levels", func_L03_00397BF0);

INCLUDE_ASM("asm/levels", func_L03_00397C78);

INCLUDE_ASM("asm/levels", func_L03_00397CF8);

/* localdecomp:start func_L03_00397E78 */
typedef struct { char pad[0x68]; char *p68; } S_00397E78;
extern S_00397E78 *D_001DE310_sda;
__asm__(".extern D_001DE310_sda, 4");
void func_L03_00397E78(int a) {
    char *p = D_001DE310_sda->p68;
    if (p != 0) {
        p[0x1C] = a;
    }
}
/* localdecomp:end func_L03_00397E78 */
