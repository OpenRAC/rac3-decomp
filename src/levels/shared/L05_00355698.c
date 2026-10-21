#include "common.h"

/* localdecomp:start func_L05_00355698 */
typedef struct {
    u8 pad0[0x10];
    f32 v10[4];
    u8 pad20[0x31 - 0x20];
    u8 b31;
    u8 pad32[0x6F - 0x32];
    u8 b6F;
} S_354660;

extern f32 D_L05_001E2700[];
extern f32 func_L01_0040E548(f32 *a0, f32 *a1);
extern void func_L01_004472C0(S_354660 *a0);

void func_L05_00355698(S_354660 *a0) {
    if (a0->b31 != 0) {
        if (func_L01_0040E548(D_L05_001E2700, a0->v10) < 576.0f) {
            func_L01_004472C0(a0);
            a0->b6F = 22;
        }
    }
}
/* localdecomp:end func_L05_00355698 */
