/* PAL near miss (Codex wave 11): near miss: 23 words differ in its file's context with the file's flags.
 * Replaces the earlier draft (Codex wave 7 near miss: 27 words differ under tools/check.py in its file's context with the file's flags, measured 2026-11-21;
 * this one: 23).
 * Worker's note: best 23 diff (W/func_0038E1F8.checks/boot_elf.log; prior draft 27): loop body identical except registers; stores written E0, D8, D0 give retail's address order (E0, D8, D0) but the scheduler stores D0, E0, D8 where retail stores D0, D8, E0 (E0 +4 after the D8 store, in blez delay slot), so i lands in a3 not a2 and mask in a2 not a3, D8 address v0 vs v1; all 6 store orders (23-43), table++ form (43-44), 5 E0 expression forms (all 23) tried
 */
#include "common.h"

/* localdecomp:start func_0038E1F8 */
typedef struct Row_0038E1F8 {
    u32 flags;
    u32 data;
} Row_0038E1F8;

extern void *D_001D55D0[];
extern Row_0038E1F8 *D_001D55D8[];
extern u8 *D_001D55E0[];

void func_0038E1F8(s32 index, void *data, s32 *table)
{
    s32 count = *table;
    s32 i;

    D_001D55E0[index] = (u8 *)((Row_0038E1F8 *)(table + 1) + count);
    D_001D55D8[index] = (Row_0038E1F8 *)(table + 1);
    D_001D55D0[index] = data;
    for (i = 0; i < count; i++) {
        Row_0038E1F8 *row = &D_001D55D8[index][i];
        u8 *p = D_001D55E0[index] + ((row->flags >> 2) & 0x3FFC);
        if (p != 0 && p[3] != 0) {
            row->flags &= 0xFFFF000F;
        }
    }
}
/* localdecomp:end func_0038E1F8 */
