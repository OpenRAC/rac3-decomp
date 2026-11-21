/* functional: high. Written from the disassembly; compiles clean, plain float C instead of retail's VU0 vadd/vsub.xyz (same results, w carried from the random-direction vector). Retail's 0x3CA3D70B constant kept. */
#include "common.h"
/* localdecomp:start func_L01_003D8DA0 */
typedef struct { f32 x, y, z, w; } V4_003D8DA0 __attribute__((aligned(16)));
extern f32 D_001DF4D8_sda;
extern s32 D_001DF4D4_sda;
extern s32 D_001DF4D0_sda;
__asm__(".extern D_001DF4D8_sda, 4");
__asm__(".extern D_001DF4D4_sda, 4");
__asm__(".extern D_001DF4D0_sda, 4");
void func_L01_003D8DA0(f32 *p) {
    extern void func_00382580(void *, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00471BF0(void *, void *, s32);
    V4_003D8DA0 pos, vel;
    func_00382580(&pos, 0.25f, 0.75f);
    pos.x = pos.x + p[0];
    pos.y = pos.y + p[1];
    pos.z = pos.z + p[2];
    vel.x = pos.x - p[0];
    vel.y = pos.y - p[1];
    vel.z = pos.z - p[2];
    vel.w = pos.w;
    func_0038CE20(&vel, &vel, func_003824E0(2.0f, 3.0f) * 0.020000001415610313f);
    vel.z = vel.z + D_001DF4D8_sda;
    func_L01_00471BF0(&pos, &vel, func_00382498(D_001DF4D4_sda, D_001DF4D0_sda));
}
/* localdecomp:end func_L01_003D8DA0 */
