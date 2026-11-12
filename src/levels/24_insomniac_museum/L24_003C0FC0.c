#include "common.h"

/* localdecomp:start func_L24_003C0FC0 */
extern void func_L01_00439880(void *, s32 *, s32 *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L24_003C0FC0(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    s32 v[2];
    s32 i;
    if (a0[0x20] == 0) {
        func_L01_00439880(a0, &v[0], &v[1]);
        *(u16 *)(a0 + 0x7C) |= 1 << func_00382468(3);
        if (p[0] != 0) {
            *(u16 *)(a0 + 0x7C) |= 1 << (v[1] - 2);
        } else if (p[1] != 0) {
            *(u16 *)(a0 + 0x7C) |= 1 << (v[1] - 1);
        } else {
            *(u16 *)(a0 + 0x7C) |= 1 << func_00382498(3, 4);
            for (i = 5; i < v[1] - 2; i++) {
                if (func_00382468(2) != 0) {
                    *(u16 *)(a0 + 0x7C) |= 1 << i;
                }
            }
        }
        *(u16 *)(a0 + 0x34) |= 2;
        func_L01_004450F0(a0, 1, -1);
    }
}
/* localdecomp:end func_L24_003C0FC0 */
