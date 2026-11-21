/* PAL near miss (Sonnet round 20, b33 h2c, improved by h7b): 3 raw differences (3 aligned words) in the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2);
 * it needs the divs_nops.txt row `func_L01_003C7D38 2` (retail has two nops before its one div.s; the row is committed with this draft).
 * Path-following camera step, written from the retail listing (never compiled before this round): the path is D_L01_0021F6C0[s->c0], the aim target
 * m = D_L01_001E0100 + a[s->index] * 128; the segment direction is vsub(next, current) in three arms (t < 0: pts[0] - s+0x140, last segment: s+0x150 - pts[idx],
 * else pts[idx+1] - pts[idx]), normalised, its dot with o+0xC0 blends gp constants into the speed controller func_003C41A0; func_L01_003C7A98 advances t, the
 * segment index is clamped (r = 2 at the path end), func_L01_003C7BC0 writes the interpolated position into o+0x10; then three aiming blocks (angles through
 * func_0038DAB8 with a clamp, or pitch/yaw from func_0038D160), three func_L01_00448890 springs and the tolerance test with func_0038DBA0 + fabs_asm.
 * What got it from 89 aligned (first compile) to 4: (1) the callees of this very file are called through per-caller aliases with their real prototypes
 * (func_L01_003C7A68 returns the float of func_L01_00477ED0, func_L01_003C7BC0 takes the fraction in $f12), so the matched neighbours stay as they are;
 * (2) vec_sub_ab INSIDE EACH ARM of the segment choice: after sched2 the three arms end in the identical `vsub.xyz vf1,vf1,vf2; sqc2 vf1,0($sp)` and jump2
 * cross-jumps them, so retail's vsub/sqc2 sit before the call's lui/mtc1/moves (31 -> 4); a single vsub after the join cannot give that order;
 * (3) head order: off = a[index] * 128 (own variable), pos = o->pos copy, path, m (statement order moves the $v0/$a2 names and the lwc1 $f12); (4) one `lim` per
 * block (a shared `lim` lands in $f22); (5) the dot product and the blend factor are ONE variable (a), the interpolated x goes through a temporary (k = ...; b = ...; a = k);
 * (6) `e = s + s->index * 4` before the +0x6D0 load (base + index sum order), arm 3 via `pp = path->pts + idx` and the quad reads pp[1], *pp.
 * h7b LEVER (5 -> 3 raw): the blend factor is its OWN variable `w` (dot, `w *= D7C`, clamp), and `a`, `b` are assigned directly from it (`a = D80 + (D74 - D80) * w; b = D88 + (D84 - D88) * w;`)
 * with no `k` temp and no copy `a = k`. In the earlier form (a = dot = factor, k temp, a = k) combine merged the copy, so the new `a` overwrote the factor the b multiply reads (a WAR edge): the
 * b chain got the longer path and sched1 loaded D88 before D74. With `w` separate there is no WAR edge: sched1 gives retail's load order (d0, c4, d8, d4) AND b lands in $f0 (b takes the register
 * the D74 temp frees at the a sum). Where it was found: sched1 table of the else-arm block (all four loads priority 11, ranked by dependents then luid) and t.c.greg conflicts.
 * Left (3 words, one allocation fact): `a` is $f2 in ours (it shares the dying D80 temp's register at the sum: `lwc1 $f2` in the first arm, `add.s $f2,$f2,$f0`, `mul.s $f15,$f2,$f15`), retail has
 * $f4 = the factor's register. Retail's `a` must be live across the whole else arm (it conflicts with every temp there): in the original the factor and the result are ONE variable, which brings back
 * the WAR edge and the wrong load order (h2c's form, 5 words). Tried on top (all >= 3): w taken from an existing local (k: 3, frac: 10, t3: 168), declaration order of w (5 positions: 3), `k` temp + copy with
 * a separate w (3), b before a (9), a single variable with b first (8), a = (D74 - D80) * w; a = D80 + a (8), operand orders (3), dot kept in `a` and a separate factor (10). A way to keep `a` live over
 * the else arm without the WAR edge (or a copy that combine does not merge) is the open question.
 * h9 (round 20, ~16 compiles + 230 toy forms): mechanism of the two registers. Toy (sonnet-b33-h9-tools/toy_003C7D38) reproduces both forms. The w form has retail's load order because RA puts b in
 * $f0 = the register of the dying a product: sched2 then sees an anti-dependence (add_a reads $f0, add_b writes it), the a chain gets the higher priority and sched2 reorders the loads to D80 D74 D88 D84
 * (sched1 emits D80 D88 D74 D84 in both forms). h2c's one-variable form gives a = $f4 (right) but b = $f3: global-alloc `preferences` for b is only $f3 (operand 0 of its PLUS = the D88 temp),
 * and with a allocated before b there is no anti-edge, so sched2 keeps D80 D88 D74 D84 (5 raw). In the w form the allocation order is w, b, a and a (last) prefers its operand 0 = D80 temp = $f2.
 * Open: a form where a conflicts with the D80 temp (so it falls to $f4 = w's register) while b is still allocated before a. Tried without change: the 224-form toy sweep (factor in w or a, a = k / in place,
 * a / b accumulators, operand orders, statement orders, a = w copies) and 12 real variants (best 3 = this draft). */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003C7D38 */
extern f32 D_L01_001DEC74_003C7D38;
extern f32 D_L01_001DEC7C_003C7D38;
extern f32 D_L01_001DEC80_003C7D38;
extern f32 D_L01_001DEC84_003C7D38;
extern f32 D_L01_001DEC88_003C7D38;
extern f32 D_L01_001DEC90_003C7D38;
extern f32 D_L01_001DEC94_003C7D38;
extern f32 D_L01_001DEC98_003C7D38;
extern f32 D_L01_001DEC9C_003C7D38;
extern f32 D_L01_001DECA0_003C7D38;
extern f32 D_L01_001DECA4_003C7D38;
extern f32 D_L01_001DECA8_003C7D38;
extern f32 D_L01_001DECAC_003C7D38;
extern f32 D_L01_001DECB0_003C7D38;
extern f32 D_L01_001DECB4_003C7D38;
extern f32 D_L01_001DECB8_003C7D38;
extern f32 D_L01_001DECBC_003C7D38;
extern f32 D_L01_001DECC0_003C7D38;
extern s32 D_L01_001DECD4_003C7D38;
__asm__(".extern D_L01_001DEC74_003C7D38, 4");
__asm__(".extern D_L01_001DEC7C_003C7D38, 4");
__asm__(".extern D_L01_001DEC80_003C7D38, 4");
__asm__(".extern D_L01_001DEC84_003C7D38, 4");
__asm__(".extern D_L01_001DEC88_003C7D38, 4");
__asm__(".extern D_L01_001DEC90_003C7D38, 4");
__asm__(".extern D_L01_001DEC94_003C7D38, 4");
__asm__(".extern D_L01_001DEC98_003C7D38, 4");
__asm__(".extern D_L01_001DEC9C_003C7D38, 4");
__asm__(".extern D_L01_001DECA0_003C7D38, 4");
__asm__(".extern D_L01_001DECA4_003C7D38, 4");
__asm__(".extern D_L01_001DECA8_003C7D38, 4");
__asm__(".extern D_L01_001DECAC_003C7D38, 4");
__asm__(".extern D_L01_001DECB0_003C7D38, 4");
__asm__(".extern D_L01_001DECB4_003C7D38, 4");
__asm__(".extern D_L01_001DECB8_003C7D38, 4");
__asm__(".extern D_L01_001DECBC_003C7D38, 4");
__asm__(".extern D_L01_001DECC0_003C7D38, 4");
__asm__(".extern D_L01_001DECD4_003C7D38, 4");
extern f32 func_L01_003C7A68_003C7D38(void *, char *, float);
extern f32 func_L01_003C7A98_003C7D38(u8 *, Path_003C7810 *, s32 *, f32, f32);
extern void func_L01_003C7BC0_003C7D38(u8 *, Path_003C7810 *, s32, u8 *, f32);
extern void func_L01_003C7C80_003C7D38(u8 *, void *, vu0_v4, f32 *, f32 *);
extern Path_003C7810 *D_L01_0021F6C0_003C7D38[];
extern u8 *D_L01_001E0100_003C7D38;
extern f32 func_0038CED8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);

s32 func_L01_003C7D38(u8 *o, u8 *s) {
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 tgt;
    vu0_v4 q;
    vu0_v4 d2;
    f32 unused;
    s32 idx;
    Path_003C7810 *path;
    u8 *m;
    f32 w, t, t2, t3, v, frac, lim1, lim2, lim3, lim4, lim5, a, b, h;
    s32 r, clamped, off;
    u8 *e;

    e = s + *(s32 *)(s + 0x6BC) * 4;
    off = *(s32 *)(e + 0x6D0) * 128;
    pos = *(vu0_v4 *)(o + 0x10);
    path = D_L01_0021F6C0_003C7D38[*(s32 *)(s + 0xC0)];
    m = D_L01_001E0100_003C7D38 + off;
    h = func_L01_003C7A68_003C7D38(o, s, D_L01_001DEC74_003C7D38);
    t = *(f32 *)(s + 0xC4);
    if (t < 0.0f) {
        vec_sub_ab(&d, &path->pts[0], s + 0x140);
    } else {
        idx = (s32)t;
        if (idx == path->count - 1) {
            vec_sub_ab(&d, s + 0x150, &path->pts[idx]);
        } else {
            vec_sub_ab(&d, &path->pts[idx + 1], &path->pts[idx]);
        }
    }
    func_0038CF68(&d, &d, 1.0f);
    w = func_0038CE68(&d, o + 0xC0);
    if (w <= 0.0f) {
        b = D_L01_001DEC88_003C7D38;
        a = D_L01_001DEC80_003C7D38;
    } else {
        w = w * D_L01_001DEC7C_003C7D38;
        if (1.0f < w) {
            w = 1.0f;
        }
        a = D_L01_001DEC80_003C7D38 + (D_L01_001DEC74_003C7D38 - D_L01_001DEC80_003C7D38) * w;
        b = D_L01_001DEC88_003C7D38 + (D_L01_001DEC84_003C7D38 - D_L01_001DEC88_003C7D38) * w;
    }
    unused = 0.0f;
    r = 0;
    func_003C41A0(&unused, s + 0xC8, h, b * 0.000400000019f, b * 0.000400000019f, a * 0.0200000014f);
    t2 = func_L01_003C7A98_003C7D38(s, path, &idx, *(f32 *)(s + 0xC4), *(f32 *)(s + 0xC8));
    *(f32 *)(s + 0xC4) = t2;
    clamped = 0;
    if (!(idx < path->count - 1)) {
        idx = path->count - 1;
        clamped = 1;
    }
    frac = t2 - (f32)idx;
    if (clamped) {
        if (1.0f <= frac) {
            frac = 1.0f;
            r = 2;
            *(f32 *)(s + 0xC4) = t2 - *(f32 *)(s + 0xC8) / path->pts[idx].w;
        }
    }
    func_L01_003C7BC0_003C7D38(s, path, idx, o + 0x10, frac);
    if (o[0x20] == 3 && !(idx < path->count - D_L01_001DECD4_003C7D38)) {
        func_L01_003C7C80_003C7D38(o, s, pos, &tgt.x, &tgt.y);
        tgt.x = -tgt.x;
        tgt.y = -tgt.y;
        tgt.x = func_0038DAB8(tgt.x, *(f32 *)(m + 0x70));
        lim1 = D_L01_001DECA0_003C7D38 * 0.017453292f;
        if (lim1 < tgt.y) {
            tgt.y = lim1;
        } else if (tgt.y < -lim1) {
            tgt.y = -lim1;
        }
        tgt.y = func_0038DAB8(tgt.y, *(f32 *)(m + 0x74));
        tgt.z = *(f32 *)(m + 0x78);
    } else if ((*(f32 *)(s + 0x14C) > 0.0f && idx == -1) || (*(f32 *)(s + 0x14C) < 0.0f && idx == 0)) {
        func_L01_003C7C80_003C7D38(o, s, pos, &tgt.x, &tgt.y);
        tgt.x = func_0038DAB8(tgt.x, *(f32 *)(m + 0x70));
        lim2 = D_L01_001DECA0_003C7D38 * 0.017453292f;
        if (lim2 < tgt.y) {
            tgt.y = lim2;
        } else if (tgt.y < -lim2) {
            tgt.y = -lim2;
        }
        tgt.y = func_0038DAB8(tgt.y, *(f32 *)(m + 0x74));
        tgt.z = *(f32 *)(o + 0xF8);
    } else {
        v = *(f32 *)(s + 0xC8) * D_L01_001DEC90_003C7D38;
        if (D_L01_001DEC94_003C7D38 < v) {
            v = D_L01_001DEC94_003C7D38;
        } else if (v < D_L01_001DEC98_003C7D38) {
            v = D_L01_001DEC98_003C7D38;
        }
        t3 = func_L01_003C7A98_003C7D38(s, path, &idx, *(f32 *)(s + 0xC4), v);
        idx = (s32)t3;
        func_L01_003C7BC0_003C7D38(s, path, idx, (u8 *)&q, t3 - (f32)idx);
        vec_sub_ab(&d2, &q, o + 0x10);
        tgt.x = 0.0f;
        v = func_0038CED8(&d2);
        tgt.y = -func_0038D160(v, d2.z);
        lim3 = D_L01_001DECA0_003C7D38 * 0.017453292f;
        if (lim3 < tgt.y) {
            tgt.y = lim3;
        } else if (tgt.y < -lim3) {
            tgt.y = -lim3;
        }
        tgt.z = func_0038D160(d2.x, d2.y);
    }
    lim4 = 0.017453292f;
    func_L01_00448890(o + 0xF4, tgt.y, s + 0x134, 0, D_L01_001DECA4_003C7D38 * lim4 * 0.000400000019f,
                      D_L01_001DECA4_003C7D38 * lim4 * 0.000400000019f, D_L01_001DECA8_003C7D38 * lim4 * 0.0200000014f);
    func_L01_00448890(o + 0xF8, tgt.z, s + 0x138, 0, D_L01_001DECAC_003C7D38 * lim4 * 0.000400000019f,
                      D_L01_001DECAC_003C7D38 * lim4 * 0.000400000019f, D_L01_001DECB0_003C7D38 * lim4 * 0.0200000014f);
    tgt.x = func_0038DAB8(tgt.x, *(f32 *)(s + 0x138) * *(f32 *)(s + 0xC8) * D_L01_001DECC0_003C7D38);
    lim5 = D_L01_001DECB4_003C7D38 * lim4;
    if (lim5 < tgt.x) {
        tgt.x = lim5;
    } else if (tgt.x < -lim5) {
        tgt.x = -lim5;
    }
    func_L01_00448890(o + 0xF0, tgt.x, s + 0x130, 0, D_L01_001DECBC_003C7D38 * 0.017453292f * 0.000400000019f,
                      D_L01_001DECBC_003C7D38 * 0.017453292f * 0.000400000019f, D_L01_001DECB8_003C7D38 * 0.017453292f * 0.0200000014f);
    *(vu0_q *)&tgt = *(vu0_q *)(m + 0x70);
    if (r == 2) {
        if (D_L01_001DEC9C_003C7D38 < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF0), tgt.x))) {
            r = 1;
        } else if (D_L01_001DEC9C_003C7D38 < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF4), tgt.y))) {
            r = 1;
        } else if (D_L01_001DEC9C_003C7D38 < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF8), tgt.z))) {
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_L01_003C7D38 */
