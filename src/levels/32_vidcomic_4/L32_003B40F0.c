#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L32_003B40F0 */
extern f32 D_L32_001DED0C;
__asm__(".extern D_L32_001DED0C, 4");
extern f32 D_L32_001DED08;
__asm__(".extern D_L32_001DED08, 4");
extern f32 D_L32_001DECFC;
__asm__(".extern D_L32_001DECFC, 4");
extern s32 D_L32_001DECF8;
__asm__(".extern D_L32_001DECF8, 4");
extern s32 D_L32_001DECF4;
__asm__(".extern D_L32_001DECF4, 4");
extern f32 D_L32_001DED00;
__asm__(".extern D_L32_001DED00, 4");
extern f32 D_L32_001DED10;
__asm__(".extern D_L32_001DED10, 4");
extern f32 D_L32_001DED04;
__asm__(".extern D_L32_001DED04, 4");
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L32_003B40F0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 one = 1.0f;
    f32 t;
    f32 f;
    s32 col;
    u8 *pos;

    t = func_003C4088(D_L32_001DED0C, D_L32_001DED08, *(f32 *)(p + 0x34));
    t = func_0038DAB8(*(f32 *)(p + 0x44), t);
    f = *(f32 *)(p + 0x34) / D_L32_001DECFC;
    *(f32 *)(p + 0x44) = t;
    if (one < f) {
        f = one;
    }
    pos = p + 0x10;
    col = (func_0038DBD8(D_L32_001DECF8, D_L32_001DECF4, *(f32 *)(p + 0x34)) & 0xFFFFFF) | ((s32)(f * 128.0f) << 24);
    t = func_003C4088(D_L32_001DED00, one, f);
    func_003D9508(pos, 0x27, col, 0, D_L32_001DED10 * t, D_L32_001DED04, *(f32 *)(p + 0x44));
}
/* localdecomp:end func_L32_003B40F0 */
