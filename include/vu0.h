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
 * - qzero(): the quadword zero store `sq $0, dst`. SN cc1 cannot emit it from C (movti_internal
 *   stores only from a register: por + sq), and an `sq $0` from a $0 register variable is an
 *   ordinary insn that reorg puts into delay slots, which retail's never are. A non-volatile "=m"
 *   asm schedules freely and stays out of delay slots, exactly like retail's.
 * - fabs_asm(): `abs.s`, which retail likewise never puts into a delay slot (__builtin_fabsf does).
 *   Use it only where retail's abs.s sits outside a slot it could fill; elsewhere use fabsf. */

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

static __inline__ void qzero(void *d) {
    __asm__("sq $0, %0" : "=m"(*(vu0_q *)d));
}

static __inline__ float fabs_asm(float x) {
    float r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

#endif /* VU0_H */
