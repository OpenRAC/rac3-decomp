#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } V4_003B5710;

/* localdecomp:start func_L03_003C4EE8 */
extern u8 D_L03_001E2440[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);

void func_L03_003C4EE8(f32 *pos, s32 count) {
    f32 velocity[4], origin[4];
    V4_003B5710 direction;
    V4_003B5710 axis;
    f32 offset[4];
    f32 size, zero, angle, k;
    s32 sign;
    s32 i;
    u8 *p;
    vec_sub_ab(&direction, D_L03_001E2440, pos);
    func_0038CF68(offset, &direction, 0.3f);
    direction.z = 0;
    axis.x = 0;
    axis.y = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    i = 0;
    if (count > 0) {
    k = 0.020000001f;
    zero = direction.z;
    for (; i < count; i++) {
        size = func_003824E0(0.5f, 2.0f);
        sign = func_00382468(2);
        if (!sign) sign--;
        angle = func_003824E0(-1.0471976f, 1.0471976f);
        func_0038D890(velocity, &direction, &axis, angle);
        func_0038CF68(velocity, velocity, func_003824E0(0.05f, 3.0f) * k);
        velocity[2] = func_003824E0(1.0f, 5.0f) * k;
        vec_add_ab(origin, pos, offset);
        pos[0] += func_L01_00443A18(zero, 0.15f);
        pos[1] += func_L01_00443A18(zero, 0.15f);
        pos[2] += func_L01_00443A18(zero, 0.15f);
        p = func_L01_0046B458(origin, size * 0.1f, 0x32, size, 0.0028800003f, 0xDD10FFFF, 0, sign, velocity, 0);
        if (p) p[9] = 0x74;
        p = func_L01_0046B458(origin, size * 0.07f, 0x32, size * 0.7f, 0.0028800003f, 0xDD10FFFF, 1, -sign, velocity, 0);
        if (p) p[9] = 0x74;
    }
    }
}
/* localdecomp:end func_L03_003C4EE8 */

/* localdecomp:start func_L03_003C5190 */
typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[4]; f32 f2C; } S_003C5190;
extern s32 D_L03_001DF4C0;
extern f32 D_L03_001DEDB4;
__asm__(".extern D_L03_001DEDB4, 4");
extern f32 D_L03_001DEDB8;
__asm__(".extern D_L03_001DEDB8, 4");
extern f32 D_L03_001DEDBC;
__asm__(".extern D_L03_001DEDBC, 4");
extern f32 D_L03_001DEDC0;
__asm__(".extern D_L03_001DEDC0, 4");
extern s32 D_L03_001DEDC4;
__asm__(".extern D_L03_001DEDC4, 4");
extern s32 D_L03_001DEDC8;
__asm__(".extern D_L03_001DEDC8, 4");
extern s32 D_L03_001DEDCC;
__asm__(".extern D_L03_001DEDCC, 4");
extern f32 D_L03_001DEDD0;
__asm__(".extern D_L03_001DEDD0, 4");
extern f32 D_L03_001DEDD4;
__asm__(".extern D_L03_001DEDD4, 4");
extern s32 D_L03_001DEDD8;
__asm__(".extern D_L03_001DEDD8, 4");
extern s32 D_L03_001DEDDC;
__asm__(".extern D_L03_001DEDDC, 4");
extern f32 D_L03_001DEDE0;
__asm__(".extern D_L03_001DEDE0, 4");
extern f32 D_L03_001DEDE4;
__asm__(".extern D_L03_001DEDE4, 4");
extern s32 D_L03_001DEDE8;
__asm__(".extern D_L03_001DEDE8, 4");
extern s32 D_L03_001DEDEC;
__asm__(".extern D_L03_001DEDEC, 4");
extern s32 D_L03_001DEDF0;
__asm__(".extern D_L03_001DEDF0, 4");
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

static inline s32 pal_time_003C5190(s32 t) { return (t * 5 + 2) / 6; }
static inline f32 pulse_003C5190(s32 j) {
    s32 t = (D_L03_001DF4C0 + j * 20) & 0xFF;
    {
        s32 p = 212 - pal_time_003C5190(t);
        {
            f32 f = 0.5f - (f32)p / 212.0f;
            return fabs_asm(f);
        }
    }
}
static inline f32 ring_scale_003C5190(S_003C5190 *self, s32 j) {
    f32 base = D_L03_001DEDE0 + (f32)j * D_L03_001DEDE4;
    {
        f32 k = self->f2C / *(f32 *)(self->p24 + 0x24);
        return base * k;
    }
}
#define LERPCOL_003C5190(a, b, t) ({ s32 _a = (a), _b = (b); f32 _t = (t); func_0038DBD8(_a, _b, _t); })
#define SPRITE_003C5190(p, c, al, x, y, s) ({ s32 _c = (c), _al = (al); f32 _s = (s); func_L01_0046C2E8(p, _c, _al, x, y, 2, 0, 0, _s); })
static inline void vstep_003C5190(vu0_v4 *a, vu0_v4 *b) { vec_add_ab(a, a, b); }
static inline s32 ring_alpha_003C5190(s32 j) {
    s32 v = (u8)D_L03_001DF4C0;
    if (j & 2) v = v << 1;
    if (j & 1) v = 255 - v;
    return v & 0xFF;
}

void func_L03_003C5190(S_003C5190 *self) {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 w;
    vu0_v4 q;
    vu0_v4 r;
    s32 i;
    s32 j;

    func_0038D000(&pos, &D_L03_001DEDF0, (u8 *)self + 0xC0);
    vec_add_ab(&pos, &pos, (u8 *)self + 0x10);
    if (func_00382468(4) == 0) {
        func_L01_00443B88(&vel, D_L03_001DEDB4 * 0.020000001f, D_L03_001DEDB8 * 0.020000001f);
        func_L01_0046C470(&pos, &vel, D_L03_001DEDC8, D_L03_001DEDD0, D_L03_001DEDC4, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        for (i = 0; i < 3; i++) {
            func_L01_00443B88(&w, D_L03_001DEDBC * 0.020000001f, D_L03_001DEDC0 * 0.020000001f);
            vec_add_ab(&vel, &vel, &w);
            func_L01_0046C470(&pos, &vel, D_L03_001DEDCC, D_L03_001DEDD4, D_L03_001DEDC4, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&q, D_L03_001E2440, &pos);
    func_0038CF68(&q, &q, -0.300000012f);
    func_0038CF68(&r, &q, 0.100000001f);
    vec_add_ab(&q, &q, &pos);
    for (j = 0; j < 4; j++) {
        s32 col = LERPCOL_003C5190(D_L03_001DEDD8, D_L03_001DEDDC, pulse_003C5190(j));
        SPRITE_003C5190(&q, col, ring_alpha_003C5190(j), D_L03_001DEDEC, D_L03_001DEDE8, ring_scale_003C5190(self, j));
        vstep_003C5190(&q, &r);
    }
}
/* localdecomp:end func_L03_003C5190 */
