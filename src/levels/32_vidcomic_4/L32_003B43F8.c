#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L32_003B41E8.c, which this file was cut from */
extern s32 D_L32_001DED54;
extern u8 D_L32_001E2440[] __attribute__((section(".sdata")));
extern void func_L32_003B43F8(u8 *, u8 *);

/* localdecomp:start func_L32_003B43F8 */
extern f32 D_L32_001DED60;
__asm__(".extern D_L32_001DED60, 4");
extern f32 D_L32_001DED74;
__asm__(".extern D_L32_001DED74, 4");
extern s32 D_L32_001DED1C;
__asm__(".extern D_L32_001DED1C, 4");
extern s32 D_L32_001DED20;
__asm__(".extern D_L32_001DED20, 4");
extern s32 D_L32_001DED50;
__asm__(".extern D_L32_001DED50, 4");
extern f32 D_L32_001DED8C;
__asm__(".extern D_L32_001DED8C, 4");
extern f32 D_L32_001DED88;
__asm__(".extern D_L32_001DED88, 4");
__asm__(".extern D_L32_001DED54, 4");
extern f32 D_L32_001DED7C;
__asm__(".extern D_L32_001DED7C, 4");
extern f32 D_L32_001DED78;
__asm__(".extern D_L32_001DED78, 4");
extern f32 D_L32_001DED84;
__asm__(".extern D_L32_001DED84, 4");
extern f32 D_L32_001DED80;
__asm__(".extern D_L32_001DED80, 4");
extern f32 D_L32_001DEDC8;
__asm__(".extern D_L32_001DEDC8, 4");
extern f32 D_L32_001DECF0;
__asm__(".extern D_L32_001DECF0, 4");
extern f32 D_L32_001DED70;
__asm__(".extern D_L32_001DED70, 4");
extern f32 D_L32_001DED6C;
__asm__(".extern D_L32_001DED6C, 4");
/* func_L32_003B41E8 with its pointer parameter before the floats (the EABI registers are the same) */
extern void func_L32_003B41E8_003B43F8(void *, void *, f32 *, f32, f32);
extern void func_00382580(void *, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);

typedef struct {
    u8 *moby;
    s32 pad_4;
    s16 life;
    u16 flags;
    s16 pad_c;
    u16 color;
    f32 t;
    f32 u;
    f32 size;
} P_003B43F8;

typedef struct {
    u8 pad_0[3];
    u8 b3;
    u32 rgba;
    u8 alpha;
    u8 pad_9;
    s16 age;
    f32 size;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_003B43F8;

void func_L32_003B43F8(u8 *a0, u8 *a1) {
    S_003B43F8 *s = (S_003B43F8 *)a0;
    P_003B43F8 *p = (P_003B43F8 *)a1;
    u8 *moby;
    u8 *vars;
    u8 *sys;
    f32 sz;
    f32 t;
    f32 k0;
    f32 k1;
    f32 lo;
    f32 hi;
    u16 c;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 d;

    if (p == 0)
        return;
    moby = p->moby;
    sys = D_L32_001E2440;
    if (moby == 0 || sys == 0)
        return;
    vars = *(u8 **)(moby + 0x68);
    if (vars == 0)
        return;
    if (p->flags & 1) {
        p->t = (*(f32 *)(vars + 0x34) - *(f32 *)(vars + 0x3C) * 0.3f < 0.0f) ? 0.0f : *(f32 *)(vars + 0x34) - *(f32 *)(vars + 0x3C) * 0.3f;
        func_L32_003B41E8_003B43F8(moby, &v0, &p->t, -1.0f, 0.01f);
        func_00382580(&s->x, 0.0f, D_L32_001DED60);
        vec_add_ab(&s->x, &s->x, &v0);
        s->y += D_L32_001DED74;
        p->u = func_003824E0(0.0f, 1.0f);
        s->rgba = func_0038DBD8(D_L32_001DED50, *(s32 *)(vars + 0x40) ? D_L32_001DED1C : D_L32_001DED20, func_003824E0(0.0f, 1.0f));
        sz = func_003824E0(D_L32_001DED8C, D_L32_001DED88);
        p->size = sz;
        s->size = sz;
        s->b3 = D_L32_001DED54;
    }
    t = func_L03_0034B440(1, 0, 0, (f32)s->age, (f32)p->life, 1.0f);
    k0 = (1.0f < (1.0f - t) / (1.0f - func_003C4088(D_L32_001DED7C, D_L32_001DED78, p->u)))
        ? 1.0f : (1.0f - t) / (1.0f - func_003C4088(D_L32_001DED7C, D_L32_001DED78, p->u));
    k1 = (1.0f < (1.0f - t) / (1.0f - func_003C4088(D_L32_001DED84, D_L32_001DED80, p->u)))
        ? 1.0f : (1.0f - t) / (1.0f - func_003C4088(D_L32_001DED84, D_L32_001DED80, p->u));
    func_L32_003B41E8_003B43F8(moby, &v0, &p->t, -1.0f, 0.01f);
    p->t = (1.0f < p->t + D_L32_001DEDC8 * k1 * D_L32_001DECF0) ? 1.0f : p->t + D_L32_001DEDC8 * k1 * D_L32_001DECF0;
    func_L32_003B41E8_003B43F8(moby, &v1, &p->t, -1.0f, 0.01f);
    vec_sub_ba(&d, &v1, &v0);
    vec_add_ab(&s->x, &s->x, &d);
    c = p->color;
    lo = (f32)(c & 0xFF);
    hi = lo + (lo + D_L32_001DED70 * (f32)p->life * (f32)(c >> 8) * 0.00390625f);
    s->alpha = func_003C4088(lo, hi, func_L03_0034B148(s->age, p->life, 0.0f));
    s->size = p->size * k0;
    s->rgba = (s->rgba & 0xFFFFFF) | ((s32)(D_L32_001DED6C * k0) << 24);
}
/* localdecomp:end func_L32_003B43F8 */
