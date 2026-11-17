#include "common.h"

/* localdecomp:start func_L39_00617CB8 */
typedef struct { f32 v[4]; } V4_00617CB8;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; } O_00617CB8;
extern void func_003EDB40(void *, s32 *, s32 *);
extern s32 func_003EDAF8(void *, s32);
extern void func_0011D534(void *, s32, s32);
void func_L39_00617CB8(O_00617CB8 *o, f32 *p, V4_00617CB8 *out, s32 flag) {
    V4_00617CB8 box;
    s32 w0, w1;
    f32 sx, sy, dx, dy;
    f32 ax, ay, x, y;
    sx = sy = 2.0f;
    dx = dy = 0.0f;
    if (flag != 0) {
        w0 = 0;
        w1 = 0;
        func_003EDB40(o, &w0, &w1);
        if (w0 != 3) {
            if (w0 == 1) {
                dx = 1.0f;
            } else {
                sx = sy;
                dx = -1.0f;
            }
        }
        if (w1 != 3) {
            if (w1 == 2) {
                sy = 2.0f;
                dy = -1.0f;
            } else {
                sy = 2.0f;
                dy = 1.0f;
            }
        }
    }
    ax = o->f10;
    ax = (p[2] - p[0]) * ax + p[0];
    ay = o->f14;
    ay = (p[3] - p[1]) * ay + p[1];
    x = ax - o->f18 * ((dx + 1.0f) / sx);
    out->v[0] = x;
    y = (ay - o->f1C / sy) + dy * o->f1C / sy;
    out->v[1] = y;
    out->v[2] = x + o->f18;
    out->v[3] = y + o->f1C;
    if (func_003EDAF8(o, 0x40)) {
        f32 ox = o->f20;
        f32 oy = o->f24;
        func_0011D534(&box, 0, 0x10);
        box = *out;
        box.v[0] += ox;
        box.v[2] += ox;
        box.v[1] += oy;
        box.v[3] += oy;
        out->v[0] = box.v[0] < out->v[0] ? box.v[0] : out->v[0];
        out->v[2] = out->v[2] < box.v[2] ? box.v[2] : out->v[2];
        out->v[3] = out->v[3] < box.v[3] ? box.v[3] : out->v[3];
        out->v[1] = box.v[1] < out->v[1] ? box.v[1] : out->v[1];
    }
}
/* localdecomp:end func_L39_00617CB8 */
