#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x60 - 0x1C];
    f32 f60;
    f32 f64;
    f32 f68;
} State_416A50;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} Class_416A50;
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x20 - 0x1C];
    u8 b20;
    u8 pad2[0x24 - 0x21];
    Class_416A50 *cls;
    u8 pad3[0x2C - 0x28];
    f32 f2C;
    u8 pad4[0x68 - 0x30];
    State_416A50 *st;
    u8 pad5[0xF0 - 0x6C];
    f32 fF0;
    f32 fF4;
    f32 fF8;
    f32 fFC;
} Obj_416A50;

typedef struct { f32 x, y; } F2_00326C90;
typedef struct {
    u8 p0[0x10]; s32 w10; s32 w14; f32 f18; u8 p1C[4]; f32 f20; f32 f24; u8 p28[4]; f32 f2C;
    f32 f30; s32 w34; s32 w38; s32 w3C; f32 f40; f32 f44; f32 f48; f32 f4C; u8 p50[8]; s32 w58; u8 p5C[4]; vu0_v4 v60;
} S_00326C90;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_00326C90 *p68; } M_00326C90;

/* localdecomp:start func_L02_00326C90 */
#include "vu0.h"

extern u8 D_001A4C60[];
extern s32 D_L02_001F1580[];
extern vu0_v4 D_L02_001E1280;
extern F2_00326C90 D_L02_001E0220[1];
extern F2_00326C90 D_L02_001DC988[1];
__asm__(".extern D_L02_001DC988, 8");
extern F2_00326C90 D_L02_001DC968[1];
__asm__(".extern D_L02_001DC968, 8");
extern f32 D_L02_001DC958[2];
__asm__(".extern D_L02_001DC958, 8");
extern f32 D_L02_001DC948_00326C90[2];
__asm__(".extern D_L02_001DC948_00326C90, 8");
extern s32 D_L02_001DE4C0;
extern s32 func_00382380(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_00327B50(void *, void *);
extern void func_L02_00327C70(f32 *, f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern s32 func_L02_00327CC0(void *);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L02_00327038();
extern f32 D_001D5324;
__asm__(".extern D_001D5324, 16");
void func_L02_00326C90(M_00326C90 *m) {
    S_00326C90 *s = m->p68;
    vu0_v4 d;
    vu0_v4 v;
    F2_00326C90 *tab;
    f32 *sc;
    s32 j;
    f32 r;
    if (s->w58 != -1 && func_00382380(D_001A4C60, s->w58, 0) == 0) return;
    if (m->b20 == 0) func_L02_00327B50(m, s);
    if (D_L02_001F1580[0] != s->w34) return;
    if (func_00382380(D_001A4C60, s->w38, 0) != 0) {
        *(s16 *)(D_001A4C60 + 0x17E) = 0;
        return;
    }
    if (func_00382380(D_001A4C60, s->w3C, 0) != 0) {
        *(s16 *)(D_001A4C60 + 0x17E) = 0;
        return;
    }
    r = s->f18;
    *(s16 *)(D_001A4C60 + 0x17E) = 2;
    vec_sub_ba(&d, &D_L02_001E1280, &s->v60);
    s->v60 = D_L02_001E1280;
    if (!(s->f24 < D_L02_001E1280.z)) return;
    if (s->w10 != 0 && s->w14 >= 3) {
        tab = D_L02_001DC988;
        sc = D_L02_001DC958;
    } else {
        tab = D_L02_001DC968;
        sc = D_L02_001DC948_00326C90;
    }
    for (j = 0; j < s->w14; j++) {
        func_0038CE20(&v, &d, (sc[j] * 1.5f) / (r * 5.0f));
        func_L02_00327C70(&D_L02_001E0220[j].x, v.x, v.y);
    }
    s->f2C = s->f20 + func_0038D0B0((f32)(D_L02_001DE4C0 % 360) * 0.017444445f - 3.14f) * s->f30;
    for (j = 0; j < s->w14; j++, tab++) {
        f32 t = D_001D5324 * s->f40;
        func_L02_00327C70(&D_L02_001E0220[j].x, tab->x * t, tab->y * t);
        if (s->f44 != 0.0f) {
            f32 x;
            s->f4C = func_0038DAB8(s->f4C, s->f48);
            t = s->f4C;
            if (j & 1) t = -t;
            x = tab->x * s->f44 * func_0038D098(t);
            func_L02_00327C70(&D_L02_001E0220[j].x, x, tab->y * s->f44 * func_0038D0B0(t));
        }
    }
    if (func_L02_00327CC0(s)) func_L01_004048D0(func_L02_00327038, m);
    else func_L01_00404808(func_L02_00327038, m);
}
/* localdecomp:end func_L02_00326C90 */

/* localdecomp:start func_L02_00326FC0 */
typedef int u128_00326730 __attribute__((mode(TI)));
typedef union { u128_00326730 q; f32 f[4]; s32 w[4]; } V_00326730;

extern u128_00326730 D_L02_001E12A0[];
extern void func_0038CF68(V_00326730 *, V_00326730 *, f32);
extern void func_0038CE90(void *, V_00326730 *, V_00326730 *);

void func_L02_00326FC0(V_00326730 *v, void *a1) {
    V_00326730 t;
    v->q = D_L02_001E12A0[0];
    t.q = 0;
    v->w[2] = 0;
    t.f[2] = 1.0f;
    t.f[3] = 1.0f;
    v->f[3] = 1.0f;
    func_0038CF68(v, v, 1.0f);
    func_0038CE90(a1, v, &t);
}
/* localdecomp:end func_L02_00326FC0 */

/* localdecomp:start func_L02_00327038 */
#include "vu0.h"

typedef struct {
    u8 p0[3];
    u8 b3;
    u8 p4[4];
    u8 col0[4];
    u8 col1[4];
    s32 w10;
    s32 w14;
    f32 f18;
    s32 tex1C;
    f32 f20;
    u8 p24[4];
    f32 f28;
    f32 f2C;
    u8 p30[0x50 - 0x30];
    s32 w50;
} S_00327038;
typedef struct { u8 p0[0x68]; S_00327038 *s; } M_00327038;
typedef struct { u8 pad[0x238]; f32 f238; f32 f23C; } R_00327038;
typedef struct { u8 pad[0x140]; vu0_v4 pos; } C_00327038;
typedef struct { f32 x, y, z; } P_00327038;
typedef struct { f32 u, v; } T_00327038;

extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001A71A4[];
extern u8 D_L02_001D60F8[] __attribute__((section(".sdata")));
extern R_00327038 D_L02_001E5E40;
extern C_00327038 D_L02_001E1140;
extern F2_00326C90 D_L02_001DC9D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC9D8, 8");
extern F2_00326C90 D_L02_001DC9F8[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC9F8, 8");
extern f32 D_L02_001DC9A8[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC9A8, 8");
extern f32 D_L02_001DC9B8[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC9B8, 8");
extern f32 D_L02_001DC9C8[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC9C8, 8");
__asm__(".extern D_L02_001DC948_00326C90, 8");
__asm__(".extern D_L02_001DC958, 8");
extern P_00327038 D_L02_002750D0[];
extern s32 D_L02_001E0240[] __attribute__((section(".sdata")));
extern s32 D_L02_00275860[];
extern f32 D_L02_00275190[][2];
extern f32 D_L02_00275370[];
extern P_00327038 D_L02_00275460[];
extern s32 D_L02_00275760[];
extern T_00327038 D_L02_002758E0[];
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern s32 func_0038DBD8(u32, u32, f32);
extern void func_L02_00326FC0(V_00326730 *, void *);

void func_L02_00327038(M_00327038 *m) {
    S_00327038 *s;
    vu0_v4 t;
    V_00326730 a;
    vu0_v4 b;
    vu0_v4 v[4];
    vu0_v4 d0;
    vu0_v4 d1;
    vu0_v4 u;
    u32 ca;
    u32 cb;
    f32 *sc;
    F2_00326C90 *tbl;
    F2_00326C90 *o;
    f32 (*g)[2];
    f32 save238;
    f32 save23C;
    f32 dist;
    f32 size;
    f32 r;
    f32 h;
    f32 k;
    f32 f;
    f32 uvs;
    f32 xys;
    s32 i;
    s32 j;
    s32 n;

    if (D_001D545C == 5) return;
    save238 = D_L02_001E5E40.f238;
    save23C = D_L02_001E5E40.f23C;
    s = m->s;
    if (D_001A71A4[0] != 0x1C && D_L02_001D60F8[0] == 0) {
        D_L02_001E5E40.f238 = 255.0f;
        D_L02_001E5E40.f23C = 249.9f;
    }
    func_003A9440(0x42, 0x3200000044UL);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    if (s->b3 & 0x80) {
        func_003A9440(0x47, 0x5310B);
    } else {
        func_003A9440(0x47, 0x513F1);
    }
    func_003A9440(6, func_00389598(0x16));
    func_0038C750();
    func_L02_00326FC0(&a, &b);
    tbl = D_L02_001DC9D8;
    if (D_L02_001E1140.pos.z - s->f20 > 200.0f) {
        tbl = D_L02_001DC9F8;
    }
    for (i = 0; i < 4; i++) {
        func_0038CE20(&v[i], &a, tbl[i].x);
        func_0038CE20(&t, &b, tbl[i].y);
        if (i & 1) {
            func_0038CE20(&u, &a, s->f28);
            vec_add_ab(&t, &u, &t);
        }
        vec_add_ab(&v[i], &v[i], &t);
    }
    for (i = 0; i < 4; i++) {
        vec_add_ab(&v[i], &v[i], &D_L02_001E1280);
        v[i].z = s->f2C;
    }
    vec_sub_ba(&d0, &v[1], &v[0]);
    vec_sub_ab(&d1, &v[3], &v[2]);
    for (i = 0; i < 12; i += 2) {
        f = i;
        f /= 10.0f;
        func_0038CE20(&t, &d0, f);
        vec_add_ab(&t, &t, &v[0]);
        func_0038CC88(&D_L02_002750D0[i], &t, 12);
        func_0038CE20(&t, &d1, f);
        vec_add_ab(&t, &t, &v[2]);
        func_0038CC88(&D_L02_002750D0[i + 1], &t, 12);
    }
    func_003D3A24(12, D_L02_002750D0, D_L02_001E0240, D_L02_00275860, 1);
    ca = (s->col0[3] << 24) | (s->col0[2] << 16) | (s->col0[1] << 8) | s->col0[0];
    cb = (s->col1[3] << 24) | (s->col1[2] << 16) | (s->col1[1] << 8) | s->col1[0];
    if (s->w10 != 0 && s->w14 >= 3) {
        sc = D_L02_001DC958;
    } else {
        sc = D_L02_001DC948_00326C90;
    }
    if (s->w10 != 0) {
        func_003A9440(6, func_00389598(s->tex1C + 100));
    } else {
        func_003A9440(0x42, 0x8000000048UL);
    }
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    dist = fabs_asm(D_L02_001E1140.pos.z - s->f2C);
    r = s->f18;
    size = r * 2.5f;
    if (dist < 10.0f) {
        dist = 10.0f;
    }
    if (s->b3 & 0x80) {
        h = dist * r * 2e-5f * 1.05f;
        if (h < 0.15f) h = 0.15f;
    } else {
        h = dist * r * 2e-5f;
        if (h < 0.125f) h = 0.125f;
    }
    if (D_L02_001E1140.pos.z < s->f2C) {
        h = -h;
    }
    for (j = 0; j < s->w14; j++) {
        if (D_L02_001DC9A8[j] < dist) continue;
        k = (1.0f - dist / D_L02_001DC9A8[j]) * D_L02_001DC9B8[j];
        if (1.0f < k) {
            k = 1.0f;
        } else if (k < 0.0f) {
            k = 0.0f;
        }
        cb = (cb & 0xFFFFFF) | ((s32)(s->col1[3] * k) << 24);
        if (s->w10 != 0 && (j & 1)) {
            ((u8 *)&ca)[3] = 0;
            ((u8 *)&cb)[3] = 0;
        } else {
            ((u8 *)&ca)[3] = s->col0[3];
            ((u8 *)&cb)[3] = s->col1[3];
        }
        if (s->w10 != 0) {
            if ((s->w14 & 1) && j == s->w14 - 1) continue;
            if (j & 1) {
                if (s->w50 != 0) {
                    func_003A9440(0x42, 0x8000000051UL);
                } else {
                    func_003A9440(0x42, 0x8000000058UL);
                }
            } else {
                func_003A9440(0x42, 0x800000006AUL);
            }
        } else {
            func_003A9440(6, func_00389598(s->tex1C + 100 + j));
        }
        uvs = sc[j] / size;
        xys = D_L02_001DC9C8[j];
        o = &D_L02_001E0220[j];
        g = D_L02_00275190;
        for (n = 0; n < 60; n++) {
            s32 c = func_0038DBD8(cb, ca, D_L02_00275370[n] * k);
            f32 x = g[n][0];
            f32 y = g[n][1];
            D_L02_00275760[n] = c;
            D_L02_002758E0[n].u = x * uvs + o->x;
            D_L02_002758E0[n].v = y * uvs + o->y;
            D_L02_00275460[n].x = x * xys + D_L02_001E1140.pos.x;
            D_L02_00275460[n].y = y * xys + D_L02_001E1140.pos.y;
            D_L02_00275460[n].z = s->f2C + h;
        }
        func_003D3A24(60, D_L02_00275460, D_L02_00275760, D_L02_002758E0, 1);
    }
    D_L02_001E5E40.f238 = save238;
    D_L02_001E5E40.f23C = save23C;
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L02_00327038 */

/* localdecomp:start func_L02_003278C0 */
#include "vu0.h"
extern f32 D_L02_00275190[][2];
extern f32 D_L02_00275370[];

void func_L02_003278C0(f32 d, void *idx, f32 x, f32 y) {
    s32 *n = (s32 *)idx;
    f32 t = sqrt_asm(x * x + y * y);

    D_L02_00275190[*n][0] = x;
    t = t / d;
    D_L02_00275190[*n][1] = y;
    if (1.0f < t) {
        t = 1.0f;
    }
    t = 1.0f - t;
    D_L02_00275370[*n] = t + t - t * t;
    (*n)++;
}
/* localdecomp:end func_L02_003278C0 */

/* localdecomp:start func_L02_00327960 */
extern s32 D_L02_00275860[];
extern s32 D_L02_001E0240[] __attribute__((section(".sdata")));
extern s32 func_0038DBD8(u32, u32, f32);
extern void func_L02_003278C0(f32, void *, f32, f32);

void func_L02_00327960(s32 unused, u8 *p) {
    s32 i;
    s32 *w;
    s32 *q;
    u32 a;
    u32 b;
    s32 buf;
    f32 f18;
    f32 hi;
    f32 lo;
    f32 nxt;
    f32 cur;
    s32 j;
    s32 k;
    s32 r;

    q = D_L02_00275860;
    i = 0;
    a = (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
    b = (p[7] << 24) | (p[6] << 16) | (p[5] << 8) | p[4];
    w = D_L02_001E0240;
    for (; i < 12; i += 2) {
        q[0] = 0;
        q[1] = 0;
        r = func_0038DBD8(a, b, i / 10.0f);
        w[0] = r;
        w[1] = r;
        w += 2;
        q += 4;
    }
    f18 = *(f32 *)(p + 0x18);
    buf = 0;
    hi = f18 * 2.5f;
    lo = -hi;
    for (k = 0; k < 5; k++) {
        if (k & 1) {
            nxt = lo + f18;
            cur = hi;
            for (j = 5; j >= 0; j--) {
                func_L02_003278C0(hi, &buf, cur, lo);
                func_L02_003278C0(hi, &buf, cur, nxt);
                cur -= f18;
            }
        } else {
            cur = -hi;
            nxt = lo + f18;
            for (j = 5; j >= 0; j--) {
                func_L02_003278C0(hi, &buf, cur, lo);
                func_L02_003278C0(hi, &buf, cur, nxt);
                cur += f18;
            }
        }
        lo = nxt;
    }
}
/* localdecomp:end func_L02_00327960 */

/* localdecomp:start func_L02_00327B50 */
/* log:
 * v1: first draft
 */
#include "vu0.h"

extern vu0_v4 D_L02_001E1280;
extern F2_00326C90 D_L02_001E0220[1];
extern void func_L01_004450F0(void *, int, int);
extern float func_003824E0(float, float);
extern void func_L02_00327960(s32 unused, u8 *p);

void func_L02_00327B50(void *a, void *b) {
    u8 *m = a;
    S_00326C90 *s = b;
    s32 i;

    func_L01_004450F0(m, 1, -1);
    m[0x30] = 0xFF;
    s->w14 = s->w14 * 2;
    if (s->w14 > 4) s->w14 = 4;
    else if (s->w14 < 0) s->w14 = 0;
    if (s->f18 > 32.0f) s->f18 = 32.0f;
    for (i = 0; i < s->w14; i++) {
        D_L02_001E0220[i].x = func_003824E0(0.0f, 1.0f);
        D_L02_001E0220[i].y = func_003824E0(0.0f, 1.0f);
    }
    s->f4C = 0.0f;
    func_L02_00327960((s32)m, (u8 *)s);
    s->v60 = D_L02_001E1280;
}
/* localdecomp:end func_L02_00327B50 */

/* localdecomp:start func_L02_00327C70 */
void func_L02_00327C70(f32 *v, f32 x, f32 y) {
    f32 a = v[0] + x;
    f32 b = v[1] + y;

    v[0] = a - (f32)(s32)a;
    v[1] = b - (f32)(s32)b;
}
/* localdecomp:end func_L02_00327C70 */

/* localdecomp:start func_L02_00327CC0 */
s32 func_L02_00327CC0(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 3)) & 0x80;
}
/* localdecomp:end func_L02_00327CC0 */
