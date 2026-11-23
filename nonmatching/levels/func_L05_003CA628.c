/* func_L05_003CA628 (levels 05, 11, 17): near miss. PAL port (2026-11-20) of the NTSC-U draft of func_L05_003C8498, reworked
 * 2026-11-21 (task 2785) and 2026-11-22 (task 2834). 16 differences (tools/check.py) at level 05, 17 at level 11, 16 at level 17,
 * with the file's committed line (`-mvu0-use-vf0-vf2 ... @ps2as`) and a divs_nops.txt row `func_L05_003CA628 2 2` (not committed:
 * 93 differences at level 05 without it). --version us: 92 (NTSC-U's code differs).
 * Form (2026-11-22, r3-44): no VU0 value crosses between separate asm blocks through the registers alone. The first vadd is the
 * include/vu0.h helper vec_add_ab; the branch loads its two operands into real "j" variables (a, b) in each arm, and one vadd and
 * one sqc2 follow the branch: the inline VU0 j-form (PROVISIONAL, VU0 j-constraint form; r3-34: a match would need that comment,
 * its own commit and a PR flag). func_0038CF68 keeps the file's out-parameter prototype (the func_L05_003CA8F0 block declares it
 * `void func_0038CF68(void *, void *, f32)`), so there is no by-value prototype any more.
 * Still differs (16 words at level 05):
 *  (1) The layout of `old` and `dest`: `dest` has to be the first local declared, so it is at sp+0 and `old` at sp+0x10 (retail:
 *      old at sp+0, dest at sp+0x10). 3 words: the sq of `old`, and `move $a0/$a1, $sp` for retail's `addiu $a0/$a1, $sp, 0x10`.
 *      With retail's order (old first) gcse makes &dest at sp+0x10 partially redundant (the else arm's func_0038CF68 argument,
 *      then the func_003D3CB0 argument) and keeps it in a saved register: 168 differences (frame 0xa0, $s5 saved). Five wordings
 *      give those same 168: the out-parameter call, a by-value func_0038CF68 into `dest`, a by-value call as the lqc2's "m"
 *      operand, a `vu0_v4 *pd = &dest` pointer for all three uses, and a pointer local in the else arm only. A block-scoped
 *      temporary for the else arm's call (at sp+0x50, 32 differences) or `dest` and `work` declared in a nested block after the
 *      branch (dest at sp+0x20, 31) avoid gcse, but not at retail's offsets. Only a by-value temporary shares retail's slot with
 *      `dest`, and then gcse is back (fact #46726).
 *  (2) The argument setup of the func_L01_00446760 call (13 words): ours puts `addiu $s1, $sp, 0x20` (&work) before the
 *      `sqc2 vf1` of the vadd and `lui $a3, %hi(D_L05_001D66B0)` first; retail has the sqc2, then &work, `lwc1 $f12`, `lui $a2`,
 *      the moves, then the `lui`/`addiu $a3`. The registers are now retail's ($s1 &work, $s0/$s4 obj+0x10).
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
    vu0_q a, b, r;

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
            /* PROVISIONAL, VU0 j-constraint form */
            if (func_0038CEA8(sub) > *(f32 *)(sub + 0x20)) {
                __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)sub));
                __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(vu0_v4 *)(obj + 0x10)));
            } else {
                func_0038CF68(&dest, sub, *(f32 *)(sub + 0x20));
                __asm__("lqc2 %0, %1" : "=j"(a) : "m"(dest));
                __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(vu0_v4 *)(obj + 0x10)));
            }
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(dest) : "j"(r));
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
