#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_00393538();
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern s32 func_00392F68(s32 key);

/* localdecomp:start func_003935B0 */
void func_003935B0(s32 id, s32 v) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_00331AE0[i].id == id) break;
    }
    if (i < 13) {
        D_00331AE0[i].f24 = v;
        if (!D_00331AE0[i].f68) D_00331AE0[i].f4 = v;
    }
}
/* localdecomp:end func_003935B0 */
