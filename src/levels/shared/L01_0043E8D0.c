#include "common.h"

/* Hand-written assembly (ASM_FUNC): no stack frame, $ra saved into its own upper half with
 * pcpyld and restored with pcpyud before the jr, then used as the scratchpad's base register
 * (lui $ra, 0x7000); trapping add/addi/sub, which gcc never emits; nop padding placed by hand in
 * its loops; scratchpad DMA (channels at 0x1000D000/0x1000D400) waited on with a sync.p/sync and
 * bc0f loop; VU0 macro code (vitof15/vitof0, vmulaw, vrsqrt/vwaitq) on vf1-vf10 and ACC; and two
 * exits through a j to its own label at 0x0043EF88. */

ASM_FUNC("asm/levels", func_L01_0043E8D0);
