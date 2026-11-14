#include "common.h"

/* NTSC-U counterpart of func_L14_00353910 (src/levels/14_koros/L14_00353718.c): 125 -> 150; 0.05 -> 0.0416667 */
#include "vu0.h"
extern u8 D_L14_001D66B0_003528F8;

/* localdecomp:start func_L14_003528F8 */
extern u8 D_L14_001D66B0_003528F8;
extern void func_L02_00426140(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
void func_L14_003528F8(void *a0, void *pos, void *dir, s32 n) {
    vu0_v4 p;
    vu0_v4 d;
    p = *(vu0_v4 *)pos;
    d = *(vu0_v4 *)dir;
    func_L02_00426140(a0, &p, 5, 0, &D_L14_001D66B0_003528F8, 0xC850C828, 0, 0x96, 0.0f, 10.0f, 0.8f, 1.2f);
    func_L02_003E0520(a0, &p, 0.0f, &D_L14_001D66B0_003528F8, 10, 0, 0.0416666679f, 1.5f, 3.0f, 1.0f, 1);
}
/* localdecomp:end func_L14_003528F8 */
