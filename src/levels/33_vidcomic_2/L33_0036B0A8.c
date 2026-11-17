#include "common.h"

/* localdecomp:start func_L33_0036B0A8 */
#include "vu0.h"

extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L33_0036B0A8(f32 *pos) {
    f32 v[4] __attribute__((aligned(16)));
    s32 i;

    for (i = 0; i < 1; i++) {
        f32 ang = func_00382538();
        f32 r = func_003824E0(0.0f, 0.6f);
        f32 a = func_003824E0(0.0f, 1.2f);
        f32 b = func_003824E0(1.0f, 4.0f);
        s32 n = func_00382498(0x46, 0x82);
        u8 *p;

        v[0] = func_0038D098(ang) * r;
        v[1] = func_0038D0B0(ang) * r;
        v[2] = 0.0f;
        vec_add_ba(v, v, pos);
        p = func_L01_0046B288(a, b, v, 0x5005B182, 0x5B182, n);
        if (p != 0) {
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L33_0036B0A8 */
