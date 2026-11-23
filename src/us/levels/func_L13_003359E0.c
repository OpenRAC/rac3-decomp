#include "common.h"

/* NTSC-U counterpart of func_L13_00336530 (src/levels/shared/L13_00336530.c) */
/* localdecomp:start func_L13_003359E0 */
#include "vu0.h"

typedef struct {
    vu0_v4 v0;      /* 0x00 */
    vu0_v4 v10;     /* 0x10 */
    vu0_v4 v20;     /* 0x20 */
    s32 timer;      /* 0x30 */
    s32 flags;      /* 0x34 */
    f32 f38;        /* 0x38 */
} V_00336530;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;     /* 0x10 */
    u8 state;       /* 0x20 */
    u8 pad21[2];
    u8 alpha;       /* 0x23 */
    u8 pad24[0x10];
    u16 flags;      /* 0x34 */
    u8 pad36[0x32];
    V_00336530 *vars; /* 0x68 */
    u8 pad6C[0x54];
    struct { vu0_v4 r[4]; } mtx; /* 0xC0 */
} M_00336530;

extern u8 D_L13_001D66B0_003359E0[] __attribute__((section(".sdata")));
extern vu0_v4 D_L13_001E8F40;
extern s32 func_00388398(void *);
extern void func_003888C8(void *, void *, void *);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern s32 func_L01_003F9498(void *, f32, s32, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388770(void *);
extern f32 func_00388730(void *, void *);
extern void func_L01_0040C260(void *, void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_003BF2F8(void *, void *, f32);
extern void func_003890F8(void *, void *);
extern void func_003BF360(void *, void *);
extern void func_003BD360(void *);
extern void func_L13_00429058(void *, void *, f32, f32, s32);
extern void func_L01_00447D00(void *, void *, void *, f32, f32, s32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32);

void func_L13_003359E0(M_00336530 *m) {
    V_00336530 *v = m->vars;
    vu0_v4 p;
    vu0_v4 rot[3];
    vu0_v4 q;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 mtx[4];
    vu0_v4 s;
    vu0_v4 axis;
    f32 r;
    f32 len;
    f32 dot;

    switch (m->state) {
    case 0:
        func_003BD360(m);
        return;
    case 1:
        if (func_00388398(&v->timer)) {
            m->state = 3;
            v->timer = 10;
            m->flags |= 0x2000;
            return;
        }
        break;
    case 2:
        func_003888C8(&p, &v->v20, &m->mtx);
        vec_add_ab(&p, &p, &m->pos);
        if (v->flags & 2) {
            func_L13_00429058(m, &p, 0.3f, 10.0f, -1);
        } else {
            func_L01_00447D00(m, D_L13_001D66B0_003359E0, &p, 0.0f, 0.0f, 5, 3, 5, -1, 1.0f, 0.5f, 9.0f, 0.333f, 0.0f, 0, 0, -1, 0, 0x1010001);
        }
        func_003BD360(m);
        return;
    case 3:
        if (func_00388398(&v->timer)) {
            func_003BD360(m);
            return;
        }
        m->alpha = (s32)(((f32)v->timer / 10.0f) * 128.0f);
        break;
    }

    func_00388BD0(rot, &v->v10);
    func_003888C8(&p, &v->v20, &m->mtx);
    func_00388EB8(&m->mtx, rot, &m->mtx);
    func_003888C8(&q, &v->v20, &m->mtx);
    vec_sub_ba(&d, &q, &p);
    vec_sub_ab(&m->pos, &m->pos, &d);
    vec_add_ba(&m->pos, &m->pos, &v->v0);
    r = v->v20.w;
    v->v0.z = v->v0.z - v->f38;
    func_003888C8(&t, &v->v20, &m->mtx);
    vec_add_ab(&t, &t, &m->pos);
    if (func_L01_003F9498(&t, r, 0, m)) {
        func_00388830(&D_L13_001E8F40, &D_L13_001E8F40, 1.0f);
        len = func_00388770(v);
        dot = func_00388730(v, &D_L13_001E8F40);
        if (dot < 0.0f) {
            func_L01_0040C260(v, v, &D_L13_001E8F40);
            func_00388830(&s, &D_L13_001E8F40, dot * 0.5f);
            vec_add_ba(v, v, &s);
            func_00388830(v, v, len);
            func_00388758(&axis, &D_L13_001E8F40, v);
            func_00388830(&axis, &axis, 1.0f);
            func_003BF2F8(&axis, &axis, func_00388770(&v->v10));
            func_003890F8(&axis, mtx);
            func_003BF360(mtx, &v->v10);
        }
    }
}
/* localdecomp:end func_L13_003359E0 */
