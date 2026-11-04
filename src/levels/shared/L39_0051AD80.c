#include "common.h"

/* localdecomp:start func_L39_0051AD80 */
extern f32 D_L39_0024BB4C;
extern s32 func_L01_003F7EE8(u8 *self);
extern s32 func_L39_005B4398(s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L39_0051AD80(u8 *self)
{
    switch (self[0x20]) {
    case 0:
        if (func_L01_003F7EE8(self) != 0 ||
            (0.949999988079071044921875f < D_L39_0024BB4C && func_L39_005B4398(10) == 0)) {
            func_L01_004450F0(self, 1, -1);
            *(u16 *)(self + 0x34) |= 0x2800;
        }
        break;
    case 1:
        func_L01_003F7EE8(self);
        if (self[0x23] < 2)
            func_003C2880(self);
        else
            self[0x23] -= 2;
        break;
    }
}
/* localdecomp:end func_L39_0051AD80 */
