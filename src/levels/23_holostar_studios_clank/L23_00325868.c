#include "common.h"

typedef struct {
    u8 pad0[128];
    u8 f128[9700 - 128];
    u8 f9700;
} S_1A4BE0_00325868;

/* localdecomp:start func_L23_00325868 */
extern S_1A4BE0_00325868 D_001A4BE0;
extern f32 func_0038CF00(void *, void *);
extern void func_L23_004CF590(s32, s32, void *);

void func_L23_00325868(u8 *a0) {
    if (D_001A4BE0.f9700 == 0) {
        if (func_0038CF00(D_001A4BE0.f128, a0 + 16) < 4.0f) {
            func_L23_004CF590(2, 90, a0);
        }
    }
}
/* localdecomp:end func_L23_00325868 */
