#include "common.h"

/* Hand-written assembly (ASM_FUNC): moby_set_colour has a `nop` before `jr $ra`, where gcc
 * never leaves one (the store already fills the delay slot). */

ASM_FUNC("asm/levels", func_L01_0043B9E8);
