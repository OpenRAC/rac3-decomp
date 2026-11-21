#include "common.h"

/* NTSC-U counterpart of func_L16_003E8690 (src/levels/16_kerwan/L16_003E8690.c) */
extern float func_0037E2A8(void);

/* localdecomp:start func_L16_003E6748 */
#include "vu0.h"

typedef struct {
    vu0_v4 x0;
    vu0_v4 x10;
    s32 x20;
    s32 x24;
    f32 x28;
    f32 x2C;
    f32 x30;
} D_003E8690;

typedef struct {
    u8 pad0[0x18];
    u8 *x18;
    u8 pad1C[4];
    vu0_v4 x20;
} G_003E8690;

extern s32 D_L16_001DF65C_003E6748;
extern f32 D_L16_001DF660_003E6748;
extern s32 D_L16_001DF664;
extern f32 D_L16_001DF668;
extern f32 D_L16_001DF66C;
extern f32 D_L16_001DF670;
extern f32 D_L16_001DF674;
__asm__(".extern D_L16_001DF65C_003E6748, 4");
__asm__(".extern D_L16_001DF660_003E6748, 4");
__asm__(".extern D_L16_001DF664, 4");
__asm__(".extern D_L16_001DF668, 4");
__asm__(".extern D_L16_001DF66C, 4");
__asm__(".extern D_L16_001DF670, 4");
__asm__(".extern D_L16_001DF674, 4");
extern u8 *D_L16_001E98D8_003E6748[];
extern G_003E8690 D_L16_001E98C0_003E6748;
extern u8 *D_L16_001ED940_003E6748[];
extern u8 *D_L16_00220734_003E6748[];
typedef struct {
    u8 pad0[0x35C];
    s32 x35C;
    u8 pad360[0x25C0 - 0x360];
    u8 *x25C0;
} H_003E8690;
extern H_003E8690 D_001A4BE0;
extern u8 *D_001A71A0[];

extern f32 func_00389380(f32, f32);
extern f32 func_00388770(void *);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern f32 func_0037E2A8(void);
extern void func_L01_00462FD0(void *, void *, s32, s32, s32, s32, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern s32 func_003BF7E8(u8 *);
extern s32 func_L01_0032FE90_003E6748(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern void func_L01_003C2140(u8 *);
extern void func_003BD360(void *);

void func_L16_003E6748(u8 *self) {
    D_003E8690 *d;
    vu0_v4 v90;
    vu0_v4 dir;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 rot;
    f32 half;
    f32 lim;
    f32 rad;
    s32 done;
    s32 target;
    s32 hit;
    u8 *o;
    u8 *part;
    u8 *cls;
    u8 **pp;
    vu0_q qpos, qvel;

    d = *(D_003E8690 **)(self + 0x68);
    done = 0;
    target = 0;
    __asm__("lqc2 %0, %1" : "=j"(qpos) : "m"(*(vu0_v4 *)(self + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qvel) : "m"(d->x10));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qpos) : "j"(qpos), "j"(qvel));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(self + 0x10)) : "j"(qpos));
    vec_add_ba(&d->x0, &d->x0, &d->x10);
    d->x2C = func_00389380(d->x2C, 0.20943953f);
    {
        vu0_q qd;
        __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(d->x0));
        __asm__("lqc2 %0, %1" : "=j"(qpos) : "m"(*(vu0_v4 *)(self + 0x10)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qd) : "j"(qd), "j"(qpos));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(qd));
    }
    half = func_00388770(&dir) * 0.5f;
    if (half < 0.2f) {
        done = 1;
    }
    lim = (f32)d->x24 / 10.0f;
    /* MIN(D_L16_001DF66C, MIN(half, lim)), a min macro expanded: retail evaluates the inner one twice */
    lim = D_L16_001DF66C < (half < lim ? half : lim) ? D_L16_001DF66C : (half < lim ? half : lim);
    lim = lim * d->x28;
    qzero(&v90);
    v90.z = lim;
    func_00389158(&v90, &v90, &dir, d->x2C);
    vec_add_ab(&v90, &v90, &d->x0);
    vec_sub_ba(&dir, &v90, self + 0x10);
    func_00388830(&dir, &dir, D_L16_001DF660_003E6748);
    *(f32 *)(self + 0xF8) = func_00388A28(dir.x, dir.y);
    *(f32 *)(self + 0xF4) = -func_00388A28(func_003887A0(&dir), dir.z);
    vec_add_ba(self + 0x10, self + 0x10, &dir);
    *(vu0_q *)&pos = 0;
    pos.x = func_0037E250(-1.0f, 1.0f);
    pos.y = func_0037E250(-1.0f, 1.0f);
    pos.z = func_0037E250(-1.0f, 1.0f);
    vel = pos;
    func_00388830(&vel, &vel, func_0037E250(0.1f, 0.2f) * 0.016666668f);
    func_00388830(&pos, &dir, -func_0037E250(0.0016666668f, 0.016666668f));
    vec_add_ba(&vel, &vel, &pos);
    vec_add_ab(&vel, &vel, &d->x10);
    func_00388830(&pos, &dir, func_0037E250(0.0f, D_L16_001DF660_003E6748));
    vec_add_ab(&pos, &pos, self + 0x10);
    part = func_L01_00466F98(&pos, &vel, 0x3C, 0x7F, 0x606060, 3, 40000.0f, 1000.0f, 1.0f, -0.0002f, 0.0f);
    if (part != 0) {
        u8 c = D_L16_00220734_003E6748[0][0];
        part[3] = 0x44;
        part[2] = c;
    }
    func_L01_00466F98(self + 0x10, &vel, 6, 0x7F, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.0004f, 0.0f);
    *(vu0_q *)&rot = 0;
    rot.z = 0.02f;
    func_003888C8(&rot, &rot, self + 0xC0);
    func_00389158(&rot, &rot, self + 0xC0, func_0037E2A8());
    func_L01_00462FD0(&pos, &rot, 0x4F007FFF, 0x1FFFFFFF, 5, 1, 20000.0f);
    rad = D_L16_001DF670;
    func_L01_004C76B8();
    hit = func_L01_003F9498(self + 0x10, 0, self, rad);
    if (hit != 0) {
        o = D_L16_001E98D8_003E6748[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004C76F0();
    if (hit != 0) {
        u8 *q = D_L16_001E98C0_003E6748.x18;
        if (q == 0 || q != *(u8 **)(self + 0xB8)) {
            *(vu0_q *)(self + 0x10) = *(vu0_q *)&D_L16_001E98C0_003E6748.x20;
            done = 1;
            if (D_L16_001E98C0_003E6748.x18 == D_001A4BE0.x25C0) {
                target = D_001A4BE0.x35C;
            } else if (func_003BF7E8(D_L16_001E98C0_003E6748.x18) != 0) {
                target = (s32)D_L16_001E98C0_003E6748.x18;
            }
        }
    }
    if (++d->x24 >= D_L16_001DF65C_003E6748) {
        done = 1;
    }
    if (done) {
        func_L01_0032FE90_003E6748(self + 0x10, 0, 6, 6, 6, 10, 5, 0, D_L16_001DF674, 0.0f, d->x30, D_L16_001DF668,
                          0, 1, 0, 0, 0, 0, D_L16_001DF664, target, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                          0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        cls = D_001A71A0[0];
        func_L01_004C76B8();
        hit = func_003CF790(self + 0x10, 1, cls, 0, 2.0f);
        if (hit != 0) {
            o = D_L16_001E98D8_003E6748[0];
            if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
                o[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit > 0) {
            pp = D_L16_001ED940_003E6748;
            do {
                o = *pp;
                hit--;
                if (o != 0 && *(s16 *)(o + 0xAA) == 0x1ADA) {
                    func_L01_003C2140(o);
                }
                pp++;
            } while (hit != 0);
        }
        func_003BD360(self);
    }
}
/* localdecomp:end func_L16_003E6748 */
