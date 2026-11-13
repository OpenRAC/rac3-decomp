#include "common.h"

/* localdecomp:start func_L48_003DF798 */
#include "vu0.h"
typedef struct { f32 x, y; } F2_3DF798;
typedef struct {
    u8 p0[0x10]; s32 w10; s32 w14; f32 f18; u8 p1C[4]; f32 f20; f32 f24; u8 p28[4]; f32 f2C;
    f32 f30; s32 w34; u8 p38[8]; f32 f40; f32 f44; f32 f48; f32 f4C; u8 p50[0x10]; vu0_v4 v60;
} S_3DF798;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_3DF798 *p68; } M_3DF798;
extern s32 D_L48_00275A00[];
extern vu0_v4 D_L48_00249B40;
extern F2_3DF798 D_L48_00249310[1];
extern F2_3DF798 D_L48_002469F0[1];
__asm__(".extern D_L48_002469F0, 8");
extern F2_3DF798 D_L48_002469D0[1];
__asm__(".extern D_L48_002469D0, 8");
extern f32 D_L48_002469C0[2];
__asm__(".extern D_L48_002469C0, 8");
extern f32 D_L48_002469B0[2];
__asm__(".extern D_L48_002469B0, 8");
extern s32 D_L48_0024112C;
extern f32 D_L48_0024119C;
extern void func_L48_003E05D0(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_00327C70(f32 *, f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern s32 func_L02_00327CC0(void *);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L48_003DFAD0();
void func_L48_003DF798(M_3DF798 *m) {
    S_3DF798 *s = m->p68;
    vu0_v4 d;
    vu0_v4 v;
    F2_3DF798 *tab;
    f32 *sc;
    s32 j;
    f32 r;
    if (m->b20 == 0) func_L48_003E05D0(m, s);
    if (D_L48_00275A00[0] != s->w34) return;
    r = s->f18;
    vec_sub_ba(&d, &D_L48_00249B40, &s->v60);
    s->v60 = D_L48_00249B40;
    if (!(s->f24 < D_L48_00249B40.z)) return;
    if (s->w10 != 0 && s->w14 >= 3) {
        tab = D_L48_002469F0;
        sc = D_L48_002469C0;
    } else {
        tab = D_L48_002469D0;
        sc = D_L48_002469B0;
    }
    for (j = 0; j < s->w14; j++) {
        func_0038CE20(&v, &d, (sc[j] * 1.5f) / (r * 5.0f));
        func_L02_00327C70(&D_L48_00249310[j].x, v.x, v.y);
    }
    s->f2C = s->f20 + func_0038D0B0((f32)(D_L48_0024112C % 360) * 0.017444445f - 3.14f) * s->f30;
    for (j = 0; j < s->w14; j++, tab++) {
        f32 t = D_L48_0024119C * s->f40;
        func_L02_00327C70(&D_L48_00249310[j].x, tab->x * t, tab->y * t);
        if (s->f44 != 0.0f) {
            f32 x;
            s->f4C = func_0038DAB8(s->f4C, s->f48);
            t = s->f4C;
            if (j & 1) t = -t;
            x = tab->x * s->f44 * func_0038D098(t);
            func_L02_00327C70(&D_L48_00249310[j].x, x, tab->y * s->f44 * func_0038D0B0(t));
        }
    }
    if (func_L02_00327CC0(s)) func_L01_004048D0(func_L48_003DFAD0, m);
    else func_L01_00404808(func_L48_003DFAD0, m);
}
/* localdecomp:end func_L48_003DF798 */
