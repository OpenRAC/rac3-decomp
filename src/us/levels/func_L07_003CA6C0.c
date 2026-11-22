#include "common.h"

/* NTSC-U counterpart of func_L07_003CC0C0 (src/levels/shared/L07_003CB9B8.c): 60 Hz speed scale (1/60) */
/* localdecomp:start func_L07_003CA6C0 */
#include "vu0.h"
extern s32 D_L07_001DE6F4_003CA6C0;
extern s32 D_L07_001DE6F8;
extern s32 D_L07_001DE6FC;
extern s32 D_L07_001DE700;
extern s32 D_L07_001DE704;
extern s32 D_L07_001DE708;
extern s32 D_L07_001DE70C;
extern f32 D_L07_001DE710;
extern s32 D_L07_001DE714;
extern s32 D_L07_001DE718;
extern f32 D_L07_001DE71C;
extern f32 D_L07_001DE720;
extern f32 D_L07_001DE724;
extern f32 D_L07_001DE728;
__asm__(".extern D_L07_001DE6F4_003CA6C0, 4");
__asm__(".extern D_L07_001DE6F8, 4");
__asm__(".extern D_L07_001DE6FC, 4");
__asm__(".extern D_L07_001DE700, 4");
__asm__(".extern D_L07_001DE704, 4");
__asm__(".extern D_L07_001DE708, 4");
__asm__(".extern D_L07_001DE70C, 4");
__asm__(".extern D_L07_001DE710, 4");
__asm__(".extern D_L07_001DE714, 4");
__asm__(".extern D_L07_001DE718, 4");
__asm__(".extern D_L07_001DE71C, 4");
__asm__(".extern D_L07_001DE720, 4");
__asm__(".extern D_L07_001DE724, 4");
__asm__(".extern D_L07_001DE728, 4");
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L07_003CA6C0(void *a0) {
    vu0_v4 w;
    vu0_v4 v;
    s32 i;

    for (i = 0; i < D_L07_001DE714; i++) {
        *(vu0_q *)&v = 0;
        v.x = func_0037E250(D_L07_001DE71C, D_L07_001DE720);
        v.y = func_0037E250(D_L07_001DE71C, D_L07_001DE720);
        v.z = func_0037E250(D_L07_001DE724, D_L07_001DE728);
        w = v;
        func_00388830(&w, &w, D_L07_001DE710 * 0.016666668f);
        func_L01_00460318(a0, &w,
                          (D_L07_001DE700 << 24) | (D_L07_001DE6FC << 16) | (D_L07_001DE6F8 << 8) | D_L07_001DE6F4_003CA6C0,
                          (D_L07_001DE6FC << 16) | (D_L07_001DE6F8 << 8) | D_L07_001DE6F4_003CA6C0,
                          D_L07_001DE704, D_L07_001DE708, D_L07_001DE70C, D_L07_001DE718);
    }
}
/* localdecomp:end func_L07_003CA6C0 */
