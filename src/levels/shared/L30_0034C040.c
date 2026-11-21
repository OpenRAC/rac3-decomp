#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_0034C040 */
extern s32 D_L30_001DD49C_0034C040;
extern s32 D_L30_001DF2C0;
extern f32 D_L30_001DD4A0_0034C040, D_L30_001DD4A4;
__asm__(".extern D_L30_001DD49C_0034C040, 4");
__asm__(".extern D_L30_001DD4A0_0034C040, 4");
__asm__(".extern D_L30_001DD4A4, 4");
void func_L30_0034C040(u8 *arg0) {
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 wave;
    s32 color;
    wave = func_0038D098((f32)(D_L30_001DF2C0 % D_L30_001DD49C_0034C040) * 6.283185482f
                         / (f32)D_L30_001DD49C_0034C040);
    color = func_0038DBD8(*(s32 *)(p + 0x20), *(s32 *)(p + 0x24), wave * 0.5f + 0.5f);
    func_L30_0034CF28(arg0 + 0x10, p + 0x28, color, D_L30_001DD4A0_0034C040, D_L30_001DD4A4);
}
/* localdecomp:end func_L30_0034C040 */
