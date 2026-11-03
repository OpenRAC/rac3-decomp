/* NTSC decomp draft rewritten as plain C (GPL-3.0; THIRD_PARTY_NOTICES.md).
 * Rechecked 2026-10-31 with the owning file's S/default flags: 2 differing words.
 * The table pointer is loaded into a0 instead of retail's v0; the following
 * addu consequently uses a0. Struct-index and integer-address forms give the
 * same difference; splitting the pointer assignment gives 9 differences.
 * No register pins or assembly barriers are used. Not integrated.
 */
#include "common.h"
/* localdecomp:start func_00381FF0 */
extern s32 D_001D99A0_00381FF0[];
extern u8 D_001D5788;
extern s32 func_00381F80(s32 id);
s32 func_00381FF0(s32 id)
{
    s32 index = func_00381F80(id);
    s32 result = (s32)&D_001D5788;
    if (index >= 0) {
        result = *(s32 *)(index * 16 + D_001D99A0_00381FF0[0]);
    }
    return (s32)result;
}
/* localdecomp:end func_00381FF0 */
