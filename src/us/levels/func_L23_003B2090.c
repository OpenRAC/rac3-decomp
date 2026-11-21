#include "common.h"

/* NTSC-U counterpart of func_L23_003B3998 (src/levels/23_holostar_studios_clank/L23_003AD800.c): 60 Hz timers (40, 80 frames) */
/* localdecomp:start func_L23_003B2090 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B2090;
typedef struct Moby_3B2090 Moby_3B2090;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x39 - 0x36];
    u8 x39;
    u8 pad3A[0x40 - 0x3A];
    f32 x40;
    u8 pad44[0x58 - 0x44];
    u8 x58;
    u8 pad59;
    u8 x5A;
    u8 pad5B[0x70 - 0x5B];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0xA8 - 0x84];
    s32 xA8;
    u8 padAC[0x2A4 - 0xAC];
    f32 x2A4;
    u8 pad2A8[0x2B8 - 0x2A8];
    f32 x2B8;
    u8 pad2BC[0x2DC - 0x2BC];
    s32 x2DC;
    s32 x2E0;
    s32 x2E4;
    u8 pad2E8[0x300 - 0x2E8];
    s32 x300;
    s32 x304;
    f32 x308;
    s32 x30C;
    u8 pad310[4];
    s32 x314;
    s32 x318;
    s32 x31C;
    u8 pad320[4];
    s32 x324;
    s32 x328;
    s32 x32C;
    s32 x330;
    s32 x334;
    f32 x338;
    s32 x33C;
    s32 x340;
    s32 x344;
    s32 x348;
    s32 x34C;
    V4_3B2090 x350;
    V4_3B2090 x360;
    V4_3B2090 x370;
    s32 x380;
    s32 x384;
    s32 x388;
    s32 x38C;
    s32 x390;
    u8 pad394[4];
    s32 x398;
} Vars_3B2090;

extern Moby_3B2090 *D_L23_001DE310;
extern void func_L01_00441FB8(void *, s32, s32);
extern u16 D_L23_001DE370;
__asm__(".extern D_L23_001DE370, 4");
extern f32 D_L23_001DE368;
__asm__(".extern D_L23_001DE368, 4");
extern s32 D_L23_001DDFE0;

extern f32 func_003BE7F0(void *, s32, s32, f32);

void func_L23_003B2090(u8 *self)
{
    Vars_3B2090 *v = *(Vars_3B2090 **)(self + 0x68);
    f32 f;
    f32 s;

    v->x58 = 0x14;
    v->x5A = 0xE;
    if (v->x34 == 0)
        v->x34 = D_L23_001DE370;
    if (D_L23_001DDFE0 > 0) {
        f = 1.0f - D_L23_001DDFE0 * 0.1f;
        if (f > 0.25f)
            s = f;
        else
            s = 0.25f;
        v->x34 = v->x34 * s;
    }
    v->x30 = v->x34;
    v->x39 = 1;
    v->x2DC = 0;
    v->x70 = D_L23_001DE368;
    v->x40 = 3.5f;
    v->x2E0 = 0x28;
    v->x2E4 = 0x50;
    v->x2B8 = 1.0f;
    v->x300 = 0;
    v->x2A4 = 0.87266463f;
    v->x74 = D_L23_001DE368;
    v->x304 = 0;
    v->x80 = 1.3962634f;
    v->xA8 = 1;
    v->x78 = 1.0f;
    v->x7C = 1.0f;
    v->x308 = *(f32 *)(self + 0xF8);
    v->x30C = 0;
    v->x318 = 0;
    v->x31C = 0;
    v->x324 = 0;
    v->x328 = 0;
    v->x32C = 0;
    v->x330 = 0;
    v->x334 = 0;
    v->x314 = -1;
    v->x33C = 0;
    v->x338 = v->x34;
    v->x340 = 0;
    v->x344 = 0;
    v->x348 = 0;
    v->x34C = 0;
    v->x350 = *(V4_3B2090 *)(self + 0x10);
    v->x360 = *(V4_3B2090 *)(self + 0x10);
    v->x370 = *(V4_3B2090 *)(self + 0x10);
    v->x370.z = func_003BE7F0(&v->x370, 0, 0, 0.5f);
    v->x390 = -1;
    v->x380 = 0;
    v->x384 = 0;
    v->x388 = 0;
    v->x38C = 0;
    v->x398 = 0;
    *(s16 *)(self + 0x32) = 0xF0;
    self[0x30] = 0xF0;
    *(s16 *)(self + 0x7C) = 0xFF;
    D_L23_001DE310 = (Moby_3B2090 *)self;
    func_L01_00441FB8(self, 1, 0);
}
/* localdecomp:end func_L23_003B2090 */
