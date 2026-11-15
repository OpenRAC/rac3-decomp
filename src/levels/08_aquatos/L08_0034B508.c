#include "common.h"

/* localdecomp:start func_L08_0034B508 */
#include "vu0.h"
typedef int Q_0034B508 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x20]; vu0_v4 x20; vu0_v4 x30; vu0_v4 x40; } G_0034B508;
extern G_0034B508 D_L08_001E8A80;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C2880(void *);

void func_L08_0034B508(u8 *a0)
{
    u8 *q = *(u8 **)(a0 + 0x68);
    vu0_v4 v;
    s32 hit;
    u8 *p;

    vec_add_ab(&v, a0 + 0x10, q);
    hit = func_003D3CB0(a0 + 0x10, &v, 0, *(void **)(q + 0x18), 0);
    if (hit == 0) {
        v.z += 0.3f;
        hit = func_L01_003FB640(&v, 0, *(u8 **)(q + 0x18), 0.3f);
        v.z -= 0.3f;
    } else {
        *(Q_0034B508 *)&D_L08_001E8A80.x30 = *(Q_0034B508 *)&D_L08_001E8A80.x20;
        D_L08_001E8A80.x30.z += 0.3f;
    }
    if (hit != 0) {
        *(Q_0034B508 *)(a0 + 0x10) = *(Q_0034B508 *)&D_L08_001E8A80.x30;
        *(f32 *)(a0 + 0x18) -= 0.3f;
        func_L01_0040E790((f32 *)q, (f32 *)q, (f32 *)&D_L08_001E8A80.x40);
        func_0038CE20(q, q, 0.75f);
        if (func_0038CEA8(q) < 0.01f) {
            func_003C2880(a0);
            return;
        }
    } else {
        *(vu0_v4 *)(a0 + 0x10) = v;
    }
    *(f32 *)(q + 0x8) -= *(f32 *)(q + 0x10);
    *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), *(f32 *)(q + 0x14));
    p = *(u8 **)(q + 0x1C);
    if (p == 0 || *(s16 *)(p + 0xAA) != 0x326 || p[0x20] == 0xFE || p[0x20] == 0xFD
        || *(f32 *)(a0 + 0x10) < 2.0f || 1021.0f < *(f32 *)(a0 + 0x10)
        || *(f32 *)(a0 + 0x14) < 2.0f || 1021.0f < *(f32 *)(a0 + 0x14)
        || *(f32 *)(a0 + 0x18) < 2.0f || 1021.0f < *(f32 *)(a0 + 0x18)) {
        func_003C2880(a0);
    } else {
        *(Q_0034B508 *)(p + 0x10) = *(Q_0034B508 *)(a0 + 0x10);
        *(Q_0034B508 *)(*(u8 **)(q + 0x1C) + 0xF0) = *(Q_0034B508 *)(a0 + 0xF0);
    }
}
/* localdecomp:end func_L08_0034B508 */
