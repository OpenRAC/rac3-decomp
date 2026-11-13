#include "common.h"

/* localdecomp:start func_L30_003468C8 */
__asm__(".extern D_L30_001E1188, 16");
extern u8 D_L30_001E1188;
extern void func_L30_003472E8(u8 *);
extern int func_L30_00346FB8(u8 *);
extern void func_L01_004450F0(u8 *, int, int);
extern int func_L30_0034D8D8(u8 *, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L30_00346988();

void func_L30_003468C8(u8 *moby) {
    switch (*(u8 *)(moby + 0x20)) {
    case 1:
        func_L30_003472E8(moby);
        if (func_L30_00346FB8(moby)) {
            func_L01_004450F0(moby, 2, -1);
        }
        if (func_L30_0034D8D8(moby + 0x10, 3.0f) == 0) {
            func_003C2880(moby);
            return;
        }
        {
            func_L30_0034C8A8(&D_L30_001E1188, moby);
            func_L01_00404808(func_L30_00346988, moby);
        }
        break;
    case 2:
        func_L30_00346D08(moby);
        break;
    }
}
/* localdecomp:end func_L30_003468C8 */

INCLUDE_ASM("asm/levels", func_L30_00346988);
