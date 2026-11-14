#include "common.h"

/* localdecomp:start func_L06_00351418 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_351418;
typedef struct { u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 w28; s32 w2C; } S_E1700;
extern S_E1700 D_L06_001E1700_00351418;
extern u8 D_L06_001D66B0[8];
extern void func_L01_004412D0(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90(f32 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003BD360(void *);

void func_L06_00351418(u8 *a0, u8 *a1) {
    V4_351418 v;

    func_L01_004412D0(a0, 0, 3);
    if (a1[0x5E] == 0) {
        func_0039FE80(0xC, 0, a0);
        func_0039FE80(0xF, 0, a0);
        *(u128_t *)&v = *(u128_t *)(*(u8 **)(a1 + 0x260) + 0x10);
        v.z = v.z + 0.5f;
        func_L01_0032FE90((f32 *)&v, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.5f, 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        D_L06_001E1700_00351418.f20 = 0.1f;
        D_L06_001E1700_00351418.w28 = 0x1E;
        D_L06_001E1700_00351418.w2C = 0;
        func_L01_0044ED60(*(u8 **)(a1 + 0x260), 0xFF, D_L06_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_0044ED60(a0, 0x3F, D_L06_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    }
    func_003BD360(*(u8 **)(a1 + 0x260));
    func_003BD360(a0);
}
/* localdecomp:end func_L06_00351418 */
