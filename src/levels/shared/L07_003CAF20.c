#include "common.h"

/* localdecomp:start func_L07_003CAF20 */
#include "vu0.h"
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L07_003CC1C0(void *);
extern void func_L05_003CAE70(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L07_003CB1F8(void *);
extern u8 D_L07_001D66B0[8];
typedef struct { u8 *g; s32 pad; f32 v[4]; } S_003CAF20;
extern S_003CAF20 D_L07_001E8C18;

static __inline__ void step_003CAF20(vu0_v4 *out, u8 *pos, u8 *vel) {
    if (*(f32 *)(vel + 0x20) < func_0038CEA8(vel)) {
        vec_add_ab(out, pos, vel);
    } else {
        func_0038CF68(out, vel, *(f32 *)(vel + 0x20));
        vec_add_ab(out, out, pos);
    }
}

void func_L07_003CAF20(u8 *o) {
    u8 *st = *(u8 **)(o + 0x68);
    vu0_v4 old;
    vu0_v4 v;
    u8 b[0x30] __attribute__((aligned(16)));
    void *col;
    u8 *g;
    s32 hit;
    s32 n;
    f32 f;

    old = *(vu0_v4 *)(o + 0x10);
    if (o[0x20] == 0) {
        if (func_L01_004561B8(o) == 0) {
            vec_add_ab(o + 0x10, o + 0x10, st);
        }
        if (func_0038CAD0(st + 0x24) != 0) {
            func_003C2880(o);
            return;
        }
        if (*(s32 *)(st + 0x30) == 0) {
            step_003CAF20(&v, o + 0x10, st);
            func_L01_00446760(b, o, 0x10001, D_L07_001D66B0, *(f32 *)(st + 0x34));
            *(s32 *)(b + 0x28) = *(s32 *)(st + 0x44);
            col = *(void **)(o + 0xB8);
            func_L01_004CB320();
            hit = func_003D3CB0(o + 0x10, &v, 0x10, col, b);
            if (hit != 0) {
                g = D_L07_001E8C18.g;
                if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                    g[0x20] = 4;
                }
            }
            func_L01_004CB358();
            if (hit != 0) {
                *(s32 *)(st + 0x30) = 1;
                *(vu0_v4 *)(st + 0x10) = *(vu0_v4 *)D_L07_001E8C18.v;
                f = func_0038CF00(o + 0x10, st + 0x10) / func_0038CEA8(st);
                n = ((s32)f * 5 + 2) / 6;
                *(s32 *)(st + 0x24) = n;
                *(f32 *)(st + 0x28) = 1.0f / n;
                if (D_L07_001E8C18.g == 0) {
                    func_L07_003CC1C0(o);
                } else {
                    func_L05_003CAE70(st + 0x10);
                }
            }
        }
        func_L01_00404A10(func_L07_003CB1F8, o);
    }
    if (*(f32 *)(o + 0x10) < 2.0f || 1021.0f < *(f32 *)(o + 0x10) ||
        *(f32 *)(o + 0x14) < 2.0f || 1021.0f < *(f32 *)(o + 0x14) ||
        *(f32 *)(o + 0x18) < 2.0f || 1021.0f < *(f32 *)(o + 0x18)) {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L07_003CAF20 */

/* localdecomp:start func_L07_003CB1F8 */
#include "vu0.h"

typedef struct { f32 u, v; } UV_003CB1F8;
typedef struct { vu0_v4 p[4]; s32 c[4]; UV_003CB1F8 uv[4]; u8 p70[0x20]; } Q_003CB1F8;
typedef struct {
    vu0_v4 dir;
    vu0_v4 end;
    f32 len;
    s32 n;
    f32 scale;
    f32 scroll;
    s32 fixed;
} S_003CB1F8;
typedef struct {
    vu0_v4 pos;
    u8 pad[0x460 - 0x10];
} E_003CB1F8;

extern s32 D_L07_001D52F0;
__asm__(".extern D_L07_001D52F0, 16");
extern E_003CB1F8 D_L07_001E1EC0[];
__asm__(".extern D_L07_001DE668, 4");
__asm__(".extern D_L07_001DE66C, 4");
__asm__(".extern D_L07_001DE670, 4");
__asm__(".extern D_L07_001DE674, 4");
__asm__(".extern D_L07_001DE678, 4");
__asm__(".extern D_L07_001DE67C, 4");
__asm__(".extern D_L07_001DE680, 4");
__asm__(".extern D_L07_001DE684, 4");
__asm__(".extern D_L07_001DE688, 4");
extern s32 D_L07_001DE668;
extern s32 D_L07_001DE66C;
extern s32 D_L07_001DE670;
extern s32 D_L07_001DE674;
extern f32 D_L07_001DE678;
extern s32 D_L07_001DE67C;
extern s32 D_L07_001DE680;
extern s32 D_L07_001DE684;
extern s32 D_L07_001DE688;

extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L07_003CB1F8(void *ov)
{
    u8 *o = ov;
    S_003CB1F8 *s = *(S_003CB1F8 **)(o + 0x68);
    Q_003CB1F8 q;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 d;
    vu0_v4 t0, t1, t2, t3, t4, t5, t6, t7;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 h;
    vu0_v4 k;
    f32 alpha;
    s32 i;

    if (o == 0) return;
    if (o[0x20] == 0xFE) return;
    if (o[0x20] == 0xFD) return;
    if (s == 0) return;

    a = *(vu0_v4 *)(o + 0x10);
    if (s->fixed != 0) {
        b = s->end;
        vec_sub_ab(&d, &b, &a);
    } else {
        func_0038CF68(&d, s, s->len);
        vec_add_ab(&b, &a, &d);
    }

    alpha = s->n * s->scale;
    func_003D93B0(&q, 0x17, 0, 0x80);
    q.c[1] = ((s32)(alpha * 64.0f) << 24) | 0x108080;
    q.c[0] = ((s32)(alpha * 64.0f) << 24) | 0x108080;
    q.c[3] = ((s32)(alpha * 64.0f) << 24) | 0x101080;
    q.c[2] = ((s32)(alpha * 64.0f) << 24) | 0x101080;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= s->scroll;
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    s->scroll += 0.1f;
    if (4.0f <= s->scroll) {
        s->scroll -= 4.0f;
    }

    vec_sub_ab(&e, o + 0x10, &D_L07_001E1EC0[D_L07_001D52F0]);
    func_0038CE90(&f, &e, &d);
    func_0038CF68(&f, &f, 0.1f);
    func_0038CE20(&g, &d, D_L07_001DE678);
    func_0038CE20(&h, &d, 1.0f - D_L07_001DE678);
    func_0038CE20(&k, &d, 0.5f);
    vec_add_ba(&g, &g, &a);
    vec_add_ab(&h, &h, &a);
    vec_add_ab(&k, &k, &a);
    vec_add_ab(&t0, &a, &f);
    vec_sub_ba(&t1, &a, &f);
    vec_add_ab(&t2, &g, &f);
    vec_sub_ba(&t3, &g, &f);
    vec_add_ab(&t4, &h, &f);
    vec_sub_ba(&t5, &h, &f);
    vec_add_ab(&t6, &b, &f);
    vec_sub_ba(&t7, &b, &f);

    q.p[0] = t0;
    q.p[1] = t1;
    q.p[2] = t2;
    q.p[3] = t3;
    q.c[0] = (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    q.c[1] = (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    q.c[2] = (D_L07_001DE674 << 24) | (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    q.c[3] = (D_L07_001DE674 << 24) | (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    func_003D2DA0(&q, 0, 0);

    q.p[0] = t4;
    q.p[1] = t5;
    q.c[0] = (D_L07_001DE674 << 24) | (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    q.c[1] = (D_L07_001DE674 << 24) | (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    func_003D2DA0(&q, 0, 0);

    q.p[2] = t6;
    q.p[3] = t7;
    q.c[2] = (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    q.c[3] = (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, 1, 0x80);
    q.c[3] = ((s32)(alpha * 64.0f) << 24) | 0x40FF;
    q.c[2] = ((s32)(alpha * 64.0f) << 24) | 0x40FF;
    q.c[1] = ((s32)(alpha * 64.0f) << 24) | 0x40FF;
    q.c[0] = ((s32)(alpha * 64.0f) << 24) | 0x40FF;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    func_0038CF68(&f, &f, 0.6f);
    vec_add_ba(&t0, &a, &f);
    vec_sub_ba(&t1, &a, &f);
    vec_add_ba(&t2, &k, &f);
    vec_sub_ba(&t3, &k, &f);
    vec_add_ba(&t4, &b, &f);
    vec_sub_ab(&t5, &b, &f);

    q.p[0] = t0;
    q.p[1] = t1;
    q.p[2] = t2;
    q.p[3] = t3;
    q.c[0] = (D_L07_001DE684 << 16) | (D_L07_001DE680 << 8) | D_L07_001DE67C;
    q.c[1] = (D_L07_001DE684 << 16) | (D_L07_001DE680 << 8) | D_L07_001DE67C;
    q.c[2] = (D_L07_001DE688 << 24) | (D_L07_001DE684 << 16) | (D_L07_001DE680 << 8) | D_L07_001DE67C;
    q.c[3] = (D_L07_001DE688 << 24) | (D_L07_001DE684 << 16) | (D_L07_001DE680 << 8) | D_L07_001DE67C;
    func_003D2DA0(&q, 0, 0);

    q.p[0] = t4;
    q.p[1] = t5;
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L07_003CB1F8 */
