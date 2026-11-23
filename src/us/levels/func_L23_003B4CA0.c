#include "common.h"

/* NTSC-U counterpart of func_L23_003B65F0, with regional timing. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    u8 pad0[0x30]; f32 x30; s16 h34; u8 pad36[0x3]; u8 x39; u8 pad3A[0x6]; f32 x40; u8 pad44[0x14];
    u8 x58; u8 pad59[0x1]; u8 x5A; u8 pad5B[0x15]; f32 x70; f32 x74; f32 x78; f32 x7C; f32 x80; u8 pad84[0x18];
    f32 x9C; f32 xA0; f32 xA4; u8 padA8[0xC8]; u8 x170; u8 x171; u8 pad172[0xA];
    f32 x17C; f32 x180; f32 x184; f32 x188; f32 x18C; f32 x190; f32 x194; u8 pad198[0x4]; f32 x19C; f32 x1A0;
    u8 pad1A4[0x5]; u8 x1A9; u8 pad1AA[0xE]; f32 x1B8; f32 x1BC; u8 pad1C0[0xC]; u8 x1CC; u8 x1CD; u8 pad1CE[0x9];
    u8 x1D7; u8 x1D8; u8 pad1D9[0x2]; u8 x1DB; u8 pad1DC[0x220 - 0x1DC];
    V4 v220; s32 w230; s16 h234; u8 pad236[0x240 - 0x236]; u8 a240[0x80];
    s32 x2C0; s32 x2C4; s32 x2C8; s32 x2CC;
    s32 w2D0; f32 f2D4; s32 w2D8; f32 f2DC; u8 pad2E0[0x8]; s32 x2E8; u8 pad2EC[0x4]; s32 x2F0; s32 x2F4;
    u8 pad2F8[0x10]; s32 x308; s32 w30C; u8 pad310[0x10]; V4 x320; V4 x330;
} V_3B4CA0;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[0x10]; u8 b31; u8 pad32[0x68 - 0x32];
    V_3B4CA0 *vars; u8 pad6C[3]; u8 b6F; u8 pad70[0x25]; u8 b95;
} M_3B4CA0;

extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L23_003B4CA0 */
extern f32 D_L23_001DE4B4;
__asm__(".extern D_L23_001DE4B4, 4");
extern f32 D_L23_001DE4B8;
__asm__(".extern D_L23_001DE4B8, 4");

void func_L23_003B4CA0(void *obj)
{
    M_3B4CA0 *m = obj;
    V_3B4CA0 *v = m->vars;
    f32 g;
    f32 h;

    v->x58 = 10;
    v->x5A = 2;
    v->x40 = 0.3f;
    v->x39 = 1;
    if (v->h34 == 0) {
        v->h34 = 2;
        v->x30 = 2.0f;
    }
    g = D_L23_001DE4B4;
    h = D_L23_001DE4B8;
    v->x70 = g;
    v->x78 = 0.5f;
    v->xA4 = h;
    v->x80 = 1.553343f;
    v->xA0 = 0.17453292f;
    v->x9C = 0.0027222224f;
    v->x74 = g;
    v->x170 = 11;
    v->x7C = 1.0f;
    v->x190 = g;
    v->x194 = g;
    v->x19C = 0.15f;
    v->x1D7 = 1;
    v->x171 = 7;
    v->x1CC = 7;
    v->x1D8 = 0;
    v->x1B8 = 0.1f;
    v->x1BC = 1.0f;
    v->x1CD = 14;
    v->x1DB = 20;
    v->x184 = 0.0069444445f;
    v->x17C = 0.25f;
    v->x180 = 0.025000002f;
    v->x1A9 = 0;
    v->x188 = 0.0069444445f;
    v->x18C = 0.00055555557f;
    v->x1A0 = m->pos.z - 10.0f;
    v->x2C0 = 0;
    v->x2C4 = 0;
    v->x2C8 = 0;
    v->x2CC = 0;
    v->x2F0 = 0;
    v->x2F4 = 0;
    v->x2E8 = 0;
    v->x320 = m->pos;
    v->x330 = m->pos;
    if (v->x308 != 0)
        func_L01_00441FB8(m, 4, 1);
    else
        func_L01_00441FB8(m, 4, 2);
}
/* localdecomp:end func_L23_003B4CA0 */
