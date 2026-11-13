#include "common.h"

/* localdecomp:start func_L40_004B98E8 */
extern s32 D_L40_00243B78;
extern s32 D_L40_00243B7C;
extern u8 D_L40_00243BE0[];
extern u8 D_L40_00243BF0[];
extern u8 D_001A5815[];
extern u8 D_001A5816[];
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern s32 func_L39_005E7FF8(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);

void func_L40_004B98E8(void) {
    s32 mode = 0;

    switch (func_L01_00517688()) {
    case 0:
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    }
    if (D_L40_00243B78 >= 0) {
        u8 *buf = (u8 *)func_L39_005E7FF8((void *)func_003B9BD0(mode), 0, D_L40_00243B78);
        u8 *fmt = D_L40_00243BE0;
        s32 a = func_00381FF0(0x142);
        s32 b = func_00381FF0(0x18E);
        s32 c;
        if (D_001A5815[0] != 0) {
            c = func_00381FF0(0x175);
        } else {
            c = func_00381FF0(0x176);
        }
        func_00120048(buf, fmt, a, b, c);
    }
    if (D_L40_00243B7C >= 0) {
        u8 *buf = (u8 *)func_L39_005E7FF8((void *)func_003B9BD0(mode), 0, D_L40_00243B7C);
        u8 *fmt = D_L40_00243BF0;
        s32 a = func_00381FF0(0x148);
        s32 c;
        if (D_001A5816[0] != 0) {
            c = func_00381FF0(0x175);
        } else {
            c = func_00381FF0(0x176);
        }
        func_00120048(buf, fmt, a, c);
    }
}
/* localdecomp:end func_L40_004B98E8 */
