#include "common.h"

/* localdecomp:start func_L28_003098F0 */
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s16 D_001426A2[];
extern s32 D_001426A4[];
s32 func_L28_003098F0(void) {
    if (D_001D545C == 0x1C) return D_001426A2[0];
    if (D_001D545C == 0x13) return D_001426A4[0];
    return 0;
}
/* localdecomp:end func_L28_003098F0 */

/* localdecomp:start func_L28_00309928 */
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;

/* from rac2-decomp's func_L08_003DB4E8 */
s32 func_L28_00309928(void)
{
    s32 v = D_001D545C;
    s32 r = 1;
    if (v == 8)
        return 1;
    if (v == 0x13)
        r = 2;
    return r;
}
/* localdecomp:end func_L28_00309928 */

INCLUDE_ASM("asm/levels", func_L28_00309958);

/* localdecomp:start func_L28_00309CE8 */
/* Ps2EeAs uses $gp for these only if it knows they are small before the first use;
   D_L28_001DE840 stays unknown, so its delay-slot copy is the only $gp read of it. */
__asm__(".extern D_L28_001DC560, 4");
__asm__(".extern D_L28_001D6694, 4");
typedef int u128_00309CE8 __attribute__((mode(TI)));
extern u128_00309CE8 D_001A4C60;
extern u8 *D_L28_001DC560;
extern s32 D_L28_001DE840;
extern s32 D_L28_001D6694;
extern void func_L28_00309958(void);
extern s32 func_L24_0041CE48(s32 a, void *b, s32 c);

/* from rac2-decomp's func_L08_003DB8E8 */
void func_L28_00309CE8(u8 *self) {
    s32 *vars = *(s32 **)(self + 0x68);
    s32 count;
    s32 shown;

    *(u128_00309CE8 *)(self + 0x10) = D_001A4C60;
    count = func_L28_003098F0();
    if (self[0x20] == 0) {
        self[0x20] = 1;
        vars[0] = count;
        vars[1] = 0;
        self[0x30] = 0xFF;
        D_L28_001DC560 = self;
    }
    if (D_L28_001DE840 % 10 == 0) {
        shown = vars[0];
        if (shown < count) {
            vars[1] = 0;
            vars[0] = shown + 1;
        } else if (count < shown) {
            vars[0] = shown - 1;
        }
    }
    if (count > 0 && D_L28_001D6694 != 2 && (self[0x20] == 1 || self[0x20] == 2)) {
        self[0x20] = 2;
        func_L24_0041CE48(0, func_L28_00309958, 2);
        return;
    }
    if ((count <= 0 || D_L28_001D6694 == 2) && self[0x20] == 2) {
        func_L24_0041CE48(0, 0, 2);
        self[0x20] = 1;
    }
}
/* localdecomp:end func_L28_00309CE8 */
