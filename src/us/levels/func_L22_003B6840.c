#include "common.h"

/* localdecomp:start func_L22_003B6840 */
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_0037DF98(s32);
extern void func_L22_003B6220(s32);

void func_L22_003B6840(u8 *a0) {
    u8 *p;
    s32 i;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0x14 || a0[0x20] == 0x12 || a0[0x20] == 0x13) {
        func_L01_00512AB0(0x120094, 1, 0);
        func_L22_003B6220(func_0037DF98(0x15F3));
    } else if (a0[0x20] == 0x15) {
        func_L01_00512AB0(0x12008E, 1, 0);
        func_L01_00512AB0(0x12008D, 1, 0);
        for (i = 0; i < 0x10; i++) {
            func_L01_00512AB0(0x120044 + i, 1, 0);
            func_L01_00512AB0(0x120055 + i, 1, 0);
            func_L01_00512AB0(0x120066 + i, 1, 0);
            func_L01_00512AB0(0x120077 + i, 1, 0);
            func_L01_00512AB0(0x120000 + i, 1, 0);
            func_L01_00512AB0(0x120011 + i, 1, 0);
            func_L01_00512AB0(0x120022 + i, 1, 0);
            func_L01_00512AB0(0x120033 + i, 1, 0);
        }
        func_L01_00512AB0(0x120094, 1, 1);
    } else if (a0[0x20] == 0x17 || a0[0x20] == 0x1A) {
        func_L01_00512AB0(0x12008E, 1, 1);
        func_L01_00512AB0(0x12008D, 1, 0);
        func_L22_003B6220(func_0037DF98(*(s32 *)(p + 0x4AC)));
    } else if (a0[0x20] == 0x16) {
        func_L01_00512AB0(0x12008E, 1, 0);
        func_L01_00512AB0(0x12008D, 1, 1);
        if (*(u16 *)(a0 + 0x96) >= 0x1F) {
            func_L01_00512AB0(0x120094, 1, 0);
        }
        func_L22_003B6220(func_0037DF98(*(s32 *)(p + 0x4AC)));
    } else if (a0[0x20] == 0x18 || a0[0x20] == 0x19) {
        func_L01_00512AB0(0x120094, 1, 0);
        func_L22_003B6220(func_0037DF98(*(s32 *)(p + 0x4AC)));
    }
}
/* localdecomp:end func_L22_003B6840 */
