/* PAL near miss (b29 n2 and nm1, from the b22 nm20-b draft 3, 2026-11-20): 7 instructions differ of 555 when aligned (check.py says
 * 127 because the colour loop is one instruction longer here and shifts the rest). Needs `-mvu0-use-vf0-vf2` on the file's text_parts
 * line (without it the vec_add helpers fail with "vf17 was spilled"); measured with
 * `check.py FILE func_L16_003E7350 --flags=-mvu0-use-vf0-vf2` (the file's other block, func_L16_003E7C00, still matches with it).
 *
 * Still different:
 *  (a) function entry: retail `bne $v1,$v0; lwc1 $f1,D44($gp)` in the delay slot, ours `bnel; lwc1 $f0,0x18($s1)` and the D44
 *      load later (`f32 d = D44;` before the `if` fixes it but swaps three loads in the else head: net 0). reorg fills the slot from
 *      the target thread, so retail's else head starts with the D44 load and then the size load; ours the other way round;
 *  (b) the two `lui`s before the k loop (`lui $s3,1` / `lui $v0,0x2a`) are swapped (hoisted insns, tie broken by uid);
 *  (c) the colour loop (m, 32 iterations): retail keeps `addiu $t3,$t3,-1` next to the `bgez` at the loop end, sched1's interblock
 *      motion moves it to the loop head (into `bc1f`'s slot) in ours, which is also where the one extra `nop` before the final j loop
 *      comes from. `-dS -fsched-verbose-3` lists the regions: ours has region 0 = the colour loop (blocks 26-29) and region 1 = the
 *      final j loop (blocks 32-36); retail behaves as if only the j loop were a region.
 *
 * What was ruled out for (c) (b29 n2 and nm1, about 120 compiles):
 *  - Control-flow shape of the colour loop (nm1, 40 compiles): `for`, `while`, `do-while`, `for (;;)` with `break`, `continue` in either
 *    arm, the decrement inside the test (`while (m-- > 0)`, `while (--m >= 0)`, `for (m = 32; m-- > 0;)`), inverted test or arms, the
 *    counter stepped in each arm: every form that keeps the count-down (bgez) loop is the same 4-block diamond and the same region 0.
 *    loop.c only reverses a loop whose biv has ONE increment (check_dbra_loop: biv_count == 1), so a two-latch loop (each arm with its
 *    own decrement, which sched1 could not hoist because the counter is live in the other arm) gives the forward `slti` form, not
 *    retail's `bgez`. Counting the other way (`m++` in both arms) is 30 aligned.
 *  - Region size: find_rgns drops a loop over MAX_RGN_INSNS (100). Ours is about 75 real insns at sched1 time: 1 to 4 extra distinct
 *    stores keep region 0, 5 remove it. Retail would need about 25 more real insns that vanish later. Neither 24 dead local assignments
 *    (deleted before sched1), nor extra blank/`;` lines or putting each arm on one line (source line notes), nor 9 repeated identical
 *    stores (cse keeps them: the `lw first` between them stops it) changes the region. No source change adds insns that disappear.
 *  - do-while and count-down forms (31..0, 32..1), counter types, `continue`, else-less forms: same bytes (b22 and b29 n2).
 *  - Scheduler lab (nm1; toy functions compiled with `-dS -fsched-verbose-3`, tools in sonnet-b29-nm1-tools): a diamond loop is a region
 *    only in some function shapes, and when it is not, usually NO loop of the function is. Regions form for the last loop of a function,
 *    for loops inside a constant-bound outer loop, and for several loops one after another; they all vanish when straight-line code
 *    (a store, a call) follows the last loop, when an early `return` precedes the loop, when the loop sits in an `if` that ends the
 *    function, or when the outer loop's bound is a variable. In THIS function, adding one store or call after the final j loop removes
 *    all regions (raw 127 -> 41: the colour loop is exact, the j loop loses retail's `addiu $a1,$gp,0x2cb0` at its head), the same as
 *    `-fno-sched-interblock`, which seven level files already use (L01_00340670.c, L01_00344A88.c, L01_00344C70.c, L01_003586F8.c,
 *    L03_003C81D0.c, L07_003A46C8.c, L11_003AE1B0.c): with it the draft is 20 raw / 10 aligned. Left then: (a), (b), the register of
 *    the `lw 0x50($sp)` before the first lqc2 ($a1 instead of $v0) and the j loop's `la` (retail hoists it into the loop head; the
 *    pointer-local tricks `g = &D5560` before the `if` (function-level, block-local, reassigned in the else arm) give 10 to 26
 *    aligned). So the colour loop alone is not region-free in retail while the j loop is a region, unless retail's j-loop `la` comes
 *    from the source order instead and retail is region-free as a whole; nothing found that makes the whole function region-free in
 *    plain C without extra code.
 *  - The NTSC-U twin (`differs`) has the same shape: decrement at the bottom, D44 load in the `bne` slot, same else-head order.
 * The L20 functions are not twins of this one (functions.tsv: different hash and size). */
/* localdecomp:start func_L16_003E7350 */
#include "vu0.h"

typedef struct {
    u8 pad0[0xC];
    f32 f0C;
    vu0_v4 pos;
    s32 c20;
    s32 c24;
    s32 c28;
    s32 c2C;
    u8 pad30[0xB0 - 0x30];
} E_003E7C00;

extern E_003E7C00 D_002A3830[];

typedef struct {
    f32 f0;
    u8 pad4[0x14];
    f32 size;
    s32 first;
} St_003E7C00;

extern s32 D_L16_001DF560;
__asm__(".extern D_L16_001DF560, 4");
extern s32 D_L16_001DF5A0;
__asm__(".extern D_L16_001DF5A0, 4");
extern f32 D_L16_001DF4F4; __asm__(".extern D_L16_001DF4F4, 4");
extern s32 D_L16_001DF4F8; __asm__(".extern D_L16_001DF4F8, 4");
extern s32 D_L16_001DF4FC; __asm__(".extern D_L16_001DF4FC, 4");
extern s32 D_L16_001DF500; __asm__(".extern D_L16_001DF500, 4");
extern s32 D_L16_001DF504; __asm__(".extern D_L16_001DF504, 4");
extern s32 D_L16_001DF508; __asm__(".extern D_L16_001DF508, 4");
extern f32 D_L16_001DF510; __asm__(".extern D_L16_001DF510, 4");
extern f32 D_L16_001DF514; __asm__(".extern D_L16_001DF514, 4");
extern f32 D_L16_001DF518; __asm__(".extern D_L16_001DF518, 4");
extern f32 D_L16_001DF51C; __asm__(".extern D_L16_001DF51C, 4");
extern f32 D_L16_001DF520; __asm__(".extern D_L16_001DF520, 4");
extern s32 D_L16_001DF524; __asm__(".extern D_L16_001DF524, 4");
extern f32 D_L16_001DF528; __asm__(".extern D_L16_001DF528, 4");
extern f32 D_L16_001DF52C; __asm__(".extern D_L16_001DF52C, 4");
extern f32 D_L16_001DF530; __asm__(".extern D_L16_001DF530, 4");
extern f32 D_L16_001DF534; __asm__(".extern D_L16_001DF534, 4");
extern f32 D_L16_001DF538; __asm__(".extern D_L16_001DF538, 4");
extern vu0_v4 D_001E98E0;

extern void func_L01_0040C7A0(void *, void *);
extern void func_L01_0040C8A0(void *, void *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void polar_003E7350(vu0_v4 *v, f32 ang, f32 r) {
    v->x = func_0038D098(ang) * r;
    v->y = func_0038D0B0(ang) * r;
    v->z = 0.0f;
}

void func_L16_003E7350(u8 *self, void *vec, s32 init) {
    St_003E7C00 *st = *(St_003E7C00 **)(self + 0x68);
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 p;
    vu0_v4 c;
    s32 i, n, j, k, m, z, flag, fl;
    vu0_v4 *pp;
    f32 a, b, lim, sz, dz;

    if (self[0x20] == 2) {
        if (init) {
            for (i = 0; i < 32; i = n) {
                n = i + 1;
                func_L01_0040C7A0(&D_002A3830[st->first + i], &D_L16_001DF560);
                D_002A3830[st->first + i].f0C = func_0038DB48((f32)i * 3.1415927f * 2.0f * 0.03125f);
                D_002A3830[st->first + i].pos.w = func_0038DB48((f32)n * 3.1415927f * 2.0f * 0.03125f);
            }
        }
        for (j = 0; j < 32; j++) {
            a = D_002A3830[st->first + j].f0C;
            b = D_002A3830[st->first + j].pos.w;
            v.x = func_0038D098(a) * st->size;
            v.y = func_0038D0B0(a) * st->size;
            v.z = 0.0f;
            vec_add_ab(&D_002A3830[st->first + j], self + 0x10, &v);
            v.x = func_0038D098(b) * st->size;
            v.y = func_0038D0B0(b) * st->size;
            v.z = 0.0f;
            vec_add_ab(&D_002A3830[st->first + j].pos, self + 0x10, &v);
            D_002A3830[st->first + j].f0C = a;
            D_002A3830[st->first + j].pos.w = b;
        }
    } else {
        sz = st->size;
        lim = D_L16_001DF4F4 * sz;
        lim = lim * lim;
        for (i = 0; i < 32; i++) {
            flag = 0;
            if (D_002A3830[st->first + i].f0C <= 0.0f) {
                vec_add_ab(&D_002A3830[st->first + i], &D_002A3830[st->first + i], vec);
                vec_add_ba(&D_002A3830[st->first + i].pos, &D_002A3830[st->first + i].pos, (u8 *)st + 0x30);
                if (lim < func_L01_0040E570(&D_002A3830[st->first + i], &D_002A3830[st->first + i].pos))
                    flag = 1;
            } else {
                vec_add_ab(&D_002A3830[st->first + i], &D_002A3830[st->first + i], vec);
                vec_add_ba(&D_002A3830[st->first + i].pos, &D_002A3830[st->first + i].pos, vec);
                D_002A3830[st->first + i].f0C -= 1.0f;
                if (D_002A3830[st->first + i].f0C <= 0.0f)
                    flag = 1;
            }
            if (init || flag) {
                b = func_00382538();
                a = func_00382538();
                func_00382760(&v, st->size * 0.5f * st->f0, b, a);
                vec_add_ab(&v, &v, self + 0x10);
                func_00382760(&w, D_L16_001DF4F4 * st->size * st->f0, b, a);
                vec_add_ab(&w, &w, &v);
                z = func_00382468(D_L16_001DF508) == 0;
                if (z && func_003D3CB0(&v, &w, 0, 0, 0)) {
                    *(vu0_v4 *)&D_002A3830[st->first + i] = v;
                    pp = &D_002A3830[st->first + i].pos;
                    *pp = D_001E98E0;
                    D_002A3830[st->first + i].f0C = 0.0f;
                    func_L01_0040C7A0(&D_002A3830[st->first + i], &D_L16_001DF560);
                    for (k = 0; k < D_L16_001DF524; k++) {
                        fl = 0x1003c;
                        a = func_00382538();
                        b = func_003824E0(D_L16_001DF528, D_L16_001DF52C);
                        polar_003E7350(&p, a, b);
                        p.z = func_003824E0(D_L16_001DF530, D_L16_001DF534);
                        p.w = D_L16_001DF538;
                        dz = 0.086f;
                        c = p;
                        c.z -= dz;
                        func_L01_00463378(&D_002A3830[st->first + i].pos, &p, &c,
                                          func_0038DBD8(0x80081620, 0x80102540, func_003824E0(0.0f, 1.0f)),
                                          func_0038DBD8(0x60081620, 0x60102540, func_003824E0(0.0f, 1.0f)),
                                          8, 0x1d, 6, fl);
                    }
                } else {
                    *(vu0_v4 *)&D_002A3830[st->first + i] = v;
                    func_003C4098(&D_002A3830[st->first + i].pos, &v, &w, func_003824E0(D_L16_001DF510, D_L16_001DF514) + (z ? D_L16_001DF518 : 0.0f));
                    D_002A3830[st->first + i].f0C = func_003824E0(D_L16_001DF51C, D_L16_001DF520);
                    func_L01_0040C7A0(&D_002A3830[st->first + i], &D_L16_001DF5A0);
                }
                for (m = 0; m < 32; m++) {
                    if (st->size < 0.5f) {
                        D_002A3830[st->first + i].c20 = D_L16_001DF500;
                        D_002A3830[st->first + i].c24 = D_L16_001DF500;
                        D_002A3830[st->first + i].c24 &= 0xFFFFFF;
                        D_002A3830[st->first + i].c28 = D_L16_001DF504;
                        D_002A3830[st->first + i].c2C = D_L16_001DF504;
                        D_002A3830[st->first + i].c2C &= 0xFFFFFF;
                    } else {
                        D_002A3830[st->first + i].c20 = D_L16_001DF4F8;
                        D_002A3830[st->first + i].c24 = D_L16_001DF4F8;
                        D_002A3830[st->first + i].c24 &= 0xFFFFFF;
                        D_002A3830[st->first + i].c28 = D_L16_001DF4FC;
                        D_002A3830[st->first + i].c2C = D_L16_001DF4FC;
                        D_002A3830[st->first + i].c2C &= 0xFFFFFF;
                    }
                }
            }
        }
    }
    for (j = 0; j < 32; j++) {
        if (self[0x20] == 2 || D_002A3830[st->first + j].f0C <= 0.0f)
            func_L01_0040C8A0(&D_002A3830[st->first + j], &D_L16_001DF560);
        else
            func_L01_0040C8A0(&D_002A3830[st->first + j], &D_L16_001DF5A0);
    }
}
/* localdecomp:end func_L16_003E7350 */
