#include "common.h"

/* localdecomp:start func_L13_003B1218 */
extern u8 D_L13_001E2140[];
extern f32 func_L01_0040E548(void *a, void *b);
extern void func_L01_004472C0(void *a);

void func_L13_003B1218(u8 *a0)
{
    if (a0[49] != 0) {
        if (func_L01_0040E548(D_L13_001E2140, a0 + 16) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[111] = 30;
        }
    }
}
/* localdecomp:end func_L13_003B1218 */
