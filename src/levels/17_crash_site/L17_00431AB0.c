#include "common.h"

/* localdecomp:start func_L17_00431AB0 */
extern u8 *D_L17_001DF180_a;
__asm__(".extern D_L17_001DF180_a, 16");
extern void func_L05_00451228(s32, s32, s32, s32, u8 *, u8 *);
void func_L17_00431AB0(s32 a0, s32 a1, s32 a2, s32 a3, s32 i) {
    u8 *p;
    if (i != -1) {
        p = D_L17_001DF180_a + (i << 7);
        func_L05_00451228(a0, a1, a2, a3, p + 0x30, p + 0x70);
    }
}
/* localdecomp:end func_L17_00431AB0 */
