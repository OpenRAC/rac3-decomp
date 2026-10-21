#include "common.h"

/* localdecomp:start func_L19_0032F1E8 */
typedef struct {
    u8 pad0[128];
    u8 f128[9700 - 128];
    u8 f9700;
} S_001A4BE0;
extern S_001A4BE0 D_001A4BE0;
extern f32 func_0038CF00(void *, void *);
extern void func_L01_004ED3F8(s32, s32, void *);
void func_L19_0032F1E8(u8 *a0) {
    if (D_001A4BE0.f9700 == 0) {
        if (func_0038CF00(D_001A4BE0.f128, a0 + 16) < 1.7f) {
            func_L01_004ED3F8(1, 63, a0);
        }
    }
}
/* localdecomp:end func_L19_0032F1E8 */
