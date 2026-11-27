#include "common.h"

/* Hand-written assembly (ASM_FUNC): no prologue, $ra kept in its own upper half (pcpyld/pcpyud),
 * $at used as a working register, 91 trapping `addi`s (which gcc never emits), its buffers in the
 * scratchpad at 0x70000000, about 215 VU0 macro instructions and the GIF/VIF1 DMA registers at
 * 0x1000D400 written directly. */
ASM_FUNC("asm/levels", func_L01_00440AD8);

ASM_FUNC("asm/levels", func_L01_00441558);

ASM_FUNC("asm/levels", func_L01_00441658);

ASM_FUNC("asm/levels", func_L01_00441740);

ASM_FUNC("asm/levels", func_L01_004436F4);
