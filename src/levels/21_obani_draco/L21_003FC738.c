#include "common.h"

/* localdecomp:start func_L21_003FC738 */
#include "vu0.h"

typedef struct {
    vu0_v4 p[4];
    s32 c[4];
    f32 uv[4][2];
    u8 pad90[0x20];
} Q_003FC738;
typedef struct {
    vu0_v4 v[4];
} M_003FC738;
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x10];
    vu0_v4 m[4];
} C_003FC738;

extern const M_003FC738 D_001D6C30;
extern C_003FC738 D_L21_001E1680;

extern void func_003D93B0(void *, s32, s32, s32);
extern s32 func_00382468(s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);

static __inline__ void vcopy_003FC738(vu0_v4 *d, vu0_v4 *s) {
    *d = *s;
}

void func_L21_003FC738(f32 a, f32 b, f32 c, void *p, s32 e, s32 f, s32 g, s32 h, s32 i) {
    vu0_v4 v;
    vu0_v4 t;
    Q_003FC738 q;
    vu0_v4 w;
    M_003FC738 m;
    s32 color;
    s32 j;

    func_003D93B0(&q, i, e, 0x80);
    color = ((func_00382468(g) + f) << 24) | (h << 16) | (h << 8) | h;
    *(vu0_q *)&w = 0;
    w.x = 0.1f;
    m = D_001D6C30;
    q.c[3] = color;
    q.c[2] = color;
    q.c[1] = color;
    q.c[0] = color;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    func_0038D000(&v, &w, D_L21_001E1680.m);
    vec_add_ab(&v, &D_L21_001E1680.pos, &v);
    for (j = 0; j < 4; j++) {
        func_0038CF68(&m.v[j], &m.v[j], c);
        m.v[j].z = b * m.v[j].z + *(f32 *)p;
        func_0038D000(&m.v[j], &m.v[j], D_L21_001E1680.m);
        vec_add_ba(&t, &v, &m.v[j]);
        vcopy_003FC738(&q.p[j], &t);
        q.p[j].w = 1.0f;
    }
    *(f32 *)p += a;
    if (*(f32 *)p >= 0.05f) {
        *(f32 *)p -= 0.1f;
    } else if (*(f32 *)p <= -0.05f) {
        *(f32 *)p += 0.1f;
    }
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L21_003FC738 */
