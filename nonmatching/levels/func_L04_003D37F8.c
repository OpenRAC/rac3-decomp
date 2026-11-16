/* NTSC-U draft (Codex wave 3): C of func_L04_003D1920, the NTSC-U twin of func_L04_003D37F8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 121 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L04_003D1920", whose code is not the PAL one).
 * Worker's note: 121 diff; flags blocker: default ee-as emits literal-pool lwc1 for retail inline lui/ori/mtc1 constants; documented Matching-Patterns line 139 requires unlisted @ps2as; not tried; real VU0 block has operands/clobbers; best log func_L04_003D1920.check02.log
 */
#include "common.h"

/* localdecomp:start func_L04_003D1920 */
typedef int Q_003D1920 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003D1920;
extern s32 D_L04_001DF9C0[];
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004632D8(void *, void *, s32, s32, s32, f32);

void func_L04_003D1920(u8 *self, u8 *p) {
    V_003D1920 pos, vel, tmp;
    s32 c, color;
    f32 size;
    if (!(D_L04_001DF9C0[0] & 1)) {
        *(f32 *)(p + 0x9C) = func_00389380(*(f32 *)(p + 0x9C), func_L01_00440918(0.052359879f, 0.104719758f));
        *(Q_003D1920 *)&pos = *(Q_003D1920 *)(self + 0x10);
        pos.z += 1.0f;
        pos.x += func_00388960(*(f32 *)(p + 0x9C)) * func_L01_00440918(0.5f, 1.0f);
        pos.y += func_00388978(*(f32 *)(p + 0x9C)) * func_L01_00440918(0.5f, 1.0f);
        if (*(s32 *)(p + 0x90)) {
            func_003886E8(&tmp, self + 0xC0, 3.0f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(pos) : "m"(tmp), "m"(pos) : "vf1", "vf2");
        }
        vel.x = func_00388960(*(f32 *)(p + 0x9C)) * (func_0037E250(0.5f, 2.0f) * 0.0166666675f);
        vel.y = func_00388978(*(f32 *)(p + 0x9C)) * (func_0037E250(0.5f, 2.0f) * 0.0166666675f);
        vel.z = 0.0f;
        vel.z = func_0037E250(0.0333333351f, 0.0833333358f);
        c = func_0037E208(0x10, 0x20);
        color = ((c << 8) | 0x80000000) | (c << 16);
        color |= c;
        size = func_0037E250(3.0f, 5.0f) * 210000.0f;
        func_L01_004632D8(&pos, &vel, color, 0x101010, func_0037E208(0x50, 0x78), size);
    }
}
/* localdecomp:end func_L04_003D1920 */
