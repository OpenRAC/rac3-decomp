#include "common.h"

/* NTSC-U counterpart of func_L07_003C84F8. */
/* localdecomp:start func_L07_003C6B50 */
#include "vu0.h"
void func_L07_003C6B50(u8 *obj, void *point) {
    extern f32 func_00388730(f32 *, f32 *);
    extern f32 func_00389410(f32);
    extern void func_00389018(void *, s32, f32);
    extern void func_00388F50(void *, void *, void *);
    extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
    vu0_v4 delta;
    vu0_v4 rotation;
    u8 *state = *(u8 **)(obj + 0x68);
    vec_sub_ba(&delta, obj + 0x10, point);
    {
        f32 angle = func_00388730((f32 *)&delta, (f32 *)(obj + 0xC0));
        angle = func_00389410(angle / 0.3f);
        func_00389018(&rotation, 1, angle);
    }
    func_00388F50(state + 0x3D0, state + 0x3D0, &rotation);
    func_L01_0044B5C8(obj, state + 0x240, 6, 0.01f, 0.3f);
    func_L01_0044B5C8(obj, state + 0x2C0, 3, 0.03f, 0.3f);
    func_L01_0044B5C8(obj, state + 0x340, 4, 0.03f, 0.3f);
}
/* localdecomp:end func_L07_003C6B50 */
