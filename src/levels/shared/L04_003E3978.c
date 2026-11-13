#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003E3978 */
extern f32 func_L01_004395E0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern u8 D_001A4BE0[];

void func_L04_003E3978(u8 *a0) {
    vu0_v4 p;
    vu0_v4 r;
    f32 f;
    f32 t;
    f32 yaw;
    u8 *h;

    if (a0[0x42] == 1) {
        t = func_L01_004395E0(a0);
    } else {
        t = 170.0f;
    }
    f = t / 170.0f;
    h = D_001A4BE0;
    yaw = func_0038DAB8(f * 0.69813168f - 0.34906584f, *(f32 *)(h + 0x98));
    p.x = func_0038D098(yaw) * 5.0f;
    p.y = func_0038D0B0(yaw) * 5.0f;
    p.z = 0.0f;
    vec_add_ba(&p, &p, h + 0x80);
    p.z += 1.0f;
    qzero(&r);
    r.z = func_0038DAB8(yaw, 3.1415927f);
    r.y = f * -0.17f;
    func_L01_003EB350(0, &p);
    func_L01_003EB3C0(0, &r);
}
/* localdecomp:end func_L04_003E3978 */
