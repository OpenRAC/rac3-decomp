#include "common.h"

/* NTSC-U counterpart of func_L39_00526FC0 (src/levels/shared/L39_00524E00.c): 0.36 -> 0.3; 0.048 -> 0.04; 0.012 -> 0.01 */
#include "vu0.h"
extern f32 func_00388730(void *, void *);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern void func_00388758(void *, void *, void *);
extern void func_L39_00526B18(u8 *);

/* localdecomp:start func_L39_00526B18 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    f32 uv[4][2];
    long a;
    long tex;
    long c;
    long d;
} S_00526FC0;

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2C[0x3C - 0x2C];
    f32 f3C;
    u8 pad40[0x54 - 0x40];
    u8 *p54;
} V_00526FC0;

extern vu0_v4 D_L39_003B5840[];
extern vu0_v4 D_L39_003B5E40[];
extern vu0_v4 D_L39_003B6300[][12][20];
extern void func_L39_00526FB8_00526B18(void *, void *, s32, s32, f32, f32, f32, f32, s32, s32);
extern void func_L39_00527590(u8 *);
extern long func_L39_00588720(s32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388730(void *, void *);
extern void func_003CD830(void *, s32, s32);

static __inline__ void qcopy_00526FC0(vu0_v4 *d, vu0_v4 *s) { *d = *s; }

void func_L39_00526B18(u8 *m) {
    S_00526FC0 s;
    vu0_v4 d0;
    vu0_v4 d1;
    vu0_v4 n;
    vu0_v4 e;
    V_00526FC0 *v;
    u8 *p;
    s32 idx;
    u32 col;
    s32 i, j, k;
    f32 y, u0, u1;

    if (m == 0) return;
    if (*(s16 *)(m + 0xAA) != 0x10A7) return;
    if (m[0x20] == 0xFE) return;
    if (m[0x20] == 0xFD) return;
    v = *(V_00526FC0 **)(m + 0x68);
    if (v == 0) return;
    idx = 0;
    p = v->p54;
    if (p != 0) idx = *(s32 *)(p + 0x2544);

    v->f28 -= 0.300000012f;
    if (v->f28 <= -8.0f) v->f28 += 8.0f;
    func_L39_00526FB8_00526B18(&D_L39_003B5840[idx * 12], p + 0x23A0, 0x80, 0x40, 0.05f, 0.4f, 0.9f, v->f28, 0xC, 0x103FFF);
    col = 0x400000FF;
    func_L39_00526FB8_00526B18(&D_L39_003B5E40[idx * 12], p + 0x23A0, 0x80, 0x40, 0.05f, 0.4f, 0.9f, v->f28, 0xC, 0x10107F);
    func_L39_00527590(m);
    s.tex = func_L39_00588720(0xD);
    s.c = 0xFF9000000260;
    s.d = 0x8000000048;
    s.a = 0;
    s.col[3] = col;
    s.col[2] = col;
    s.col[1] = col;
    s.col[0] = col;

    y = v->f3C;
    v->f3C = y - 0.0399999991f;
    if (v->f3C <= -8.0f) v->f3C += 8.0f;
    v->f20 -= 0.00999999978f;
    if (v->f20 <= -7.0f) v->f20 += 7.0f;
    v->f24 += 0.00999999978f;
    if (v->f24 >= 5.0f) v->f24 -= 5.0f;

    for (i = 2; i < 12; i++) {
        u0 = v->f20;
        u1 = v->f24;
        for (j = 0; j < 20; j++) {
            k = (j + 1) % 20;
            qcopy_00526FC0(&s.pos[0], D_L39_003B6300[idx][i + 1] + j);
            qcopy_00526FC0(&s.pos[1], D_L39_003B6300[idx][i + 1] + k);
            qcopy_00526FC0(&s.pos[2], D_L39_003B6300[idx][i] + j);
            qcopy_00526FC0(&s.pos[3], D_L39_003B6300[idx][i] + k);
            vec_sub_ba(&d0, &s.pos[0], &s.pos[1]);
            vec_sub_ab(&d1, &s.pos[2], &s.pos[1]);
            func_00388758(&n, &d1, &d0);
            vec_sub_ab(&e, &s.pos[1], p + 0x23A0);
            if (func_00388730(&n, &e) >= 0.0f) {
                u0 += 0.05f;
                u1 += 0.05f;
            } else {
                f32 x;
                if (i == 11) {
                    s.col[1] = 0xFF;
                    s.col[0] = 0xFF;
                }
                x = y - 0.066667f;
                s.uv[0][0] = y;
                s.uv[0][1] = u0;
                s.uv[1][0] = y;
                s.uv[1][1] = u0 + 0.05f;
                s.uv[2][0] = x;
                s.uv[2][1] = u0;
                s.uv[3][0] = x;
                s.uv[3][1] = u0 + 0.05f;
                u0 += 0.05f;
                func_003CD830(&s, 0, 0);
                s.uv[0][0] = y;
                s.uv[0][1] = u1;
                s.uv[1][0] = y;
                s.uv[1][1] = u1 + 0.05f;
                s.uv[2][0] = x;
                s.uv[2][1] = u1;
                s.uv[3][0] = x;
                s.uv[3][1] = u1 + 0.05f;
                u1 += 0.05f;
                func_003CD830(&s, 0, 0);
            }
        }
        y += 0.066667f;
    }
}
/* localdecomp:end func_L39_00526B18 */
