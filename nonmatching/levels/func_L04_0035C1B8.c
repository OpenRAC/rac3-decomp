/* PAL near miss (b9-t2): every instruction matches except two nops that retail has between the li.s of 0.99f and the sqrt.s (our assembler inserts none there), so the code after it shifts by two words; sqrt_asm for the sqrt.s */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L04_0035C1B8 */
extern f32 func_L01_0040E548(void *, void *);
__asm__(".extern D_001DD4E8, 4");
__asm__(".extern D_001DD4EC, 4");
__asm__(".extern D_001DD4F0, 4");
__asm__(".extern D_001DD4F4, 4");
extern f32 D_001DD4E8;
extern s32 D_001DD4EC;
extern f32 D_001DD4F0;
extern s32 D_001DD4F4;

void func_L04_0035C1B8(u8 *a0, u8 *a1) {
    f32 max;
    f32 d;
    s32 i;
    s32 v;
    u8 *p;

    max = 0.0f;
    p = a1 + 0x50;
    for (i = 3; i >= 0; i--) {
        if (*(s32 *)(p + 0x20) != 0) {
            d = func_L01_0040E548(a0 + 0x10, p + 0x10);
            if (max < d) {
                max = d;
            }
        }
        p += 0x30;
    }
    if (max > 0.0f) {
        max = sqrt_asm(max) + 0.99f;
        v = (s32)(max + D_001DD4E8);
        if (v > D_001DD4EC) {
            v = D_001DD4EC;
        }
        a0[0x30] = v;
        v = (s32)(max + D_001DD4F0);
        if (v > D_001DD4F4) {
            v = D_001DD4F4;
        }
        *(s16 *)(a0 + 0x32) = v;
    } else {
        a0[0x30] = D_001DD4EC;
        *(s16 *)(a0 + 0x32) = 0;
    }
}
/* localdecomp:end func_L04_0035C1B8 */
