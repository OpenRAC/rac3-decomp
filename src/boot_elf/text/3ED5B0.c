#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003ED5B0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
/* --- end of declarations from other files --- */

typedef struct { u8 b[16]; } V16_003E7C90;
extern s32 D_001D97F0_003ED5B0;
extern V16_003E7C90 D_001D96C0_003ED5B0;
/* localdecomp:start func_003ED5B0 */
typedef struct {
    u8 pad[0x10];
    s32 (*isA)(void *, s32);
    u8 pad14[0xC];
    s32 (*get)(void *, void *, f32 *, s32);
} VT_003ED5B0;
s32 func_003ED5B0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E7C90 v;
    f32 out[4];
    if ((*(VT_003ED5B0 **)((u8 *)arg0 + 8))->isA(arg0, D_001D97F0_003ED5B0) != 0) {
        v = D_001D96C0_003ED5B0;
        (*(VT_003ED5B0 **)((u8 *)arg0 + 8))->get(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003ED5B0 */
