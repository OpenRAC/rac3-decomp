#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D8B18);

INCLUDE_ASM("asm/levels", func_L07_003D8E28);

INCLUDE_ASM("asm/levels", func_L07_003D90A8);

INCLUDE_ASM("asm/levels", func_L07_003D9218);

/* localdecomp:start func_L07_003D9260 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003D93F0();

void func_L07_003D9260(s32 arg0) {
    func_L07_003D93F0();
    func_L01_004450F0(arg0, 4, -1);
}
/* localdecomp:end func_L07_003D9260 */

INCLUDE_ASM("asm/levels", func_L07_003D9298);

INCLUDE_ASM("asm/levels", func_L07_003D9330);

INCLUDE_ASM("asm/levels", func_L07_003D93F0);

INCLUDE_ASM("asm/levels", func_L07_003D9548);

/* localdecomp:start func_L07_003D9630 */
extern s32 func_L07_00333AB8(void *);
extern f32 func_L01_0040E570(void *, void *);

s32 func_L07_003D9630(u8 *arg0) {
    s32 *p;
    u8 *a;
    s32 i = 0;

    a = *(u8 **)(arg0 + 0x68);
    p = (s32 *)(a + 0x20);
    do {
        if (*p != 0) {
            if (func_L07_00333AB8((void *)*p) == 0) {
                if (484.0f < func_L01_0040E570((u8 *)*p + 0x10, *(u8 **)a + 0x10)) {
                    return 0;
                }
            }
            *p = 0;
        }
        i++;
        p++;
    } while (i < 2);
    return 1;
}
/* localdecomp:end func_L07_003D9630 */
