/* Near miss: matches at level 32 by check.py (an if-chain over sparse values written as a `switch`), but the full level build rejects it: its .rodata jump table entry +0x4 is 0x3A0318 where retail has 0x3A0338 (table [0x3A0308, 0x3A0338, 0x3A0318, 0x3A0328, 0x3A0348, 0, 0, 0, ...]), i.e. the case-to-label mapping differs although the code is equal. check.py does not compare jump tables; only the full build does
 */
#include "common.h"

/* localdecomp:start func_L32_003A0228 */
extern void func_L32_003A05F0(u8 *);
extern void func_L32_003A06B8(u8 *);
extern void func_L32_003A09F0(u8 *);
extern void func_L32_003A0AF8(u8 *);
extern void func_L32_003A0BB8(u8 *);
extern void func_L32_003A0E20(u8 *);
extern void func_L32_003A11C8(u8 *);
extern void func_L32_003A1670(u8 *, s32);
extern void func_L32_003A20C8(u8 *);
extern void func_L32_003A21E0(u8 *);
extern void func_L32_003A22E0(u8 *);
extern void func_L32_003A23C8(u8 *);

void func_L32_003A0228(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    s32 state;

    switch (obj[0x20]) {
    case 0x42:
        func_L32_003A20C8(obj);
        break;
    case 1:
        func_L32_003A21E0(obj);
        break;
    case 0:
        func_L32_003A11C8(obj);
        if (obj[0x20] < 0xFD) {
            func_L32_003A1670(obj, 3);
        }
        break;
    case 2:
        func_L32_003A22E0(obj);
        break;
    case 3:
        func_L32_003A23C8(obj);
        break;
    }

    state = *(s32 *)(s + 0x21C);
    switch (state) {
    case 0:
        func_L32_003A05F0(obj);
        break;
    case 1:
        func_L32_003A06B8(obj);
        break;
    case 2:
        func_L32_003A09F0(obj);
        break;
    case 3:
        func_L32_003A0AF8(obj);
        break;
    case 4:
        func_L32_003A0BB8(obj);
        break;
    }
    func_L32_003A0E20(obj);
}
/* localdecomp:end func_L32_003A0228 */
