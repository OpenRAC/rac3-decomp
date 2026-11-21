#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_004638C8 (src/levels/shared/L01_00462978.c): drag factor 0.98 (PAL 0.976) */
/* localdecomp:start func_L01_00460418 */
extern vu0_v4 D_L01_001D7EA0_00460418 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D7EA0_00460418, 0");
void func_L01_00460418(u8 *self) {
    extern void func_003886E8(void *, void *, f32);
    extern s32 func_L01_00444338_00460418(s32, s32, f32);
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    u8 *vars = self + 0x20;
    vu0_v4 position;
    *(f32 *)(self + 0xC) = (*(s16 *)(vars + 0x18) * (*(s32 *)(vars + 0x1C) - *(s16 *)(self + 0xA)) / *(s32 *)(vars + 0x1C) + *(s16 *)(vars + 0x1A)) * 1000.0f;
    func_003886E8(vars, vars, 0.98f);
    vec_add_ba(self + 0x10, self + 0x10, vars);
    {
        vu0_q a, b;
        __asm__("lqc2 %1, %4\n\tlqc2 %0, %5\n\tvadd.xyz %1, %1, %0\n\tsqc2 %1, %2\n\tsqc2 %1, %3"
                : "=&j"(a), "=&j"(b), "=m"(*(vu0_v4 *)(self + 0x10)), "=m"(position)
                : "m"(*(vu0_v4 *)(self + 0x10)), "m"(D_L01_001D7EA0_00460418));
    }
    self[8]++;
    *(s32 *)(self + 4) = func_L01_00444338_00460418(*(s32 *)(vars + 0x14), *(s32 *)(vars + 0x10), (f32)*(s16 *)(self + 0xA) / (f32)*(s32 *)(vars + 0x1C));
    if (func_003883C8(self + 0xA)) func_003C7CE0(self);
}
/* localdecomp:end func_L01_00460418 */
