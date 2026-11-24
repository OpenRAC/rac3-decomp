/* PAL near miss (round 23 W1): 21 positional word differences with --no-context. Reuse the width branch predicate in the color chain and draw calls. Retail passes the predicate in a2 and saves a copy in fp, while this draft keeps it in s5 across both calls. The owning file also needs compatible object and row declarations before integration. */
#include "common.h"
#include "vu0.h"
extern void func_003D2DA0();
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
/* localdecomp:start func_L01_0035A6B0 */
typedef struct { f32 u, v; } UV_0035A6B0;
typedef struct { vu0_v4 p[4]; s32 c[4]; UV_0035A6B0 uv[4]; u8 p70[0x20]; } Q_0035A6B0;
typedef struct { u8 p0[0x10]; f32 f10; } S_0035A6B0;
typedef struct { u8 b0; u8 b1; u8 p2[0xEE]; } Row_0035A6B0;
extern u8 D_001425C0[];
extern Row_0035A6B0 D_L01_002C5600[];
extern s32 D_001A71A4[];
extern u8 D_L01_001E29C0_0035A6B0[];
extern s32 D_L01_001DD698;
extern s32 D_L01_001DD69C;
extern f32 D_L01_001DD6A0;
extern f32 D_L01_001DD6A4;
extern s32 D_L01_001DD6A8;
__asm__(".extern D_L01_001DD698, 4");
__asm__(".extern D_L01_001DD69C, 4");
__asm__(".extern D_L01_001DD6A0, 4");
__asm__(".extern D_L01_001DD6A4, 4");
__asm__(".extern D_L01_001DD6A8, 4");
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);


void func_L01_0035A6B0(u8 *o, vu0_v4 a, vu0_v4 b) {
    Q_0035A6B0 q;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 u;
    S_0035A6B0 *s;
    Row_0035A6B0 *ent;
    s32 b1;
    s32 small;
    s32 i;
    f32 w;

    ent = &D_L01_002C5600[D_001425C0[0x7F]];
    s = *(S_0035A6B0 **)(o + 0x68);
    b1 = ent->b1;
    if ((u32)(D_001A71A4[0] - 0x13) >= 2) {
        if (!(small = (b1 < 4))) {
            w = 0.06f;
            goto wdone;
        }
    } else {
        if (!(small = (b1 < 4))) {
            w = 0.09f;
            goto wdone;
        }
    }
    w = 0.12f;
wdone:
    D_L01_001DD6A4 = D_L01_001DD6A0 = w;
    if (b1 == 0 || b1 == 1) {
        D_L01_001DD698 = 0x5F204080;
        D_L01_001DD69C = 0x5F202080;
    } else if (b1 == 2 || b1 == 3) {
        D_L01_001DD69C = D_L01_001DD698 = 0x5F804020;
    } else if (!small) {
        D_L01_001DD69C = D_L01_001DD698 = 0x7F000000;
    }
    func_003D93B0(&q, D_L01_001DD6A8, small, 0x80);
    q.c[3] = D_L01_001DD698;
    q.c[2] = D_L01_001DD698;
    q.c[1] = D_L01_001DD698;
    q.c[0] = D_L01_001DD698;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= s->f10;
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, &a, &b);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, &a, D_L01_001E29C0_0035A6B0);
    vec_sub_ba(&f, &b, D_L01_001E29C0_0035A6B0);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L01_001DD6A0);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L01_001DD6A4);
    vec_sub_ba(&u, &a, &e);
    t = u;
    q.p[0] = t;
    vec_add_ba(&u, &a, &e);
    t = u;
    q.p[1] = t;
    vec_sub_ba(&u, &b, &f);
    t = u;
    q.p[2] = t;
    vec_add_ba(&u, &b, &f);
    t = u;
    q.p[3] = t;
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, small, 0x80);
    q.c[3] = D_L01_001DD69C;
    q.c[2] = D_L01_001DD69C;
    q.c[1] = D_L01_001DD69C;
    q.c[0] = D_L01_001DD69C;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= s->f10;
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    vec_sub_ba(&d, &a, &b);
    func_0038CF68(&d, &d, 1.0f);
    vec_sub_ba(&e, &a, D_L01_001E29C0_0035A6B0);
    vec_sub_ba(&f, &b, D_L01_001E29C0_0035A6B0);
    func_0038CE90(&e, &e, &d);
    func_0038CF68(&e, &e, D_L01_001DD6A0 * 0.5f);
    func_0038CE90(&f, &f, &d);
    func_0038CF68(&f, &f, D_L01_001DD6A4 * 0.5f);
    vec_sub_ba(&u, &a, &e);
    t = u;
    q.p[0] = t;
    vec_add_ba(&u, &a, &e);
    t = u;
    q.p[1] = t;
    vec_sub_ba(&u, &b, &f);
    t = u;
    q.p[2] = t;
    vec_add_ba(&u, &b, &f);
    t = u;
    q.p[3] = t;
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L01_0035A6B0 */
