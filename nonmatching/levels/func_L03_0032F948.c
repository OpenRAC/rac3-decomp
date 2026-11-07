/* near miss (level 3, Starship Phoenix): 31 differences: incomplete attempt (the agent returned no report); the control flow and the float scaling constants are in place, the instruction sequence is not yet verified against retail (uses mult $ac2 forms), so it needs another pass */
#include "common.h"

/* localdecomp:start func_L03_0032F948 */
typedef struct { char pad[0xC]; s32 v; char pad2[0x28 - 0x10]; } S_0032F948;
extern S_0032F948 D_L03_002AE4D0_0032F948[];
extern unsigned char func_L03_0032FA50(int i);
extern int func_L01_0041A4F0(void);
int func_L03_0032F948(int i) {
    S_0032F948 *p = &D_L03_002AE4D0_0032F948[i]; float f = p->v;
    int n = func_L03_0032FA50(i);
    if (n >= 2) {
        f *= 0.1f;
    } else if (n == 1) {
        f *= 0.33f;
    }
    if (func_L01_0041A4F0()) {
        f *= 20.0f;
    }
    return (int)(f * 0.02f + 0.5f) * 50;
}
/* localdecomp:end func_L03_0032F948 */
