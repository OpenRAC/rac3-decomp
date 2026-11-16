#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern u8 D_001426E0[];
extern u8 D_00142CBE[];

/* localdecomp:start func_L07_003C1430 */
extern u8 D_001D5551[];

u8 func_L07_003C1430(s32 arg0) {
    u8 var_v0;

    var_v0 = 1;
    if (arg0 == 0) {
        var_v0 = D_001D5551[0];
    }
    return var_v0;
}
/* localdecomp:end func_L07_003C1430 */

/* localdecomp:start func_L07_003C1448 */
extern u8 D_001426E0[];
extern u8 D_00142CBE[];
extern u16 D_001A8070[];
extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_L07_003A2380(s32, s32, s32, s32);

void func_L07_003C1448(u8 *a0) {
    u8 *s2;
    u8 *s1;
    u8 s0;

    s0 = 0xFF;
    s2 = *(u8 **)(a0 + 0x68);
    if (D_00142CBE[0] == 0) {
        if (D_001A8070[0] == 0) {
            s0 = func_00382380(D_001A4C60, *(s32 *)(s2 + 0x14), 0);
            if (s0 != 0) {
                func_L01_0041A5B0(0xB8F, 0x32);
            }
        }
    }
    s1 = D_001426E0;
    if (s1[0x8F] != 0) {
        if ((s1[0xD9] ^ 1) & 1) {
            if (s0 == 0xFF) {
                s0 = func_00382380(D_001A4C60, *(s32 *)(s2 + 0x14), 0);
            }
            if (s0 != 0) {
                func_L07_003A2380(0x73, 0, 0, 0x64);
                s1[0xD9] |= 1;
            }
        }
    }
}
/* localdecomp:end func_L07_003C1448 */
