/* NTSC-U draft (Claude wave K): C of func_L02_0039EBD8, the NTSC-U twin of func_L02_003A0978, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 139 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (S mode; entry's -mno-split-addresses dropped)" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses") (NTSC-U twin "func_L02_0039EBD8", whose code is not the PAL one).
 * Worker's note: 139 diff words of 168 (43 structural; yours 169 insns vs retail 168) in S mode with '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (the entry's flags have -mno-split-addresses: retail shows `lui $a1,0x1D; addiu $a1,$a1,0x66B0` and ...
 */
/* NEAR (139 diff words of 168; 43 structural; yours 169 insns vs retail 168): flags needed '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (S mode: the entry's -mno-split-addresses must be dropped; vu0 + @ps2as are not on the PAL line). Matches through the first big computation (rand, lerp, sin/cos, vec_add_ab); remaining: callee-saved set (retail s3=-1, s4=+1, s5=b5 hoisted before the cos call, texture address D_L02_001D66B0 re-materialised per call, D_L02_0021E2BC lui-form), mine keeps the texture address in a saved register. */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39EBD8;

extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

/* localdecomp:start func_L02_0039EBD8 */
extern u8 D_L02_001D66B0[];
extern u8 *D_L02_0021E2BC;

void func_L02_0039EBD8(u8 *a0) {
    V4_39EBD8 pos;
    V4_39EBD8 v10;
    u8 *st;
    u8 *p;
    f32 r0;
    f32 base;
    f32 lin;
    f32 ang;
    f32 zup;
    f32 sp;
    f32 sz;
    f32 f0;
    s32 life;
    s32 color;
    s32 b5;

    st = *(u8 **)(a0 + 0x68);
    r0 = func_0037E250(0.0f, *(f32 *)(st + 8));
    lin = *(f32 *)(st + 0xC) * -0.79999995f + 0.9f;
    base = lin + (0.1f - lin) * r0;
    ang = func_0037E2A8();
    zup = *(f32 *)(st + 8) - 0.5f;
    if (zup < 0.0f) {
        zup = 0.0f;
    }
    *(u128_t *)&v10 = 0;
    zup = zup * 3.0f + r0 * 3.0f;
    v10.x = base * func_00388978(ang);
    v10.y = base * func_00388960(ang);
    v10.z = zup;
    *(u128_t *)&pos = *(u128_t *)&v10;
    vec_add_ab(&pos, a0 + 0x10, &pos);
    life = func_0037E208(-10, 10) + 30;
    sz = func_0037E250(-0.1f, 0.1f) + 0.3f;
    color = st[0x16] << 16 | st[0x15] << 8 | st[0x14];
    b5 = 0;
    p = func_L01_0046C468(&pos, D_L02_001D66B0, life, color, func_0037E1D8(2) ? -1 : 1, 0x40, 0x20, 0,
                          sz * 210000.00f, sz * 210000.00f, 0.0011111111f);
    if (p != 0) {
        b5 = p[8] + 0x20;
        p[2] = *D_L02_0021E2BC;
    }
    p = func_L01_0046C468(&pos, D_L02_001D66B0, life, 0xF7F7F7, func_0037E1D8(2) ? -1 : 1, 0x30, 0x30, 0,
                          sz * 0.4f * 210000.00f, sz * 0.4f * 210000.00f, 0.0011111111f);
    if (p != 0) {
        p[8] = b5;
        p[2] = *D_L02_0021E2BC;
    }
}
/* localdecomp:end func_L02_0039EBD8 */
