#include "common.h"

/* NTSC-U counterpart of func_L17_003B3678 (src/levels/17_crash_site/L17_003B3678.c) */
/* localdecomp:start func_L17_003B1B98 */
typedef struct { s32 f0; s32 f4; } S_3678_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_3678_D *f68; u8 p6C[0x50]; u8 bBC; } S_3678_O;
extern u8 D_001A4C60[];
extern void func_L01_003B6498(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L17_003B1C98(void *);
void func_L17_003B1B98(S_3678_O *a0) {
    S_3678_D *d = a0->f68;
    switch (a0->b20) {
    case 0:
        func_L01_003B6498(a0);
        break;
    case 1:
        if (func_0037E0F0(D_001A4C60, d->f0, 0) == 0) return;
        if (d->f4 <= 0) {
            func_L17_003B1C98(a0);
        } else {
            func_L01_00441FB8(a0, 2, -1);
            a0->bBC = d->f4;
        }
        break;
    case 2:
        a0->bBC--;
        if (a0->bBC == 0) func_L17_003B1C98(a0);
        break;
    }
}
/* localdecomp:end func_L17_003B1B98 */
