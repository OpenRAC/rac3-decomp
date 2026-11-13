#include "common.h"

/* NTSC-U counterpart of func_L34_00351B58 (src/levels/34_vidcomic_3/L34_003515A0.c): 0.0288 -> 0.02; 0.432 -> 0.3 */
/* localdecomp:start func_L34_00350E38 */
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_003A4F28(s32);
extern void func_L34_00351190(void *);
extern void func_003C2880(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern u8 D_001A30B0[];

void func_L34_00350E38(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    s32 idx;

    if (func_L01_00444358(a0, 0x10000, 0) != 0) {
        idx = *(s32 *)(s1 + 0x18C);
        if (idx != -1) {
            u8 *e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(s1 + 0x18C) = -1;
        func_L34_00351190(a0);
        func_003C2880(a0);
    } else {
        func_L01_0044B5C8(a0, s1, 3, 0.0199999996f, 0.300000012f);
    }
}
/* localdecomp:end func_L34_00350E38 */
