#include "common.h"

typedef struct {
    u8 pad[0x14];
    f32 f14;
    f32 f18;
    u8 tail[0x100 - 0x1C];
} S_3D9330;

extern S_3D9330 *D_L07_001DF41C;

/* localdecomp:start func_L07_003D8B18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003D8B18;
extern f32 D_L07_001DE8F4;
extern f32 D_L07_001DE8F8;
extern s32 D_L07_001DE8FC;
extern s32 D_L07_001DE900;
extern s32 D_L07_001DEF40;
typedef struct { u8 pad[0x20]; f32 scale; s32 pad24, timer, state; } State_003D8B18;
extern State_003D8B18 D_L07_001E1EC0;
__asm__(".extern D_L07_001DE8F4, 4");
__asm__(".extern D_L07_001DE8F8, 4");
__asm__(".extern D_L07_001DE8FC, 4");
__asm__(".extern D_L07_001DE900, 4");
void func_L07_003D8B18(u8 *obj) {
    extern u8 *func_L01_00447490(void *, s32, s32);
    extern void func_L07_003D89A8(void *, s32, s32, f32, f32, f32, f32, s32);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                                 f32, f32, f32, f32, f32, f32, f32, f32);
    extern void func_L01_00451E78(void *, s32, f32);
    extern void func_L01_004450F0(s32, s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(void *);
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *actor;
    f32 ratio, zero, size;
    s32 life;
    switch (obj[0x20]) {
    case 0:
        actor = func_L01_00447490(obj, -1, 1);
        if (actor == 0) break;
        *(f32 *)(state + 8) += *(f32 *)(actor + 0x2C);
        if (*(f32 *)(state + 8) > *(f32 *)(state + 0xC)) {
            f32 radius = 4.0f;
            f32 speed = 1.5f;
            *(f32 *)(state + 4) -= *(f32 *)(state + 0xC);
            *(s32 *)(state + 8) = 0;
            zero = *(f32 *)(state + 8);
            ratio = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
            func_L07_003D89A8(obj, 5, 255, zero, radius, speed, ratio, 1);
            func_L07_003D89A8(obj, 5, 255, zero, radius, speed, ratio, 1);
        }
        if (*(f32 *)(state + 4) <= 0.0f) {
            func_003A52A0(0, 0, obj);
            {
                Vec_003D8B18 v = {0};
                v.z = 1.0f;
                func_0038CE20(&v, &v, D_L07_001DE8F4 * 0.020000001415610313f);
                size = func_003824E0(20.0f, 40.0f);
                life = func_00382498(70, 100);
                func_L01_00451FE0(obj, 127, &v, 255, life, 0, 0, 35, 0, 3,
                                  3.0f, 6.0f, 3.0f, 6.0f, D_L07_001DE8F8, size, 1.0f, 1.0f);
            }
            func_L01_00451E78(obj, 1, 0.0f);
            {
                State_003D8B18 *g = &D_L07_001E1EC0;
                g->state = 0;
                g->timer = 25;
                g->scale = 1.0f;
            }
            obj[0x31] = 0;
            {
                s32 count = D_L07_001DE8FC;
                *(u16 *)(obj + 0x34) |= 1;
                *(s32 *)state = (count * 5 + 2) / 6;
            }
            func_L01_004450F0((s32)obj, 1, -1);
        }
        break;
    case 1:
        if (D_L07_001DEF40 % D_L07_001DE900 == 0) {
            ratio = *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
            func_L07_003D89A8(obj, 5, 255, 0.0f, 4.0f, 1.5f, ratio, 2);
        }
        if (func_0038CAD0(state)) func_L01_004450F0((s32)obj, 2, -1);
        break;
    case 2:
        func_003C2880(obj);
        return;
    }
    obj[0xA8] = 255;
}
/* localdecomp:end func_L07_003D8B18 */

/* localdecomp:start func_L07_003D8E28 */
void func_L07_003D8E28(s32 self) {
    extern void func_L07_003D90A8(s32);
    extern s32 func_L07_003D9630(u8 *);
    extern void func_L01_004450F0(s32, s32, s32);
    extern void func_L07_003D9298(s32);
    extern void func_L07_003D9330(s32);
    u8 *v;
    func_L07_003D90A8(self);
    v = *(u8 **)(self + 0x68);
    switch (*(u8 *)(self + 0x20)) {
    case 1: break;
    case 2:
        if (*(f32 *)(v + 0x2C) != 0.0f) {
            *(f32 *)(v + 0x2C) -= 0.018000001087784767f;
            if (*(f32 *)(v + 0x2C) <= 0.0f) *(f32 *)(v + 0x2C) = 0.0f;
        }
        if (func_L07_003D9630((u8 *)self)) func_L01_004450F0(self, 7, -1);
        func_L07_003D9298(self);
        break;
    case 3:
        if (func_L07_003D9630((u8 *)self)) func_L01_004450F0(self, 6, -1);
        break;
    case 4:
        *(f32 *)(v + 0x2C) += 0.018000001087784767f;
        if (*(f32 *)(v + 0x2C) > 1.0f) {
            *(f32 *)(v + 0x2C) = 1.0f;
            if (v[0x3C]) func_L01_004450F0(self, 5, -1);
            else func_L01_004450F0(self, 3, -1);
        }
        func_L07_003D9298(self);
        break;
    case 5:
        *(f32 *)(v + 0x28) += 0.012f;
        if (*(f32 *)(v + 0x28) > 1.0f) {
            *(f32 *)(v + 0x28) = 1.0f;
            func_L01_004450F0(self, 2, -1);
        }
        func_L07_003D9330(self);
        break;
    case 6:
        *(f32 *)(v + 0x2C) -= 0.018000001087784767f;
        if (*(f32 *)(v + 0x2C) <= 0.0f) {
            *(f32 *)(v + 0x2C) = 0.0f;
            func_L01_004450F0(self, 1, -1);
        }
        func_L07_003D9298(self);
        break;
    case 7:
        if (*(f32 *)(v + 0x2C) != 0.0f) {
            *(f32 *)(v + 0x2C) -= 0.018000001087784767f;
            if (*(f32 *)(v + 0x2C) <= 0.0f) *(f32 *)(v + 0x2C) = 0.0f;
            func_L07_003D9298(self);
        }
        *(f32 *)(v + 0x28) += 0.012f;
        if (*(f32 *)(v + 0x28) >= 2.0f && *(f32 *)(v + 0x2C) <= 0.0f) {
            *(f32 *)(v + 0x28) = 0.0f;
            func_L01_004450F0(self, 1, -1);
        }
        func_L07_003D9330(self);
        break;
    }
}
/* localdecomp:end func_L07_003D8E28 */

/* localdecomp:start func_L07_003D90A8 */
typedef int Quad_3D90A8 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern void func_L07_003D9218(s32);
extern void func_L07_003D9260(s32);

void func_L07_003D90A8(s32 arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *vars;
    u8 *out;
    u8 **slot;
    u8 *row;
    s32 i;
    if (obj[0x20] == 0) {
        vars = *(u8 **)(obj + 0x68);
        row = (u8 *)D_L07_001DF41C + (*(s32 *)(vars + 0x30) << 8);
        *(Quad_3D90A8 *)(row + 0x10) = *(Quad_3D90A8 *)(obj + 0x10);
        *(Quad_3D90A8 *)(row + 0xF0) = *(Quad_3D90A8 *)(obj + 0xF0);
        row[0x30] = obj[0x30];
        *(u16 *)(row + 0x32) = *(u16 *)(obj + 0x32);
        slot = (u8 **)(vars + 0x34);
        i = 0;
        do {
            out = func_003C24B0(0x1CA1, 0x80);
            if (out != 0) {
                out[0x31] = 1;
                *(u16 *)(out + 0x32) = *(u16 *)(obj + 0x32);
                out[0x30] = obj[0x30];
                *(unsigned long *)(out + 0x38) = *(unsigned long *)(obj + 0x38);
                if (i != 0) {
                    *(u16 *)(out + 0x34) |= 0x8000;
                }
                *(Quad_3D90A8 *)(out + 0x10) = *(Quad_3D90A8 *)(obj + 0x10);
                *(f32 *)(out + 0x14) -= 7.07f;
                *(f32 *)(out + 0xF8) = (f32)i * 3.1415927f;
                func_003C7C38(out);
            }
            slot[i] = out;
            i++;
        } while (i < 2);
        *(void (**)(s32))(vars + 4) = func_L07_003D9218;
        *(void (**)(s32))(vars + 8) = func_L07_003D9260;
        func_L07_003D9218(arg0);
    }
}
/* localdecomp:end func_L07_003D90A8 */

/* localdecomp:start func_L07_003D9218 */
extern void func_L01_004450F0(s32 a0, s32 a1, s32 a2);
extern void func_L07_003D9298(s32 a0);
extern void func_L07_003D9330(s32 a0);

void func_L07_003D9218(s32 a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    p[11] = 0;
    p[10] = 0;
    func_L07_003D9298(a0);
    func_L07_003D9330(a0);
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L07_003D9218 */

/* localdecomp:start func_L07_003D9260 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003D93F0();

void func_L07_003D9260(s32 arg0) {
    func_L07_003D93F0();
    func_L01_004450F0(arg0, 4, -1);
}
/* localdecomp:end func_L07_003D9260 */

/* localdecomp:start func_L07_003D9298 */
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);

void func_L07_003D9298(s32 a0) {
    s32 *e = *(s32 **)(a0 + 0x68);
    s32 *p = (s32 *)((u8 *)e + 0x34);
    f32 d = func_003C3BE8(0.0f, 8.0f, *(f32 *)((u8 *)e + 0x2C));
    s32 i = 0;

    do {
        f32 f = *(f32 *)((u8 *)a0 + 0x10);
        s32 *v = (s32 *)*p;
        if (i == 0) {
            f = f - d;
        } else {
            f = f + d;
        }
        *(f32 *)((u8 *)v + 0x10) = f;
        i++;
        func_003C7C38((void *)*p);
        p++;
    } while (i < 2);
}
/* localdecomp:end func_L07_003D9298 */

/* localdecomp:start func_L07_003D9330 */
extern f32 func_003C3BE8(f32, f32, f32);


void func_L07_003D9330(s32 a0) {
    u8 *e = *(u8 **)(a0 + 0x68);
    f32 t = *(f32 *)(e + 0x28);
    f32 one;
    f32 rest;
    S_3D9330 *g;
    s32 idx;

    if (1.0f < t) {
        one = 1.0f;
        rest = t - 1.0f;
    } else {
        one = t;
        rest = 0.0f;
    }
    idx = *(s32 *)(e + 0x30);
    g = &D_L07_001DF41C[idx];
    g->f14 = *(f32 *)(a0 + 0x14) - func_003C3BE8(0.0f, 15.01f, one);
    g->f18 = *(f32 *)(a0 + 0x18) - func_003C3BE8(0.0f, 3.0f, rest);
}
/* localdecomp:end func_L07_003D9330 */

/* localdecomp:start func_L07_003D93F0 */
extern u8 D_00142764[];
extern u8 D_00142763[];
extern void func_L07_003A2380(s32, s32, s32, s32);
extern u8 *func_L07_00333CF8(void *, s32);
extern void func_L07_003D9548(void *, void *, s32, s32, f32);

void func_L07_003D93F0(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 i;
    s32 j;
    u8 *p;

    for (i = 1; i >= 0; i--) {
        *(s32 *)(sub + 0x20 + i * 4) = 0;
    }
    if (sub[0x13] != 0) {
        if (D_00142764[0] == 0) {
            func_L07_003A2380(0x1C, *(s32 *)sub, 0, 0x64);
        }
        sub[0x3C] = 1;
        func_L07_003D9548(obj, func_L07_00333CF8(*(void **)sub, 0), sub[0x3C], 0, 0.0f);
    } else if (*(u16 *)(sub + 0x14) != 0) {
        if (D_00142763[0] == 0) {
            func_L07_003A2380(0x1B, *(s32 *)sub, 0, 0x64);
        }
        sub[0x3C] = 1;
        func_L07_003D9548(obj, func_L07_00333CF8(*(void **)sub, 1), sub[0x3C], 0, 1.0f);
        func_L07_003D9548(obj, func_L07_00333CF8(*(void **)sub, 2), sub[0x3C], 1, -1.0f);
    }
    p = sub + 0x15;
    for (j = 2; j >= 0; j--) {
        *p = 0;
        p--;
    }
}
/* localdecomp:end func_L07_003D93F0 */

/* localdecomp:start func_L07_003D9548 */
typedef unsigned int Q_003D9548 __attribute__((mode(TI)));
typedef struct { u8 pad[0x20]; void *objects[2]; } State_003D9548;
void func_L07_003D9548(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 offset) {
    extern u8 *func_L07_00333918(void *);
    extern void func_L07_00333D40(void *, void *);
    extern void func_L07_00333C70(void *, void *);
    u8 *obj = arg0;
    u8 *other = arg1;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 index = arg3;
    u8 *data = func_L07_00333918(other);
    *(s16 *)(data + 0xE) = 0x3E;
    if (state[0x3C]) *(s16 *)(data + 0xE) = 0x91;
    data[0x1E] = 0;
    *(Q_003D9548 *)(other + 0x10) = *(Q_003D9548 *)(obj + 0x10);
    *(f32 *)(other + 0x18) += 1.5f;
    if (offset != 0.0f) *(f32 *)(other + 0x10) += offset * 3.0f;
    func_L07_00333D40(*(void **)(data + 4), other);
    *(f32 *)(other + 0xF8) = *(f32 *)(obj + 0xF8);
    func_L07_00333C70(*(void **)state, other);
    ((State_003D9548 *)state)->objects[index] = other;
}
/* localdecomp:end func_L07_003D9548 */

/* localdecomp:start func_L07_003D9630 */
extern s32 func_L07_00333AB8(void *);
extern f32 func_L01_0040E570(void *, void *);

s32 func_L07_003D9630(u8 *arg0) {
    s32 *p;
    u8 *a;
    s32 i = 0;

    a = *(u8 **)(arg0 + 0x68);
    p = (s32 *)(a + 0x20);
    do {
        if (*p != 0) {
            if (func_L07_00333AB8((void *)*p) == 0) {
                if (484.0f < func_L01_0040E570((u8 *)*p + 0x10, *(u8 **)a + 0x10)) {
                    return 0;
                }
            }
            *p = 0;
        }
        i++;
        p++;
    } while (i < 2);
    return 1;
}
/* localdecomp:end func_L07_003D9630 */
