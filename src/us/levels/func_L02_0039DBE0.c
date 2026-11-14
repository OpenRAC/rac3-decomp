#include "common.h"

/* NTSC-U counterpart of func_L02_0039F980 (src/levels/02_florana/L02_0039EF28.c): 0.12 -> 0.1 */
#include "vu0.h"

/* localdecomp:start func_L02_0039DBE0 */
extern u8 D_001A4C60[];
extern u8 D_L02_001DDCB0;
extern u8 D_L02_001DDCC0;
extern u8 D_L02_001DDCD0;
__asm__(".extern D_L02_001DDCB0, 4");
__asm__(".extern D_L02_001DDCC0, 4");
__asm__(".extern D_L02_001DDCD0, 4");
extern void func_003C1130(void *, void *, s32, s32, void *, s32, s32, s32, void *, void *, s32);
extern void func_003C1440(void *, void *, s32);
extern void func_003BF838(void *, void *, void *, void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);

void func_L02_0039DBE0(u8 *self) {
    u8 *d = *(u8 **)(self + 0x68);
    vu0_v4 pos, rot, dp;

    if (d == 0) return;
    pos = *(vu0_v4 *)(self + 0x10);
    rot = *(vu0_v4 *)(self + 0xF0);
    if (self[0x20] == 0) {
        func_003C1130(self, d + 0x70, 0, 0, &D_L02_001DDCB0, 0, 0, 0, &D_L02_001DDCD0, &D_L02_001DDCC0, 0);
    } else if (self[0x20] == 2) {
        func_003C1440(self, d + 0x70, 0);
    }
    vec_sub_ab(&dp, &pos, self + 0x10);
    func_003BF838(d + 0x30, &dp, &rot, self + 0xF0);
    if (self[0x20] == 0) {
        if (*(s32 *)(d + 0x130) != 0) {
            *(f32 *)(d + 0x138) = *(f32 *)(self + 0x18);
            self[0x20] = 1;
            *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) - 7.0f;
        } else {
            self[0x20] = 2;
        }
    }
    if (self[0x20] == 1) {
        if (func_0037E0F0(D_001A4C60, *(s32 *)(d + 0x134), 0) != 0) {
            func_003BEBF8((f32 *)(self + 0x18), *(f32 *)(d + 0x138), 0.100000009f);
            if (*(f32 *)(self + 0x18) == *(f32 *)(d + 0x138)) self[0x20] = 2;
        }
    }
}
/* localdecomp:end func_L02_0039DBE0 */
