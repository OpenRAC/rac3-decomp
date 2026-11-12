#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_003E8DF8);

/* localdecomp:start func_L09_003E91B8 */
void func_L01_0044ABD0(void *, void *);
u8 *func_L01_00447490(u8 *, s32, s32);
void func_003C4A40(void *, void *);
void func_L01_004450F0(s32, s32, s32);

void func_L09_003E91B8(u8 *a0) {
    u8 *st;
    u8 *r5;

    if (a0[0x20] == 0) {
        return;
    }
    st = *(u8 **)(a0 + 0x68);
    func_L01_0044ABD0(a0, st + 0x30);
    r5 = func_L01_00447490(a0, 0x80000, 0);
    if (r5 != 0) {
        if (*(s16 *)(*(u8 **)(r5 + 0x20) + 0xAA) == 0x1C0C) {
            f32 f = *(f32 *)(r5 + 0x2C);
            st[0x37] = 0xFF;
            *(s16 *)(st + 0x64) = (s32)*(u16 *)(st + 0x64) - (s32)f;
            func_003C4A40(a0, st + 0x30);
            if (*(s16 *)(st + 0x64) <= 0) {
                if (a0[0x20] != 3) {
                    if (a0[0x20] != 4) {
                        func_L01_004450F0((s32)a0, 3, -1);
                    }
                }
            }
            a0[0xA8] = 0xFF;
            return;
        }
    }
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L09_003E91B8 */

/* localdecomp:start func_L09_003E9298 */
void func_L01_004450F0(s32, s32, s32);
void func_L09_003E9298(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if (arg1 != -1) {
        *(s32 *)((u8 *)temp_v1 + 0x70) = arg1;
    } else {
        *(s32 *)((u8 *)temp_v1 + 0x70) = 0x7D;
    }
    func_L01_004450F0((s32) arg0, 2, -1);
}
/* localdecomp:end func_L09_003E9298 */
