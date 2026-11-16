/* PAL retail reconstruction, P08 wave 3.
 * Stock check.py: 159 positional differences with the owner's unchanged
 * -O2 -G8 -fopt-stack -mno-check-zero-division flags (initially 176).
 * Explicit case 0 fixes the switch root; an unsized pointer table read restores
 * the non-GP global access. Remaining differences include shared store-tail
 * placement, indexed address operand order and the resulting branch distances.
 * The owning INCLUDE_ASM remains. Full PAL/US linkage is not verified.
 */
#include "common.h"
extern s16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C[];
extern s32 D_001DF458_sda;
extern s32 func_L07_003A7178(void *, void *, s32, s32, s32);
extern s32 func_L07_003BA000(void *, void *, s32, s32, s32, s32);
extern s32 func_L07_003A6C90(void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003B91C8(u8 *arg0, s32 index, s32 value) {
    u8 *s;
    *(u16 *)(arg0 + 0x34) &= 0xFFFD;
    s = *(u8 **)(arg0 + 0x68);
    *(s32 *)(s + 0x7C) = index;
    switch (s[index]) {
    case 1: {
        s16 *p = D_L07_0021C020[*(s32 *)(s + 0x70)];
        while ((*(s32 *)(s + 0x70) & 0xFF) != 0xFF &&
               D_001DF458_sda >= *(s32 *)(s + 0x70) && p &&
               (p[-1] >= 0 || p == D_L07_0021C020[*(s32 *)(s + 0x70)])) {
            u8 *target = D_L07_001DF41C[0] + (((u16)*p & 0x7FFF) << 8);
            if (!target) break;
            if (func_L07_003A7178(target, arg0 + 0x10, value, arg0[0x21], ((s32 *)(s + 0x50))[index])) {
                *(u8 **)(s + 0x80) = target;
                break;
            }
            p++;
        }
        break;
    }
    case 2: {
        s16 *p = D_L07_0021C020[*(s32 *)(s + 0x78)];
        while ((*(s32 *)(s + 0x78) & 0xFF) != 0xFF &&
               D_001DF458_sda >= *(s32 *)(s + 0x78) && p &&
               (p[-1] >= 0 || p == D_L07_0021C020[*(s32 *)(s + 0x78)])) {
            u8 *target = D_L07_001DF41C[0] + (((u16)*p & 0x7FFF) << 8);
            if (!target) break;
            if (func_L07_003BA000(target, arg0 + 0x10, s[index + 8], value, arg0[0x21], ((s32 *)(s + 0x50))[index])) {
                *(u8 **)(s + 0x80) = target;
                break;
            }
            p++;
        }
        break;
    }
    case 3: {
        s16 *p = D_L07_0021C020[*(s32 *)(s + 0x74)];
        while ((*(s32 *)(s + 0x74) & 0xFF) != 0xFF &&
               D_001DF458_sda >= *(s32 *)(s + 0x74) && p &&
               (p[-1] >= 0 || p == D_L07_0021C020[*(s32 *)(s + 0x74)])) {
            u8 *target = D_L07_001DF41C[0] + (((u16)*p & 0x7FFF) << 8);
            if (!target) break;
            if (func_L07_003A6C90(target, arg0 + 0x10,
                ((s16 *)(s + 0x40))[index], ((s16 *)(s + 0x10))[index],
                ((s16 *)(s + 0x20))[index], ((s16 *)(s + 0x30))[index],
                value, arg0[0x21], ((s32 *)(s + 0x50))[index])) {
                *(u8 **)(s + 0x80) = target;
                break;
            }
            p++;
        }
        break;
    }
    case 0:
    default:
        break;
    }
    func_L01_004450F0(arg0, 2, -1);
}
