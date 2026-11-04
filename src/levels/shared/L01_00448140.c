#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00448140);

/* localdecomp:start func_L01_00448148 */
void func_L01_00448148(f32 *vel, f32 d, f32 a, f32 b, f32 c) {
    f32 cur;
    f32 ad;
    f32 cur2;

    do {
        cur = *vel;
    } while (0);
    ad = __builtin_fabsf(d);
    if (ad < cur) {
        *vel = ad;
    } else if (cur < -ad) {
        *vel = -ad;
    }
    *vel = *vel + (a * d - b * *vel);
    if (c > 0.0f) {
        if (c < *vel) {
            *vel = c;
        } else if (*vel < -c) {
            *vel = -c;
        }
    }
    do {
        cur2 = *vel;
    } while (0);
    d = __builtin_fabsf(d);
    if (d < cur2) {
        *vel = d;
    } else if (cur2 < -d) {
        *vel = -d;
    }
}
/* localdecomp:end func_L01_00448148 */
