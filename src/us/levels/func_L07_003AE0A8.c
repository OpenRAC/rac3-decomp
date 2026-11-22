#include "common.h"

/* NTSC-U counterpart of func_L07_003AF920. */
/* localdecomp:start func_L07_003AE0A8 */
#include "vu0.h"
extern f32 D_L07_001DE478, D_L07_001DE47C, D_L07_001DE480;
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DE478, 4");
__asm__(".extern D_L07_001DE47C, 4");
__asm__(".extern D_L07_001DE480, 4");
void func_L07_003AE0A8(u8 *self) {
    extern void func_003BD9A0(void *, s32, void *);
    extern void func_00388830(void *, void *, f32);
    extern void func_L07_003C9438(void *, void *, void *, s32, s32, s32, u32, f32, f32);
    extern void func_L01_00467DA8(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
    extern void func_L01_0046D570(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
    vu0_v4 matrix[4], direction, point, sum, position, particle;
    u8 *state = *(u8 **)(self + 0x68);
    func_003BD9A0(self, 1, matrix);
    *(vu0_q *)&direction = *(vu0_q *)&matrix[1];
    *(vu0_q *)&point = *(vu0_q *)&matrix[3];
    func_00388830(&direction, &direction, D_L07_001DE478 * 0.01666666753590107f);
    *(vu0_q *)&position = *(vu0_q *)&matrix[3];
    *(vu0_q *)&particle = *(vu0_q *)&matrix[3];
    vec_add_ab(&sum, &position, &direction);
    func_L07_003C9438(&position, &direction, self, 0, 0, -1, 0xFFFFFFFFu, D_L07_001DE47C, (f32)state[0x64]);
    func_L01_00467DA8(&particle, 9, 0xBF204080, 2, 1, D_L07_001D66B0, 1, D_L07_001DE480 * 7.0f, 0.1f, 0.0f);
    func_L01_00467DA8(&particle, 9, 0xBF2040A0, 2, -1, D_L07_001D66B0, 1, D_L07_001DE480 * 5.0f, 0.1f, 0.0f);
    func_L01_00467DA8(&particle, 9, 0xC0FFFFFF, 2, 1, D_L07_001D66B0, 1, D_L07_001DE480 * 3.5f, 0.1f, 0.0f);
    func_L01_00467DA8(&particle, 9, 0xB0FFFFFF, 2, -1, D_L07_001D66B0, 1, D_L07_001DE480 * 2.5f, 0.1f, 0.0f);
    func_L01_0046D570(&particle, 7, 0x46787878, 2, 2, D_L07_001D66B0, 0, 2, 6, 1, 1.08f, 0.8400000333786011f);
    func_L01_0046D570(&particle, 10, 0x46787878, 2, -1, D_L07_001D66B0, 1, 2, 6, 1, 2.0400002002716064f, 0.8400000333786011f);
    func_L01_0046D570(&particle, 10, 0x2D787878, 2, 1, D_L07_001D66B0, 1, 2, 6, 1, 2.4000000953674316f, 1.8000000715255737f);
}
/* localdecomp:end func_L07_003AE0A8 */
