#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001D9FD0[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];
extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001D9FD0[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];
extern u8 D_001D5B78[];
extern s32 D_001A7430[];
extern s32 D_001D9FD0_003A0EC0[1];
extern s32 D_001D5B90_003A0EC0;
extern s32 D_001D5B94_003A0EC0;
extern s32 D_001D4CEC_003A0EC0;
extern s32 D_001D6DA4_003A0EC0;
extern s32 D_001D6D9C_003A0EC0;
extern s32 D_001D6DA0_003A0EC0;
extern s32 D_001D6DA8_003A0EC0;
/* localdecomp:start func_003A0EC0 */
/* declarations of 3A0EC0.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001D5B94_003A1148;
extern s32 D_001D5B90_003A1148;
extern s32 D_001D5B8C_003A0EC0;
extern s32 D_001D6D98_003A0EC0;
extern s32 D_001D6D9C_003A1148;
extern s32 D_001D6DA0_003A1148;
extern u8 *D_001D6DA8_003A1148;
extern f32 D_002259B0_003A0EC0[];
extern void func_003A8E10(void);
extern void func_00382BF0(s32, s32, s32, f32, f32, f32, f32);
extern void func_003877A0();
extern void func_003A8C70();
extern void func_003B35D0();
extern s32 D_001D6D98_003A0EC0;
extern s32 D_001D5B90_003A0EC0b[];

extern s32 D_001D5B90_003A0EC0b[];
extern s32 D_001D5B94_003A0EC0b[];
extern s32 D_001D4CEC_003A0EC0b[];
extern u8  D_001D5B78_003A0EC0[];
extern s32 D_001D9FD0_003A0EC0b[];
extern s32 D_001A7430_003A0EC0[];
extern s32 D_001D6DA4_003A0EC0b[];
extern s32 D_001D6D9C_003A0EC0b[];
extern s32 D_001D6DA0_003A0EC0b[];
extern s32 D_001D6DA8_003A0EC0b[];

extern s32 D_001D5B90_003A0EC0b[];
extern s32 D_001D5B94_003A0EC0b[];
extern s32 D_001D4CEC_003A0EC0b[];
extern u8  D_001D5B78_003A0EC0[];
extern s32 D_001D9FD0_003A0EC0b[];
extern s32 D_001A7430_003A0EC0[];
extern s32 D_001D6DA4_003A0EC0b[];
extern s32 D_001D6D9C_003A0EC0b[];
extern s32 D_001D6DA0_003A0EC0b[];
extern s32 D_001D6DA8_003A0EC0b[];

extern u8 D_001D5B78_003A0EC0[];
extern s32 D_001A7430_003A0EC0[];
extern s32 D_001D9FD0_003A0EC0_003A0EC0[1];
__asm__(".extern D_001D6DA4_003A0EC0_003A0EC0, 4");
__asm__(".extern D_001D6D9C_003A0EC0_003A0EC0, 4");
__asm__(".extern D_001D6DA0_003A0EC0_003A0EC0, 4");
__asm__(".extern D_001D6DA8_003A0EC0_003A0EC0, 4");
extern s32 D_001D5B90_003A0EC0_003A0EC0;
extern s32 D_001D5B94_003A0EC0_003A0EC0;
extern s32 D_001D4CEC_003A0EC0_003A0EC0;
extern s32 D_001D6DA4_003A0EC0_003A0EC0;
extern s32 D_001D6D9C_003A0EC0_003A0EC0;
extern s32 D_001D6DA0_003A0EC0_003A0EC0;
extern s32 D_001D6DA8_003A0EC0_003A0EC0;

s32 func_003A0EC0(s32 screenId, s32 mode, s32 arg2, s32 arg3, u8 *outPtr) {
    s32 result;
    s32 flag;

    if (outPtr != 0) {
        *outPtr = 0;
    }
    result = (D_001D5B90_003A0EC0_003A0EC0 == -2) ? 0 : -1;
    if (mode == 1) {
        result = (D_001D6DA4_003A0EC0_003A0EC0 < 8) ? result : -2;
    }
    do {
        flag = 0;
    } while (0);
    if (screenId >= 0) flag = D_001D5B78_003A0EC0[screenId];
    if (flag) {
        result = -3;
    }
    if (D_001A7430_003A0EC0[0] == 0) {
        if ((D_001D5B94_003A0EC0_003A0EC0 != 0) || ((D_001D4CEC_003A0EC0_003A0EC0 & 1) == 0)) {
            result = -1;
        }
    }
    if (result == 0) {
        D_001D5B90_003A0EC0_003A0EC0 = screenId;
        D_001D6D9C_003A0EC0_003A0EC0 = arg2;
        D_001D6DA0_003A0EC0_003A0EC0 = arg3;
        D_001D6DA8_003A0EC0_003A0EC0 = (s32)outPtr;
        if (mode == 1) {
            D_001D9FD0_003A0EC0_003A0EC0[D_001D6DA4_003A0EC0_003A0EC0++] = D_001D5B94_003A0EC0_003A0EC0;
        }
    }
    return result;
}
/* localdecomp:end func_003A0EC0 */

extern s32 D_001D5B90_003A0F98;
extern s32 D_001D5B94_003A0F98;
extern s32 D_001A7430_003A0F98[];
extern s32 D_001D9FD0_003A0F98[1];
extern s32 D_001D6DA4_003A0F98;
extern s32 D_001D6D9C_003A0F98;
extern s32 D_001D6DA0_003A0F98;
extern s32 D_001D6DA8_003A0F98;
/* localdecomp:start func_003A0F98 */
__asm__(".extern D_001D6DA4_003A0F98_003A0F98, 4");
__asm__(".extern D_001D6D9C_003A0F98_003A0F98, 4");
__asm__(".extern D_001D6DA0_003A0F98_003A0F98, 4");
__asm__(".extern D_001D6DA8_003A0F98_003A0F98, 4");
extern s32 D_001D5B90_003A0F98_003A0F98;
extern s32 D_001D5B94_003A0F98_003A0F98;
extern s32 D_001A7430_003A0F98_003A0F98[];
extern s32 D_001D9FD0_003A0F98_003A0F98[1];
extern s32 D_001D6DA4_003A0F98_003A0F98;
extern s32 D_001D6D9C_003A0F98_003A0F98;
extern s32 D_001D6DA0_003A0F98_003A0F98;
extern s32 D_001D6DA8_003A0F98_003A0F98;
s32 func_003A0F98(s32 screenId, s32 arg1) {
    s32 result;
    if (D_001D5B90_003A0F98_003A0F98 != -2) result = 1; else result = 0;
    if (D_001D6DA4_003A0F98_003A0F98 == 0) result = 1;
    if (D_001D5B94_003A0F98_003A0F98 != 4) {
        if (D_001A7430_003A0F98_003A0F98[0] == 0) result = -1;
    }
    if (result == 0) {
        s32 i = D_001D6DA4_003A0F98_003A0F98 - 1;
        D_001D6D9C_003A0F98_003A0F98 = screenId;
        D_001D6DA0_003A0F98_003A0F98 = arg1;
        D_001D6DA4_003A0F98_003A0F98 = i;
        D_001D5B90_003A0F98_003A0F98 = D_001D9FD0_003A0F98_003A0F98[i];
        D_001D6DA8_003A0F98_003A0F98 = 0;
    }
    return result;
}
/* localdecomp:end func_003A0F98 */

LINKER_REMNANT("asm/remnants", func_003A1020);

extern u32 *D_001DA050_003A1028;
extern u32 *D_001DA050_0039C02A;
extern s32 D_00227400_003A1028[];
extern s32 D_00225700_003A1028[];
extern u32 D_001D4CF8_003A1028;
extern u8 D_001D0560[];
extern void func_0038A3B8();
/* localdecomp:start func_003A1028 */
extern u32 *D_001DA050;
extern u32 *D_001DA050_003A1028;
__asm__(".extern D_001DA050_003A1028, 16");
extern s32 D_00227400[];
extern s32 D_00225700[];
extern u32 D_001D4CF8_003A1028;
__asm__(".extern D_001D4CF8_003A1028, 16");
extern u8 D_001D0560[];
extern void func_0038A3B8();
extern void func_0038A518();

void func_003A1028(u32 *a0) {
    D_001DA050_003A1028 = a0;
    a0[0] = 0x30000009;
    D_001DA050_003A1028[1] = (D_001D4CF8_003A1028 + 0xC0) & 0x0FFFFFFF;
    D_001DA050_003A1028[2] = 0;
    D_001DA050_003A1028[3] = 0x50000009;
    D_001DA050_003A1028[4] = 0x30000025;
    D_001DA050_003A1028[5] = (u32)D_001D0560;
    D_001DA050_003A1028[6] = 0;
    D_001DA050_003A1028[7] = 0x50000025;
    D_001DA050_003A1028 += 8;
    D_00225700[13] += 1;
    if (D_00227400[0] != 0) {
        func_0038A3B8();
        a0 = D_001DA050;
    } else {
        func_0038A518();
        a0 = D_001DA050_003A1028;
    }
    a0[0] = 0x70000000;
    D_001DA050_003A1028[1] = 0;
    D_001DA050_003A1028 += 4;
}
/* localdecomp:end func_003A1028 */
