/* functional: high. 44 words differ: only scheduling/branch layout (the compiler reloads D_L31_001E9180 base after the collision test); reads, writes, calls and args equal retail. Needs the file's vu0 flag line (already set for this file). */
/* localdecomp:start func_L31_00346838 */
#include "vu0.h"
__asm__(".extern D_L31_001DCFCC, 4");
__asm__(".extern D_L31_001DCFD0, 4");
extern f32 D_L31_001DCFCC;
extern f32 D_L31_001DCFD0;
extern u8 D_L31_001E9180[];
extern vu0_v4 D_L31_001E91A0;
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L30_003445B8(u8 *);
extern void func_L30_00343830(u8 *, void *, void *, f32);
s32 func_L31_00346838(void *a0, void *a1, vu0_v4 *a2, s32 a3, f32 f12, f32 f13) {
    vu0_v4 v0, v10, v20, v30;
    u8 *moby;

    v0 = *(vu0_v4 *)a1;
    v0.z += f13;
    func_0038CF68(&v20, a2, f12 + D_L31_001DCFCC);
    vec_add_ab(&v10, &v0, &v20);
    if (func_003D3CB0(&v0, &v10, 2, a0, 0) == 0) {
        return 0;
    }
    moby = *(u8 **)(D_L31_001E9180 + 0x18);
    if (moby != 0) {
        if (func_L30_003445B8(moby) != 0) {
            func_L30_00343830(*(u8 **)(D_L31_001E9180 + 0x18), &v30, &v0, f12 + D_L31_001DCFD0);
        }
    }
    if (!(func_0038CF00(&v0, &D_L31_001E91A0) < f12) && a3 == 0) {
        return 1;
    }
    vec_sub_ab(&v20, &v0, &D_L31_001E91A0);
    func_0038CF68(&v20, &v20, f12);
    vec_add_ab(&v0, &D_L31_001E91A0, &v20);
    *(vu0_v4 *)a1 = v0;
    ((vu0_v4 *)a1)->z -= f13;
    return 1;
}
/* localdecomp:end func_L31_00346838 */
