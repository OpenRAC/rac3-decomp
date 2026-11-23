/* PAL draft (2026-11-21, Promises fleet rac3-w2; retried 2026-11-22 by NM-R10, rac3-w3): func_L04_00355740
 * (1204 B; levels 04 24 26 39-53), written from retail. check.py with its file's line
 * (-mvu0-use-vf0-vf2 ... @ps2as): 2 diff at every placement (04, 24, 26, 39-53; also NTSC-U and --no-context),
 * re-measured 2026-11-23 (task #2996). The history below gives the earlier counts (233 -> 136 -> 2). Calls,
 * constants and the order of the vector operations follow retail. The colour fields are s32 (u32 gives `lui/ori 0xFFFF` for -1, retail has `addiu -1`: 247 -> 233).
 * The 2026-11-22 retry, each step measured on top of the one before:
 *  - vec_copy(&e, &D_001E27C0) before the func_0038CF68(&a, t, -0.17f) call: the scheduler no longer keeps three
 *    VU0 values live there, one of the two 16-byte spill slots goes (frame 0x180 -> 0x170) and the first half's
 *    vf1/vf2 roles line up with retail: 233 -> 148 (between the call and vec_add_ba it stays 233);
 *  - the second block's col[3] stored before col[2]: 148 -> 146;
 *  - the second block's uv stores in plain order uv[0].u ... uv[3].v: 146 -> 138;
 *  - the third block's colours stored col[3], col[2], col[1], col[0]: 138 -> 136 (all 24 orders tried: 136-138).
 * What still differs: the frame is 0x170, retail's 0x160. vec_copy(&g, o + 0x10) is the last spill: retail loads
 * o + 0x10 for the copy right after storing q.v[0] and stores g at once, where this C's scheduling keeps the copy's
 * value live across vec_sub_ab(&q.v[1], ...) and reload spills it to 0x100($sp). The copy placed before
 * vec_sub_ab (153) or before vec_add_ba (155) moves the spill to another value; before the func_0038CF68(&f, &f,
 * 0.2f) call it goes (frame 0x160) but the copy is then out of place (158). The _ab/_ba choice of those two
 * helpers changes nothing (the loads are reordered freely). Everything after that point is two instructions out of
 * step, and vf1/vf2 are the other way round in most of the later sequences.
 * 2026-11-23 (RT-G, rac3-w3): re-measured at 136. The copy at each of its three places after the 0.2f call
 * (before vec_add_ba(&q.v[0], ...): 143; before vec_sub_ab(&q.v[1], ...): 141; after it: 136), each with all four
 * _ab/_ba choices of the q.v[0]/q.v[1] helpers (no change at any place) and vec_add_ba for d = g + c (no change):
 * the frame stays 0x170 in all 15. Retail's order is lqc2 o + 0x10 for the vsub, sqc2 q.v[0], lqc2 o + 0x10,
 * sqc2 g, lqc2 f, vsub: the copy's store comes before f's load, where this C's sched1 puts it after the vsub's
 * store and reload spills the copied value to 0x100($sp).
 * 2026-11-23 (RT-I, rac3-w1, task #2976): 136 -> 2 differences, in the PROVISIONAL VU0 j-constraint form
 * (docs/wiki/Matching-Patterns.md, "VU0 j-form") for three sequences, with RT-H2's levers (#2971):
 *  - the 0.2f block's copy of o + 0x10 into g loads into r, the add's result register, right after r is
 *    stored to q.v[0]: the copy no longer spills, frame 0x170 -> 0x160 (136 -> 62);
 *  - the same for the first block (a = o + a, e = D_001E27C0, b = o - e), back at its retail place after the
 *    -0.17f call: the copy and the sub's o load both go into y, the add's spent operand, the add's result into x
 *    and the e load into x after x is stored (62 -> 47);
 *  - the _ab/_ba choice of the helpers, greedily (47 -> 19); d = g + c joined to the 0.2f block with g loaded into
 *    the sub's spent result (19 -> 16) and the last block's a = o + a; q.v[0] = a + f as j-form with f loaded into
 *    a spent register (-> 12); the first and third colour blocks' store orders re-searched (24 each) (-> 2).
 * What still differs (2 words): in the first block retail loads o + 0x10 for the sub (lqc2 vf1) before it stores
 * a (sqc2 vf2); this C stores a first. sched1's dump (-dS -fsched-verbose=5) shows both ready at the same cycle:
 * the store reaches the vsub through the e load (BLKmode stack operands conflict, or the register reuse), one step
 * longer than the o load, and as a store it also lowers register pressure, so it always wins. TImode casts on any
 * of the block's operands, other register-variable choices (244) and the 22 valid statement orders did not change
 * it (47 at that stage) or spilled.
 * 2026-11-23 (RT-I2, rac3-w1, task #2982): still 2 (also 2 with --no-context; 2 at level 26, 3 at 24 and 4 at
 * 39-53, where the extra words are only D_001E27C0's relocation; NTSC-U 2, the same pair). sched1's dump: the o
 * load (lqc2 o + 0x10) and the a store issue in the same cycle (issue rate 2); the e load's only link to the a store
 * is the anti dependence of reusing x, so the two have equal priority and the store wins on register weight. After
 * reload sched2 sees a true memory dependence from the a store to the o load, so the order is fixed in sched1.
 * Tried without a gain:
 *  - each of the block's eight lqc2/sqc2 as asm or as a plain TImode copy (x = *(vu0_q *)&e; ...), all 256
 *    combinations: 2 at best (a C store of a with a C store of e lets the a store issue at once: 3-9 or a spill);
 *  - the e load into a fresh variable, with every asm/TImode-asm/C form of the o load, a store and e load (27, and
 *    7 more with a C store of e): 10 at best, or a spill (0x170/0x180). With BLKmode operands the e load gets a
 *    true memory dependence on the a store (the store gains priority); with TImode a/e the a store loses its output
 *    dependence on the e store and issues before the D load; with C loads the e load takes the memory unit ahead of
 *    the o load (it depends on the last insn issued).
 * 2026-11-23 (PASS-P1, rac3-w1, task #2996): D_001E27C0 is level 04's .bss (0x1DF580 + 0xC5600), so it is named
 * D_L04_001E27C0 (docs/build/levels.md, "C in level code"): levels 24 and 39-53 go from 3 and 4 to 2, the same
 * pair as level 04. Still 2: sched1's dump (block 6) has the o load (231) and the a store (233) ready at t = 8
 * with no memory dependence between them (o is the incoming a3, an argument base, which alias analysis keeps
 * apart from the frame), and the store is issued first. Tried without a gain (all 2 unless noted):
 *  - a pointer local for o + 0x10 (scoped vu0_v4 *p = o + 0x10, or p = o and p[1]), ((vu0_v4 *)o)[1], and TImode
 *    "m" operands for one or both o loads;
 *  - BLKmode/TImode "m" for the e store, the a store and the e load, with the e load into x or a fresh variable
 *    (16): x keeps 2-4, a fresh variable 10 (the a store's BLKmode store gives the e load a true dependence) or
 *    a spill (frame 0x180);
 *  - other block structures: the add and the copy + sub as two blocks (10), the add as a block plus vec_copy and
 *    vec_sub_ab (233, frame 0x170), vec_add_ba plus the copy + sub block (10), the a store moved into the first
 *    of two blocks (230, 0x170), the vsub's result into x (9), and vu0.h helpers for all three (233, 0x170);
 *  - the second o load as a compiler TImode load (y = *(vu0_q *)(o + 0x10)), alone or with the first: the load
 *    gets the memory unit but is still ready at t = 8 with the store, which is issued first.
 */
#include "common.h"
#include "vu0.h"

typedef struct { f32 u, v; } UV_355740;
typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    UV_355740 uv[4];
    long x70, x78, x80, x88;
} Q_355740;

extern void func_L01_0034D840(void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern vu0_v4 D_L04_001E27C0;

void func_L04_00355740(void *unused, u32 c0, u32 c1, u8 *o) {
    Q_355740 q;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 f;
    vu0_v4 e;
    vu0_v4 g;
    u8 *t;
    s32 i;

    t = *(u8 **)(o + 0x68);
    func_L01_0034D840(&q);
    func_003D93B0(&q, 0x2F, 0, 0x80);
    q.col[1] = -1;
    q.col[3] = 0x40FFFFFF;
    q.col[2] = 0x40FFFFFF;
    q.col[0] = -1;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= *(f32 *)(t + 0x28);
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    *(f32 *)(t + 0x28) += 0.1f;
    if (4.0f <= *(f32 *)(t + 0x28)) {
        *(f32 *)(t + 0x28) -= 4.0f;
    }
    func_0038CF68(&a, t, -0.17f);
    {
        vu0_q x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_L04_001E27C0));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(y));
    }
    if (t[0x34] != 0 && *(f32 *)(t + 0x38) < 4.0f) {
        func_0038CF68(&c, t, -*(f32 *)(t + 0x38));
    } else {
        func_0038CF68(&c, t, -4.0f);
    }
    vec_add_ba(&d, &a, &c);
    func_0038CE90(&f, &b, &c);
    func_0038CF68(&f, &f, 0.1f);
    vec_add_ba(&q.v[0], o + 0x10, &f);
    vec_sub_ab(&q.v[1], o + 0x10, &f);
    vec_add_ba(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    q.col[0] = q.col[2];
    q.col[1] = q.col[3];
    q.col[3] = 0x801010;
    q.col[2] = 0x801010;
    *(vu0_q *)&q.v[0] = *(vu0_q *)&q.v[2];
    *(vu0_q *)&q.v[1] = *(vu0_q *)&q.v[3];
    vec_add_ba(&q.v[2], &q.v[2], &c);
    vec_add_ab(&q.v[3], &q.v[3], &c);
    func_003D2DA0(&q, 0, 0);
    func_003D93B0(&q, 0x29, 1, 0x80);
    q.col[1] = c0;
    q.col[0] = c0;
    q.col[3] = c1;
    q.col[2] = c1;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    func_0038CF68(&f, &f, 0.2f);
    {
        vu0_q x, y, r, s, u;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(s) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("sqc2 %1, %0" : "=m"(q.v[0]) : "j"(r));
        __asm__("lqc2 %0, %1" : "=j"(r) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("sqc2 %1, %0" : "=m"(g) : "j"(r));
        __asm__("lqc2 %0, %1" : "=j"(u) : "m"(f));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(s) : "j"(s), "j"(u));
        __asm__("sqc2 %1, %0" : "=m"(q.v[1]) : "j"(s));
        __asm__("lqc2 %0, %1" : "=j"(s) : "m"(g));
        __asm__("lqc2 %0, %1" : "=j"(u) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(u) : "j"(s), "j"(u));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(u));
    }
    vec_add_ba(&d, &d, &c);
    vec_add_ab(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    q.col[1] = c0;
    q.col[3] = c1;
    q.col[0] = c0;
    q.col[2] = c1;
    func_0038CF68(&f, &f, 0.4f);
    func_0038CF68(&a, t, -0.1f);
    {
        vu0_q x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_v4 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(r) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(r));
        __asm__("sqc2 %1, %0" : "=m"(q.v[0]) : "j"(y));
    }
    vec_sub_ba(&q.v[1], &a, &f);
    vec_add_ab(&d, &a, &c);
    vec_add_ba(&d, &d, &c);
    vec_add_ab(&q.v[2], &d, &f);
    vec_sub_ab(&q.v[3], &d, &f);
    func_003D2DA0(&q, 0, 0);
    func_003D9508(o + 0x10, 0x13, 0x60804020, 1, 0.3f, 0.08f, func_00382538());
}
