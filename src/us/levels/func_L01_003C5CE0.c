#include "common.h"

/* NTSC-U counterpart of func_L01_003C7560 (src/levels/shared/L01_003C7560.c): 0.0004 -> 0.000277778; 0.02 -> 0.0166667 */
/* localdecomp:start func_L01_003C5CE0 */
extern s32 D_L01_001DFBC0_003C5CE0;
extern s32 D_L01_001DEC74;
extern f32 D_L01_001DEC68_003C5CE0;
extern f32 D_L01_001DEC6C_003C5CE0;
extern f32 D_L01_001DEC64_003C5CE0;
extern f32 D_L01_001DEC84_003C5CE0;
extern f32 D_L01_001DEC88_003C5CE0;
extern f32 D_L01_001DEC80_003C5CE0;
__asm__(".extern D_L01_001DFBC0_003C5CE0, 16");
__asm__(".extern D_L01_001DEC74, 4");
__asm__(".extern D_L01_001DEC68_003C5CE0, 4");
__asm__(".extern D_L01_001DEC6C_003C5CE0, 4");
__asm__(".extern D_L01_001DEC64_003C5CE0, 4");
__asm__(".extern D_L01_001DEC84_003C5CE0, 4");
__asm__(".extern D_L01_001DEC88_003C5CE0, 4");
__asm__(".extern D_L01_001DEC80_003C5CE0, 4");
extern s32 func_L01_003C5780(void *, void *);
extern f32 func_L01_00445758(void *, f32, void *, s32, f32, f32, f32);
extern f32 func_003BEC60(f32 *, void *, f32, f32, f32, f32);

s32 func_L01_003C5CE0(void *m, u8 *v) {
    if (D_L01_001DFBC0_003C5CE0 - D_L01_001DEC74 < *(s32 *)(v + 0xA4)) {
        func_L01_003C5780(m, v);
    } else {
        func_L01_00445758(v + 0x674, 0.0f, v + 0x98, 0,
                          D_L01_001DEC68_003C5CE0 * 0.017453292f * 0.000277777785f,
                          D_L01_001DEC6C_003C5CE0 * 0.017453292f * 0.000277777785f,
                          D_L01_001DEC64_003C5CE0 * 0.017453292f * 0.0166666675f);
        *(f32 *)(v + 0x694) = *(f32 *)(v + 0x674);
    }
    func_003BEC60((f32 *)(v + 0x6A8), v + 0x9C, 0.0f,
                  D_L01_001DEC84_003C5CE0 * 0.017453292f * 0.000277777785f,
                  D_L01_001DEC88_003C5CE0 * 0.017453292f * 0.000277777785f,
                  D_L01_001DEC80_003C5CE0 * 0.017453292f * 0.0166666675f);
    if (*(f32 *)(v + 0x674) == 0.0f && *(f32 *)(v + 0x6A8) == 0.0f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003C5CE0 */
