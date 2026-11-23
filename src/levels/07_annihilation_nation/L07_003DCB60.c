#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3DCFF8;
extern V_3DCFF8 D_L07_001E1E40;

/* localdecomp:start func_L07_003DCB60 */
typedef union { vu0_q q; f32 f[4]; } RibbonVector_3DCB60;
typedef struct {
    RibbonVector_3DCB60 points[4];
    s32 colors[4];
    f32 uv[4][2];
    unsigned long alpha, texture, state, clamp;
} RibbonPacket_3DCB60;

extern long func_00389598(s32);
extern void func_L07_003DCAD8(void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L07_003DCB60(RibbonVector_3DCB60 *points, s32 pointCount, s32 blend, s32 primaryColor, s32 secondaryColor,
                       s32 unused, f32 width, f32 widthRatio)
{
    RibbonVector_3DCB60 matrix[4];
    RibbonPacket_3DCB60 primary;
    RibbonPacket_3DCB60 secondary;
    RibbonVector_3DCB60 primaryWidth, secondaryWidth;
    s32 i;
    f32 u, nextU;

    primary.texture = func_00389598(0x2B);
    primary.state = 0xFF9000000260UL;
    primary.clamp = ((unsigned long)blend << 32) | 0x68;
    primary.colors[3] = primaryColor;
    primary.colors[2] = primaryColor;
    primary.colors[1] = primaryColor;
    primary.colors[0] = primaryColor;
    primary.alpha = 0;
    func_L07_003DCAD8(&primary);
    primary.uv[0][0] = 0.0f;
    primary.uv[0][1] = 0.0f;
    primary.uv[1][0] = 0.0f;
    primary.uv[1][1] = 1.0f;
    primary.uv[2][0] = 1.0f;
    primary.uv[2][1] = 0.0f;
    primary.uv[3][0] = 1.0f;
    primary.uv[3][1] = 1.0f;
    secondary.texture = func_00389598(0x2B);
    secondary.state = 0xFF9000000260UL;
    secondary.colors[3] = secondaryColor;
    secondary.colors[2] = secondaryColor;
    secondary.colors[1] = secondaryColor;
    secondary.colors[0] = secondaryColor;
    secondary.alpha = 0;
    secondary.clamp = ((unsigned long)(blend / 3) << 32) | 0x68;
    func_L07_003DCAD8(&secondary);
    primaryWidth.q = 0;
    secondaryWidth.q = 0;
    secondary.uv[0][0] = 0.0f;
    secondary.uv[0][1] = 0.0f;
    secondary.uv[1][0] = 0.0f;
    secondary.uv[1][1] = 1.0f;
    secondary.uv[2][0] = 0.33f;
    secondary.uv[2][1] = 0.0f;
    secondary.uv[3][0] = 0.33f;
    secondary.uv[3][1] = 1.0f;
    primaryWidth.f[3] = 1.0f;
    secondaryWidth.f[3] = 1.0f;
    primaryWidth.f[2] = width;
    secondaryWidth.f[2] = width * widthRatio;
    vec_sub_ba(&matrix[0], points + 1, points);
    func_0038CF68(&matrix[0], &matrix[0], 1.0f);
    vec_sub_ba(&matrix[1], &D_L07_001E1E40, points);
    func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
    func_0038CF68(&matrix[2], &matrix[2], 1.0f);
    func_0038CE90(&matrix[1], &matrix[0], &matrix[2]);
    primary.points[0].q = primaryWidth.q;
    matrix[3].q = points[0].q;
    func_0038CE20(primary.points[1].f, &primary.points[0], -1.0f);
    func_0038D028(&primary.points[0], &primary.points[0], &matrix[0]);
    func_0038D028(&primary.points[1], &primary.points[1], &matrix[0]);
    secondary.points[0].q = secondaryWidth.q;
    func_0038CE20(secondary.points[1].f, &secondary.points[0], -1.0f);
    func_0038D028(&secondary.points[0], &secondary.points[0], &matrix[0]);
    func_0038D028(&secondary.points[1], &secondary.points[1], &matrix[0]);

    for (i = 1; i < pointCount; i++) {
        primary.points[2].q = primaryWidth.q;
        func_0038CE20(primary.points[3].f, &primary.points[2], -1.0f);
        secondary.points[2].q = secondaryWidth.q;
        func_0038CE20(secondary.points[3].f, &secondary.points[2], -1.0f);
        vec_sub_ab(&matrix[0], points + i + 1, points + i);
        func_0038CF68(&matrix[0], &matrix[0], 1.0f);
        vec_sub_ab(&matrix[1], &D_L07_001E1E40, points + i);
        func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
        func_0038CF68(&matrix[2], &matrix[2], 1.0f);
        func_0038CE90(&matrix[1], &matrix[0], &matrix[2]);
        matrix[3].q = points[i].q;
        func_0038D028(&primary.points[2], &primary.points[2], &matrix[0]);
        func_0038D028(&primary.points[3], &primary.points[3], &matrix[0]);
        func_0038D028(&secondary.points[2], &secondary.points[2], &matrix[0]);
        func_0038D028(&secondary.points[3], &secondary.points[3], &matrix[0]);
        if (i == pointCount - 1) {
            primary.colors[2] = 0;
            primary.colors[3] = 0;
            secondary.colors[2] = 0;
            secondary.colors[3] = 0;
        }
        primary.texture = func_00389598(0x47);
        primary.clamp = ((unsigned long)blend << 32) | 0x68;
        primary.texture = func_00389598(0x2B);
        func_003D2DA0(&primary, 0, 0);
        func_003D2DA0(&secondary, 0, 0);
        u = i * 0.33f;
        nextU = u + 0.33f;
        if (u >= 1.0f) {
            u -= 1.0f;
            nextU -= 1.0f;
        }
        secondary.uv[0][0] = u;
        secondary.uv[2][0] = nextU;
        secondary.uv[1][0] = u;
        secondary.uv[3][0] = nextU;
        primary.points[0].q = primary.points[2].q;
        primary.points[1].q = primary.points[3].q;
        secondary.points[0].q = secondary.points[2].q;
        secondary.points[1].q = secondary.points[3].q;
    }
}
/* localdecomp:end func_L07_003DCB60 */

/* localdecomp:start func_L07_003DCFF8 */
#include "vu0.h"
typedef struct { f32 u, v; } UV_3DCFF8;
typedef struct { V_3DCFF8 p[4]; s32 c[4]; UV_3DCFF8 uv[4]; } Q_3DCFF8;
__asm__(".extern D_L07_001DE958, 4");
__asm__(".extern D_L07_001DE948, 4");
__asm__(".extern D_L07_001DE94C, 4");
__asm__(".extern D_L07_001DE950, 4");
__asm__(".extern D_L07_001DE954, 4");
extern s32 D_L07_001DE958;
extern s32 D_L07_001DE948;
extern s32 D_L07_001DE94C;
extern f32 D_L07_001DE950;
extern f32 D_L07_001DE954;
extern void func_003D93B0(void *, s32, s32, s32);

static __inline__ V_3DCFF8 vsub_3DCFF8(V_3DCFF8 *a, V_3DCFF8 *b) {
    V_3DCFF8 r;
    vec_sub_ba(&r, a, b);
    return r;
}

static __inline__ V_3DCFF8 vadd_3DCFF8(V_3DCFF8 *a, V_3DCFF8 *b) {
    V_3DCFF8 r;
    vec_add_ba(&r, a, b);
    return r;
}

void func_L07_003DCFF8(void *obj, void *pa, void *pb) {
    V_3DCFF8 a = *(V_3DCFF8 *)pa;
    V_3DCFF8 b = *(V_3DCFF8 *)pb;
    Q_3DCFF8 q;
    char buf[32];
    V_3DCFF8 e;
    V_3DCFF8 f;
    V_3DCFF8 d;
    V_3DCFF8 *ap = &a;
    V_3DCFF8 *bp = &b;
    u8 *s = *(u8 **)((u8 *)obj + 0x68);
    s32 c;
    s32 i;

    func_003D93B0(&q, D_L07_001DE958, 1, 0x80);
    c = D_L07_001DE948;
    q.c[3] = c;
    q.c[2] = c;
    q.c[1] = c;
    q.c[0] = c;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= *(f32 *)(s + 0x120);
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, ap, bp);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, ap, &D_L07_001E1E40);
    vec_sub_ba(&f, bp, &D_L07_001E1E40);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L07_001DE950);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L07_001DE954);
    {
        q.p[0] = vsub_3DCFF8(ap, &e);
    }
    {
        q.p[1] = vadd_3DCFF8(ap, &e);
    }
    {
        q.p[2] = vsub_3DCFF8(bp, &f);
    }
    {
        q.p[3] = vadd_3DCFF8(bp, &f);
    }
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, 1, 0x80);
    c = D_L07_001DE94C;
    q.c[3] = c;
    q.c[2] = c;
    q.c[1] = c;
    q.c[0] = c;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= *(f32 *)(s + 0x120);
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, ap, bp);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, ap, &D_L07_001E1E40);
    vec_sub_ba(&f, bp, &D_L07_001E1E40);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L07_001DE950 * 0.5f);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L07_001DE954 * 0.5f);
    {
        q.p[0] = vsub_3DCFF8(ap, &e);
    }
    {
        q.p[1] = vadd_3DCFF8(ap, &e);
    }
    {
        q.p[2] = vsub_3DCFF8(bp, &f);
    }
    {
        q.p[3] = vadd_3DCFF8(bp, &f);
    }
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L07_003DCFF8 */

/* localdecomp:start func_L07_003DD3C8 */
typedef struct O_3DD3C8 O_3DD3C8;
typedef struct {
    u8 pad0[8];
    u8 state;
    u8 pad9[0x17];
    u8 f20[0x30];
    u8 f50[0x10];
    O_3DD3C8 *child;
    f32 progress;
} V_3DD3C8;

struct O_3DD3C8 {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x47];
    V_3DD3C8 *vars;
    u8 pad6C[0x84];
    f32 rot;
};

extern void func_L07_003DD5D8();
extern s32 func_L01_004561B8(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038D688(void *, void *, void *);
extern void func_L07_003DD750();
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);

void func_L07_003DD3C8(void *arg)
{
    O_3DD3C8 *m = arg;
    V_3DD3C8 *v;
    f32 r;

    func_L07_003DD5D8(m);
    v = m->vars;
    switch (m->state) {
    case 0:
        break;
    case 1:
        if (v->state == 2) func_L01_004450F0(m, 4, -1);
        break;
    case 2:
        if (func_L01_004561B8(m)) func_003A52A0(1, 4, m);
        func_0038D688(v->f20, v->f20, v->f50);
        func_L07_003DD750(m);
        if (v->state == 1) {
            func_L01_004AA760(1, m);
            func_L01_004450F0(m, 5, -1);
        }
        break;
    case 3:
        break;
    case 4:
        if (func_L01_004561B8(m)) func_003A52A0(0, 4, m);
        v->progress += 0.012f;
        if (v->progress >= 1.0f) {
            v->progress = 1.0f;
            func_L01_004AA760(0, m);
            func_L01_004450F0(m, 2, -1);
        }
        r = func_003C3BE8(3.1415927f, 0.0f, v->progress);
        m->rot = r;
        v->child->rot = r;
        func_003C7C38(v->child);
        break;
    case 5:
        if (func_L01_004561B8(m)) func_003A52A0(0, 4, m);
        v->progress -= 0.012f;
        if (v->progress <= 0.0f) {
            v->progress = 0.0f;
            func_L01_004AA760(0, m);
            func_L01_004450F0(m, 1, -1);
        }
        r = func_003C3BE8(3.1415927f, 0.0f, v->progress);
        m->rot = r;
        v->child->rot = r;
        func_003C7C38(v->child);
        break;
    }
}
/* localdecomp:end func_L07_003DD3C8 */

/* localdecomp:start func_L07_003DD5D8 */
#include "vu0.h"
typedef struct {
    u8 pad[0x24];
    f32 scale;
} Class_3DD5D8;

typedef struct Obj_3DD5D8 {
    u8 p0[0x10];
    vu0_q pos;
    u8 state;
    u8 p21[3];
    Class_3DD5D8 *cls;
    u8 p28[4];
    f32 scale;
    u8 b30, b31;
    u16 h32;
    u8 p34[4];
    unsigned long flags38;
    u8 p40[0x28];
    void *vars;
    u8 p6C[0x84];
    vu0_q rot;
} Obj_3DD5D8;

typedef struct {
    void *f0;
    void (*cb)(void *);
    u8 p8[8];
    u8 f10[0x40];
    u8 f50[0x10];
    Obj_3DD5D8 *child;
} Vars_3DD5D8;

extern Obj_3DD5D8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern void func_0038D750(void *, s32, f32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L07_003DD6D8();

void func_L07_003DD5D8(Obj_3DD5D8 *m)
{
    Vars_3DD5D8 *v;
    Obj_3DD5D8 *o;

    if (m->state != 0) return;
    v = m->vars;
    o = func_003C24B0(0x1D2D, 0x80);
    if (o) {
        o->b31 = 1;
        o->h32 = m->h32;
        o->b30 = m->b30;
        o->flags38 = m->flags38;
        o->scale = o->cls->scale * 1.1f;
        o->pos = m->pos;
        o->rot = m->rot;
        func_003C7C38(o);
    }
    v->child = o;
    func_0038D750(v->f50, 2, -0.1466076672f);
    func_0038CB78(v->f10, 0, 0x40);
    func_L01_0043A430(m, 0, v->f10);
    v->cb = func_L07_003DD6D8;
    func_L07_003DD6D8(m);
}
/* localdecomp:end func_L07_003DD5D8 */

/* localdecomp:start func_L07_003DD6D8 */
typedef struct {
    u8 pad_0[8];
    u8 x8;              /* 0x8 */
    u8 pad_9[0x60 - 0x9];
    void *x60;          /* 0x60 */
    f32 x64;            /* 0x64 */
} S_3DD6D8_OBJ;

typedef struct {
    u8 pad_0[0x68];
    S_3DD6D8_OBJ *obj;  /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 xF0;            /* 0xF0 */
} S_3DD6D8;

typedef struct {
    u8 pad_0[0xF0];
    f32 xF0;            /* 0xF0 */
} S_3DD6D8_XF0;

extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003DD6D8(S_3DD6D8 *arg0)
{
    S_3DD6D8_OBJ *o = arg0->obj;
    f32 v;

    o->x64 = 0;
    v = func_003C3BE8(3.1415927f, o->x64, o->x64);
    arg0->xF0 = v;
    ((S_3DD6D8_XF0 *)o->x60)->xF0 = v;
    func_003C7C38(o->x60);
    o->x8 = 1;
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003DD6D8 */

/* localdecomp:start func_L07_003DD750 */
/* Vec4f, declared locally: the owning source file includes only common.h. */
typedef struct {
    f32 x, y, z, w;
} V4_3DD750;

typedef struct {
    u8 pad_0[0x10];
    V4_3DD750 v10;      /* 0x10 */
} S_3DD750;

typedef struct {
    u8 pad_0[0x80];
    V4_3DD750 pos;      /* 0x80 */
    u8 pad_90[0x25C0 - 0x90];
    void *moby;         /* 0x25C0 */
} S_3DD750_HERO;

extern S_3DD750_HERO D_001A4BE0;
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern f32 D_001DA978;
extern f32 D_002F3630[];
extern u8 D_L07_001D66B0[8];

extern f32 func_L01_0040E570(void *a, void *b);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446A70(void *a, void *b, s32 c, void *d, void *e, f32 f);

void func_L07_003DD750(S_3DD750 *arg0)
{
    S_3DD750_HERO *h = &D_001A4BE0;

    if (fabsf(arg0->v10.z - h->pos.z) < 0.5f) {
        if (func_L01_0040E570(&arg0->v10, &h->pos) <= 4.0f) {
            f32 v;
            if (func_L01_0041A4F0()) {
                s32 id = D_001D545C;
                if (id == 7 && D_0014275B[0] != 0) v = D_001DA978;
                else v = D_002F3630[id];
            } else {
                v = 1.0f;
            }
            func_L01_00446A70(h->moby, arg0, 1, D_L07_001D66B0,
                          D_L07_001D66B0, v);
        }
    }
}
/* localdecomp:end func_L07_003DD750 */

/* localdecomp:start func_L07_003DD838 */
extern f32 D_L07_001DE960;
extern f32 D_L07_001DE970;
extern void *D_001DE968_sda;
extern s32 D_L07_001DE96C;
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DE960, 4");
__asm__(".extern D_L07_001DE970, 4");
__asm__(".extern D_001DE968_sda, 4");
__asm__(".extern D_L07_001DE96C, 4");
__asm__(".extern D_L07_001DF41C, 16");
void func_L07_003DD838(u8 *obj) {
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_L01_004561B8(void *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_004AA760(s32, void *);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern f32 func_0038DB48(f32);
    extern void *func_0038DBD8(void *, s32, f32);
    u8 *v = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        *(void **)(obj + 0x78) = D_001DE968_sda;
        *(u16 *)(obj + 0x34) |= 0x10;
        func_L01_004450F0(obj, 1, -1);
    }
    switch (obj[0x20]) {
    case 2:
        if (obj[0xBE] & 4) func_L01_004450F0(obj, 3, -1);
        break;
    case 3:
        if (func_L01_004561B8(obj)) func_L01_004AAC98(0, 0x114, obj, 0x1D6B);
        *(f32 *)(v + 0x10) += D_L07_001DE960 * 1.2f;
        if (*(f32 *)(v + 0x10) >= 1.0f) {
            *(f32 *)(v + 0x10) = 1.0f;
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 4, -1);
        }
        *(f32 *)(obj + 0xF0) = func_0038DB48(func_003C3BE8(0.0f, *(f32 *)(v + 0x18), *(f32 *)(v + 0x10)));
        break;
    case 4: {
        s32 index;
        u8 *m;
        m = D_L07_001DF41C + ((*(u8 *)((s32)v + v[0x1C] + 8) == 1 ? *(s32 *)v : *(s32 *)(v + 4)) << 8);
        m[0xBE] |= 4;
        *(f32 *)(v + 0x14) = 0.0f;
        func_L01_004450F0(obj, 5, -1);
        break;
    }
    case 1:
        break;
    case 5: {
        f32 phase;
        *(f32 *)(v + 0x14) += D_L07_001DE970 * 1.2f;
        if (*(f32 *)(v + 0x14) >= 2.0f) *(f32 *)(v + 0x14) -= 2.0f;
        if (*(f32 *)(v + 0x14) > 1.0f) phase = 2.0f - *(f32 *)(v + 0x14);
        else phase = *(f32 *)(v + 0x14);
        *(void **)(obj + 0x78) = func_0038DBD8(D_001DE968_sda, D_L07_001DE96C, phase);
        break;
    }
    }
}
/* localdecomp:end func_L07_003DD838 */

/* localdecomp:start func_L07_003DDA38 */
typedef struct {
    u8 pad_0[0x68];
    u8 *obj;            /* 0x68 */
    u8 pad_6C[0x78 - 0x6C];
    void *x78;          /* 0x78 */
    u8 pad_7C[0xF0 - 0x7C];
    s32 xF0;            /* 0xF0 */
} S_3DDA38;

typedef struct {
    s32 x0;             /* 0x0 */
    s32 x4;             /* 0x4 */
    u8 x8[0x8];         /* 0x8 */
    s32 x10;            /* 0x10 */
    u8 pad_14[4];
    f32 x18;            /* 0x18 */
    u8 x1C;             /* 0x1C */
} T_3DDA38;

extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_001DE964_sda;
__asm__(".extern D_001DE964_sda, 4");
extern void *D_001DE968_sda;
__asm__(".extern D_001DE968_sda, 4");

extern void func_L01_004AA760(s32, void *);
extern void func_L07_003B2870(u8 *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003DDA38(void *arg0, u8 arg1)
{
    S_3DDA38 *a = arg0;
    T_3DDA38 *s = (T_3DDA38 *)a->obj;
    s32 st;

    s->x1C = arg1;
    s->x10 = 0;
    a->x78 = D_001DE968_sda;
    a->xF0 = 0;
    func_L01_004AA760(0, arg0);
    func_L07_003B2870(D_L07_001DF41C + (s->x0 << 8));
    func_L07_003B2870(D_L07_001DF41C + (s->x4 << 8));
    s->x18 = (f32)D_001DE964_sda * 3.1415927f * 2.0f;
    st = s->x8[arg1];
    if (st == 1) {
        s->x18 = s->x18 + 4.1887903f;
        func_L01_004450F0(arg0, 2, -1);
    } else if (st == 2) {
        s->x18 = s->x18 + 2.0943952f;
        func_L01_004450F0(arg0, 2, -1);
    } else {
        func_L01_004450F0(arg0, 1, -1);
    }
}
/* localdecomp:end func_L07_003DDA38 */
