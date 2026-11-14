#include "common.h"

/* localdecomp:start func_L34_00350A90 */
typedef struct { s32 a; s32 b; } E_00350A90;
typedef struct { E_00350A90 e[14]; s32 f70; s32 t74; s32 c78; s32 i7C; f32 f80; s32 m84; } V_00350A90;
extern u8 D_001A4BE0[];
extern void func_L34_00350D80(u8 *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L34_003515A0(s32, s32);

void func_L34_00350A90(u8 *o) {
    V_00350A90 *v = *(V_00350A90 **)(o + 0x68);
    f32 d;
    s32 in;
    u8 *r;
    s32 t;
    u8 *h;

    func_L34_00350D80(o);
    d = func_0038CF38(o + 0x10, D_001A4BE0 + 0x80);
    h = D_001A4BE0;
    in = 0;
    if (*(f32 *)(h + 0x88) > 83.0f && *(f32 *)(h + 0x88) < 100.0f &&
        *(f32 *)(h + 0x80) > 108.0f && *(f32 *)(h + 0x80) < 120.0f) {
        in = 1;
    }
    switch (o[0x20]) {
    case 0:
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        if (in) {
            break;
        }
        func_003A52A0(0, 0, o);
        v->c78 = v->e[0].a;
        if (o[0x43] != 1) {
            func_003C3A10(o, 1, 0, 6);
        }
        func_L01_004450F0(o, 2, -1);
        break;
    case 2:
        if (func_0038CAD0(&v->t74)) {
            r = (u8 *)func_L34_003515A0((s32)o, 0);
            if (r != 0) {
                r = *(u8 **)(r + 0x68);
                *(f32 *)(r + 0xC) = v->f80;
                if (v->m84 != 0) {
                    *(s32 *)r = v->m84;
                }
            }
            t = v->c78 - 1;
            v->c78 = t;
            if (t < 0) {
                v->c78 = 0;
            }
            v->t74 = 0xC;
        }
        if (v->c78 == 0) {
            v->t74 = v->e[v->i7C].b;
            v->i7C += 1;
            if (v->e[v->i7C].a == 0) {
                v->i7C = 0;
            }
            v->c78 = v->e[v->i7C].a;
            func_L01_004450F0(o, 3, -1);
        }
        break;
    case 3:
        if (in) {
            func_L01_004450F0(o, 1, -1);
        }
        if (*(u16 *)(o + 0x96) >= 0x1A && o[0x43] != 0) {
            func_003A52A0(1, 0, o);
            if (o[0x43] != 0) {
                func_003C3A10(o, 0, 0, 6);
            }
        }
        if (func_0038CAD0(&v->t74) && d > 5.0f) {
            func_003A52A0(0, 0, o);
            if (o[0x43] != 1) {
                func_003C3A10(o, 1, 0, 6);
            }
            func_L01_004450F0(o, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L34_00350A90 */

/* localdecomp:start func_L34_00350D80 */
extern u8 D_L34_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L34_00350D80(u8 *o) {
    u8 *r;
    u8 *p;
    s16 t;
    if (*(u16 *)(o + 0x96) < 0xFFFF) {
        *(u16 *)(o + 0x96) += 1;
    }
    r = (u8 *)func_L01_00447490(o, 0x10000, 0);
    if (r == 0) {
        return;
    }
    o[0xA8] = 0xFF;
    p = *(u8 **)(r + 0x20);
    if (p == 0) {
        return;
    }
    t = *(s16 *)(p + 0xAA);
    if (t != 0x15C6 && t != 0x1363 && t != 0x1EF9) {
        return;
    }
    func_003A52A0(2, 0, o);
    func_L01_003303B8(o + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.57f, 0.0f, 0.0f, 2.0f, 1, 1, 1, 0, 1, 0,
                      0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                      0x280000FF, 0x3064FF, 0);
    func_L01_00451FE0(o, 0xF, &D_L34_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0xFF, 0xB4, 0, 0, 0x23, 0, 3);
    func_003C2880(o);
}
/* localdecomp:end func_L34_00350D80 */
