#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_00445488 */
extern s32 D_L19_001DF600;
extern f32 D_L19_001DF5F8;
extern f32 D_L19_001E2080[];
extern vu0_v4 D_L19_001E8E60;
extern f32 D_L19_001D7B80;
__asm__(".extern D_L19_001D7B80, 4");
extern s32 D_L19_001D7B24;
__asm__(".extern D_L19_001D7B24, 4");
extern f32 func_L01_00451768(vu0_v4 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern f32 func_003824E0(f32, f32);
extern void *func_L01_0046A938(vu0_v4 *, s32, s32, f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_00463218(void *, s32, s32);
void func_L19_00445488(vu0_v4 *pos) {
    vu0_v4 v;
    vu0_v4 t;
    vu0_v4 d2;
    vu0_v4 d;
    vu0_v4 *pv = &v;
    f32 ok = 0.0f;
    s32 r;
    *(vu0_q *)&v = *(vu0_q *)pos;
    if (D_L19_001DF600 != 0) {
        v.z = func_L01_00451768(&v) + D_L19_001DF5F8;
        if (v.z < D_L19_001E2080[2] + 5.0f) {
            *(vu0_q *)&t = *(vu0_q *)&v;
            ok = 1.0f;
            t.z = t.z - (D_L19_001DF5F8 + D_L19_001DF5F8) - 2.0f;
        }
    } else if (0.0f < v.x && 0.0f < v.y && v.x < 1024.0f && v.y < 1024.0f) {
        *(vu0_q *)&t = *(vu0_q *)pos;
        t.z = D_L19_001E2080[2] - 20.0f;
        ok = 1.0f;
    }
    if (ok == 0.0f) return;
    if (func_003D3CB0(pv, &t, 0x12, 0, 0) == 0) return;
    r = func_003D5630();
    if (r == 0 || r == 4 || r == 3) {
        *(vu0_q *)pv = *(vu0_q *)&D_L19_001E8E60;
        pv->z += D_L19_001D7B80;
        func_L01_0046A938(pv, D_L19_001D7B24, -1, func_003824E0(0.4f, 0.6f), 5250.0f);
    } else {
        vec_sub_ab(&d, &D_L19_001E8E60, D_L19_001E2080);
        *(vu0_q *)&d2 = *(vu0_q *)&d;
        func_L01_00463218(&D_L19_001E8E60, (u8)(s32)(func_0038CED8(&d2) / 60.0f * 191.0f + 64.0f), 0);
    }
}
/* localdecomp:end func_L19_00445488 */
