#include "common.h"

/* localdecomp:start func_L32_003A0228 */
extern void func_L32_003A05F0_003A0228(u8 *);
extern void func_L32_003A06B8_003A0228(u8 *);
extern void func_L32_003A09F0_003A0228(u8 *);
extern void func_L32_003A0AF8_003A0228(u8 *);
extern void func_L32_003A0BB8_003A0228(u8 *);
extern void func_L32_003A0E20_003A0228(u8 *);
extern void func_L32_003A11C8_003A0228(u8 *);
extern void func_L32_003A1670_003A0228(u8 *, s32);
extern void func_L32_003A20C8_003A0228(u8 *);
extern void func_L32_003A21E0_003A0228(u8 *);
extern void func_L32_003A22E0_003A0228(u8 *);
extern void func_L32_003A23C8_003A0228(u8 *);

void func_L32_003A0228(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    s32 state;

    switch (obj[0x20]) {
    case 0x42:
        func_L32_003A20C8_003A0228(obj);
        break;
    case 1:
        func_L32_003A21E0_003A0228(obj);
        break;
    case 0:
        func_L32_003A11C8_003A0228(obj);
        if (obj[0x20] < 0xFD) {
            func_L32_003A1670_003A0228(obj, 3);
        }
        break;
    case 2:
        func_L32_003A22E0_003A0228(obj);
        break;
    case 3:
        func_L32_003A23C8_003A0228(obj);
        break;
    }

    state = *(s32 *)(s + 0x21C);
    switch (state) {
    case 0:
        func_L32_003A05F0_003A0228(obj);
        break;
    case 2:
        func_L32_003A06B8_003A0228(obj);
        break;
    case 3:
        func_L32_003A09F0_003A0228(obj);
        break;
    case 1:
        func_L32_003A0AF8_003A0228(obj);
        break;
    case 4:
        func_L32_003A0BB8_003A0228(obj);
        break;
    }
    func_L32_003A0E20_003A0228(obj);
}
/* localdecomp:end func_L32_003A0228 */
