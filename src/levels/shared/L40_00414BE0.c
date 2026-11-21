#include "common.h"

/* localdecomp:start func_L40_00414BE0 */
typedef struct {
    s32 v[24];
    s32 n;
} S_00414BE0;
extern s32 D_001DE038_sda __attribute__((section(".sdata")));
extern s32 D_L40_002496E8[];
extern s32 D_L40_00249718[];
void func_L40_00414BE0(u8 *a0) {
    S_00414BE0 *p = *(S_00414BE0 **)(a0 + 0x68);
    s32 i = 0;
    D_001DE038_sda = p->n;
    if (i < p->n) {
        s32 *d1 = D_L40_002496E8;
        s32 *d2 = D_L40_00249718;
        do {
            d1[i] = p->v[i];
            d2[i] = p->v[i + 12];
            i++;
        } while (i < p->n);
    }
}
/* localdecomp:end func_L40_00414BE0 */
