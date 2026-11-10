#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { s32 count; s32 pad[3]; V4 points[1]; } Path;

INCLUDE_ASM("asm/levels", func_L23_003B7530);

INCLUDE_ASM("asm/levels", func_L23_003B7730);

INCLUDE_ASM("asm/levels", func_L23_003B7930);

INCLUDE_ASM("asm/levels", func_L23_003B7E80);

/* localdecomp:start func_L23_003B7F60 */
extern Path *D_L23_0021D380[];
extern f32 D_L23_002A3B30[];
extern void func_003C4098(void *, void *, void *, f32);

void func_L23_003B7F60(void *out, s32 idx, f32 dist)
{
    Path *path = D_L23_0021D380[idx];
    V4 a = path->points[0];
    V4 b;
    s32 i;

    for (i = 1; i < path->count; i++) {
        b = path->points[i];
        if (dist < D_L23_002A3B30[i - 1]) {
            func_003C4098(out, &a, &b, dist / D_L23_002A3B30[i - 1]);
            return;
        }
        a = b;
        dist -= D_L23_002A3B30[i - 1];
    }
}
/* localdecomp:end func_L23_003B7F60 */

INCLUDE_ASM("asm/levels", func_L23_003B8008);
