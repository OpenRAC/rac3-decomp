/* func_L05_003CA628 (levels 05, 11, 17): near miss. PAL port (2026-11-20) of the NTSC-U draft of func_L05_003C8498, reworked
 * 2026-11-21 (task 2785): 24 instructions differ after alignment at L05 (18 raw words; 30 / 29 aligned at L11 / L17), down from 31.
 * Needs `@ps2as` on L05_003CA628.c's line (the inline `lui`/`ori`/`mtc1` float constants and no `mfc1` hazard nop; the default
 * assembler gives 38 aligned) and a divs_nops.txt row `func_L05_003CA628 2 2`; neither is committed. `-mvu0-use-vf0-vf2` is not
 * needed (24 with or without it): the VU0 code is explicit-register blocks, not the j-form.
 * What changed from the 2026-11-20 draft:
 *  - func_0038CF68 declared as returning a 16-byte vector by value (`dest = func_0038CF68(sub, r)`, the hidden result pointer is
 *    $a0 under EABI, so the call is the same) and `old`/`dest` as separate struct-typed locals. This removes the saved register
 *    that held &dest (the frame is 0x90 and the saved registers $s0-$s4 are retail's). A reordered/EABI-equivalent prototype:
 *    flag it (r3-11) if this is ever taken.
 *  - The VU0 code as explicit-register volatile blocks: the two branches each load vf1/vf2 (retail's order and registers) and one
 *    shared block adds and stores. The blocks share vf1/vf2 across the branch through the registers alone, which is between
 *    "one block per VU0 sequence" and a violation of it: watcher-2's call (r3-12) if this is ever taken.
 * Still differs: (1) `dest` must be the first local declared to avoid the pseudo for &dest, so it is at sp+0 and `old` at sp+0x10;
 * retail has old at sp+0 and dest at sp+0x10. Declaring `old` first (retail's layout) brings the saved register for &dest back
 * (43 aligned): gcse makes &dest at sp+0x10 partially redundant (else branch's argument, then the collision call), where at sp+0
 * the address is $sp itself and is not a gcse candidate. (2) Register roles of the func_L01_00446760 arguments: ours keeps &work
 * in $s0 and obj+0x10 in $s1/$s4 and schedules the argument moves after the `lui`s; retail has &work in $s1, obj+0x10 in $s0 then
 * $s4, and the moves before the `lui $a3`. Tried without effect: -fno-cse-follow-jumps/-fno-cse-skip-blocks (diagnostics only),
 * the out-parameter call with separate locals (43), u128 locals (the dead `old` copy is deleted).
 */
#include "common.h"

/* localdecomp:start func_L05_003CA628 */
typedef int u128_003CA628 __attribute__((mode(TI)));
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V_003CA628;

extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern V_003CA628 func_0038CF68(void *, f32);
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
extern u128_003CA628 D_L05_001EA6E0[];

void func_L05_003CA628(u8 *obj) {
    V_003CA628 dest;
    V_003CA628 old;
    u128_003CA628 work[3];
    u8 *sub;
    u8 *hit;
    s32 result;
    f32 len;

    old = *(V_003CA628 *)(obj + 0x10);
    sub = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        if (func_L01_004561B8(obj) == 0) {
            __asm__ __volatile__("lqc2 $vf1, 0x10(%0)\n"
                                 "lqc2 $vf2, 0(%1)\n"
                                 "vadd.xyz $vf1, $vf1, $vf2\n"
                                 "sqc2 $vf1, 0x10(%0)\n"
                                 : : "r"(obj), "r"(sub) : "vf1", "vf2", "memory");
        }
        if (func_0038CAD0(sub + 0x24)) {
            func_003C2880(obj);
            return;
        }
        if (*(s32 *)(sub + 0x30) == 0) {
            if (func_0038CEA8(sub) > *(f32 *)(sub + 0x20)) {
                __asm__ __volatile__("lqc2 $vf2, 0(%0)\n"
                                     "lqc2 $vf1, 0x10(%1)\n"
                                     : : "r"(sub), "r"(obj) : "vf1", "vf2");
            } else {
                dest = func_0038CF68(sub, *(f32 *)(sub + 0x20));
                __asm__ __volatile__("lqc2 $vf1, %0\n"
                                     "lqc2 $vf2, 0x10(%1)\n"
                                     : : "m"(dest), "r"(obj) : "vf1", "vf2");
            }
            __asm__ __volatile__("vadd.xyz $vf1, $vf1, $vf2\n"
                                 "sqc2 $vf1, %0\n"
                                 : "=m"(dest) : : "vf1");
            func_L01_00446760(work, obj, 0x10001, D_L05_001D66B0, *(f32 *)(sub + 0x34));
            func_L01_004CB320();
            result = func_003D3CB0(obj + 0x10, &dest, 16, obj, work);
            if (result && (hit = D_L05_001EA6D8[0]) && *(s16 *)(hit + 0xAA) == 0x186D && hit[0x20] != 2 && hit[0x20] != 5) {
                hit[0x20] = 4;
            }
            func_L01_004CB358();
            if (result) {
                *(s32 *)(sub + 0x30) = 1;
                *(u128_003CA628 *)(sub + 0x10) = D_L05_001EA6E0[0];
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
