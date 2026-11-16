#include "common.h"
#include "vu0.h"

typedef int s128_3D8F20 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_003D9510 */
extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];

s32 func_L01_003D9510(void) {
    s32 r = 0;
    if (D_L01_001D6740 != 0 || D_001A4F48[0] != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_003D9510 */

/* localdecomp:start func_L01_003D9540 */
extern s32 D_L01_001D673C_003D9540;
s32 func_L01_003D9540(void) {
    return D_L01_001D673C_003D9540;
}
/* localdecomp:end func_L01_003D9540 */

INCLUDE_ASM("asm/levels", func_L01_003D9548);

INCLUDE_ASM("asm/levels", func_L01_003D9FD0);

INCLUDE_ASM("asm/levels", func_L01_003DA3F0);

INCLUDE_ASM("asm/levels", func_L01_003DA6E8);

/* localdecomp:start func_L01_003DAAE0 */
extern void func_003C2F58(void *, s32, s128_3D8F20 *);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L01_003DAAE0(void *m) {
    s128_3D8F20 v;
    func_003C2F58(m, 14, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
    func_003C2F58(m, 15, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
}
/* localdecomp:end func_L01_003DAAE0 */

INCLUDE_ASM("asm/levels", func_L01_003DABC8);

INCLUDE_ASM("asm/levels", func_L01_003DB200);

/* localdecomp:start func_L01_003DB3F8 */
extern u8 D_L01_002A2E40_003DB3F8[];

void func_L01_003DB3F8(void) {
    s32 i;
    u8 *h = D_L01_002A2E40_003DB3F8;

    for (i = 0; i < 64; i++) {
        *(s32 *)(h + i * 0x30 + 0x20) = 0;
    }
}
/* localdecomp:end func_L01_003DB3F8 */

/* localdecomp:start func_L01_003DB428 */
typedef struct {
    u128_t position;           /* 0x00 */
    u8 pad_10[0x20 - 0x10];
    s32 active;                /* 0x20 */
    u8 pad_24[0x28 - 0x24];
    f32 phase;                 /* 0x28 */
    u8 pad_2C[0x30 - 0x2C];
} Duck_3DB428;

/* The V5 ducks in flight, 64 slots */
extern Duck_3DB428 D_L01_002A2E40[];
extern f32 func_0038D0B0(f32 angle);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_003DB768(void *position, s32 texture, s32 blend, f32 size, f32 a, f32 b, f32 c);

/* qwack_duck_v5_star_draw: draws each V5 Qwack-O-Ray duck in flight: two stars of texture 57
   turning both ways, pulsing with the duck's phase, and a 0x3B glow */
void func_L01_003DB428(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        if (D_L01_002A2E40[i].active != 0) {
            Duck_3DB428 *duck = &D_L01_002A2E40[i];

            func_003D9508(duck, 0x39, 0x207F7F8F, 1, func_0038D0B0(duck->phase) * 0.25f + 0.5f, -0.1f, duck->phase);
            func_003D9508(duck, 0x39, 0x207F7F8F, 1, func_0038D0B0(duck->phase) * 0.25f + 0.5f, -0.1f, -duck->phase);
            func_L01_003DB768(duck, 0x3B, 1, (func_0038D0B0(duck->phase) * 0.7f + 0.75f) * 0.1f, 0.2f, 0.0f, 0.005f);
        }
    }
}
/* localdecomp:end func_L01_003DB428 */

INCLUDE_ASM("asm/levels", func_L01_003DB588);

INCLUDE_ASM("asm/levels", func_L01_003DB680);

INCLUDE_ASM("asm/levels", func_L01_003DB768);

/* localdecomp:start func_L01_003DBC60 */
extern u8 D_L01_001DF538[8];
__asm__(".extern D_L01_001DF538, 8");

u8 *func_L01_003DBC60(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 4;
        return D_L01_001DF538;
    }
    return 0;
}
/* localdecomp:end func_L01_003DBC60 */

INCLUDE_ASM("asm/levels", func_L01_003DBC80);

/* localdecomp:start func_L01_003DC268 */
typedef struct {
    u128_t direction;
    f32 life;
    s32 ticks;
    s32 flag;
    s32 state;
    f32 length;
    s32 lead;
    s32 target;
} Vars_003DC268;
typedef struct {
    u8 pad0[16];
    u128_t position;
    u8 pad20[4];
    u8 *cls;
    u8 pad28[4];
    f32 scale;
    u8 opacity;
    u8 mode;
    u16 flags;
    u8 pad34[0x34];
    Vars_003DC268 *vars;
    u8 pad6C[0x4C];
    void *parent;
    u8 padBC[4];
    u8 matrix[0x30];
    f32 rotation[4];
} Obj_003DC268;
extern s32 D_L01_001DF4F8;
extern s32 D_L01_001DF4FC;
extern s32 D_L01_001DF528;
extern s32 D_L01_001DF52C;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DF4F8, 4");
__asm__(".extern D_L01_001DF4FC, 4");
__asm__(".extern D_L01_001DF528, 4");
__asm__(".extern D_L01_001DF52C, 4");
Obj_003DC268 *func_L01_003DC268(void *parent, s32 flag, u128_t *pos, f32 *dir, f32 life) {
    extern Obj_003DC268 *func_003C24B0(s32, s32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D308(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003C7C38(void *);
    Obj_003DC268 *obj;
    Vars_003DC268 *v;
    s32 end;
    s32 now;
    obj = func_003C24B0(7556, 128);
    if (obj) {
        v = obj->vars;
        obj->parent = parent;
        v->flag = flag;
        obj->opacity = 255;
        obj->flags = 128;
        obj->mode = 1;
        obj->scale = *(f32 *)(obj->cls + 36) * 0.75f;
        obj->position = *pos;
        obj->rotation[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
        obj->rotation[2] = func_0038D160(dir[0], dir[1]);
        func_0038D308(obj->matrix, obj->rotation);
        v->direction = *(u128_t *)dir;
        v->length = func_0038CEA8(dir);
        v->life = life;
        if (v->flag) v->ticks = D_L01_001DF4F8 * 2;
        else v->ticks = func_00382498(D_L01_001DF4FC, D_L01_001DF4F8);
        now = D_L01_001DFB40;
        v->target = -1;
        v->state = 0;
        end = now + D_L01_001DF52C;
        if (end < D_L01_001DF528) D_L01_001DF528 = -1;
        if (D_L01_001DF528 < now) {
            v->lead = 1;
            D_L01_001DF528 = end;
        } else v->lead = 0;
        func_L01_004450F0(obj, 1, -1);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003DC268 */

INCLUDE_ASM("asm/levels", func_L01_003DC400);

INCLUDE_ASM("asm/levels", func_L01_003DC690);

INCLUDE_ASM("asm/levels", func_L01_003DC780);

INCLUDE_ASM("asm/levels", func_L01_003DCAA0);

LINKER_REMNANT("asm/levels", func_L01_003DD0F0);

INCLUDE_ASM("asm/levels", func_L01_003DD0F8);

INCLUDE_ASM("asm/levels", func_L01_003DD9C8);

INCLUDE_ASM("asm/levels", func_L01_003DDDA8);

/* localdecomp:start func_L01_003DE198 */
extern u8 *func_00382348(void);

void func_L01_003DE198(void) {
    u8 *p = func_00382348();
    if (p != 0 && (u8)(p[14] - 1) < 2) {
        p[14] = 2;
    }
}
/* localdecomp:end func_L01_003DE198 */

INCLUDE_ASM("asm/levels", func_L01_003DE1D8);

/* localdecomp:start func_L01_003DE418 */
extern void func_0038D000(void *, void *, void *);

void func_L01_003DE418(u8 *obj, u128_t *out) {
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = -0.1f;
    v.w = 1.0f;
    func_0038D000(&v, &v, obj + 0xC0);
    vec_add_ba(out, &v, obj + 0x10);
}
/* localdecomp:end func_L01_003DE418 */

/* localdecomp:start func_L01_003DE488 */

extern void func_L01_003DE418(u8 *, u128_t *);
extern void func_L01_003DE510(u128_t *, u8 *, s32, s32, f32, f32, f32);
extern void func_L01_00409B08(u128_t *, s32, s32);

void func_L01_003DE488(u8 *m) {
    u128_t a;
    u128_t b;
    u8 *t;

    t = *(u8 **)(m + 104);
    if (t != 0) {
        func_L01_003DE418(m, &a);
        b = *(u128_t *)(m + 16);
        func_L01_003DE510(&b, t + 16, 0x1030FF, 4, 0.0f, 0.85f, 0.25f);
        func_L01_00409B08(&a, 0x2040FF, 0);
    }
}
/* localdecomp:end func_L01_003DE488 */

INCLUDE_ASM("asm/levels", func_L01_003DE510);

INCLUDE_ASM("asm/levels", func_L01_003DEB40);

INCLUDE_ASM("asm/levels", func_L01_003DEC20);

/* localdecomp:start func_L01_003DEDF8 */
#include "vu0.h"
extern u8 D_00142CC0[];
extern u8 D_00142D60[];
extern f32 D_001A4C60[];
extern f32 D_L01_001DF548;
__asm__(".extern D_L01_001DF548, 4");
void func_L01_003DEDF8(u8 *obj) {
    extern void func_L01_003DEB40(u8 *);
    extern void func_003C2880(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_L01_003DEC20(u8 *);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_00451F60(s32, s32, s32);
    extern s32 func_0039EF28(void);
    extern s32 func_L01_00436620(s32);
    extern s32 func_L01_0041A5B0(s32, s32);
    s32 state = obj[0x20];
    switch (state) {
    case 0:
        func_L01_003DEB40(obj);
        if (D_00142CC0[0]) {
            func_003C2880(obj);
        } else {
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    case 1:
        func_L01_003DEC20(obj);
        if (func_L01_0040E570(obj + 0x10, D_001A4C60) < D_L01_001DF548 * D_L01_001DF548) {
            if (fabs_asm(*(f32 *)(obj + 0x18) - D_001A4C60[2]) < D_L01_001DF548) {
                func_L01_00451F60(0xAF7, -1, 0);
                D_00142CC0[0] = state;
                D_00142D60[0] = state;
                func_0039EF28();
                obj[0x31] = 0;
                *(u16 *)(obj + 0x34) |= 1;
                func_L01_004450F0(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (!func_L01_00436620(0) && func_L01_0041A5B0(0x1627, 0x138)) {
            func_003C2880(obj);
        }
        break;
    }
}
/* localdecomp:end func_L01_003DEDF8 */

/* localdecomp:start func_L01_003DEF68 */
typedef struct {
    u8 p0[0x1210];
    s32 w1210;
    u8 p1214[0xC];
    s32 w1220;
} S_003DEF68;
extern S_003DEF68 D_001A4BE0;
extern s32 D_L01_001D6694;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_003A0EC0(s32, s32, s32, s32, s32);

void func_L01_003DEF68(u8 *obj) {
    if (obj[0x20] == 0) {
        obj[0x20] = 1;
    }
    if (D_L01_001D6694 == 0) {
        u8 *hero = D_001D52FC;
        if ((*(s32 *)(hero + 0x1A4) & D_001A4BE0.w1210) != 0) {
            if (D_001A4BE0.w1220 >= 0x13) {
                func_003A0EC0(5, 1, 4, 0, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_003DEF68 */

INCLUDE_ASM("asm/levels", func_L01_003DEFE8);

INCLUDE_ASM("asm/levels", func_L01_003DF1B0);

/* localdecomp:start func_L01_003DF558 */
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_003DF558(u8 *p)
{
    s32 *o = *(s32 **)(p + 0x68);
    s32 c;
    s32 rgba;

    c = 0x80 - o[2] * 2;
    rgba = c << 24 | c << 16 | c << 8 | c;
    func_003A9440(0x42, 0x48);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
}
/* localdecomp:end func_L01_003DF558 */

/* localdecomp:start func_L01_003DF620 */
typedef struct { u8 p[0x20]; f32 angle; s32 timer; } State_003DF620;
typedef struct { vu0_v4 position; void *owner; u8 p24[4]; f32 scale; u8 p2C[4]; s32 a, b, c, d; f32 e, f, phase; u8 p3C[0x14]; } Row_003DF620;
extern u8 D_L01_002A3A40[];
extern s32 D_L01_001DF550;
__asm__(".extern D_L01_001DF550, 4");
void func_L01_003DF620(u8 *obj) {
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, f32);
    vu0_v4 out;
    vu0_v4 origin;
    State_003DF620 *state;
    Row_003DF620 *row;
    u8 *base;
    s32 n, count;
    state = *(State_003DF620 **)(obj + 0x68);
    if (state != 0) {
        count = 0;
        for (n = 0; n < 24; n++) {
            base = D_L01_002A3A40 + n * 0x50;
            row = (Row_003DF620 *)(base + 0x10);
            if (row->owner != obj) goto next;
            if (count < (120 - state->timer) / 5) {
                func_0038D890(&row->position, &row->position, base, row->scale);
                count++;
                row->phase += 0.06f;
                func_0038CF68(&row->position, &row->position, row->phase);
                vec_add_ab(&out, &row->position, obj + 0x10);
                *(u128_t *)&origin = *(u128_t *)(obj + 0x10);
                func_L01_0040A8C0(&origin, &out, D_L01_001DF550, 1, row->e, row->f, row->a, row->b, row->c, row->d, state->angle);
            }
        next:;
        }
        state->angle -= 0.018f;
        if (state->angle <= -8.0f) state->angle += 8.0f;
    }
}
/* localdecomp:end func_L01_003DF620 */

INCLUDE_ASM("asm/levels", func_L01_003DF7A8);

/* localdecomp:start func_L01_003DF8B8 */
void func_L01_003DF8B8(void) {

}
/* localdecomp:end func_L01_003DF8B8 */

INCLUDE_ASM("asm/levels", func_L01_003DF8C0);

INCLUDE_ASM("asm/levels", func_L01_003E0058);

INCLUDE_ASM("asm/levels", func_L01_003E01B8);
