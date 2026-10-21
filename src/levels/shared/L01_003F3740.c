#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003F3740);

INCLUDE_ASM("asm/levels", func_L01_003F3768);

/* localdecomp:start func_L01_003F37A0 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_L01_002F7680[];
void func_L01_003F37A0(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_L01_002F7680[*(s16 *)(p + 0x8C)].c;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_L01_003F37A0 */
