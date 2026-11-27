#include "common.h"

/* localdecomp:start func_L02_004E2118 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x1B50];
    s32 x1B50;
    u8 pad1B54[0x25C4 - 0x1B54];
    s32 x25C4;
} H_004E2118;
extern H_004E2118 D_001A4BE0;
extern s32 func_L02_004D36C0(s32, s32);

void func_L02_004E2118(vu0_v4 *a0, vu0_v4 *a1, s32 a2) {
    vu0_v4 v = *a1;
    vu0_v4 *g = (vu0_v4 *)((u8 *)&D_001A4BE0 + 0x1B40);

    g[0] = *a0;
    g[2] = v;
    D_001A4BE0.x1B50 = a2;
    if ((u32)(D_001A4BE0.x25C4 - 0x66) >= 4) {
        func_L02_004D36C0(0x66, 2);
    }
}
/* localdecomp:end func_L02_004E2118 */
