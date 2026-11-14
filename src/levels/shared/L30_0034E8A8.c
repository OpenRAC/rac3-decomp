#include "common.h"

/* declared by functions of L30_0034E420.c, which this file was cut from */
typedef struct { s16 a, b; f32 c; s32 d, e, f; void *g; } S_0034E710;
extern S_0034E710 D_L30_001E1260 __attribute__((section(".sdata")));
extern void func_L30_0034E8A8(void *, void *);

/* localdecomp:start func_L30_0034E8A8 */
#include "vu0.h"
typedef struct {
    u8 pad0[3];
    u8 alpha;
    s32 col0;
    u8 pad8[2];
    s16 hA;
    s32 col1;
    f32 p0[4];
    f32 p1[4];
} S_0034E8A8_A;
typedef struct {
    u8 *moby;
    void *p4;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 padB;
    f32 angle;
} S_0034E8A8_B;
extern f32 D_L30_001DD558; __asm__(".extern D_L30_001DD558, 4");
extern u8 D_L30_001DD55C; __asm__(".extern D_L30_001DD55C, 1");
extern f32 D_L30_001DD560; __asm__(".extern D_L30_001DD560, 4");
extern f32 D_L30_001DD564; __asm__(".extern D_L30_001DD564, 4");
extern f32 D_L30_001DD570; __asm__(".extern D_L30_001DD570, 4");
extern f32 D_L30_001DD57C; __asm__(".extern D_L30_001DD57C, 4");
extern f32 D_L30_001DD580; __asm__(".extern D_L30_001DD580, 4");
extern void func_L30_0034E420(void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
void func_L30_0034E8A8(void *arg0, void *arg1) {
    S_0034E8A8_A *a0 = arg0;
    S_0034E8A8_B *a1 = arg1;
    u8 *moby;
    S_0034E710 *sys;
    void *m68;
    f32 pos[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 t, s, r, f, d0, d1;
    s32 c;
    f32 y;
    if (a1 == 0) {
        return;
    }
    moby = a1->moby;
    sys = &D_L30_001E1260;
    m68 = *(void **)(moby + 0x68);
    if (moby == 0 || m68 == 0 || sys == 0) {
        return;
    }
    func_L30_0034E420(moby, pos);
    if (a1->b9 & 1) {
        if (moby[0x20] >= 0xFD) {
            a0->hA = 0;
            return;
        }
        a1->angle = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        a0->alpha = D_L30_001DD55C;
    }
    t = func_L03_0034B440(0, 0, 0, (f32)a0->hA, (f32)(a1->b8 * 4), 1.0f);
    s = func_003C4088(D_L30_001DD564, D_L30_001DD560, (f32)a1->bA * 0.00390625f);
    f = (D_L30_001DD570 + s) * t;
    r = (D_L30_001DD570 < f) ? D_L30_001DD570 : f;
    v[0] = func_0038D098(a1->angle) * r;
    v[2] = func_0038D0B0(a1->angle) * r;
    v[1] = 0.0f;
    vec_add_ab(a0->p0, pos, v);
    f = D_L30_001DD570 * t - (1.0f - t) * s;
    y = v[1];
    r = (f < y) ? y : f;
    v[0] = func_0038D098(a1->angle) * r;
    v[2] = func_0038D0B0(a1->angle) * r;
    v[1] = y;
    vec_add_ab(a0->p1, pos, v);
    d0 = func_0038CF00(pos, ((S_0034E8A8_A *)arg0)->p0) / D_L30_001DD570;
    d1 = func_0038CF00(pos, a0->p1) / D_L30_001DD570;
    a0->col0 = func_0038DBD8(func_L30_0034E4D0(moby, 1), func_L30_0034E4D0(moby, 0), d0);
    c = func_0038DBD8(func_L30_0034E4D0(moby, 1), func_L30_0034E4D0(moby, 0), d1);
    a0->col0 = (a0->col0 & 0xFFFFFF) | 0x80000000;
    a0->col1 = (c & 0xFFFFFF) | 0x80000000;
    a0->p0[3] = func_003C4088(D_L30_001DD57C, D_L30_001DD580, t);
    a0->p1[3] = D_L30_001DD558;
}
/* localdecomp:end func_L30_0034E8A8 */
