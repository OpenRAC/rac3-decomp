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

/* CpuStoreGp(p): $gp stored at p, `sw $gp, ...`, with the memory clobber retail shows (issue #67's
 * "store it into a field", the maintainer, 2026-11-28). iSetTimerHandler (func_00125A70) stores $gp
 * into the timer entry and then loads the entry's mode word again, although it has just stored it
 * from a register: an asm that may write memory, as the switches above, and not the plain store of
 * CpuGp() (func_0012AA78, func_0012FD50 keep their values across their store). */
static __inline__ void CpuStoreGp(void **p) { __asm__ __volatile__("sw $28, %0" : "=m"(*p) : : "memory"); }

/* CpuLoadGp(p) and CpuSetGp(p): the switch around a callback when the saved gp is in memory (issue
 * #67, the maintainer, 2026-11-28). Retail loads it straight into $gp, `daddu rd, $gp, $0; lw $gp,
 * ...`, and sets the old value back with the one move `daddu $gp, rs, $0`, where CpuSwapGp() has a
 * register for the new gp and two moves: the libcdvd power-off handler (func_0012ADC8) and two SIF
 * callbacks (func_00123118, func_0012EDD0). */
static __inline__ void *CpuLoadGp(void **p) {
    void *old;
    __asm__ __volatile__("move %0, $28\n\tlw $28, %1" : "=&r"(old) : "m"(*p) : "memory");
    return old;
}
static __inline__ void CpuSetGp(void *p) { __asm__ __volatile__("move $28, %0" : : "r"(p) : "memory"); }

/* COP0 Count ($9), the EE's cycle counter, as `mfc0 rd, Count` (the maintainer, 2026-11-28). The
 * compiler cannot read a COP0 register; retail reads Count in compiled code to time a piece of
 * work: func_L39_0057CEB0 (multiplayer levels 39-53) reads it on entry, keeps the value in a stack
 * slot across its calls, reads it again at the end and stores the difference, each read scheduled
 * between ordinary compiled code. `volatile`: every read is a new value, so two reads must stay two
 * and keep their place. */
static __inline__ unsigned int CpuGetCount(void) {
    unsigned int count;
    __asm__ __volatile__("mfc0 %0, $9" : "=r"(count));
    return count;
}

#endif /* CPU_H */
