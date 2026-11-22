#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

extern int D_001DA050[];
/* localdecomp:start func_003A9F70 */
extern int D_001DA050[];
extern u32 *D_001DA050_g;
extern u8 D_001D8030;
void func_003A9F70(void) {
    ((u32 *)D_001DA050[0])[0] = 0x30000003;
    ((u32 *)D_001DA050[0])[1] = (u32)&D_001D8030;
    ((u32 *)D_001DA050[0])[2] = 0;
    ((u32 *)D_001DA050[0])[3] = 0x50000003;
    D_001DA050_g = (u32 *)D_001DA050[0] + 4;
}
/* localdecomp:end func_003A9F70 */
