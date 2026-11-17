#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E40A0;

/* localdecomp:start func_L12_003E61E0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003E61E0;

typedef struct {
    u8 pad00[0x4C];
    f32 f4C;
    s32 i50;
    u8 pad54[0x5C - 0x54];
    f32 f5C;
} Var_003E61E0;

typedef struct {
    u8 pad000[0x250];
    s32 r;
    s32 g;
    s32 b;
} Rgb_003E61E0;

extern s32 func_0038DC20(void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_003A9440(s32, unsigned long);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB48(f32);
extern void func_0038D328(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L12_0040DEE0(void *, s32, s32, s32, s32, f32, f32, f32);

extern u8 D_L12_001E2700[];
extern s32 D_L12_001DF840;
extern Rgb_003E61E0 D_L12_001E72C0;

extern f32 D_L12_001DF2F0;
__asm__(".extern D_L12_001DF2F0, 4");
extern s32 D_L12_001DF324;
__asm__(".extern D_L12_001DF324, 4");
extern s32 D_L12_001DF328;
__asm__(".extern D_L12_001DF328, 4");
extern s32 D_L12_001DF32C;
__asm__(".extern D_L12_001DF32C, 4");
extern s32 D_L12_001DF330;
__asm__(".extern D_L12_001DF330, 4");
extern s32 D_L12_001DF334;
__asm__(".extern D_L12_001DF334, 4");
extern f32 D_L12_001DF338;
__asm__(".extern D_L12_001DF338, 4");
extern f32 D_L12_001DF344;
__asm__(".extern D_L12_001DF344, 4");
extern f32 D_L12_001DF348;
__asm__(".extern D_L12_001DF348, 4");
extern f32 D_L12_001DF34C;
__asm__(".extern D_L12_001DF34C, 4");
extern f32 D_L12_001DF350;
__asm__(".extern D_L12_001DF350, 4");
extern s32 D_L12_001DF354;
__asm__(".extern D_L12_001DF354, 4");
extern f32 D_L12_001DF358;
__asm__(".extern D_L12_001DF358, 4");
extern f32 D_L12_001DF35C;
__asm__(".extern D_L12_001DF35C, 4");
extern f32 D_L12_001DF360;
__asm__(".extern D_L12_001DF360, 4");
extern f32 D_L12_001DF364;
__asm__(".extern D_L12_001DF364, 4");
extern f32 D_L12_001DF368;
__asm__(".extern D_L12_001DF368, 4");
extern f32 D_L12_001DF36C;
__asm__(".extern D_L12_001DF36C, 4");
extern f32 D_L12_001DF370;
__asm__(".extern D_L12_001DF370, 4");
extern f32 D_L12_001DF374;
__asm__(".extern D_L12_001DF374, 4");

void func_L12_003E61E0(u8 *o) {
    V4_003E61E0 sphere;
    V4_003E61E0 rot;
    V4_003E61E0 m[4];
    V4_003E61E0 *pos;
    Var_003E61E0 *v;
    f32 dist;
    f32 a;
    f32 b;
    f32 range;
    f32 t;
    s32 color;
    u8 type;

    pos = (V4_003E61E0 *)(o + 0x10);
    sphere = *pos;
    v = *(Var_003E61E0 **)(o + 0x68);
    sphere.w = v->f4C;
    if (func_0038DC20(&sphere, (f32)*(s16 *)(o + 0x32)) == -1) {
        return;
    }
    dist = func_0038CF00(pos, D_L12_001E2700);
    if ((f32)*(s16 *)(o + 0x32) < dist) {
        return;
    }
    type = o[0x20];
    if (type == 2) {
        if (v->f5C < D_L12_001DF358) {
            b = 0.0f;
        } else if (D_L12_001DF35C < v->f5C) {
            b = 1.0f;
        } else {
            b = (v->f5C - D_L12_001DF358) / (D_L12_001DF35C - D_L12_001DF358);
        }
        if (v->f5C < D_L12_001DF360) {
            a = 0.0f;
        } else if (D_L12_001DF364 < v->f5C) {
            a = 1.0f;
        } else {
            a = (v->f5C - D_L12_001DF360) / (D_L12_001DF364 - D_L12_001DF360);
        }
    } else if (type == 3) {
        if (D_L12_001DF368 < v->f5C) {
            b = 1.0f;
        } else if (v->f5C < D_L12_001DF36C) {
            b = 0.0f;
        } else {
            b = (v->f5C - D_L12_001DF36C) / (D_L12_001DF368 - D_L12_001DF36C);
        }
        if (D_L12_001DF370 < v->f5C) {
            a = 1.0f;
        } else if (v->f5C < D_L12_001DF374) {
            a = 0.0f;
        } else {
            a = (v->f5C - D_L12_001DF374) / (D_L12_001DF370 - D_L12_001DF374);
        }
    } else {
        b = 1.0f;
        a = 1.0f;
    }
    range = (f32)*(s16 *)(o + 0x32) - D_L12_001DF2F0;
    if (range < dist) {
        f32 k = 1.0f - (dist - range) / D_L12_001DF2F0;
        b *= k;
        a *= k;
    }
    func_003A9440(0x3D, 0);
    t = (f32)(D_L12_001DF840 % D_L12_001DF354) / (f32)D_L12_001DF354;
    if (0.0f < a) {
        f32 ang;

        color = func_0038DBD8(0x7F000000, D_L12_001DF32C, a);
        qzero(&rot);
        ang = (f32)(D_L12_001DF840 % D_L12_001DF334) / (f32)D_L12_001DF334;
        ang = (ang + ang) * 3.1415927f - 3.1415927f;
        rot.z = func_0038DB48(func_0038D098(ang) * (D_L12_001DF338 * 0.017453292f));
        func_0038D328(m, &rot);
        func_0038CE20(&m[0], &m[0], v->f4C);
        func_0038CE20(&m[1], &m[1], v->f4C);
        func_0038CE20(&m[2], &m[2], v->f4C);
        func_0038D5F0(m, o + 0xC0, m);
        m[3] = *(V4_003E61E0 *)(o + 0x10);
        func_L12_0040DEE0(m, D_L12_001DF324, color, v->i50, 1, t + 0.5f, D_L12_001DF344, D_L12_001DF348);
    }
    if (0.0f < b) {
        f32 ang;

        color = func_0038DBD8(0x7F000000, D_L12_001DF330, b);
        qzero(&rot);
        ang = (f32)((D_L12_001DF840 + D_L12_001DF334 / 2) % D_L12_001DF334) / (f32)D_L12_001DF334 * 2.0f * 3.1415927f - 3.1415927f;
        rot.z = func_0038DB48(func_0038D098(ang) * (D_L12_001DF338 * 0.017453292f));
        func_0038D328(m, &rot);
        func_0038CE20(&m[0], &m[0], v->f4C);
        func_0038CE20(&m[1], &m[1], v->f4C);
        func_0038CE20(&m[2], &m[2], v->f4C);
        func_0038D5F0(m, o + 0xC0, m);
        m[3] = *(V4_003E61E0 *)(o + 0x10);
        func_L12_0040DEE0(m, D_L12_001DF328, color, v->i50, 1, t, D_L12_001DF34C, D_L12_001DF350);
        qzero(&rot);
        rot.z = func_0038DB48(func_0038D0B0(ang) * (D_L12_001DF338 * 0.017453292f));
        func_0038D328(m, &rot);
        func_0038CE20(&m[0], &m[0], v->f4C);
        func_0038CE20(&m[1], &m[1], v->f4C);
        func_0038CE20(&m[2], &m[2], v->f4C);
        func_0038D5F0(m, o + 0xC0, m);
        m[3] = *(V4_003E61E0 *)(o + 0x10);
        func_L12_0040DEE0(m, D_L12_001DF328, color, v->i50, 1, t + 0.5f, D_L12_001DF34C, D_L12_001DF350);
    }
    func_003A9440(0x3D, (unsigned long)D_L12_001E72C0.r | ((unsigned long)D_L12_001E72C0.g << 8) | ((unsigned long)D_L12_001E72C0.b << 16));
}
/* localdecomp:end func_L12_003E61E0 */
