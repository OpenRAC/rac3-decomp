#include "common.h"

/* localdecomp:start func_L32_003A0370 */
#include "vu0.h"

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 D_L32_001DE70C;
extern s32 D_L32_001DE710;
extern f32 D_L32_001DE728;
extern f32 D_L32_001DE724;
extern f32 D_L32_001DE714;
extern s32 D_L32_001DE708;
extern f32 D_L32_001DE720;
extern s32 D_L32_001DE6DC;
extern s32 D_L32_001DE6E8;

__asm__(".extern D_L32_001DE70C, 4");
__asm__(".extern D_L32_001DE710, 4");
__asm__(".extern D_L32_001DE728, 4");
__asm__(".extern D_L32_001DE724, 4");
__asm__(".extern D_L32_001DE714, 4");
__asm__(".extern D_L32_001DE708, 4");
__asm__(".extern D_L32_001DE720, 4");
__asm__(".extern D_L32_001DE6DC, 4");
__asm__(".extern D_L32_001DE6E8, 4");

typedef struct {
    u8 pad0[0x78];
    s32 f78;
    u8 pad7C[0x200 - 0x7C];
    void *parts[7];
    s32 f21C;
} Vars_003A0370;

typedef struct {
    u8 pad0[0x10];
    vu0_q pos;
    u8 pad20[0x68 - 0x20];
    Vars_003A0370 *vars;
} Moby_003A0370;

typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 f8;
    s16 fA;
    f32 fC;
    vu0_q pos;
} Dst_003A0370;

void func_L32_003A0370(Dst_003A0370 *d, u8 *s) {
    Moby_003A0370 *m;
    Vars_003A0370 *vars;
    f32 f20;
    f32 sc;
    s32 on;
    vu0_v4 a;
    vu0_v4 b;

    if (s == 0) {
        return;
    }
    m = *(Moby_003A0370 **)(s + 0x0);
    on = *(s32 *)(s + 0x4);
    vars = m->vars;
    if (m == 0 || on == 0) {
        return;
    }
    if (*(u16 *)(s + 0xA) & 1) {
        if ((u32)(vars->f21C - 2) < 2 && func_003824E0(0.0f, 1.0f) < 0.5f) {
            *(s16 *)(s + 0xC) = 6;
        } else {
            *(s16 *)(s + 0xC) = func_00382498(0, 5);
        }
        *(s32 *)(s + 0x18) = func_L30_0034DBA0(D_L32_001DE70C, D_L32_001DE710);
        *(f32 *)(s + 0x1C) = func_003824E0(D_L32_001DE728, D_L32_001DE724);
    }
    if (vars->parts[*(s16 *)(s + 0xC)] == 0) {
        return;
    }
    f20 = func_L03_0034B148(d->fA, *(s16 *)(s + 0x8), 0.0f);
    if (*(s16 *)(s + 0xC) == 6) {
        d->pos = m->pos;
    } else {
        func_003C2F58(vars->parts[*(s16 *)(s + 0xC)], 0, &a);
        func_003C2F58(vars->parts[*(s16 *)(s + 0xC)], 1, &b);
        vec_add_ab(&d->pos, &a, &b);
        func_0038CE20(&d->pos, &d->pos, 0.5f);
    }
    d->f4 = func_0038DBD8(func_L03_0034B148(d->fA, *(s16 *)(s + 0x8), D_L32_001DE714), *(s32 *)(s + 0x18), D_L32_001DE708);
    d->f8 = *(u8 *)(s + 0xE);
    sc = func_003C4088(*(f32 *)(s + 0x1C), D_L32_001DE720, f20);
    d->fC = sc;
    if (vars->f21C == 0 && *(s16 *)(s + 0xC) == 6) {
        d->fC = sc * ((1.0f - (f32)vars->f78 / (f32)D_L32_001DE6DC) * 0.5f);
    }
    if (vars->f21C == 3 && *(s16 *)(s + 0xC) == 6) {
        d->fC = d->fC * ((1.0f - (f32)vars->f78 / (f32)D_L32_001DE6E8) * 0.5f + 0.5f);
    }
}
/* localdecomp:end func_L32_003A0370 */
