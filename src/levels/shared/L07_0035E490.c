#include "common.h"

/* localdecomp:start func_L07_0035E490 */
typedef struct { u8 p0[0x10]; f32 f10; } S_0035E490;
extern f32 D_L07_001DD75C;
__asm__(".extern D_L07_001DD75C, 4");
extern s32 D_L07_001DD748;
__asm__(".extern D_L07_001DD748, 4");
extern u32 D_L07_001DD758;
__asm__(".extern D_L07_001DD758, 4");
extern f32 D_L07_001DD764;
__asm__(".extern D_L07_001DD764, 4");
extern f32 D_L07_001DD760;
__asm__(".extern D_L07_001DD760, 4");
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L07_0035E490(u8 *a0)
{
    S_0035E490 *p = *(S_0035E490 **)(a0 + 0x68);
    p->f10 = func_0038DAB8(p->f10, D_L07_001DD75C * 0.017453292f);
    func_003D9508(a0 + 0x10, D_L07_001DD748, D_L07_001DD758, 1, D_L07_001DD764, 0.08f, func_00382538());
    func_003D9508(a0 + 0x10, D_L07_001DD748, D_L07_001DD758, 1, D_L07_001DD764, 0.08f, p->f10 * 1.5f);
    func_003D9508(a0 + 0x10, D_L07_001DD748, D_L07_001DD758, 1, D_L07_001DD764, 0.08f, func_0038DAB8(p->f10 * 2.5f, 0.0f));
    func_003D9508(a0 + 0x10, 0x31, 0x10007FFF, 1, 0.36f, 0.08f, p->f10 * 0.5f);
    func_003D9508(a0 + 0x10, 0x31, 0x10007FFF, 1, 0.36f, 0.08f, p->f10 * -0.5f);
    func_003D9508(a0 + 0x10, 0x2F, 0x507F7F7F, 1, D_L07_001DD760, 0.08f, func_00382538());
}
/* localdecomp:end func_L07_0035E490 */
