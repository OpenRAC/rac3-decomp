#include "common.h"

/* localdecomp:start func_L03_0043C438 */
extern u16 **D_L03_001D6764_0043C438;
extern s32 D_L03_001D6768_0043C438;
extern char *D_L03_001E085C_0043C438;
extern f32 func_0038CF00(void *, void *);

s32 func_L03_0043C438(void *self, s32 idx)
{
    s32 best = -1;
    f32 bestDist;
    u16 *p;
    char *q;
    s32 i;

    if (idx != -1) {
        bestDist = 9999.0f;
        p = D_L03_001D6764_0043C438[idx];
        while (p != 0 && (((s16 *)p)[-1] >= 0 || p == D_L03_001D6764_0043C438[idx])
               && (q = D_L03_001E085C_0043C438 + (*p & 0x7FFF) * 64) != 0) {
            f32 d = func_0038CF00(q + 0x30, (char *)self + 0x10);
            if (d < bestDist) {
                bestDist = d;
                best = *p & 0x7FFF;
            }
            p++;
        }
    }
    if (best == -1) {
        bestDist = 9999.0f;
        for (i = 0; i < D_L03_001D6768_0043C438; i++) {
            p = D_L03_001D6764_0043C438[i];
            while (p != 0 && (((s16 *)p)[-1] >= 0 || p == D_L03_001D6764_0043C438[i])
                   && (q = D_L03_001E085C_0043C438 + (*p & 0x7FFF) * 64) != 0) {
                f32 d = func_0038CF00(q + 0x30, (char *)self + 0x10);
                if (d < bestDist) {
                    bestDist = d;
                    best = *p & 0x7FFF;
                }
                p++;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L03_0043C438 */
