/* functional: high. Written from PAL asm (no draft): clamp of t (angle uses the unclamped read), up/side basis via cross products, 33-step spiral ribbon drawn as two GS passes per segment (retail's 41 jal targets in identical order, constants multiset identical to retail per check.py diff), a/b decay with reset to scale*2.25, 4 flares, 24 arcs with growing radius, phase wrap, 4 random-rolled sprites; sp+0x80/0x84 uv centre kept in locals cu/cv. Not run: coverage untested. */
#include "vu0.h"
typedef struct { vu0_v4 p[4]; u32 color[4]; f32 uv[4][2]; u8 pad[24]; unsigned long flags; } Packet_00376490;
typedef struct {
    u8 pad0[0x40]; f32 phase, radius; u8 pad48[0x20];
    f32 scale; u8 pad6c[4];
    f32 a, b, angle, angle2, t; u8 pad84[4]; f32 spin; u8 pad8c[0x14];
    vu0_v4 direction[24], result[24]; f32 angles[24];
} State_00376490;
extern vu0_v4 D_L01_001E2A40;
extern f32 D_001A4EC0[];
void func_L01_00376490(u8 *obj)
{
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CF68(f32, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D308(void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003A9440(s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_00389478(void *, f32 *, f32 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_L01_00376178(void *, s32, f32, f32, f32, f32);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
    vu0_v4 v0, dir, side, up, v40, v50, v60, v70, v80;
    Packet_00376490 pk;
    State_00376490 *s = *(State_00376490 **)(obj + 0x68);
    f32 t = s->t;
    f32 r, f23, ang, sn, cs, cu, cv;
    s32 i, j;

    if (1.0f < t) s->t = 1.0f;
    else if (t < 0.0f) s->t = 0.0f;
    r = func_0038D098(t * 3.14159274f);
    f23 = (1.0f - r) * 0.5f * 0.600000024f;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(dir) : "m"(*(vu0_v4 *)(obj + 0x10)), "m"(D_L01_001E2A40) : "vf1", "vf2");
    func_0038CF68(s->t + 0.5f, &dir, &dir);
    func_0038CF68(1.0f, &up, D_001A4EC0);
    func_0038CE90(&up, &dir, &up);
    func_0038CF68(s->t + 1.0f, &up, &up);
    func_0038CE90(&side, &up, &dir);
    func_0038CF68(s->t + 0.5f, &side, &side);
    func_0038CF68(-0.0500000007f, &v0, &up);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(v40) : "m"(*(vu0_v4 *)(obj + 0x10)), "m"(v0) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(v50) : "m"(v40), "m"(dir) : "vf1", "vf2");
    func_0038CE20(&v0, &dir, -0.0500000007f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(v40) : "m"(v40), "m"(dir) : "vf1", "vf2");
    ang = func_0038DAB8(s->spin, 0.0139626348f);
    s->spin = ang;
    for (i = 0; i < 33; i++) {
        v70 = v40;
        sn = func_0038D098(ang);
        cs = func_0038D0B0(ang);
        if (sn != 0.0f) {
            func_0038CE20(&v80, &up, sn);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(v70) : "m"(v70), "m"(v80) : "vf1", "vf2");
        }
        if (cs != 0.0f) {
            func_0038CE20(&v80, &side, cs);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(v70) : "m"(v70), "m"(v80) : "vf1", "vf2");
        }
        if (i != 0) {
            func_003D93B0(&pk, 0x4D, 1, 0x80);
            pk.flags = 0x800000004AUL;
            pk.p[0] = v60;
            pk.p[1] = v70;
            pk.p[3] = v50;
            pk.p[2] = v50;
            pk.color[3] = 0x80808080;
            pk.color[2] = 0x80808080;
            pk.color[1] = 0x80808080;
            pk.color[0] = 0x80808080;
            pk.uv[0][0] = 0.0f; pk.uv[0][1] = 0.0f;
            pk.uv[1][0] = 1.0f; pk.uv[1][1] = 0.0f;
            pk.uv[2][0] = 0.0f; pk.uv[2][1] = 1.0f;
            pk.uv[3][0] = 1.0f; pk.uv[3][1] = 1.0f;
            func_003A9440(0x47, 0x31001);
            func_003D2DA0(&pk, 0, 0);
            for (j = 0; j < 4; j++)
                func_00389478(&pk.p[j], &pk.uv[j][0], &pk.uv[j][1]);
            cu = (pk.uv[0][0] + pk.uv[1][0]) * 0.5f;
            cv = (pk.uv[0][1] + pk.uv[1][1]) * 0.5f;
            for (j = 2; j < 4; j++) {
                pk.uv[j][0] = pk.uv[j][0] + (cu - pk.uv[j][0]) * f23;
                pk.uv[j][1] = pk.uv[j][1] + (cv - pk.uv[j][1]) * f23;
            }
            func_003D93B0(&pk, -1, 1, 0x80);
            *(unsigned long *)pk.pad = 5;
            pk.flags = 0x2000000054UL;
            func_003A9440(0x47, 0x53001);
            func_003D2DA0(&pk, 0, 0);
            func_003A9440(0x47, 0x5360B);
        }
        v60 = v70;
        ang = func_0038DAB8(ang, 0.196349546f);
    }
    s->a -= 0.0399999991f;
    if (s->a <= 0.100000001f) s->a = s->scale * 2.25f;
    s->b -= 0.0250000004f;
    if (s->b <= 0.100000001f) s->b = s->scale * 2.25f;
    s->angle = func_0038DAB8(s->angle, 0.052359879f);
    s->angle2 = func_0038DAB8(s->angle, 0.0872664675f);
    func_L01_00376178(obj + 0x10, 0x36, s->a, 0.5f, s->angle, 0.800000012f);
    func_L01_00376178(obj + 0x10, 0x36, s->b, 0.5f, s->angle2, 0.800000012f);
    func_L01_00376178(obj + 0x10, 0x36, s->scale * 2.26999998f, 0.5f, -s->angle, 0.800000012f);
    func_L01_00376178(obj + 0x10, 0x36, s->scale * 2.26999998f, 0.5f, s->angle, 0.800000012f);
    for (j = 0; j < 24; j++) {
        f32 grow, lim;
        func_0038D890(&s->result[j], &s->result[j], &s->direction[j], s->angles[j]);
        grow = s->radius + 0.0299999993f;
        lim = s->scale * 3.0f;
        s->radius = grow;
        if (lim < grow) s->radius = lim;
        func_0038CF68(s->radius, &s->result[j], &s->result[j]);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(v70) : "m"(s->result[j]), "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
        v80 = *(vu0_v4 *)(obj + 0x10);
        func_L01_0040A8C0(&v70, &v80, 18, 1, 0x2020FF, 0x2020FF, 0x2FFF2020, 0x2FFF2020,
                          s->scale * 0.0799999982f, s->scale * 3.0f, s->phase);
    }
    s->phase -= func_003824E0(0.0250000004f, 0.0350000001f);
    if (s->phase <= -8.0f) s->phase += 8.0f;
    func_003D9508(obj + 0x10, 57, 0x4FFFFFFF, 1, s->scale * 0.25f * 1.29999995f, 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 11, 0x3FFF2040, 3, s->scale * 0.300000012f * 1.29999995f, 0.00999999978f, func_00382538());
    func_003D9508(obj + 0x10, 57, 0x4FFFFFFF, 1, s->scale * 0.270000011f * 1.29999995f, 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 11, 0x3FFF2040, 1, s->scale * 0.349999994f * 1.29999995f, 0.00999999978f, func_00382538());
}
