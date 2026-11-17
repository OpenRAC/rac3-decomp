#ifndef VU0_H
#define VU0_H

/* The game's vector-library helpers, as inline functions with inline asm. Only these may be asm in
 * matched C (AGENTS.md, "Vector-library asm"): retail's code shows they were asm in the original.
 *
 * - VU0 macro-mode operations: one asm statement per instruction with "j" operands (SN cc1's VU0
 *   register class; the file's flag line needs -mvu0-use-vf0-vf2). Pointer parameters reproduce
 *   retail's addressing: a constant destination is stored through %lo(sym)($hi) and the sources
 *   are reached from a register anchored on it. The _ab and _ba forms load the two sources in
 *   the two orders retail has (vf1/vf2 roles).
 * - vec_copy(): a vector copy through a VU0 register (lqc2 + sqc2). SN cc1 copies a plain 128-bit
 *   value with lq/sq through a GPR; retail's lqc2/sqc2 copies of a moby position into the stack
 *   (func_L06_0034A7A8's states 18 and 30, beside the vsub/vadd helpers) are the vector library's.
 * - qzero(): the quadword zero store `sq $0, dst`. SN cc1 cannot emit it from C (movti_internal
 *   stores only from a register: por + sq), and an `sq $0` from a $0 register variable is an
 *   ordinary insn that reorg puts into delay slots, which retail's never are. A non-volatile "=m"
 *   asm schedules freely and stays out of delay slots, exactly like retail's.
 * - fabs_asm(): `abs.s`, the game's fabs. Retail never puts it into a delay slot, and its float
 *   code schedules around it as around an asm (constants loaded before the operand); in the hero
 *   state machine every fabs is this one.
 * - sqrt_asm(): `sqrt.s`, the game's square root. Same evidence as fabs_asm: retail never puts it
 *   into a delay slot (the hero state machines' sqrt.s is followed by jal + nop), and the C
 *   library's sqrtf() adds an errno check and a fallback call.
 * - fmax_asm(): `max.s`, the game's float maximum. SN cc1 emits max.s only under -ffast-math,
 *   which no game file uses, and then it fills delay slots with it; retail never does (the level
 *   loader func_L39_005A12B8's tie and shrub scales: max.s before jal + nop, or before the
 *   argument move that fills the slot).
 * - mat_scale(): scales the four rows of a 4x4 matrix by a float (lqc2 x4, the scalar through $at
 *   into vf5, vmulx.xyzw x4, sqc2 x4), one block as the vector library wrote it: retail's
 *   func_L14_003F9A10 uses vf1-vf5 and $at, which the "j" class (vf1/vf2 only) cannot hold. It needs
 *   @ps2as on its file: SN's assembler leaves the return's delay slot empty as retail does (ee-as
 *   fills it with the last sqc2), and `.set noat` keeps Ps2EeAs from crashing on the $at use.
 * - abs_asm(): the game's integer abs, `blezl x, 1f; neg x, x; 1:`, always in place. SN cc1 cannot
 *   emit it: its abssi2 is `bltzl`/`subu` (the abs() builtin, which retail also has, 23 times in the
 *   levels), it never emits the trapping `sub` that `neg` is, and no assembler of the toolchains
 *   (ee-as, as, Ps2EeAs, the 2.10-ee and dtls GNU as) expands an `abs` macro to a branch-likely:
 *   they give `bgez`/`nop`/`neg` or `bgez`/`move`/`neg`. Retail has the pair 343 times in the
 *   levels' unmatched code and in core handwritten code, never in a delay slot, and the compiler
 *   never folds it: func_L01_0032A0C8 runs it on a value it has just tested > 0, and
 *   func_L02_003484D8 on a 0/1 comparison result. */

typedef int vu0_q __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) vu0_v4;

static __inline__ void vec_sub_ab(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

static __inline__ void vec_sub_ba(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

static __inline__ void vec_add_ab(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

static __inline__ void vec_add_ba(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

/* vec_neg(): the vector library's negate, d.xyz = -a.xyz, as `vsub.xyz vf, vf0, vf` from the VU0's
 * constant zero register (lqc2, vsub.xyz with $vf0 as the minuend, sqc2). The "j" class holds only
 * vf1/vf2 and an operand known to be zero is still loaded into one of them, so neither vec_sub_ab
 * with a zero vector nor any other helper here emits it; retail's func_L21_003A8050 (states 15 and
 * 16, after func_0038CF68) does. */
static __inline__ void vec_neg(void *d, void *a) {
    vu0_q qa, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vsub.xyz %0, vf0, %1" : "=j"(qr) : "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

static __inline__ void vec_copy(void *d, void *s) {
    vu0_q q;
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_v4 *)s));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(q));
}

/* qzero is a macro, not an inline function: an asm statement records its source line
 * (ASM_OPERANDS), and gcc's cross-jumping merges only equal insns. Expanded from an inline
 * function every qzero has the header's line, so two `qzero(p); break;` case tails become one
 * block; retail keeps them apart (func_L04_00504520's case 0x58 and its last case, 0x3C/0x64/0x65), which is what the
 * use-site line of a macro gives. */
#define qzero(d) __asm__("sq $0, %0" : "=m"(*(vu0_q *)(d)))

static __inline__ float fabs_asm(float x) {
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static __inline__ float sqrt_asm(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

static __inline__ float fmax_asm(float a, float b) {
    float r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

/* abs_asm is the game's integer abs (docs/wiki/Matching-Patterns.md, "Integer abs"). The
 * .set noreorder keeps the assembler from padding the branch-likely with a nop. */
static __inline__ int abs_asm(int x) {
    __asm__(".set noreorder\n\tblezl %0, 1f\n\tneg %0, %0\n1:\n\t.set reorder" : "+r"(x));
    return x;
}

static __inline__ void mat_scale(void *dst, void *src, float scale) {
    __asm__ __volatile__(
        ".set noat\n\t"
        "lqc2 $vf1, 0(%1)\n\t"
        "lqc2 $vf2, 16(%1)\n\t"
        "lqc2 $vf3, 32(%1)\n\t"
        "lqc2 $vf4, 48(%1)\n\t"
        "mfc1 $at, %2\n\t"
        "qmtc2.ni $at, $vf5\n\t"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n\t"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n\t"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n\t"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n\t"
        "sqc2 $vf1, 0(%0)\n\t"
        "sqc2 $vf2, 16(%0)\n\t"
        "sqc2 $vf3, 32(%0)\n\t"
        "sqc2 $vf4, 48(%0)\n\t"
        ".set at"
        : : "r"(dst), "r"(src), "f"(scale) : "$1", "memory");
}

#endif /* VU0_H */
