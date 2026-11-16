/* PAL near miss (Codex wave 6): near miss: 35 words differ with the file's flags.
 * Worker's note: 35 instruction differences in floating register allocation; build/codex/w285/func_L01_0030D7A8.02.log; three later wordings produced identical 36-diff code, stopped
 */
#include "common.h"
/* localdecomp:start func_L01_0030D7A8 */
typedef int Q_0030D7A8 __attribute__((mode(TI)));
void func_L01_0030D7A8(f32 *out, f32 *a, f32 *b, f32 *c, f32 *d, f32 t) {
    f32 t2, t3, x, y, z;
    if (t == 0.0f) {
        *(Q_0030D7A8 *)out = *(Q_0030D7A8 *)a;
        return;
    }
    if (t == 1.0f) {
        *(Q_0030D7A8 *)out = *(Q_0030D7A8 *)b;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    z = b[0] - c[0];
    x = c[0] - a[0];
    y = (d[0] - b[0]) - x;
    out[0] = ((y * t3 + (x - y) * t2) + z * t) + a[0];
    z = b[1] - c[1];
    x = c[1] - a[1];
    y = (d[1] - b[1]) - x;
    out[1] = ((y * t3 + (x - y) * t2) + z * t) + a[1];
    z = b[2] - c[2];
    x = c[2] - a[2];
    y = (d[2] - b[2]) - x;
    out[2] = ((y * t3 + (x - y) * t2) + z * t) + a[2];
    out[3] = 0.0f;
}
/* localdecomp:end func_L01_0030D7A8 */
