/* func_L05_003BDFA8: near miss (file L05_003BD078.c). MATCH with -mvu0-use-vf0-vf2 -fno-sched-interblock @ps2as (87 without -fno-sched-interblock): gcc's inter-block scheduler hoists the if-body's constants and the loop decrement above the `if (r != 0)` test, retail did not; same spawn code as the matched func_L19_003C41F0. -fno-sched-interblock is not a flag the level build uses (build-fidelity rule 5), so this stays a draft until the maintainers allow it */
#include "common.h"
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L05_001E2680;

void func_L05_003BDFA8(vu0_v4 *pos) {
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 c;
    u8 *r;
    u8 *t;
    s32 i;
    s32 k;
    f32 sz;

    vec_sub_ab(&d, &D_L05_001E2680, pos);
    for (i = 0; i < 20; i++) {
        func_0038CE20(&a, &D_001A4EC0, -(func_003824E0(0.2f, 3.0f) * 0.020000001f));
        k = (s32)func_L01_00443A18(1.0f, 2.0f);
        sz = func_003824E0(0.3f, 0.75f) * 210000.0f;
        c.x = pos->x + func_L01_00443A18(0.0f, 0.2f);
        c.y = pos->y + func_L01_00443A18(0.0f, 0.2f);
        c.z = pos->z + func_L01_00443A18(0.0f, 0.2f);
        r = func_L01_004669B0(&c, 0.0f, 1.0f, 1.01f, sz, k, &a, 0x7F202020, 0);
        if (r != 0) {
            *(s16 *)(r + 0xA) = 0x4B;
            t = r + 0x20;
            r[0x3] = 0x44;
            r[0x9] = 0x44;
            *(f32 *)(t + 0x1C) = 4.0f;
            *(s32 *)(t + 0x4) = 3;
            t[0xA] = 0x30;
            t[0xB] = r[0xA];
        }
    }
}
