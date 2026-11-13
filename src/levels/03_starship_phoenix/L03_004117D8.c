#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_004117D8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    s16 life;
    s16 pad2;
    f32 w;
    f32 h;
    f32 spin;
    s32 i10;
    s32 c0;
    s32 c1;
    s32 n;
} P_004117D8;
typedef struct { u8 pad[0x1A0]; u8 *list[1]; } G_004117D8;
extern G_004117D8 D_L03_001E6800;
extern P_004117D8 D_L03_001D6A90 __attribute__((section(".sdata")));
__asm__(".extern D_L03_001D6A90, 4");
extern s32 func_00382468(s32);
extern void func_003C2EC0(u8 *, s32, f32 *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003C4C18(f32 *, f32);
extern u8 *func_L01_004637C8(f32 *, f32 *, s32, s32, s32, s32, s32, s32);

void func_L03_004117D8(s32 idx, void *b) {
    f32 vb[4];
    f32 *v = vb;
    P_004117D8 a;
    P_004117D8 c;
    f32 q[4];
    f32 p[4];
    f32 x[4];
    f32 m[16];
    u8 *o;
    s32 r;
    s32 i;
    f32 sc;
    f32 fw;
    f32 fh;
    o = D_L03_001E6800.list[idx];
    *(u128_t *)vb = *(u128_t *)b;
    a = D_L03_001D6A90;
    a.w = 300.0f;
    a.c0 = 0x40505570;
    a.c1 = 0x202020;
    a.life = 0x78;
    a.h = 200.0f;
    a.spin = 0.026f;
    c = D_L03_001D6A90;
    c.c1 = 0x20;
    c.c0 = 0x80102080;
    c.life = 0x19;
    c.w = 200.0f;
    c.spin = 0.026f;
    c.n = 2;
    c.h = 100.0f;
    r = func_00382468(100);
    func_003C2EC0(o, 1, m);
    sc = func_0038CEA8(m);
    func_0038CE20(x, x, sc);
    func_0038D028(x, v, m);
    vec_add_ab(p, x, m + 12);
    qzero(q);
    func_003C4C18(q, a.spin);
    fh = sc * a.h + (f32)r;
    fw = sc * a.w + (f32)r;
    func_L01_004637C8(p, q, a.c0, a.c1, (s32)(sc * (f32)a.life), (s32)fh, (s32)fw, func_00382468(2));
    func_L01_004637C8(p, q, c.c0, c.c1, (s32)(sc * 0.5f * (f32)a.life), (s32)fh, (s32)fw, 0);
    for (i = 0; i < c.n; i++) {
        qzero(q);
        func_0038D028(x, v, m);
        vec_add_ab(p, x, m + 12);
        r = func_00382468(0x32);
        func_003C4C18(q, a.spin);
        c.c0 = ((func_00382468(100) + 0x3C) << 8) | 0xFF1400FF;
        fh = sc * c.h + (f32)r;
        fw = sc * c.w + (f32)r;
        func_L01_004637C8(p, q, c.c0, c.c1, (s32)(sc * (f32)c.life - sc * 0.5f * (f32)func_00382468(c.life)), (s32)fh, (s32)fw, 1);
    }
}
/* localdecomp:end func_L03_004117D8 */

/* localdecomp:start func_L03_00411BD0 */
typedef struct { float x, y, z, w; } V4_00411BD0;
extern void func_L03_004117D8(s32, void *);

void func_L03_00411BD0(s32 a) {
    V4_00411BD0 v0, v1;
    *(u128_t *)&v0 = 0;
    *(u128_t *)&v1 = 0;
    v0.x = -2.0f;
    v0.y = 0.6f;
    v1.x = -2.0f;
    v1.y = -0.6f;
    func_L03_004117D8(a, &v0);
    func_L03_004117D8(a, &v1);
}
/* localdecomp:end func_L03_00411BD0 */
