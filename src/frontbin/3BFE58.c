#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


extern s32 D_001DA31C[];
extern void func_003CD250(s32);
/* localdecomp:start func_003BFE58 */
void func_003BFE58(void) {
    s32 *p = D_001DA31C;
    s32 i;
    for (i = 5; i >= 0; i--, p++) {
        if (*p) { func_003CD250(*p); *p = 0; }
    }
}
/* localdecomp:end func_003BFE58 */
