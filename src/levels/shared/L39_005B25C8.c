#include "common.h"

/* Hand-written assembly (ASM_FUNC): no prologue, $ra/$fp/$sp/$s0-$s7 saved into the scratchpad
 * at 0x70003FA8-0x70003FF8, $at used as a working register, 215 trapping `addi`s (which gcc never
 * emits), and the GIF/VIF1 DMA registers at 0x1000D400 written directly. */

ASM_FUNC("asm/levels", func_L39_005B25C8);
