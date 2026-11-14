#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005D62A8);

/* localdecomp:start func_L39_005D62B8 */
#include "vu0.h"
typedef struct {
    s32 count;
    u8 pad4[0xC];
    vu0_v4 pts[1];
} S_005D62B8;
extern void func_0038CF68(void *, void *, f32);

void func_L39_005D62B8(S_005D62B8 *path, s32 *idx, f32 *frac, vu0_v4 *out, f32 t, f32 len) {
    vu0_v4 s;
    vu0_v4 r;
    s32 i;
    s32 n;

    i = (s32)(t / len);
    *idx = i;
    n = path->count - 1;
    if (i >= n) {
        *idx = n;
        *frac = 0.0f;
        *out = *(path->pts + *idx);
        return;
    }
    if (i < 0) {
        *idx = 0;
        *frac = 0.0f;
        *out = *(path->pts + *idx);
        return;
    }
    *frac = t - (f32)i * len;
    vec_sub_ba(&r, &path->pts[*idx + 1], &path->pts[*idx]);
    *out = s = r;
    func_0038CF68(out, out, *frac);
    vec_add_ab(&r, out, &path->pts[*idx]);
    *out = s = r;
}
/* localdecomp:end func_L39_005D62B8 */

LINKER_REMNANT("asm/levels", func_L39_005D63C0);
