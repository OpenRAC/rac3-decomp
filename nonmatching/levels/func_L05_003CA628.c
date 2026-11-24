/* func_L05_003CA628 (levels 05, 11, 17): near miss. PAL port (2026-11-20) of the NTSC-U draft of func_L05_003C8498, reworked
 * 2026-11-21 (task 2785), 2026-11-22 (task 2834) and 2026-11-22 (task 2935). 18 differences (tools/check.py) at level 05, 19 at level 11,
 * 18 at level 17, with the file's committed line (`-mvu0-use-vf0-vf2 ... @ps2as`) and a divs_nops.txt row `func_L05_003CA628 2 2`
 * (not committed: 95 differences at levels 05, 11 and 17 without it).
 * Form (task 2935, r3-44): only include/vu0.h helpers, no inline VU0 asm, so no VU0 value crosses between asm blocks. Retail's
 * single vadd.xyz + sqc2 after the branch is gcc's cross-jumping of the two arms' identical tails: both arms call vec_add_ab
 * (`vec_add_ab(&dest, obj + 0x10, sub)` and, after func_0038CF68, `vec_add_ab(&dest, &dest, obj + 0x10)`), and an inline
 * function's asm statements carry the header's line, so the two vadd/sqc2 pairs are equal insns and become one tail. The
 * scheduler swaps the then-arm's two lqc2 (sub into vf2 first), as retail has it. Both arms with vec_add_ba also cross-jump, but
 * from the obj+0x10 load on (140); vec_add_ba then vec_add_ab do not cross-jump (134). Because the arms end in their own blocks,
 * sched1 no longer moves the &work setup above the sqc2.
 * The previous draft (task 2834: one inline j-form vadd/sqc2 after the branch, fed by "j" variables loaded in each arm) was 16
 * with the same row, but #2918 Q5 read its j values living across the branch as VU0 state between asm blocks (r3-44).
 * Still differs (18 words at level 05):
 *  (1) The layout of `old` and `dest` (6 words): `dest` has to be the first local declared, so it is at sp+0 and `old` at
 *      sp+0x10 (retail: old at sp+0, a dead store, dest at sp+0x10): the sq of `old`, `move $a0/$a1, $sp` for retail's
 *      `addiu $a0/$a1, $sp, 0x10`, and the lqc2/sqc2 offsets of dest. With retail's order (old first) gcse makes &dest at
 *      sp+0x10 partially redundant and keeps it in a saved register: 168 (frame 0xa0, $s5 saved), also in this form (fact #46726).
 *  (2) The func_L01_00446760 call (12 words): retail has `addiu $s1, $sp, 0x20` (&work), `lwc1 $f12`, `lui $a2`, the moves,
 *      `ori $a2`, then `lui`/`addiu $a3` and `addiu $s0, $s2, 0x10` in the jal's delay slot; ours puts `lui $a3` first and
 *      `ori $a2` in the slot, and swaps $s0/$s1 (&work / obj+0x10). Unchanged (18) with a named f32 local for the sub+0x34
 *      argument, `&work[0]` / `&D_L05_001D66B0[0]`, a `(u8 *)obj + 0x10` cast, and `work` declared vu0_v4[3].
 * 2026-11-23 retry (task 2984, upstream 59c6db4f): still 18 at level 05 (19 at 11, 18 at 17, 18 with --no-context) with the row.
 *  (1) gcc's gcse dump (`--flags "-dG"`) shows where the 168 comes from: with `old` first, the address of `dest` (`at` + 16)
 *      is computed into a pseudo for the else arm's func_0038CF68 call and for func_003D3CB0, and PRE copies it to a new
 *      register at the end of both arms ("PRE/HOIST: end of bb 7 / bb 8 ... expression 11"), which then lives across the calls
 *      in $s5. With `dest` first its address is $sp itself and there is no expression to move. `dest` and `work` declared in
 *      the `*(s32 *)(sub + 0x30) == 0` block (retail's offsets) give the same 168.
 *  (2) In ours `obj + 0x10` for func_003D3CB0 is created after the func_L01_004CB320 call and sched1 lifts it over that call
 *      only; retail has it in func_L01_00446760's delay slot. A `u8 *pos = obj + 0x10;` set before or after the
 *      func_L01_00446760 call and passed to func_003D3CB0 gives the same 18 (sched1 moves it back below the call); `pos`
 *      also passed to func_0038CF00 gives 151; `pos` set at the top of the block gives 159. The prototype
 *      `(void *, void *, s32, f32, void *)` used by other files (EABI-equivalent) gives the same 18 (168 with `old` first).
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003CA628 */
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L05_003CB090(void *);
extern void func_L05_003CAE70(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L05_003CA8F0(void *);
extern u8 D_L05_001D66B0[];
extern u8 *D_L05_001EA6D8[];
extern vu0_q D_L05_001EA6E0[];

void func_L05_003CA628(u8 *obj) {
    vu0_v4 dest;
    vu0_v4 old;
    vu0_q work[3];
    u8 *sub;
    u8 *hit;
    s32 result;
    f32 len;

    old = *(vu0_v4 *)(obj + 0x10);
    sub = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        if (func_L01_004561B8(obj) == 0) {
            vec_add_ab(obj + 0x10, obj + 0x10, sub);
        }
        if (func_0038CAD0(sub + 0x24)) {
            func_003C2880(obj);
            return;
        }
        if (*(s32 *)(sub + 0x30) == 0) {
            if (func_0038CEA8(sub) > *(f32 *)(sub + 0x20)) {
                vec_add_ab(&dest, obj + 0x10, sub);
            } else {
                func_0038CF68(&dest, sub, *(f32 *)(sub + 0x20));
                vec_add_ab(&dest, &dest, obj + 0x10);
            }
            func_L01_00446760(work, obj, 0x10001, D_L05_001D66B0, *(f32 *)(sub + 0x34));
            func_L01_004CB320();
            result = func_003D3CB0(obj + 0x10, &dest, 16, obj, work);
            if (result && (hit = D_L05_001EA6D8[0]) && *(s16 *)(hit + 0xAA) == 0x186D && hit[0x20] != 2 && hit[0x20] != 5) {
                hit[0x20] = 4;
            }
            func_L01_004CB358();
            if (result) {
                *(s32 *)(sub + 0x30) = 1;
                *(vu0_q *)(sub + 0x10) = D_L05_001EA6E0[0];
                len = func_0038CF00(obj + 0x10, sub + 0x10);
                len = len / func_0038CEA8(sub);
                *(s32 *)(sub + 0x24) = ((s32)len * 5 + 2) / 6;
                *(f32 *)(sub + 0x28) = 1.0f / (f32)*(s32 *)(sub + 0x24);
                if (*(u8 **)((u8 *)D_L05_001EA6E0 - 8) == 0) {
                    func_L05_003CB090(obj);
                } else {
                    func_L05_003CAE70(sub + 0x10);
                }
            }
        }
        func_L01_00404A10(func_L05_003CA8F0, obj);
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L05_003CA628 */
