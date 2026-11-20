#include "common.h"

/* localdecomp:start func_L39_0056A7B8 */
#include "vu0.h"

typedef int q128_0056A7B8 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x50]; u8 *p50; u8 pad54[0x460 - 0x54]; } Entry_0056A7B8;

typedef struct {
    u8 pad0[0x70];
    u8 *follow;
    u8 pad74[0x94 - 0x74];
    s32 player;
} Cam_0056A7B8;

extern Entry_0056A7B8 D_L39_0024DE80[];
extern s32 D_L39_0024B858[2] __attribute__((section(".sdata")));
extern vu0_v4 D_L39_0025F760;

extern void func_L01_003E4028(u8 *, q128_0056A7B8 *);
extern void func_L39_00569868(Cam_0056A7B8 *);
extern void func_L39_00569EB0(Cam_0056A7B8 *, vu0_v4 *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_L39_00578EA0(f32 *, f32, f32, f32, f32, f32);
extern s32 func_L01_0040E020(void *);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_L01_003E5700(u8 *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CEA8(void *);
extern void func_L01_003E8C28(s32, f32, f32);

void func_L39_0056A7B8(Cam_0056A7B8 *cam) {
    vu0_v4 dir;
    vu0_v4 pos[2];      /* func_L01_003E4028 fills pos[0]; retail keeps the 16 bytes of pos[1] (sp+0x20) unused */
    vu0_v4 old;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 off;
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 hit;
    vu0_v4 d;
    vu0_v4 mid;
    u8 *entry;
    u8 *follow;
    u8 *springs;
    u8 *target;
    u8 *vel;
    u8 *look;
    u8 *hero;
    u8 *body;
    u8 *p;
    f32 zero;
    f32 radius;
    f32 height;
    f32 len;

    entry = (u8 *)&D_L39_0024DE80[cam->player];
    follow = cam->follow;
    zero = 0.0f;
    springs = follow + 0x180;
    target = follow + 0xC0;
    vel = follow + 0x70;
    look = follow + 0x60;
    body = entry + 0x60;
    hero = entry + 0x150;

    func_L01_003E4028((u8 *)cam, (q128_0056A7B8 *)pos);
    func_L39_00569868(cam);
    func_L39_00569EB0(cam, &dir);
    *(q128_0056A7B8 *)(vel) = *(q128_0056A7B8 *)&dir;
    *(q128_0056A7B8 *)&old = *(q128_0056A7B8 *)look;
    {
        f32 t = func_0038CE68(entry + 0x90, target);
        func_0038CE20(&a, entry + 0x90, t);
    }
    vec_sub_ba(&b, target, &a);
    *(f32 *)(look + 0x110) = func_0038CF00(&a, vel);
    a.x = func_L39_00578EA0((f32 *)(follow + 0x100), a.x, *(f32 *)(look + 0x10), *(f32 *)(look + 0x104), *(f32 *)(look + 0x108), zero);
    a.y = func_L39_00578EA0((f32 *)(follow + 0x104), a.y, *(f32 *)(look + 0x14), *(f32 *)(look + 0x104), *(f32 *)(look + 0x108), zero);
    a.z = func_L39_00578EA0((f32 *)(follow + 0x108), a.z, *(f32 *)(look + 0x18), *(f32 *)(look + 0x104), *(f32 *)(look + 0x108), zero);
    b.x = func_L39_00578EA0((f32 *)(follow + 0xF0), b.x, *(f32 *)(look + 0x0), *(f32 *)(look + 0xFC), *(f32 *)(look + 0x100), zero);
    b.y = func_L39_00578EA0((f32 *)(follow + 0xF4), b.y, *(f32 *)(look + 0x4), *(f32 *)(look + 0xFC), *(f32 *)(look + 0x100), zero);
    b.z = func_L39_00578EA0((f32 *)(follow + 0xF8), b.z, *(f32 *)(look + 0x8), *(f32 *)(look + 0xFC), *(f32 *)(look + 0x100), zero);
    vec_add_ba(look, look, vel);
    vec_add_ab(target, &b, &a);
    func_0038CE20(&off, entry + 0x80, *(f32 *)(look + 0xD0));
    if (look[0xF9] != 0) {
        look[0xF8]++;
        if (*(s16 *)(look + 0x10C) < look[0xF8]) {
            look[0xF8] = *(s16 *)(look + 0x10C);
        }
        func_0038CDF8((f32 *)&from, (f32 *)look, (f32 *)target, (f32)look[0xF8] / (f32)*(s16 *)(look + 0x10C));
        vec_add_ab(follow + 0xA0, &off, &from);
    } else {
        func_L01_0040E020(follow + 0x158);
        func_0038CDF8((f32 *)&from, (f32 *)look, (f32 *)target, (f32)look[0xF8] / (f32)*(s16 *)(look + 0x10C));
        vec_add_ab(follow + 0xA0, &off, &from);
    }
    func_L01_003E5700((u8 *)cam, (s32)&off);
    if (hero[0x12C] != 0 && hero[0x133] != 0) {
        func_0038CE20(&off, body + 0x20, 2.0f);
    } else if (*(s32 *)(hero + 0x104) == 0x11) {
        qzero(&off);
    } else {
        func_0038CE20(&off, body + 0x20, 0.5f);
    }
    p = body + 0x20;
    vec_add_ba(&from, pos, &off);
    func_0038CE20(&off, p, *(f32 *)(springs + 0x30));
    vec_add_ba(look + 0x50, &off, look);
    {
        Entry_0056A7B8 *e = &D_L39_0024DE80[cam->player];
        u8 *m = *(u8 **)(e->p50 + 0x70);
        radius = *(f32 *)(m + 0x254) * *(f32 *)(m + 0x24C) * (*(f32 *)(m + 0x250) - 1.0f) + 0.35f;
    }
    func_0038CE20(&to, p, 20.0f);
    vec_add_ab(&to, &from, &to);
    if (func_003D3CB0(&from, &to, D_L39_0024B858[cam->player], *(void **)(hero + 0xF0), 0) != 0) {
        hit = D_L39_0025F760;
    } else {
        hit = to;
    }
    func_0038CE20(&to, p, 20.0f);
    vec_sub_ab(&to, &from, &to);
    if (func_003D3CB0(&from, &to, D_L39_0024B858[cam->player], *(void **)(hero + 0xF0), 0) != 0) {
        to = D_L39_0025F760;
    }
    vec_sub_ab(&d, &to, &hit);
    if (func_0038CEA8(&d) < radius + radius) {
        vec_add_ba(&mid, &hit, &to);
        func_0038CE20(&mid, &mid, 0.5f);
        *(vu0_v4 *)(look + 0x50) = mid;
        vec_sub_ba(&d, &mid, look);
        func_L01_003E8C28(cam->player, func_0038CE68(&d, p), 0.006f);
    } else {
        vec_sub_ab(&d, &hit, look);
        len = func_0038CEA8(&d);
        height = *(f32 *)(springs + 0x30);
        if (len <= height + radius) {
            func_0038CE20(&mid, p, radius);
            vec_sub_ba(&mid, &hit, &mid);
            *(vu0_v4 *)(look + 0x50) = mid;
            vec_sub_ba(&d, &mid, look);
            func_L01_003E8C28(cam->player, func_0038CE68(&d, p), 0.006f);
        } else {
            f32 dl = func_0038CE68(look, body + 0x30);
            if (func_0038CE68(&to, body + 0x30) < dl) {
                to = *(vu0_v4 *)look;
            }
            func_0038CE20(&off, p, height);
            vec_add_ab(look + 0x50, &off, &to);
        }
    }
}
/* localdecomp:end func_L39_0056A7B8 */
