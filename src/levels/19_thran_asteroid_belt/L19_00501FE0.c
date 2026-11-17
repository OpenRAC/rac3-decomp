#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_00501FE0 */
extern u8 D_001A4BE0[];
typedef struct { f32 x68; u8 pad6C[0x80 - 0x6C]; u8 x80[1]; } S_501FE0;
extern S_501FE0 D_L19_001E8E68;
extern vu0_v4 D_L19_001E8E60;
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044A850(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L01_00511848(void *);
extern f32 func_L01_005114B0(void *);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);

f32 func_L19_00501FE0(f32 t, f32 g, f32 h) {
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 q;
    u8 *hero;
    u8 *h2;
    f32 b;

    hero = D_001A4BE0;
    switch (hero[0x25F4]) {
    case 0: {
        f32 r0, r1;
        if (h < 0.0f) {
            func_0038CE20(&p, hero + 0xF0, t);
            p.z -= (t * t + t) * 0.5f * g;
            vec_add_ba(&p, &p, hero + 0x80);
            d = *(vu0_v4 *)(hero + 0x80);
            func_L01_0044A850(&d, &p);
            d = *(vu0_v4 *)(hero + 0x80);
            if (func_003D3CB0(&d, &p, 0xD22, 0, 0) != 0 && func_L01_00511848(D_L19_001E8E68.x80) <= 0.87266463f) {
                h = D_L19_001E8E68.x68;
            }
        }
        if (0.0f < h) {
            h2 = D_001A4BE0;
            if (func_L01_004461B8(&r0, &r1, g * -0.5f, *(f32 *)(h2 + 0xF8) - g * -0.5f, *(f32 *)(h2 + 0x88) - h) > 0 && 0.0f < r0) {
                return r0;
            }
        }
        break;
    }
    case 1: {
        f32 r0, r1, a, c, z;
        d = *(vu0_v4 *)(hero + 0x2C0);
        func_0038CF68(&d, &d, g);
        func_0038CE20(&d, &d, -1.0f);
        func_0038CE20(&p, hero + 0xF0, t);
        func_0038CE20(&s, &d, (t * t + t) * 0.5f * g);
        vec_add_ba(&p, &s, &p);
        vec_add_ab(&p, hero + 0x80, &p);
        q = *(vu0_v4 *)(hero + 0x80);
        func_L01_0044A850(&q, &p);
        if (func_003D3CB0(hero + 0x80, &p, 0xD22, 0, 0) != 0) {
            a = g * -0.5f;
            b = func_L01_005114B0(hero + 0xF0) - a;
            z = func_L01_005114B0(hero + 0x80);
            c = z - func_L01_005114B0(&D_L19_001E8E60);
            if (func_L01_004461B8(&r0, &r1, a, b, c) > 0 && 0.0f < r0) {
                return r0;
            }
        }
        break;
    }
    case 2: {
        f32 r0, r1, a, c, z;
        s.x = s.y = s.z = 100.0f;
        vec_sub_ab(&d, hero + 0x80, &s);
        func_0038CF68(&d, &d, g);
        func_0038CE20(&d, &d, -1.0f);
        func_0038CE20(&p, hero + 0xF0, t);
        func_0038CE20(&s, &d, (t * t + t) * 0.5f * g);
        vec_add_ba(&p, &s, &p);
        vec_add_ab(&p, hero + 0x80, &p);
        q = *(vu0_v4 *)(hero + 0x80);
        func_L01_0044A850(&q, &p);
        if (func_003D3CB0(hero + 0x80, &p, 0xD22, 0, 0) != 0) {
            a = g * -0.5f;
            b = func_L01_005114B0(hero + 0xF0) - a;
            z = func_L01_005114B0(hero + 0x80);
            c = z - func_L01_005114B0(&D_L19_001E8E60);
            if (func_L01_004461B8(&r0, &r1, a, b, c) > 0 && 0.0f < r0) {
                return r0;
            }
        }
        break;
    }
    }
    return t;
}
/* localdecomp:end func_L19_00501FE0 */
