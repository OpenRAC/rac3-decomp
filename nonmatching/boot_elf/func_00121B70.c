/* PAL near miss: 29 words differ with 121B38.c's existing SN flags.
 * Callback registration uses the negative/positive tables at D_153158 + 0xC/0x14.
 * CpuGetGp supplies the GP copy. Register allocation, store scheduling and the
 * shared return still differ. Sony 2.9 also differs; the owning file's flags
 * have not been changed. No matched implementation is claimed here.
 */
#include "common.h"
#include "cpu.h"

/* localdecomp:start func_00121B70 */
typedef struct {
    void (*fn)(void *, void *);
    void *arg;
    void *gp;
} Callback_121B70;
typedef struct {
    u8 pad0[0xC];
    Callback_121B70 *negative;
    s32 pad10;
    Callback_121B70 *positive;
} CallbackTable_121B70;

void func_00121B70(s32 index, void (*fn)(void *, void *), void *arg) {
    CallbackTable_121B70 *table = (CallbackTable_121B70 *)&D_153158;
    if (index < 0) {
        Callback_121B70 *entry;
        index &= 0x7FFFFFFF;
        entry = &table->negative[index];
        entry->arg = arg;
        entry->fn = fn;
        table->negative[index].gp = CpuGetGp();
    } else {
        Callback_121B70 *entry = &table->positive[index];
        entry->arg = arg;
        entry->fn = fn;
        table->positive[index].gp = CpuGetGp();
    }
}
/* localdecomp:end func_00121B70 */
