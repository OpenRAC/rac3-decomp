#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_003B4C30. */
/* localdecomp:start func_L07_003B3340 */
extern u8 *D_L07_0021EE04 __attribute__((section(".data")));
void func_L07_003B3340(void *self, u8 side, f32 amount, u8 kind)
{
    extern void func_003BD9A0(void *, s32, void *);
    extern void func_00388830(void *, void *, f32);
    extern void func_003BF6A8(void *, f32);
    extern u8 *func_L01_00471970(void *, void *, void *, f32, f32, f32, u32, s32, s32, s32, s32);
    vu0_v4 matrix[4];
    vu0_v4 position;
    vu0_v4 velocity;
    u8 *effect;
    func_003BD9A0(self, side * 3 + 8, matrix);
    if (side == 1) vec_neg(matrix, matrix);
    func_00388830(&position, matrix, 1.0f);
    vec_add_ab(&position, &matrix[3], &position);
    func_00388830(&velocity, matrix, 0.3333333432674408f);
    func_003BF6A8(&velocity, 0.03333333507180214f);
    effect = func_L01_00471970(self, &position, &velocity, *(f32 *)((u8 *)self + 0x18), 84000.0f, amount * 420000.0f,
        0x7F808080, (s32)(amount * 50.0f), 5, kind, 0);
    if (effect) effect[2] = D_L07_0021EE04[0];
    if (amount >= 1.0f) {
        func_003BF6A8(&position, 0.2f);
        effect = func_L01_00471970(self, &position, &velocity, *(f32 *)((u8 *)self + 0x18), 84000.0f, 84000.0f,
            0x7F808080, 10, 0, 0, 0);
        if (effect) effect[2] = D_L07_0021EE04[0];
    }
}
/* localdecomp:end func_L07_003B3340 */
