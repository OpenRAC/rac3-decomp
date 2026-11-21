#include "common.h"

/* NTSC-U counterpart of func_L05_003B1778 (src/levels/05_daxx/L05_003B15D0.c): 0.0139626 -> 0.0116355; 0.00010472 -> 7.27221e-05; 0.000139626 -> 9.69627e-05; 0.012 -> 0.00999999; 0.988 -> 0.99; 0.0004 -> 0.000277778; 0.08 -> 0.0666667; 0.1 -> 0.0833333; 0.000418879 -> 0.000290888; 0.000558505 -> 0.000387851; 0.0558505 -> 0.0465421 */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

/* localdecomp:start func_L05_003AF858 */
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L05_003AF6B0(u8 *);
extern void func_L05_003AFB20(u8 *);
extern vu0_v4 D_L05_001DE7F0 __attribute__((section(".sdata")));
__asm__(".extern D_L05_001DE7F0, 4");

void func_L05_003AF858(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 f;
    f32 c;
    vu0_v4 w;
    vu0_v4 v;

    if (q[0x2BE] == 0) {
        if (fabs_asm(func_003893C8(*(f32 *)(q + 0x278), *(f32 *)(q + 0x27C))) < 0.034906585f
            || func_L05_003AF6B0(a0) == 0) {
            func_L05_003AFB20(a0);
        }
    }
    c = 0.0116355289f;
    f = *(f32 *)(q + 0x274);
    func_L01_00445758(q + 0x278, *(f32 *)(q + 0x27C), q + 0x274, 7.2722054e-05f, 9.69627363e-05f, c, 0);
    f = func_003893C8(*(f32 *)(q + 0x274), f);
    if (f * *(f32 *)(q + 0x274) < 0.0f) {
        f32 t = 1.0f - fabs_asm(*(f32 *)(q + 0x274)) / c;
        f = func_003893C8(((f < 0.0f) ? -t : t) * 0.17453292f, *(f32 *)(a0 + 0xF0));
        *(f32 *)(a0 + 0xF0) = func_00389380(*(f32 *)(a0 + 0xF0), f * 0.00999999046f);
    } else {
        *(f32 *)(a0 + 0xF0) *= 0.99000001f;
    }
    f = 0.000277777785f;
    func_003BEC60((f32 *)(q + 0x28C), q + 0x294, *(f32 *)(q + 0x290), f, f, 0.0666666701f);
    func_003BEC60((f32 *)(q + 0x280), q + 0x288, *(f32 *)(q + 0x284), f, f, 0.0833333358f);
    *(vu0_q *)&v = 0;
    v.x = func_00388960(*(f32 *)(q + 0x278));
    v.y = func_00388978(*(f32 *)(q + 0x278));
    w = v;
    func_00388830(&w, &w, *(f32 *)(q + 0x28C));
    w.z = *(f32 *)(q + 0x280);
    vec_add_ab(a0 + 0x10, &D_L05_001DE7F0, &w);
    if (q[0x2BF] == 0) {
        f = func_00389380(*(f32 *)(q + 0x278), 3.14159274f);
        func_L01_00445758(a0 + 0xF8, f, q + 0x270, 0.000290888216f, 0.000387850945f, 0.0465421155f, 0);
    }
}
/* localdecomp:end func_L05_003AF858 */
