#include "common.h"
/* localdecomp:start func_L01_00335418 */
#include "vu0.h"
extern char *D_L01_001DFC4C;
extern s32 *D_L01_0021F6C0[];
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_00382498(s32, s32);
s32 func_L01_00335418(u8 *a, u8 *b, u8 *moby, u8 *state, s32 value, u8 *cfg) {
    vu0_v4 sum;
    s32 *path;
    s32 i;
    u8 *v;
    f32 ang;
    f32 r;
    if (*(s32 *)(cfg + 0x70) == -1) {
        return 1;
    }
    {
        s32 off = *(s32 *)(cfg + 0x70) * 0x30;
        path = D_L01_0021F6C0[**(s32 **)(D_L01_001DFC4C + off + 0x3C)];
    }
    qzero(&sum);
    for (i = 0; i < *path; i++) {
        vec_add_ba(&sum, &sum, &((vu0_v4 *)path)[i + 1]);
    }
    func_0038CE20(&sum, &sum, 1.0f / (f32)*path);
    ang = func_00382538();
    r = func_003824E0(2.0f, 10.0f);
    qzero(state + 0x4A0);
    *(f32 *)(state + 0x4A0) = func_0038D098(ang) * r;
    *(f32 *)(state + 0x4A4) = func_0038D0B0(ang) * r;
    vec_add_ba(state + 0x4A0, state + 0x4A0, &sum);
    if (func_L01_00456500(state + 0x4A0, *(s32 *)(cfg + 0x70)) == 0) {
        *(vu0_q *)(state + 0x4A0) = *(vu0_q *)&sum;
    }
    if (*(s32 *)(b + 0x68) == 0) {
        *(s32 *)(b + 0x68) = func_00382498(300, 0x212);
    }
    a[0xBC] = 0;
    b[0x5E] = 0;
    return 0;
}
/* localdecomp:end func_L01_00335418 */
