#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B7B20.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B7F80(void);
extern void func_003B7E38(void);
extern void func_003B7F08(void);
extern void func_003B7F30(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA1A0;
extern s32 D_001DA188[2];
extern void func_003B77A0();
extern void func_003B7C88();
/* localdecomp:start func_003B7F80 */
extern void func_003B7E38(void);
extern void func_003B7F08(void);
extern void func_003B7F30(void);
s32 func_003B7F80(void) {
    if (D_001DA1A0 == 0) {
        func_003E6FA0(D_001DA188, (s32)func_003B77A0, (s32)func_003B7E38, (s32)func_003B7C88, (s32)func_003B7F08, (s32)func_003B7F30);
        D_001DA1A0 = 1;
    }
    return (s32)D_001DA188;
}
/* localdecomp:end func_003B7F80 */
