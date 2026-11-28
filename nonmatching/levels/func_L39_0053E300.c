/* PAL near miss (wave 13, r23), first draft of a fresh entry: 161 words differ in its file's context with
 * the file's flags, measured with the divs row `func_L39_0053E300 2 2 2 2` injected (four div.s, two nops
 * each; the row is not in config/levels/divs_nops.txt yet).
 * Blocker: retail's VU0 sequences (0x294-0x408: lqc2/vsub.xyz/vadd.xyz/sqc2) have GPR insns scheduled
 * between their instructions, i.e. one compiler insn per VU0 op as include/vu0.h's "j" helpers give, which
 * needs -mvu0-use-vf0-vf2; this file's line lacks it, so each sequence is one asm block here (the
 * func_L01_0040E408 / mat_scale form) and that region cannot match under this line.
 * Data views: D_L39_00352B4C_0053E300 is the same word as the file's D_L39_00352B4C with a type that has the
 * second per-player array at 0xE8 (the file's S_352C4C_0053DA40 only has f88[1]; reading it as
 * f88[idx + 24] computes the index twice and gives 241); the colour table is read as three byte names
 * D_L39_002462A8/A9/AA (one 3-byte record per colour): retail forms the three addresses sym+0, sym+2,
 * sym+1 separately, which a u8 [][3] or a {u8 r, g, b} array does not give (one shared base, 4 words
 * shorter, 243).
 * Left besides the VU0 region: g and &c0 swap s3/s4, the uv loop gets t0/a3 where retail keeps &e and &f
 * in a3/a2 across it, and the colour/uv store order (c[] chain orders tried: no better).
 */
#include "common.h"

/* localdecomp:start func_L39_0053E300 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0053E300;
typedef struct { V_0053E300 v[4]; u32 c[4]; f32 uv[8]; u8 p70[0x20]; } Q_0053E300;
typedef struct { u8 p0[0x10]; V_0053E300 pos; u8 p20[0x48]; u8 *f68; } O_0053E300;
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; u8 p20[8]; s32 f28; } S_0053E300;
typedef struct { V_0053E300 pos; u8 p10[0x450]; } Cam_0053E300;
typedef struct { u8 p0[0x88]; s32 f88[24]; s32 fE8[8]; } G_0053E300;
extern G_0053E300 *D_L39_00352B4C_0053E300[];
extern u8 D_L39_002462A8[];
extern u8 D_L39_002462A9[];
extern u8 D_L39_002462AA[];
extern Cam_0053E300 D_L39_0024DE80[];
extern s32 D_L39_00241118;
__asm__(".extern D_L39_00241118, 16");
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);

void func_L39_0053E300(O_0053E300 *a0) {
    Q_0053E300 q;
    V_0053E300 d;
    V_0053E300 e;
    V_0053E300 f;
    V_0053E300 c0;
    V_0053E300 pos;
    S_0053E300 *s;
    s32 c;
    s32 lvl;
    s32 r;
    s32 g;
    s32 b;
    s32 r2;
    s32 i;
    f32 *uv;

    s = (S_0053E300 *)a0->f68;
    c = D_L39_00352B4C_0053E300[0]->f88[s->f1C];
    lvl = D_L39_00352B4C_0053E300[0]->fE8[s->f1C];
    if (c == -1) {
        r = 0xFF;
        g = 0xFF;
        b = 0xFF;
    } else {
        f32 fl;
        f32 base;
        if (lvl > 0x50) {
            s->f28 = 1;
        }
        fl = (f32)lvl;
        base = (100.0f - fl) * 255.0f / 100.0f;
        r = (s32)((f32)D_L39_002462A8[c * 3] * fl / 100.0f + base) & 0xFF;
        g = (s32)((f32)D_L39_002462A9[c * 3] * fl / 100.0f + base) & 0xFF;
        b = (s32)((f32)D_L39_002462AA[c * 3] * fl / 100.0f + base) & 0xFF;
    }
    func_003D93B0(&q, 0x17, 0, 0x80);
    q.c[0] = q.c[1] = 0x40000000 | (b << 16) | (g << 8) | r;
    q.c[2] = q.c[3] = (b << 16) | (g << 8) | r;
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = 1.0f;
    q.uv[4] = 5.0f;
    q.uv[5] = 0.0f;
    q.uv[6] = 5.0f;
    q.uv[7] = 1.0f;
    uv = q.uv;
    for (i = 3; i >= 0; i--) {
        *uv = *uv - s->f18;
        if (*uv <= 7.0f) {
            *uv = *uv + 7.0f;
        }
        uv += 2;
    }
    s->f18 = s->f18 + 0.1f;
    if (s->f18 >= 4.0f) {
        s->f18 = s->f18 - 4.0f;
    }
    d = a0->pos;
    d.z = 500.0f;
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(a0->pos));
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(e) : "m"(a0->pos), "m"(D_L39_0024DE80[D_L39_00241118].pos));
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(f) : "m"(d), "m"(pos));
    func_0038CE90(&c0, &e, &f);
    func_0038CF68(&c0, &c0, 2.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q.v[0]) : "m"(a0->pos), "m"(c0));
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(q.v[1]) : "m"(a0->pos), "m"(c0));
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q.v[2]) : "m"(d), "m"(c0));
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(q.v[3]) : "m"(d), "m"(c0));
    func_003D2DA0(&q, 0, 0);
    func_003D93B0(&q, 0xE, 1, 0x80);
    r2 = r + 0x20;
    if (r2 >= 0x100) {
        r2 = 0xFF;
    }
    q.c[0] = q.c[1] = 0x40000000 | (b << 16) | (g << 8) | r2;
    q.c[2] = q.c[3] = (b << 16) | (g << 8) | r2;
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = 1.0f;
    q.uv[4] = 1.0f;
    q.uv[5] = 0.0f;
    q.uv[6] = 1.0f;
    q.uv[7] = 1.0f;
    func_0038CF68(&c0, &c0, 6.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q.v[0]) : "m"(a0->pos), "m"(c0));
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(q.v[1]) : "m"(a0->pos), "m"(c0));
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q.v[2]) : "m"(d), "m"(c0));
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(q.v[3]) : "m"(d), "m"(c0));
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L39_0053E300 */
