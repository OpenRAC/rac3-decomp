/* PAL near miss (Claude wave S2/pal): near miss: 8 words differ with the file's flags.
 * Worker's note: 8 diff: 64-bit field repack (low word kept, a<<32 / b<<40 / c<<48, unsigned long): gcc folds the low-word mask into lwu, retail has ld + dsll32/dsrl32 zero-extend + a nop before jr (sd in the slot); 7 wordings (u32 cast, shifts, signed, temp) all fold to lwu
 */
#include "common.h"

/* localdecomp:start func_L01_0043B9E8 */
void func_L01_0043B9E8(u8 *obj, s32 a, s32 b, s32 c) {
    unsigned long v = *(unsigned long *)(obj + 0x38);
    *(unsigned long *)(obj + 0x38) = (unsigned long)(u32)v | ((unsigned long)a << 32) | ((unsigned long)b << 40) | ((unsigned long)c << 48);
}
/* localdecomp:end func_L01_0043B9E8 */
