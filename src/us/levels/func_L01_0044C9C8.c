#include "common.h"

/* NTSC-U counterpart of func_L01_0044FC48 (src/levels/shared/L01_0044FC48.c): 150 -> 180 */
/* localdecomp:start func_L01_0044C9C8 */
typedef struct {
    s32 v[38];
} T_0044FC48;

extern T_0044FC48 D_L01_002BC290;
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);

void func_L01_0044C9C8(s32 i, u8 flag) {
    T_0044FC48 t = D_L01_002BC290;

    if (flag) {
        func_L01_0044ECE0(t.v[i], -1, 0);
    } else if (t.v[i] != 0) {
        func_L01_0044F2E8(0, 15, t.v[i], 180, 0, 0, 0);
    }
}
/* localdecomp:end func_L01_0044C9C8 */
