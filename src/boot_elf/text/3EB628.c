#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003EB628(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
/* --- end of declarations from other files --- */

typedef struct { u8 b[16]; } V16_func_003E5D08;
extern s32 D_001D9790_func_003E5D08;
extern V16_func_003E5D08 D_001D96C0_func_003E5D08;
/* localdecomp:start func_003EB628 */
/* from the US draft (nonmatching/boot_elf/func_003EB628.c); V16_func_003E5D08, D_001D9790_func_003E5D08
   and D_001D96C0_func_003E5D08 are declared by the source file right above the marker. */
s32 func_003EB628(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_func_003E5D08 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001D9790_func_003E5D08) != 0) {
        v = D_001D96C0_func_003E5D08;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EB628 */
