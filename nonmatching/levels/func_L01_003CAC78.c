/* NTSC-U draft (Claude wave K): C of func_L01_003C93E0, the NTSC-U twin of func_L01_003CAC78, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 37 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003C93E0", whose code is not the PAL one).
 * Worker's note: first full draft (was skip: not attempted): 37 aligned diffs of ~230 words; the whole body is decoded and compiles to the same shape (two duplicated halves, vec_sub_ab, clamp, the final spawner call). Needs -mvu0-use-vf0-vf2 (vec_sub_ab) + @ps2as (float ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_003C9138 (src/levels/shared/L01_003C8DE8.c) */
/* localdecomp:start func_L01_003C93E0 */
extern u8 D_L01_001D66B0[];
extern void func_003BDA38(s32, s32, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_003AFF80(void *, void *, void *, u32, u32, u32, u32, f32, f32);
extern void func_L01_00466F98(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);

void func_L01_003C93E0(u8 *o) {
    vu0_v4 a, b, c;
    u8 *st;
    u8 *own;
    f32 r, ang, h;
    vu0_v4 *p;

    st = *(u8 **)(o + 0x68);
    own = *(u8 **)(*(u8 **)(o + 0xB8) + 0xB8);
    own = *(u8 **)(own + 0x68);
    *(vu0_q *)&b = *(vu0_q *)(st + 0x4A0);
    func_003BDA38(*(s32 *)(st + 0x550), 0, &a);
    r = func_0037E250(0.0f, 1.0f);
    if (r <= *(f32 *)(own + 0x84)) {
        vec_sub_ab(&c, &b, &a);
        ang = func_003893C8(func_00388A28(c.x, c.y), func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_00388A28(func_003887A0(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_0037E4B8(&c, 1.0f, func_00389380(func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003AFF80(o, &a, p, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, *(f32 *)(own + 0x80), 0.6499999761581421f);
    } else {
        b.x += func_L01_00440918(0.0f, 0.2f);
        b.y += func_L01_00440918(0.0f, 0.2f);
        b.z += func_L01_00440918(0.0f, 0.2f);
        vec_sub_ab(&c, &b, &a);
        ang = func_003893C8(func_00388A28(c.x, c.y), func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_00388A28(func_003887A0(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_0037E4B8(&c, 1.0f, func_00389380(func_00389380(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003AFF80(o, &a, p, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.6499999761581421f);
    }
    func_L01_00466F98(&a, D_L01_001D66B0, 0x14, 0x50, 0xFF1010, 0, func_0037E250(8.0f, 10.0f) * 0.25f * 210000.0f, 600.0f, 0.949999988079071f, 0.0f, 0.0f);
}
/* localdecomp:end func_L01_003C93E0 */
