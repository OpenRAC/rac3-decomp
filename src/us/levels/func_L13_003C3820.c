#include "common.h"

/* NTSC-U counterpart of func_L13_003C59E8 (src/levels/shared/L13_003C59E8.c): 0.12 -> 0.1 */
/* localdecomp:start func_L13_003C3820 */
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_0044DB68(void *, void *, f32, f32, f32);
extern void func_L01_00443610(void *, void *, s32, f32);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern void func_L04_00324BA8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_L01_0044F1E8(void *, s32, s32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C59E8;
typedef struct {
    u8 pad[0x18];
    u8 a;
    u8 b;
    u16 c;
    s32 d[5];
} Hit_003C59E8;

void func_L13_003C3820(u8 *self) {
    u8 *p;
    V4_003C59E8 v;
    V4_003C59E8 pos;
    Hit_003C59E8 h;

    p = *(u8 **)(self + 0x68);
    func_0039FE80(4, 0, self);
    func_003886E8(&v, self + 0xE0, 0.100000009f);
    func_L01_0044ED60(self, 0x7FF, &v, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    if (*(s32 *)(p + 0x250)) {
        func_L01_0044DB68(self, &pos, 0.0f, 0.0f, 1.5f);
        func_L01_00443610(&h, self, 0x1010001, *(s32 *)(p + 0x254) ? 2.0f : 10.0f);
        h.a = 2;
        h.b = 1;
        h.c = *(u16 *)(self + 0xAA);
        func_003CF790(&pos, 0x10, 3.0f, self, &h);
        func_L04_00324BA8(self + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 20.0f, 1, 1, 0, 0);
    }
    func_L01_0044F1E8(self, 0x1EF5, 0x20);
}
/* localdecomp:end func_L13_003C3820 */
