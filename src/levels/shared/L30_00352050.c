#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern s32 D_L30_001DF2C0;

/* localdecomp:start func_L30_00352050 */
#include "vu0.h"
__asm__(".extern D_L30_001DF2C0, 16");
__asm__(".extern D_L30_001DDA18, 4");
__asm__(".extern D_L30_001DDA1C, 4");
extern s32 D_L30_001DF2C0;
extern f32 D_L30_001DDA18;
extern f32 D_L30_001DDA1C;
extern u8 D_L30_001E2120[];
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u32 func_L01_00448D88(u32, s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L30_00352050(s32 a0, void *a1, void *a2) {
    vu0_v4 pos;
    vu0_v4 v;
    f32 s;
    f32 a;
    f32 b;
    u32 c1;
    u32 c2;

    if (D_L30_001DF2C0 % 10 != 0) {
        return;
    }
    s = D_L30_001DDA18;
    a = func_003824E0(0.261799395f, 1.04719758f);
    b = func_00382538();
    func_0038CE20(&v, D_L30_001E2120, D_L30_001DDA1C);
    vec_add_ab(&pos, &v, &pos);
    func_00382760(&pos, func_003824E0(7.0f, 10.5f) * 0.0200000014f * 0.7f, b, a);
    func_0038CE20(&v, D_L30_001E2120, D_L30_001DDA1C);
    vec_add_ba(&pos, &v, &pos);
    vec_add_ba(&pos, &pos, a2);
    c1 = func_L01_00448D88(0x4F007FFF, 0);
    c2 = func_L01_00448D88(0x1F00007F, 0);
    func_L01_00465738(a1, &pos, c1, c2, func_00382498(0x21, 0x36), 1, -1, -1, 0, s * 40000.0f);
}
/* localdecomp:end func_L30_00352050 */

INCLUDE_ASM("asm/levels", func_L30_00352208);
