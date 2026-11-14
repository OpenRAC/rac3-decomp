#include "common.h"

/* localdecomp:start func_L39_0055ED80 */
extern const f32 D_001DFC50_sda;
extern const f32 D_001DFC54_sda;
extern const f32 D_001DFC58_sda;
extern const f32 D_001DFC5C_sda;
__asm__(".extern D_001DFC50_sda, 4");
__asm__(".extern D_001DFC54_sda, 4");
__asm__(".extern D_001DFC58_sda, 4");
__asm__(".extern D_001DFC5C_sda, 4");
extern f32 func_003893C8(f32, f32);
extern void func_L01_0044B5C8(f32, void *, f32, void *, s32);

void func_L39_0055ED80(u8 *a, u8 *b) {
    *(f32 *)(b + 0xE8) = func_003893C8(*(f32 *)(b + 0x210), *(f32 *)(a + 0xF8));
    func_L01_0044B5C8(D_001DFC50_sda, a, D_001DFC54_sda, b + 0x80, 0);
    *(f32 *)(b + 0x160) = *(f32 *)(b + 0x214);
    func_L01_0044B5C8(D_001DFC58_sda, a, D_001DFC5C_sda, b + 0x100, 2);
    *(f32 *)(b + 0x1E0) = *(f32 *)(b + 0x214) * 0.35f;
    func_L01_0044B5C8(D_001DFC58_sda, a, D_001DFC5C_sda, b + 0x180, 3);
}
/* localdecomp:end func_L39_0055ED80 */
