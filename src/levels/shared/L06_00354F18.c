#include "vu0.h"
#include "common.h"

/* localdecomp:start func_L06_00354F18 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
extern s32 func_L01_004561E0(void *);
extern f32 func_003C3D30(void *, s32, void *, f32);
s32 func_L06_00354F18(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 f;
    if (*(s32 *)(v + 0x26C) == 2 && (a0[0x43] == 2 || a0[0x43] == 0x11)) {
        if ((a0[0x60] & 2) || a0[0x43] == 2) {
            if (*(s32 *)(v + 0x33C) != 0) {
                func_L06_00351930(a0, v, 0x11, 0, 10);
                *(s32 *)(v + 0x33C) = 0;
            } else if (0.0f < *(f32 *)(v + 0x338)) {
                func_L01_004450F0(a0, 1, 3);
                func_L06_00351930(a0, v, 2, 0, 10);
            } else {
                func_L01_004450F0(a0, 1, 5);
                func_L06_00351930(a0, v, 2, 0, 10);
            }
        }
        return 1;
    }
    if (func_L01_004561E0(a0)) {
        func_L06_00351930(a0, v, 1, 0, 10);
    } else if (a0[0x43] == 1 && (a0[0x60] & 2)) {
        func_L06_00351930(a0, v, 2, 0, 10);
    }
    f = func_003C3D30(a0 + 0x10, 0, a0, 1.0f);
    if (0.0f < f) {
        *(f32 *)(a0 + 0x18) = f;
    }
    return 0;
}
/* localdecomp:end func_L06_00354F18 */

/* localdecomp:start func_L06_003550B0 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
s32 func_L06_003550B0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    f32 f;
    if (a0[96] & 2) {
        func_L01_004450F0(a0, 1, 0);
        func_L06_00351930(a0, s1, 0, 0, 0);
        f = (*(f32 *)(s1 + 788) + *(f32 *)(s1 + 796)) * 0.5f;
        if (*(f32 *)(s1 + 616) < f) {
            *(f32 *)(s1 + 616) = f;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003550B0 */

/* localdecomp:start func_L06_00355148 */
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern int func_L01_004561E0(void *a0);
extern void func_L06_00353208(float f, void *a0, void *a1);

int func_L06_00355148(void *moby)
{
    char *pv = *(char **)((char *)moby + 104);

    if (func_L01_004561E0(moby)) {
        func_L06_00353208(*(float *)(pv + 824), moby, pv);
        *(int *)(pv + 824) = 0;
        ((void (*)(void *a0, int a1, int a2))func_L01_004450F0)(moby, 3, -1);
        return 1;
    }
    if (*(unsigned char *)((char *)moby + 32) == 15) {
        ((void (*)(void *a0, int a1, int a2))func_L01_004450F0)(moby, 1, 5);
        ((void (*)(void *a0, void *a1, int a2, int a3, int t0))func_L06_00351930)(moby, pv, 2, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00355148 */

INCLUDE_ASM("asm/levels", func_L06_003551E8);

/* localdecomp:start func_L06_003552F8 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L06_00354270(void *, void *);
extern void func_L06_0045B1F8(void *, void *, void *, void *);
extern f32 func_L06_0045B290(void *, s32, s32, f32, f32);
extern void func_L06_00353208(float f, void *a0, void *a1);
extern vu0_v4 D_L06_001E1680[];

void func_L06_003552F8(u8 *a0, u8 *v, s32 a2, s32 a3) {
    vu0_v4 p;
    vu0_v4 save;
    vu0_v4 d;
    f32 dot;
    f32 t;
    f32 bestYaw;
    s32 bestKey;
    s32 best;
    s32 score;
    s32 i;
    s32 r;

    if (*(s32 *)(v + 0x270) != 0) {
        func_L01_004450F0(a0, 0x12, -1);
        return;
    }
    bestYaw = 0.0f;
    bestKey = -1;
    *(s32 *)(v + 0x4BC) = a2;
    *(s32 *)(v + 0x4C0) = a3;
    best = 0;
    i = 0;
    while (i < 5) {
        r = func_L06_00354270(v + 0x4B0, v + 0x4F0);
        if (r == 0) {
            func_L01_004450F0(a0, 0x12, -1);
            return;
        }
        if (r < 0) {
            break;
        }
        p = *(vu0_v4 *)(v + 0x4A0);
        score = 0;
        p.z = func_003C3D30(&p, 0, 0, 0.5f) + 5.0f;
        if (func_003D3CB0(&p, v + 0x220, 2, a0, 0)) {
            score = 300;
        }
        vec_sub_ab(&d, v + 0x4A0, &D_L06_001E1680[0]);
        func_0038CF68(&d, &d, 1.0f);
        dot = func_0038CE68(&d, &D_L06_001E1680[2]);
        if (dot < 0.0f) {
            dot *= 0.25f;
        } else if (dot < 0.5f) {
            dot = dot * dot;
        } else {
            dot *= 1.5f;
        }
        score += (s32)(dot * 250.0f);
        if (*(s16 *)(v + 0x23C) != 0) {
            t = (func_0038CF38(a0 + 0x10, v + 0x220) - *(f32 *)(v + 0x4C4)) /
                (*(f32 *)(v + 0x4C8) - *(f32 *)(v + 0x4C4));
            if (1.0f < t) {
                t = 1.0f;
            } else if (t < 0.0f) {
                t = 0.0f;
            }
            score += (s32)(t * 100.0f);
        }
        if (5.0f < func_0038CF38(a0 + 0x10, v + 0x4A0)) {
            score += 150;
        }
        if (score >= 0x2EF) {
            break;
        }
        if (best < score) {
            best = score;
            save = *(vu0_v4 *)(v + 0x4A0);
            bestYaw = *(f32 *)(v + 0x368);
            bestKey = *(s32 *)(v + 0x364);
        }
        i++;
    }
    if (i == 5) {
        if (best <= 0) {
            func_L01_004450F0(a0, 0x12, -1);
            return;
        }
        *(vu0_v4 *)(v + 0x4A0) = save;
        *(f32 *)(v + 0x368) = bestYaw;
        *(s32 *)(v + 0x364) = bestKey;
    }
    *(s32 *)(v + 0x36C) = 0x12;
    func_L06_0045B1F8(*(void **)(v + 0x358), a0 + 0x10, v + 0x344, v + 0x348);
    func_L06_00353208(func_L06_0045B290(*(void **)(v + 0x358), *(s32 *)(v + 0x344), *(s32 *)(v + 0x364),
                                        *(f32 *)(v + 0x348), *(f32 *)(v + 0x368)),
                      a0, v);
    func_L01_004450F0(a0, 3, -1);
}
/* localdecomp:end func_L06_003552F8 */

/* localdecomp:start func_L06_00355610 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L06_00354270(void *, void *);
extern void func_L06_0045B1F8(void *, void *, void *, void *);
extern f32 func_L06_0045B290(void *, s32, s32, f32, f32);
extern void func_L06_00353208(float f, void *a0, void *a1);
extern vu0_v4 D_L06_001E1680[];

void func_L06_00355610(u8 *a0, u8 *v, s32 a2, s32 a3) {
    vu0_v4 save;
    vu0_v4 d;
    f32 dot;
    f32 t;
    f32 bestYaw;
    s32 bestKey;
    s32 best;
    s32 score;
    s32 base;
    s32 i;
    s32 r;

    if (*(s32 *)(v + 0x270) != 0) {
        func_L01_004450F0(a0, 0x17, -1);
        return;
    }
    bestYaw = 0.0f;
    *(s32 *)(v + 0x4DC) = a2;
    *(s32 *)(v + 0x4E0) = a3;
    best = 0;
    bestKey = 0;
    i = 0;
    while (i < 5) {
        r = func_L06_00354270(v + 0x4D0, v + 0x4F0);
        if (r == 0) {
            func_L01_004450F0(a0, 0x17, -1);
            return;
        }
        if (r < 0) {
            break;
        }
        vec_sub_ab(&d, v + 0x4A0, &D_L06_001E1680[0]);
        func_0038CF68(&d, &d, 1.0f);
        dot = func_0038CE68(&d, &D_L06_001E1680[2]);
        if (dot < 0.0f) {
            dot *= 0.25f;
        } else if (dot < 0.5f) {
            dot = dot * dot;
        } else {
            dot *= 1.5f;
        }
        base = (s32)(dot * 250.0f);
        score = base;
        if (*(s16 *)(v + 0x23C) != 0) {
            t = (func_0038CF38(a0 + 0x10, v + 0x220) - *(f32 *)(v + 0x4C4)) /
                (*(f32 *)(v + 0x4C8) - *(f32 *)(v + 0x4C4));
            if (1.0f < t) {
                t = 1.0f;
            } else if (t < 0.0f) {
                t = 0.0f;
            }
            score = base + (s32)(t * 100.0f);
        }
        if (16.0f < func_0038CF38(a0 + 0x10, v + 0x4A0)) {
            score += 150;
        }
        if (score >= 0x2EF) {
            break;
        }
        if (best < score) {
            best = score;
            save = *(vu0_v4 *)(v + 0x4A0);
            bestYaw = *(f32 *)(v + 0x368);
            bestKey = *(s32 *)(v + 0x364);
        }
        i++;
    }
    if (i == 5) {
        if (best <= 0) {
            func_L01_004450F0(a0, 0x17, -1);
            return;
        }
        *(vu0_v4 *)(v + 0x4A0) = save;
        *(f32 *)(v + 0x368) = bestYaw;
        *(s32 *)(v + 0x364) = bestKey;
    }
    *(s32 *)(v + 0x36C) = 0x17;
    func_L06_0045B1F8(*(void **)(v + 0x358), a0 + 0x10, v + 0x344, v + 0x348);
    func_L06_00353208(func_L06_0045B290(*(void **)(v + 0x358), *(s32 *)(v + 0x344), *(s32 *)(v + 0x364),
                                        *(f32 *)(v + 0x348), *(f32 *)(v + 0x368)),
                      a0, v);
    func_L01_004450F0(a0, 3, -1);
}
/* localdecomp:end func_L06_00355610 */

INCLUDE_ASM("asm/levels", func_L06_003558D0);

INCLUDE_ASM("asm/levels", func_L06_00355C20);

/* localdecomp:start func_L06_00355F90 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_L06_00353160(u8 *, s32);
s32 func_L06_00355F90(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        *(s32 *)(v + 0x350) = 1;
        *(f32 *)(v + 0x354) = func_L06_00353160(v, *(s32 *)(v + 0x344));
        *(f32 *)(v + 0xA4) = 0.15f;
        func_L01_0045BD78(a0, 0.004f, 0.20000002f, 0.010053097f, 0.25132743f);
        func_L06_00351930(a0, v, 6, 0, 10);
    }
    func_L06_00351220(a0, v);
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 6, -1);
        func_L06_00351930(a0, v, 7, 0, 5);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00355F90 */

/* localdecomp:start func_L06_00356088 */
#include "vu0.h"

extern void func_L01_004450F0_00356088(u8 *a0, s32 a1, s32 a2);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern s32 func_L06_00351220_00356088(u8 *, u8 *);
extern s32 func_L01_00476498_00356088(void *, void *, s32 *, f32 *, f32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern s32 func_L06_00352FB0_00356088(u8 *, s32, s32, void *, s32 *);
extern f32 func_L06_0045B290_00356088(void *, s32, s32, f32, f32);
extern f32 func_L01_00448890_00356088(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L02_00431568_00356088(void *, void *, s32, f32, f32, f32, f32);
extern void func_L06_00353210_00356088(u8 *, s32 *, s32);
extern f32 func_0038CE68(void *, void *);

typedef struct {
    s32 k;
    f32 f;
} N_00356088;
typedef struct {
    u8 pad[0x280];
    N_00356088 n[0x18];
    s32 x340;
    s32 key;
    f32 off;
    f32 f;
} V_00356088;

s32 func_L06_00356088(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 tgt;
    vu0_v4 pt;
    s32 key;
    f32 off;
    s32 idx;
    f32 yaw;
    f32 d;
    f32 f;
    f32 step;
    s32 r;
    s32 n;

    func_L06_00351220_00356088(a0, v);
    key = ((V_00356088 *)v)->key;
    off = ((V_00356088 *)v)->off;
    step = 5.0f;
    if (((V_00356088 *)v)->f < 0.0f) step = -5.0f;
    r = func_L01_00476498_00356088(*(void **)(v + 0x358), &pos, &key, &off, step, *(s32 *)(v + 0x340));
    vec_sub_ab(&dir, &pos, a0 + 0x10);
    dir.z = 0.0f;
    func_0038CF68(&dir, &dir, 1.0f);
    yaw = func_0038D160(dir.x, dir.y);
    if (func_L06_00352FB0_00356088(v, 0.0f <= *(f32 *)(v + 0x34C), key, &tgt, &idx)) {
        if (((V_00356088 *)v)->n[idx].f < -2.0f) {
            *(f32 *)(v + 0x34C) = func_L06_0045B290_00356088(*(void **)(v + 0x358), *(s32 *)(v + 0x344), ((V_00356088 *)v)->n[idx].k,
                                  *(f32 *)(v + 0x348), 0.0f);
            if (*(f32 *)(v + 0x34C) < 0.0f) {
                *(f32 *)(v + 0x34C) += ((V_00356088 *)v)->n[idx].f;
            } else {
                *(f32 *)(v + 0x34C) -= ((V_00356088 *)v)->n[idx].f;
            }
            key = *(s32 *)(v + 0x344);
            off = *(f32 *)(v + 0x348);
            func_L01_00476498_00356088(*(void **)(v + 0x358), &pos, &key, &off, *(f32 *)(v + 0x34C), *(s32 *)(v + 0x340));
            *(vu0_v4 *)(v + 0x4A0) = pos;
            func_L01_004450F0_00356088(a0, 9, -1);
            return 2;
        }
        pos = tgt;
        pos.z = func_003C3D30(&tgt, 0, a0, 0.5f);
    } else {
        pos.z += *(f32 *)(v + 0x354);
    }
    func_L01_00448890_00356088(a0 + 0xF8, yaw, v + 0x124, *(f32 *)(v + 0x84), *(f32 *)(v + 0x88), *(f32 *)(v + 0x8C), 0);
    func_L02_00431568_00356088(a0, &pos, 0x515, yaw, -1.0f, -1.0f, -1.0f);
    ((void (*)(void *, void *, s32, f32))func_L06_00353210_00356088)(&pt, *(void **)(v + 0x358), *(s32 *)(v + 0x344),
                                                           *(f32 *)(v + 0x348));
    d = func_0038CE68(a0 + 0x10, &dir) - func_0038CE68(&pt, &dir);
    if (0.0f <= d) {
        f = *(f32 *)(v + 0x34C);
        if (0.0f < f) {
            f = f - d;
            *(f32 *)(v + 0x34C) = f;
            if (f < 0.375f) *(f32 *)(v + 0x34C) = 0.375f;
        } else {
            f = f + d;
            *(f32 *)(v + 0x34C) = f;
            if (-0.375f < f) *(f32 *)(v + 0x34C) = -0.375f;
            d = -d;
        }
        func_L01_00476498_00356088(*(void **)(v + 0x358), &pos, (s32 *)(v + 0x344), (f32 *)(v + 0x348),
                          d, *(s32 *)(v + 0x340));
    }
    if (*(f32 *)(v + 0x13C) < *(f32 *)(v + 0xA4)) {
        if (0.0f < *(f32 *)(v + 0x34C)) {
            if (0.0f < *(f32 *)(v + 0x348)) {
                *(s32 *)(v + 0x344) += 1;
                n = **(s32 **)(v + 0x358) - 1;
                if (n < *(s32 *)(v + 0x344)) *(s32 *)(v + 0x344) = n;
                *(f32 *)(v + 0x348) = 0.0f;
            }
        } else if (0.0f < *(f32 *)(v + 0x348)) {
            *(s32 *)(v + 0x344) -= 1;
            if (*(s32 *)(v + 0x344) < 0) *(s32 *)(v + 0x344) = 0;
            *(f32 *)(v + 0x348) = 0.0f;
        }
        if (r) {
            func_L01_004450F0_00356088(a0, 3, -1);
        } else {
            func_L01_004450F0_00356088(a0, 7, -1);
        }
    return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00356088 */

/* localdecomp:start func_L06_003564A0 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045A9F0(u8 *);
s32 func_L06_003564A0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    if (func_L01_004561B8(a0)) {
        *(s32 *)(v + 0x350) = 0;
        *(f32 *)(v + 0xA4) = 0.5f;
        func_L01_0045BD78(a0, 0.0056000003f, 0.10000001f, 0.010053097f, 0.25132743f);
    }
    if (a0[0x43] == 8 && (a0[0x60] & 2)) {
        func_L01_004450F0(a0, 3, -1);
        func_L06_00351930(a0, v, 2, 0, 10);
        return 1;
    }
    if (*(f32 *)(v + 0x100) < *(f32 *)(a0 + 0x18)) {
        func_L01_0045A9F0(a0);
        return 0;
    }
    if (a0[0x43] != 8) {
        func_L06_00351930(a0, v, 8, 0, 5);
    }
    return 0;
}
/* localdecomp:end func_L06_003564A0 */

/* localdecomp:start func_L06_003565B8 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
s32 func_L06_003565B8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        *(s32 *)(v + 0x384) = 0;
        *(s32 *)(v + 0x350) = 1;
        *(f32 *)(v + 0x354) = 2.0f;
        *(f32 *)(v + 0xA4) = 0.15f;
        func_L01_0045BD78(a0, 0.004f, 0.20000002f, 0.010053097f, 0.25132743f);
        func_L06_00351930(a0, v, 6, 0, 10);
    }
    func_L06_00351220(a0, v);
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 9, -1);
        func_L06_00351930(a0, v, 7, 0, 5);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003565B8 */

INCLUDE_ASM("asm/levels", func_L06_003566B0);
