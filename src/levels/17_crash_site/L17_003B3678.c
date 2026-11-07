#include "common.h"

/* localdecomp:start func_L17_003B3678 */
typedef struct { s32 f0; s32 f4; } S_3678_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_3678_D *f68; u8 p6C[0x50]; u8 bBC; } S_3678_O;
extern u8 D_001A4C60[];
extern void func_L01_003B7C98(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L17_003B3790(void *);
void func_L17_003B3678(S_3678_O *a0) {
    S_3678_D *d = a0->f68;
    switch (a0->b20) {
    case 0:
        func_L01_003B7C98(a0);
        break;
    case 1:
        if (func_00382380(D_001A4C60, d->f0, 0) == 0) return;
        if (d->f4 <= 0) {
            func_L17_003B3790(a0);
        } else {
            func_L01_004450F0(a0, 2, -1);
            a0->bBC = (d->f4 * 5 + 2) / 6;
        }
        break;
    case 2:
        a0->bBC--;
        if (a0->bBC == 0) func_L17_003B3790(a0);
        break;
    }
}
/* localdecomp:end func_L17_003B3678 */
