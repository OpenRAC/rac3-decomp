/* PAL retail reconstruction, P08 wave 3.
 * Stock check.py: 58 positional differences with the owner's unchanged
 * -O2 -G8 -fopt-stack -mno-check-zero-division flags (initially 85).
 * A one-entry iteration with the function's early exit reproduces the live
 * zero index and the 0x40 frame. Remaining: object/state saved-register roles,
 * branch/epilogue slot selection and body layout. Fully indexed accesses were
 * worse (64); an outer iteration also worsened allocation.
 * The owning INCLUDE_ASM remains. Full PAL/US linkage is not verified.
 */
#include "common.h"
typedef int Q_3B9590 __attribute__((mode(TI)));
extern Q_3B9590 D_001A4C60;
extern void func_L07_003B98E0(void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_003F2A50(s32, s32);
extern void func_L01_003F2AF8(s32, s32);
extern void func_L07_003B96F8(u8 *, s32);
void func_L07_003B9590(u8 *arg0) {
    Q_3B9590 position = D_001A4C60;
    u8 *s = *(u8 **)(arg0 + 0x68);
    s32 i = 0;
    switch (arg0[0x20]) {
    case 0:
        func_L07_003B98E0(arg0);
        break;
    case 2:
        for (; i < 1; i++) {
        if (func_00382380(&position, *(s32 *)s, 0) &&
            *(s32 *)(s + 0x30) == 0 &&
            (*(s32 *)(s + 0x60) == -1 || func_L01_00445AD0(*(s32 *)(s + 0x60), -1, 0))) {
            *(s32 *)(s + 0x40) = func_L01_003F2A50(0, 5);
            *(s32 *)(s + 0x30) = 1;
            func_L07_003B96F8(arg0, 0);
        } else if (((s32 *)(s + 0x30))[i] != 0 &&
                   (!func_00382380(&position, *(s32 *)s, 0) ||
                    (*(s32 *)(s + 0x60) != -1 && !func_L01_00445AD0(*(s32 *)(s + 0x60), -1, 0)))) {
            func_L01_003F2AF8(0, ((s32 *)(s + 0x40))[i]);
            ((s32 *)(s + 0x30))[i] = 0;
        }
        return;
        }
        break;
    case 1:
        break;
    }
}
