/* functional: high. Compiles with file flags (191 words differ: frame size, regalloc); every call, constant and branch checked against the asm. */
/* localdecomp:start func_L01_0037C3C8 */
#include "vu0.h"
extern u8 *D_L01_00221098[] __attribute__((section(".sdata")));
extern u8 *D_L01_0022116C[];
extern vu0_v4 D_001A4EC0;
void func_L01_0037C3C8(u8 *p, vu0_v4 a, vu0_v4 b) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_00382468(s32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
    vu0_v4 velocity;
    vu0_v4 pos;
    vu0_v4 step;
    vu0_v4 tail;
    u8 *v = *(u8 **)(p + 0x68);
    f32 length = func_0038CEA8(v);
    s32 count = length / 0.1f;
    s32 i;
    pos = b;
    vec_sub_ab(&step, &a, &b);
    func_0038CF68(&step, &step, length / count);
    for (i=0; i<count; ++i) {
        s32 spin = func_L01_00443A18(1.0f, 3.0f);
        s32 life, alpha;
        s32 rgb;
        u8 *particle;
        func_0038CE20(&velocity, &D_001A4EC0, -(func_003824E0(0.1f, 0.2f) * 0.020000001415610313f));
        life = func_00382498(3,6);
        if (func_0013D3E0() & 2) { alpha=64; rgb=0xFF7F40; }
        else { alpha=96; rgb=0xFF4040; }
        particle=func_L01_0046A610(&pos, &velocity, (life*5+2)/6, alpha, rgb, spin, 63000.00390625f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&pos, &pos, &step);
        if (particle) {
            particle[2] = *D_L01_00221098[23];
            particle[3] = alpha == 64 ? 0x48 : 0x44;
        }
    }
    if (*(s32 *)(v+0x14) < 50 && func_00382468(2)) {
        s32 colour=0x7F80DFFF;
        u8 *particle;
        func_0038CE20(&tail, v, -0.04000000283122063f);
        func_003C4C18(&tail, 0.12000000476837158f);
        tail.z += 0.06000000238418579f;
        if (func_00382468(2)) colour=0x7F407FFF;
        particle=func_L01_00465738(p+0x10, &tail, colour, 255, func_00382498(8,17), 0, -1, -1, 0, 94500.0f);
        if (particle) {
            *(f32 *)(particle+0x2C)=0.002400000113993883f;
            particle[2]=*D_L01_0022116C[0];
        }
    }
}
/* localdecomp:end func_L01_0037C3C8 */
