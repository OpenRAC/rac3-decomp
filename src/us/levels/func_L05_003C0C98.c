#include "common.h"

/* NTSC-U counterpart of func_L05_003C2D08 (src/levels/shared/L05_003C0EA8.c): 0.02 -> 0.0166667 */
#include "vu0.h"

/* localdecomp:start func_L05_003C0C98 */
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L05_003C0480(void);
extern void func_L01_0044EB78(u8 *, void *, s32, s32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L05_00465110(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2780;
__asm__(".extern D_L05_001DEB48, 4");
extern s32 D_L05_001DEB48;
__asm__(".extern D_L05_001DEB4C, 4");
extern f32 D_L05_001DEB4C;
__asm__(".extern D_L05_001DEB58, 4");
extern f32 D_L05_001DEB58;
__asm__(".extern D_L05_001DEB5C, 4");
extern f32 D_L05_001DEB5C;
__asm__(".extern D_L05_001DEB90, 8");
extern u8 D_L05_001DEB90[8];

void func_L05_003C0C98(u8 *a0) {
    u8 *v;
    s32 i;
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 d;
    vu0_v4 m[4];

    v = *(u8 **)(a0 + 0x68);
    func_00388398(v + 0x2D0);
    func_003883C8(v + 0x2D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_00402498(func_L05_003C0480, a0);
    func_L01_0044EB78(a0, v + 0x240, 2, 1, 2.5f);
    if (a0[0x31] != 0 && func_L01_0040C018(&D_L05_001E2780, a0 + 0x10) < 1024.0f) {
        func_L01_00444188(a0);
        a0[0x6F] = 0x1E;
    }
    *(vu0_q *)&p = *(vu0_q *)(a0 + 0x10);
    func_00388830(&d, a0 + 0xE0, 0.6f);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DEB48; i++) {
        func_003BF6A8(&p, D_L05_001DEB4C);
        func_00388830(&r, a0 + 0xE0, func_0037E250(D_L05_001DEB58, D_L05_001DEB5C) * 0.0166666675f);
        func_L05_00465110(&p, &r, D_L05_001DEB90, func_0037E1D8(2), func_0037E1D8(3) - 1);
    }
}
/* localdecomp:end func_L05_003C0C98 */
