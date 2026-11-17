/* PAL near miss (Codex wave 4): near miss: 8 words differ with the file's flags.
 * Worker's note: sister build/codex/pool/X4/pal_func_00125BE8_rac4.c; best log build/codex/w165/func_00125BE8.check01.log; 8 word diffs: ee29 allocates v1 instead of retail a2 in both unsigned product halves; direct division, explicit sibling helper call and unsigned-long ...
 */
#include "common.h"

/* localdecomp:start func_00125BE8 */
/* Ported from rac5-sm-decomp/src/boot/TimerUSec2BusClock.c. */
u64 func_00125BE8(u32 sec, u32 usec) {
    return (u64)sec * 0x08CA0000u + (u64)usec * 0x08CA0000u / 1000000u;
}
/* localdecomp:end func_00125BE8 */
