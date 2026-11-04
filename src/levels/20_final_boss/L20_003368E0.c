#include "common.h"

/* localdecomp:start func_L20_003368E0 */
extern s32 D_001A71A4[];
extern s32 D_L20_001DEBF4;
extern s32 D_L20_001DEBF0;
extern s32 D_L20_001D6694;
extern s32 D_L20_001DCAC0;
__asm__(".extern D_L20_001DCAB8, 4");
extern s32 D_L20_001DCAB8;
extern s32 D_L20_001DCAC4;
extern s32 func_0038CB00(void *);
extern void func_L20_00336AA0(void *);
extern void func_L20_00337140(void *);
extern void func_L20_003372C8(void *);
extern void func_L01_00404A10(void *, void *);

void func_L20_003368E0(u8 *self)
{
    u8 *state;
    s32 one;

    state = *(u8 **)(self + 0x68);
    if (D_L20_001DEBF4 != 0 && *(s32 *)(state + 0x66C) == 0)
        return;
    if (D_L20_001DEBF0 != 0)
        return;
    if (*(s32 *)0x1D545C == 0x14) {
        if (D_001A71A4[0] == 0xB0)
            return;
    }
    if (D_L20_001D6694 == 2)
        return;
    one = 1;
    switch (self[0x20]) {
    case 0:
        func_L20_00336AA0(self);
        *(s16 *)(state + 0x10) = (*(s32 *)(state + 0xC) * 5 + 2) / 6;
        self[0x20] = 2;
        *(f32 *)(state + 0x624) = 2.5f;
        *(s16 *)(state + 8) = one;
        *(s16 *)(state + 0xA) = one;
        **(s32 **)(state + 0x664) = -1;
        break;
    case 1:
        break;
    case 2:
        if (func_0038CB00(state + 0x10) != 0) {
            self[0x20] = 3;
            *(s16 *)(state + 0x10) = 100;
        }
        break;
    case 3:
        if (func_0038CB00(state + 0x10) != 0) {
            if (*(s16 *)(state + 6) != 0)
                self[0x20] = 2;
            *(s16 *)(state + 0x10) = 0;
        } else if (*(s16 *)(state + 0x12) == 0) {
            func_L20_00336AA0(self);
        }
        break;
    }
    if (*(s16 *)(state + 0x12) != 0) {
        if (D_L20_001DCAC0 == 0)
            func_L20_00337140(self);
        if (D_L20_001DCAB8 < *(s16 *)(state + 0x12) && D_L20_001DCAC4 == 0)
            func_L01_00404A10(func_L20_003372C8, self);
    }
}
/* localdecomp:end func_L20_003368E0 */

INCLUDE_ASM("asm/levels", func_L20_00336AA0);

INCLUDE_ASM("asm/levels", func_L20_00337140);

INCLUDE_ASM("asm/levels", func_L20_003372C8);
