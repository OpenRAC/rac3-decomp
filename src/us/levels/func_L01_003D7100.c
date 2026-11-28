#include "common.h"
/* localdecomp:start func_L01_003D7100 */
#include "vu0.h"
extern f32 D_L01_001DF508;
__asm__(".extern D_L01_001DF508, 4");
void func_L01_003D7100(vu0_v4 *pos) {
    extern void func_0037E2F0(void *, f32, f32);
    extern f32 func_0037E250(f32, f32);
    extern void func_003886E8(void *, void *, f32);
    extern s32 func_L01_00445C50(s32, s32);
    extern s32 func_0037E208(s32, s32);
    extern void func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
    vu0_v4 p, velocity;
    f32 scale;
    s32 first, second, life;
    func_0037E2F0(&p, 0.25f, 0.75f);
    vec_add_ab(&p, &p, pos);
    vec_sub_ba(&velocity, &p, pos);
    func_003886E8(&velocity, &velocity, func_0037E250(1.0f, 3.0f) * 0.0166666675f);
    scale = D_L01_001DF508;
    first = func_L01_00445C50(0x4F007FFF, 0);
    second = func_L01_00445C50(0x1F00007F, 0);
    life = func_0037E208(20, 35);
    func_L01_00462190(pos, &velocity, first, second, life, 1, -1, -1, 0, scale * 40000.0f);
}
/* localdecomp:end func_L01_003D7100 */
