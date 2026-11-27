#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E58A8.c's earlier functions */
extern s32 func_003E6378();
extern s32 func_003E7118();

extern s32 D_001D96D0[];
extern s32 func_003E7118();
extern void func_003E7108();
/* localdecomp:start func_003E5CE8 */
extern s32 func_003E6378();
s32 func_003E5CE8(s32 *a0, u32 a1, s32 a2) {
    s32 *p;
    s32 *obj;
    s32 *s1;
    if (a1 < 0x23) {
        if (*(s32 *)(a1 * 4 + *a0 + 0x50) == 0) {
            obj = (s32 *)func_003E6378(a0, a2);
            if (obj != 0 && ((s32 (*)())(*(s32 *)(obj[2] + 0x10)))(obj, D_001D96D0[0]) != 0) s1 = obj; else s1 = 0;
            if (s1 != 0) {
                p = (s32 *)(a1 * 4 + *a0); p += 0x14;
                if (*p != 0) func_003E7118(*p);
                *p = (s32)s1;
                func_003E7108(s1);
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_003E5CE8 */
