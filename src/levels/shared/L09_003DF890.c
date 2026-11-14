#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x10];
    f32 roll;       /* 0x10: grows by 1 degree a frame */
    u8 pad14[0x10];
    s32 tracer;     /* 0x24: draws the tracer */
    f32 flown;      /* 0x28: u */
} N60Draw_003DFF48;

typedef struct {
    f32 u;
    f32 v;
} UV_003DFD68;
typedef struct {
    vu0_v4 p[4];
    s32 c[4];
    UV_003DFD68 uv[4];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_003DFD68;

typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; vu0_v4 *vel; } M_003E0360;
typedef struct { u8 p0[1]; u8 b1; u8 p2[0xEE]; } T_003E0360;

INCLUDE_ASM("asm/levels", func_L09_003DF890);

INCLUDE_ASM("asm/levels", func_L09_003DF968);

/* localdecomp:start func_L09_003DFD68 */
#include "vu0.h"


extern u8 D_L09_001E2B00[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L09_003DFD68(u8 *a0) {
    vu0_v4 m[4];
    Q_003DFD68 q;
    vu0_v4 t;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 r1;
    f32 r2;
    s32 i;

    r1 = func_003824E0(0.45f, 0.7f);
    r2 = func_003824E0(4.0f, 4.5f);
    func_0038CF68(&m[0], s, 1.0f);
    vec_sub_ba(&m[1], &D_L09_001E2B00[0], a0 + 0x10);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], r1);
    func_0038CF68(&m[0], &m[0], r2);
    m[0].w = 0.0f;
    m[1].w = 0.0f;
    m[2].w = 0.0f;
    func_003D93B0(&q, 0x3F, 0, 0x80);
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&q.p[i]);
        q.p[i].x = i < 2 ? 0.0f : 1.0f;
        q.p[i].y = 0.0f;
        q.p[i].z = (i & 1) ? 1.0f : -1.0f;
        q.p[i].w = 1.0f;
        q.c[i] = 0x7FFFFFFF;
    }
    func_0038CF68(&t, s, -3.7f);
    vec_add_ba(&m[3], &t, a0 + 0x10);
    m[3].w = 1.0f;
    func_003D2DA0(&q, m, 0);
}
/* localdecomp:end func_L09_003DFD68 */

/* localdecomp:start func_L09_003DFF48 */
/* rac3 src/levels/shared/L01_0035BF48.c: func_L01_0035C8D0, matched on master */


extern f32 func_0038DAB8(f32 a, f32 b);
extern void func_003D9508(u8 *pos, s32 texture, u32 colour, s32 blend, f32 half, f32 push, f32 roll);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern void func_L09_003DFD68(u8 *bullet);

/* n60_bullet_draw: an N60 Storm bullet in flight, additive: three stars (57) rolling at -1.5,
   0.5 and 2.5 times its roll, two yellow flames (49) at +-0.5 times it, a glow (47) at a new
   roll each frame; with the tracer, it starts once the bullet has flown 2 u. */
void func_L09_003DFF48(u8 *bullet)
{
    N60Draw_003DFF48 *vars = *(N60Draw_003DFF48 **)(bullet + 0x68);
    u8 *pos;

    pos = bullet + 0x10;
    /* 1 degree a frame */
    vars->roll = func_0038DAB8(vars->roll, 0.017453292f);
    /* grey 0x7F at alpha 0x20 */
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, func_0038DAB8(-vars->roll * 1.5f, 0.0f));
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, vars->roll * 0.5f);
    func_003D9508(pos, 0x39, 0x207F7F7F, 1, 0.75f, 0.08f, func_0038DAB8(vars->roll * 2.5f, 0.0f));
    /* yellow (0xFF, 0xFF, 0) at alpha 0x10 */
    func_003D9508(pos, 0x31, 0x1000FFFF, 1, 0.5f, 0.08f, vars->roll * 0.5f);
    func_003D9508(pos, 0x31, 0x1000FFFF, 1, 0.5f, 0.08f, vars->roll * -0.5f);
    /* grey at alpha 0x50 */
    func_003D9508(pos, 0x2F, 0x507F7F7F, 1, 0.2f, 0.08f, func_00382538());
    if (vars->tracer != 0) {
        vars->flown += func_0038CEA8(vars);
        if (vars->flown > 2.0f) {
            func_L09_003DFD68(bullet);
        }
    }
}
/* localdecomp:end func_L09_003DFF48 */

/* localdecomp:start func_L09_003E0140 */
#include "vu0.h"

extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 D_L09_001E2B00[];

void func_L09_003E0140(f32 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 angle;
    f32 r;
    f32 p;
    f32 t;
    s32 n;
    s32 i;
    f32 size;

    vec_sub_ab(d, D_L09_001E2B00, a0);
    angle = func_0038D160(d[0], d[1]);
    for (i = 0; i < 8; i++) {
        r = func_003824E0(0.5f, 1.0f);
        n = func_L01_00443A18(1.0f, 2.0f);
        size = func_003824E0(0.05f, 0.2f) * 210000.0f;
        p = func_003824E0(0.0f, 1.3962634f);
        t = func_0038DAB8(angle, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(vel, 0.1f * 0.2f * r, t, p);
        pos[0] = a0[0] + func_L01_00443A18(0.0f, 0.1f);
        pos[1] = a0[1] + func_L01_00443A18(0.0f, 0.1f);
        pos[2] = a0[2] + func_L01_00443A18(0.0f, 0.1f);
        func_L01_0046A610(pos, vel, 25, 127, 0x7F7F7F, n, func_003824E0(0.05f, 0.2f) * 210000.0f, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
/* localdecomp:end func_L09_003E0140 */

/* localdecomp:start func_L09_003E0360 */
#include "vu0.h"

extern f32 D_L09_001DF074;
__asm__(".extern D_L09_001DF074, 4");
extern u8 D_001425C0[];
extern T_003E0360 D_L09_002C5E40[];
extern u8 *D_L09_00220018[];
extern u8 *D_L09_002200EC[];
extern u8 D_001A4EC0[];
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, s32, f32, f32);
extern s32 func_00382468(s32);
extern void func_003C4C18(f32 *, f32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
void func_L09_003E0360(M_003E0360 *m, vu0_v4 *pa, vu0_v4 *pb) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v30;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 v60;
    vu0_v4 *vel;
    f32 len;
    f32 sc;
    s32 n;
    s32 i;
    sc = D_L09_001DF074 * 210000.0f;
    a = *pa;
    vel = m->vel;
    b = *pb;
    len = func_0038CEA8(vel);
    n = (s32)(len / 0.1f);
    c = b;
    vec_sub_ab(&d, &a, &b);
    func_0038CF68(&d, &d, len / (f32)n);
    for (i = 0; i < 10; i++) {
        s32 life = (s32)func_L01_00443A18(1.0f, 3.0f);
        s32 r;
        s32 size;
        s32 color;
        u8 *p;
        u8 v;
        T_003E0360 *e;
        T_003E0360 *e2;
        f32 s = func_003824E0(0.1f, 0.3f) * 0.020000001f;
        func_0038CE20(&v30, D_001A4EC0, -s);
        r = func_00382498(6, 0xC);
        if (func_0013D3E0() & 2) {
            size = 0x40;
            color = 0x306FFF;
            e = &D_L09_002C5E40[D_001425C0[0x2F]];
            if (e->b1 == 0) color = 0xFFFF;
        } else {
            size = 0x60;
            color = 0x2020FF;
            e2 = &D_L09_002C5E40[D_001425C0[0x2F]];
            if (e2->b1 == 0) color = 0x207F7F;
        }
        p = func_L01_004713C8(&c, &v30, (r * 5 + 2) / 6, color, life, size, 0, sc, 0, sc * 0.05f, 0.0f);
        vec_add_ab(&c, &c, &d);
        if (p != 0) {
            if (func_00382468(2))
                p[2] = D_L09_00220018[0x184 / 4][4];
            else
                p[2] = D_L09_00220018[0x184 / 4][5];
            p[3] = (size == 0x40) ? 0x48 : 0x44;
        }
    }
    {
        s32 color;
        s32 x;
        u8 *p;
        func_0038CE20(&v60, vel, -0.040000003f);
        color = 0x7F80DFFF;
        func_003C4C18(&v60.x, 0.120000005f);
        v60.z += 0.060000002f;
        if (func_00382468(2)) color = 0x7F407FFF;
        x = func_00382498(8, 0x11);
        p = func_L01_00465738(&m->pos, &v60, color, 0xFF, x, 0, -1, -1, 0, 94500.0f);
        if (p != 0) {
            *(f32 *)(p + 0x2C) = 0.0024f;
            p[2] = *D_L09_002200EC[0];
        }
    }
}
/* localdecomp:end func_L09_003E0360 */
