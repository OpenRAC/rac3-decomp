#include "common.h"

/* declared by functions of L21_003A3BA0.c, which this file was cut from */
extern s32 func_00382468(s32 a0);

/* localdecomp:start func_L21_003A4500 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L21_003A3F30(u8 *a0);
extern void func_L21_003A41F8(u8 *a0, u8 *a1);
extern void func_L21_003A43E8(u8 *a0, u8 *a1);
extern s32 D_L21_001DE0E8[];
extern s32 D_L21_001E0FF0[];

void func_L21_003A4500(u8 *arg0) {
    u8 *m = *(u8 **)(arg0 + 0x68);
    s32 i;

    if (*(s32 *)(m + 0x58) == 0 && func_L01_00447490(arg0, -1, 0)) {
        func_L21_003A3F30(arg0);
        return;
    }
    switch (arg0[0x20]) {
    case 0:
        func_L21_003A4148(arg0, m);
        *(s32 *)(m + 0x50) = func_00382468(3);
        for (i = 0; i < 3; i++) {
            D_L21_001E0FF0[i] = D_L21_001DE0E8[func_00382468(4)];
        }
        break;
    case 1:
        func_L21_003A41F8(arg0, m);
        func_L21_003A43E8(arg0, m);
        break;
    }
}
/* localdecomp:end func_L21_003A4500 */
