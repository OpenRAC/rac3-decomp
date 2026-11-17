#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_003067B8);

/* localdecomp:start func_L02_00306C88 */
#include "vu0.h"

extern f32 D_L02_001E00A0;
__asm__(".extern D_L02_001E00A0, 4");
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_003016B0(void *, s32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0046A938(void *, void *, s32, f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00468A68(void *, void *, s32, s32);

void func_L02_00306C88(u8 *o) {
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
    D_L02_001E00A0 = func_003C3D30(o + 0x10, 0, 0, 0.5f);
    pos.z = D_L02_001E00A0;
    func_L01_003016B0(&pos, 3, 4.5f, 1.025f);
    for (i = 4; i >= 0; i--) {
        v10.x = *(f32 *)(o + 0x10) + (f32)n * func_003824E0(-0.3f, 0.3f);
        v10.y = *(f32 *)(o + 0x14) + (f32)n * func_003824E0(-0.3f, 0.3f);
        v10.z = D_L02_001E00A0;
        func_L01_0046A938(&v10, &D_L02_001E00A0, -1, (f32)n * func_003824E0(0.3f, 0.6f), 5250.0f);
    }
    for (j = 39; j >= 0; j--) {
        a = func_00382538();
        k = (f32)n * func_003824E0(0.0f, 0.060000002f);
        v10.x = func_0038D098(a) * k;
        v10.y = func_0038D0B0(a) * k;
        v10.z = (f32)n * func_003824E0(0.040000003f, 0.10000001f);
        t = v10.x * 8.0f;
        v20.x = *(f32 *)(o + 0x10) + t;
        v20.y = *(f32 *)(o + 0x14) + t;
        v20.z = D_L02_001E00A0 - func_003824E0(0.0f, 0.2f);
        c = func_00382468(2);
        func_L01_00468A68(&v20, &v10, c, n * func_00382498(0x5A, 0x78));
    }
}
/* localdecomp:end func_L02_00306C88 */
