#include "common.h"

/* NTSC-U counterpart of func_L30_00352050 (src/levels/shared/L30_00352050.c) */
extern s32 D_L30_001DF2C0_00351128;

/* localdecomp:start func_L30_00351128 */
#include "vu0.h"
__asm__(".extern D_L30_001DF2C0_00351128, 16");
__asm__(".extern D_L30_001DDA58, 4");
__asm__(".extern D_L30_001DDA5C, 4");
extern s32 D_L30_001DF2C0_00351128;
extern f32 D_L30_001DDA58;
extern f32 D_L30_001DDA5C;
extern u8 D_L30_001E2120_00351128[];
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_003886E8(void *, void *, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u32 func_L01_00445C50(u32, s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L30_00351128(s32 a0, void *a1, void *a2) {
    vu0_v4 pos;
    vu0_v4 v;
    f32 s;
    f32 a;
    f32 b;
    u32 c1;
    u32 c2;

    if (D_L30_001DF2C0_00351128 % 10 != 0) {
        return;
    }
    s = D_L30_001DDA58;
    a = func_0037E250(0.261799395f, 1.04719758f);
    b = func_0037E2A8();
    func_003886E8(&v, D_L30_001E2120_00351128, D_L30_001DDA5C);
    vec_add_ab(&pos, &v, &pos);
    func_0037E4B8(&pos, func_0037E250(7.0f, 10.5f) * 0.01666666753590107f * 0.7f, b, a);
    func_003886E8(&v, D_L30_001E2120_00351128, D_L30_001DDA5C);
    vec_add_ba(&pos, &v, &pos);
    vec_add_ba(&pos, &pos, a2);
    c1 = func_L01_00445C50(0x4F007FFF, 0);
    c2 = func_L01_00445C50(0x1F00007F, 0);
    func_L01_00462190(a1, &pos, c1, c2, func_0037E208(0x28, 0x41), 1, -1, -1, 0, s * 40000.0f);
}
/* localdecomp:end func_L30_00351128 */
