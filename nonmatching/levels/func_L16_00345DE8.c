/* PAL near miss (Claude wave S/pal): near miss: 30 words differ with the file's flags.
 * Worker's note: NEEDS divs row 'func_L16_00345DE8 2' (1 div.s, 2 nops; row injected for the check); 30 diff (mostly shift): same control flow and constants, only the second cvt.w.s differs: retail converts (s32)t twice (cvt.w.s+mfc1 for the index, a second cvt.w.s+cvt.s.w in ...
 */
#include "common.h"

/* localdecomp:start func_L16_00345DE8 */
extern f32 D_L16_00278200_00345DE8[];

f32 func_L16_00345DE8(f32 t, f32 d, s32 *pn) {
    s32 n;

    if (0.0f < d) {
        n = *pn;
        do {
            s32 i = (s32)t;
            f32 rem = 1.0f - (t - (f32)(s32)t);
            f32 seg = D_L16_00278200_00345DE8[i];
            s32 next = (i + 1) % n;
            f32 step = d / seg;

            if (rem < step) {
                d = d - rem * seg;
                t = (f32)next;
            } else {
                t = t + step;
                d = 0.0f;
            }
        } while (0.0f < d);
    }
    return t;
}
/* localdecomp:end func_L16_00345DE8 */
