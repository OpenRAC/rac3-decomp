/* Near miss (2 words of 16, 2026-11-18): func_L01_0044AE78 wraps an angle into [-pi, pi).
 * Needs `@ps2as` on L01_0044ABD0.c (retail builds the two constants inline) and the divs_nops row
 * `func_L01_0044AE78 2`. Left: retail's `sub.s $f1, $f12, $f1` writes the fraction into the
 * truncation's register; this C ties it to t's ($f12). Tried: t as a local, the parameter reused,
 * a separate frac local, frac as an inline function, the truncation in its own local (same bytes).
 */
#include "common.h"
/* localdecomp:start func_L01_0044AE78 */
#include "vu0.h"
f32 func_L01_0044AE78(f32 x) {
    f32 t = (x + 3.1415927f) / 6.2831855f;
    f32 frac = t - cvtsw_asm(cvtws_asm(t));
    return frac * 6.2831855f - 3.1415927f;
}
/* localdecomp:end func_L01_0044AE78 */
