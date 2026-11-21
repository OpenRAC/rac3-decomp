#include "common.h"

/* NTSC-U counterpart of func_L02_00306C88 (src/levels/shared/L02_00306C88.c): 0.06 -> 0.05; 0.04 -> 0.0333333; 0.1 -> 0.0833333 */
/* localdecomp:start func_L02_00306A00 */
#include "vu0.h"

extern f32 D_L02_001E0120;
__asm__(".extern D_L02_001E0120, 4");
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00301508(void *, s32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00467288(void *, void *, s32, f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00465410(void *, void *, s32, s32);

void func_L02_00306A00(u8 *o) {
    vu0_v4 pos;
    vu0_v4 v10;
    vu0_v4 v20;
    s32 n = 2;
    s32 i;
    s32 c;
    s32 j;
    f32 a;
    f32 k;
    f32 t;

    pos = *(vu0_v4 *)(o + 0x10);
    D_L02_001E0120 = func_003BE7F0(o + 0x10, 0, 0, 0.5f);
    pos.z = D_L02_001E0120;
    func_L01_00301508(&pos, 3, 4.5f, 1.025f);
    for (i = 4; i >= 0; i--) {
        v10.x = *(f32 *)(o + 0x10) + (f32)n * func_0037E250(-0.3f, 0.3f);
        v10.y = *(f32 *)(o + 0x14) + (f32)n * func_0037E250(-0.3f, 0.3f);
        v10.z = D_L02_001E0120;
        func_L01_00467288(&v10, &D_L02_001E0120, -1, (f32)n * func_0037E250(0.3f, 0.6f), 5250.0f);
    }
    for (j = 39; j >= 0; j--) {
        a = func_0037E2A8();
        k = (f32)n * func_0037E250(0.0f, 0.0500000045f);
        v10.x = func_00388960(a) * k;
        v10.y = func_00388978(a) * k;
        v10.z = (f32)n * func_0037E250(0.0333333351f, 0.0833333358f);
        t = v10.x * 8.0f;
        v20.x = *(f32 *)(o + 0x10) + t;
        v20.y = *(f32 *)(o + 0x14) + t;
        v20.z = D_L02_001E0120 - func_0037E250(0.0f, 0.2f);
        c = func_0037E1D8(2);
        func_L01_00465410(&v20, &v10, c, n * func_0037E208(0x5A, 0x78));
    }
}
/* localdecomp:end func_L02_00306A00 */
