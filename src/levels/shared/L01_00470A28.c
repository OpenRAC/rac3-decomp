#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct {
    f32 unk00;
    f32 unk04;
    s32 unk08;
    f32 unk0C;
    f32 unk10;
    s32 unk14;
} S_467288_Sub;
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_467288_Sub sub;
} S_467288;
typedef int s128_467510 __attribute__((mode(TI)));
typedef struct {
    s128_467510 q0;
    f32 f10;
    f32 f14;
    int f18;
} P_467510;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 pos[3];
    s32 unk0C;
    f32 off[3];
    s32 unk1C;
} S_468DC0_Sub;
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_468DC0_Sub sub;
} S_468DC0;
typedef int u128_469BA0 __attribute__((mode(TI)));
typedef struct {
    f32 f0;
    f32 f4;
    s32 x8;
    f32 fC;
    f32 f10;
} Q_469BA0;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_469BA0 v10;
    Q_469BA0 q;
} P_469BA0;
typedef struct {
    f32 v[3];
    s32 x0C;
    f32 x10;
    f32 x14;
    s16 x18;
    s16 x1A;
    s16 x1C;
} S_469D90_Q;
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    s32 x4;
    u8 x8;
    u8 x9;
    s16 xA;
    f32 xC;
    s128 x10;
    S_469D90_Q q;
} S_469D90;
typedef struct {
    f32 *p;
    f32 radius;
    f32 angle;
    f32 speed;
    f32 rise;
    u8 step;
} Orbit_0046E408;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[3];
    f32 f12;
    f32 f16;
    f32 pad20;
    f32 f24;
    f32 pad28;
    Orbit_0046E408 o;
} Obj_0046E408;

/* localdecomp:start func_L01_00470A28 */
typedef struct Motion_470A28 {
    f32 x, y, z, w;
    s32 col0, col1;
    s16 duration, spark;
} Motion_470A28;
typedef struct Particle_470A28 {
    u8 a, b, c, d;
    s32 color;
    s16 x, life;
    f32 size;
    vu0_v4 pos;
    Motion_470A28 motion;
} Particle_470A28;
extern s32 D_L01_001DFB40_00470A28;
__asm__(".extern D_L01_001DFB40_00470A28, 4");
extern s32 func_L01_00447470_00470A28(s32, s32, f32);
extern f32 func_003824E0(f32, f32), func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);

void func_L01_00470A28(Particle_470A28 *p)
{
    vu0_v4 old;
    vu0_v4 vec;
    Motion_470A28 *vel = &p->motion;
    vu0_v4 *pos;
    f32 length;

    if (func_0038CB00(&p->life)) {
        func_003CD250((Obj *)p);
        return;
    }
    pos = &p->pos;
    p->color = func_L01_00447470_00470A28(vel->col1, vel->col0, (f32)p->life / (f32)vel->duration);
    vec_add_ab(&p->pos, &p->pos, vel);
    vel->z -= vel->w;
    old = p->pos;
    if (p->pos.w != 0.0f) {
        if (p->pos.w == 2.0f) {
            func_L01_004CAB30(pos, pos);
        }
        p->pos.w = 2.0f;
    }
    if (vel->spark && (D_L01_001DFB40_00470A28 & 1)) {
        vu0_v4 r = {0.0f, 0.0f, 0.0f, 0.0f};
        r.x = func_003824E0(-1.0f, 1.0f);
        r.y = func_003824E0(-1.0f, 1.0f);
        r.z = func_003824E0(-1.0f, 1.0f);
        vec = r;
        length = func_0038CEA8(vel);
        func_0038CF68(&vec, &vec, length * func_003824E0(0.15f, 0.25f));
        vec_add_ba(&vec, &vec, vel);
        func_0038CE20(&vec, &vec, func_003824E0(0.75f, 0.95f));
        func_L01_00465738(pos, &vec, p->color, vel->col1, (func_00382498(15, 30) * 5 + 2) / 6, 0,
                          p->c, p->d, (s32)p->pos.w, p->size);
    } else {
        func_0038CE20(vel, vel, 0.96f);
    }
}
/* localdecomp:end func_L01_00470A28 */
