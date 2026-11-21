#include "common.h"

/* localdecomp:start func_L40_004903C8 */
typedef struct {
    u8 pad0[0x20];
    s16 h20[8];
    f32 f30[8];
    u8 pad50[0x10];
} S_004903C8;

extern S_004903C8 D_L40_002926E0[];

void func_L40_004903C8(s32 a, s32 b, f32 v) {
    S_004903C8 *ea = &D_L40_002926E0[a];
    S_004903C8 *eb = &D_L40_002926E0[b];
    s32 ra = -1;
    s32 rb = -1;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (ea->h20[i] == -1) {
            ra = i;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        if (eb->h20[i] == -1) {
            rb = i;
            break;
        }
    }
    if (ra != -1 && rb != -1) {
        ea->h20[ra] = b;
        ea->f30[ra] = v;
        eb->h20[rb] = a;
        eb->f30[rb] = v;
    }
}
/* localdecomp:end func_L40_004903C8 */

/* localdecomp:start func_L40_004904B8 */
#include "vu0.h"

extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);

void func_L40_004904B8(u8 *a0, s32 a1, u8 *a2, f32 *a3, f32 *a4)
{
    vu0_v4 sum;
    u8 *pa;
    f32 m;
    f32 z;
    f32 r;
    s32 i;

    {
        f32 z0 = *(f32 *)(a0 + 8);
        *a3 = z0;
        qzero(&sum);
        *a4 = z0;
    }
    m = 0.0f;
    if (a1 > 0) {
        u8 *q = a0;
        s32 k = a1;
        do {
            vec_add_ab(&sum, &sum, q);
            q += 16;
            k--;
        } while (k != 0);
    }
    func_0038CE20(&sum, &sum, 1.0f / (f32)a1);
    if (a1 > 0) {
        pa = a0;
        i = a1;
        do {
            r = func_0038CF00(&sum, pa);
            z = *(f32 *)(pa + 8);
            if (m < r) {
                m = r;
            }
            if (*a3 < z) {
                *a3 = z;
            }
            if (z < *a4) {
                *a4 = z;
            }
            pa += 16;
            i--;
        } while (i != 0);
    }
    *(vu0_q *)a2 = *(vu0_q *)&sum;
    *(f32 *)(a2 + 0xC) = m;
}
/* localdecomp:end func_L40_004904B8 */
