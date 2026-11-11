#include "common.h"

/* localdecomp:start func_L19_0035C9C8 */
extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_003F2A50(s32, s32);
extern void func_L01_003F2AF8(s32, s32);
extern void func_L01_003094A0(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L19_0035C9C8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 0:
        *(s32 *)(p + 0x28) = 0;
        obj[0x31] = 0;
        *(s32 *)(obj + 0x98) = 0;
        obj[0x30] = 0xFF;
        *(u16 *)(obj + 0x34) |= 1;
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (func_00382380(D_001A4C60, *(s32 *)p, 0) != 0) {
            if (*(s32 *)(p + 0x28) == 0) {
                s32 t = func_L01_003F2A50(0, 5);

                *(s32 *)(p + 0x28) = 1;
                *(s32 *)(p + 0x2C) = t;
                func_L01_003094A0(obj);
                break;
            }
        } else if (*(s32 *)(p + 0x28) == 0) {
            break;
        }
        if (func_00382380(D_001A4C60, *(s32 *)p, 0) == 0) {
            func_L01_003F2AF8(0, *(s32 *)(p + 0x2C));
            *(s32 *)(p + 0x28) = 0;
        }
        break;
    }
}
/* localdecomp:end func_L19_0035C9C8 */
