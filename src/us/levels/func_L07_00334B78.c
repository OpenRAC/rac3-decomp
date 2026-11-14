#include "common.h"

/* localdecomp:start func_L07_00334B78 */
extern s32 func_0037E1D8(s32);
extern s32 func_L07_003A0BC0(s32, u8 *, s32, s32);

void func_L07_00334B78(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 f;

    f = *(s32 *)(s + 0xE0) & 0xFFFF7FFF;
    *(s32 *)(s + 0xE0) = f;
    if ((f & 0x10000) != 0) {
        func_L07_003A0BC0(0x32, a0, 0, 0x78);
        *(s32 *)(s + 0xE0) &= 0xFFFEFFFF;
    } else {
        switch (func_0037E1D8(6)) {
        case 0:
            if ((*(s32 *)(s + 0xE0) & 0x1000) == 0) {
                func_L07_003A0BC0(0x33, a0, 0, 0x78);
                *(s32 *)(s + 0xE0) |= 0x1000;
            }
            break;
        case 1:
            switch (a1) {
            case 0x13:
            case 0x27:
            case 0x3F:
            case 0x97:
                if ((*(s32 *)(s + 0xE0) & 0x2000) == 0) {
                    func_L07_003A0BC0(0x34, a0, 0, 0x78);
                    *(s32 *)(s + 0xE0) |= 0x2000;
                }
                break;
            }
            break;
        case 2:
            if (s[0xB1] >= 3) {
                if ((*(s32 *)(s + 0xE0) & 0x4000) == 0) {
                    func_L07_003A0BC0(0x35, a0, 0, 0x78);
                    *(s32 *)(s + 0xE0) |= 0x4000;
                }
            }
            break;
        }
    }
}
/* localdecomp:end func_L07_00334B78 */
