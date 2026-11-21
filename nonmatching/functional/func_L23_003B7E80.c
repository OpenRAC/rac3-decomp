/* functional: high. Same ops; only register allocation differs from retail. */
#include "vu0.h"
extern Path *D_L23_0021D380[];
extern f32 D_L23_002A3B30[];
extern s32 D_L23_001DE510;
extern f32 D_L23_001E1350;
extern f32 func_0038CEA8(void *);

void func_L23_003B7E80(s32 idx)
{
    Path *path;
    V4 prev;
    V4 cur;
    V4 diff;
    s32 i;

    if (idx != D_L23_001DE510) {
        D_L23_001DE510 = idx;
        D_L23_001E1350 = 0.0f;
        path = D_L23_0021D380[idx];
        prev = path->points[0];
        for (i = 1; i < path->count; i++) {
            cur = path->points[i];
            vec_sub_ab(&diff, &cur, &prev);
            D_L23_002A3B30[i - 1] = func_0038CEA8(&diff);
            prev = cur;
            D_L23_001E1350 = D_L23_001E1350 + D_L23_002A3B30[i - 1];
        }
    }
}
