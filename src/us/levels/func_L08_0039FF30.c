#include "common.h"

/* NTSC-U counterpart of func_L08_003A1BE8 (src/levels/shared/L08_003A1BE8.c) */
#include "vu0.h"

/* localdecomp:start func_L08_0039FF30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A1BE8;
extern V4_003A1BE8 D_001A4C60;
extern u8 D_L08_001D66B0_0039FF30[8];
extern f32 D_L08_001DE280_0039FF30;
__asm__(".extern D_L08_001DE280_0039FF30, 4");
extern s32 D_L08_001DE2A0;
__asm__(".extern D_L08_001DE2A0, 4");
extern s32 D_L08_001DE2A4;
__asm__(".extern D_L08_001DE2A4, 4");
extern s32 D_L08_001DE2A8_0039FF30;
__asm__(".extern D_L08_001DE2A8_0039FF30, 4");
extern s32 D_L08_001DE2AC_0039FF30;
__asm__(".extern D_L08_001DE2AC_0039FF30, 4");
extern s32 D_L08_001DE2B0_0039FF30;
__asm__(".extern D_L08_001DE2B0_0039FF30, 4");
extern s32 D_L08_001DE2B4_0039FF30;
__asm__(".extern D_L08_001DE2B4_0039FF30, 4");
extern s32 D_L08_001DE2B8_0039FF30;
__asm__(".extern D_L08_001DE2B8_0039FF30, 4");
extern s32 D_L08_001DE2BC_0039FF30;
__asm__(".extern D_L08_001DE2BC_0039FF30, 4");
extern s32 D_L08_001DE2C0_0039FF30;
__asm__(".extern D_L08_001DE2C0_0039FF30, 4");
extern f32 D_L08_001DE2C4_0039FF30;
__asm__(".extern D_L08_001DE2C4_0039FF30, 4");
extern f32 D_L08_001DE2C8_0039FF30;
__asm__(".extern D_L08_001DE2C8_0039FF30, 4");
extern f32 D_L08_001DE2CC_0039FF30;
__asm__(".extern D_L08_001DE2CC_0039FF30, 4");
extern f32 D_L08_001DE2D0_0039FF30;
__asm__(".extern D_L08_001DE2D0_0039FF30, 4");

extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00470258(void *, void *, f32, s32, s32, s16, s32);
extern void *func_L08_003A81D8(void *, void *, void *, f32, f32);
extern void func_L08_0039FB40(void *, void *, void *);

void func_L08_0039FF30(u8 *m, u8 *t) {
    V4_003A1BE8 d;
    V4_003A1BE8 x;
    V4_003A1BE8 rot;
    V4_003A1BE8 unused; /* never used: retail's frame has a dead 16-byte slot at 0x40 */
    V4_003A1BE8 pos;
    V4_003A1BE8 tmp;
    s32 i;
    s32 c1, c2;
    f32 g, f;

    vec_sub_ab(&d, &D_001A4C60, m + 0x10);
    func_00388830(&d, &d, 1.0f);
    rot = *(V4_003A1BE8 *)(m + 0xE0);
    func_00388758(&x, &rot, &d);
    for (i = 0; i < 10; i++) {
        func_003886E8(&tmp, &rot, func_L01_00440918(0.0f, 0.5f));
        vec_add_ab(&pos, &tmp, &d);
        func_003886E8(&tmp, &x, func_L01_00440918(0.0f, 0.5f));
        vec_add_ab(&pos, &tmp, &pos);
        func_003886E8(&pos, &pos, func_0037E250(D_L08_001DE2D0_0039FF30 * 0.4f, D_L08_001DE2D0_0039FF30) * 0.016666668f);
        c1 = func_003894A0(D_L08_001DE2A0, D_L08_001DE2A8_0039FF30, func_0037E250(0.0f, 1.0f));
        c2 = func_003894A0(D_L08_001DE2A4, D_L08_001DE2AC_0039FF30, func_0037E250(0.0f, 1.0f));
        g = func_0037E250((f32)D_L08_001DE2B8_0039FF30 * 0.5f, (f32)D_L08_001DE2B8_0039FF30 * 2.5f);
        func_L01_0045FEC8(t, &pos, D_L08_001D66B0_0039FF30, c1, c2, D_L08_001DE2B0_0039FF30, D_L08_001DE2B4_0039FF30,
            (s32)g, -1);
        func_003886E8(&pos, &pos, func_0037E250(1.5f, 2.5f));
        f = func_0037E250(D_L08_001DE2C4_0039FF30, D_L08_001DE2C8_0039FF30) * 210000.0f;
        func_L01_00470258(t, &pos, f, D_L08_001DE2BC_0039FF30, D_L08_001DE2C0_0039FF30, func_0037E208(0x78, 0xF0), 0);
    }
    func_003886E8(&tmp, &rot, func_L01_00440918(0.0f, 0.75f));
    vec_add_ab(&pos, &tmp, &d);
    func_003886E8(&tmp, &x, func_L01_00440918(0.0f, 0.5f));
    vec_add_ab(&pos, &tmp, &pos);
    func_003886E8(&pos, &pos, func_0037E250(D_L08_001DE2CC_0039FF30 * 0.7f, D_L08_001DE2CC_0039FF30) * 0.016666668f);
    func_L08_003A81D8(t, &pos, m, 0.0f, D_L08_001DE280_0039FF30);
    func_L08_0039FB40(m, t, &d);
}
/* localdecomp:end func_L08_0039FF30 */
