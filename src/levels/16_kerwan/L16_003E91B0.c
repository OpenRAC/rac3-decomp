#include "common.h"

/* localdecomp:start func_L16_003E91B0 */
extern void func_L16_003E9068(void *a0, void *a1, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, s32 a2, s32 a3, u8 a4, u8 a5, s32 a6);
__asm__(".extern D_L16_001DF644, 4");
extern f32 D_L16_001DF644;
__asm__(".extern D_L16_001DF648, 1");
extern u8 D_L16_001DF648;
__asm__(".extern D_L16_001DF649, 1");
extern u8 D_L16_001DF649;
__asm__(".extern D_L16_001DF64A, 1");
extern u8 D_L16_001DF64A;
__asm__(".extern D_L16_001DF64B, 1");
extern u8 D_L16_001DF64B;
__asm__(".extern D_L16_001DF64C, 4");
extern s32 D_L16_001DF64C;

void func_L16_003E91B0(void *arg0, u8 *p, f32 *t) {
    u8 *m = *(u8 **)((u8 *)arg0 + 0x68);

    *t -= D_L16_001DF644;
    if (*t <= -10.0f) {
        *t = 10.0f;
    }
    func_L16_003E9068(p, m + 0x40, 0.0f, *(f32 *)(p + 0xC), 1.0f, *(f32 *)(m + 0x64), *t, 0x3ED8FF, 0x446876,
                      D_L16_001DF648, D_L16_001DF649, D_L16_001DF64C);
    func_L16_003E9068(p, m + 0x40, 1.0f, *(f32 *)(p + 0xC), 1.0f, *(f32 *)(m + 0x64), *t * 3.0f, 0x54AB, 0x9099,
                      D_L16_001DF64A, D_L16_001DF64B, m[0x6F]);
}
/* localdecomp:end func_L16_003E91B0 */
