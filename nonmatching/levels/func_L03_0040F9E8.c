/* near miss (level 3, Starship Phoenix): 3 differences: loop body and registers match, only the address setup differs (retail: lui a1; addiu a1; lui v1; addiu v1; the C: lui v1; lui v0; addiu a1,v0; addiu v1,v1); about 14 compiles (extern order, hints 4/16/32, ps2as, sized arrays, pointer locals, countdown loop) */
#include "common.h"

/* localdecomp:start func_L03_0040F9E8 */
extern int D_001D4C60[];
extern int D_001D4C80[];

void func_L03_0040F9E8(int a) {
    int i;
    for (i = 0; i < 8; i++) {
        if (D_001D4C60[i] == a) D_001D4C60[i] = 0;
        if (D_001D4C80[i] == a) D_001D4C80[i] = 0;
    }
}
/* localdecomp:end func_L03_0040F9E8 */
