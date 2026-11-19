#include "common.h"

/* Hand-written assembly (ASM_FUNC): anim_frame_unpack uses `add`/`addi` throughout, which gcc
 * never emits, $at as a working register and $24/$25 for its arguments. */

ASM_FUNC("asm/levels", func_L01_0043C8F8);
