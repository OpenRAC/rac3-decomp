/* functional: high. PAL port of the NTSC draft: PAL uses 0.02 (0x3CA3D70B) not 1/60, and its own gp constants (0x23A4..0x23BC) and callees (angle step, sin, cos). Only 7 words of scheduling differ; the NTSC draft was not trusted. */
#include "common.h"
/* localdecomp:start func_L01_003C6D30 */
extern f32 D_L01_001DEC58, D_L01_001DEC54, D_L01_001DEC64, D_L01_001DEC68, D_L01_001DEC6C, D_L01_001DEC5C, D_L01_001DEC60;
__asm__(".extern D_L01_001DEC58, 4");
__asm__(".extern D_L01_001DEC54, 4");
__asm__(".extern D_L01_001DEC64, 4");
__asm__(".extern D_L01_001DEC68, 4");
__asm__(".extern D_L01_001DEC6C, 4");
__asm__(".extern D_L01_001DEC5C, 4");
__asm__(".extern D_L01_001DEC60, 4");
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
void func_L01_003C6D30(s32 unused, u8 *obj, f32 *p1, f32 *p2, f32 *p3) {
    *(f32 *)(obj + 0xB4) = func_0038DAB8(*(f32 *)(obj + 0xB4), D_L01_001DEC58 * 0.017453292f * 0.020000001f);
    *p1 = func_0038D0B0(*(f32 *)(obj + 0xB4)) * D_L01_001DEC54;
    *p2 = D_L01_001DEC64 * func_0038D0B0(*(f32 *)(obj + 0xB8)) * func_0038D0B0(*(f32 *)(obj + 0xBC)) * 1.5f;
    *p3 = D_L01_001DEC64 * func_0038D0B0(*(f32 *)(obj + 0xB8)) * func_0038D098(*(f32 *)(obj + 0xBC));
    *(f32 *)(obj + 0xB8) = func_0038DAB8(*(f32 *)(obj + 0xB8), D_L01_001DEC68 * 0.017453292f * 0.020000001f);
    *(f32 *)(obj + 0xBC) = func_0038DAB8(*(f32 *)(obj + 0xBC), D_L01_001DEC6C * 0.017453292f * 0.020000001f);
    *p3 += func_0038D0B0(*(f32 *)(obj + 0xB4) + D_L01_001DEC5C) * D_L01_001DEC60;
}
/* localdecomp:end func_L01_003C6D30 */
