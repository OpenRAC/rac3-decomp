#include "common.h"

/* Hand-written assembly (ASM_FUNC): both use `sub`/`addi`, which gcc never emits, and
 * timer_tick_seconds (func_L01_0040E050) uses $at as a working register. */

ASM_FUNC("asm/levels", func_L01_0040E020);

ASM_FUNC("asm/levels", func_L01_0040E050);
