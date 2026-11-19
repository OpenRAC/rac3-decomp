/* functional: high. Written from asm; 87 diff = register allocation and the cvt.w.s/cvt.s.w float truncation (compiler adds a GPR round trip), not behaviour; unused first argument kept */
#include "vu0.h"
extern void func_00389478(void *, f32 *, f32 *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern f32 D_L30_001DCF2C;
extern f32 D_L30_001DCF30;
extern f32 D_L30_001DCF34;
__asm__(".extern D_L30_001DCF2C, 4");
__asm__(".extern D_L30_001DCF30, 4");
__asm__(".extern D_L30_001DCF34, 4");

void func_L30_00346080(u8 *obj, void *pos, f32 *pu, f32 *pv, f32 a, f32 b, f32 amp, f32 k) {
    f32 t;
    f32 inv;

    func_00389478(pos, pu, pv);
    t = D_L30_001DCF34 * b;
    inv = 1.0f - k;
    *pu += func_0038D0B0(func_0038DB48((t - (f32)(s32)t + D_L30_001DCF30 * k) * 6.2831855f)) * (inv * D_L30_001DCF2C * amp);
    t = D_L30_001DCF34 * a;
    *pv += func_0038D0B0(func_0038DB48((t - (f32)(s32)t + D_L30_001DCF30 * k) * 6.2831855f)) * (inv * D_L30_001DCF2C * amp);
    if (1.0f < *pu) {
        *pu = 1.0f;
    } else if (*pu < 0.0f) {
        *pu = 0.0f;
    }
    if (1.0f < *pv) {
        *pv = 1.0f;
    } else if (*pv < 0.0f) {
        *pv = 0.0f;
    }
}
