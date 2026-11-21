#include "common.h"
#include "vu0.h"

/* declared by functions of L05_003AFC08.c, which this file was cut from */
typedef struct { u8 pad[0x144]; s32 v; } S_003B1100;
extern S_003B1100 D_L05_001E2700;

/* localdecomp:start func_L05_003B15D0 */
__asm__(".extern D_L05_001E2700, 16");
extern f32 D_001DE7B0_sda;
__asm__(".extern D_001DE7B0_sda, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

s32 func_L05_003B15D0(u8 *o) {
    u8 *b = (u8 *)&D_L05_001E2700 + 0x380;
    u8 *g;
    u8 *p;
    vu0_v4 a;
    vu0_v4 d;
    vu0_v4 c;
    vu0_v4 r;

    a = *(vu0_v4 *)b;
    g = b - 0x380;
    p = *(u8 **)(o + 0x68);
    a.z = 0.0f;
    func_0038CF68(&a, &a, 1.0f);
    vec_sub_ab(&d, o + 0x10, b - 0x380);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 1.0f);
    if (fabs_asm(1.5707964f - func_0038D0C8(func_0038CE68(&a, &d))) < *(f32 *)(g + 0x428) * 0.5f) {
        return 1;
    }
    *(vu0_q *)&r = 0;
    r.x = func_0038D098(*(f32 *)(p + 0x27C));
    r.y = func_0038D0B0(*(f32 *)(p + 0x27C));
    c = r;
    func_0038CF68(&c, &c, *(f32 *)(p + 0x28C));
    vec_add_ba(&c, &D_001DE7B0_sda, &c);
    vec_sub_ab(&d, &c, b - 0x380);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 1.0f);
    return fabs_asm(1.5707964f - func_0038D0C8(func_0038CE68(&a, &d))) < *(f32 *)(g + 0x428) * 0.5f;
}
/* localdecomp:end func_L05_003B15D0 */

/* localdecomp:start func_L05_003B1778 */
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L05_003B15D0(u8 *);
extern void func_L05_003B1A40(u8 *);
extern vu0_v4 D_L05_001DE7B0 __attribute__((section(".sdata")));
__asm__(".extern D_L05_001DE7B0, 4");

void func_L05_003B1778(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 f;
    f32 c;
    vu0_v4 w;
    vu0_v4 v;

    if (q[0x2BE] == 0) {
        if (fabs_asm(func_0038DB00(*(f32 *)(q + 0x278), *(f32 *)(q + 0x27C))) < 0.034906585f
            || func_L05_003B15D0(a0) == 0) {
            func_L05_003B1A40(a0);
        }
    }
    c = 0.013962635f;
    f = *(f32 *)(q + 0x274);
    func_L01_00448890(q + 0x278, *(f32 *)(q + 0x27C), q + 0x274, 0.000104719766f, 0.00013962634f, c, 0);
    f = func_0038DB00(*(f32 *)(q + 0x274), f);
    if (f * *(f32 *)(q + 0x274) < 0.0f) {
        f32 t = 1.0f - fabs_asm(*(f32 *)(q + 0x274)) / c;
        f = func_0038DB00(((f < 0.0f) ? -t : t) * 0.17453292f, *(f32 *)(a0 + 0xF0));
        *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), f * 0.011999965f);
    } else {
        *(f32 *)(a0 + 0xF0) *= 0.98800004f;
    }
    f = 0.00040000002f;
    func_003C41A0((f32 *)(q + 0x28C), q + 0x294, *(f32 *)(q + 0x290), f, f, 0.080000006f);
    func_003C41A0((f32 *)(q + 0x280), q + 0x288, *(f32 *)(q + 0x284), f, f, 0.10000001f);
    *(vu0_q *)&v = 0;
    v.x = func_0038D098(*(f32 *)(q + 0x278));
    v.y = func_0038D0B0(*(f32 *)(q + 0x278));
    w = v;
    func_0038CF68(&w, &w, *(f32 *)(q + 0x28C));
    w.z = *(f32 *)(q + 0x280);
    vec_add_ab(a0 + 0x10, &D_L05_001DE7B0, &w);
    if (q[0x2BF] == 0) {
        f = func_0038DAB8(*(f32 *)(q + 0x278), 3.14159274f);
        func_L01_00448890(a0 + 0xF8, f, q + 0x270, 0.00041887906f, 0.00055850536f, 0.05585054f, 0);
    }
}
/* localdecomp:end func_L05_003B1778 */
