#include "common.h"

/* localdecomp:start func_L39_00551F68 */
#include "vu0.h"

typedef int u128_00551F68 __attribute__((mode(TI)));

typedef struct {
    u128_00551F68 v0;
    vu0_v4 v10;
    u128_00551F68 v20;
    u128_00551F68 v30;
    u8 v40[0x10];
    s16 h50;
    s16 h52;
    s32 i54;
    s32 i58;
    f32 f5C;
} E_00551F68;

extern u8 D_L39_003C1020[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L39_00551F68(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    E_00551F68 *e = (E_00551F68 *)D_L39_003C1020 + st[0x3A];
    vu0_v4 fwd;
    vu0_v4 up;
    vu0_v4 side;
    s32 count;

    func_0038CF68(&fwd, st, 1.0f);
    *(u128_00551F68 *)&up = 0;
    up.z = 1.0f;
    up.w = 1.0f;
    func_0038CE90(&side, &fwd, &up);
    func_0038CF68(&side, &side, 1.0f);
    func_0038CE90(e->v40, &side, &fwd);
    e->v30 = *(u128_00551F68 *)&fwd;
    e->v0 = *(u128_00551F68 *)(a0 + 0x10);
    vec_add_ab(&e->v10, a0 + 0x10, st);
    e->v20 = *(u128_00551F68 *)&e->v10;
    count = 0x21;
    e->h50 = 1;
    e->h52 = count;
    e->f5C = 1.0f / count;
    e->i58 = 0;
    e->i54 = 0;
}
/* localdecomp:end func_L39_00551F68 */

/* localdecomp:start func_L39_00552070 */
typedef int Q_552070 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_552070;
extern u8 D_L39_003C1020[];
extern s32 func_0038CB00(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);

s32 func_L39_00552070(u8 *a0) {
    V4_552070 v;
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *e = D_L39_003C1020 + st[0x3A] * 0x60;
    f32 f21;
    f32 f20;
    Q_552070 x, y;

    if (*(s16 *)(e + 0x50) == 0) {
        return 0;
    }
    if (func_0038CB00(e + 0x52) != 0) {
        *(s16 *)(e + 0x50) = 0;
        return 0;
    }
    *(Q_552070 *)(e + 0x20) = *(Q_552070 *)(a0 + 0x10);
    f21 = func_0038CF00(e, e + 0x20);
    f20 = func_0038CF00(e, e + 0x10);
    if (f21 < f20) {
        *(Q_552070 *)(e + 0x10) = *(Q_552070 *)(a0 + 0x10);
        f20 = 0.0f;
    } else {
        f20 = f21 - f20;
    }
    *(f32 *)(e + 0x54) += 0.05f;
    if (*(f32 *)(e + 0x54) >= 4.0f) {
        *(f32 *)(e + 0x54) -= 4.0f;
    }
    *(f32 *)(e + 0x58) += 0.075f;
    if (*(f32 *)(e + 0x58) >= 4.0f) {
        *(f32 *)(e + 0x58) -= 4.0f;
    }
    func_0038CF68(&v, st, 0.32000002f);
    func_L01_0040E6B8(&v, &v, f21);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_552070 *)(e + 0)));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_552070 *)(e + 0)) : "j"(x));
    func_L01_0040E6B8(&v, &v, f20);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_552070 *)(e + 16)));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_552070 *)(e + 16)) : "j"(x));
    return 1;
}
/* localdecomp:end func_L39_00552070 */

/* localdecomp:start func_L39_005521F8 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_5521F8;
typedef int Q_5521F8 __attribute__((mode(TI)));

typedef struct {
    V4_5521F8 v[4];
    u32 col[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Prim_5521F8;

typedef struct {
    V4_5521F8 v[3];
    V4_5521F8 axis0;
    V4_5521F8 axis2;
    s16 active;
    s16 timer;
    f32 scroll0;
    f32 scroll1;
    f32 scale;
} Ent_5521F8;

extern u8 D_L39_003C1020[];
extern V4_5521F8 D_L39_0047F550[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L39_005521F8(void *arg0) {
    Prim_5521F8 p;
    V4_5521F8 m[4];
    V4_5521F8 pts[3][20];
    V4_5521F8 tmp;
    V4_5521F8 w;
    u8 *st;
    Ent_5521F8 *e;
    s32 i;
    s32 j;
    s32 n;
    s32 back0;
    s32 back1;
    u32 col;
    u32 c;
    u32 c2;
    f32 fade;
    f32 t;
    f32 u0;
    f32 u1;
    f32 base;

    st = *(u8 **)((u8 *)arg0 + 0x68);
    e = (Ent_5521F8 *)D_L39_003C1020 + st[0x3A];
    func_003D93B0(&p, 0x15, 0, 0x80);
    if (e->active == 0) {
        return;
    }
    *(Q_5521F8 *)&m[0] = *(Q_5521F8 *)&e->axis0;
    *(Q_5521F8 *)&m[2] = *(Q_5521F8 *)&e->axis2;
    c = 0x804020;
    func_0038CE90(&m[1], &m[0], &m[2]);
    fade = (f32)e->timer * e->scale;
    col = ((s32)(fade * 64.0f) << 24) | c;
    p.col[3] = col;
    p.col[2] = col;
    p.col[1] = col;
    p.col[0] = col;
    for (i = 0; i < 3; i++) {
        *(Q_5521F8 *)&m[3] = *(Q_5521F8 *)&e->v[i];
        for (j = 0; j < 20; j++) {
            func_0038CE20(&tmp, &D_L39_0047F550[j], 0.12f);
            func_0038D028(&pts[i][j], &tmp, m);
        }
    }

    u0 = e->scroll0;
    u1 = u0 + 4.0f;
    c = 0x804020;
    for (j = 1; j < 3; j++) {
        t = 0.0f;
        for (i = 0; i < 20; i++) {
            n = (i + 1) % 20;
            /* byte offsets of points i and n of the previous ring, from ring j */
            back0 = i * sizeof(V4_5521F8) - sizeof(pts[0]);
            back1 = n * sizeof(V4_5521F8) - sizeof(pts[0]);
            *(Q_5521F8 *)&p.v[0] = *(Q_5521F8 *)&pts[j][i];
            *(Q_5521F8 *)&p.v[1] = *(Q_5521F8 *)&pts[j][n];
            *(Q_5521F8 *)&p.v[2] = *(Q_5521F8 *)((u8 *)pts[j] + back0);
            *(Q_5521F8 *)&p.v[3] = *(Q_5521F8 *)((u8 *)pts[j] + back1);
            p.col[2] = c;
            p.col[3] = c;
            p.uv[0][0] = u0;
            p.uv[0][1] = t;
            p.uv[1][0] = u0;
            p.uv[1][1] = t + 0.05f;
            p.uv[2][0] = u1;
            p.uv[2][1] = t;
            p.uv[3][0] = u1;
            p.uv[3][1] = t + 0.05f;
            t += 0.05f;
            func_003D2DA0(&p, 0, 0);
        }
        c = col;
    }

    func_003D93B0(&p, 0xE, 1, 0x80);
    c2 = 0x804020;
    col = ((s32)(fade * 80.0f) << 24) | c2;
    p.col[3] = col;
    p.col[2] = col;
    p.col[1] = col;
    p.col[0] = col;
    p.uv[0][0] = 0.0f;
    p.uv[0][1] = 0.0f;
    p.uv[1][0] = 0.0f;
    p.uv[1][1] = 1.0f;
    p.uv[2][1] = 0.0f;
    p.uv[3][1] = 1.0f;
    p.uv[3][0] = 0.5f;
    p.uv[2][0] = 0.5f;
    vec_sub_ba(&tmp, *(u8 **)(st + 0x3C) + 0x23A0, &e->v[0]);
    func_0038CE90(&m[1], &m[0], &tmp);
    func_0038CF68(&w, &m[1], 1.0f);
    for (j = 0; j < 2; j++) {
        V4_5521F8 *a = &e->v[j];
        V4_5521F8 *b = &e->v[j + 1];
        vec_add_ba(&p.v[0], b, &w);
        vec_sub_ab(&p.v[1], b, &w);
        vec_add_ab(&p.v[2], a, &w);
        vec_sub_ab(&p.v[3], a, &w);
        p.col[2] = c2;
        p.col[3] = c2;
        func_003D2DA0(&p, 0, 0);
        c2 = col;
        p.uv[1][0] = p.uv[2][0];
        p.uv[0][0] = p.uv[2][0];
        p.uv[3][0] = 3.0f;
        p.uv[2][0] = 3.0f;
    }

    func_003D93B0(&p, 0x17, 1, 0x80);
    c2 = 0x804020;
    col = ((s32)(fade * 255.0f) << 24) | c2;
    base = e->scroll1;
    p.col[3] = col;
    p.col[2] = col;
    p.col[1] = col;
    p.col[0] = col;
    p.uv[0][0] = 0.0f;
    p.uv[0][1] = 0.0f;
    p.uv[1][0] = 0.0f;
    p.uv[1][1] = 1.0f;
    p.uv[2][1] = 0.0f;
    p.uv[3][0] = base + 0.5f;
    p.uv[3][1] = 1.0f;
    p.uv[2][0] = base + 0.5f;
    c2 = 0x7F7F7F;
    func_0038CF68(&w, &m[1], 0.1f);
    for (j = 0; j < 2; j++) {
        V4_5521F8 *a = &e->v[j];
        V4_5521F8 *b = &e->v[j + 1];
        vec_add_ba(&p.v[0], b, &w);
        vec_sub_ab(&p.v[1], b, &w);
        vec_add_ab(&p.v[2], a, &w);
        vec_sub_ab(&p.v[3], a, &w);
        p.col[2] = c2;
        p.col[3] = c2;
        func_003D2DA0(&p, 0, 0);
        c2 = col;
        p.uv[1][0] = p.uv[2][0];
        p.uv[0][0] = p.uv[2][0];
        p.uv[3][0] = base + 3.0f;
        p.uv[2][0] = base + 3.0f;
    }
}
/* localdecomp:end func_L39_005521F8 */
