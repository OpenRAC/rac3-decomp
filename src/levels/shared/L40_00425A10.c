#include "common.h"

/* localdecomp:start func_L40_00425A10 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00425A10;
typedef struct { u8 r, g, b; } C3_00425A10;
typedef struct {
    u8 p0[0x230]; s32 f230;
    u8 p234[0x23C - 0x234]; s32 f23C;
    u8 p240[0x2A0 - 0x240]; s32 f2A0;
} V_00425A10;
typedef struct {
    u8 p0[0x10]; V4_00425A10 pos;
    u8 p20[0x68 - 0x20]; V_00425A10 *vars;
    u8 p6C[0xBE - 0x6C]; u8 bBE;
    u8 pBF[0xC0 - 0xBF]; u8 fC0[0x10];
} M_00425A10;

extern f32 D_L40_0024775C;
extern f32 D_L40_00247760;
extern f32 D_L40_00247768;
extern f32 D_L40_0024776C;
extern f32 D_L40_00247770;
extern s32 D_L40_00247774;
extern s32 D_L40_00247778;
extern s32 D_L40_00247754;
extern s32 D_L40_00247758;
extern s32 D_L40_00247764;
extern C3_00425A10 D_L40_00247780[];
extern void func_0038CC88(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9740(void *, s32, f32, s32, s32, s32);

void func_L40_00425A10(M_00425A10 *m) {
    V4_00425A10 mtx[4];
    C3_00425A10 c1;
    C3_00425A10 c2;
    V_00425A10 *v;
    f32 t;

    t = D_L40_0024775C + D_L40_00247760;
    v = m->vars;
    D_L40_0024775C = t;
    if (t >= 7.0f) {
        D_L40_0024775C = t - 7.0f;
    }
    func_0038CC88(mtx, m->fC0, 0x30);
    mtx[3] = m->pos;
    func_0038CE20(&mtx[0], &mtx[0], D_L40_00247770);
    func_0038CE20(&mtx[1], &mtx[1], D_L40_0024776C);
    func_0038CE20(&mtx[2], &mtx[2], D_L40_00247768);
    if (v->f230 == 0 || v->f2A0 != 0) {
        if (v->f23C < D_L40_00247774) {
            v->f23C = v->f23C + D_L40_00247778;
        }
    } else {
        if (v->f23C > 0) {
            v->f23C = v->f23C - D_L40_00247778;
        }
    }
    if (v->f23C > D_L40_00247774) {
        v->f23C = D_L40_00247774;
    }
    if (v->f23C < 0) {
        v->f23C = 0;
    }
    c1 = D_L40_00247780[0];
    c2 = D_L40_00247780[0];
    if (m->bBE & 8) {
        c1.r = 0xFF;
        c1.b = 0x80;
        c2.r = 0xFF;
        c2.b = 0x80;
    }
    func_003D9740(mtx, D_L40_00247754, D_L40_0024775C, (v->f23C << 24) | (c1.b << 16) | (c1.g << 8) | c1.r, D_L40_00247764, 1);
    func_003D9740(mtx, D_L40_00247758, D_L40_0024775C, (v->f23C << 24) | (c2.b << 16) | (c2.g << 8) | c2.r, D_L40_00247764, 1);
}
/* localdecomp:end func_L40_00425A10 */
