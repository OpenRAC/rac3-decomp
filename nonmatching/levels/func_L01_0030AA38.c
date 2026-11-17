/* PAL near miss (Codex wave 8): near miss: 2 words differ with the file's flags.
 * Worker's note: 2 diff / 78 words at +0x34/+0x48: white ORI and loop-counter initialization exchanged, 01.log. Three loop wordings reproduce identical wrong bytes (01/04/06); six compiles. contract.log compiles cleanly; no all-place exact proof.
 */
#include "common.h"
/* localdecomp:start func_L01_0030AA38 */
void func_L01_0030AA38(void *owner)
{
    extern void func_L01_0030AD10(void *, A00309EA0 *);
    A00309EA0 *entry;
    u8 *position;
    s32 i;
    s32 color, color2;
    for (i = 29; i >= 0; i--) {
        entry = &D_L01_0026FD30[29-i];
        position = (u8 *)entry + 0x30;
        if (*(void **)(position + 0x5C) == owner) {
        func_L01_0030AD10(owner, entry);
        if (*(s32 *)(position + 0x64) == 0) {
        color = (func_00382498(80, 96) << 24) | 0x103080;
        func_003D9508((s32)position, 49, color, 1, 0.5f, 0.15f, func_00382538());
        color2 = (func_00382498(80, 96) << 24) | 0xFFFFFF;
        func_003D9508((s32)position, 49, color2, 1, 0.3f, 0.151f, func_00382538());
        }
        }
    }
}
/* localdecomp:end func_L01_0030AA38 */
