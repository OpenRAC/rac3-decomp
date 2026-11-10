#include "common.h"

/* localdecomp:start func_L23_003BF0C0 */
extern u8 D_L23_001D66B0;
__asm__(".extern D_L23_001D66B0, 16");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L23_003BF290(void *, f32, f32, f32);

void func_L23_003BF0C0(void *self) {
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 3, &D_L23_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                      2.5f, 3.0f, 2.0f, 3.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L23_003BF290(self, 0.35f, 0.65f, 0.25f);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003BF0C0 */

/* localdecomp:start func_L23_003BF1A8 */
extern u8 D_L23_001D66B0;
__asm__(".extern D_L23_001D66B0, 16");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_L23_003BF290(void *, f32, f32, f32);

void func_L23_003BF1A8(void *self) {
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 3, &D_L23_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                      2.5f, 3.0f, 2.0f, 3.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L23_003BF290(self, 0.45f, 0.65f, 0.25f);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003BF1A8 */

/* localdecomp:start func_L23_003BF290 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern s32 func_00382468(s32);
extern void func_003C4C18(f32 *v, f32 r);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004637C8(void *, void *, u32, s32, s32, s32, s32, s32);

void func_L23_003BF290(void *self, f32 spread, f32 height, f32 base) {
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
        func_003C4C18(&vel.x, 0.0060000005f);
        vel.z += func_003824E0(0.0f, 0.010000001f);
        func_L01_004637C8(&pos, &vel, 0x70507080, 0, 0x4B, r + 0x1E, r + 0x6E, i < 26);
    }
}
/* localdecomp:end func_L23_003BF290 */

/* localdecomp:start func_L23_003BF3B0 */
extern u8 D_L23_001D66B0;
__asm__(".extern D_L23_001D66B0, 16");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                              f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_L23_003BF290(void *, f32, f32, f32);

void func_L23_003BF3B0(void *self) {
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 31, &D_L23_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                          3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L23_003BF290(self, 0.5f, 0.5f, 0.25f);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003BF3B0 */

/* localdecomp:start func_L23_003BF488 */
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern void func_L01_004AA7E8(u8 *a0, s32 a1);

void func_L23_003BF488(u8 *a0) {
    if (D_L23_001D6694 == 2) {
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & ~0x1000;
        func_L01_004AA7E8(a0, 1);
    } else {
        u8 *o = *(u8 **)(a0 + 36);
        *(u16 *)(a0 + 52) &= ~0x41;
        *(u16 *)(a0 + 52) |= *(u16 *)(o + 68) & 0x1000;
        *(s32 *)(a0 + 152) = *(s32 *)(o + 16);
    }
}
/* localdecomp:end func_L23_003BF488 */
