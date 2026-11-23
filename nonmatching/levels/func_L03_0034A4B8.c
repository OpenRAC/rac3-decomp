/* PAL draft (2026-11-21, Promises): written from level 3's assembly. 8 words differ at level 03
 * with its file's flags: ours keeps a duplicated blez count guard and loads delta.z before it;
 * retail has one guard and loads z after it. Do-while and counting-down wordings keep &axis in an
 * extra saved register instead (161 diff).
 * LV-R2 retry (2026-11-22): 8 differences (tools/check.py) at level 03 with the file's flags. A down-counting do-while in the wrapper gives retail's single guard but hoists &axis into an extra saved register (161); every guard/test spelling gives 8.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_0034A4B8 */
extern vu0_v4 D_L03_001E2440;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(void *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind, s32 spin, void *velocity, f32 unk, s32 delay);

void func_L03_0034A4B8(void *arg0, s32 count) {
    f32 *position = arg0;
    vu0_v4 velocity, at, delta, axis, base;
    f32 size, angle, z;
    s32 spin, i;
    u8 *p;
    vec_sub_ab(&delta, &D_L03_001E2440, position);
    func_0038CF68(&base, &delta, 0.3f);
    delta.z = 0.0f;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    axis.w = 1.0f;
    if (count > 0) {
    z = delta.z;
    for (i = 0; i < count; i++) {
        size = func_003824E0(0.5f, 2.0f);
        spin = func_00382468(2);
        if (spin == 0) spin--;
        angle = func_003824E0(-1.0471976f, 1.0471976f);
        func_0038D890(&velocity, &delta, &axis, angle);
        func_0038CF68(&velocity, &velocity, func_003824E0(0.05f, 3.0f) * 0.020000001f);
        velocity.z = func_003824E0(1.0f, 5.0f) * 0.020000001f;
        vec_add_ab(&at, position, &base);
        position[0] += func_L01_00443A18(z, 0.15f);
        position[1] += func_L01_00443A18(z, 0.15f);
        position[2] += func_L01_00443A18(z, 0.15f);
        p = func_L01_0046B458(&at, 50, size * 0.1f, size, 0xDD10FF10, 0, spin, &velocity, 0.0028800003f, 0);
        if (p) p[9] = 0x74;
        p = func_L01_0046B458(&at, 50, size * 0.07f, size * 0.7f, 0xDD10FF10, 1, -spin, &velocity, 0.0028800003f, 0);
        if (p) p[9] = 0x74;
    }
    }
}
/* localdecomp:end func_L03_0034A4B8 */
