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

#endif /* CPU_H */
