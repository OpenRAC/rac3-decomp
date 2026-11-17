#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;

typedef struct { u8 pad0[0xFB0]; f32 f0FB0; u8 pad1[0x2468 - 0xFB4]; f32 f2468; } S_00633160;

typedef struct {
    u8 pad0[0x474];
    s32 mode;
    s32 kind;
    u8 pad1[0x142F - 0x47C];
    u8 alternate;
    u8 pad2[0x1A07 - 0x1430];
    u8 special;
    u8 pad3[0x2468 - 0x1A08];
    f32 speed;
} View_00633428;

/* declared by functions of L39_00632888.c, which this file was cut from */
extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D160(f32 x, f32 y);

/* localdecomp:start func_L39_00633980 */
#include "vu0.h"

extern void func_L39_00633888(void *, Vec4 *);

void func_L39_00633980(void *a) {
    Vec4 v;

    qzero(&v);
    v.f[2] = 0.6f;
    func_L39_00633888(a, &v);
}
/* localdecomp:end func_L39_00633980 */

/* localdecomp:start func_L39_006339B0 */
#include "vu0.h"

extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D348(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern f32 func_L01_00448728(f32 *, void *, s32, f32, f32, f32, f32);

void func_L39_006339B0(void *self_, Vec4 *a1, f32 *dst_, s32 a3, f32 fx, f32 fy, f32 fz) {
    u8 *self = self_;
    u8 *dst = (u8 *)dst_;
    Vec4 m0[4];
    Vec4 m1[4];
    Vec4 e;
    Vec4 v;
    f32 out = 0.0f;
    f32 d;
    f32 ang;
    f32 yaw;
    f32 pitch;

    *(u128_t *)(dst + 0x00) = *(u128_t *)(self + 0x20);
    *(u128_t *)(dst + 0x10) = *(u128_t *)(self + 0x30);
    *(u128_t *)(dst + 0x20) = *(u128_t *)(self + 0x40);
    *(u128_t *)(dst + 0x30) = *(u128_t *)(self + 0x50);
    d = func_0038CE68(a1, dst + 0x20);
    ang = func_0038D160(d, sqrt_asm(1.0f - d * d));
    func_0038CE90(&v, a1, dst + 0x20);
    if (v.f[2] < 0.99f) {
        yaw = func_0038D160(v.f[0], v.f[1]);
        e.f[0] = 0.0f;
        e.f[1] = 0.0f;
        e.f[2] = -yaw;
        func_0038D348(m1, &e);
        func_0038D640((Vec4 *)dst, m1, (Vec4 *)dst);
        func_0038D028(&v, &v, m1);
        pitch = func_0038D160(v.f[2], v.f[0]);
        e.f[0] = 0.0f;
        e.f[1] = -pitch;
        e.f[2] = 0.0f;
        func_0038D348(m0, &e);
        func_0038D640((Vec4 *)dst, m0, (Vec4 *)dst);
        func_0038D028(&v, &v, m0);
    } else {
        yaw = 0.0f;
        pitch = yaw;
    }
    if (a3 != 0) {
        e.f[0] = 0.0f;
        e.f[2] = ang;
    } else {
        func_L01_00448728(&out, self + 0xC4, 0, ang, fx, fy, fz);
        e.f[0] = 0.0f;
        e.f[2] = out;
    }
    e.f[1] = 0.0f;
    func_0038D348(m1, &e);
    func_0038D640((Vec4 *)dst, m1, (Vec4 *)dst);
    e.f[1] = pitch;
    e.f[2] = 0.0f;
    func_0038D348(m0, &e);
    func_0038D640((Vec4 *)dst, m0, (Vec4 *)dst);
    e.f[2] = yaw;
    e.f[1] = 0.0f;
    func_0038D348(m1, &e);
    func_0038D640((Vec4 *)dst, m1, (Vec4 *)dst);
    if (a3 != 0) {
        func_003C48A8((Vec4 *)dst, (void *)a3);
    } else {
        func_003C48A8((Vec4 *)dst, (Vec4 *)(self + 0xB0));
    }
}
/* localdecomp:end func_L39_006339B0 */

/* localdecomp:start func_L39_00633C78 */
extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004485E0(s32, f32, f32);

void func_L39_00633C78(u8 *a, s32 b, s32 c) {
    f32 v[4];

    ((void (*)(f32 *, s32, void *))func_0038D028)(v, b, a + 96);
    func_L01_004485E0(c, func_0038D160(v[0], v[1]), 0.0f);
}
/* localdecomp:end func_L39_00633C78 */
