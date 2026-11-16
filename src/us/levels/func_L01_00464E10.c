#include "common.h"

/* NTSC-U counterpart of func_L01_00468468 (src/levels/shared/L01_00462978.c) */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern u32 func_L01_00445B88(f32 r, f32 g, f32 b, f32 a);

/* localdecomp:start func_L01_00464E10 */
typedef int Q_00468468 __attribute__((mode(TI)));

void func_L01_00464E10(void *arg0) {
    extern void func_003C7CE0(u8 *);
    extern u32 func_L01_00445B88(f32 r, f32 g, f32 b, f32 a);
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f1;
    f32 temp_f3;
    void *temp_16;
    void *temp_4;

    if (arg0 != 0) {
        temp_4 = (*(void **)((u8 *)(arg0) + (0x20)));
        temp_16 = arg0 + 0x20;
        if ((temp_4 == 0) || (((*(u8 *)((u8 *)(temp_4) + (0x20))) & 0xF0) == 0xF0) || ((*(Q_00468468 *)((u8 *)(arg0) + (0x10))) = (Q_00468468) (*(Q_00468468 *)((u8 *)(temp_4) + (0x10))), temp_f3 = (*(f32 *)((u8 *)(temp_16) + (8))), temp_f1 = (*(f32 *)((u8 *)(temp_16) + (4))) + temp_f3, (*(f32 *)((u8 *)(temp_16) + (4))) = temp_f1, (temp_f1 < 0.0f))) {
            func_003C7CE0(arg0);
            return;
        }
        if (temp_f1 > 0.6f) {
            temp_f0 = -temp_f3;
            (*(f32 *)((u8 *)(temp_16) + (8))) = temp_f0;
            (*(f32 *)((u8 *)(temp_16) + (4))) = (f32) (temp_f1 + temp_f0);
        }
        temp_f0_2 = (*(f32 *)((u8 *)(temp_16) + (0x10))) + -0.0174f;
        (*(f32 *)((u8 *)(temp_16) + (0x10))) = temp_f0_2;
        if (temp_f0_2 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x10))) = 0.0f;
        }
        temp_f0_3 = (*(f32 *)((u8 *)(temp_16) + (0x14))) + -0.01446f;
        (*(f32 *)((u8 *)(temp_16) + (0x14))) = temp_f0_3;
        if (temp_f0_3 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x14))) = 0.0f;
        }
        temp_f0_4 = (*(f32 *)((u8 *)(temp_16) + (0x18))) + -0.0015f;
        (*(f32 *)((u8 *)(temp_16) + (0x18))) = temp_f0_4;
        if (temp_f0_4 < 0.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0x18))) = 0.0f;
        }
        (*(s32 *)((u8 *)(arg0) + (4))) = func_L01_00445B88((*(f32 *)((u8 *)(temp_16) + (0x10))), (*(f32 *)((u8 *)(temp_16) + (0x14))), (*(f32 *)((u8 *)(temp_16) + (0x18))), (*(f32 *)((u8 *)(temp_16) + (4))));
        temp_f0_5 = (*(f32 *)((u8 *)(temp_16) + (0xC))) + 0.0011f;
        (*(f32 *)((u8 *)(temp_16) + (0xC))) = temp_f0_5;
        if (temp_f0_5 > 1.0f) {
            (*(f32 *)((u8 *)(temp_16) + (0xC))) = (f32) (temp_f0_5 - 1.0f);
        }
        (*(s8 *)((u8 *)(arg0) + (8))) = (s8) (s32) ((*(f32 *)((u8 *)(temp_16) + (0xC))) * 255.0f);
        (*(f32 *)((u8 *)(arg0) + (0xC))) = (f32) (((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + (0x20)))) + (0x2C))) * 100000.0f * 30.0f) + 50000.0f);
    }
}
/* localdecomp:end func_L01_00464E10 */
