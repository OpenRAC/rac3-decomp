#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern f32 func_003AF658(f32, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AF658 */
extern u8 D_001D8798[];
extern u8 D_001D87B0[];
extern void func_00116F98(void *, s32, void *);
f32 func_003AF658(f32 t, f32 p0, f32 m0, f32 m1, f32 p1) {
    f32 t2, t3;
    if (!(t >= 0.0f && t <= 1.0f)) {
        func_00116F98(D_001D8798, 0x24, D_001D87B0);
    }
    t2 = t * t;
    t3 = t2 * t;
    p0 *= 1.0f + (2.0f * t3 - 3.0f * t2);
    m0 *= t3 - 2.0f * t2 + t;
    m1 *= t3 - t2;
    p1 *= -(2.0f * t3) + 3.0f * t2;
    return p0 + m0 + m1 + p1;
}
/* localdecomp:end func_003AF658 */
