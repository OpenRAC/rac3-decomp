#include "common.h"

/* localdecomp:start func_L01_00454370 */
extern s32 D_L01_001D673C;
extern void func_L01_00449088(void *a0, void *a1, s32 a2);
extern void func_L01_0044A030(void *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 s0, f32 f12);
extern void func_L01_00449BA8(void *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1);
extern void func_L01_004495F0(void *a0, void *a1, s32 a2);
extern s32 func_L01_00454728(void *a0, u8 *a1);
extern s32 func_L01_00455550(void *a0, u8 *a1);

s32 func_L01_00454370(void *a0, u8 *a1) {
    s32 ret = 0;
    if (a1[24] == 1 && a1[25] != 0) {
        func_L01_00449088(a0, a1 + 128, a1[25]);
    }
    if (a1[24] == 2 && a1[25] != 0) {
        func_L01_0044A030(a0, a1 + 128, a1[25], 0x4F804020, 10, 16, 94, 0, 0, 1.2f);
    }
    if (a1[24] == 3 && a1[25] != 0) {
        func_L01_00449BA8(a0, a1 + 128, a1[25], 0x4F804020, 2, 3);
    }
    if (a1[24] == 4 && a1[25] != 0) {
        func_L01_004495F0(a0, a1 + 128, a1[25]);
    }
    switch (a1[26]) {
    case 0:
    case 1:
    case 2:
        if (D_L01_001D673C == 0) {
            ret = func_L01_00454728(a0, a1);
        } else {
            ret = func_L01_00455550(a0, a1);
        }
        break;
    }
    if (ret & 2) {
        a1[24] = 0;
    }
    return ret;
}
/* localdecomp:end func_L01_00454370 */
