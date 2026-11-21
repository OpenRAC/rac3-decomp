/* functional: high. Angle distance: |a-b|, and if it is pi or more, 2*pi minus it (shortest arc between two angles). Uses fabs_asm (retail abs.s) from vu0.h so -0.0 behaves; the draft's register asm tricks dropped. */
#include "vu0.h"
float func_0038DBA0(float first, float second) {
    float d = fabs_asm(first - second);
    float pi = 3.1415927f;
    if (!(d < pi)) {
        d = (pi + pi) - d;
    }
    return d;
}
