#include "common.h"

/* NTSC-U counterpart of func_L39_005E3618 (src/levels/shared/L39_005E31D8.c): the game-mode struct D_001A4560 sits at another address in the NTSC-U core */
/* localdecomp:start func_L39_005E10A8 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_005E10A8;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_005E10A8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad0c[4]; s32 f10; } S_005E10A8;
extern s32 D_L39_00240578;
extern F_005E10A8 D_L39_0024057C;
extern s32 D_001D8294_sda;
extern u8 D_L39_00242B2C;
extern u8 D_L39_00242B2D;
extern u8 D_L39_0024BF70;
extern P_005E10A8 *D_L39_002412E4;
extern S_005E10A8 D_001A4560;
extern void func_L39_005BD880(s32, s32);
extern void func_L39_005A40D8(s32, s32);
extern void func_L01_003EFA70_005E10A8(void);
extern void func_L39_005F9608(void);
__asm__(".extern D_001D8294_sda, 4");
void func_L39_005E10A8(void) {
    u32 p;
    switch (D_L39_00240578) {
    case 3:
        if (D_L39_002412E4->f1A4 & 0x40) {
            D_L39_0024057C.b0 = 0;
            D_001D8294_sda++;
        }
        break;
    case 8:
        p = D_L39_002412E4->f1A4;
        if (p & 0x20) {
            D_L39_0024057C.b3 = 1;
        } else if (p & 0x10) {
            if (D_L39_00242B2D) { func_L39_005F9608(); break; }
            D_L39_0024057C.b5 = 1;
            D_L39_0024057C.b1 = 0;
            D_L39_0024057C.b2 = 0;
            if (D_L39_00242B2C == 0) func_L39_005BD880(6, 0);
        }
        break;
    case 15:
        p = D_L39_002412E4->f1A4;
        if (p & 0x20) {
            func_L39_005A40D8(0, 0);
        } else if (p & 0x10) {
            if (D_L39_00242B2D) { func_L39_005F9608(); break; }
            D_L39_0024057C.b5 = 1;
            D_L39_0024057C.b1 = 0;
            D_L39_0024057C.b2 = 0;
            if (D_L39_00242B2C == 0) D_001D8294_sda++;
        }
        break;
    case 22:
        if (D_L39_002412E4->f1A4 & 0x40) {
            D_L39_0024057C.b6 = 0;
            D_L39_0024057C.b10 = 0;
            D_L39_0024057C.b1 = 0;
            D_L39_0024057C.b2 = 0;
            if (D_L39_00242B2C == 0) D_001D8294_sda++; else D_001D8294_sda++;
        }
        break;
    case 19: case 20: case 24: {
        S_005E10A8 *e = &D_001A4560;
        if (e->f8 != 2) { func_L39_005F9608(); break; }
        if (e->f10 == 0) D_L39_00240578 = 11;
        else if (e->f10 == -1) { e->f10 = 0; D_L39_00240578 = 11; }
        else if (e->f10 == -2) D_L39_00240578 = 7;
        else D_L39_00240578 = 14;
        D_001D8294_sda++;
        break;
    }
    case 14:
        if (D_L39_0024BF70 == 0) break;
    case 4: case 5: case 7:
        if (D_L39_002412E4->f1A4 & 0x40) {
            D_L39_0024057C.b1 = 0;
            D_L39_0024057C.b2 = 0;
            D_001D8294_sda++;
        }
        break;
    case 21:
        if (D_L39_00242B2C != 0 && D_L39_0024BF70 == 0) {
            if (D_L39_002412E4->f1A4 & 0x40) {
                func_L01_003EFA70_005E10A8();
                D_L39_0024057C.b1 = 0;
                D_L39_0024057C.b2 = 0;
                D_L39_0024057C.b5 = 1;
                func_L39_005F9608();
            }
        } else if (D_L39_00242B2D) {
            if (D_L39_002412E4->f1A4 & 0x40) func_L39_005F9608();
        } else if (D_L39_002412E4->f1A4 & 0x40) {
            D_L39_0024057C.b1 = 0;
            D_L39_0024057C.b2 = 0;
            D_001D8294_sda++;
        }
        break;
    case 26: case 27:
        p = D_L39_002412E4->f1A4;
        if (p & 0x40) {
            func_L01_003EFA70_005E10A8();
            D_L39_0024057C.b1 = 0;
            D_L39_0024057C.b2 = 0;
            D_L39_0024057C.b5 = 1;
            func_L39_005F9608();
        } else if (p & 0x10) {
            D_L39_0024057C.b5 = 1;
            D_001D8294_sda++;
        }
        break;
    case 6:
        if (D_L39_00242B2C != 0) {
            if (D_L39_0024BF70 == 0) {
                if (D_L39_002412E4->f1A4 & 0x40) {
                    func_L01_003EFA70_005E10A8();
                    D_L39_0024057C.b1 = 0;
                    D_L39_0024057C.b2 = 0;
                    func_L39_005F9608();
                }
                if (D_L39_002412E4->f1A4 & 0x10) {
                    D_L39_0024057C.b5 = 1;
                    D_L39_0024057C.b1 = 0;
                    D_L39_0024057C.b2 = 0;
                    D_001D8294_sda++;
                }
            } else if (D_L39_002412E4->f1A4 & 0x40) {
                D_L39_0024057C.b5 = 1;
                D_L39_0024057C.b1 = 0;
                D_L39_0024057C.b2 = 0;
                D_001D8294_sda++;
            }
        } else if (D_L39_00242B2D) {
            if (D_L39_002412E4->f1A4 & 0x20) func_L39_005F9608();
        } else if (D_L39_002412E4->f1A4 & 0x40) {
            D_L39_0024057C.b5 = 1;
            D_L39_0024057C.b1 = 0;
            D_L39_0024057C.b2 = 0;
            D_001D8294_sda++;
        }
        break;
    case 1: case 11: case 18:
        if (!D_L39_0024057C.b1 && !D_L39_0024057C.b2) D_001D8294_sda++;
        break;
    case 2: case 9: case 10: case 12: case 13: case 16: case 17: case 23: case 25:
    case 28: case 29: case 30: case 31: case 32:
        break;
    }
}
/* localdecomp:end func_L39_005E10A8 */
