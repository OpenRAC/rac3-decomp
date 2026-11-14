#include "common.h"

/* NTSC-U counterpart of func_L40_004B98E8 (src/levels/shared/L40_004B98E8.c) */
/* localdecomp:start func_L39_005E4CD8 */
extern s32 D_L39_00243CE0;
extern s32 D_L39_00243CE4;
extern u8 D_L39_00243D48[];
extern u8 D_L39_00243D58[];
extern u8 D_001A5995[];
extern u8 D_001A5996[];
extern s32 func_L01_00513698(void);
extern s32 func_003B46F0(s32);
extern s32 func_L39_005E5A88(void *, s32, s32);
extern s32 func_0037DF98(s32);
extern s32 func_00120048(u8 *, u8 *, ...);

void func_L39_005E4CD8(void) {
    s32 mode = 0;

    switch (func_L01_00513698()) {
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
    if (D_L39_00243CE0 >= 0) {
        u8 *buf = (u8 *)func_L39_005E5A88((void *)func_003B46F0(mode), 0, D_L39_00243CE0);
        u8 *fmt = D_L39_00243D48;
        s32 a = func_0037DF98(0x142);
        s32 b = func_0037DF98(0x18E);
        s32 c;
        if (D_001A5995[0] != 0) {
            c = func_0037DF98(0x175);
        } else {
            c = func_0037DF98(0x176);
        }
        func_00120048(buf, fmt, a, b, c);
    }
    if (D_L39_00243CE4 >= 0) {
        u8 *buf = (u8 *)func_L39_005E5A88((void *)func_003B46F0(mode), 0, D_L39_00243CE4);
        u8 *fmt = D_L39_00243D58;
        s32 a = func_0037DF98(0x148);
        s32 c;
        if (D_001A5996[0] != 0) {
            c = func_0037DF98(0x175);
        } else {
            c = func_0037DF98(0x176);
        }
        func_00120048(buf, fmt, a, c);
    }
}
/* localdecomp:end func_L39_005E4CD8 */
