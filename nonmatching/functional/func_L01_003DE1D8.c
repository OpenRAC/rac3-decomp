/* functional: high. Codex near miss, 128 words differ: stack layout, VU0 vsub scheduling, callee-saved register choice, loop test bgtz vs bnez (count is already > 0). I changed D_L01_00221098 to the file's u8 *[] (cast to s32 for the add). */
#include "common.h"
/* localdecomp:start func_L01_003DE1D8 */
#include "vu0.h"
extern vu0_v4 D_001A4EC0;
extern s32 D_001DF540_sda;
extern u8 *D_001DF544_sda;
__asm__(".extern D_001DF540_sda, 4");
__asm__(".extern D_001DF544_sda, 4");
void func_L01_003DE1D8(u8 *self, vu0_q *source) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    vu0_v4 step;
    vu0_q position;
    vu0_v4 velocity;
    vu0_v4 input;
    f32 length;
    u8 *state;
    s32 count, i;
    *(vu0_q *)&input = *source;
    state = *(u8 **)(self + 0x68);
    position = *(vu0_q *)&input;
    length = *(f32 *)(state + 0x68);
    vec_sub_ba(&step, self + 0x10, &input);
    count = (s32)(length / 0.1f) / 4;
    func_0038CF68(&step, &step, length / count);
    for (i = count; i > 0; --i) {
        s32 kind = (s32)func_L01_00443A18(1.0f, 3.0f);
        s32 life;
        s32 texture;
        f32 size;
        u32 color;
        u8 *particle;
        func_0038CE20(&velocity, &D_001A4EC0, -(func_003824E0(0.2f, 1.0f) * 0.020000001415610313f));
        life = func_00382498(20, 40);
        size = func_003824E0(200.0f, 1000.0f);
        if (func_0013D3E0() & 2) { texture = 80; color = 0x204080; }
        else { texture = 80; color = 0x4080FF; }
        particle = func_L01_0046A610(&position, &velocity, (life * 5 + 2) / 6, texture, color, kind, 21000.0f, size, 1.0f, 0.0f, 1.0f);
        vec_add_ab(&position, &position, &step);
        if (particle) {
            particle[2] = *(u8 *)((s32)D_L01_00221098[D_001DF540_sda] + (s32)D_001DF544_sda);
            particle[3] = texture == 64 ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L01_003DE1D8 */
