#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003AB218(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AB218 */
extern s32 D_001DA070;
extern f32 D_001DA074[];
extern f32 D_001DA078_003AB218;
void func_003AB218(s32 on) {
    f32 f;
    D_001DA070 = on;
    f = 1.076923f;
    if (on == 0) {
        f = 1.0f;
    }
    D_001DA074[0] = f;
    f = 0.9f;
    if (on == 0) {
        f = 1.0f;
    }
    D_001DA078_003AB218 = f;
}
/* localdecomp:end func_003AB218 */
