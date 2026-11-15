#include "common.h"

/* localdecomp:start func_L08_003BDE60 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BDE60;
extern void func_0038CF68(V4_003BDE60 *out, void *v, f32 r);
extern s32 func_00382468(s32);
extern void func_003C4C18(f32 *v, f32 r);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_004637C8(void *, void *, u32, s32, s32, s32, s32, s32);

/* the same shape as func_L23_003BF290 (L23_003BF0C0.c) */
void func_L08_003BDE60(void *self, f32 spread, f32 height) {
    V4_003BDE60 pos;
    V4_003BDE60 vel;
    V4_003BDE60 center;
    f32 scale;
    s32 i;
    s32 r;
    s32 n;

    scale = *(f32 *)((u8 *)self + 0x2C) / *(f32 *)(*(u8 **)((u8 *)self + 0x24) + 0x24);
    func_0038CF68(&center, (u8 *)self + 0xD0, scale * height);
    vec_add_ab(&center, (u8 *)self + 0x10, &center);
    for (i = 0; i < 30; i++) {
        r = func_00382468(50);
        qzero(&pos);
        func_003C4C18(&pos.x, spread);
        vec_add_ab(&pos, &center, &pos);
        qzero(&vel);
        func_003C4C18(&vel.x, 0.0060000005f);
        vel.z += func_003824E0(0.0f, 0.010000001f);
        n = func_00382468(75);
        func_L01_004637C8(&pos, &vel, 0x70507080, 0, n + 0x4B, scale * (f32)(r + 0x82), scale * (f32)(r + 0xFA), i < 26);
    }
}
/* localdecomp:end func_L08_003BDE60 */
