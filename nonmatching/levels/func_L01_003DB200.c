/* PAL near miss (Codex wave 10): near miss: 86 words differ with the file's flags.
 * Worker's note: 87 diff in func_L01_003DB200.09.log; loop decrement and branch/call setup schedule differs; no all-place proof
 */
#include "common.h"
/* localdecomp:start func_L01_003DB200 */
#include "vu0.h"
extern vu0_v4 D_001A4EC0;
typedef struct { u8 pad[0x5C]; u8 *value; } S_003DB200;
extern S_003DB200 D_L01_00221098;
void func_L01_003DB200(u8 *obj, vu0_q *position) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, f32, f32, f32, f32, f32, s32, s32, u32, s32);
    vu0_v4 input;
    vu0_v4 velocity;
    vu0_v4 pos;
    vu0_v4 delta;
    s32 count, frames, mode, intensity;
    s32 i;
    u32 color;
    f32 speed;
    *(vu0_q *)&input = *position;
    *(vu0_q *)&pos = *(vu0_q *)&input;
    vec_sub_ab(&delta, obj + 0x10, &input);
    func_0038CF68(&delta, &delta, 0.1f);
    i = 9;
    while (i >= 0) {
        u8 *particle;
        count = (s32)func_L01_00443A18(1.0f, 3.0f);
        speed = func_003824E0(0.2f, 1.0f);
        func_0038CE20(&velocity, &D_001A4EC0, -(speed * 0.020000001415610313f));
        frames = func_00382498(30, 55);
        speed = func_003824E0(200.0f, 1000.0f);
        if ((func_0013D3E0() & 2) == 0) { color = 0x4080FF; intensity = 80; }
        else { speed *= 2.0f; color = 0x104080; intensity = 64; }
        particle = func_L01_0046A610(&pos, &velocity, 31500.001953125f, speed, 1.0f, 0.0f, 0.0f, (frames * 5 + 2) / 6, intensity, color, count);
        vec_add_ab(&pos, &pos, &delta);
        if (particle) {
            particle[2] = *D_L01_00221098.value;
            particle[3] = intensity == 80 ? 0x48 : 0x44;
        }
        i--;
    }
}
/* localdecomp:end func_L01_003DB200 */
