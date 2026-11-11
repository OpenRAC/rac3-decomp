#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L17_003B3790 */
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE38(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L17_003B3790(u8 *self) {
    vu0_v4 a, b, d, c;

    func_0038CE20(&a, self + 0xD0, -0.1f);
    func_0038CE20(&b, self + 0xE0, 0.03f);
    vec_add_ab(&c, &a, &b);
    d = c;
    a = c;
    func_L01_00451FE0(self, 0xF, &a, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_0038CE38(&d, &a, 0.1f);
    func_003A52A0(0, 0, self);
    self[0x20] = 3;
    *(u16 *)(self + 0x34) |= 1;
    *(s32 *)(self + 0x98) = 0;
}
/* localdecomp:end func_L17_003B3790 */

/* localdecomp:start func_L17_003B38B0 */
typedef struct { u8 p0[0x68]; u8 *f68; } S_38B0_O;
extern u8 D_001A4C60[];
extern f32 D_001A4C68[];
extern u8 *D_L17_001DF180;
__asm__(".extern D_L17_001DF180, 16");
extern f32 func_0038CF00(void *, void *);
s32 func_L17_003B38B0(S_38B0_O *self) {
    u8 *d = self->f68;
    s32 v;
    if (*(s32 *)(d + 0xC0) != -1) {
        f32 a = func_0038CF00(D_001A4C60, d + 0x70);
        f32 b = func_0038CF00(D_001A4C60, D_L17_001DF180 + (*(s32 *)(d + 0xC0) << 7) + 0x30);
        v = 0;
        if (!(b < a)) v = 1;
        return v;
    } else {
        f32 f = *(f32 *)(d + 0xA4);
        f32 x, d1, d2;
        if (f == 0.0f) return 2;
        x = *(f32 *)((u8 *)self + 0x18);
        d1 = fabs_asm(D_001A4C68[0] - x);
        d2 = fabs_asm(D_001A4C68[0] - (x + f));
        v = 0;
        if (!(d2 < d1)) v = 1;
        return v;
    }
}
/* localdecomp:end func_L17_003B38B0 */

/* localdecomp:start func_L17_003B3980 */
typedef struct { u8 p0[0x70]; f32 pos[4]; u8 p80[0x28]; s32 ids[7]; f32 cum[7]; } S_3980_P;
typedef struct { u8 p0[0x68]; S_3980_P *f68; } S_3980_O;
extern u8 *D_L17_001DF180;
__asm__(".extern D_L17_001DF180, 16");
extern f32 func_0038CF00(void *, void *);
void func_L17_003B3980(S_3980_O *self) {
    S_3980_P *d = self->f68;
    f32 *cum;
    f32 total, inv;
    s32 i;

    cum = d->cum;
    total = func_0038CF00(d->pos, D_L17_001DF180 + (d->ids[0] << 7) + 0x30);
    cum[0] = total;
    for (i = 1; i < 7; i++) {
        total += func_0038CF00(D_L17_001DF180 + (d->ids[i - 1] << 7) + 0x30, D_L17_001DF180 + (d->ids[i] << 7) + 0x30);
        d->cum[i] = total;
    }
    inv = 1.0f / total;
    for (i = 0; i < 6; i++) {
        cum[i] *= inv;
    }
    cum[6] = 1.0f;
}
/* localdecomp:end func_L17_003B3980 */

/* localdecomp:start func_L17_003B3A78 */
typedef struct { u8 p0[0x70]; vu0_v4 a; vu0_v4 b; u8 p90[4]; f32 f94; u8 p98[0x10]; s32 ids[7]; f32 cum[7]; } S_3A78_P;
typedef struct { u8 p0[0x30]; vu0_v4 a; u8 p40[0x30]; vu0_v4 b; } N_3A78;
extern u8 *D_L17_001DF180;
__asm__(".extern D_L17_001DF180, 16");
extern f32 func_0038D098(f32);
extern void func_L17_00431AB0(void *, void *, void *, void *, s32, f32);
void func_L17_003B3A78(u8 *self) {
    S_3A78_P *d = *(S_3A78_P **)(self + 0x68);
    vu0_v4 v[2];
    f32 c, u, prev;
    s32 i;

    if (1.0f < d->f94) {
        d->f94 = 1.0f;
    } else if (d->f94 < 0.0f) {
        d->f94 = 0.0f;
    }
    c = func_0038D098(d->f94 * 3.1415927f);
    u = (1.0f - c) * 0.5f;
    i = 0;
    while (d->cum[i] < u) i++;
    prev = 0.0f;
    if (i == 0) {
        v[0] = d->a;
        v[1] = d->b;
    } else {
        prev = d->cum[i - 1];
        v[0] = ((N_3A78 *)D_L17_001DF180)[d->ids[i - 1]].a;
        v[1] = ((N_3A78 *)D_L17_001DF180)[d->ids[i - 1]].b;
    }
    func_L17_00431AB0(self + 0x10, self + 0xF0, &v[0], &v[1], d->ids[i], (u - prev) / (d->cum[i] - prev));
}
/* localdecomp:end func_L17_003B3A78 */

INCLUDE_ASM("asm/levels", func_L17_003B3BF0);
