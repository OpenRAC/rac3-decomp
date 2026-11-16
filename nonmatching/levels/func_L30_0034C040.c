/* PAL near miss (Codex wave 7): held at landing (0c7bdf5e): the C matches PAL at every place, but its NTSC-U counterpart (same code) did not build from it everywhere in the NTSC-U build.
 */
#include "common.h"
/* localdecomp:start func_L30_0034C040 */
extern s32 D_L30_001DD49C;
extern s32 D_L30_001DF2C0;
extern f32 D_L30_001DD4A0, D_L30_001DD4A4;
__asm__(".extern D_L30_001DD49C, 4");
__asm__(".extern D_L30_001DD4A0, 4");
__asm__(".extern D_L30_001DD4A4, 4");
void func_L30_0034C040(u8 *arg0) {
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 wave;
    s32 color;
    wave = func_0038D098((f32)(D_L30_001DF2C0 % D_L30_001DD49C) * 6.283185482f / (f32)D_L30_001DD49C);
    color = func_0038DBD8(*(s32 *)(p + 0x20), *(s32 *)(p + 0x24), wave * 0.5f + 0.5f);
    func_L30_0034CF28(arg0 + 0x10, p + 0x28, color, D_L30_001DD4A0, D_L30_001DD4A4);
}
/* localdecomp:end func_L30_0034C040 */
