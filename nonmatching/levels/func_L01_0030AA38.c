/* PAL near miss: 2 of 78 words differ, both in the loop preheader.
 * Best draft. Retail order at 0x0030AA78/0x0030AA80 is
 * `addiu $s1,$v0,0x30` (position's IV init) then `addiu $s5,$zero,0x1d`
 * (the counter's init); gcc emits them swapped.
 *
 * Root cause (verified with -dL/-dS on gcc 2.95.3): the loop pass emits
 * the two strength-reduced giv inits in the order [position, entry]
 * (position = entry + 0x30 is emitted before entry = base), so flow2 puts
 * the REG_DEAD note for the base register on ENTRY. The Haifa scheduler's
 * register-weight tie-break (weight = #sets - #dead, lower = preferred)
 * then gives entry weight 0 (kills base) and schedules it early, while
 * position (weight 1) ties with the counter init (weight 1) and loses to
 * the counter on the LUID tie-break. Retail's compiler emitted
 * [entry, position], so the death note landed on position and it was
 * scheduled before the counter. Making the two colour masks locals
 * (0x103080, 0xFFFFFF) is what moves their lui/ori pair into retail's
 * slots; the remaining pair is this flow2/scheduler tie, not a plain
 * scheduler tie.
 */
#include "common.h"
/* localdecomp:start func_L01_0030AA38 */
void func_L01_0030AA38(void *owner)
{
    extern void func_L01_0030AD10(void *, A00309EA0 *);
    A00309EA0 *entry;
    u8 *position;
    u32 mask = 0x103080;
    u32 white = 0xFFFFFF;
    s32 i;
    s32 color, color2;
    for (i = 29; i >= 0; i--) {
        entry = &D_L01_0026FD30[29-i];
        position = (u8 *)entry + 0x30;
        if (*(void **)(position + 0x5C) == owner) {
        func_L01_0030AD10(owner, entry);
        if (*(s32 *)(position + 0x64) == 0) {
        color = (func_00382498(80, 96) << 24) | mask;
        func_003D9508((s32)position, 49, color, 1, 0.5f, 0.15f, func_00382538());
        color2 = (func_00382498(80, 96) << 24) | white;
        func_003D9508((s32)position, 49, color2, 1, 0.3f, 0.151f, func_00382538());
        }
        }
    }
}
/* localdecomp:end func_L01_0030AA38 */
