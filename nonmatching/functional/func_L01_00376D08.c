/* functional: high. Verified vs PAL asm: state offsets (a 0x70, b 0x74, angle 0x78/0x7C, radius 0x44, phase 0x40, arrays at 0xA0/0x220/0x3A0), 4 flare calls, 24-bolt loop with rotate/scale/offset, phase wrap, 4 random-rolled sprites; func_0038CF68 calls use the file's (scale,dst,src) prototype. */
#include "vu0.h"
typedef struct {
    u8 pad[0x40]; f32 phase, radius; u8 pad48[0x28];
    f32 a, b, angle, angle2; u8 pad80[0x20];
    vu0_v4 direction[24], result[24]; f32 angles[24];
} State_00376D08;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } M_00376D08;
void func_L01_00376D08(u8 *obj)
{
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_00376178(void *, s32, f32, f32, f32, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
    vu0_v4 at, center;
    State_00376D08 *s = *(State_00376D08 **)(obj + 0x68);
    vu0_v4 *in, *out;
    f32 *angle;
    s32 i;
    u8 *pos;
    s->a -= 0.04f;
    if (s->a <= 0.0f) s->a = 0.0f;
    s->b -= 0.025f;
    if (s->b <= 0.0f) s->b = 0.0f;
    pos = obj + 0x10;
    s->angle = func_0038DAB8(s->angle, 0.052359879f);
    s->angle2 = func_0038DAB8(s->angle, 0.087266468f);
    func_L01_00376178(&((M_00376D08 *)obj)->pos, 54, s->a, 0.5f, s->angle, 0.5f);
    func_L01_00376178(&((M_00376D08 *)obj)->pos, 54, s->b, 0.5f, s->angle2, 0.5f);
    func_L01_00376178(&((M_00376D08 *)obj)->pos, 54, s->radius, 0.5f, -s->angle, 0.8f);
    func_L01_00376178(&((M_00376D08 *)obj)->pos, 54, s->radius, 0.5f, s->angle, 0.8f);
    s->radius -= 0.125f;
    if (s->radius < 0.0f) s->radius = 0.0f;
    out = s->result;
    angle = s->angles;
    in = s->direction;
    for (i = 23; i >= 0; i--) {
        func_0038D890(out, out, in, *angle);
        angle++;
        func_0038CF68(s->radius, out, out);
        in++;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(at) : "m"(*out), "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
        *(vu0_q *)&center = *(vu0_q *)(obj + 0x10);
        out++;
        func_L01_0040A8C0(&at, &center, 18, 1, 0x2020FF, 0x2020FF, 0x1FFF2020, 0x1FFF2020, 0.08f, 3.0f, s->phase);
    }
    s->phase -= func_003824E0(0.025f, 0.035f);
    if (s->phase <= -8.0f) s->phase += 8.0f;
    func_003D9508(pos, 57, 0x4FFFFFFF, 1, 0.25f, 0.0f, func_00382538());
    func_003D9508(pos, 11, 0x3FFF2040, 3, 0.3f, 0.01f, func_00382538());
    func_003D9508(pos, 57, 0x4FFFFFFF, 1, 0.27f, 0.0f, func_00382538());
    func_003D9508(pos, 11, 0x3FFF2040, 1, 0.35f, 0.01f, func_00382538());
}
