/* functional: high. Same stores and call; retail differs only in register allocation and store order. */
typedef struct {
    u8 pad0[0x30]; f32 f30; u16 h34; u8 pad36[3]; u8 b39; u8 pad3A[6]; f32 f40;
    u8 pad44[0x58 - 0x44]; u8 b58; u8 pad59; u8 b5A; u8 pad5B[0x70 - 0x5B];
    f32 f70, f74, f78, f7C, f80; u8 pad84[0x9C - 0x84]; f32 f9C, fA0, fA4;
    u8 padA8[0x170 - 0xA8]; u8 b170, b171; u8 pad172[0x17C - 0x172];
    f32 f17C, f180, f184, f188, f18C, f190, f194; u8 pad198[4]; f32 f19C, f1A0;
    u8 pad1A4[0x1A9 - 0x1A4]; u8 b1A9; u8 pad1AA[0x1B8 - 0x1AA]; f32 f1B8, f1BC;
    u8 pad1C0[0x1CC - 0x1C0]; u8 b1CC, b1CD; u8 pad1CE[0x1D7 - 0x1CE]; u8 b1D7, b1D8;
    u8 pad1D9[2]; u8 b1DB; u8 pad1DC[0x2C0 - 0x1DC]; s32 w2C0, w2C4, w2C8, w2CC;
    u8 pad2D0[0x2E8 - 0x2D0]; s32 w2E8; u8 pad2EC[4]; s32 w2F0, w2F4;
    u8 pad2F8[0x308 - 0x2F8]; s32 w308; u8 pad30C[0x320 - 0x30C]; V4 v320; V4 v330;
} Vars_3B65F0;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 pad20[0x68 - 0x20]; Vars_3B65F0 *vars;
} Moby_3B65F0;
extern f32 D_L23_001DE474;
__asm__(".extern D_L23_001DE474, 4");
extern f32 D_L23_001DE478;
__asm__(".extern D_L23_001DE478, 4");
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B65F0(void *arg)
{
    Moby_3B65F0 *self = arg;
    Vars_3B65F0 *v = self->vars;

    v->b58 = 10;
    v->b5A = 2;
    v->f40 = 0.3f;
    v->b39 = 1;
    if (v->h34 == 0) {
        v->h34 = 2;
        v->f30 = 2.0f;
    }
    v->f78 = 0.5f;
    v->b170 = 0xB;
    v->b1CD = 0xE;
    v->b1DB = 0x14;
    v->fA4 = D_L23_001DE478;
    v->f80 = 1.553343f;
    v->fA0 = 0.17453292f;
    v->f9C = 0.00392f;
    v->f194 = D_L23_001DE474;
    v->f19C = 0.15f;
    v->b1D7 = 1;
    v->b1CC = 7;
    v->f1B8 = 0.1f;
    v->f1BC = 1.0f;
    v->f17C = 0.3f;
    v->f180 = 0.030000001f;
    v->f188 = 0.010000001f;
    v->f18C = 0.00080000004f;
    v->f70 = D_L23_001DE474;
    v->f74 = D_L23_001DE474;
    v->f7C = 1.0f;
    v->f190 = D_L23_001DE474;
    v->b171 = 7;
    v->b1D8 = 0;
    v->f184 = 0.010000001f;
    v->b1A9 = 0;
    v->f1A0 = self->pos.z - 10.0f;
    v->w2C0 = 0;
    v->w2C4 = 0;
    v->w2C8 = 0;
    v->w2CC = 0;
    v->w2F0 = 0;
    v->w2F4 = 0;
    v->w2E8 = 0;
    v->v320 = self->pos;
    v->v330 = self->pos;
    if (v->w308 != 0) {
        func_L01_004450F0(self, 4, 1);
    } else {
        func_L01_004450F0(self, 4, 2);
    }
}
