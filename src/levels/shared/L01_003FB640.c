#include "common.h"

/* Hand-written assembly (ASM_FUNC): no prologue, $s0-$s7 and $ra saved into their own upper halves
 * with pcpyld and restored with pcpyud instead of a stack frame, trapping `addi`s (which gcc
 * never emits), and VU0 macro code (vmulx.w on $vf0, qmtc2.ni/qmfc2.ni, vdiv/vwaitq) interleaved
 * with the integer pipeline. */

ASM_FUNC("asm/levels", func_L01_003FB640);

/* Hand-written assembly (ASM_FUNC): the same register-saving scheme and VU0 code as
 * func_L01_003FB640 (pcpyld/pcpyud saves, trapping `addi`s, qmtc2.ni/qmfc2.ni). */

ASM_FUNC("asm/levels", func_L01_003FC480);
