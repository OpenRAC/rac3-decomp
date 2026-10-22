#include "common.h"

/* localdecomp:start func_L13_003AF6F8 */
void func_003C3A10(s32, s32, s32, s32);
void func_L13_003AF6F8(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    void *temp_a1;
    void *temp_a2;

    temp_a2 = *(void **)((u8 *)arg1 + 0x68);
    temp_a1 = *(void **)((u8 *)arg0 + 0x68);
    *(u8 *)((u8 *)temp_a1 + 0x26D) = (u8) (*(u8 *)((u8 *)temp_a2 + 0x80));
    *(s32 *)((u8 *)temp_a1 + 0x370) = (s32) (*(s32 *)temp_a2);
    temp_f0 = *(f32 *)((u8 *)temp_a2 + 4);
    if (temp_f0 > 0.0f) {
        *(f32 *)((u8 *)temp_a1 + 0x374) = temp_f0;
    }
    *(s32 *)((u8 *)temp_a1 + 0x378) = (s32) (*(s32 *)((u8 *)temp_a2 + 8));
    temp_f0_2 = *(f32 *)((u8 *)temp_a2 + 0xC);
    if (temp_f0_2 > 0.0f) {
        *(f32 *)((u8 *)temp_a1 + 0x37C) = temp_f0_2;
    }
    *(s32 *)((u8 *)temp_a1 + 0x380) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x10));
    *(s32 *)((u8 *)temp_a1 + 0x384) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x14));
    *(s32 *)((u8 *)temp_a1 + 0x388) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x38));
    *(s32 *)((u8 *)temp_a1 + 0x394) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x68));
    *(s32 *)((u8 *)temp_a1 + 0x390) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x78));
    *(s32 *)((u8 *)temp_a1 + 0x398) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x2C));
    *(s32 *)((u8 *)temp_a1 + 0x39C) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x28));
    *(u8 *)((u8 *)temp_a1 + 0x3AB) = (u8) (*(u8 *)((u8 *)temp_a2 + 0x30));
    *(f32 *)((u8 *)temp_a1 + 0x3C4) = (f32) (*(f32 *)((u8 *)temp_a2 + 0x84));
    *(s32 *)((u8 *)temp_a1 + 0x3D0) = (s32) (*(s32 *)((u8 *)temp_a2 + 0x88));
    *(u16 *)((u8 *)temp_a1 + 0x3A8) = (u16) (*(u16 *)((u8 *)temp_a2 + 0x8C));
    if ((*(u8 *)((u8 *)arg0 + 0x43)) != 0) {
        func_003C3A10((s32) arg0, 0, 0, 0);
    }
}
/* localdecomp:end func_L13_003AF6F8 */
