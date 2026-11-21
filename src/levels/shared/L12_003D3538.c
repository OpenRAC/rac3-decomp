#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt003D1AA8;
typedef struct {
    s32 a;
    f32 b;
    s32 c;
    f32 d;
} Src_3D1EB8;

typedef struct {
    u8 pad0[0x19E0];
    u8 *f19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    s32 f25C0;
} G_003D1BE8;
typedef struct {
    u8 pad0[0x140];
    s32 f140;
    u8 pad144[0x160 - 0x144];
    u8 f160[0x1C8 - 0x160];
    f32 f1C8;
    u8 pad1CC[0x1E0 - 0x1CC];
    u8 f1E0[0x240 - 0x1E0];
    f32 f240;
    u8 pad244[0x274 - 0x244];
    f32 f274;
    f32 f278;
} P_003D1BE8;

/* declared by functions of L12_003D2E60.c, which this file was cut from */
extern void func_L12_003D3538(u8 *, u8 *, s32);

/* localdecomp:start func_L12_003D3538 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003D3538;
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *, s32, s32);
extern u8 D_L12_001D6700[];

void func_L12_003D3538(u8 *self, u8 *target, s32 flag) {
    V_003D3538 v;

    if (flag) {
        v = *(V_003D3538 *)(self + 0x10);
        v.z += *(f32 *)(target + 0x40);
        func_L01_003303B8(&v, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2,
                          *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24), 0.0f, 0.0f, 2.0f,
                          1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                          0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003A52A0(1, 0, self);
        func_L01_00452310(self, 0x1F, D_L12_001D6700, 1, 0x23, -1.0f, 3.0f, 6.0f, 3.0f, 6.0f,
                          0xFF, -1.0f, -1.0f, 0xB4, 0);
    }
    func_L01_004443E8(self, 0, 3);
}
/* localdecomp:end func_L12_003D3538 */
