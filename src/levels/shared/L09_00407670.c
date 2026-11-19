#include "common.h"

typedef int u128_00407D08 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00407D08;
typedef struct {
    u8 pad0[0x20];
    u8 *target[4];
    u8 pad30[0x10];
    f32 f40[4];
    f32 f50[4];
    u8 pad60[0x40];
    f32 fA0[4];
    f32 fB0[4];
    u8 padC0[0x20];
    f32 fE0[4];
} Cam_00407D08;
typedef struct {
    u8 pad0[0x1C];
    Cam_00407D08 *cam;
} Row_00407D08;
typedef struct {
    s32 v;
    u8 pad[0x1C];
} Pad_00407D08;

/* localdecomp:start func_L09_00407670 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x20];
    u8 *target[4];
    u8 pad30[0x30];
    f32 f60[4];
    f32 f70[4];
    f32 f80[4];
    f32 f90[4];
    f32 fA0[4];
    f32 fB0[4];
    f32 fC0[4];
    f32 fD0[4];
    f32 fE0[4];
    f32 fF0[4];
    s32 i100[4];
} T_00407670;

__asm__(".extern D_L09_001DF884, 16");
extern Row_00407D08 *D_L09_001DF884;
extern u8 D_001A4BE0[];
extern vu0_v4 D_L09_002BBD10[];
extern vu0_v4 D_L09_002BBD00[];
extern u8 D_L09_001E2B80[];
extern u8 D_L09_001E98C0[];
__asm__(".extern D_L09_001DF778, 4");
extern f32 D_L09_001DF778;
/* func_L01_004482A0 is (value, target, rate, gain, damping, cap); this file's later declaration
   has the two pointers first, and retail's argument order needs the real one: an alias */
extern f32 func_L01_004482A0_00407670(f32 *value, f32 target, f32 *rate, f32 gain, f32 damping, f32 cap);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern u8 *func_00382348(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, s32, f32);

void func_L09_00407670(u8 *obj)
{
    vu0_v4 off;
    vu0_v4 eye;
    vu0_v4 dir;
    vu0_v4 pos;
    vu0_v4 old;
    vu0_v4 tmp;
    vu0_v4 mat[4];
    vu0_v4 d;
    T_00407670 *table;
    s32 idx;
    s32 special;
    s32 hit;
    u8 *target;
    u8 *data;
    u8 *state;
    u8 *ctx;
    u8 *x;
    u8 *m;
    u8 *v;
    u8 *hero;
    u8 *r;
    u8 *g;
    f32 angle;
    f32 extra;
    f32 bias;

    table = (T_00407670 *)D_L09_001DF884[*(s16 *)(obj + 0x84)].cam;
    idx = *(s32 *)(obj + 0x94);
    hero = D_001A4BE0;
    special = 0;
    angle = 0.0f;
    extra = 0.0f;
    bias = 0.0f;
    *(vu0_q *)&dir = 0;
    dir.z = 1.0f;
    dir.w = 1.0f;
    ctx = *(u8 **)(hero + 0xBF8);
    *(s32 *)(ctx + 0x98) = 0;
    qzero(&off);
    x = table->target[idx];
    if (x != 0) {
        target = x;
        if (*(s16 *)(target + 0xAA) == 0x107E) {
            u8 *w = *(u8 **)(target + 0x68);

            angle = *(f32 *)(w + 0x350);
            dir = *(vu0_v4 *)(w + 0x3C0);
            off = D_L09_002BBD10[0];
        } else if (*(s16 *)(target + 0xAA) == 0x107C || *(s16 *)(target + 0xAA) == 0x1A17) {
            f32 angleGoal = 0.0f;
            f32 offsetGoal = 0.0f;

            data = *(u8 **)(target + 0x68);
            special = 1;
            state = *(u8 **)(data + 0x6D0);
            if (*(s16 *)(target + 0xAA) == 0x1A17) {
                off.x = 7.0f;
                off.y = 0.0f;
                off.z = 2.5f;
                off.w = 1.0f;
            } else {
                off = D_L09_002BBD00[*(s16 *)(state + 0x124)];
            }
            if (*(s16 *)(state + 0x128) != 0) {
                angleGoal = 15.0f;
                offsetGoal = 1.5f;
            }
            bias = 0.0f;
            func_L01_004482A0_00407670(&table->f60[idx], angleGoal, &table->f70[idx], 0.0020943952f, 0.02792527f, bias);
            func_L01_004482A0_00407670(&table->f80[idx], offsetGoal, &table->f90[idx], 0.00504f, 0.14400001f, bias);
            extra = table->f80[idx];
            angle = table->f60[idx] * 0.017453292f;
            table->i100[idx]++;
            if (*(u8 *)(data + 0x713) == 0 &&
                *(f32 *)(*(u8 **)(data + 0x720) + 0xC) * 0.020000001f < *(f32 *)(state + 0x138) &&
                table->i100[idx] < 42) {
                if (*(s16 *)(state + 0x128) != 0) {
                    table->fC0[idx] = -1.25f;
                } else {
                    table->fC0[idx] = -0.5f;
                }
            } else {
                table->fC0[idx] = -1.5f;
            }
            if (table->fA0[idx] == D_L09_001DF778) {
                table->i100[idx] = 0;
            }
            bias = table->fC0[idx];
        }
    } else {
        u8 *e = (u8 *)(*(s32 *)(obj + 0x94) * 0x460 + (s32)D_L09_001E2B80);

        target = *(u8 **)(e + 0x240);
    }
    pos = *(vu0_v4 *)(target + 0x10);
    if (special) {
        func_L01_004482A0_00407670(&table->fE0[*(s32 *)(obj + 0x94)], pos.z, &table->fF0[*(s32 *)(obj + 0x94)], 0.16000001f, 0.060000002f, 0.0f);
        pos.z = table->fE0[*(s32 *)(obj + 0x94)];
    } else {
        table->fE0[*(s32 *)(obj + 0x94)] = pos.z;
    }
    off.x += extra + bias;
    m = *(u8 **)(obj + 0x70);
    v = m + 0x70;
    old = *(vu0_v4 *)(obj + 0x30);
    if (angle != 0.0f) {
        f32 sn = func_0038D0B0(angle);
        f32 cs = func_0038D098(angle);
        tmp = off;
        off.x = cs * tmp.x - sn * tmp.z;
        off.y = tmp.y;
        off.z = sn * tmp.x + cs * tmp.z;
    }
    func_0038CE20(&mat[0], target + 0xC0, -1.0f);
    mat[3] = pos;
    mat[2] = dir;
    func_0038CE90(&mat[1], &mat[0], &dir);
    func_0038CF68(&mat[1], &mat[1], 1.0f);
    func_0038CE90(&mat[0], &mat[2], &mat[1]);
    func_0038D028(&tmp, &off, mat);
    vec_sub_ab(&d, &tmp, &pos);
    func_0038CDF8(v, v, &d, 0.045f);
    dir = *(vu0_v4 *)(m + 0x70);
    vec_add_ab(obj + 0x30, &pos, &dir);
    qzero(&eye);
    r = func_00382348(target);
    if (r != 0) {
        func_0038CE20(&eye, target + 0xE0, *(f32 *)(r + 0x10));
    }
    vec_add_ab(&eye, &eye, &pos);
    hit = 0;
    if (func_003D3CB0(&eye, obj + 0x30, 4, target, 0)) {
        g = D_L09_001E98C0;
        if (*(u8 **)(g + 0x18) == 0 || *(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1AD6) {
            vec_sub_ba(&tmp, &eye, g + 0x20);
            func_0038CF68(&dir, &tmp, 0.02f);
            hit = 1;
            vec_add_ab(obj + 0x30, g + 0x20, &dir);
        }
    }
    if (!hit && func_003D3CB0(&old, obj + 0x30, 4, 0, 0)) {
        g = D_L09_001E98C0;
        if (*(u8 **)(g + 0x18) == 0 || *(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1AD6) {
            vec_sub_ba(&tmp, &old, g + 0x20);
            func_0038CF68(&dir, &tmp, 0.02f);
            vec_add_ab(obj + 0x30, g + 0x20, &dir);
        }
    }
    if (func_L01_003FB640(obj + 0x30, 4, 0, 0.25f)) {
        u8 *g2 = D_L09_001E98C0;

        if (*(u8 **)(g2 + 0x18) == 0) {
            *(vu0_v4 *)(obj + 0x30) = *(vu0_v4 *)(g2 + 0x30);
        }
        if (*(u8 **)(g2 + 0x18) != 0 && *(s16 *)(*(u8 **)(g2 + 0x18) + 0xAA) == 0x1AD6) {
            vu0_v4 push;

            func_0038CF68(&push, g2 + 0x40, 1.0f);
            func_0038CE20(&push, &push, 0.25f);
            vec_add_ab(obj + 0x30, obj + 0x30, &push);
        }
    }
    {
        u8 *h = D_001A4BE0;
        u8 *moby = *(u8 **)(h + 0xBF8);

        *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L09_00407670 */

/* localdecomp:start func_L09_00407D08 */
#include "vu0.h"


__asm__(".extern D_L09_001DF884, 16");
extern Row_00407D08 *D_L09_001DF884;

extern Pad_00407D08 D_143A70[];
extern u8 D_1439F4[];
extern u8 D_L09_001E2B80[];
__asm__(".extern D_L09_001DF778, 4");
extern f32 D_L09_001DF778;
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
void func_L09_00407D08(u8 *a0)
{
    V_00407D08 off;
    V_00407D08 pos;
    V_00407D08 up;
    V_00407D08 dir;
    V_00407D08 t40;
    V_00407D08 t50;
    s32 flag;
    s32 p;
    Cam_00407D08 *cam;
    u8 *tgt;
    u8 *obj;
    u8 *o;
    u8 *m;
    f32 *h;
    f32 fov;

    p = *(s32 *)(a0 + 0x94);
    flag = 1;
    cam = D_L09_001DF884[*(s16 *)(a0 + 0x84)].cam;
    fov = 80.0f;
    qzero(&off);
    *(u128_00407D08 *)&up = 0;
    *(u128_00407D08 *)&dir = 0;
    up.z = 1.0f;
    up.w = 1.0f;
    dir.z = 1.0f;
    dir.w = 1.0f;
    h = (f32 *)(*(u8 **)(a0 + 0x70) + 0x90);
    tgt = cam->target[p];
    if (tgt != 0) {
        obj = tgt;
        if (*(s16 *)(obj + 0xAA) == 0x107E) {
            s32 b = D_1439F4[0];
            f32 sign;
            f32 x;
            f32 t;
            f32 speed;

            m = *(u8 **)(obj + 0x68);
            speed = 0.012f;
            sign = 1.0f;
            if (D_143A70[b].v != 0) {
                sign = -1.0f;
            }
            if (b == 0) {
                sign = 1.0f;
            }
            x = *(f32 *)(D_001D52FC + 0x100) * sign;
            *(u128_00407D08 *)&up = *(u128_00407D08 *)(m + 0x3C0);
            if (x > 0.01f) {
                t = -1.4f;
            } else if (x < -0.01f) {
                t = 1.4f;
            } else {
                t = 0.0f;
                speed = 0.009f;
            }
            func_L01_004482A0(&cam->f40[p], &cam->f50[p], t, speed * 1.44f, 0.57600003f, 0.120000005f);
            if (*(s32 *)(m + 0x3BC) != 0) {
                f32 a = func_0038DAB8(*(f32 *)(tgt + 0xF8), 1.5707964f);
                off.x = func_0038D098(a) * cam->f40[p];
                off.y = func_0038D0B0(a) * cam->f40[p];
                off.z = 0.0f;
            } else {
                *(u128_00407D08 *)&dir = *(u128_00407D08 *)(m + 0x3C0);
                flag = 0;
                func_0038CE20(&off, m + 0x2E0, -cam->f40[p]);
            }
        } else if (*(s16 *)(obj + 0xAA) == 0x107C || *(s16 *)(obj + 0xAA) == 0x1A17) {
            o = *(u8 **)(*(u8 **)(obj + 0x68) + 0x6D0);
            if (*(f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(o + 0x100) + 0x68) + 0x720) + 0xC) * 0.020000001f < *(f32 *)(o + 0x138) &&
                cam->fB0[p] <= *(f32 *)(o + 0x138)) {
                func_003C4138(&cam->fA0[p], 97.0f, 0.34906587f);
            } else {
                func_003C4138(&cam->fA0[p], D_L09_001DF778, 0.10471976f);
            }
            fov = cam->fA0[p];
            cam->fB0[p] = *(f32 *)(o + 0x138);
        }
    } else {
        u8 *e = (u8 *)(*(s32 *)(a0 + 0x94) * 0x460 + (s32)D_L09_001E2B80);
        obj = *(u8 **)(e + 0x240);
    }
    func_00382810(*(s32 *)(a0 + 0x94), 0, 0, fov * 0.017453292f, 0.005f, 0.2f, 0.0f);
    t40 = *(V_00407D08 *)(obj + 0x10);
    t40.z = cam->fE0[*(s32 *)(a0 + 0x94)];
    pos = t40;
    if (flag != 0) {
        pos.z += *h;
    } else {
        func_0038CE20(&t50, &dir, *h);
        vec_add_ab(&pos, &pos, &t50);
    }
    vec_add_ba(&pos, &pos, &off);
    vec_sub_ba(a0, &pos, a0 + 0x30);
    func_0038CF68(a0, a0, 1.0f);
    func_0038CE90(a0 + 0x10, a0, &up);
    func_0038CF68(a0 + 0x10, a0 + 0x10, 1.0f);
    func_0038CE90(a0 + 0x20, a0 + 0x10, a0);
}
/* localdecomp:end func_L09_00407D08 */

/* localdecomp:start func_L09_00408150 */
extern u8 D_L09_001E2B80[];

s32 func_L09_00408150(u8 *obj) {
    u8 *e = (u8 *)(*(s32 *)(obj + 148) * 1120 + (s32)D_L09_001E2B80);
    return *(s32 *)(e + 588) == 0x1D;
}
/* localdecomp:end func_L09_00408150 */

/* localdecomp:start func_L09_00408178 */
typedef struct {
    u8 pad0[0x20];
    u8 *a20[4];
} I_00408178;

extern u8 *D_L09_001DF884_00408178;
extern u8 D_L09_001E2B80[];
extern s32 D_001A73EC[];
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);

void func_L09_00408178(u8 *a0) {
    s32 idx = *(s32 *)(a0 + 0x94);
    I_00408178 *info = *(I_00408178 **)(D_L09_001DF884_00408178 + *(s16 *)(a0 + 0x84) * 0x20 + 0x1C);
    u8 *e = D_L09_001E2B80 + idx * 0x460;

    if (*(s32 *)(e + 0x250) != 0x31) {
        e[0x2A3] = 0;
        *(s16 *)(a0 + 0x7E) = 2;
        *(f32 *)(e + 0x2C8) = 0.018f;
        *(f32 *)(e + 0x2B8) = 0.018f;
        *(s32 *)(e + 0x24C) = 0;
        D_001A73EC[0] = 0;
        info->a20[idx] = 0;
        func_00382810(idx, 0x1E, 3, 63.6f * 0.017453292f, 0.005f, 0.2f, 0.0f);
    }
}
/* localdecomp:end func_L09_00408178 */
