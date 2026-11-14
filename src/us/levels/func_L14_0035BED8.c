#include "common.h"

/* NTSC-U counterpart of func_L14_0035CF00 (src/levels/14_koros/L14_0035C810.c) */
#include "vu0.h"
void func_L14_0035BED8(u8 *a0);

/* localdecomp:start func_L14_0035BED8 */
typedef struct {
    vu0_v4 m;
    u8 *obj;
    s32 flags;
    s32 f28;
    f32 f2C;
    s32 f30;
} S_35CF00;
extern u8 D_L14_001D66B0_0035BED8;
extern s32 D_L14_001D67B8_0035BED8;
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CF790(void *, s32, void *, void *, f32);
extern void func_L01_00456960(s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L14_0035C060(u8 *, f32, f32);
extern void func_003BD360(void *);
void func_L14_0035BED8(u8 *a0) {
    S_35CF00 blk;
    vu0_v4 v;
    vu0_v4 *pv;
    S_35CF00 *pb;
    func_L01_0044ED60(a0, 0x7FFF, &D_L14_001D66B0_0035BED8, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    if (*(f32 *)(a0 + 0xE8) == 1.0f) {
        pv = &v;
        pb = &blk;
        blk.f2C = 2.0f;
        blk.m = *(vu0_v4 *)(a0 + 0xC0);
        blk.obj = a0;
        blk.f30 = 0;
        func_00388830(pv, a0 + 0xE0, 0.5f);
        *pv = *(vu0_v4 *)(a0 + 0x10);
        blk.flags = 0x8000000;
        v.z += 1.1f;
        func_003CF790(pv, 0x10, a0, pb, 1.4f);
    }
    D_L14_001D67B8_0035BED8 = D_L14_001D67B8_0035BED8 + 1;
    if (D_L14_001D67B8_0035BED8 >= 100) {
        func_L01_00456960(0x11);
    }
    func_L01_0044EBF8(a0, 1, 0.0f);
    func_L14_0035C060(a0, -0.06666667f, -0.16666667f);
    func_003BD360(a0);
}
/* localdecomp:end func_L14_0035BED8 */
