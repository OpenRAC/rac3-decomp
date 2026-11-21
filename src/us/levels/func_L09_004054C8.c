#include "common.h"

/* NTSC-U counterpart of func_L09_00407670 (src/levels/shared/L09_00407670.c) */
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

/* localdecomp:start func_L09_004054C8 */
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

__asm__(".extern D_L09_001DF904, 16");
extern Row_00407D08 *D_L09_001DF904;
extern u8 D_001A4BE0[];
extern vu0_v4 D_L09_002BBD90[];
extern vu0_v4 D_L09_002BBD80[];
extern u8 D_L09_001E2C00[];
extern u8 D_L09_001E9940[];
__asm__(".extern D_L09_001DF7B8, 4");
extern f32 D_L09_001DF7B8;
/* func_L01_004482A0 is (value, target, rate, gain, damping, cap); this file's later declaration
   has the two pointers first, and retail's argument order needs the real one: an alias */
extern f32 func_L01_00445168_004054C8(f32 *value, f32 target, f32 *rate, f32 gain, f32 damping, f32 cap);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003888F0(void *, void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern u8 *func_0037E0B8(void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003F9498(void *, s32, s32, f32);

void func_L09_004054C8(u8 *obj)
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

    table = (T_00407670 *)D_L09_001DF904[*(s16 *)(obj + 0x84)].cam;
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
            off = D_L09_002BBD90[0];
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
                off = D_L09_002BBD80[*(s16 *)(state + 0x124)];
            }
            if (*(s16 *)(state + 0x128) != 0) {
                angleGoal = 15.0f;
                offsetGoal = 1.5f;
            }
            bias = 0.0f;
            func_L01_00445168_004054C8(&table->f60[idx], angleGoal, &table->f70[idx], 0.0014544411f, 0.019392548f, bias);
            func_L01_00445168_004054C8(&table->f80[idx], offsetGoal, &table->f90[idx], 0.0035f, 0.1f, bias);
            extra = table->f80[idx];
            angle = table->f60[idx] * 0.017453292f;
            table->i100[idx]++;
            if (*(u8 *)(data + 0x713) == 0 &&
                *(f32 *)(*(u8 **)(data + 0x720) + 0xC) * 0.016666668f < *(f32 *)(state + 0x138) &&
                table->i100[idx] < 50) {
                if (*(s16 *)(state + 0x128) != 0) {
                    table->fC0[idx] = -1.25f;
                } else {
                    table->fC0[idx] = -0.5f;
                }
            } else {
                table->fC0[idx] = -1.5f;
            }
            if (table->fA0[idx] == D_L09_001DF7B8) {
                table->i100[idx] = 0;
            }
            bias = table->fC0[idx];
        }
    } else {
        u8 *e = (u8 *)(*(s32 *)(obj + 0x94) * 0x460 + (s32)D_L09_001E2C00);

        target = *(u8 **)(e + 0x240);
    }
    pos = *(vu0_v4 *)(target + 0x10);
    if (special) {
        func_L01_00445168_004054C8(&table->fE0[*(s32 *)(obj + 0x94)], pos.z, &table->fF0[*(s32 *)(obj + 0x94)], 0.11111111f, 0.041666668f, 0.0f);
        pos.z = table->fE0[*(s32 *)(obj + 0x94)];
    } else {
        table->fE0[*(s32 *)(obj + 0x94)] = pos.z;
    }
    off.x += extra + bias;
    m = *(u8 **)(obj + 0x70);
    v = m + 0x70;
    old = *(vu0_v4 *)(obj + 0x30);
    if (angle != 0.0f) {
        f32 sn = func_00388978(angle);
        f32 cs = func_00388960(angle);
        tmp = off;
        off.x = cs * tmp.x - sn * tmp.z;
        off.y = tmp.y;
        off.z = sn * tmp.x + cs * tmp.z;
    }
    func_003886E8(&mat[0], target + 0xC0, -1.0f);
    mat[3] = pos;
    mat[2] = dir;
    func_00388758(&mat[1], &mat[0], &dir);
    func_00388830(&mat[1], &mat[1], 1.0f);
    func_00388758(&mat[0], &mat[2], &mat[1]);
    func_003888F0(&tmp, &off, mat);
    vec_sub_ab(&d, &tmp, &pos);
    func_003886C0(v, v, &d, 0.045f);
    dir = *(vu0_v4 *)(m + 0x70);
    vec_add_ab(obj + 0x30, &pos, &dir);
    qzero(&eye);
    r = func_0037E0B8(target);
    if (r != 0) {
        func_003886E8(&eye, target + 0xE0, *(f32 *)(r + 0x10));
    }
    vec_add_ab(&eye, &eye, &pos);
    hit = 0;
    if (func_003CE740(&eye, obj + 0x30, 4, target, 0)) {
        g = D_L09_001E9940;
        if (*(u8 **)(g + 0x18) == 0 || *(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1AD6) {
            vec_sub_ba(&tmp, &eye, g + 0x20);
            func_00388830(&dir, &tmp, 0.02f);
            hit = 1;
            vec_add_ab(obj + 0x30, g + 0x20, &dir);
        }
    }
    if (!hit && func_003CE740(&old, obj + 0x30, 4, 0, 0)) {
        g = D_L09_001E9940;
        if (*(u8 **)(g + 0x18) == 0 || *(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1AD6) {
            vec_sub_ba(&tmp, &old, g + 0x20);
            func_00388830(&dir, &tmp, 0.02f);
            vec_add_ab(obj + 0x30, g + 0x20, &dir);
        }
    }
    if (func_L01_003F9498(obj + 0x30, 4, 0, 0.25f)) {
        u8 *g2 = D_L09_001E9940;

        if (*(u8 **)(g2 + 0x18) == 0) {
            *(vu0_v4 *)(obj + 0x30) = *(vu0_v4 *)(g2 + 0x30);
        }
        if (*(u8 **)(g2 + 0x18) != 0 && *(s16 *)(*(u8 **)(g2 + 0x18) + 0xAA) == 0x1AD6) {
            vu0_v4 push;

            func_00388830(&push, g2 + 0x40, 1.0f);
            func_003886E8(&push, &push, 0.25f);
            vec_add_ab(obj + 0x30, obj + 0x30, &push);
        }
    }
    {
        u8 *h = D_001A4BE0;
        u8 *moby = *(u8 **)(h + 0xBF8);

        *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L09_004054C8 */
