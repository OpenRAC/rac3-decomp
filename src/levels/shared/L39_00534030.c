#include "common.h"

/* localdecomp:start func_L39_00534030 */
#include "vu0.h"

typedef struct {
    f32 u;
    f32 v;
} UV_00534030;
typedef struct {
    vu0_v4 p[4];
    s32 c[4];
    UV_00534030 uv[4];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_00534030;
typedef struct {
    vu0_v4 pos;
    u8 pad[0x450];
} C_00534030;
__asm__(".extern D_L39_0024AD50, 4");
extern f32 D_L39_0024AD50;
/* no size hint: retail reaches it through lui (Ps2EeAs expands the unsized small-data load) */
extern s32 D_L39_00241118;
extern C_00534030 D_L39_0024DE80[];
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_00534030(u8 *a0) {
    vu0_v4 m[4];
    Q_00534030 q;
    vu0_v4 t;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 r1;
    f32 r2;
    s32 i;

    r1 = func_L39_005B4410(0.45f, 0.7f);
    r2 = func_L39_005B4410(4.0f, 4.5f);
    func_0038CF68(&m[0], s, 1.0f);
    vec_sub_ba(&m[1], &D_L39_0024DE80[D_L39_00241118].pos, a0 + 0x10);
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
    func_0038CF68(&t, s, D_L39_0024AD50);
    vec_add_ba(&m[3], &t, a0 + 0x10);
    m[3].w = 1.0f;
    func_003D2DA0(&q, m, 0);
}
/* localdecomp:end func_L39_00534030 */

INCLUDE_ASM("asm/levels", func_L39_00534220);

INCLUDE_ASM("asm/levels", func_L39_00534530);

INCLUDE_ASM("asm/levels", func_L39_00534880);
