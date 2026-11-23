#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_004642F0 (src/levels/shared/L01_00462978.c): the fade-out takes 6 frames (PAL 5) */
/* localdecomp:start func_L01_00460D98 */
extern u8 *D_L01_00221138[];
void func_L01_00460D98(u8 *p) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern u32 func_003894A0(u32, u32, f32);
    u8 *v = p + 0x20;
    u32 color;
    s32 life;
    vec_add_ab(p + 0x10, p + 0x10, v);
    if (func_003883C8(p + 0xA)) {
        func_003C7CE0(p);
    } else {
        *(f32 *)(p + 0xC) += *(f32 *)(v + 0x1C);
        color = func_003894A0(*(u32 *)(v + 0x14), *(u32 *)(v + 0x10),
                             (f32)*(s16 *)(p + 0xA) / (f32)*(s32 *)(v + 0x18));
        *(u32 *)(p + 4) = color;
        life = *(s16 *)(p + 0xA);
        if (life < 6) {
            *(u32 *)(p + 4) = (color & 0xFFFFFF) | ((life * (s32)(color >> 24) / 6) << 24);
        }
        p[2] = D_L01_00221138[0][(*(s32 *)(v + 0x18) - *(s16 *)(p + 0xA)) * 10 / *(s32 *)(v + 0x18)];
    }
}
/* localdecomp:end func_L01_00460D98 */
