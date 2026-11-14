#include "common.h"

/* localdecomp:start func_L39_00565D30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00565D30;
extern f32 D_L39_0024B550;
extern f32 D_L39_0024B554;
__asm__(".extern D_L39_0024B550, 4");
__asm__(".extern D_L39_0024B554, 4");
extern s32 func_L39_005BE900(V4_00565D30 *, V4_00565D30 *, f32);
extern void func_L01_003303B8(V4_00565D30 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L39_00565D30(V4_00565D30 *a, f32 f, s32 b, s32 c) {
    V4_00565D30 v90;
    V4_00565D30 vA0;

    v90 = *a;
    v90.w = 0.5f;
    if (func_L39_005BE900(&v90, &vA0, 96.0f) > 0) {
        if (vA0.x < D_L39_0024B550 * D_L39_0024B550) {
            func_L01_003303B8(a, 0, 5, 0, 5, 5, 0, 0, f * 0.4f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, c, c, c, c, c, c, c, c, c, 0);
        } else if (vA0.x < D_L39_0024B554 * D_L39_0024B554) {
            func_L01_003303B8(a, 0, 2, 0, 0, 3, 0, 0, f * 0.4f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, c, c, c, c, c, c, c, c, c, 0);
        } else {
            func_L01_003303B8(a, 0, 0, 0, 0, 2, 0, 0, f * 0.4f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, c, c, c, c, c, c, c, c, c, 0);
        }
    }
}
/* localdecomp:end func_L39_00565D30 */
