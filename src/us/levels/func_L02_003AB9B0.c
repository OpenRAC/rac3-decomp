#include "common.h"

/* NTSC-U counterpart of func_L02_003AD978 (src/levels/02_florana/L02_003AD978.c): 0.018 -> 0.015 */
#include "vu0.h"

/* localdecomp:start func_L02_003AB9B0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L02_001E11E0[];
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_00426140(void *, void *, s32, s32, void *, f32, f32, f32, f32, s32, s32, s32);
extern void func_003BD360(void *);

void func_L02_003AB9B0(u8 *self) {
    vu0_v4 vel, pos, off;
    u8 *r;

    if (func_L01_00444358(self, -1, 0) == 0) return;
    func_0039FE80(0, 0, self);
    func_00388830(&vel, D_L02_001E11E0, 0.0150000006f);
    func_L01_0044ED60(self, 7, &vel, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      -1.0f, -1.0f, 1.0f, 1.0f);
    r = func_L01_0044F1E8(self, 0x1C51, 0);
    if (r != 0) *(s32 *)(r + 0x98) = *(s32 *)(*(u8 **)(r + 0x24) + 0x10);
    *(u128_t *)&pos = 0;
    pos.z = 1.0f;
    func_003886E8(&off, &pos, *(f32 *)(r + 0x2C) * 19.5f);
    vec_add_ab(&pos, &off, self + 0x10);
    func_L02_00426140(self, &pos, 7, 1, &vel, 1.0f, 3.0f, 0.75f, *(f32 *)(r + 0x2C) * 4.5f, 0x30008720, 0, 0xB4);
    func_003BD360(self);
}
/* localdecomp:end func_L02_003AB9B0 */
