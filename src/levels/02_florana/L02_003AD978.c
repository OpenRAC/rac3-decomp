#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_003AD978 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L02_001E1160[];
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, f32, f32, f32, f32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L02_003AD978(u8 *self) {
    vu0_v4 vel, pos, off;
    u8 *r;

    if (func_L01_00447490(self, -1, 0) == 0) return;
    func_003A52A0(0, 0, self);
    func_0038CF68(&vel, D_L02_001E1160, 0.018000001f);
    func_L01_00451FE0(self, 7, &vel, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      -1.0f, -1.0f, 1.0f, 1.0f);
    r = func_L01_00452460(self, 0x1C51, 0);
    if (r != 0) *(s32 *)(r + 0x98) = *(s32 *)(*(u8 **)(r + 0x24) + 0x10);
    *(u128_t *)&pos = 0;
    pos.z = 1.0f;
    func_0038CE20(&off, &pos, *(f32 *)(r + 0x2C) * 19.5f);
    vec_add_ab(&pos, &off, self + 0x10);
    func_L02_00429840(self, &pos, 7, 1, &vel, 1.0f, 3.0f, 0.75f, *(f32 *)(r + 0x2C) * 4.5f, 0x30008720, 0, 0xB4);
    func_003C2880(self);
}
/* localdecomp:end func_L02_003AD978 */
