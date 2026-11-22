#include "common.h"

/* Hand-written assembly (ASM_FUNC): a leaf that compares two buffers eight bytes at a time with
 * `ld`, and steps both pointers and the byte count with the trapping `addi`, which the compiler
 * never emits; its results are set with `addi $v0, $zero, 1` / `0` as well. */

ASM_FUNC("asm/levels", func_L03_003FB6C8);
