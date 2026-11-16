/* PAL near miss (Codex wave 6): near miss: 3 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_0039FD50; 7 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 3).
 * Worker's note: 3 diff: build/codex/w329/func_0039FE68-04.log; table la after sll instead of before. Removed inaccurate inherited extern size hints; array indexing and integer address (04,05) keep 3 diffs; pointer increment (07) gives 7 diffs. Contract compile clean in ...
 */
#include "common.h"
/* localdecomp:start func_0039FE68 */
extern S_39AAF0 D_0022CF80_0039FE68;
extern u32 D_001D545C;
extern s32 D_00143140_0039FE68[] __attribute__((section(".sdata")));
__asm__(".extern D_00143140_0039FE68, 16");
extern u32 D_001D545C_0039FE68;
__asm__(".extern D_001D545C_0039FE68, 16");
void func_0039FE68(void *buffer) {
    extern void func_0038CF58(void *, s32, s32);
    extern s32 func_0039FD58(s32);
    extern s32 func_0038E100();
    extern void func_0039FF28();
    S_39AAF0 *state = &D_0022CF80_0039FE68;
    s32 result;
    u32 index;
    if (state->f10) {
        if (!state->f28) {
            func_0038CF58(buffer, 0, 0x800);
        } else {
            func_0039FD58(D_001D545C);
            result = func_0038E100(buffer, 0x800, state->f14, state->fC);
            if (result == -1) {
                func_0039FF28(buffer);
                index = D_001D545C_0039FE68;
            } else index = D_001D545C;
            if (D_00143140_0039FE68[index] < result) D_00143140_0039FE68[index] = result;
        }
    }
}
/* localdecomp:end func_0039FE68 */
