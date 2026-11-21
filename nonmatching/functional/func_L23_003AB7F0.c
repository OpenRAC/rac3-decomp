/* functional: high. Same calls, args and order; only register allocation and VU0 op scheduling differ. */
#include "vu0.h"
#include "structs/hero.h"
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern u8 D_001A4CC0[];
extern struct Hero D_001A4BE0;
extern s32 D_L23_001DE1E0;
__asm__(".extern D_L23_001DE1E0, 4");

void func_L23_003AB7F0(u8 *self)
{
    s32 *vars = *(s32 **)(self + 0x68);
    V4 pos;
    V4 dir;
    V4 jit;
    V4 spark;
    V4 P;
    V4 Q;
    V4 D;
    s32 i;
    s32 r1;
    s32 r2;

    pos.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.1f;
    pos.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.1f;
    pos.z = 1.0f;
    P = *(V4 *)(self + 0x10);
    Q = *(V4 *)D_001A4CC0;
    vec_sub_ab(&D, &Q, &P);
    vec_add_ab(&pos, &pos, &P);
    dir = D;
    func_0038CF68(&dir, &dir, 1.2f);
    for (i = 9; i >= 0; i--) {
        jit = dir;
        jit.x += func_003824E0(-0.40000001f, 0.40000001f);
        jit.y += func_003824E0(-0.40000001f, 0.40000001f);
        jit.z += func_003824E0(-0.40000001f, 0.40000001f);
        func_0038CE20(&jit, &jit, 0.25f);
        jit.w = func_003824E0(0.5f, 1.0f);
        qzero(&spark);
        spark.z = 0.01f;
        spark.w = 1.2f;
        r1 = func_00382498(0x11, 0x19);
        r2 = func_00382498(8, 0x11);
        func_L01_00463378(&pos, &jit, &spark, 0x80406060, 0x80808080, 1, r1, r2, -1);
    }
    func_L23_003B0978(self, &pos, &dir, (s32)D_001A4BE0.hero_moby, 0x96, 0);
    vars[0] = D_L23_001DE1E0;
}
