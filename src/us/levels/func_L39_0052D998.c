#include "common.h"

/* NTSC-U counterpart of func_L39_0052DF20 (src/levels/shared/L39_0052DF20.c): 38 -> 46; 9 -> 11; 0.04 -> 0.0333333; 37 -> 45 */
/* localdecomp:start func_L39_0052D998 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x660];
    vu0_v4 v660[4];
    vu0_v4 v6A0;
    f32 f6B0[4];
    u8 pad6C0[0x10];
    u8 *f6D0;
    u8 pad6D4[0x3C];
    u16 f710;
    u8 pad712;
    u8 f713;
    u8 pad714;
    u8 f715;
    u8 pad716[4];
    s16 f71A;
    u8 pad71C[0x38];
    s16 f754;
    u8 pad756[0x4E];
    f32 f7A4;
    s32 f7A8;
} A_0052DF20;

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} S_0052DF20;

extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003D00C0(void);
extern void func_L39_00624540(u8 *);
extern void func_L39_00664930(void *, u32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_003888F0(void *, void *, void *);
extern f32 func_003BEBF8(f32 *, f32, f32);

__asm__(".extern D_L39_002440A0, 16");
extern vu0_v4 D_L39_002440A0 __attribute__((section(".sdata")));
extern S_0052DF20 D_L39_0025F840_0052D998;
extern vu0_v4 D_L39_0025F880;
extern f32 D_L39_0024D610[] __attribute__((section(".sdata")));
extern const f32 D_L39_0024AD78[] __attribute__((section(".sdata")));
extern const f32 D_L39_0024AD68[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AC50_0052D998, 4");
extern vu0_v4 D_L39_0024AC50_0052D998[] __attribute__((section(".sdata")));

static __inline__ vu0_v4 *wheel_offset_0052DF20(s32 idx) {
    return &D_L39_0024AC50_0052D998[idx];
}

void func_L39_0052D998(A_0052DF20 *a0) {
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 normal;
    vu0_v4 tmp;
    vu0_v4 gravity;
    vu0_v4 push;
    u8 *veh;
    u8 *moby;
    s32 i;
    s32 was_flag;
    s32 can_flag;
    s32 local;
    s32 n_free;
    s32 hit;
    s32 id;
    f32 sum;
    f32 gap;
    f32 rest;
    f32 k;
    f32 ratio;

    was_flag = a0->f713;
    can_flag = 1;
    veh = a0->f6D0;
    sum = 0.0f;
    moby = *(u8 **)(veh + 0x2D0);
    local = (*(s32 *)(veh + 0x2F8) >> 2) & 1;
    func_003886E8(&gravity, &D_L39_002440A0, -0.002f);
    qzero(&normal);
    if (a0->f7A8 != 0) {
        *(f32 *)(moby + 0x18) += a0->f7A4;
        a0->f7A8 = 0;
    }
    a0->f713 = 0;
    veh[0x300] = 1;
    if (local != 0) can_flag = 1;
    n_free = 4;
    for (i = 0; i < 4; i++) {
        tmp = *wheel_offset_0052DF20(i);
        func_003888C8(&from, &tmp, moby + 0xC0);
        vec_add_ab(&from, &from, moby + 0x10);
        to = from;
        from.z += 1.5f;
        to.z -= D_L39_0024D610[i];
        if (func_003CE740(&from, &to, 0xC24, moby, 0) != 0) {
            hit = func_003D00C0();
            n_free--;
            if (D_L39_0025F840_0052D998.f18 != 0) {
                id = *(s16 *)(D_L39_0025F840_0052D998.f18 + 0xAA);
            } else {
                id = -1;
            }
            if (id >= 0 && local != 0) {
                if (id == 0x1B23 || id == 0x19AF || id == 0x19B2 || id == 0x1A29) {
                    can_flag = 0;
                }
            }
            if (D_L39_0025F840_0052D998.f18 == 0 || id != 0x10C4) {
                if (hit == 0xD || hit == 3 || hit == 0xB) {
                    if (0.0f < *(f32 *)(veh + 0x308)) {
                        a0->f710 |= 8;
                        if (moby[0xBC] != 9 && moby[0xBC] != 10) {
                            if (*(u8 **)(veh + 0x2D8) != 0) {
                                func_L39_00624540(*(u8 **)(veh + 0x2D8));
                            }
                            if (*(u8 **)(veh + 0x2DC) != 0) {
                                func_L39_00624540(*(u8 **)(veh + 0x2DC));
                            }
                        }
                        if (local != 0) {
                            func_L39_00664930(veh, -1, 0xE, -1);
                        }
                    }
                }
            }
            tmp = D_L39_0025F880;
            func_00388830(&normal, &tmp, 1.0f);
            if (normal.z < 0.707f) {
                continue;
            }
            if (a0->f715 == 1 && a0->f71A >= 0x2E && hit == 5) {
                a0->f713 = 1;
            }
            veh[0x300] = 0;
            vec_sub_ba(&tmp, &D_L39_0025F840_0052D998.v20, &from);
            gap = func_00388770(&tmp) - 1.5f;
            if (gap < 0.0f) {
                *(f32 *)(moby + 0x18) -= gap;
                gap = 0.0f;
            }
            rest = D_L39_0024AD78[i] - gap;
            func_003888F0(&push, &normal, veh + 0x1B0);
            gap = D_L39_0024D610[i] - gap;
            ratio = gap / D_L39_0024D610[i];
            k = gap * 0.025f;
            if (a0->f713 != 0 && i >= 2 && a0->f71A >= 0x2E) {
                k *= 0.5f;
            }
            func_003886E8(&tmp, &push, k);
            vec_add_ba(&a0->v660[i], &a0->v660[i], &tmp);
            func_003886E8(&tmp, &D_L39_002440A0, k * (ratio * 0.275f * ratio));
            vec_add_ab(&a0->v6A0, &a0->v6A0, &tmp);
            a0->f6B0[i] = rest;
        } else {
            if (was_flag == 0 || *(s16 *)(veh + 0x302) >= 11) {
                vec_add_ab(&a0->v660[i], &a0->v660[i], &gravity);
            }
            func_003BEBF8(&a0->f6B0[i], D_L39_0024AD68[i], 0.0333333351f);
        }
        sum += D_L39_0024D610[i] - a0->f6B0[i];
    }
    if (n_free >= 2 && local != 0) {
        *(u32 *)(veh + 0x2F8) &= ~0x800;
    }
    if (was_flag != 0 && veh[0x300] != 0 && *(s16 *)(veh + 0x302) < 0x2D) {
        a0->f713 = 1;
    }
    if (a0->f754 == 0) {
        a0->f7A8 = 1;
        func_003BEBF8(&a0->f7A4, (1.0f - sum * 0.25f / D_L39_0024D610[0]) * -0.8f, 0.0333333351f);
        *(f32 *)(moby + 0x18) -= a0->f7A4;
    }
    if (local != 0 && can_flag != 0) {
        *(u32 *)(veh + 0x2F8) |= 0x800;
    } else {
        *(u32 *)(veh + 0x2F8) &= ~0x800;
    }
}
/* localdecomp:end func_L39_0052D998 */
