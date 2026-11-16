/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Context blocked: exact existing func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32) type is declared after entry; hoist original typedef/prototype for Claude, no incompatible alias used. Ordinary wrapper COMPILE ERROR in 30BF20-wrapper-context.log; ...
 */
#include "common.h"
/* localdecomp:start func_L01_0030BF20 */
#include "vu0.h"
void func_L01_0030BF20(f32 *position, f32 *direction, s32 count, u32 color) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046B458(f32, f32, f32, void *, s32, u32, s32, s32, void *, s32);
    vu0_v4 velocity;
    vu0_v4 original;
    vu0_v4 angles;
    vu0_v4 matrix[3];
    f32 scale;
    s32 sign, random, remaining;

    u8 *particle;
    if (count <= 0) return;
    {
    f32 outer = 0.1f;
    f32 inner = 0.07f;
    f32 shrink = 0.7f;
    remaining = count;
    do {
        scale = func_003824E0(1.75f, 2.0f);
        sign = func_00382468(2);
        if (!sign) sign--;
        angles.w = 0;
        angles.y = func_003824E0(-1.5707964f, 1.5707964f);
        angles.x = func_003824E0(-1.5707964f, 1.5707964f);
        angles.z = func_003824E0(-1.5707964f, 1.5707964f);
        func_0038D308(matrix, &angles);
        func_0038D000(&velocity, direction, matrix);
        func_0038CF68((void *)&velocity, (void *)&velocity, 0.05f);
        velocity.z += 0.060000002f;
        *(vu0_q *)&original = *(vu0_q *)position;
        position[0] += func_L01_00443A18(0.0f, 0.15f);
        position[1] += func_L01_00443A18(0.0f, 0.15f);
        position[2] += func_L01_00443A18(0.0f, 0.15f);
        random = (u32)func_0013D3E0() % 2;
        particle = func_L01_0046B458(scale * outer, scale, 0.0028800003f, position, 50, color | 0x4F000000, 0, sign, &velocity, 1);
        if (particle) particle[9] = 0x74;
        particle = func_L01_0046B458(scale * inner, scale * shrink, 0.0028800003f, position, 50, 0x7FFFFFFF, 1, -sign, &velocity, 1);
        if (particle) particle[9] = 0x74;
    } while (--remaining);
    }
}
/* localdecomp:end func_L01_0030BF20 */
