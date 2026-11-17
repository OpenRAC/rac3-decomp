/* func_L32_003A0228: 64 diff with the file's flags. Switch on state (0..4, jump table jtbl_002BF730) matches in shape; the type-byte if-chain is laid out differently (retail tests t==2 first, then t<3 with t==0/t==1 bodies out of line, t==3 and t==0x42 after). Tried: plain nested ifs with obj[0x20] re-read (a), a cached t as u8 (b), as s32 (c, slti in retail). */
#include "common.h"
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
    s32 t = obj[0x20];
    s32 state;

    if (t != 2) {
        if (t < 3) {
            if (t == 0) {
                func_L32_003A11C8(obj);
                if (obj[0x20] < 0xFD) {
                    func_L32_003A1670(obj, 3);
                }
            } else if (t == 1) {
                func_L32_003A21E0(obj);
            }
        } else {
            if (t == 3) {
                func_L32_003A23C8(obj);
            } else if (t == 0x42) {
                func_L32_003A20C8(obj);
            }
        }
    } else {
        func_L32_003A22E0(obj);
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
