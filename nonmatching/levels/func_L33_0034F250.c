/* PAL near miss (sonnet-b30-j3b): a particle's per-frame update (first frame: random direction and speed from the emitter's moby, then drift by the
 * emitter's velocity, size and colour fade, func_003C4088 lerp for the alpha). Plain C with the vu0.h helper vec_add_ab; typed P/Q structs (casts
 * `*(f32 *)(p + 0x10)` let the scheduler keep the $gp loads behind the stores: 37 -> 13 aligned in one edit). Needs the file line
 * `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as` (retail's lui/ori/mtc1 float constants: a cut of src/levels/33_vidcomic_2/L33_0034E8C0.c,
 * which has neither flag) and the row `func_L33_0034F250 0 2 2` in config/levels/divs_nops.txt (not committed: the function is still INCLUDE_ASM).
 * 16 raw words differ (10 aligned): (1) `move $a0, $sp` (the &v argument of func_L33_00344F88) sits after the first store (`swc1 $f0, 0x10($s0)`) in
 * retail, first in ours; (2) the 1.0f constant is $f5 and n+1 is $f4 in retail, the other way round in ours; (3) the last block's `lh q->h8` goes to $a1 in
 * retail, to $v1 in ours. Tried without effect: statement-order permutations of the join block (12), n/n+1 as separate variables and temporaries,
 * block-local n, call-argument locals, `(f32)n / ((f32)n + 1.0f)` (worse), the three orders of the final loads, declaration order of v and a (worse).
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L33_0034F250 */
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
} P_0034F250;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    u8 padC[2];
    u16 hE;
    u8 pad10[8];
    f32 f18;
    f32 f1C;
} Q_0034F250;

extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern f32 func_L03_0034B148(s32, f32);
extern f32 D_L33_001DD704;
__asm__(".extern D_L33_001DD704, 4");
extern f32 D_L33_001DD700;
__asm__(".extern D_L33_001DD700, 4");
extern f32 D_L33_001DD6F8;
__asm__(".extern D_L33_001DD6F8, 4");
extern s32 D_L33_001DD6C4;
__asm__(".extern D_L33_001DD6C4, 4");
extern s32 D_L33_001DD6C8;
__asm__(".extern D_L33_001DD6C8, 4");
extern s32 D_L33_001DD760;
__asm__(".extern D_L33_001DD760, 4");
extern f32 D_L33_001DD6E8;
__asm__(".extern D_L33_001DD6E8, 4");
extern f32 D_L33_001DD6EC;
__asm__(".extern D_L33_001DD6EC, 4");
extern f32 D_L33_001DD6D4;
__asm__(".extern D_L33_001DD6D4, 4");
extern f32 D_L33_001DD708;
__asm__(".extern D_L33_001DD708, 4");
extern f32 D_L33_001DD6D0;
__asm__(".extern D_L33_001DD6D0, 4");
extern f32 D_L33_001DD6CC;
__asm__(".extern D_L33_001DD6CC, 4");
extern f32 D_L33_001DD6E4;
__asm__(".extern D_L33_001DD6E4, 4");

void func_L33_0034F250(P_0034F250 *p, Q_0034F250 *q) {
    vu0_v4 v;
    vu0_v4 a;
    u8 *m;
    u8 *pv;
    s32 n;
    s32 on;
    s32 n2;

    if (q == 0) return;
    m = q->m;
    pv = *(u8 **)(m + 0x68);
    on = q->w4;
    if (m == 0) return;
    if (on == 0) return;

    if (q->hA & 1) {
        f32 ang1;
        f32 ang2;
        f32 s;

        ang1 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        s = func_003824E0(D_L33_001DD704, D_L33_001DD700);
        ang2 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        func_003C2F58(m, 1, &p->pos);
        a.x = func_0038D098(ang2) * D_L33_001DD6F8;
        a.z = func_0038D0B0(ang2) * D_L33_001DD6F8;
        a.y = 0.0f;
        vec_add_ab(&p->pos, &p->pos, &a);
        q->f18 = s * func_0038D098(ang1);
        q->f1C = s * func_0038D0B0(ang1);
        p->w4 = func_L30_0034DBA0(D_L33_001DD6C4, D_L33_001DD6C8);
        p->fC = func_003C4088(D_L33_001DD6E8, D_L33_001DD6EC, (f32)*(s32 *)(pv + 0xA8) / (f32)D_L33_001DD760);
    }

    p->pos.x += q->f18;
    q->f1C += D_L33_001DD6D4;
    p->pos.z += q->f1C;
    n = p->hA;
    p->fC *= 1.0f - D_L33_001DD708 * (1.0f - (f32)n / (f32)(n + 1));
    func_L33_00344F88(&v, p->w4);
    n2 = p->hA;
    v.x *= D_L33_001DD6D0;
    v.y *= D_L33_001DD6CC;
    v.w *= (f32)n2 / (f32)(n2 + 1);
    func_L33_003453C8(&p->w4, &v);
    {
        f32 lo = (f32)(q->hE & 0xFF);
        f32 hi = (f32)(q->hE >> 8);
        f32 hi2 = D_L33_001DD6E4 * (f32)q->h8 * hi * 0.00390625f;
        p->b8 = (s32)func_003C4088(lo, lo + hi2, func_L03_0034B148(p->hA, 0.0f));
    }
}
/* localdecomp:end func_L33_0034F250 */
