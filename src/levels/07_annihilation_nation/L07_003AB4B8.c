#include "common.h"
#include "vu0.h"

extern void func_003C2F58(u8 *, s32, f32 *);

/* localdecomp:start func_L07_003AB4B8 */
void func_L07_003AB4B8(u8 *obj) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00474078(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
    vu0_q base, velocity, origin;
    u8 *state = *(u8 **)(obj + 0x68);
    s32 i;
    func_003C2F58(obj, state[0x533], (f32 *)&base);
    for (i = 1; i >= 0; i--) {
        f32 speed, angle, pitch;
        s32 life;
        speed = func_003824E0(3.0f, 5.0f);
        angle = func_003824E0(-0.785398185f, 0.785398185f);
        angle = func_0038DB48(*(f32 *)(obj + 0xF8) + *(f32 *)(state + 0x2A8) + angle);
        pitch = func_003824E0(-0.785398185f, 0.785398185f);
        func_00382760(&velocity, speed, angle, pitch);
        life = func_00382498(20, 30);
        if (*(s16 *)(state + 0x530) < life) life = *(s16 *)(state + 0x530);
        origin = base;
        vec_add_ab(&origin, &base, &velocity);
        func_0038CE20(&velocity, &velocity, -1.0f / life);
        func_L01_00474078(&origin, &velocity, life, 0x80808020, 0x30FF8020, 4, 0, 0.04f, 3.0f, 1.5f, 0.5f);
    }
}
/* localdecomp:end func_L07_003AB4B8 */

/* localdecomp:start func_L07_003AB678 */
typedef struct { u8 pad0[0x164]; u8 *texture; } Effects_003AB678;
extern Effects_003AB678 D_L07_0021EC98;
extern void func_003C2F58(u8 *a, s32 b, f32 *out);

void func_L07_003AB678(u8 *object) {
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_003C4C18(void *, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, f32, f32, s32, f32);
    vu0_v4 origin;
    vu0_v4 position;
    vu0_v4 velocity;
    u8 *state = *(u8 **)(object + 0x68);
    f32 speed;
    f32 angle;
    f32 size;
    s32 n;
    s32 i;
    s32 duration;
    u8 kind;
    u8 frame;
    u8 *effect;

    if (*(f32 *)(state + 0x538) == 1.0f) {
        *(vu0_q *)&origin = *(vu0_q *)(state + 0x520);
    } else {
        func_003C2F58(object, state[0x533], (f32 *)&position);
        vec_sub_ba(&origin, state + 0x520, &position);
        func_0038CE20(&origin, &origin, *(f32 *)(state + 0x538));
        vec_add_ab(&origin, &position, &origin);
    }
    n = func_00382498(0, 2);
    for (i = 0; i < n; i++) {
        *(vu0_q *)&position = *(vu0_q *)&origin;
        func_003C4C18(&position, 0.3f);
        speed = func_003824E0(3.0f, 5.5f) * 0.020000001f;
        angle = func_00382538();
        func_00382760(&velocity, speed, angle, func_003824E0(1.0471976f, 3.1415927f));
        kind = 253;
        if (func_00382468(2) == 0) {
            kind = 3;
        }
        frame = func_00382468(256);
        duration = (func_00382498(20, 40) * 5 + 2) / 6;
        size = func_003824E0(0.25f, 0.75f) * 210000.0f;
        effect = func_L01_0046FB40(&position, &velocity, duration, 0x806020, kind, 127, 0, size, size, 0, 0.00392f);
        if (effect) {
            effect[2] = *D_L07_0021EC98.texture;
            frame = effect[8] + 32;
        }
        size *= 0.3f;
        effect = func_L01_0046FB40(&position, &velocity, duration, 0xFFFFFF, kind, 127, 64, size, size, 0, 0.00392f);
        if (effect) {
            effect[8] = frame;
            effect[2] = *D_L07_0021EC98.texture;
        }
    }
}
/* localdecomp:end func_L07_003AB678 */

/* localdecomp:start func_L07_003AB918 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003AB918;
typedef struct {
    V_003AB918 vertex[4];
    s32 color[4];
    f32 uv[8];
    u8 rest[0x20];
} Quad_003AB918;
extern V_003AB918 D_L07_001E1EC0;
void func_L07_003AB918(u8 *obj) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_00382538(void);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    V_003AB918 start;
    V_003AB918 direction;
    V_003AB918 end;
    V_003AB918 side0;
    V_003AB918 side1;
    Quad_003AB918 quad;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 fraction = (f32)*(s16 *)(vars + 0x530) / 10.0f;
    f32 width;
    f32 width2;
    f32 length;
    f32 random;
    if (fraction > 1.0f) fraction = 1.0f;
    func_003C2F58(obj, vars[0x533], (f32 *)&start);
    vec_sub_ab(&direction, (V_003AB918 *)(vars + 0x520), &start);
    if (*(f32 *)(vars + 0x538) == 1.0f) {
        end = *(V_003AB918 *)(vars + 0x520);
    } else {
        func_0038CE20(&end, &direction, *(f32 *)(vars + 0x538));
        vec_add_ab(&end, &start, &end);
    }
    vec_sub_ab(&side0, &start, &D_L07_001E1EC0);
    width = fraction * 0.25f;
    func_0038CE90(&side0, &side0, &direction);
    func_0038CF68(&side0, &side0, width);
    vec_sub_ab(&side1, &end, &D_L07_001E1EC0);
    func_0038CE90(&side1, &side1, &direction);
    func_0038CF68(&side1, &side1, width);
    func_003D93B0(&quad, 0x2B, 1, 0x80);
    quad.color[3] = 0x40802020;
    quad.color[2] = 0x40802020;
    quad.color[1] = 0x40802020;
    quad.color[0] = 0x40802020;
    vec_add_ba(&quad.vertex[0], &start, &side0);
    vec_sub_ab(&quad.vertex[1], &start, &side0);
    vec_add_ba(&quad.vertex[2], &end, &side1);
    vec_sub_ab(&quad.vertex[3], &end, &side1);
    quad.uv[0] = 0.0f;
    quad.uv[1] = 0.0f;
    quad.uv[2] = 0.0f;
    quad.uv[3] = 1.0f;
    quad.uv[4] = 1.0f;
    quad.uv[5] = 0.0f;
    quad.uv[6] = 1.0f;
    quad.uv[7] = 1.0f;
    func_003D2DA0(&quad, 0, 0);
    func_003D93B0(&quad, 0x27, 1, 0x80);
    width2 = fraction * 0.35f;
    quad.color[1] = -256;
    quad.color[3] = 0x80FF0000;
    quad.color[0] = -256;
    quad.color[2] = 0x80FF0000;
    func_0038CF68(&side0, &side0, width2);
    func_0038CF68(&side1, &side1, width2);
    vec_add_ba(&quad.vertex[0], &start, &side0);
    vec_sub_ab(&quad.vertex[1], &start, &side0);
    vec_add_ba(&quad.vertex[2], &end, &side1);
    vec_sub_ab(&quad.vertex[3], &end, &side1);
    length = *(f32 *)(vars + 0x538) * 4.0f;
    quad.uv[0] = 0.0f - *(f32 *)(vars + 0x534);
    quad.uv[1] = 0.0f;
    quad.uv[2] = 0.0f - *(f32 *)(vars + 0x534);
    quad.uv[3] = 1.0f;
    quad.uv[4] = length - *(f32 *)(vars + 0x534);
    quad.uv[5] = 0.0f;
    quad.uv[6] = length - *(f32 *)(vars + 0x534);
    quad.uv[7] = 1.0f;
    func_003D2DA0(&quad, 0, 0);
    random = func_00382538();
    func_003D9508(&start, 0x47, 0x60606020, 1, 0.9f, 0.4f, random);
    random = func_00382538();
    func_003D9508(&start, 0x47, 0x80FFFFFF, 1, 0.25f, 0.4f, random);
    random = func_00382538();
    func_003D9508(&end, 0x47, 0x60604020, 0, 0.75f, 0.0f, random);
    random = func_00382538();
    func_003D9508(&end, 0x47, 0x80FFFFFF, 0, 0.5f, 0.0f, random);
}
/* localdecomp:end func_L07_003AB918 */

/* localdecomp:start func_L07_003ABD18 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L07_003AC2D0(void *);
extern void func_L07_003AC500(void *);
void func_L07_003ACA90(void *, s32);
extern void func_L07_003ACD58(void *, f32);
extern void func_L07_003ACF40(u8 *);
extern void func_L07_003AD088(void *);
extern void func_L07_003AD180(void *);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L07_00331008(u8 *, void *);
extern s32 func_L07_00334408(u8 *);
extern s32 func_L07_003346D8(u8 *);
extern void func_L07_00334588(u8 *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_00404808(void *, void *);

void func_L07_003ABD18(u8 *self) {
    u8 *p;
    f32 d;

    if (self[0x20] == 0) func_L07_003AC2D0(self);
    func_L07_003AC500(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0(self);
        if (func_0038CB00(p + 0x24E)) func_L07_003ACA90(self, 3);
        break;
    case 3:
        func_L01_0045A9F0(self);
        func_L07_003ACA90(self, 4);
        break;
    case 4:
        func_L01_0045A748(self, *(u8 **)(p + 0x240) + 0x10);
        if (func_L01_0040E570(*(u8 **)(p + 0x240) + 0x10, self + 0x10) < 484.0f) {
            p[0x25E] = 1;
            func_L07_003ACA90(self, 6);
        }
        break;
    case 5:
        func_L01_0045A9F0(self);
        if (func_L01_00454370(self, p + 0x70) & 2) {
            if (p[0x25E] == 0) {
                func_L07_003ACA90(self, 4);
            } else {
                func_L07_003ACA90(self, 6);
            }
        }
        break;
    case 6:
        func_L01_0045A9F0(self);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (func_L01_0040E570(self + 0x10, p + 0x130) < 121.0f) {
                func_L07_003ACA90(self, 8);
            } else {
                func_L07_003ACA90(self, 7);
            }
        } else {
            func_L07_003ACA90(self, 13);
        }
        break;
    case 7:
        func_L07_003ACD58(self, 5.0f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (func_L01_0040E570(self + 0x10, p + 0x130) < 64.0f) {
                func_L07_003ACA90(self, 8);
            }
        } else {
            func_L07_003ACA90(self, 6);
        }
        break;
    case 8:
        func_L07_003ACD58(self, 1.5f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            if (121.0f < func_L01_0040E570(self + 0x10, p + 0x130)) {
                *(s32 *)(p + 0x188) &= ~0x10;
                func_L07_003ACA90(self, 7);
            } else if (func_0038CB00(p + 0x564)) {
                if (func_L01_0040E570(self + 0x10, p + 0x130) < 6.25f) {
                    *(s16 *)(p + 0x24C) = func_L07_00334408(self);
                    if (func_L07_003346D8(self)) func_L07_003ACA90(self, 10);
                }
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(self);
            func_L07_003ACA90(self, 6);
        }
        break;
    case 9:
        func_L07_003ACD58(self, 1.5f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) {
            f32 dist = func_0038CF38(self + 0x10, p + 0x130);
            if (11.0f < dist) {
                *(s32 *)(p + 0x188) &= ~0x10;
                func_L07_00334588(self);
                func_L07_003ACA90(self, 7);
            } else if (dist < 2.5f) {
                func_L07_003ACA90(self, 10);
            }
        } else {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_00334588(self);
            func_L07_003ACA90(self, 6);
        }
        break;
    case 10:
        d = func_L01_004395E0(self);
        func_L01_0045A9F0(self);
        if (10.0f < d) {
            (*(u16 *)(p + 0x564))++;
            if (!(*(u16 *)(p + 0x564) % 2)) func_L07_003AD088(self);
            func_L01_00404808(func_L07_003AD180, self);
        }
        if (13.0f < d && d < 16.0f) func_L07_003ACF40(self);
        if (self[0x60] & 2) {
            func_L07_00334588(self);
            if (p[0x566] == 0) {
                *(s16 *)(p + 0x564) = 50;
                func_L07_003ACA90(self, 6);
            } else {
                func_L07_003ACA90(self, 12);
            }
        }
        break;
    case 11:
        (*(u16 *)(p + 0x564))++;
        if (!(*(u16 *)(p + 0x564) % 2)) func_L07_003AD088(self);
        func_L01_00404808(func_L07_003AD180, self);
        func_L01_0045A9F0(self);
        func_L07_003ACF40(self);
        if (self[0x60] & 2) {
            func_L07_00334588(self);
            if (p[0x566] != 0) {
                if (self[0x43] != 8) func_003C3A10(self, 8, 0, 10);
                func_L07_003ACA90(self, 12);
            } else {
                *(s16 *)(p + 0x564) = 50;
                if (self[0x43] != 3) func_003C3A10(self, 3, 0, 10);
                func_L01_004450F0(self, 6, -1);
            }
        }
        break;
    case 12:
        func_L07_003ACD58(self, 4.0f);
        if (self[0x60] & 2) {
            *(s32 *)(p + 0x188) &= ~0x10;
            func_L07_003ACA90(self, 6);
        }
        break;
    case 13:
        func_L07_003ACD58(self, 8.0f);
        if (func_L07_00331008(*(u8 **)(p + 0x240), self)) func_L07_003ACA90(self, 6);
        break;
    }
}
/* localdecomp:end func_L07_003ABD18 */
