#include "common.h"

/* localdecomp:start func_L01_0051D5F8 */
void func_L01_0051D5F8(void) {

}
/* localdecomp:end func_L01_0051D5F8 */

/* localdecomp:start func_L01_0051D600 */
extern s32 func_L01_00521C88_0051D600();
extern char D_L01_001DC0C0[];

void func_L01_0051D600(u8 *p, s32 f) { *(u8 **)(p + 8) = D_L01_001DC0C0; if (f & 1) func_L01_00521C88_0051D600(p); }
/* localdecomp:end func_L01_0051D600 */

LINKER_REMNANT("asm/levels", func_L01_0051E060);
