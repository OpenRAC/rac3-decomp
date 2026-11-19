#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00392640(s32, long, long);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern unsigned long D_001D07E8[];
/* localdecomp:start func_00392640 */
extern unsigned long D_001D07E8[];
void func_00392640(s32 arg0, long arg1, long arg2) {
    D_001D07E8[0] = arg0 | (arg1 << 8) | (arg2 << 0x10) | (unsigned long)0x80000000;
}
/* localdecomp:end func_00392640 */
