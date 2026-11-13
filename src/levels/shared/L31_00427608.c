#include "common.h"

/* localdecomp:start func_L31_00427608 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
} S_00427608;

extern S_00427608 D_001A4BE0;
extern f32 func_L31_00424440(u8 *, f32 *, s32);

s32 func_L31_00427608(u8 *a0, f32 r, f32 h) {
    if (fabs_asm(D_001A4BE0.pos[0] - *(f32 *)(a0 + 0x10)) < r
        && func_L31_00424440(a0, D_001A4BE0.pos, 0) < 1.5707964f
        && fabs_asm(D_001A4BE0.pos[2] - *(f32 *)(a0 + 0x18)) < h) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L31_00427608 */

LINKER_REMNANT("asm/levels", func_L31_004276B0);
