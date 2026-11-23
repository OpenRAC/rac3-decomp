#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003ADF68 */
extern u8 D_L07_001D66B0[8];

extern void func_L07_003AE410(u8 *);
extern void func_L07_003AE618(u8 *);
extern s32 func_0038CB00(u8 *);
extern void func_L07_003AEAA0(s32, s32);
extern void func_L07_003AF010(u8 *, void *, void *);
extern void func_L07_003AEF58();
extern void func_L07_003AEF78(u8 *, void *);
extern void func_L07_003AF0B0(u8 *, void *, f32);
extern void func_L07_003AF2B8(u8 *, s32, f32);
extern s32 func_L07_003AED20(u8 *);
extern void func_L07_003AED80(u8 *);
extern s32 func_L07_00331008(u8 *, u8 *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L03_0032FAF0(void *, void *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L07_003315B0(void *);
extern s32 func_003A52A0(s32, s32, void *);

void func_L07_003ADF68(u8 *obj) {
    u8 *s;
    vu0_v4 tmp;
    vu0_v4 *q;

    if (obj[0x20] == 0) {
        func_L07_003AE410(obj);
    }
    func_L07_003AE618(obj);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        if (func_0038CB00(s + 0x24E) != 0) {
            func_L07_003AEAA0((s32)obj, 3);
        }
        break;
    case 3:
        func_L07_003AEAA0((s32)obj, 4);
        /* fall through */
    case 4:
        func_L07_003AF010(obj, s + 0x260, func_L07_003AEF58);
        if (func_L01_0040E570(obj + 0x10, *(u8 **)(s + 0x240) + 0x10) < 484.0f) {
            s[0x25E] = 1;
            func_L07_003AEAA0((s32)obj, 6);
        }
        break;
    case 6:
        func_L07_003AED80(obj);
        if (func_L07_00331008(*(u8 **)(s + 0x240), obj) != 0) {
            func_L07_003AEAA0((s32)obj, 7);
        }
        break;
    case 7:
        if (func_L07_003AED20(obj) != 0) {
            func_L03_0032FAF0(&tmp, s + 0x220, *(f32 *)(s + 0x254), 2.5f);
            func_L07_003AF010(obj, &tmp, func_L07_003AEF78);
            if (func_L01_0040E570(obj + 0x10, s + 0x220) < 9.0f) {
                func_L07_003AEAA0((s32)obj, 8);
            }
        }
        break;
    case 8:
        func_L07_003AF010(obj, obj + 0x10, func_L07_003AEF58);
        if (func_L07_003AED20(obj) != 0) {
            if (obj[0x60] & 2) {
                func_L07_003AEAA0((s32)obj, 9);
            }
        }
        break;
    case 9:
        func_L07_003AF010(obj, obj + 0x10, func_L07_003AEF58);
        *(f32 *)(obj + 0x48) = 1.0f - (f32) * (s16 *)(s + 0x284) / 42.0f;
        if (func_L07_003AED20(obj) != 0) {
            if (func_0038CB00(s + 0x284) != 0) {
                func_L07_003AEAA0((s32)obj, 10);
            }
        }
        break;
    case 10:
        if (func_L07_003AED20(obj) != 0) {
            func_L07_003AEF78(obj, s + 0x220);
            func_L07_003AF0B0(obj, D_L07_001D66B0, 0.0f);
            func_L07_003AF2B8(obj, 0, 0.0f);
            if (func_L01_0040E570(obj + 0x10, s + 0x220) > 225.0f) {
                func_L07_003AEAA0((s32)obj, 7);
            }
        }
        break;
    case 14: {
        u8 *position = obj + 0x10;
        *(f32 *)(obj + 0xF8) = func_0038DAB8(*(f32 *)(obj + 0xF8), 0.50265485f);
        q = &tmp;
        vec_add_ba(obj + 0x10, obj + 0x10, s + 0xD0);
        tmp = *(vu0_v4 *)(obj + 0x10);
        tmp.z = tmp.z + 0.8f;
        if (func_0038CB00(s + 0x284) != 0 || func_L01_003FB640(q, 0, obj, 0.9f) != 0) {
            func_L01_003303B8(position, 0, 5, 0xA, 0xA, 3, 0x14, 0, 0.3f, 0.0f, (f32)s[0x135], 1.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00451FE0(obj, 0x1F, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23,
                              1.0f, 1.0f, 0, 3);
            func_L07_003315B0(obj);
            func_003A52A0(2, 0, obj);
        }
        break;
    }
    }
}
/* localdecomp:end func_L07_003ADF68 */

/* localdecomp:start func_L07_003AE410 */
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    f32 f34;
    u8 pad38[8];
    f32 f40;
    u8 pad44[0x18];
    f32 f5c;
    f32 f60;
    u8 pad64[0xB8];
    s32 f11c;
    f32 hp;
    s16 life;
    u8 pad126[14];
    u8 d0;
    u8 d1;
    u8 d2;
    u8 pad137[0x39];
    u8 b170;
    u8 b171;
    u8 b172;
    u8 pad173[0x35];
    u8 b1a8;
    u8 pad1a9[0x9B];
    void (*cb244)(int *);
    void (*cb248)(s32);
    s16 h24c;
    u8 pad24e[15];
    u8 b25d;
    u8 pad25e[1];
    u8 b25f;
} Vars_003AE410;

extern s32 func_L07_003C1AF8(u8 *);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
void func_L07_003AECD8(int *);
void func_L07_003AECA8(s32);

void func_L07_003AE410(u8 *m) {
    Vars_003AE410 *v = *(Vars_003AE410 **)(m + 0x68);
    s32 kind = func_L07_003C1AF8(m);
    u8 *q = (u8 *)v + 0x120;
    f32 scale = func_L07_003C1B40(kind);

    *(s16 *)(q + 4) = v->life * scale;
    v->hp = *(s16 *)(q + 4);
    q[0x14] = v->d0 * scale;
    q[0x15] = v->d1 * scale;
    q[0x16] = v->d2 * scale;
    if (kind == 1 || kind == 3) {
        func_L01_00446058(m, 0x1D88, 0x19D2);
    }
    q[0x28] = 20;
    *(f32 *)(q + 0x10) = 0.25f;
    q[9] = 0;
    q[0x2A] = 14;
    v->f11c = 0;
    v->b170 = 5;
    v->b1a8 = 255;
    v->b171 = 255;
    v->b172 = 255;
    v->f30 = 0.8f;
    v->f34 = -0.3f;
    v->f40 = 3.1415927f;
    v->f60 = 0.7853982f;
    v->f5c = 0.00392f;
    func_L01_0045BD78(m, 0.0048f, 0.24000001f, 0.0025132743f, 0.12566371f);
    v->cb244 = func_L07_003AECD8;
    v->cb248 = func_L07_003AECA8;
    v->b25d = 6;
    v->h24c = -1;
    v->b25f = 7;
    func_L07_003AECA8((s32)m);
}
/* localdecomp:end func_L07_003AE410 */

/* localdecomp:start func_L07_003AE618 */
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0[];
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L07_003333F8(s32, f32, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003315B0(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L07_00331158(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
void func_L07_003AEAA0(s32, s32);

void func_L07_003AE618(u8 *obj) {
    u8 *p;
    u8 *t;
    f32 f;
    f32 g;
    f32 yaw;
    f32 lim;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1 || obj[0x20] == 0xE) {
        return;
    }
    f = *(f32 *)(p + 0x120);
    t = (u8 *)func_L01_00447490(obj, 0x10000, 0);
    if (func_L01_00452FB0(obj, p + 0x160, 0, 0, 0) != 0) {
        func_L07_003333F8(*(s32 *)(p + 0x240), f, *(f32 *)(p + 0x120));
    }
    if (*(s32 *)(p + 0x108) == 1) {
        func_L01_00451FE0(obj, 0x1F, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_003303B8(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L07_003315B0(obj);
    } else {
        if (*(f32 *)(p + 0x120) <= 0.0f) {
            if (t != 0 && 0.0f < func_0038CE68(t + 0x10, t + 0x10)) {
                g = -func_0038D160(func_0038CED8(t + 0x10), *(f32 *)(t + 0x18));
                lim = 0.34906584f;
                if (lim < g) {
                    g = lim;
                } else if (g < 0.0f) {
                    g = 0.0f;
                }
                yaw = func_0038D160(*(f32 *)(t + 0x10), *(f32 *)(t + 0x14));
                func_00382760(p + 0xD0, 1.2f, yaw, g);
                func_L07_003AEAA0((s32)obj, 0xE);
                return;
            }
            func_L01_003303B8(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_004AAC98(2, 0, obj, 0x19D2);
            func_L07_003315B0(obj);
            return;
        }
        if (p[0x14E] != 0 || p[0x150] != 0 || p[0x12E] == 2) {
            func_L07_003315B0(obj);
            return;
        }
    }
    func_L07_00331158(obj);
    if ((u8)(obj[0x20] - 8) < 3) {
        if (*(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f < *(f32 *)(obj + 0x18)) {
            *(f32 *)(p + 0x280) = *(f32 *)(p + 0x280) + 0.00392f;
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) - *(f32 *)(p + 0x280);
            if (*(f32 *)(obj + 0x18) < *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f) {
                *(f32 *)(obj + 0x18) = *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f;
            }
        } else {
            *(s32 *)(p + 0x280) = 0;
        }
    } else {
        *(s32 *)(p + 0x280) = 0;
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L07_001E1EC0, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L07_003AE618 */

/* localdecomp:start func_L07_003AEAA0 */
typedef int Quad_003AEAA0 __attribute__((mode(TI)));
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L07_003AF240(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L07_003AEAA0(s32 arg0, s32 state) {
    u8 *obj = (u8 *)arg0;
    u8 *p = *(u8 **)(obj + 0x68);

    switch (state) {
    case 1:
        break;
    case 2:
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 0);
        }
        break;
    case 3:
        break;
    case 4:
        *(s32 *)(p + 0x68) |= 0x404;
        *(f32 *)(p + 0x50) = 0.0048f;
        *(f32 *)(p + 0x54) = 0.0048f;
        *(f32 *)(p + 0x58) = 0.24000001f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        *(Quad_003AEAA0 *)(p + 0x260) = *(Quad_003AEAA0 *)(*(u8 **)(p + 0x240) + 0x10);
        *(f32 *)(p + 0x268) = *(f32 *)(obj + 0x18);
        break;
    case 5:
        break;
    case 6:
        *(s32 *)(p + 0x68) |= 0x414;
        *(f32 *)(p + 0x50) = 0.0048f;
        *(f32 *)(p + 0x54) = 0.0048f;
        *(f32 *)(p + 0x58) = 0.24000001f;
        func_L07_003AF240(obj);
        break;
    case 7:
        *(s32 *)(p + 0x68) = (*(s32 *)(p + 0x68) | 0x404) & ~0x10;
        *(f32 *)(p + 0x50) = 0.024f;
        *(f32 *)(p + 0x58) = 0.6f;
        *(f32 *)(p + 0x54) = 0.024f;
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 2);
        }
        break;
    case 8:
        if (obj[0x43] != 1) {
            func_003C3A10(obj, 1, 0, 2);
        }
        break;
    case 9:
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 2);
        }
        *(s16 *)(p + 0x284) = 42;
        break;
    case 10:
        *(f32 *)(p + 0x50) = 0.0016000001f;
        *(f32 *)(p + 0x58) = 0.060000002f;
        *(f32 *)(p + 0x54) = 0.0016000001f;
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 2);
        }
        break;
    case 11:
    case 12:
    case 13:
        break;
    case 14:
        *(s16 *)(p + 0x284) = 25;
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003AEAA0 */
