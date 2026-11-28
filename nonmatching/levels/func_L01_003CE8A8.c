/* func_L01_003CE8A8 (Claude wave 14 r54, 2026-11-28). First draft kept here. */
/* PAL near miss (r54, wave 14): first draft of a fresh entry (the native port's functional C as a guide), 309 diff under
 * the file's line with the divs row 'func_L01_003CE8A8 2' injected (retail pads its div.s with two nops; not in
 * config/levels/divs_nops.txt). The render callback of func_L01_003CE3D0 (func_L01_00404A10): flicker colours, phase
 * wrap, distance fade, then the quad strips through func_003D3A24 (2 passes for the base quad, 2 per row of the
 * D_L01_002BB550 table), with the vu0.h vec_add_ba/vec_copy/vec_add_ab sequences retail has. Still differs: retail's frame
 * is 0xF0 (ours 0xC0): its spills of self/vars sit at 0x20/0x24 between the vectors (v 0x0, t 0x10, w 0x30, w2 0x50
 * in retail), which shifts every stack offset; and retail strength-reduces every table address of the first loop into its
 * own pointer (s1/s2/s7/fp, 0x78/0x7C spills, s3-s5 for the three position arrays) with the counter reversed
 * (bgez), where ours shares i*8 and recomputes i*12 (loop.c: 'giv not worth while'); the j loop uses a pointer
 * compare. Explicit pointer increments for the first loop give the same count. */
#include "common.h"

/* localdecomp:start func_L01_003CE8A8 */
typedef struct {
    u8 pad0[0x10];
    f32 phase;      /* 0x10 */
    u8 pad14[0xC];
    f32 f20;        /* 0x20 */
    f32 f24;        /* 0x24 */
    s32 color0;     /* 0x28 */
    s32 color1;     /* 0x2C */
} V_003CE8A8;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;     /* 0x10 */
    u8 pad20[0x48];
    V_003CE8A8 *vars; /* 0x68 */
    u8 pad6C[0x54];
    vu0_v4 rot[3];  /* 0xC0 */
} M_003CE8A8;

extern V4_3C41F0 D_L01_001E29C0;
extern s32 D_L01_001DBCA0;
extern s32 D_L01_001DF250;
__asm__(".extern D_L01_001DF250, 4");
extern s32 D_L01_001DF254;
__asm__(".extern D_L01_001DF254, 4");
extern f32 D_L01_001DF20C;
__asm__(".extern D_L01_001DF20C, 4");
extern f32 D_L01_001DF1FC;
__asm__(".extern D_L01_001DF1FC, 4");
extern f32 D_L01_001DF200;
__asm__(".extern D_L01_001DF200, 4");
extern f32 D_L01_001DF210[2];
__asm__(".extern D_L01_001DF210, 8");
extern f32 D_L01_001DF214[];
extern f32 D_L01_001DF230[2];
__asm__(".extern D_L01_001DF230, 8");
extern f32 D_L01_001DF234[];
extern f32 D_L01_001E22A0[];
extern f32 D_L01_001E22A4[];
extern f32 D_L01_001E22A8[];
extern s32 D_L01_001E22D0[];
extern f32 D_L01_001E22E0[];
extern f32 D_L01_001E22E4[];
extern f32 D_L01_002BB550[];
extern f32 D_L01_002BB558[];

void func_L01_003CE8A8(M_003CE8A8 *self) {
    extern void func_003A9440(s32, unsigned long);
    extern void func_0038C750(void);
    extern f32 func_0038CF00(void *, void *);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    extern unsigned long func_00389598(s32);
    vu0_v4 v;
    vu0_v4 t;
    vu0_v4 w;
    vu0_v4 w2;
    V_003CE8A8 *vars;
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    f32 s;
    f32 dist;
    f32 scale;
    f32 f20;
    f32 f21;

    vars = self->vars;
    a = D_L01_001DF250;
    b = D_L01_001DF254;
    vars->color0 = a;
    vars->color1 = b;
    if ((u32)(a & 0xFF000000) > 0x80000000 || (u32)(b & 0xFF000000) > 0x80000000) {
        D_L01_001DBCA0 |= 1;
    }
    s = vars->phase + D_L01_001DF20C;
    vars->phase = s - (f32)(s32)s;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260);
    func_003A9440(0x47, 0x513F1);
    func_0038C750();
    dist = func_0038CF00(&self->pos, &D_L01_001E29C0);
    if (dist < D_L01_001DF1FC) {
        scale = D_L01_001DF200 + dist / D_L01_001DF1FC * (1.0f - D_L01_001DF200);
    } else {
        scale = 1.0f;
    }
    f20 = vars->f24 * scale;
    f21 = f20 * vars->f20;
    for (i = 0; i < 4; i++) {
        func_0038CE20(&v, &self->rot[0], D_L01_001DF210[i * 2] * f21);
        func_0038CE20(&t, &self->rot[1], D_L01_001DF214[i * 2] * f20);
        vec_add_ba(&v, &t, &v);
        vec_copy(&w, &self->pos);
        D_L01_001E22E0[i * 2] = D_L01_001DF230[i * 2];
        vec_add_ab(&v, &v, &w);
        D_L01_001E22E4[i * 2] = D_L01_001DF234[i * 2];
        D_L01_001E22A0[i * 3] = v.x;
        D_L01_001E22A4[i * 3] = v.y;
        D_L01_001E22A8[i * 3] = v.z;
        D_L01_001E22D0[i] = -1;
    }
    func_003A9440(6, func_00389598(0x3A));
    func_003A9440(0x42, 0x800000006A);
    func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
    for (i = 0; i < 4; i++) {
        D_L01_001E22D0[i] = vars->color0;
        D_L01_001E22E4[i * 2] += vars->phase;
    }
    func_003A9440(0x42, 0x8000000058);
    func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 4; i++) {
            func_0038CE20(&v, &self->rot[0], D_L01_002BB550[j * 12 + i * 3] * f21);
            func_0038CE20(&t, &self->rot[1], D_L01_002BB550[j * 12 + i * 3 + 1] * f20);
            vec_add_ba(&v, &t, &v);
            func_0038CE20(&t, &self->rot[2], D_L01_002BB558[j * 12 + i * 3] * f20);
            vec_add_ba(&v, &t, &v);
            vec_copy(&w2, &self->pos);
            D_L01_001E22E0[i * 2] = D_L01_001DF230[i * 2];
            vec_add_ab(&v, &v, &w2);
            D_L01_001E22E4[i * 2] = D_L01_001DF234[i * 2];
            D_L01_001E22A0[i * 3] = v.x;
            D_L01_001E22A4[i * 3] = v.y;
            D_L01_001E22A8[i * 3] = v.z;
            D_L01_001E22D0[i] = -1;
        }
        func_003A9440(0x42, 0x800000006A);
        func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
        for (i = 0; i < 4; i++) {
            D_L01_001E22D0[i] = vars->color1;
            D_L01_001E22E4[i * 2] += vars->phase;
        }
        func_003A9440(0x42, 0x8000000058);
        func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_003CE8A8 */
