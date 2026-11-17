#include "common.h"

/* localdecomp:start func_L39_005F1130 */
typedef struct {
    u8 pad0[8];
    s32 f8;
    s32 fC;
    u8 pad10[9];
    u8 f19;
} S_005F1130;
extern s32 func_L39_00577818(void);

s32 func_L39_005F1130(S_005F1130 *obj, s32 flag, f32 x, f32 lo, f32 hi) {
    s32 base = obj->f8;
    s32 r;
    if (func_L39_00577818()) {
        base = 0;
    }
    if ((obj->f19 & 1) || flag) {
        if (x <= lo) {
            r = obj->fC;
        } else if (hi <= x) {
            r = base;
        } else {
            r = base + (s32)((hi - x) * (hi - x) * (f32)(obj->fC - base) / ((hi - lo) * (hi - lo)));
        }
    } else {
        if (x <= lo) {
            r = obj->fC;
        } else if (hi <= x) {
            r = base;
        } else {
            r = base + (s32)((hi - x) * (f32)(obj->fC - base) / (hi - lo));
        }
    }
    return r;
}
/* localdecomp:end func_L39_005F1130 */
