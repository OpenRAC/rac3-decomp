#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003F3740);

/* localdecomp:start func_L01_003F3768 */
extern u8 D_L01_001E2A40[];

void func_L01_003F3768(s32 idx) {
    u8 *p;

    p = D_L01_001E2A40 + idx * 0x460;
    p = *(u8 **)(p + 0x124);
    if (p != 0) {
        *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L01_003F3768 */

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
