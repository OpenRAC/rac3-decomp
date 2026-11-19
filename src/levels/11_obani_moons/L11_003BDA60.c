#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L11_003BDA60 */
extern u8 D_L11_001D66B0[8];
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L05_003DC520(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32);
extern void func_L02_003E2E38(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L11_003BDA60(void *self, s32 id, void *direction, s32 unused, s32 sound, s32 sparks, s32 smoke, s32 burst, u32 color, f32 scale, f32 radius) {
    vu0_v4 dir, pos, offset, velocity;
    u8 *m = self;
    vu0_v4 *dirp = &dir;
    *(vu0_q *)dirp = *(vu0_q *)direction;
    func_003A52A0(0, 0, self);
    func_L01_00451FE0(self, id, D_L11_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (sound) func_L05_003DC520(self, sound);
    *(vu0_q *)&pos = *(vu0_q *)(m + 0x10);
    *(vu0_q *)&offset = *(vu0_q *)dirp;
    func_0038CF68(&offset, &offset, (*(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24)) * scale);
    vec_add_ab(&pos, &pos, &offset);
    func_0038CF68(&velocity, dirp, 0.030000001192092896f);
    if (sparks) func_L02_00429840(self, &pos, 1.0f, 15, 0, &velocity, 0.1600000113248825f, 0.5f, 1.0f, color, 0, 58);
    if (smoke) func_L02_003E2E38(self, &pos, &velocity, 15, 0, 1, 1.5f, 0.020000001415610313f, 2.0f, 6.0f, 1.0f);
    if (burst) func_L01_003303B8(&pos, 0, 0, 0, 0, 2, 5, 0, 0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0, radius, 0.0f, 0.0f, 0.0f);
    func_L01_00451E78(self, 1, 0.0f);
    func_003C2880(self);
}
/* localdecomp:end func_L11_003BDA60 */
