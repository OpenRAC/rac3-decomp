/* PAL near miss (sonnet-b30-j3d): a three-state path-follower moby (state 0 loads the waypoint path D_L19_0021D500[w0] and the first two points, state 2 releases
 * the sound slot, state 1 steps to the next point, keeps a sound slot via func_003A52A0, calls the particle emitter func_L01_0046B458 twice with the rope ends
 * and runs func_L03_00433C70), the same tail as the matched func_L19_00323000 (take its externs). 6 raw words differ with the file's own line (S mode, @ps2as,
 * `check.py --no-context --mode S --as ps2as`), ALL of them registers, none structural (mnemonic and register-masked counts are 0): in state 1's entry
 * address `lw a1, 0x5c($s2)` (the index) is $v0 in ours, `lw v0, 0x54($s2); sll a1, a1, 4; addu a2, a1, v0` are `lw a2; sll v0; addu a2, a2, v0`, and the later
 * `lq v0, 0x20($a1)` reads through the copy `move $a1, $a2` (passed here as a second argument of func_003C7DD8: an approximation, see the nm10 notes below) where ours reads through $a2. Needs the row
 * `func_L19_003CFC58 0 1 0` in config/levels/divs_nops.txt (not committed: the function is still INCLUDE_ASM; without it the length is 299 words, not 300).
 * What fixed the rest: the arm order of the last-point test (`if (w5c >= count - 1) { reset arm } else { ... }`: retail lays the reset arm out in line), the store order of
 * case 0 (`wb0, wb4, wb8, wbc`: the slot of the func_L01_0040C7A0 call holds the 0xB0 store), a pointer to the entry (`e = base + (w5c << 4)`) with 0x10 / 0x20 displacements,
 * func_003C7DD8 called with the entry as a second argument (prototype `(void *, void *)`: retail has the `move $a1, $a2`), the third store
 * read from the stored vector (`obj->pos = v->v80`) and one variable per use (`s` for the sound slot entry, `e` for the path entry).
 * Tried without effect (about 40 compiles, J3D): the shared `s` / a reassigned `e` (a global pseudo: the slot entry then takes a1), a copy `f = e`, block-scoped e / i, i / p locals in
 * both orders, product-first address sums (`(i << 4) + base`, `i * 16 + base`: 9 words), three declaration orders of s / e, the three stores in all 6 orders and both chain orders, 24 orders of the four case-0 stores (only `0 4 8 c` is right).
 *
 * sonnet-b30-nm10 (about 45 more compiles), still 6 raw words:
 * - func_003C7DD8 is HANDWRITTEN (asm/handwritten/func_003C7DD8.s): it reads only $a0 and uses $a1 as its own scratch, and every other caller (the matched sibling func_L19_00323000 too) declares it
 *   `(void *)`. So retail's `move $a1, $a2` is NOT an argument move but a compiler copy of the entry pointer, and the `(void *, void *)` prototype / `func_003C7DD8(obj, e)` of this draft is only an
 *   approximation that reproduces the word and its place. With the one-argument call and the same C the copy is missing (299 words, 7 raw words).
 * - Retail at the allocator (inferred from the final code): index I = $a1 (S = I << 4 tied in $a1), path B = $v0, E = S + B in $a2 with the operand ORDER (S, B) (`addu $a2, $a1, $v0`; ours is (B, S)), first quad p0 through E,
 *   `move $a1, $a2` (Q = E), second quad p1 through Q. E and Q overlap at local allocation, which is why E is not tied to S or B. The two-argument draft has the same instruction order and E in $a2
 *   (the hard register a1 of the argument keeps E out of it); only the base of the second `lq` (a2, retail a1) and the I / B registers differ.
 * - Natural `v->w54->pts[v->w5c]` / `pts[v->w5c + 1]` with the one-argument call puts the index in $a1 as retail does but forms the second address separately (`addiu; sll; addu`): 140 raw words.
 *   Product-first sums give retail's (S, B) operand order but tie E to S ($v1) and move p0 to $a2: 9 raw words, so that order alone is not the lever.
 * - No copy appears with: `f = e` read for the second quad (cse / cprop fold it, with or without `e` re-assigned in the tail), two pointers computed from the same expression in a then-arm
 *   (the arm joins the EBB of its single predecessor), the NM5/NM7 order (first quad through the anonymous address, then `e = ...`, second quad through `e`, with one or two arguments),
 *   a three-argument call, `-fno-gcse`, and about 30 toy shapes (inline helpers with pointer parameters, post-increment, `p + 1`, a two-iteration loop, 32-byte struct copies, typed index locals).
 * - gcse of this draft: `PRE GCSE ... 0 substs`. Retail's copy needs a second computation of the entry address in ANOTHER extended basic block (a label with two predecessors between the two quad
 *   reads) that vanishes before the final code (reaching registers are probably never copy-propagated: recalled from gcse.c, not verified). No plain C with such a boundary and no visible branch found.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L19_003CFC58 */
typedef struct {
    s32 count;
    u8 pad4[0xC];
    vu0_v4 pts[1];
} Path_003CFC58;

typedef struct {
    s32 w0;
    u8 pad4[0x1C];
    s32 w20;
    f32 f24;
    f32 f28;
    u8 b2C;
    u8 b2D;
    u8 b2E;
    u8 b2F;
    u8 pad30[0x24];
    Path_003CFC58 *w54;
    f32 f58;
    s32 w5c;
    s32 w60;
    s32 w64;
    u8 pad68[8];
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    vu0_v4 va0;
    s32 wb0;
    s32 wb4;
    s32 wb8;
    s32 wbc;
} V_003CFC58;

extern Path_003CFC58 *D_L19_0021D500[];
extern u8 D_001A30B0[];
extern u8 D_L19_001D66F0[8];
extern s32 D_00142668[];
extern u8 *D_L19_001E8E58[];
extern char D_L19_001D64E0[] __attribute__((section(".sdata")));
extern void func_003C2880(void *);
extern void func_003C7DD8(void *, void *);
extern void func_L01_0040C7A0(void *, void *);
extern void func_L01_0040C8A0(void *, void *);
extern s32 func_L01_0040E050(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_L01_00404A10(void *, void *);
extern void func_L19_003D0108(void *arg0);
extern s32 func_L19_003D0130(s32 a);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);

void func_L19_003CFC58(u8 *obj) {
    V_003CFC58 *v = *(V_003CFC58 **)(obj + 0x68);
    u8 *s;
    u8 *e;

    switch (obj[0x20]) {
    case 0:
        if (v->w0 == -1) {
            func_003C2880(obj);
            return;
        }
        obj[0x31] = 0;
        *(u16 *)(obj + 0x34) |= 1;
        v->w5c = 0;
        v->w54 = D_L19_0021D500[v->w0];
        v->v90 = v->v70 = v->w54->pts[0];
        v->va0 = v->v80 = v->w54->pts[1];
        v->wb0 = -1;
        v->wb4 = -1;
        v->wb8 = (v->b2F << 24) | (v->b2E << 16) | (v->b2D << 8) | v->b2C;
        v->wbc = (v->b2F << 24) | (v->b2E << 16) | (v->b2D << 8) | v->b2C;
        func_L01_0040C7A0(&v->v90, D_L19_001D64E0);
        if (v->w20 == 0) {
            v->f58 = (v->f28 * 5.0f + 2.0f) / 6.0f;
            func_L01_004450F0(obj, 2, -1);
        } else {
            v->f58 = (v->f24 * 5.0f + 2.0f) / 6.0f;
            func_L01_004450F0(obj, 1, -1);
        }
        return;
    case 2:
        if (v->w60 != -1) {
            s = D_001A30B0 + (v->w60 << 7);
            if (*(u8 **)(s + 0xDC) == obj && s[0xD0] != 0) {
                func_003A4F28(v->w60);
            }
        }
        v->w60 = -1;
        if (func_L01_0040E050(&v->f58) != 0) {
            v->f58 = (v->f24 * 5.0f + 2.0f) / 6.0f;
            func_L01_004450F0(obj, 1, -1);
        }
        return;
    case 1:
        if (func_L01_0040E050(&v->f58) != 0) {
            v->w5c = v->w5c + 1;
            if (v->w5c >= v->w54->count - 1) {
                v->w5c = 0;
                v->f58 = (v->f28 * 5.0f + 2.0f) / 6.0f;
                func_L01_004450F0(obj, 2, -1);
            } else {
                v->f58 = (v->f24 * 5.0f + 2.0f) / 6.0f;
            }
            e = (u8 *)v->w54 + (v->w5c << 4);
            v->v90 = v->v70 = *(vu0_v4 *)(e + 0x10);
            v->va0 = v->v80 = *(vu0_v4 *)(e + 0x20);
            *(vu0_v4 *)(obj + 0x10) = v->v80;
            func_003C7DD8(obj, e);
            if (obj[0x20] == 2) {
                return;
            }
        }
        if (v->w60 == -1 || (s = D_001A30B0 + (v->w60 << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0) {
            v->w60 = func_003A52A0(0, 4, obj);
        }
        func_L01_0046B458((u8 *)&v->v70, 1, 1.0f, 1.0f, (v->b2F << 24) | (v->b2E << 16) | (v->b2D << 8) | v->b2C,
                          0, 0, D_L19_001D66F0, 0.0f, 0);
        func_L01_0046B458((u8 *)&v->v80, 1, 1.0f, 1.0f, (v->b2F << 24) | (v->b2E << 16) | (v->b2D << 8) | v->b2C,
                          0, 0, D_L19_001D66F0, 0.0f, 0);
        func_L01_0040C8A0(&v->v90, D_L19_001D64E0);
        func_L01_00404A10(func_L19_003D0108, obj);
        if (func_L03_00433C70(obj, &v->v70, &v->v80, 0x410001, 0, 1, 0,
                              (f32)func_L19_003D0130(D_00142668[0] / 5 + 1), 1.0f) != 0
            && D_L19_001E8E58[0] != 0 && v->w64 <= 0) {
            func_003A52A0(1, 0, obj);
            v->w64 = 0x11;
        }
        break;
    }
}
/* localdecomp:end func_L19_003CFC58 */
