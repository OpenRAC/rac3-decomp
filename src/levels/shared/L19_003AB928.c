#include "common.h"

/* declared by functions of L19_003AB7D0.c, which this file was cut from */
typedef struct { f32 x; f32 y; f32 z; f32 w; } V4_3A9BF8;
typedef struct {
    u8 p0[0x10]; V4_3A9BF8 pos; u8 b20; u8 p21[0x47]; void *w68; u8 p6C[0x29]; u8 b95; u8 p96[0x14]; s16 hAA;
} M_3A9BF8;
extern void func_L19_003AB928(M_3A9BF8 *);

/* localdecomp:start func_L19_003AB928 */
typedef int Q_003AB928 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[3];
    u8 b39;
    u8 pad3A[4];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59;
    u8 b5A;
    u8 pad5B[0x15];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    s32 w9C;
    f32 fA0;
    u8 padA4[0xCC];
    u8 b170;
    u8 pad171[0x1F];
    f32 f190;
    f32 f194;
    u8 pad198[4];
    f32 f19C;
    u8 pad1A0[8];
    u8 b1A8;
    u8 pad1A9[0x2E];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 pad1DC[0x64];
    s32 w240;
    u8 pad244[4];
    s32 w248;
    s32 w24C;
    s32 w250;
    s32 w254;
    u8 pad258[0xC];
    s32 w264;
    s32 w268;
    s32 w26C;
    u8 pad270[4];
    s32 w274;
    s32 w278;
    s32 w27C;
    u8 pad280[0x10];
    Q_003AB928 q290;
    u8 b2A0[0x10];
} S_003AB928;

extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L19_003AB928(M_3A9BF8 *m) {
    S_003AB928 *v = m->w68;
    s32 seven;
    v->b1D7 = 1;
    v->b1D8 = 0;
    seven = 7;
    v->b1D9 = 0;
    v->b1A8 = 3;
    v->b1DA = 0;
    v->w9C = 0;
    v->b170 = seven;
    v->f19C = 0.15f;
    v->b1DB = 0xFF;
    v->f70 = 0.7f;
    v->f190 = 0.5f;
    v->f194 = 0.5f;
    v->f74 = 0.5f;
    v->f78 = 0.5f;
    v->f7C = 1.0f;
    v->f80 = 1.5707964f;
    v->fA0 = 0.34906584f;
    func_L01_0045BD78(m, 0.0024f, 0.060000002f, 0.0033510325f, 0.12566371f);
    v->b58 = 20;
    v->b5A = 14;
    if (v->h34 == 0) {
      v->h34 = 100;
      v->f30 = 100.0f;
    }
    v->b3E = 1;
    v->f40 = 2.0f;
    v->b39 = 0;
    *(u16 *)((u8 *)m + 0x34) |= 0x10;
    v->w278 = -1;
    v->w240 = 0;
    v->w248 = 0;
    v->w250 = 0;
    v->w254 = 0;
    v->w274 = 0;
    v->w24C = 0;
    v->w264 = 0;
    v->w26C = 0;
    v->w268 = 0;
    v->w27C = 0;
    v->q290 = *(Q_003AB928 *)&m->pos;
    func_L01_0043A430(m, 0, v->b2A0);
    func_L01_004450F0(m, 1, 1);
}
/* localdecomp:end func_L19_003AB928 */
