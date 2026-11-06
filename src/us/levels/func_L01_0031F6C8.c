#include "common.h"

/* localdecomp:start func_L01_0031F6C8 */
extern void func_L01_0031F858(u8 *);
extern u8 *func_L01_00469378(u8 *, s32, s32, s32);
extern void func_L01_0031F768(u8 *);
extern f32 func_L01_0040CEC8(f32, f32);

void func_L01_0031F6C8(u8 *object) {
    u8 *effect;
    if (object[0x20] == 0) {
        func_L01_0031F858(object);
        effect = func_L01_00469378(object + 0x10, 15, 0, 0);
        if (effect != 0) {
            *(f32 *)(effect + 0xC) = 157500.0f;
        }
        *(f32 *)(object + 0xF0) = func_L01_0040CEC8(*(f32 *)(object + 0xF0), 0.0349065885f);
        *(f32 *)(object + 0xF4) = func_L01_0040CEC8(*(f32 *)(object + 0xF4), 0.1308996975f);
        func_L01_0031F768(object);
    }
}
/* localdecomp:end func_L01_0031F6C8 */
