#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L21_003B2A40 */
extern u8 *func_003C24B0(s32, s32);
void func_0038CF68(void *, void *, f32);

void *func_L21_003B2A40(void *arg0, s32 arg1) {
    u8 *temp_s1;
    u8 *temp_s0;
    vu0_v4 sp_v;

    temp_s1 = func_003C24B0(0x1C79, 0x80);
    if (temp_s1 != 0) {
        *(void **)(temp_s1 + 0xB8) = arg0;
        *(u8 *)(temp_s1 + 0x30) = 0xFF;
        *(vu0_q *)(temp_s1 + 0x10) = *(vu0_q *)((u8 *)arg0 + 0x10);
        temp_s0 = *(u8 **)(temp_s1 + 0x68);
        *(vu0_q *)(temp_s1 + 0xF0) = *(vu0_q *)((u8 *)arg0 + 0xF0);
        func_0038CF68(&sp_v, (u8 *)arg0 + 0xE0, 0.25f);
        vec_add_ab(temp_s1 + 0x10, &sp_v, temp_s1 + 0x10);
        *(vu0_q *)temp_s0 = *(vu0_q *)((u8 *)arg0 + 0xC0);
        *(s32 *)(temp_s0 + 0x14) = (s32) ((f32) arg1 + (f32) arg1);
    }
    return temp_s1;
}
/* localdecomp:end func_L21_003B2A40 */
