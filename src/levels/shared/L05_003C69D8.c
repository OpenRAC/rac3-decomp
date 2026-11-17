#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003C69D8 */
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

void func_L05_003C69D8(u8 *a0) {
    u8 *m;
    u8 inv[0x30];
    vu0_v4 d;
    u8 rot[0x30];
    vu0_v4 w;
    f32 r;
    f32 a;

    m = *(u8 **)(a0 + 0x68);
    func_L01_0040EE50(inv, a0 + 0xC0);
    vec_sub_ba(&d, m + 0x220, a0 + 0x10);
    func_0038D000(&d, &d, inv);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 1.0f);
    a = func_0038D0C8(d.y);
    if (d.x < 0.0f) {
        a = -a;
    }
    {
        f32 p = *(f32 *)(m + 0x84);
        f32 q = *(f32 *)(m + 0x88);
        f32 s = *(f32 *)(m + 0x8C);
        r = 0.0f;
        func_L01_00448890(&r, a, m + 0x124, p, q, s, 0);
    }
    qzero(&w);
    w.z = *(f32 *)(m + 0x124);
    func_0038D308(rot, &w);
    func_0038D5F0(a0 + 0xC0, a0 + 0xC0, rot);
}
/* localdecomp:end func_L05_003C69D8 */
