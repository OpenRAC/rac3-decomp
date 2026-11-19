/* functional: high. Register passthrough: retail calls func_0038CF68/func_0038CE20 with the scale left in $f12 (t), passed explicitly here. vadd.xyz is three float adds (w untouched, as retail). Retail keeps hero base in a callee-saved reg; same memory. */
#include "common.h"
/* localdecomp:start func_L01_003C68E8 */
#include "vu0.h"
extern f32 D_L01_001DEE00;
__asm__(".extern D_L01_001DEE00, 4");
extern u8 D_001A4C60[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_L01_005003D0(s32, s32);
void func_L01_003C68E8(u8 *m, f32 *vec, f32 arg) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 t = D_L01_001DEE00 + arg;
    f32 ang;
    vu0_v4 tmp;
    s32 st;
    if (t <= 0.0f) {
        func_L01_00511A40(D_001A4C60, 0, *(f32 *)(D_001A4C60 + 0x18));
        return;
    }
    if (arg > 1000.0f) {
        t = t - 1000.0f;
        st = 2;
    } else {
        st = 1;
    }
    v[0x100] = st;
    if (vec != 0) {
        func_0038CF68(&tmp, vec, t);
        ang = func_0038D160(vec[0], vec[1]);
    } else {
        func_0038CE20(&tmp, m + 0xC0, t);
        ang = *(f32 *)(m + 0xF8);
    }
    tmp.x += *(f32 *)(D_001A4C60 + 0);
    tmp.y += *(f32 *)(D_001A4C60 + 4);
    tmp.z += *(f32 *)(D_001A4C60 + 8);
    func_L01_00511A40(&tmp, 1, ang);
    if (*(s32 *)(D_001A4C60 + 0x2544) == 0x68) {
        func_L01_005003D0(0x66, 2);
    }
}
/* localdecomp:end func_L01_003C68E8 */
