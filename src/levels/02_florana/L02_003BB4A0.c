#include "common.h"

/* localdecomp:start func_L02_003BB4A0 */
extern u8 D_L02_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L02_003BB4A0(void *self) {
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 63, D_L02_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L02_003BB4A0 */

/* localdecomp:start func_L02_003BB560 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L02_003BB560(u8 *o) {
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_003A52A0(0, 0, o);
        func_L01_00451FE0(o, 7, D_L02_001D66B0, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00451E78(o, 1, 0.0f);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L02_003BB560 */

/* localdecomp:start func_L02_003BB620 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BB620;
typedef struct {
    V4_3BB620 v;
    void *owner;
    s32 flags;
    s32 pad28;
    f32 f2c;
    s32 f30;
} S_3BB620;

extern u8 D_L02_001D66B0[];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_0038CF68(V4_3BB620 *, void *, f32);
extern void func_003D4D00(V4_3BB620 *, s32, void *, S_3BB620 *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L02_003BB620(u8 *self) {
    S_3BB620 s;
    V4_3BB620 pos;
    u8 *r;
    S_3BB620 *ps;
    if (func_L01_00447490(self, -1, 0) != 0) {
        ps = &s;
        s.f2c = 2.0f;
        s.v = *(V4_3BB620 *)(self + 0xC0);
        s.owner = self;
        s.f30 = 0;
        func_0038CF68(&pos, self + 0xE0, 0.5f);
        pos = *(V4_3BB620 *)(self + 0x10);
        s.flags = 0x8000000;
        pos.z += 1.4f;
        func_003D4D00(&pos, 0x10, self, ps, 1.4f);
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 0x3F, D_L02_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        if (func_00382468(3) != 0) {
            r = func_L01_00452460(self, 0x1CE1, 0);
            *(s32 *)(r + 0x98) = *(s32 *)(*(u8 **)(r + 0x24) + 0x10);
        }
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L02_003BB620 */

/* localdecomp:start func_L02_003BB790 */
extern u8 D_L02_001D66B0[];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L02_003BB790(void *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x3F, D_L02_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L02_003BB790 */
