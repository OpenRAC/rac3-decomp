#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 D_001D5C78;
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AF4B8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001D8798[];
extern u8 D_001D87B0[];
extern void func_00116F98(void *, s32, void *);

/* localdecomp:start func_003AF760 */
extern void func_003AF420(void *, s32);
void func_003AF760(void) {
    s32 i;
    if (D_001D5C78 != 0) {
        for (i = 0; i < 1; i++) {
            func_003AF420((void *)(D_001D5C78 + 0x1FCA8), i);
        }
    }
}
/* localdecomp:end func_003AF760 */
