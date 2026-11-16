/* NTSC-U draft (Claude wave C3): C of func_L16_003E3840, the NTSC-U twin of func_L16_003E56F0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L16_003E3840", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (native MATCH, 412 B) only with an extra @ps2as on the PAL counterpart file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division): its float constants are lui/ori/mtc1 in retail, gp-relative .lit4 loads with plain ee-as. Template ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L16_003E56F0 (src/levels/shared/L16_003E5488.c) */
/* localdecomp:start func_L16_003E3840 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003DC320;
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern f32 D_L16_001DF4C4;
__asm__(".extern D_L16_001DF4C4, 4");
extern f32 D_L16_001DF4C8;
__asm__(".extern D_L16_001DF4C8, 4");

void func_L16_003E3840(u8 *p) {
    V4_003DC320 a;
    V4_003DC320 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_003DC320){0.0f, 0.0f, 0.0f, 0.0f};
    b.z = D_L16_001DF4C4 * (1.0f / D_L16_001DF4C8);
    a = b;
    b = (V4_003DC320){0.0f, 0.0f, 0.0f, 0.0f};
    b.x = 0.033333335f;
    b.z = 0.033333335f;
    func_003888C8(&b, &b, p + 0xC0);
    r = func_0037E208(3, 6);
    func_L02_003E0520(p, &a, 0.0f, &b, r, 0, 0, 0.033333335f, 0.7f, 15.0f, 1.0f);
    b.x = -0.033333335f;
    b.z = 0.040000003f;
    func_003888C8(&b, &b, p + 0xC0);
    r = func_0037E208(3, 6);
    func_L02_003E0520(p, &a, 0.0f, &b, r, 1, 0, 0.033333335f, 0.7f, 15.0f, 1.0f);
    *q = func_0037E208(90, 180);
}
/* localdecomp:end func_L16_003E3840 */
