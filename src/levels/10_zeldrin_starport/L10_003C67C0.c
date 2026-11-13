#include "common.h"

/* localdecomp:start func_L10_003C67C0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C67C0;
typedef struct {
    V4_3C67C0 v;
    void *owner;
    s32 flags;
    s32 pad28;
    f32 f2c;
    s32 f30;
} S_3C67C0;

extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003D4D00(void *, s32, void *, S_3C67C0 *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L10_003C67C0(u8 *self) {
    S_3C67C0 s;

    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 0x1F, D_L10_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        s.owner = self;
        s.f2c = 2.0f;
        s.v = *(V4_3C67C0 *)(self + 0xC0);
        s.flags = 0x8000000;
        s.f30 = 0;
        func_003D4D00(self + 0x10, 0x10, self, &s, 1.4f);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L10_003C67C0 */
