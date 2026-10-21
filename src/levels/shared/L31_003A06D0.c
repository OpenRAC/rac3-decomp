#include "common.h"

INCLUDE_ASM("asm/levels", func_L31_003A06D0);

INCLUDE_ASM("asm/levels", func_L31_003A0C88);

INCLUDE_ASM("asm/levels", func_L31_003A0D30);

/* localdecomp:start func_L31_003A11E0 */
extern f32 D_L31_001DE748;
extern void func_L01_004AA7E8(u8 *, s32);
void func_L31_003A11E0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    f32 k = 1.0f;
    if (*(s32 *)(s + 60) == 0) {
        k = *(f32 *)(s + 96);
    }
    *(f32 *)(a0 + 44) = *(f32 *)(*(u8 **)(a0 + 36) + 36) * D_L31_001DE748 * k;
    if (*(s32 *)(s + 60) == 0) {
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
    }
    *(s16 *)(s + 12) = 4;
    *(s16 *)(s + 14) = 15;
}
/* localdecomp:end func_L31_003A11E0 */

/* localdecomp:start func_L31_003A1270 */
typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_0039FAB0;

extern void func_L30_0034DAC0(void *);
extern void func_003C2880(Moby_0039FAB0 *);

void func_L31_003A1270(Moby_0039FAB0 *m) {
    u8 *p = m->w68;
    if (*(s32 *)(p + 60)) func_L30_0034DAC0(p + 84);
    func_003C2880(m);
}
/* localdecomp:end func_L31_003A1270 */

INCLUDE_ASM("asm/levels", func_L31_003A12B0);
