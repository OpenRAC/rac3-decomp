#include "common.h"

/* NTSC-U counterpart of func_L09_00407D08 (src/levels/shared/L09_00407670.c) */
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

/* localdecomp:start func_L09_00405B60 */
#include "vu0.h"


__asm__(".extern D_L09_001DF904, 16");
extern Row_00407D08 *D_L09_001DF904;

extern Pad_00407D08 D_00143A70[];
extern u8 D_001439F4[];
extern u8 D_L09_001E2C00[];
__asm__(".extern D_L09_001DF7B8, 4");
extern f32 D_L09_001DF7B8;
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_0037E568(s32, s32, s32, f32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);

extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
void func_L09_00405B60(u8 *a0)
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
    cam = D_L09_001DF904[*(s16 *)(a0 + 0x84)].cam;
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
            s32 b = D_001439F4[0];
            f32 sign;
            f32 x;
            f32 t;
            f32 speed;

            m = *(u8 **)(obj + 0x68);
            speed = 0.012f;
            sign = 1.0f;
            if (D_00143A70[b].v != 0) {
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
            func_L01_00445168(&cam->f40[p], &cam->f50[p], t, speed, 0.4f, 0.1f);
            if (*(s32 *)(m + 0x3BC) != 0) {
                f32 a = func_00389380(*(f32 *)(tgt + 0xF8), 1.5707964f);
                off.x = func_00388960(a) * cam->f40[p];
                off.y = func_00388978(a) * cam->f40[p];
                off.z = 0.0f;
            } else {
                *(u128_00407D08 *)&dir = *(u128_00407D08 *)(m + 0x3C0);
                flag = 0;
                func_003886E8(&off, m + 0x2E0, -cam->f40[p]);
            }
        } else if (*(s16 *)(obj + 0xAA) == 0x107C || *(s16 *)(obj + 0xAA) == 0x1A17) {
            o = *(u8 **)(*(u8 **)(obj + 0x68) + 0x6D0);
            if (*(f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(o + 0x100) + 0x68) + 0x720) + 0xC) * 0.0166666675f < *(f32 *)(o + 0x138) &&
                cam->fB0[p] <= *(f32 *)(o + 0x138)) {
                func_003BEBF8(&cam->fA0[p], 97.0f, 0.2908882200717926f);
            } else {
                func_003BEBF8(&cam->fA0[p], D_L09_001DF7B8, 0.0872664675116539f);
            }
            fov = cam->fA0[p];
            cam->fB0[p] = *(f32 *)(o + 0x138);
        }
    } else {
        u8 *e = (u8 *)(*(s32 *)(a0 + 0x94) * 0x460 + (s32)D_L09_001E2C00);
        obj = *(u8 **)(e + 0x240);
    }
    func_0037E568(*(s32 *)(a0 + 0x94), 0, 0, fov * 0.017453292f, 0.005f, 0.2f, 0.0f);
    t40 = *(V_00407D08 *)(obj + 0x10);
    t40.z = cam->fE0[*(s32 *)(a0 + 0x94)];
    pos = t40;
    if (flag != 0) {
        pos.z += *h;
    } else {
        func_003886E8(&t50, &dir, *h);
        vec_add_ab(&pos, &pos, &t50);
    }
    vec_add_ba(&pos, &pos, &off);
    vec_sub_ba(a0, &pos, a0 + 0x30);
    func_00388830(a0, a0, 1.0f);
    func_00388758(a0 + 0x10, a0, &up);
    func_00388830(a0 + 0x10, a0 + 0x10, 1.0f);
    func_00388758(a0 + 0x20, a0 + 0x10, a0);
}
/* localdecomp:end func_L09_00405B60 */
