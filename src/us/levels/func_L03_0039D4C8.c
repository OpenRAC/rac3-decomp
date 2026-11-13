#include "common.h"

/* NTSC-U counterpart of func_L03_0039ECA0 (src/levels/03_starship_phoenix/L03_0039E470.c) */
void func_L03_0039D4C8(void *, s32);
void func_L03_0039D4C8(void *, s32);

/* localdecomp:start func_L03_0039D4C8 */
void func_003BE4F0(void *, s32, s32, s32);
void func_L03_0032CFF8(void *);
void func_L01_00441FB8(void *, s32, s32);

void func_L03_0039D4C8(void *arg0, s32 arg1) {
    u8 *p = arg0;
    f32 *r;
    f32 *r2;
    u8 *q = *(u8 **)(p + 0x68);
    switch (arg1) {
    case 1:
    case 2:
        if (p[0x43] != 4) {
            func_003BE4F0(arg0, 4, 0, 0);
            break;
        }
        break;
    case 3:
        *(u16 *)(p + 0x34) |= 0x5000;
        break;
    case 4:
        break;
    case 5:
        if (p[0x43] != 0) {
            func_003BE4F0(arg0, 0, 0, 3);
            break;
        }
        break;
    case 6:
        r = (f32 *)(q + 0x150);
        r[8] = 0.00083333335f;
        r[10] = 0.050000004f;
        r[9] = 0.00083333335f;
        q[0x310] = 0;
        q[0x309] = 0;
        func_L03_0032CFF8(arg0);
        if (p[0x43] != 1) {
            func_003BE4F0(arg0, 1, 0, 3);
            break;
        }
        break;
    case 7:
        if (p[0x43] != 2) {
            func_003BE4F0(arg0, 2, 0, 3);
            break;
        }
        break;
    case 8:
        r2 = (f32 *)(q + 0x150);
        r2[8] = 0.00055555557f;
        r2[10] = 0.033333335f;
        r2[9] = 0.00055555557f;
        if (p[0x43] != 0) {
            func_003BE4F0(arg0, 0, 0, 4);
        }
        break;
    }
    func_L01_00441FB8(arg0, arg1, -1);
}
/* localdecomp:end func_L03_0039D4C8 */
