#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L20_003CF108 */
/* Draws the object's two ropes (r[0], r[1]): per rope a ribbon of 0x1F quads along its points, then a walk of the
 * 4x3 grid, every quad a GS packet built on the stack and drawn with func_003D2DA0. The same code is in three
 * places of level 20 (func_L20_003CF108, func_L20_003E6F88, func_L20_003E90C0); they differ in the gp slots.
 *
 * -fno-sched-interblock (a file of its own): the quad loops are scheduling regions of under 100 insns without line
 * notes, so sched1 would move their int-to-float conversion and counter increment into the loop head. Retail keeps
 * them in the tail, which -g (line notes enlarge the regions) gives as well, as in func_L11_003AFF60.
 *
 * Rope 1 has its own copy of every local (r2, i2, ...): one set shared by both ropes would be set twice across
 * blocks and could not be the block-local registers retail has.
 *
 * lo, seg, split, hi, ksplit, usplit and odd hold constants: gcse's constant propagation folds each into its compare
 * or mask, so the code is the same as with literals, but each is an insn when gcse sizes its expression hash table
 * (insns / 2, made odd). That size decides the order in which gcse creates the reaching registers of the eight address
 * expressions it hoists (the packet pointers, m + 0x28, m + 0xC40), and reload numbers their stack slots in that
 * order: retail's slot order needs 315 buckets, literals give 309, these variables 315.
 * The grid walk of rope 1 reads r[0].grid[k + 2][n] where it reads r[1] elsewhere: retail's 0x4B0 offset. */
typedef struct { f32 x, y; } UV_003CF108;
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    UV_003CF108 uv[4];
    long g0;
    long g1;
    long g2;
    long g3;
} Quad_003CF108;
typedef struct {
    vu0_v4 p[32];
    vu0_v4 q[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    f32 ang[3];
} Rope_003CF108;
typedef struct {
    u8 pad0[8];
    s32 total;
    u8 padC[0x22 - 0xC];
    s16 timer;
    s32 color;
    u8 idx[4];
    u8 pad2C[4];
    Rope_003CF108 r[2];
} V_003CF108;
extern vu0_v4 D_L20_001E2E00;
__asm__(".extern D_L20_001DEB08, 4");
__asm__(".extern D_L20_001DEB0C, 4");
__asm__(".extern D_L20_001DEB10, 4");
__asm__(".extern D_L20_001DEB14, 4");
__asm__(".extern D_L20_001DEB18, 4");
__asm__(".extern D_L20_001DEB28, 4");
extern s32 D_L20_001DEB08;
extern s32 D_L20_001DEB0C;
extern s32 D_L20_001DEB10;
extern s32 D_L20_001DEB14;
extern s32 D_L20_001DEB18;
extern UV_003CF108 D_L20_001DEB28[] __attribute__((section(".sdata")));
extern long func_00389598(s32);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

static __inline__ void vcopy_003CF108(vu0_v4 *d, vu0_v4 *s)
{
    *(vu0_q *)d = *(vu0_q *)s;
}

void func_L20_003CF108(u8 *a0)
{
    V_003CF108 *m = *(V_003CF108 **)(a0 + 0x68);
    Quad_003CF108 s[3];
    vu0_v4 mtxa[4];
    vu0_v4 mtxb[4];
    vu0_v4 d;
    vu0_v4 prev;
    vu0_v4 cur;
    vu0_v4 e1;
    vu0_v4 e0;
    long r;
    long pk;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 b;
    s32 t;
    s32 u;
    s32 lo = 0;
    s32 seg = 0x1E;
    s32 split = 2;
    s32 hi = 0x1F;
    s32 ksplit = 2;
    s32 odd = 1;
    s32 usplit = 2;
    long r2;
    long pk2;
    s32 i2;
    s32 j2;
    s32 k2;
    s32 n2;
    s32 b2;
    s32 t2;
    s32 u2;
    s32 lo2 = 0;
    s32 seg2 = 0x1E;
    s32 split2 = 2;
    s32 hi2 = 0x1F;
    s32 ksplit2 = 2;
    s32 odd2 = 1;
    s32 usplit2 = 2;

    func_0038D328(mtxa, m->r[0].ang);
    func_0038D5B0(mtxb, mtxa);
    mtxa[3] = *(vu0_v4 *)(a0 + 0x10);
    vec_sub_ba(&d, &D_L20_001E2E00, a0 + 0x10);
    func_0038D000(&d, &d, mtxb);
    r = func_00389598(D_L20_001DEB08);
    pk = (long)D_L20_001DEB0C | ((long)D_L20_001DEB10 << 2) |
         ((long)D_L20_001DEB14 << 4) | ((long)D_L20_001DEB18 << 6) | 0x8000000000L;
    s[0].g1 = s[1].g1 = s[2].g1 = r;
    s[0].g2 = s[1].g2 = s[2].g2 = 0xFF9000000260L;
    s[0].g0 = s[1].g0 = s[2].g0 = 0;
    s[0].g3 = s[1].g3 = s[2].g3 = pk;
    for (t = 0; t < 4; t++) {
        s[0].uv[t].y = s[1].uv[t].y = s[2].uv[t].y = D_L20_001DEB28[t].y;
        s[0].c[t] = s[1].c[t] = s[2].c[t] = m->color;
    }
    qzero(&cur);
    for (i = 0; i < 0x1F; i++) {
        prev = cur;
        if (i < seg) {
            vec_sub_ab(&e0, &m->r[0].p[i], &m->r[0].p[i + 2]);
            vec_sub_ba(&e1, &m->r[0].p[i + 1], &d);
            func_0038CE90(&cur, &e1, &e0);
            func_0038CF68(&cur, &cur, 0.1f);
        } else {
            qzero(&cur);
        }
        for (j = 0; j < 4; j++) {
            if (j < split) {
                vcopy_003CF108(&s[0].v[j], &m->r[0].p[i]);
                if (j & odd) {
                    vec_add_ab(&s[0].v[j], &s[0].v[j], &prev);
                } else {
                    vec_sub_ab(&s[0].v[j], &s[0].v[j], &prev);
                }
            } else {
                vcopy_003CF108(&s[0].v[j], &m->r[0].p[i + 1]);
                if (j & 1) {
                    vec_add_ab(&s[0].v[j], &s[0].v[j], &cur);
                } else {
                    vec_sub_ab(&s[0].v[j], &s[0].v[j], &cur);
                }
            }
            s[0].uv[j].x = D_L20_001DEB28[j].x + (f32)(i % 4) * 0.25f;
        }
        func_003D2DA0(&s[0], mtxa, 0);
    }
    for (n = 0; n < 4; n++) {
        qzero(&cur);
        b = m->idx[n];
        if (b < hi && b >= lo) {
            for (k = 0; k < 3; k++) {
                prev = cur;
                if (k < ksplit) {
                    vec_sub_ab(&e0, &m->r[0].grid[k][n], &m->r[0].grid[k + 2][n]);
                    vec_sub_ba(&e1, &m->r[0].grid[k + 1][n], &d);
                    func_0038CE90(&cur, &e1, &e0);
                    func_0038CF68(&cur, &cur, 0.1f);
                } else {
                    qzero(&cur);
                }
                if (k == 0) {
                    prev = cur;
                }
                for (u = 0; u < 4; u++) {
                    if (u < usplit) {
                        vcopy_003CF108(&s[0].v[u], &m->r[0].grid[k][n]);
                        if (u & 1) {
                            vec_add_ab(&s[0].v[u], &s[0].v[u], &prev);
                        } else {
                            vec_sub_ab(&s[0].v[u], &s[0].v[u], &prev);
                        }
                    } else {
                        vcopy_003CF108(&s[0].v[u], &m->r[0].grid[k + 1][n]);
                        if (u & 1) {
                            vec_add_ab(&s[0].v[u], &s[0].v[u], &cur);
                        } else {
                            vec_sub_ab(&s[0].v[u], &s[0].v[u], &cur);
                        }
                    }
                    s[0].uv[u].x = D_L20_001DEB28[u].x + (f32)(k % 4) * 0.25f;
                }
                func_003D2DA0(&s[0], mtxa, 0);
            }
        }
    }
    func_0038D328(mtxa, m->r[1].ang);
    func_0038D5B0(mtxb, mtxa);
    mtxa[3] = *(vu0_v4 *)(a0 + 0x10);
    vec_sub_ba(&d, &D_L20_001E2E00, a0 + 0x10);
    func_0038D000(&d, &d, mtxb);
    r2 = func_00389598(D_L20_001DEB08);
    pk2 = (long)D_L20_001DEB0C | ((long)D_L20_001DEB10 << 2) |
          ((long)D_L20_001DEB14 << 4) | ((long)D_L20_001DEB18 << 6) | 0x8000000000L;
    s[0].g1 = s[1].g1 = s[2].g1 = r2;
    s[0].g2 = s[1].g2 = s[2].g2 = 0xFF9000000260L;
    s[0].g0 = s[1].g0 = s[2].g0 = 0;
    s[0].g3 = s[1].g3 = s[2].g3 = pk2;
    for (t2 = 0; t2 < 4; t2++) {
        s[0].uv[t2].y = s[1].uv[t2].y = s[2].uv[t2].y = D_L20_001DEB28[t2].y;
        s[0].c[t2] = s[1].c[t2] = s[2].c[t2] = m->color;
    }
    qzero(&cur);
    for (i2 = 0; i2 < 0x1F; i2++) {
        prev = cur;
        if (i2 < seg2) {
            vec_sub_ab(&e0, &m->r[1].p[i2], &m->r[1].p[i2 + 2]);
            vec_sub_ba(&e1, &m->r[1].p[i2 + 1], &d);
            func_0038CE90(&cur, &e1, &e0);
            func_0038CF68(&cur, &cur, 0.1f);
        } else {
            qzero(&cur);
        }
        for (j2 = 0; j2 < 4; j2++) {
            if (j2 < split2) {
                vcopy_003CF108(&s[0].v[j2], &m->r[1].p[i2]);
                if (j2 & odd2) {
                    vec_add_ab(&s[0].v[j2], &s[0].v[j2], &prev);
                } else {
                    vec_sub_ab(&s[0].v[j2], &s[0].v[j2], &prev);
                }
            } else {
                vcopy_003CF108(&s[0].v[j2], &m->r[1].p[i2 + 1]);
                if (j2 & 1) {
                    vec_add_ab(&s[0].v[j2], &s[0].v[j2], &cur);
                } else {
                    vec_sub_ab(&s[0].v[j2], &s[0].v[j2], &cur);
                }
            }
            s[0].uv[j2].x = D_L20_001DEB28[j2].x + (f32)(i2 % 4) * 0.25f;
        }
        func_003D2DA0(&s[0], mtxa, 0);
    }
    for (n2 = 0; n2 < 4; n2++) {
        qzero(&cur);
        b2 = m->idx[n2];
        if (b2 < hi2 && b2 >= lo2) {
            for (k2 = 0; k2 < 3; k2++) {
                prev = cur;
                if (k2 < ksplit2) {
                    vec_sub_ab(&e0, &m->r[1].grid[k2][n2], &m->r[0].grid[k2 + 2][n2]);
                    vec_sub_ba(&e1, &m->r[1].grid[k2 + 1][n2], &d);
                    func_0038CE90(&cur, &e1, &e0);
                    func_0038CF68(&cur, &cur, 0.1f);
                } else {
                    qzero(&cur);
                }
                if (k2 == 0) {
                    prev = cur;
                }
                for (u2 = 0; u2 < 4; u2++) {
                    if (u2 < usplit2) {
                        vcopy_003CF108(&s[0].v[u2], &m->r[1].grid[k2][n2]);
                        if (u2 & 1) {
                            vec_add_ab(&s[0].v[u2], &s[0].v[u2], &prev);
                        } else {
                            vec_sub_ab(&s[0].v[u2], &s[0].v[u2], &prev);
                        }
                    } else {
                        vcopy_003CF108(&s[0].v[u2], &m->r[1].grid[k2 + 1][n2]);
                        if (u2 & 1) {
                            vec_add_ab(&s[0].v[u2], &s[0].v[u2], &cur);
                        } else {
                            vec_sub_ab(&s[0].v[u2], &s[0].v[u2], &cur);
                        }
                    }
                    s[0].uv[u2].x = D_L20_001DEB28[u2].x + (f32)(k2 % 4) * 0.25f;
                }
                func_003D2DA0(&s[0], mtxa, 0);
            }
        }
    }
}
/* localdecomp:end func_L20_003CF108 */
