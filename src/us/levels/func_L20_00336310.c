#include "common.h"

/* localdecomp:start func_L20_00336310 */
extern s32 D_001A71A4[];
extern s32 D_001D545C[1];
extern s32 D_L20_001DEC34;
extern s32 D_L20_001DEC30;
extern s32 D_L20_001D6694;
extern s32 D_L20_001DCB00;
__asm__(".extern D_L20_001DCAF8, 4");
extern s32 D_L20_001DCAF8;
extern s32 D_L20_001DCB04;
extern s32 func_003883C8(void *);
extern void func_L20_003364B8(void *);
extern void func_L20_00336B00(void *);
extern void func_L20_00336C88(void *);
extern void func_L01_004026A0(void *, void *);

void func_L20_00336310(u8 *self)
{
    u8 *state;
    s32 one;

    state = *(u8 **)(self + 0x68);
    if (D_L20_001DEC34 != 0 && *(s32 *)(state + 0x66C) == 0)
        return;
    if (D_L20_001DEC30 != 0)
        return;
    if (D_001D545C[0] == 0x14) {
        if (D_001A71A4[0] == 0xB0)
            return;
    }
    if (D_L20_001D6694 == 2)
        return;
    one = 1;
    switch (self[0x20]) {
    case 0:
        func_L20_003364B8(self);
        *(s16 *)(state + 0x10) = *(s32 *)(state + 0xC);
        self[0x20] = 2;
        *(f32 *)(state + 0x624) = 2.5f;
        *(s16 *)(state + 8) = one;
        *(s16 *)(state + 0xA) = one;
        **(s32 **)(state + 0x664) = -1;
        break;
    case 1:
        break;
    case 2:
        if (func_003883C8(state + 0x10) != 0) {
            self[0x20] = 3;
            *(s16 *)(state + 0x10) = 120;
        }
        break;
    case 3:
        if (func_003883C8(state + 0x10) != 0) {
            if (*(s16 *)(state + 6) != 0)
                self[0x20] = 2;
            *(s16 *)(state + 0x10) = 0;
        } else if (*(s16 *)(state + 0x12) == 0) {
            func_L20_003364B8(self);
        }
        break;
    }
    if (*(s16 *)(state + 0x12) != 0) {
        if (D_L20_001DCB00 == 0)
            func_L20_00336B00(self);
        if (D_L20_001DCAF8 < *(s16 *)(state + 0x12) && D_L20_001DCB04 == 0)
            func_L01_004026A0(func_L20_00336C88, self);
    }
}
/* localdecomp:end func_L20_00336310 */
