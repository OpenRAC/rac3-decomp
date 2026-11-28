/* func_L01_00380CE0 (Claude wave 14 r55, 2026-11-28). Replaces the earlier draft of this function (Codex wave 8 near miss). */
/* func_L01_00380CE0 rewritten from the retail assembly (worker r55, wave 14). The earlier Codex wave 8
 * draft no longer compiled in its file (its definition conflicted with the file's prototype
 * (vu0_v4 *, s32, s32, s32, s32, f32, f32, f32) from func_L01_00380880's block) and used multi-instruction
 * asm blocks with hard-coded vf1/vf2 and memory copies standing in for retail's spill slots. This one uses
 * the include/vu0.h helpers (retail interleaves single lqc2/sqc2/vadd/vsub with the scalar code), the
 * file's prototype and globals, block-scoped length variables (retail keeps them in f0/f1, with 1.0f in
 * f20 and the uv zero in f21), and the uv zero re-read after the first helper's store (retail's lwc1 f21,
 * 0xE0). Retail has 2 2 2 2 1 nops before its five div.s: NEEDS divs row 'func_L01_00380CE0 2 2 2 2 1'.
 * Still differs: register allocation and spills. Retail's frame is 0x2A0 (count and count - 1 spilled at
 * 0x1C0 / 0x210, vf spills at 0x1D0-0x200 and 0x220); this C's is 0x260 and keeps the %hi of D_L01_001E29C0
 * in one callee-saved register for the whole function, where retail rebuilds it before the second
 * func_00389598 call (s0), in every iteration of the first loop (v0) and once before the second (s2). */
#include "common.h"

/* localdecomp:start func_L01_00380CE0 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    f32 uv[4][2];
    long a;
    long tex;
    long c;
    long d;
} S_00380CE0;
__asm__(".extern D_L01_001DDC6C, 4");
__asm__(".extern D_L01_001DDC70, 4");
__asm__(".extern D_L01_001DDC50, 4");
extern s32 D_L01_001DDC6C;
extern s32 D_L01_001DDC70;
extern u32 D_L01_001DDC50;
extern vu0_v4 D_L01_001E29C0_00380CE0;

void func_L01_00380CE0(vu0_v4 *pts, s32 alpha, s32 glow_alpha, s32 count, s32 glow_col, f32 unused, f32 width,
                       f32 inset) {
    extern long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(Q_0037F860 *, Q_0037F860 *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003A9440(s32 reg, long value);
    S_00380CE0 core;
    S_00380CE0 glow;
    vu0_v4 n;
    vu0_v4 w;
    vu0_v4 r;
    vu0_v4 e;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 ra;
    vu0_v4 rb;
    vu0_v4 c;
    vu0_v4 in;
    vu0_v4 *p;
    u32 col;
    u32 gcol;
    s32 i;
    s32 last;
    f32 len;
    f32 lb;
    f32 zero;

    core.tex = func_00389598(D_L01_001DDC6C);
    col = D_L01_001DDC50 | (alpha << 24);
    core.d = 0x8000000048;
    core.c = 0xFF9000000260;
    core.a = 0;
    core.col[3] = col;
    core.col[2] = col;
    core.col[1] = col;
    core.col[0] = col;
    glow.tex = func_00389598(D_L01_001DDC70);
    glow.uv[0][0] = 0.0f;
    gcol = glow_col | (glow_alpha << 24);
    vec_sub_ab(&r, pts, &D_L01_001E29C0_00380CE0);
    zero = glow.uv[0][0];
    glow.d = core.d;
    glow.c = core.c;
    glow.a = core.a;
    glow.col[3] = gcol;
    glow.col[2] = gcol;
    glow.col[1] = gcol;
    glow.col[0] = gcol;
    glow.uv[0][1] = 0.0f;
    glow.uv[1][0] = 0.0f;
    glow.uv[1][1] = 1.0f;
    glow.uv[2][0] = 1.0f;
    glow.uv[2][1] = 0.0f;
    glow.uv[3][0] = 1.0f;
    glow.uv[3][1] = 1.0f;
    core.uv[0][0] = D_L01_001DDC54 + zero;
    core.uv[0][1] = zero;
    core.uv[1][0] = D_L01_001DDC54 + zero;
    core.uv[1][1] = 1.0f;
    core.uv[2][0] = D_L01_001DDC54 + 1.0f;
    core.uv[2][1] = zero;
    core.uv[3][0] = D_L01_001DDC54 + 1.0f;
    core.uv[3][1] = 1.0f;
    vec_sub_ab(&e, pts + 1, pts);
    func_0038CE90(&n, &e, &r);
    {
        f32 l = func_0038CEA8(&n);
        if (l != zero) {
            l = 1.0f / l;
        }
        func_0038CE20((Q_0037F860 *)&n, (Q_0037F860 *)&n, D_L01_001DDC44 * l);
    }
    vec_add_ba(&core.pos[0], pts, &n);
    vec_sub_ab(&core.pos[1], pts, &n);
    last = count - 1;
    for (i = 1, p = pts + 1; i < last; i++, p++) {
        vec_sub_ab(&r, p, &D_L01_001E29C0_00380CE0);
        vec_sub_ab(&e, p + 1, p);
        func_0038CE90(&n, &e, &r);
        {
            f32 l = func_0038CEA8(&n);
            if (l != zero) {
                l = 1.0f / l;
            }
            func_0038CE20((Q_0037F860 *)&n, (Q_0037F860 *)&n, D_L01_001DDC44 * l);
        }
        vec_add_ba(&core.pos[2], p, &n);
        vec_sub_ab(&core.pos[3], p, &n);
        if (i == 1) {
            core.col[1] = core.col[0] = D_L01_001DDC50;
        } else if (i == count - 2) {
            core.col[3] = core.col[2] = D_L01_001DDC50;
        } else if (i == 2) {
            core.col[0] = core.col[1] = col;
        }
        func_003D2DA0(&core, 0, 0);
        core.pos[0] = core.pos[2];
        core.pos[1] = core.pos[3];
    }
    for (i = 0, p = pts; i < last; i++, p++) {
        vec_sub_ab(&ra, p, &D_L01_001E29C0_00380CE0);
        vec_sub_ab(&rb, p + 1, &D_L01_001E29C0_00380CE0);
        len = func_0038CEA8(&ra);
        lb = func_0038CEA8(&rb);
        if (lb < len) {
            if (lb == 0.0f) {
                rb = ra;
            } else {
                func_0038CE20((Q_0037F860 *)&rb, (Q_0037F860 *)&rb, len / lb);
            }
        } else if (len == 0.0f) {
            ra = rb;
        } else {
            func_0038CE20((Q_0037F860 *)&ra, (Q_0037F860 *)&ra, lb / len);
        }
        vec_add_ba(&a, &D_L01_001E29C0_00380CE0, &ra);
        vec_add_ab(&b, &D_L01_001E29C0_00380CE0, &rb);
        vec_sub_ba(&e, &b, &a);
        func_0038CE20((Q_0037F860 *)&in, (Q_0037F860 *)&e, inset);
        vec_sub_ba(&a, &a, &in);
        vec_add_ba(&b, &b, &in);
        vec_sub_ab(&c, &D_L01_001E29C0_00380CE0, &a);
        func_0038CE90(&n, &c, &e);
        {
            f32 l = func_0038CEA8(&n);
            if (l != 0.0f) {
                l = 1.0f / l;
            }
            func_0038CE20((Q_0037F860 *)&w, (Q_0037F860 *)&n, width * l);
        }
        vec_add_ba(&glow.pos[0], &a, &w);
        vec_sub_ba(&glow.pos[1], &a, &w);
        vec_add_ba(&glow.pos[2], &b, &w);
        vec_sub_ab(&glow.pos[3], &b, &w);
        if (i == 0) {
            glow.col[0] = glow.col[1] = glow_col;
        } else if (i == count - 2) {
            glow.col[2] = glow.col[3] = glow_col;
        } else if (i == 1) {
            glow.col[0] = glow.col[1] = gcol;
        }
        func_003D2DA0(&glow, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_00380CE0 */
