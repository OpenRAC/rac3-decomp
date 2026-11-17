/* PAL near miss (Codex wave 7): near miss: 27 words differ with the file's flags.
 * Worker's note: 27 diff in e1-final-near.log; pointer setup ordering and register allocation; fresh PAL draft retained after 6 compiles
 */
#include "common.h"
/* localdecomp:start func_0038E1F8 */
extern void *D_001D55D0[];
extern u32 *D_001D55D8[];
extern u8 *D_001D55E0[];
void func_0038E1F8(s32 index, void *data, s32 *table) {
    s32 count = *table;
    s32 i;
    D_001D55D0[index] = data;
    D_001D55D8[index] = (u32 *)(table + 1);
    D_001D55E0[index] = (u8 *)(table + 1) + count * 8;
    for (i = 0; i < count; i++) {
        u32 *row = D_001D55D8[index] + i * 2;
        u32 value = *row;
        u8 *ptr = D_001D55E0[index] + ((value >> 2) & 0x3FFC);
        if (ptr != 0 && ptr[3] != 0) {
            *row = value & 0xFFFF000F;
        }
    }
}
/* localdecomp:end func_0038E1F8 */
