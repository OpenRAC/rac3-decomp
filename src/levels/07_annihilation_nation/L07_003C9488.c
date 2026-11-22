#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

extern void func_003C2F58(u8 *, s32, f32 *);

/* localdecomp:start func_L07_003C9488 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L07_0021D2C0[];
extern s32 func_L06_004591F8(void *, void *, u8);

void func_L07_003C9488(u8 *a0, s32 idx, u8 mode) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *t = D_L07_0021D2C0[idx];
    u128_t pos;
    s32 r;
    u8 c;

    *(u8 **)(s + 0x214) = t;
    pos = *(u128_t *)(a0 + 0x10);
    r = func_L06_004591F8(&pos, t, 0);
    *(s16 *)(s + 0x218) = r;
    c = mode;
    if (mode == 2) {
        c = (*(s32 *)t >> 1) < (s16)r;
    }
    if (c == 0) {
        *(s16 *)(s + 0x21A) = *(u16 *)t - 1;
    } else {
        *(s16 *)(s + 0x21A) = 0;
    }
}
/* localdecomp:end func_L07_003C9488 */

INCLUDE_ASM("asm/levels", func_L07_003C9528);

#include "vu0.h"

/* localdecomp:start func_L07_003C96C0 */
typedef int Quad_003C96C0 __attribute__((mode(TI)));
typedef struct Path_003C96C0 {
    s32 count;
    u8 pad04[0xC];
    Quad_003C96C0 pts[1];
} Path_003C96C0;

extern void func_0038CE20(void *, void *, f32);

void func_L07_003C96C0(Path_003C96C0 *path, Quad_003C96C0 *out, f32 t) {
    vu0_v4 d;
    s32 i = (u8)(s32)t;

    if (i >= path->count - 1) {
        *out = *(Quad_003C96C0 *)((u8 *)path + path->count * 16);
    } else {
        vec_sub_ba(&d, &path->pts[(u8)(i + 1)], &path->pts[i]);
        func_0038CE20(&d, &d, t - (f32)i);
        vec_add_ba(out, &path->pts[i], &d);
    }
}
/* localdecomp:end func_L07_003C96C0 */

/* localdecomp:start func_L07_003C9780 */
void func_L07_003C9780(float *a, float *b, float da, float db) {
    *a += da;
    if (*a > 1.0f) {
        *a = 1.0f;
    }
    *b += db;
    if (*b > 1.0f) {
        *b -= 1.0f;
    }
}
/* localdecomp:end func_L07_003C9780 */

/* localdecomp:start func_L07_003C97D0 */
/* from rac2-decomp's func_00312E10, renamed */
int func_L07_003C97D0(unsigned char *p) { return p[0x20] == 1; }
/* localdecomp:end func_L07_003C97D0 */

/* localdecomp:start func_L07_003C97E0 */
#include "vu0.h"
void func_L07_003C97E0(u8 *obj) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00474078(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
    vu0_q base, velocity, origin;
    u8 *state = *(u8 **)(obj + 0x68);
    s32 i;
    func_003C2F58(obj, state[0x4DC], (f32 *)&base);
    for (i = 1; i >= 0; i--) {
        f32 speed, angle, pitch;
        s32 life;
        speed = func_003824E0(3.0f, 5.0f);
        angle = func_003824E0(-0.785398185f, 0.785398185f);
        angle = func_0038DB48(*(f32 *)(obj + 0xF8) + *(f32 *)(state + 0x288) + angle);
        pitch = func_003824E0(-0.785398185f, 0.785398185f);
        func_00382760(&velocity, speed, angle, pitch);
        life = func_00382498(20, 30);
        if (*(s16 *)(state + 0x4C6) < life) life = *(s16 *)(state + 0x4C6);
        origin = base;
        vec_add_ab(&origin, &base, &velocity);
        func_0038CE20(&velocity, &velocity, -1.0f / life);
        func_L01_00474078(&origin, &velocity, life, 0x80808020, 0x30FF8020, 4, 0, 0.04f, 3.0f, 1.5f, 0.5f);
    }
}
/* localdecomp:end func_L07_003C97E0 */

/* localdecomp:start func_L07_003C99A0 */
typedef struct { u8 pad0[0x164]; u8 *texture; } Effects_003C99A0;
extern Effects_003C99A0 D_L07_0021EC98;

void func_L07_003C99A0(u8 *object) {
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

    if (*(f32 *)(state + 0x488) == 1.0f) {
        *(vu0_q *)&origin = *(vu0_q *)(state + 0x470);
    } else {
        func_003C2F58(object, state[0x4DC], (f32 *)&position);
        vec_sub_ba(&origin, state + 0x470, &position);
        func_0038CE20(&origin, &origin, *(f32 *)(state + 0x488));
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
/* localdecomp:end func_L07_003C99A0 */

/* localdecomp:start func_L07_003C9C40 */
#include "vu0.h"
void func_L07_003C9C40(u8 *obj) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L07_003C9E88(void *, void *, f32, f32);
    vu0_v4 start, delta, end;
    u8 *p = *(u8 **)(obj + 0x68);
    f32 t;
    func_003C2F58(obj, p[0x4DC], (f32 *)&start);
    vec_sub_ab(&delta, p + 0x470, &start);
    if (*(f32 *)(p + 0x488) == 1.0f) {
        *(vu0_q *)&end = *(vu0_q *)(p + 0x470);
    } else {
        func_0038CE20(&end, &delta, *(f32 *)(p + 0x488));
        vec_add_ab(&end, &start, &end);
    }
    if (obj[0x20] != 0x1A) {
        t = *(s16 *)(p + 0x4C6) / 10.0f;
        if (t > 1.0f) t = 1.0f;
        func_L07_003C9E88(&start, &end, t, *(f32 *)(p + 0x48C));
    } else {
        func_L07_003C9E88(&start, &end, 1.0f, *(f32 *)(p + 0x48C));
    }
}
/* localdecomp:end func_L07_003C9C40 */

/* localdecomp:start func_L07_003C9D50 */
extern void func_L07_003C9D88(u8 *o, s32 a);

void func_L07_003C9D50(u8 *a) {
    func_L07_003C9D88(a, 0);
    func_L07_003C9D88(a, 1);
}
/* localdecomp:end func_L07_003C9D50 */

/* localdecomp:start func_L07_003C9D88 */
#include "vu0.h"
void func_L07_003C9D88(u8 *obj, s32 index) {
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L07_003C9280(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L07_003C9E88(void *, void *, f32, f32);
    vu0_v4 matrix[4];
    vu0_v4 pos;
    vu0_v4 offset;
    vu0_v4 target;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 side = (u8)index;
    func_003C2EC0(obj, side, matrix);
    pos = matrix[3];
    func_0038CF68(&offset, &matrix[1], side == 0 ? 20.0f : -20.0f);
    vec_add_ab(vars + 0x470, &pos, &offset);
    func_L07_003C9280(obj);
    if (*(f32 *)(vars + 0x488) == 1.0f) {
        vec_add_ab(&target, &pos, &offset);
    } else {
        func_0038CE20(&target, &offset, *(f32 *)(vars + 0x488));
        vec_add_ab(&target, &pos, &target);
    }
    func_L07_003C9E88(&pos, &target, 1.0f, *(f32 *)(vars + 0x48C));
}
/* localdecomp:end func_L07_003C9D88 */

INCLUDE_ASM("asm/levels", func_L07_003C9E88);
