/* PAL near miss (Codex wave 6): near miss: 11 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_0039A030; 42 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 11).
 * Worker's note: 11 diff; build/codex/w289/func_0039A148.02.log and .06.log; table base scheduling and a0/a1 allocation; pointer/store order variants regress to 23-24; three wordings retain 11
 */
#include "common.h"
/* localdecomp:start func_0039A148 */
extern s32 D_001DA480_0039A148;
__asm__(".extern D_001DA480_0039A148, 16");
extern s32 D_001DA484_0039A148;
__asm__(".extern D_001DA484_0039A148, 16");
void func_0039A148(S_4F78 *obj, s32 b, void *c, s32 slot)
{
    extern void func_00399E28(s32, s32, void *, s32);
    if (!obj) {
        s32 count;
        func_003CD318(slot,1);
        count = D_001DA484_0039A148;
        D_002DB190[slot] = *(u8 *)&D_001DA484_0039A148;
        D_001DA484 = count + 1;
    } else {
        s32 count = D_001DA480_0039A148;
        D_002DB190[slot] = *(u8 *)&D_001DA480_0039A148;
        D_002DAFB0[count] = slot;
        D_002DA740[count] = (s32)obj;
        D_002DDC30[count] = obj->b2D << 10;
        if (obj->b2D == 0xFF) {
            D_002DDC30[count] = 0x100000;
        }
        func_00399E28((s32)obj,b,c,slot);
        func_003CD318(slot,0);
        D_001DA480_0039A148++;
    }
}
/* localdecomp:end func_0039A148 */
