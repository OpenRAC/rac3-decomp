#include "common.h"

/* localdecomp:start func_L39_00619D20 */
typedef struct S_00619D20 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ f32 x;
    /* 0x14 */ f32 y;
    /* 0x18 */ f32 w0;
    /* 0x1C */ f32 h0;
    /* 0x20 */ f32 ox;
    /* 0x24 */ f32 oy;
    /* 0x28 */ u8 pad28[0x14];
    /* 0x3C */ s32 flag3C;
    /* 0x40 */ u8 pad40[8];
    /* 0x48 */ f32 f48;
    /* 0x4C */ f32 f4C;
    /* 0x50 */ u8 pad50[8];
    /* 0x58 */ s32 mode;
    /* 0x5C */ f32 w;
    /* 0x60 */ f32 h;
} S_00619D20;

typedef struct R_00619D20 {
    f32 v[4];
} R_00619D20;

extern f32 D_L39_00245C38;
extern f32 D_L39_00245C50;
__asm__(".extern D_L39_00245C38, 16");
__asm__(".extern D_L39_00245C50, 16");
extern f32 D_001DA528_sda;
extern void func_0038E150(s32);
extern s32 func_L01_00447470_00619D20(s32, s32, f32);
extern f32 func_00390BF8(s32, s32, s32, f32);
extern void func_003EDB40(S_00619D20 *, s32 *, s32 *);
extern s32 func_003EFFD0(S_00619D20 *, s32);
extern s32 func_003EDAF8(S_00619D20 *, s32);
extern void func_003E72A0(f32 *, f32 *);
extern void func_0011D534(void *, s32, s32);

void func_L39_00619D20(S_00619D20 *p, f32 *c, f32 *out, s32 flag) {
    R_00619D20 tmp;
    f32 a;
    f32 b;
    f32 e;
    f32 g;
    f32 t;
    f32 dx, dy;
    s32 sx, sy;
    f32 v0, v1;
    f32 ratio;

    switch (p->mode) {
    case 1:
        func_0038E150(1);
        break;
    case 2:
        func_0038E150(0);
        break;
    case 0:
    default:
        func_0038E150(0);
        break;
    }
    if (p->flag3C != 0) {
        ratio = (f32)func_L01_00447470_00619D20(p->flag3C, -1, 1.0f) / D_L39_00245C38;
    } else {
        ratio = 0.0f;
    }
    b = a = 2.0f;
    g = e = 0.0f;
    if (flag != 0) {
        sx = 0;
        sy = 0;
        func_003EDB40(p, &sx, &sy);
        if (sx != 3) {
            if (sx == 1) {
                g = 1.0f;
            } else {
                b = -2.0f;
                g = 1.0f;
            }
        }
        if (sy != 3) {
            if (sy == 2) {
                a = -2.0f;
                e = 1.0f;
            } else {
                a = 2.0f;
                e = 1.0f;
            }
        }
    }
    p->w = p->w0;
    p->h = p->h0;
    if (func_003EFFD0(p, 1) != 0) {
        if (p->flag3C != 0) {
            t = func_00390BF8(p->flag3C, -1, (s32)(p->f48 * D_001DA528_sda), p->f4C);
        } else {
            t = 0.0f;
        }
        p->w *= t;
        p->h *= t;
    }
    if (func_003EDAF8(p, 0x2000) != 0) {
        v0 = 0.0f;
        v1 = 0.0f;
        func_003E72A0(&v0, &v1);
        p->w *= v0;
        p->h *= v1;
    }
    dx = p->w * ratio / b;
    dy = p->h * D_L39_00245C50 / a;
    out[0] = p->x - dx + dx * g;
    out[1] = p->y - dy + dy * e;
    out[2] = p->x + dx + dx * g;
    out[3] = p->y + dy + dy * e;
    if (c[0] == 0.0f && c[2] == 1.0f && c[1] == 0.0f && c[3] == 1.0f) {
        return;
    }
    {
        f32 x0 = out[0];
        f32 y0 = out[1];
        out[0] = (c[2] - c[0]) * x0 + c[0];
        out[1] = (c[3] - c[1]) * y0 + c[1];
        out[2] += out[0] - x0;
        out[3] += out[1] - y0;
    }
    if (func_003EDAF8(p, 0x40) != 0) {
        f32 ox = p->ox;
        f32 oy = p->oy;
        func_0011D534(&tmp, 0, 16);
        tmp = *(R_00619D20 *)out;
        tmp.v[0] += ox;
        tmp.v[2] += ox;
        tmp.v[1] += oy;
        tmp.v[3] += oy;
        out[0] = tmp.v[0] < out[0] ? tmp.v[0] : out[0];
        out[2] = out[2] < tmp.v[2] ? tmp.v[2] : out[2];
        out[3] = out[3] < tmp.v[3] ? tmp.v[3] : out[3];
        out[1] = tmp.v[1] < out[1] ? tmp.v[1] : out[1];
    }
}
/* localdecomp:end func_L39_00619D20 */
