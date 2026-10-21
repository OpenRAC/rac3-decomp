#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B29D8();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B29D8 */
extern void func_11AF48(void *, s32);
extern u8 D_001D8878[];
 
s32 func_003B29D8(s32 a0, void *p) {
    func_11AF48(D_001D8878, *(s32 *)((u8 *)p + 0x4));
    return 1;
}
/* localdecomp:end func_003B29D8 */
