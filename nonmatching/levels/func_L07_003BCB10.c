#include "common.h"

/*
 * Snippet MATCH with the owning file's unchanged flags:
 * -O2 -G8 -fopt-stack -mno-check-zero-division.
 * Deferred after the full PAL level 07 build failed level_symbols validation.
 * The owner's existing func_L07_003BBAC8 table requires .rodata at 0x002C0950;
 * this function's table, at object addend 0x20, requires it at 0x002C0990.
 * Retail places the still-assembly func_L07_003BBBA8 table between them.
 * One contiguous compiler section cannot satisfy both bases. No padding,
 * flag change or resolver workaround was added; the INCLUDE_ASM is restored.
 * This is not a full-program match. The removed C is preserved below.
 */

/* localdecomp:start func_L07_003BCB10 */
/* Adapted from the repository's NTSC-U counterpart func_L07_003BB200. */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L07_003BCB10(u8 *obj, s32 state) {
    switch (state) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 7);
        }
        break;
    case 11:
        if (obj[0x43] != 1) {
            func_003C3A10(obj, 1, 0, 7);
        }
        break;
    case 12:
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 7);
        }
        break;
    case 13:
    case 14:
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 7);
        }
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003BCB10 */
