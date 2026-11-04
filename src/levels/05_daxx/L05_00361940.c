#include "common.h"

/* localdecomp:start func_L05_00361940 */
extern void func_L01_004450F0(s32, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_0044F450(void *, void *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L05_00361940(void *arg0) {
    u8 *q;
    u8 *b;
    s32 n;

    q = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        func_L01_0044ED88(arg0, q, 4, -1, -1, *(s32 *)(q + 0x140), 7, 0);
        n = 3;
        b = q + 0x13D;
        do {
            *b = 1;
            n -= 1;
            b -= 0x50;
        } while (n >= 0);
        func_L01_004450F0((s32) arg0, 1, -1);
    }
    if (func_L01_00456250(arg0)) {
        func_L01_0044F450(arg0, q);
    }
}
/* localdecomp:end func_L05_00361940 */
