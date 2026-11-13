#include "common.h"

/* NTSC-U counterpart of func_L23_003BF290 (src/levels/23_holostar_studios_clank/L23_003BF0C0.c): 0.006 -> 0.005; 0.01 -> 0.00833333; 75 -> 90 */
void func_L23_003BD6A0(void *, f32, f32, f32);
extern void func_L23_003BD6A0(void *, f32, f32, f32);

/* localdecomp:start func_L23_003BD6A0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern s32 func_00382468(s32);
extern void func_003C4C18(f32 *v, f32 r);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00460318(void *, void *, u32, s32, s32, s32, s32, s32);

void func_L23_003BD6A0(void *self, f32 spread, f32 height, f32 base) {
    V4 pos;
    V4 vel;
    s32 i;
    s32 r;

    for (i = 0; i < 30; i++) {
        r = func_00382468(30);
        qzero(&pos);
        func_003C4C18(&pos.x, spread);
        pos.z = func_003824E0(-height, height) + base;
        vec_add_ab(&pos, (u8 *)self + 0x10, &pos);
        qzero(&vel);
        func_003C4C18(&vel.x, 0.00500000035f);
        vel.z += func_003824E0(0.0f, 0.00833333377f);
        func_L01_00460318(&pos, &vel, 0x70507080, 0, 0x5A, r + 0x1E, r + 0x6E, i < 26);
    }
}
/* localdecomp:end func_L23_003BD6A0 */
