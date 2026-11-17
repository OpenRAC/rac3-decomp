#include "common.h"

/* NTSC-U counterpart of func_L01_00464400 (src/levels/shared/L01_00462978.c) */
#include "vu0.h"
#include "vu0.h"
extern s32 func_00388398(void *);
extern s32 func_00388398(void *);

/* localdecomp:start func_L01_00460EA8 */
__asm__(".extern D_L01_001D7EB4_00460EA8, 4");
extern s32 D_L01_001D7EB4_00460EA8 __attribute__((section(".sdata")));
void func_L01_00460EA8(u8 *self) {
    extern s32 func_00388398(void *);
    extern void func_003C7CE0(u8 *);
    extern f32 func_00389380(f32, f32);
    u8 *vars = self + 0x20;
    s32 ticks, life, alpha;
    f32 angle;
    if (func_00388398(vars)) {
        func_003C7CE0(self);
        return;
    }
    angle = func_00389380(*(f32 *)(vars + 0xC), *(f32 *)(vars + 8));
    *(f32 *)(vars + 0xC) = angle;
    self[8] = (s32)(angle * 128.0f / 3.1415927f) - 128;
    ticks = D_L01_001D7EB4_00460EA8;
    life = ticks;
    if (*(s32 *)(self + 0x20) > life * 3 / 4) {
        alpha = *(s32 *)(vars + 0x10) * (life - *(s32 *)(self + 0x20)) / (ticks / 4);
    } else if (*(s32 *)(self + 0x20) < ticks / 4) {
        alpha = *(s32 *)(vars + 0x10) * *(s32 *)(self + 0x20) / (ticks / 4);
    } else {
        alpha = *(s32 *)(vars + 0x10);
    }
    *(u32 *)(self + 4) = (alpha << 24) + (self[3] == 0x48 ? 0x4F4F4F : 0x7F7F7F);
}
/* localdecomp:end func_L01_00460EA8 */
