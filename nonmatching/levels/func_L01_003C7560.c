/* NTSC-U draft (Codex wave 3): C of func_L01_003C5CE0, the NTSC-U twin of func_L01_003C7560, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 64 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003C5CE0", whose code is not the PAL one).
 * Worker's note: 64 diff; best log func_L01_003C5CE0.c01.log; flags blocker documented Matching-Patterns.md:139: default assembler pools 0.017453292/0.00027777778450399637/0.016666668 literals where retail has inline lui/ori/mtc1; @ps2as unlisted and never tried; initial ...
 */
#include "common.h"

/* localdecomp:start func_L01_003C5CE0 */
extern s32 D_L01_001DFBC0[];
extern s32 D_001DEC74_sda;
extern f32 D_001DEC68_sda, D_001DEC6C_sda, D_001DEC64_sda;
extern f32 D_001DEC84_sda, D_001DEC88_sda, D_001DEC80_sda;
extern void func_L01_003C5780(void *, void *);
extern f32 func_L01_00445758(void *, f32, void *, s32, f32, f32, f32);
extern void func_003BEC60(f32 *, f32, void *, f32, f32, f32);

s32 func_L01_003C5CE0(void *m, u8 *v) {
    if (D_L01_001DFBC0[0] - D_001DEC74_sda < *(s32 *)(v + 0xA4)) {
        func_L01_003C5780(m, v);
    } else {
        func_L01_00445758(v + 0x674, 0.0f, v + 0x98, 0,
            D_001DEC68_sda * 0.017453292f * 0.00027777778450399637f,
            D_001DEC6C_sda * 0.017453292f * 0.00027777778450399637f,
            D_001DEC64_sda * 0.017453292f * 0.016666668f);
        *(f32 *)(v + 0x694) = *(f32 *)(v + 0x674);
    }
    func_003BEC60((f32 *)(v + 0x6A8), 0.0f, v + 0x9C,
        D_001DEC84_sda * 0.017453292f * 0.00027777778450399637f,
        D_001DEC88_sda * 0.017453292f * 0.00027777778450399637f,
        D_001DEC80_sda * 0.017453292f * 0.016666668f);
    return *(f32 *)(v + 0x674) == 0.0f && *(f32 *)(v + 0x6A8) == 0.0f;
}
/* localdecomp:end func_L01_003C5CE0 */
