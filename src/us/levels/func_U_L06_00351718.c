#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L06_00352410. */
/* localdecomp:start func_U_L06_00351718 */
extern vu0_v4 D_L06_001D66B0 __attribute__((section(".sdata")));
extern void func_L06_0034FF58(u8 *, u8 *, s32, void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_L06_00357C38(u8 *, void *, void *, s32, f32, f32);
extern void func_L01_00467DA8(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00351718;
void func_U_L06_00351718(u8 *a0, u8 *a1, s32 a2) {
    V_00351718 pos;
    V_00351718 v10;
    V_00351718 v20;
    V_00351718 v30[4];
    func_L06_0034FF58(a0, a1, a2, v30, &pos, &v10);
    func_003886E8(&v20, &v10, 0.5833333730697632f);
    func_L06_00357C38(a0, &pos, &v20, *(s32 *)(a1 + 0x37C),
                      -func_00388A28(func_003887A0(v30), v30[0].z), (f32)a1[0x44]);
    func_L01_00467DA8(&pos, 10, 0x5F007000, 0, 2, &D_L06_001D66B0, 0, 4.0f, 5.0f, 0.0f);
}
/* localdecomp:end func_U_L06_00351718 */
