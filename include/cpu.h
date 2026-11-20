#ifndef CPU_H
#define CPU_H

/* The EE's ordering and interrupt instructions as Sony's library code has them in compiled
 * functions: inline functions with inline asm (AGENTS.md, "CPU helpers"). The compiler cannot emit
 * them; retail's Sony library code has a sync between hardware register accesses (11F2A0.c,
 * 12C4B0.c, 12C9A0.c, 132D48.c). rac1-decomp's include/common.h defines the same four.
 * Functions call these, never write the asm themselves, and only where retail has the instruction.
 */
static __inline__ void CpuSync(void) { __asm__ __volatile__("sync"); }
static __inline__ void CpuSyncP(void) { __asm__ __volatile__("sync.p"); }
static __inline__ void CpuEnableInt(void) { __asm__ __volatile__("ei"); }
static __inline__ void CpuDisableInt(void) { __asm__ __volatile__("di"); }

/* $gp, as Sony's library code reads and switches it (the maintainer, 2026-11-19). SN cc1 has no C form for it:
 * $gp is a fixed register. Three forms, as retail has them:
 * - CpuGetGp(): a copy of $gp in another register, `daddu rd, $gp, $0` (func_00122810).
 * - CpuGp(): $gp itself, for a store of the register (`sw $gp, ...`: func_0012AA78, func_0012FD50); a $28
 *   register variable, here only: an asm move would add the copy retail does not have.
 * - CpuSwapGp(p): $gp set to p and its old value returned, the two moves together (func_00135818).
 * Retail's boot_elf reads $gp into a register 29 times and stores it 4 times. */
static __inline__ void *CpuGetGp(void) { void *r; __asm__ __volatile__("move %0, $28" : "=r"(r)); return r; }
static __inline__ void *CpuGp(void) { register void *gp __asm__("$28"); return gp; }
static __inline__ void *CpuSwapGp(void *p) {
    void *old;
    __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(old) : "r"(p) : "memory");
    return old;
}

#endif /* CPU_H */
