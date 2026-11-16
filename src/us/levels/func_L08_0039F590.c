#include "common.h"

/* NTSC-U counterpart of func_L08_003A1188 (src/levels/08_aquatos/L08_003A0F48.c) */
#include "vu0.h"
#include "vu0.h"
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

/* localdecomp:start func_L08_0039F590 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A1188;

extern s32 D_L08_001DE1B0_0039F590;
__asm__(".extern D_L08_001DE1B0_0039F590, 4");
extern s32 D_L08_001DE1B4_0039F590;
__asm__(".extern D_L08_001DE1B4_0039F590, 4");
extern s32 D_L08_001DE1B8_0039F590;
__asm__(".extern D_L08_001DE1B8_0039F590, 4");
extern f32 D_L08_001DE1BC_0039F590;
__asm__(".extern D_L08_001DE1BC_0039F590, 4");
extern f32 D_L08_001DE1C0_0039F590;
__asm__(".extern D_L08_001DE1C0_0039F590, 4");
extern f32 D_L08_001DE1C4_0039F590;
__asm__(".extern D_L08_001DE1C4_0039F590, 4");
extern f32 D_L08_001DE1C8_0039F590;
__asm__(".extern D_L08_001DE1C8_0039F590, 4");
extern f32 D_L08_001DE1CC_0039F590;
__asm__(".extern D_L08_001DE1CC_0039F590, 4");
extern s32 D_L08_001DE1D0_0039F590;
__asm__(".extern D_L08_001DE1D0_0039F590, 4");
extern f32 D_L08_001DE1D4_0039F590;
__asm__(".extern D_L08_001DE1D4_0039F590, 4");
extern f32 D_L08_001DE1D8_0039F590;
__asm__(".extern D_L08_001DE1D8_0039F590, 4");
extern f32 D_L08_001DE1DC_0039F590;
__asm__(".extern D_L08_001DE1DC_0039F590, 4");
extern f32 D_L08_001DE1E0_0039F590;
__asm__(".extern D_L08_001DE1E0_0039F590, 4");
extern f32 D_L08_001DE1E4;
__asm__(".extern D_L08_001DE1E4, 4");
extern s32 D_L08_001DE1E8_0039F590;
__asm__(".extern D_L08_001DE1E8_0039F590, 4");
extern s32 D_L08_001DE1EC;
__asm__(".extern D_L08_001DE1EC, 4");
extern s32 D_L08_001DE1F0_0039F590;
__asm__(".extern D_L08_001DE1F0_0039F590, 4");
extern s32 D_L08_001DE1F4;
__asm__(".extern D_L08_001DE1F4, 4");
extern s32 D_L08_001DE1F8;
__asm__(".extern D_L08_001DE1F8, 4");
extern s32 D_L08_001DE1FC;
__asm__(".extern D_L08_001DE1FC, 4");
extern f32 D_L08_001DE200_0039F590;
__asm__(".extern D_L08_001DE200_0039F590, 4");
extern s32 D_L08_001DE204;
__asm__(".extern D_L08_001DE204, 4");
extern s32 D_L08_001DE208;
__asm__(".extern D_L08_001DE208, 4");
extern f32 D_L08_001DE20C;
__asm__(".extern D_L08_001DE20C, 4");
extern f32 D_L08_001DE210;
__asm__(".extern D_L08_001DE210, 4");
extern f32 D_L08_001DE214;
__asm__(".extern D_L08_001DE214, 4");
extern f32 D_L08_001DE218;
__asm__(".extern D_L08_001DE218, 4");
extern f32 D_L08_001DE21C;
__asm__(".extern D_L08_001DE21C, 4");
extern f32 D_L08_001DE220_0039F590;
__asm__(".extern D_L08_001DE220_0039F590, 4");

extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00470258(void *, void *, s32, s32, s16, u8, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_0039F590(u8 *m) {
    V4_003A1188 rot;
    V4_003A1188 a;
    V4_003A1188 b;
    V4_003A1188 c;
    s32 i, j, k;
    f32 f, ang, r, z, t, g, s;
    s32 c1, c2;

    rot = *(V4_003A1188 *)(m + 0xE0);
    for (i = 0; i < D_L08_001DE1FC; i++) {
        func_00388830(&a, &rot, func_0037E250(D_L08_001DE20C, D_L08_001DE210) * 0.0166666675f);
        func_003BF6A8(&a, D_L08_001DE220_0039F590 * 0.0166666675f);
        func_00388830(&b, &rot, D_L08_001DE200_0039F590);
        vec_add_ab(&b, &b, m + 0x10);
        func_003BF6A8(&b, D_L08_001DE21C);
        f = func_0037E250(D_L08_001DE214, D_L08_001DE218) * 210000.0f;
        func_L01_00470258(&b, &a, D_L08_001DE204, D_L08_001DE208, func_0037E208(0x78, 0xF0), 0, f);
    }
    for (j = 0; j < D_L08_001DE1B0_0039F590; j++) {
        a = *(V4_003A1188 *)(m + 0x10);
        func_003BF6A8(&a, D_L08_001DE1CC_0039F590);
        a.z += 0.5f;
        ang = func_0037E2A8();
        r = func_0037E250(D_L08_001DE1DC_0039F590, D_L08_001DE1C0_0039F590);
        z = func_0037E250(D_L08_001DE1C4_0039F590, D_L08_001DE1C8_0039F590);
        qzero(&b);
        b.x += func_00388960(ang) * (r * 0.0166666675f);
        b.y += func_00388978(ang) * (r * 0.0166666675f);
        b.z += z * 0.0166666675f;
        c = b;
        t = func_0037E250(D_L08_001DE1BC_0039F590 * 0.7f, D_L08_001DE1BC_0039F590 * 1.3f);
        c.z -= t * 0.000277777785f * (f32)(D_L08_001DE1B4_0039F590);
        for (k = 0; k < D_L08_001DE1D0_0039F590; k++) {
            s = func_0037E250(0.5f, 1.5f);
            b.w = s * D_L08_001DE1E0_0039F590;
            c.w = s * D_L08_001DE1E4;
            func_003BF6A8(&a, D_L08_001DE1D4_0039F590);
            func_003BF6A8(&c, D_L08_001DE1D8_0039F590 * 0.0166666675f);
            c1 = func_003894A0(D_L08_001DE1E8_0039F590, D_L08_001DE1F0_0039F590, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(D_L08_001DE1EC, D_L08_001DE1F4, func_0037E250(0.0f, 1.0f));
            g = (f32)D_L08_001DE1B8_0039F590;
            g = func_0037E250(g * 0.5f, g * 2.5f);
            func_L01_0045FEC8(&a, &b, &c, c1, c2, D_L08_001DE1F8, D_L08_001DE1B4_0039F590,
                (s32)g, -1);
        }
    }
}
/* localdecomp:end func_L08_0039F590 */
