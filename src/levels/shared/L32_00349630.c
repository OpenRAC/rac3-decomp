#include "common.h"

/* localdecomp:start func_L32_00349630 */
#include "vu0.h"

extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_L32_00348900(u8 *);
extern s32 func_L31_00346838(void *, void *, vu0_v4 *, s32, f32, f32);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L32_001DD000;
__asm__(".extern D_L32_001DD000, 4");

s32 func_L32_00349630(u8 *a0, f32 *pos, f32 f0, f32 f1, f32 f2, f32 lo, f32 hi, f32 f5, f32 f6) {
    vu0_v4 v;
    f32 d0, d1;
    f32 w;
    f32 h;
    f32 cur;
    f32 q;
    f32 aq;
    f32 r;
    f32 t;
    f32 u;
    f32 lim;
    s32 n;

    h = func_003C3D30(pos, 0, 0, 0.5f);
    cur = func_L32_00348900(a0);
    aq = fabs_asm(f1 / f2);
    w = f2;
    if (fabs_asm(f5) > 0.0f && f1 < 0.0f) {
        w = f5;
    }
    r = f0;
    if (f6 >= 0.0f) {
        r = f6;
    }
    if (pos[0] < 2.0f || pos[0] > 1021.0f || pos[1] < 2.0f || pos[1] > 1021.0f || pos[2] < 2.0f ||
        pos[2] > 1021.0f) {
        return 1;
    }
    if (cur < lo && aq > 2.0f) {
        t = lo - cur;
        t = t + t;
        q = t / aq;
        if (q > 0.0f) {
            func_003C4138((f32 *)(a0 + 0x48), q, D_L32_001DD000);
        }
    } else if (cur > lo) {
        qzero(&v);
        v.z = w;
        if (func_L31_00346838(a0, pos, &v, 0, f0, r)) {
            *(f32 *)(a0 + 0x48) = 1.0f;
        } else if (cur > hi) {
            *(f32 *)(a0 + 0x48) = 0.0f;
        } else {
            n = func_L01_004461B8(&d0, &d1, w * 0.5f, f1, pos[2] - h);
            lim = 60.0f;
            if (n > 0 && d0 > 0.0f && d0 < 60.0f) {
                lim = d0;
            }
            if (lim < 0.0001f) {
                lim = 0.0001f;
            }
            u = hi - cur;
            u = u + u;
            q = u / lim;
            if (q > 2.0f) {
                q = 2.0f;
            } else if (q < 0.0f) {
                q = 0.0f;
            }
            func_003C4138((f32 *)(a0 + 0x48), q, D_L32_001DD000);
        }
    }
    return 0;
}
/* localdecomp:end func_L32_00349630 */
