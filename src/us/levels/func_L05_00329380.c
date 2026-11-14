#include "common.h"

/* localdecomp:start func_L05_00329380 */
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);

void func_L05_00329380(s32 a0, u8 *obj, f32 *p1, f32 *p2, f32 *p3) {
    *(f32 *)(obj + 0x150) = func_00389380(*(f32 *)(obj + 0x150), 0.0349065885f);
    *p1 = func_00388978(*(f32 *)(obj + 0x150)) * 0.2f;
    *p2 = func_00388978(*(f32 *)(obj + 0x154)) * 0.0785398185f * func_00388978(*(f32 *)(obj + 0x158));
    *p3 = func_00388978(*(f32 *)(obj + 0x154)) * 0.0785398185f * func_00388960(*(f32 *)(obj + 0x158));
    *(f32 *)(obj + 0x154) = func_00389380(*(f32 *)(obj + 0x154), 0.020362176f);
    *(f32 *)(obj + 0x158) = func_00389380(*(f32 *)(obj + 0x158), 0.0290888231f);
}
/* localdecomp:end func_L05_00329380 */
