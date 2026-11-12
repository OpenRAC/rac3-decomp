#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L09_003E75B0);

INCLUDE_ASM("asm/levels", func_L09_003E7BC0);

/* localdecomp:start func_L09_003E7DA8 */
extern s32 D_L09_001DF2A8;
__asm__(".extern D_L09_001DF2A8, 4");
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0046E078(u8 *, void *, f32 *, s32 *, s32);

void func_L09_003E7DA8(u8 *a0) {
    u8 *p;
    f32 r0;
    f32 pos[4];
    f32 vel[4];
    p = *(u8 **)(a0 + 0x68);
    r0 = func_0038CEA8(p);
    vel[0] = func_003824E0(-1.0f, -0.9f) * r0;
    vel[1] = func_003824E0(-0.05f, 0.05f) * r0;
    vel[2] = func_003824E0(-0.05f, 0.05f) * r0;
    vec_sub_ab(pos, a0 + 0x10, p);
    func_L01_0046E078(a0, pos, vel, &D_L09_001DF2A8, 1);
}
/* localdecomp:end func_L09_003E7DA8 */
