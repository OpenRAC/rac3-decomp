#include "common.h"

/* localdecomp:start func_L01_003CA050 */
extern void func_L01_00407180(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00437698(u8 *, s32, f32 *);

void func_L01_003CA050(u8 *object) {
    u8 *vars = *(u8 **)(object + 0x68);
    f32 position[4];

    func_L01_00407180(object, object + 0x10, object + 0xF0,
                       0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
    if (*(u8 **)(vars + 0x550) != 0) {
        func_L01_00437698(object, 0, position);
        func_L01_00407180(*(u8 **)(vars + 0x550), (u8 *)position, object + 0xF0,
                           0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
    }
}
/* localdecomp:end func_L01_003CA050 */
