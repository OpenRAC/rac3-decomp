#include "common.h"

/* localdecomp:start func_L40_0041D4B8 */
extern u8 *D_L40_0024845C __attribute__((section(".data")));
extern void (**func_L01_0043B568(s32, s32, s32))(void *, void *, void *);

void func_L40_0041D4B8(u8 *a0, void *a1, s32 a2) {
    s32 *p = *(s32 **)(a0 + 0x68);
    s32 i;
    u8 *e;
    void (**h)(void *, void *, void *);

    for (i = 7; i >= 0; ) {
        s32 v = *p;
        i--;
        p++;
        if (v >= 0) {
            e = D_L40_0024845C + (v << 8);
            if (a2 != 0) {
                h = func_L01_0043B568(*(s16 *)(e + 0xAA), 0x4027572, 4);
                if (h != 0) {
                    (*h)(e, a1, a0);
                }
            } else {
                h = func_L01_0043B568(*(s16 *)(e + 0xAA), 0x4027571, 4);
                if (h != 0) {
                    (*h)(e, a1, a0);
                }
            }
        }
    }
}
/* localdecomp:end func_L40_0041D4B8 */

INCLUDE_ASM("asm/levels", func_L40_0041D5A8);
