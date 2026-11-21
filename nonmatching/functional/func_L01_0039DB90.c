/* functional: high. EXACT at level_01, level_05, level_12 (byte-identical).  */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern f32 D_001A4EC0[];
extern f32 D_L01_001DE19C, D_L01_001DE1A0, D_L01_001DE1B4, D_L01_001DE1B8;
extern s32 D_L01_001DE1A4, D_L01_001DE1A8, D_L01_001DE1AC, D_L01_001DE1B0;
__asm__(".extern D_L01_001DE19C, 4");
__asm__(".extern D_L01_001DE1A0, 4");
__asm__(".extern D_L01_001DE1B4, 4");
__asm__(".extern D_L01_001DE1B8, 4");
__asm__(".extern D_L01_001DE1A4, 4");
__asm__(".extern D_L01_001DE1A8, 4");
__asm__(".extern D_L01_001DE1AC, 4");
__asm__(".extern D_L01_001DE1B0, 4");
void func_L01_0039DB90(u8 *obj) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern s32 func_00382468(s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D890(vu0_v4 *, vu0_v4 *, vu0_v4 *, f32);
    extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
    vu0_v4 delta, axis, direction;
    u8 *state;
    s32 color;
    vec_sub_ab(&delta, &D_L01_001E29C0, obj + 0x10);
    state=*(u8 **)(obj+0x68);
    func_0038CE20((f32 *)&axis, D_001A4EC0, func_003824E0(D_L01_001DE19C * 0.020000001f, D_L01_001DE1A0 * 0.020000001f));
    func_0038D890((vu0_v4 *)&direction, (vu0_v4 *)&axis, (vu0_v4 *)&delta, func_00382538());
    if (state[0x47]) color = D_L01_001DE1B0;
    else color = D_L01_001DE1A8;
    func_L01_0046C470(obj+0x10, &direction, color, D_L01_001DE1B4, D_L01_001DE1A4, func_00382468(255)&255, 1, 64, 0);
    func_L01_0046C470(obj+0x10, &direction, D_L01_001DE1AC, D_L01_001DE1B8, D_L01_001DE1A4, func_00382468(255)&255, 1, 64, 0);
}
