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
extern f32 D_L02_001DC948[2];
__asm__(".extern D_L02_001DC948, 8");
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
        sc = D_L02_001DC948;
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

INCLUDE_ASM("asm/levels", func_L02_00327038);

INCLUDE_ASM("asm/levels", func_L02_003278C0);

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

INCLUDE_ASM("asm/levels", func_L02_00327B50);

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
