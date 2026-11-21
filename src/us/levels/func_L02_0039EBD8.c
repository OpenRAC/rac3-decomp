#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L02_003A0978 (src/levels/shared/L02_003A04D0.c): the particle fade rate is 0.0016 * (25/30)^2 = 1/900 at 60 Hz */
/* localdecomp:start func_L02_0039EBD8 */

typedef int u128_0039EBD8 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0039EBD8;

extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_L02_001D66B0;
__asm__(".extern D_L02_001D66B0, 16");
extern u8 *D_L02_0021E2BC[];

void func_L02_0039EBD8(u8 *a0) {
    V4_0039EBD8 pos;
    V4_0039EBD8 v10;
    u8 *st;
    u8 *p;
    f32 r0;
    f32 base;
    f32 lin;
    f32 ang;
    f32 zup;
    f32 sz;
    s32 life;
    s32 color;
    s32 b5;
    s32 r;

    st = *(u8 **)(a0 + 0x68);
    r0 = func_0037E250(0.0f, *(f32 *)(st + 8));
    lin = *(f32 *)(st + 0xC) * -0.79999995f + 0.9f;
    base = lin + (0.1f - lin) * r0;
    ang = func_0037E2A8();
    zup = *(f32 *)(st + 8) - 0.5f;
    if (zup < 0.0f) {
        zup = 0.0f;
    }
    *(u128_0039EBD8 *)&v10 = 0;
    zup *= 3.0f;
    zup += r0 * 3.0f;
    v10.x = base * func_00388978(ang);
    v10.y = base * func_00388960(ang);
    v10.z = zup;
    *(u128_0039EBD8 *)&pos = *(u128_0039EBD8 *)&v10;
    vec_add_ab(&pos, a0 + 0x10, &pos);
    life = func_0037E208(-10, 10) + 30;
    sz = func_0037E250(-0.1f, 0.1f) + 0.3f;
    color = st[0x16] << 16 | st[0x15] << 8 | st[0x14];
    b5 = 0;
    r = func_0037E1D8(2);
    p = func_L01_0046C468(&pos, &D_L02_001D66B0, life, color, r ? -1 : 1, 0x40, 0x20,
                          sz * 210000.0f, sz * 210000.0f, 0.0011111111f, 0);
    if (p != 0) {
        b5 = p[8] + 0x20;
        p[2] = *D_L02_0021E2BC[0];
    }
    r = func_0037E1D8(2);
    p = func_L01_0046C468(&pos, &D_L02_001D66B0, life, 0xF7F7F7, r ? -1 : 1, 0x30, 0x30,
                          sz * 0.4f * 210000.0f, sz * 0.4f * 210000.0f, 0.0011111111f, 0);
    if (p != 0) {
        p[2] = *D_L02_0021E2BC[0];
        p[8] = b5;
    }
}
/* localdecomp:end func_L02_0039EBD8 */
