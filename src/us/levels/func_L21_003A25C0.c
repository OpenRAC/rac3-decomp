#include "common.h"

/* localdecomp:start func_L21_003A25C0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3A25C0;

extern u8 D_L21_001D66B0[8];
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L02_00426140(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_0032FE90(f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L21_003A25C0(u8 *a0) {
    V4_3A25C0 v;

    func_0039FE80(0, 0, a0);
    func_L01_0044ED60(a0, 0x3F, D_L21_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      1.0f, 3.0f, 1.0f, 3.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_003BDA38(a0, 0, &v);
    func_L02_00426140(a0, &v, 0x14, 0, D_L21_001D66B0, 0x80808080, 0, 0x5A, 1.0f, 3.0f, 0.4f, 0.7f);
    func_L02_003E0520(a0, &v, 1.0f, D_L21_001D66B0, 0xF, 0, 1, 0.041666668f, 2.5f, 5.0f, 1.0f);
    func_L01_0032FE90((f32 *)&v, 0, 0, 0, 0, 2, 5, 0, 0.7f, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x8080, 0x8040, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    func_L01_0044EBF8(a0, 1, 0.0f);
    func_003BD360(a0);
}
/* localdecomp:end func_L21_003A25C0 */
