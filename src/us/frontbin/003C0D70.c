#include "common.h"

/* NTSC-U counterpart of func_003C62C8 (frontbin). */
#include "vu0.h"
extern void func_U_003C0D70();

/* localdecomp:start func_U_003C0D70 */
/* US draft of func_U_003C0D70 (rac3-uya-decomp func_003C6530, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */

/* NTSC-U uses 60 Hz frame and angular scales. */

typedef struct { u8 pad[0x48]; void *a[1]; } S_3C0D70_003C62C8;
void func_U_003C0D70(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg_sp0, u8 *arg_sp8) {
    u8 temp_3_2;
    void *temp_3;
    S_3C0D70_003C62C8 *s;

    s = *(S_3C0D70_003C62C8 **)((u8 *)arg0 + 0x24);
    temp_3 = (*(void **)((u8 *)s->a[arg1] + 0x14));
    if (temp_3 != 0) {
        *arg2 = (*(f32 *)((u8 *)temp_3 + 8)) * 0.01666666753590107f;
        *arg3 = (*(f32 *)((u8 *)temp_3 + 0xC)) * 0.01666666753590107f;
        *arg4 = (*(f32 *)((u8 *)temp_3 + 0x10)) * 0.00027777778450399637f;
        *arg5 = (*(f32 *)((u8 *)temp_3 + 0x14)) * 0.00027777778450399637f;
        *arg_sp0 = (*(f32 *)((u8 *)temp_3 + 4)) * 0.00027777778450399637f;
        *arg6 = (*(f32 *)((u8 *)temp_3 + 0x18));
        *arg7 = (*(f32 *)((u8 *)temp_3 + 0x1C));
        temp_3_2 = (*(u8 *)((u8 *)temp_3 + 1));
        if (temp_3_2 != 0) {
            *arg_sp8 = temp_3_2;
        }
    }
}
/* localdecomp:end func_U_003C0D70 */
