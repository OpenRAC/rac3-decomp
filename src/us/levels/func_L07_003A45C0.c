#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_003A5D80. */
/* localdecomp:start func_L07_003A45C0 */
extern void func_00388830(f32 *, u8 *, f32);
extern void func_L01_00457440(u8 *, f32 *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(u8 *, u8 *, s32, f32, f32, f32, f32);
extern f32 func_00388800(u8 *, u8 *);
extern void func_L07_00333678(s32, f32, u8 *, u8 *, u8 *);

void func_L07_003A45C0(u8 *obj, u8 side) {
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *rotation;
    u8 *position;
    f32 step[4] __attribute__((aligned(16)));
    f32 direction;
    f32 angle;

    direction = -1.0f;
    if (side == 0) {
        direction = 1.0f;
    }
    position = obj + 0x10;
    rotation = obj + 0xF8;
    func_00388830(step, obj + 0xD0, direction * 50.0f * 0.033333335f);
    vec_add_ba(step, position, step);
    func_L01_00457440(obj, step);
    angle = func_00388A28(*(f32 *)(state + 0x130) - *(f32 *)(obj + 0x10),
                          *(f32 *)(state + 0x134) - *(f32 *)(obj + 0x14));
    func_L01_00445758(rotation, state + 0x204, 0, angle, *(f32 *)(state + 0x164),
                       *(f32 *)(state + 0x168), *(f32 *)(state + 0x16C));
    if ((*(u16 *)(obj + 0x96) & 7) == 0) {
        if (side == 0) {
            func_L07_00333678(*(s32 *)(state + 0x270), func_00388800(position, state + 0x130), obj, state + 0x4A0, 0);
        } else {
            func_L07_00333678(*(s32 *)(state + 0x270), func_00388800(position, state + 0x130), obj, 0, state + 0x4A0);
        }
    }
    *(u16 *)(obj + 0x96) += 1;
}
/* localdecomp:end func_L07_003A45C0 */
