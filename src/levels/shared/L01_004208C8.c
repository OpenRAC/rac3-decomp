#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004208C8);

/* localdecomp:start func_L01_004208E0 */
typedef struct {
    s16 h0;
    s16 h2;
} E_41E1B0;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
} T_41E1B0;

extern E_41E1B0 *D_L01_001DFD20;
extern T_41E1B0 *D_L01_001DFD24;
extern s32 D_L01_001E1068;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_L01_001DFD0C;
extern long func_00396A38(int);

void func_L01_004208E0(int idx, int x, int y, int w, int h, int a, unsigned int col) {
    T_41E1B0 *t = &D_L01_001DFD24[D_L01_001DFD20[idx].h2];
    int tw = 1 << t->b6;
    int th = 1 << t->b7;
    u8 *p;

    *(s32 *)(D_L01_001E1068 + 0) = 0x10000005;
    *(s32 *)(D_L01_001E1068 + 4) = 0;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000005;
    p = (u8 *)D_L01_001E1068 + 0x10;
    D_L01_001E1068 = (s32)p;
    *(long *)(p + 0) = 0x7400000000008001UL;
    *(long *)(p + 8) = 0x5353106;
    *(long *)(p + 0x10) = func_00396A38(idx);
    *(long *)(p + 0x18) = 342;
    *(long *)(p + 0x20) = (long)(u8)col | (long)(col & 0xFF00) | ((long)(u8)(col >> 16) << 16) | ((long)a << 24);
    *(long *)(p + 0x28) = 0;
    *(long *)(p + 0x30) = (x + D_001D4BD0 - 8) | ((long)(y + D_001D4BD4 - 8) << 16) | ((long)D_L01_001DFD0C << 32);
    *(long *)(p + 0x38) = (th << 20) + (tw << 4);
    *(long *)(p + 0x40) = (x + w + D_001D4BD0 - 8) | ((long)(y + h + D_001D4BD4 - 8) << 16) | ((long)D_L01_001DFD0C << 32);
    *(long *)(p + 0x48) = 0;
    D_L01_001E1068 = D_L01_001E1068 + 0x50;
}
/* localdecomp:end func_L01_004208E0 */

LINKER_REMNANT("asm/levels", func_L01_00420AE0);
