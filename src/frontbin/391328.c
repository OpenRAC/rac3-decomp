#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00391328 */
/* the copy of func_L39_00596EE0 */
extern void func_0012A950(void), func_0012BEE8(s32, s32, s32, s32);
extern s32 D_00143950[];
extern s32 D_001D5520;

/* from rac4-decomp's func_00458670 */
void func_00391328(void)
{
    s32 mode;
    func_0012A950();
    mode = D_00143950[0];
    if (mode)
        D_001D5520 = 0;
    if (D_001D5520)
        func_0012BEE8(0, 0, 80, 1);
    else
        func_0012BEE8(0, 1, mode ? 3 : 2, 0);
}
/* localdecomp:end func_00391328 */

extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
