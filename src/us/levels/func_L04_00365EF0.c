#include "common.h"

/* NTSC-U counterpart of func_L04_00367068 (src/levels/04_marcadia/L04_00366800.c): 8 -> 10 */
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L04_00365EF0 */
extern void func_L04_00366158(void *);
extern void func_L04_00365FD8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0038CAD0(void *);

void func_L04_00365EF0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        *(s32 *)p = 10;
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00444358(a0, -1, 0) != 0) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        func_L04_00366158(a0);
        func_L01_00441FB8(a0, 3, -1);
        break;
    case 3:
        if (func_0038CAD0(p) != 0) {
            func_L04_00365FD8(a0);
        }
        break;
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
}
/* localdecomp:end func_L04_00365EF0 */
