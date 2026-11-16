/* PAL near miss (Codex wave 8): near miss: 4 words differ with the file's flags.
 * Worker's note: 4 diff / 53 words: build/codex/w413/func_L01_00445438.01.log; retail move a0 and mul.s between vsub and sqc2 cannot be placed inside intact VU sequence; existing vu0.h helper fails fixed flags (02.log); clean contract compile; no metadata
 */
#include "common.h"
/* localdecomp:start func_L01_00445438 */
typedef int Q_00445438 __attribute__((mode(TI)));
void func_L01_00445438(Q_00445438 *out, Q_00445438 *a, Q_00445438 *b, f32 t) {
    extern void func_0038CE20(void *, void *, f32);
    Q_00445438 delta;
    f32 h;
    if (t == 0.0f) *out = *a;
    else if (t == 1.0f) *out = *b;
    else {
        h = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(delta) : "m"(*a), "m"(*b) : "vf1", "vf2");
        func_0038CE20(&delta, &delta, h);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*out) : "m"(*a), "m"(delta) : "vf1", "vf2");
    }
}
/* localdecomp:end func_L01_00445438 */
