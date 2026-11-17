#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L04_003F56F8);

/* localdecomp:start func_L04_003F5AF8 */
extern u8 D_001A4BE0[];
extern s32 func_00382380(void *, s32, s32);
extern f32 func_L01_0040E548(void *, void *);

u8 func_L04_003F5AF8(u8 *m) {
    u8 *g = D_001A4BE0;
    u8 *v = *(u8 **)(m + 0x68);
    s32 id;

    if (*(s32 *)(g + 0x360) == 0) {
        return 0;
    }
    id = *(s32 *)(v + 0x14);
    if (id != -1) {
        return func_00382380(g + 0x80, id, 0);
    }
    return func_L01_0040E548(m + 0x10, g + 0x80) < *(f32 *)(v + 0x18) * *(f32 *)(v + 0x18);
}
/* localdecomp:end func_L04_003F5AF8 */

INCLUDE_ASM("asm/levels", func_L04_003F5B78);

/* localdecomp:start func_L04_003F5E38 */
extern f32 func_L01_004395E0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern u8 D_001A4BE0[];

void func_L04_003F5E38(u8 *a0) {
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
    r.z = func_0038DAB8(yaw, 3.14159012f);
    r.y = f * -0.17f;
    func_L01_003EB350(0, &p);
    func_L01_003EB3C0(0, &r);
}
/* localdecomp:end func_L04_003F5E38 */
