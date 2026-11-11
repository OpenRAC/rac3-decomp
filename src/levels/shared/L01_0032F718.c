#include "common.h"


/* localdecomp:start func_L01_0032F718 */
/* m2c3 */
s32 func_L01_0032F800(void *, void *);              /* extern */
f32 func_L01_004451A8(f32);                             /* extern */
s32 func_L01_0044C280(void *, void *, void *, s32, f32); /* extern */

void func_L01_0032F718(void *arg0) {
    void *temp_18;
    void *temp_20;

    temp_20 = (*(void **)((u8 *)(arg0) + 0x68));
    temp_18 = temp_20 + 0x30;
    func_L01_0044C280(temp_18, temp_20 + 0x10, temp_20 + 0x20, 0, func_L01_004451A8((*(f32 *)((u8 *)(temp_20) + 0x54))));
    (*(f32 *)((u8 *)(temp_20) + 0x54)) = (f32) ((*(f32 *)((u8 *)(temp_20) + 0x54)) + (*(f32 *)((u8 *)(temp_20) + 0x58)));
    func_L01_0032F800(arg0, temp_18);
    if ((*(f32 *)((u8 *)(temp_20) + 0x54)) > 0.9f) {
        (*(s32 *)((u8 *)(temp_20) + 0x50)) = 1;
    } else {
        (*(s32 *)((u8 *)(temp_20) + 0x50)) = 0;
    }
    if ((*(f32 *)((u8 *)(temp_20) + 0x54)) >= 1.0f) {
        (*(f32 *)((u8 *)(temp_20) + 0x54)) = 1.0f;
        (*(s16 *)((u8 *)(temp_20) + 0x4C)) = 1;
    }
}
/* localdecomp:end func_L01_0032F718 */
