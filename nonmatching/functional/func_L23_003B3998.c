/* functional: high. Same stores and calls; only store order differs from retail. */
typedef struct {
    u8 pad0[0x30]; f32 f30; s16 h34; u8 pad36[3]; u8 b39; u8 pad3A[6]; f32 f40;
    u8 pad44[0x58 - 0x44]; u8 b58; u8 pad59; u8 b5A; u8 pad5B[0x70 - 0x5B];
    f32 f70, f74, f78, f7C, f80; u8 pad84[0xA8 - 0x84]; s32 iA8;
    u8 padAC[0x2A4 - 0xAC]; f32 f2A4; u8 pad2A8[0x2B8 - 0x2A8]; f32 f2B8;
    u8 pad2BC[0x2DC - 0x2BC]; s32 w2DC, w2E0, w2E4; u8 pad2E8[0x300 - 0x2E8];
    s32 w300, w304; f32 f308; s32 w30C; u8 pad310[4]; s32 w314, w318, w31C;
    u8 pad320[4]; s32 w324, w328, w32C, w330, w334; f32 f338; s32 w33C, w340, w344, w348, w34C;
    V4 v350; V4 v360; V4 v370; s32 w380, w384, w388, w38C, w390; u8 pad394[4]; s32 w398;
} Vars_3B3998;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b30_pad[0x30 - 0x20]; u8 b30; u8 pad31; s16 h32;
    u8 pad34[0x68 - 0x34]; Vars_3B3998 *vars; u8 pad6C[0x7C - 0x6C]; s16 h7C;
    u8 pad7E[0xF8 - 0x7E]; f32 fF8;
} Moby_3B3998;
extern s32 D_L23_001DDFA0;
extern u16 D_L23_001DE330;
__asm__(".extern D_L23_001DE330, 2");
extern f32 D_L23_001DE328;
__asm__(".extern D_L23_001DE328, 4");
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L23_003B3998(u8 *arg)
{
    Moby_3B3998 *self = arg;
    Vars_3B3998 *v = self->vars;
    f32 scale;
    f32 hf;

    v->b58 = 0x14;
    v->b5A = 0xE;
    if (v->h34 == 0) {
        v->h34 = D_L23_001DE330;
    }
    if (D_L23_001DDFA0 > 0) {
        scale = 1.0f - (f32)D_L23_001DDFA0 * 0.1f;
        if (!(0.25f < scale)) {
            scale = 0.25f;
        }
        v->h34 = (s16)((f32)v->h34 * scale);
    }
    v->b39 = 1;
    hf = (f32)v->h34;
    v->f40 = 3.5f;
    v->w2E0 = 0x21;
    v->w2E4 = 0x43;
    v->f2A4 = 0.87266463f;
    v->f74 = D_L23_001DE328;
    v->f80 = 1.3962634f;
    v->iA8 = 1;
    v->f30 = hf;
    v->f70 = D_L23_001DE328;
    v->f7C = 1.0f;
    v->f2B8 = 1.0f;
    v->f78 = 1.0f;
    v->w2DC = 0;
    v->w300 = 0;
    v->w304 = 0;
    v->f338 = hf;
    v->f308 = self->fF8;
    v->w314 = -1;
    v->w30C = 0;
    v->w318 = 0;
    v->w31C = 0;
    v->w324 = 0;
    v->w328 = 0;
    v->w32C = 0;
    v->w330 = 0;
    v->w334 = 0;
    v->w33C = 0;
    v->w340 = 0;
    v->w344 = 0;
    v->w348 = 0;
    v->w34C = 0;
    v->v350 = self->pos;
    v->v360 = self->pos;
    v->v370 = self->pos;
    v->v370.z = func_003C3D30(&v->v370, 0, 0, 0.5f);
    v->w390 = -1;
    v->w398 = 0;
    v->w380 = 0;
    v->w384 = 0;
    v->w388 = 0;
    v->w38C = 0;
    self->b30 = 0xF0;
    self->h7C = 0xFF;
    self->h32 = 0xF0;
    D_L23_001DE2D0 = (void *)self;
    func_L01_004450F0(self, 1, 0);
}
