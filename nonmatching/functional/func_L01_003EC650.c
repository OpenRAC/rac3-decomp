/* functional: high. Orients a player-linked object toward its pose target: builds the direction to e+0x190, derives a pitch angle (acos of the dot with the object's axis), smooths it (state 0x24 ramps data+0x30 up to 1, else eases it to 0), rotates the basis by it and re-orthonormalises the three axes via cross products */
#include "vu0.h"
extern u8 D_L01_001E2A40[];
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern f32 func_0038D0C8(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
void func_L01_003EC650(u8 *a0) {
    f32 va[4] __attribute__((aligned(16)));
    f32 vb[4] __attribute__((aligned(16)));
    f32 vc[4] __attribute__((aligned(16)));
    u8 *data = *(u8 **)(a0 + 0x70);
    u8 *e = D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460;
    u8 *e150 = e + 0x150;
    f32 ang, k;

    *(vu0_q *)va = *(vu0_q *)(e + 0x190);
    va[2] = va[2] + *(f32 *)(data + 0x8C);
    vec_sub_ba(vb, va, a0 + 0x30);
    func_0038CF68(vb, vb, 1.0f);
    ang = 1.5707964f - func_0038D0C8(func_0038CE68(vb, a0));
    if (*(s32 *)(e150 + 0x100) == 0x24) {
        *(f32 *)(data + 0x30) = *(f32 *)(data + 0x30) + 0.017f;
        if (1.0f < *(f32 *)(data + 0x30)) *(f32 *)(data + 0x30) = 1.0f;
        k = ang * *(f32 *)(data + 0x30);
    } else {
        k = func_00382C58((f32 *)(data + 0x30), 0.0f, ang, 0.02f, 0.175f, 0.0f);
    }
    func_0038CE90(vc, vb, a0 + 0x40);
    func_0038D890(a0, a0 + 0x40, vc, k);
    func_0038CF68((f32 *)(a0 + 0x40), (f32 *)a0, 1.0f);
    *(vu0_q *)a0 = *(vu0_q *)(a0 + 0x40);
    func_0038CE90(a0 + 0x10, a0, D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460 + 0x80);
    func_0038CF68((f32 *)(a0 + 0x10), (f32 *)(a0 + 0x10), 1.0f);
    func_0038CE90(a0 + 0x20, a0 + 0x10, a0);
}
