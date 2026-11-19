/* functional: high. Needs #include vu0.h and -mvu0-use-vf0-vf2 on this file's flag line (it has none) for the vec_sub_ab asm; 52 instruction positions differ at L01 (register allocation / s-register for the local copy and frame size), same reads, calls, order. */
#include "vu0.h"
extern u8 *D_L01_001DF840;
__asm__(".extern D_L01_001DF840, 16");
extern f32 func_0038CED8(void *);
extern s32 func_L01_003F7490(void *pos, void *e, f32 r);

u8 *func_L01_003F7350(void *pos, f32 radius) {
    vu0_v4 p;
    vu0_v4 d;
    s32 xi;
    s32 yi;
    u8 *grid;
    u8 *cell;
    u8 *e;
    s32 off;
    s32 i;
    void *pp = &p;
    *(vu0_q *)&p = *(vu0_q *)pos;
    xi = (s32)(p.x * 0.0625f);
    yi = (s32)(p.y * 0.0625f);
    if (xi < 0 || yi < 0 || xi >= 0x41 || yi >= 0x41) {
        return 0;
    }
    grid = D_L01_001DF840;
    off = *(s32 *)(grid + ((yi * 64 + xi) << 2));
    if (off == 0) {
        return 0;
    }
    cell = grid + off;
    if (*(s32 *)cell <= 0) {
        return 0;
    }
    e = cell + 0x10;
    for (i = 0; i < *(s32 *)cell; i++) {
        f32 len;
        vec_sub_ab(&d, e, pp);
        d.w = 1.0f;
        len = func_0038CED8(&d);
        if (len < *(f32 *)(e + 0xC) + radius) {
            if (func_L01_003F7490(pp, e, radius) != 0) {
                return e;
            }
        }
        e += 0x30;
    }
    return 0;
}
