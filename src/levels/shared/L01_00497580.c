#include "common.h"

/* localdecomp:start func_L01_00497580 */
__asm__(".extern D_L01_001D9210, 4");
__asm__(".extern D_L01_001D9214, 4");
__asm__(".extern D_L01_001D9218, 4");
__asm__(".extern D_L01_001D921C, 4");
__asm__(".extern D_L01_001D91B0, 4");
__asm__(".extern D_L01_001D91B4, 4");
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern s32 D_L01_001D9210;
extern s32 D_L01_001D9214;
extern s32 D_L01_001D9218;
extern s32 D_L01_001D921C;
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_00497580(s32 a, s32 b) {
    f32 *v = (f32 *)b;

    func_003E9138(0x47001C, 0x80808080, 0, v[0] + (f32)D_L01_001D9210 * 0.001953125f, v[1] + (f32)D_L01_001D9214 / 416.0f,
                  v[2] + (f32)D_L01_001D9218 * 0.001953125f, v[3] + (f32)D_L01_001D921C / 416.0f);
    func_003E9270(0x47001B, 0x332299DE, v[0], v[1], v[2], v[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_003E8A08(a, 0x47001B, 0x47001C);
}
/* localdecomp:end func_L01_00497580 */
