#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00393990 */
/* the copy of func_003935B0 */
void func_00393990(s32 id, s32 v) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_00331AE0[i].id == id) break;
    }
    if (i < 13) {
        D_00331AE0[i].f24 = v;
        if (!D_00331AE0[i].f68) D_00331AE0[i].f4 = v;
    }
}
/* localdecomp:end func_00393990 */
