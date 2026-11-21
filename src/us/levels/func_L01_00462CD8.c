#include "common.h"

/* NTSC-U counterpart of func_L01_00466290 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "vu0.h"

/* localdecomp:start func_L01_00462CD8 */
#include "vu0.h"
void func_L01_00462CD8(u8 *self)
{
    extern f32 func_00388978(f32);
    extern f32 func_00388960(f32);
    extern void func_003888F0(void *, void *, void *);
    extern void func_003BDA38(void *, s32, void *);
    extern void func_00388830(void *, void *, f32);
    extern f32 func_00389380(f32, f32);
    extern f32 func_L01_00445D88(void *, void *, void *, s32);
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    vu0_v4 target, local, delta;
    vu0_q matrix[4];
    u8 *state = self + 0x20;
    f32 f;
    if (*(f32 *)(state + 0x10) != 0.0f) {
        u8 *source = *(u8 **)state;
        u8 *position = self + 0x10;
        matrix[0] = *(vu0_q *)source;
        matrix[1] = *(vu0_q *)(source + 0x10);
        matrix[2] = *(vu0_q *)(source + 0x20);
        local.y = func_00388978(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.z = func_00388960(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.x = 0.0f;
        local.w = 0.0f;
        func_003888F0(&delta, &local, matrix);
        vec_sub_ba(position, position, &delta);
        *(f32 *)(state + 0x1C) += 0.060010001f;
        func_003BDA38(*(void **)(state + 0x18), 0, &target);
        vec_sub_ab(&local, &target, position);
        func_00388830(&local, &local, *(f32 *)(state + 0x1C));
        vec_add_ba(position, position, &local);
        *(f32 *)(state + 0x14) = func_00389380(*(f32 *)(state + 0x14), 0.5235988f);
        *(f32 *)(state + 0x10) *= 0.9f;
        local.y = func_00388978(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.z = func_00388960(*(f32 *)(state + 0x14)) * *(f32 *)(state + 0x10);
        local.x = 0.0f;
        local.w = 0.0f;
        func_003888F0(&delta, &local, matrix);
        vec_add_ab(position, position, &delta);
        if (func_L01_00445D88(&target, *(u8 **)(state + 0x18) + 0xC0, position, 1) > 0.0f) {
            func_003C7CE0(self);
            return;
        }
    }
    *(f32 *)(state + 4) += *(f32 *)(state + 0xC) * 0.011f;
    if (*(f32 *)(state + 4) <= 0.0f || func_003883C8(self + 0xA)) {
        func_003C7CE0(self);
    } else {
        f = *(f32 *)(state + 4);
        if (f >= 1.0f) {
            f32 step = -*(f32 *)(state + 0xC);
            *(f32 *)(state + 0xC) = step;
            *(f32 *)(state + 4) = f + step * 0.011f;
        }
        *(f32 *)(self + 0xC) += -2940.0f;
        *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) | ((s32)(*(f32 *)(state + 4) * 255.0f) << 24);
        *(f32 *)(state + 8) += 0.006f;
        if (*(f32 *)(state + 8) > 1.0f) *(f32 *)(state + 8) -= 1.0f;
        self[8] = (s32)(*(f32 *)(state + 8) * 255.0f);
    }
}
/* localdecomp:end func_L01_00462CD8 */
