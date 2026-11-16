/* PAL near miss (Codex wave 6): near miss: 12 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003EE290; 39 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 12).
 * Worker's note: 12 instruction diffs: full singleton address hoisted instead of high/low rematerialization; branch-slot move missing; three forms same bytes under fixed -mno-split-addresses; build/codex/w324/func_003EE3F0.02.log
 */
#include "common.h"
/* localdecomp:start func_003EE3F0 */
__asm__(".extern D_001D9708, 16");
__asm__(".extern D_001D9670_003EE3F0, 16");
void func_003EE3F0(T_3E8AD0 *self, s32 flags) {
    extern void func_003EE290(T_E8 *);
    extern s32 func_003E74D0();
    extern s32 *func_003E6FC0();
    extern void **func_003E7078(s32 *, s32);
    extern s32 func_003F2738();
    O_3E8AD0 *p;
    s32 **end;
    s32 *singleton;
    void **allocator;
    self->f8 = D_001D9708;
    func_003EE290((T_E8 *)self);
    {
        O_3E8AD0 *first = self->x2C;
        if (first->x44) func_003E74D0(first->x44);
        first->x44 = 0;
    }
    p = self->x2C;
    if (p->x44) func_003E74D0(p->x44);
    p->x44 = 0;
    if (p) {
        end = p->arr + 16;
        while (p->arr != end) {
            --end;
            if (*end) func_003E74D0(*end);
            *end = 0;
        }
    }
    singleton = (s32 *)D_001DA938_003EE3F0;
    if (singleton[1] == 0) singleton = func_003E6FC0(singleton);
    allocator = func_003E7078(singleton, 1);
    if (allocator) {
        ((s32 (*)(void *, void *))(*(s32 **)allocator)[3])(allocator, self->x2C);
        self->x2C = 0;
    }
    self->f8 = D_001D9670_003EE3F0;
    if (flags & 1) func_003F2738(self);
}
/* localdecomp:end func_003EE3F0 */
