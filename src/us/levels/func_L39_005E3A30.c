#include "common.h"

/* NTSC-U counterpart of func_L39_005E5FA0 (src/levels/shared/L39_005E5FA0.c) */
/* localdecomp:start func_L39_005E3A30 */
extern s32 D_001A5990[];
extern int func_L39_005F0E48(s32, s32, s32);
extern void func_00193D50(s32);

void func_L39_005E3A30(s32 a0) {
    if (a0 & 0xA040) {
        s32 *p;
        func_L39_005F0E48(4, 0, 0);
        p = D_001A5990;
        p[2] = p[2] == 0;
        func_00193D50(p[2] == 0);
    }
}
/* localdecomp:end func_L39_005E3A30 */
