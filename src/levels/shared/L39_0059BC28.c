#include "common.h"

/* localdecomp:start func_L39_0059BC28 */
extern s32 D_00241418;
extern u16 D_00201558[];

void func_L39_0059BC28(u16 id) {
    s32 i;

    for (i = 0; D_00201558[i] != id && i < D_00241418; i++) {
    }
    if (i < D_00241418) {
        for (; i < D_00241418 - 1; i++) {
            D_00201558[i] = D_00201558[i + 1];
        }
        D_00201558[i] = 0;
        D_00241418--;
    }
    D_00201558[D_00241418++] = id;
}
/* localdecomp:end func_L39_0059BC28 */
