#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L19_003B8260.c, which this file was cut from */
extern s32 D_L19_001DF240;

/* localdecomp:start func_L19_003B8310 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B8310;
typedef struct {
    V4_003B8310 v0;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[4];
    s32 w20;
    u8 pad24[0xC];
} H_003B8310;
typedef struct M_003B8310 M_003B8310;
typedef struct {
    u8 pad0[0x10];
    V4_003B8310 v10;
    M_003B8310 *w20;
    s32 w24;
    void *w28;
    s32 w2C;
} P_003B8310;
struct M_003B8310 {
    u8 pad0[0x10];
    V4_003B8310 pos;
    u8 pad20[0x48];
    P_003B8310 *p68;
    u8 pad6C[0x3E];
    u16 hAA;
};

extern V4_003B8310 D_L19_001E8E60;
extern s32 D_L19_001DF240;
__asm__(".extern D_L19_001DF240, 16");
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L19_003B86E8(void *);

void func_L19_003B8310(M_003B8310 *m) {
    P_003B8310 *pv = m->p68;
    V4_003B8310 d;
    V4_003B8310 e;
    H_003B8310 h;

    switch (pv->w2C) {
    case 0:
        break;
    case 1:
        vec_sub_ba(&d, &pv->w20->pos, &m->pos);
        func_0038CE20(&d, &d, 1.1f);
        vec_add_ba(&e, &m->pos, &d);
        e.z += 0.3f;
        vec_sub_ba(&d, &e, &m->pos);
        func_0038CF68(&pv->v10, &d, func_0038CEA8(&pv->v10));
        break;
    case 2:
        vec_sub_ab(&d, &m->pos, &pv->w20->pos);
        d.z = 0.0f;
        func_0038CF68(&d, &d, 1.0f);
        vec_add_ba(&e, &pv->w20->pos, &d);
        vec_sub_ba(&d, &e, &m->pos);
        func_0038CF68(&pv->v10, &d, func_0038CEA8(&pv->v10));
        break;
    }
    *(vu0_q *)&d = *(vu0_q *)&m->pos;
    vec_add_ab(&e, &d, &pv->v10);
    func_L01_00446748(&h, m, 0x10001, 10.0f);
    h.b18 = 1;
    h.b19 = 1;
    h.h1A = m->hAA;
    h.w20 = 1;
    func_0038CF68(&h, &pv->v10, 1.0f);
    if (func_003D3CB0(&d, &e, 0, pv->w28, &h) != 0 || func_003D4D00(&e, 0, 0.2f, pv->w28, &h) != 0) {
        *(vu0_q *)&m->pos = *(vu0_q *)&D_L19_001E8E60;
        func_L01_0044AF78(m, &pv->v10, 0, 0.0f, 0.0f, 1, 1, 3, 0.0f, 0.0f, 9.0f, 0.3f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
        func_003C2880(m);
    } else {
        *(vu0_q *)&m->pos = *(vu0_q *)&e;
        if (pv->w24 < D_L19_001DF240
            || m->pos.x < 2.0f || 1021.0f < m->pos.x
            || m->pos.y < 2.0f || 1021.0f < m->pos.y
            || m->pos.z < 2.0f || 1021.0f < m->pos.z) {
            func_L01_0044AF78(m, &pv->v10, 0, 0.0f, 0.0f, 1, 1, 3, 0.0f, 0.0f, 9.0f, 0.3f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
            func_003C2880(m);
        } else {
            func_L01_00404808(func_L19_003B86E8, m);
        }
    }
}
/* localdecomp:end func_L19_003B8310 */
