#include "common.h"

/* localdecomp:start func_L40_00489900 */
extern s16 **D_L40_002429E4[];
extern u8 *D_L40_00248EFC[];
extern f32 func_0038CF00(void *, void *);

s32 func_L40_00489900(u8 *obj, s32 idx) {
    s32 best_id = -1;
    f32 best;
    s16 *p;
    u8 *e;
    f32 d;

    if (idx != -1) {
        best = 9999.0f;
        p = D_L40_002429E4[0][idx];
        while (p != 0) {
            if (p[-1] < 0 && p != D_L40_002429E4[0][idx]) {
                break;
            }
            e = D_L40_00248EFC[0] + ((*(u16 *)p & 0x7FFF) << 6);
            if (e == 0) {
                break;
            }
            d = func_0038CF00(e + 0x30, obj + 0x10);
            if (d < best) {
                best = d;
                best_id = *(u16 *)p & 0x7FFF;
            }
            p++;
        }
    }
    return best_id;
}
/* localdecomp:end func_L40_00489900 */
