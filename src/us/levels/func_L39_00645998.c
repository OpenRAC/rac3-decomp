#include "common.h"

/* localdecomp:start func_L39_00645998 */
typedef struct {
    u8 pad00[0x128];
    s32 f128;
    u8 pad12C[0x170 - 0x12C];
    s32 f170;
    u8 pad174[0x6AD - 0x174];
    u8 b6AD;
    u8 pad6AE[0x7B0 - 0x6AE];
    s32 w7B0[1];
} G_00645998;

typedef struct {
    u8 pad00[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x2558 - 0x1A15];
    s32 *p2558;
} P_00645998;

extern G_00645998 D_001A5E50;

s32 func_L39_00645998(P_00645998 *p) {
    s32 r = 0;
    s32 t;

    if (D_001A5E50.f170 != 0) {
        return 1;
    }
    if (p != 0) {
        r = 1;
        if (p->b1A14 == 0) {
            t = D_001A5E50.f128 - D_001A5E50.w7B0[((u8 *)&D_001A5E50)[*p->p2558 + 0x6AD]];
            r = t < 0x97;
        }
    }
    return r;
}
/* localdecomp:end func_L39_00645998 */
