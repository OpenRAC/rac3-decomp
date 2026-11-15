/* func_L28_00394890: 13 diff with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division). Branch layout differs: the byte-test tail (q[0x20] == 0xFE / 0xFD, else return 0) and the store block of the -1 are laid out in another order than retail's, and the frame and addresses of the three loads match. Tried: sel!=0 as the first arm, separate if/else per load (b, c, d), else-if form for the byte test (e). */
#include "common.h"
extern u8 *D_L28_001DEC9C;
extern s32 func_L01_00456500(u8 *, s32);
extern s32 func_L01_00456250(u8 *);

s32 func_L28_00394890(u8 *obj, s32 sel) {
    u8 *p = *(u8 **)(obj + 0x68);
    s32 a;
    s32 b;
    s32 c;
    u8 *q;

    if (sel != 0) {
        a = *(s32 *)(p + 0x30C);
    } else {
        a = *(s32 *)(p + 0x2F4);
    }
    if (sel != 0) {
        b = *(s32 *)(p + 0x314);
    } else {
        b = *(s32 *)(p + 0x2FC);
    }
    if (sel != 0) {
        c = *(s32 *)(p + 0x31C);
    } else {
        c = *(s32 *)(p + 0x304);
    }
    if (a != -1) {
        if (func_L01_00456500(p + 0x220, a) != 0) {
            return 1;
        }
    }
    if (b != -1) {
        if (func_L01_00456250(D_L28_001DEC9C + (b << 8)) != 0) {
            return 1;
        }
    }
    if (c == -1) {
        return 0;
    }
    q = D_L28_001DEC9C + (c << 8);
    if (q != 0) {
        if (q[0x20] != 0xFE) {
            if (q[0x20] != 0xFD) {
                return 0;
            }
        }
    }
    if (sel != 0) {
        *(s32 *)(p + 0x31C) = -1;
    } else {
        *(s32 *)(p + 0x304) = -1;
    }
    return 1;
}
