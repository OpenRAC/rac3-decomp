#include "common.h"

/* NTSC-U counterpart of func_L03_003AF848 (src/levels/03_starship_phoenix/L03_003AF848.c) */
/* localdecomp:start func_L03_003ADEE8 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
typedef struct { u8 pad0[0x64]; f32 f64; f32 f68; u8 pad6C[0x80 - 0x6C]; u8 j80[0xE8 - 0x80]; f32 fE8; u8 padEC[0x100 - 0xEC]; vu0_v4 v100; u8 pad110[4]; s32 f114; s32 f118; u8 pad11C[0x144 - 0x11C]; s32 f144; } P_003AF848;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x42 - 0x20]; u8 f42; u8 pad43[0x68 - 0x43]; P_003AF848 *f68; u8 pad6C[0xF8 - 0x6C]; f32 fF8; } M_003AF848;
f32 func_00388800(void *, void *);
f32 func_00388A28(f32, f32);
f32 func_00389468(f32, f32);
f32 func_00388770(void *);
void func_00388398();
f32 func_0037E250(f32, f32);
f32 func_00389380(f32, f32);
f32 func_003893C8(f32, f32);
f32 func_003887A0(void *);
void func_0037E4B8(void *, f32, f32, f32);
void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L03_003ADEE8(void *self) {
    M_003AF848 *a = (M_003AF848 *)self;
    P_003AF848 *p = a->f68;
    vu0_v4 d;
    vu0_q qa, qb;
    vu0_v4 tgt;
    vu0_v4 pos;
    f32 pitch, yaw, r, e;
    f32 s1 = 0.02f;
    f32 s2 = 0.3f;

    if (a->f42 == 1) {
        pitch = 0.0f;
        yaw = pitch;
    } else {
        if (p->f144 != 0) {
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(a->pos));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(p->v100));
        } else {
            if (func_00388800(&a->pos, &D_001A4BE0.pos) < 8.0f &&
                func_00389468(a->fF8, func_00388A28(D_001A4BE0.pickup_point.x - a->pos.x, D_001A4BE0.pickup_point.y - a->pos.y)) < 1.5707964f) {
                if (0.01f < func_00388770(&D_001A4BE0.vel)) {
                    p->f114 = 120;
                } else {
                    func_00388398(&p->f114);
                }
            } else if (p->f114 != 0) {
                p->f114 = 0;
                p->v100 = *(vu0_v4 *)&D_001A4BE0.pickup_point;
            }
            if (((s32 (*)(s32 *))func_00388398)(&p->f118)) {
                p->f118 = func_0037E250(180.0f, 300.0f);
                r = func_00389380(a->fF8, func_0037E250(-90.0f, 90.0f) * 0.017453292f);
                e = func_0037E250(0.0f, 30.0f) * 0.017453292f;
                func_0037E4B8(&p->v100, 6.0f, r, e);
                vec_add_ab(&p->v100, &p->v100, &a->pos);
            }
            if (p->f114 != 0) {
                s1 = 0.04f;
                s2 = 0.3f;
                tgt = *(vu0_v4 *)&D_001A4BE0.pickup_point;
            } else {
                tgt = p->v100;
            }
            pos = a->pos;
            pos.z += 2.0f;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(tgt));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(pos));
        }
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
        yaw = func_003893C8(func_00388A28(d.x, d.y), a->fF8);
        pitch = -func_00388A28(func_003887A0(&d), d.z);
    }
    if (yaw > 1.2217305f) {
        yaw = 1.2217305f;
    } else if (yaw < -1.2217305f) {
        yaw = -1.2217305f;
    }
    if (pitch > 0.08726646f) {
        pitch = 0.08726646f;
    } else if (pitch < -0.5235988f) {
        pitch = -0.5235988f;
    }
    p->f68 = yaw * 0.8f;
    p->fE8 = yaw * 0.2f;
    p->f64 = pitch;
    func_L01_0044B5C8(a, p, 0, s1, s2);
    func_L01_0044B5C8(a, p->j80, 1, s1, s2);
}
/* localdecomp:end func_L03_003ADEE8 */
