#include "common.h"

/* NTSC-U counterpart of func_L01_00470A28 (src/levels/shared/L01_00470A28.c) */
#include "vu0.h"
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

/* localdecomp:start func_L01_0046D330 */
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
extern s32 D_L01_001DFBC0_0046D330;
__asm__(".extern D_L01_001DFBC0_0046D330, 4");
extern s32 func_L01_00444338_0046D330(s32, s32, f32);
extern f32 func_0037E250(f32, f32), func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_003883C8(s16 *);
extern void func_003C7CE0(Obj *);

void func_L01_0046D330(Particle_470A28 *p)
{
    vu0_v4 old;
    vu0_v4 vec;
    Motion_470A28 *vel = &p->motion;
    vu0_v4 *pos;
    f32 length;

    if (func_003883C8(&p->life)) {
        func_003C7CE0((Obj *)p);
        return;
    }
    pos = &p->pos;
    p->color = func_L01_00444338_0046D330(vel->col1, vel->col0, (f32)p->life / (f32)vel->duration);
    vec_add_ab(&p->pos, &p->pos, vel);
    vel->z -= vel->w;
    old = p->pos;
    if (p->pos.w != 0.0f) {
        if (p->pos.w == 2.0f) {
            func_L01_004C6EC8(pos, pos);
        }
        p->pos.w = 2.0f;
    }
    if (vel->spark && (D_L01_001DFBC0_0046D330 & 1)) {
        vu0_v4 r = {0.0f, 0.0f, 0.0f, 0.0f};
        r.x = func_0037E250(-1.0f, 1.0f);
        r.y = func_0037E250(-1.0f, 1.0f);
        r.z = func_0037E250(-1.0f, 1.0f);
        vec = r;
        length = func_00388770(vel);
        func_00388830(&vec, &vec, length * func_0037E250(0.15f, 0.25f));
        vec_add_ba(&vec, &vec, vel);
        func_003886E8(&vec, &vec, func_0037E250(0.75f, 0.95f));
        func_L01_00462190(pos, &vec, p->color, vel->col1, func_0037E208(15, 30), 0,
                          p->c, p->d, (s32)p->pos.w, p->size);
    } else {
        func_003886E8(vel, vel, 0.96f);
    }
}
/* localdecomp:end func_L01_0046D330 */
