#include "common.h"

/* localdecomp:start func_L30_00346230 */
void func_L30_00346278();
void func_L30_00346320(void *);
void func_L30_00346600(void *);

void func_L30_00346230(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        func_L30_00346278();
    }
    func_L30_00346600(arg0);
    func_L30_00346320(arg0);
}
/* localdecomp:end func_L30_00346230 */

INCLUDE_ASM("asm/levels", func_L30_00346278);

INCLUDE_ASM("asm/levels", func_L30_00346320);

INCLUDE_ASM("asm/levels", func_L30_00346600);

INCLUDE_ASM("asm/levels", func_L30_003467C0);
