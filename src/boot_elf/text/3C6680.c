#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C6680();
/* --- end of declarations from other files --- */

/* US draft of func_003C6680 (rac3-uya-decomp func_003C6530, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */

/* PAL retail runs at 50 Hz, so the frame scale is 1/50 (0x3CA3D70B) and the angular
   scale is 1/50*1/50 (0x39D1B718); the US 60 Hz constants (1/60, 1/3600) are wrong here. */

/* localdecomp:start func_003C6680 */
typedef struct { u8 pad[0x48]; void *a[1]; } S_3C0D70;
void func_003C6680(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg_sp0, u8 *arg_sp8) {
    u8 temp_3_2;
    void *temp_3;
    S_3C0D70 *s;

    s = *(S_3C0D70 **)((u8 *)arg0 + 0x24);
    temp_3 = (*(void **)((u8 *)s->a[arg1] + 0x14));
    if (temp_3 != 0) {
        *arg2 = (*(f32 *)((u8 *)temp_3 + 8)) * 0.020000001f;
        *arg3 = (*(f32 *)((u8 *)temp_3 + 0xC)) * 0.020000001f;
        *arg4 = (*(f32 *)((u8 *)temp_3 + 0x10)) * 0.00040000001f;
        *arg5 = (*(f32 *)((u8 *)temp_3 + 0x14)) * 0.00040000001f;
        *arg_sp0 = (*(f32 *)((u8 *)temp_3 + 4)) * 0.00040000001f;
        *arg6 = (*(f32 *)((u8 *)temp_3 + 0x18));
        *arg7 = (*(f32 *)((u8 *)temp_3 + 0x1C));
        temp_3_2 = (*(u8 *)((u8 *)temp_3 + 1));
        if (temp_3_2 != 0) {
            *arg_sp8 = temp_3_2;
        }
    }
}
/* localdecomp:end func_003C6680 */
