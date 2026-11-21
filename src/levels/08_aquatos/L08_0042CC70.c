#include "common.h"
#include "vu0.h"

typedef struct LaunchState_0042CC70 {
    /* 0x00 */ f32 direction[4];
    /* 0x10 */ u8 pad10[8];
    /* 0x18 */ f32 radius;
    /* 0x1C */ f32 height;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ s32 flags;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s16 lifetime;
    /* 0x2E */ u8 pad2E[0x0E];
    /* 0x3C */ u8 active;
    /* 0x3D */ u8 pad3D;
    /* 0x3E */ s16 delay;
    /* 0x40 */ f32 heading;
    /* 0x44 */ s32 age;
} LaunchState_0042CC70;

/* localdecomp:start func_L08_0042CC70 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_00382348(u8 *);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L08_0042CC70(u8 *m, LaunchState_0042CC70 *p, s32 animation, s32 flags, s32 frames, f32 angle)
{
    s32 effect;
    s32 active;
    p->direction[0] = func_0038D098(angle) * p->radius;
    p->direction[1] = func_0038D0B0(angle) * p->radius;
    p->direction[2] = p->height;
    p->direction[3] = 1.0f;
    {
        f32 heading = func_0038DAB8(angle, 3.1415927f);
        s16 lifetime = 250;
        active = 1;
        p->age = 0;
        p->delay = 0;
        p->heading = heading;
        p->lifetime = lifetime;
        p->active = active;
    }
    effect = func_00382348(m);
    if (effect && *(f32 *)effect == 0.0f) {
        p->flags |= 0x20;
        *(s32 *)(m + 0x98) = 0;
    }
    if (p->flags & 2)
        func_L01_00444F38(m, animation, frames, flags, active);
    else
        func_003C3A10(m, animation, frames, flags);
}
/* localdecomp:end func_L08_0042CC70 */

/* localdecomp:start func_L08_0042CDA8 */
typedef struct { u8 p0[0x18]; s32 w18; s32 w1C; vu0_v4 v20; vu0_v4 v30; vu0_v4 v40; } G_42CDA8;
extern G_42CDA8 D_L08_001E8A80;
extern u8 *D_L08_001ECB00[];
extern void func_L01_00449088(void *, void *, s32);
extern void func_L01_0044A030(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00449BA8(void *, void *, s32, s32, s32, s32);
extern void func_L01_004495F0(void *, void *, s32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_003D5630(void);
extern void func_L01_003016B0(void *, s32, f32, f32);
extern f32 func_L01_004463D0(void *);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);
extern void func_L01_004455E8(void *, void *, f32, f32, f32, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_003C4B50(void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);

s32 func_L08_0042CDA8(u8 *self, u8 *st) {
    s32 flags = 0;
    vu0_v4 t10, v20, v30, v40, v50, v60;
    f32 d, d2, t74, t78;
    f32 f21;
    f32 r;
    f32 f20, fk;
    f32 bounce;
    f32 tmp;
    f32 sub;
    s32 n;
    vu0_v4 *src, *hit;

    *(f32 *)(st + 8) -= *(f32 *)(st + 0x10);
    if (st[0x2E] == 1 && st[0x2F] != 0) func_L01_00449088(self, st, st[0x2F]);
    if (st[0x2E] == 2 && st[0x2F] != 0) func_L01_0044A030(self, st, st[0x2F], 0x4F804020, 10, 16, 94, 0, 0, 1.2f);
    if (st[0x2E] == 3 && st[0x2F] != 0) func_L01_00449BA8(self, st, st[0x2F], 0x4F804020, 2, 3);
    if (st[0x2E] == 4 && st[0x2F] != 0) func_L01_004495F0(self, st, st[0x2F]);
    d = func_0038CED8(st);
    {
        f32 ka = *(s16 *)(st + 0x3E) == 2 ? 0.0f : *(f32 *)(st + 0x4C);
        f32 kb = *(f32 *)(st + 0x14);
        func_003C4138(&d, ka, kb);
    }
    func_0038CFB8(st, st, d);
    if (*(f32 *)(st + 0x1C) < *(f32 *)(st + 8)) *(f32 *)(st + 8) = *(f32 *)(st + 0x1C);
    v20 = *(vu0_v4 *)(self + 0x10);
    v20.z += *(f32 *)(st + 0x28);
    f21 = func_003C3D30(&v20, 0, 0, 0.5f);
    if (func_003D5630() == 0) {
        if (*(f32 *)(st + 0x5C) == 0.0f && f21 <= v20.z && v20.z + *(f32 *)(st + 8) < f21) {
            *(f32 *)(st + 0x5C) = 1.0f;
            v20.z = f21;
            func_L01_003016B0(&v20, 3, 3.0f, 1.025f);
        }
        f21 = func_L01_004463D0(self + 0x10);
    } else {
        if (!(*(u32 *)(st + 0x24) & 0x10) && *(s16 *)(st + 0x3E) != 2) goto after;
        vec_add_ab(&v30, self + 0x10, st);
        r = func_L01_004463D0(&v30);
        if (r < f21 - 0.25f) func_0038CFB8(st, st, 0.0f);
    }
after:
    if (*(f32 *)(st + 0x5C) != 0.0f) {
        if (*(f32 *)(st + 0x5C) < 4.0f) func_0038CE20(st, st, 0.7f);
        if (*(f32 *)(st + 0x5C) < 7.0f) {
            *(f32 *)(st + 0x5C) += 1.0f;
            *(f32 *)(st + 0x10) *= 0.75f;
        }
    }
    if (*(f32 *)(self + 0x10) < 2.0f || 1021.0f < *(f32 *)(self + 0x10) || *(f32 *)(self + 0x14) < 2.0f ||
        1021.0f < *(f32 *)(self + 0x14) || *(f32 *)(self + 0x18) < 2.0f || 1021.0f < *(f32 *)(self + 0x18)) {
        flags = 0x100;
    }
    if (*(f32 *)(st + 0x54) != -1.0f && *(f32 *)(st + 0x50) != -1.0f) {
        switch (*(s16 *)(st + 0x3E)) {
        case 0:
            f20 = fabs_asm(*(f32 *)(st + 8) / *(f32 *)(st + 0x10));
            if (2.0f < f20) {
                f32 q = (*(f32 *)(st + 0x50) - func_L01_004395E0(self)) / f20;
                if (0.0f < q) func_003C4138((f32 *)(self + 0x48), q, 0.120000005f);
            }
            break;
        case 1:
            if (*(f32 *)(st + 0x54) <= func_L01_004395E0(self)) {
                *(s32 *)(self + 0x48) = 0;
            } else {
                f32 a = *(f32 *)(st + 0x10) * -0.5f;
                f32 q;
                f20 = 60.0f;
                if (func_L01_004461B8(&t74, &t78, a, *(f32 *)(st + 8) - a, *(f32 *)(self + 0x18) - f21) > 0) {
                    if (0.0f < t74 && t74 < f20) f20 = t74;
                }
                if (f20 < 0.0001f) f20 = 0.0001f;
                q = (*(f32 *)(st + 0x54) - func_L01_004395E0(self)) / f20;
                if (q > 2.0f) q = 2.0f;
                else if (q < 0.0f) q = 0.0f;
                func_003C4138((f32 *)(self + 0x48), q, 0.120000005f);
            }
            break;
        case 2:
            *(f32 *)(self + 0x48) = 1.0f;
            break;
        }
    }
    if (self[0x60] & 2) flags |= 0x40;
    if (!(*(u32 *)(st + 0x24) & 4)) {
        func_L01_004455E8(self, st + 0x44, *(f32 *)(st + 0x40), 0.02f, 0.3f, *(f32 *)(st + 0x48));
    }
    t10 = *(vu0_v4 *)(self + 0x10);
    t10.z += *(f32 *)(st + 0x28);
    vec_add_ab(self + 0x10, self + 0x10, st);
    v30 = *(vu0_v4 *)(self + 0x10);
    v30.z += *(f32 *)(st + 0x28);
    vec_add_ab(&v40, &v30, st);
    n = func_003D4D00(&v40, 0x10, self, 0, (f32)*(s32 *)(st + 0x20) * 0.0010742188f);
    if (n > 0) {
        u8 **pp = D_L08_001ECB00;
        s32 i = n;
        do {
            if (func_003C4B50(*pp) != 0) func_L01_00446A70(*pp, self, 0x10000, self + 0x10, st, 1.0f);
            i--;
            pp++;
        } while (i != 0);
    }
    fk = 0.0009765625f;
    if (func_0038CEA8(st) > (f32)*(s32 *)(st + 0x20) * fk) {
        func_003D3CB0(&t10, &v30, 0x24, self, 0);
        src = &D_L08_001E8A80.v20;
        v30 = *src;
    }
    if (func_L01_003FB640(&v30, 0x24, self, (f32)*(s32 *)(st + 0x20) * fk) != 0) {
        hit = &D_L08_001E8A80.v30;
        *(vu0_v4 *)(self + 0x10) = *hit;
        flags |= 2;
        sub = *(f32 *)(st + 0x28);
        tmp = *(f32 *)(self + 0x18) - sub;
        *(f32 *)(self + 0x18) = tmp;
        func_0038CF68(&v50, hit + 1, 1.0f);
        if (0.707f <= v50.z) {
            bounce = func_0038CE68(st, &v50);
            if (bounce < 0.0f) {
                if (D_L08_001E8A80.w18 == 0 || D_L08_001E8A80.w1C > 0) {
                    flags |= 1;
                    *(s16 *)(st + 0x3E) = 2;
                }
                func_0038CF68(&v60, &v50, bounce);
                vec_sub_ab(st, st, &v60);
                if (*(s16 *)(st + 0x3E) == 2) {
                    d2 = func_0038CEA8(st);
                    func_003C4138(&d2, 0.0f, *(f32 *)(st + 0x10));
                    func_0038CF68(st, st, d2);
                }
            }
        } else {
            tmp = func_0038CE68(st, &v50);
            if (tmp < 0.0f) {
                func_0038CF68(&v60, &v50, tmp * -(*(f32 *)(st + 0x30) + 1.0f));
                vec_add_ab(st, st, &v60);
            }
        }
    }
    if (*(s16 *)(st + 0x3E) == 0 && *(f32 *)(st + 8) < 0.0f) *(s16 *)(st + 0x3E) = 1;
    return flags;
}
/* localdecomp:end func_L08_0042CDA8 */
