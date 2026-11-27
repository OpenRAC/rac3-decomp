#include "common.h"

/* Hand-written assembly (ASM_FUNC): no prologue, $at used as a working register, trapping `addi`s
 * (which gcc never emits), VU0 macro code (qmtc2.ni, vsub/vmul/vmaddz/vmini, vitof0) and the
 * scratchpad at 0x70000000-0x70000DF0 cleared with `sq $0`, plus a moby walk entered at an inner
 * label (func_005ACC28) that `j`umps back to it. */

ASM_FUNC("asm/levels", func_L39_005ACB68);
