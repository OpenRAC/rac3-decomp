#include "common.h"

/* NTSC-U counterpart of func_L24_00354F38 (src/levels/24_insomniac_museum/L24_00354948.c) */
extern s32 func_L24_00353F00(void *);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L24_00353F00 */
#include "vu0.h"
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_004A6DF8(void *, s32);
__asm__(".extern D_L24_001DD558_00353F00, 4");
__asm__(".extern D_L24_001DD55C_00353F00, 4");
__asm__(".extern D_L24_001DD560_00353F00, 4");
__asm__(".extern D_L24_001DD564_00353F00, 4");
extern f32 D_L24_001DD558_00353F00;
extern f32 D_L24_001DD55C_00353F00;
extern f32 D_L24_001DD560_00353F00;
extern f32 D_L24_001DD564_00353F00;

typedef struct S_00354F38 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x3];
    u8 b39;
    u8 pad3A[0x4];
    u8 b3E;
    u8 pad3F[0x1];
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x15];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    f32 f9C;
    f32 fA0;
    u8 padA4[0x8];
    s32 wAC;
    u8 padB0[0xAC];
    f32 f15C;
    u8 pad160[0x10];
    u8 b170;
    u8 b171;
    u8 b172;
    u8 pad173[0x3];
    u8 b176;
    u8 pad177[0x5];
    f32 f17C;
    f32 f180;
    f32 f184;
    f32 f188;
    f32 f18C;
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    f32 f1A0;
    u8 pad1A4[0x4];
    u8 b1A8;
    u8 b1A9;
    u8 pad1AA[0x22];
    u8 b1CC;
    u8 b1CD;
    u8 pad1CE[0x4];
    u8 b1D2;
    u8 b1D3;
    u8 pad1D4[0x3];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    s32 w1DC;
    u8 pad1E0[0x28];
    f32 f208;
    u8 pad20C[0xD0];
    s32 w2DC;
    u8 pad2E0[0x4];
    s32 w2E4;
    u8 pad2E8[0x4];
    s32 w2EC;
    u8 pad2F0[0x4];
    s32 w2F4;
    u8 pad2F8[0x18];
    vu0_q q310;
    u8 pad320[0x18];
    s32 w338;
    u8 pad33C[0x14];
    s32 w350;
} S_00354F38;

s32 func_L24_00353F00(void *o) {
    u8 *obj = o;
    S_00354F38 *s = *(S_00354F38 **)(obj + 0x68);

    s->b1A8 = 3;
    s->b170 = 0x16;
    s->b176 = 0xE;
    s->b1D3 = 0x10;
    s->b1D2 = 0xB;
    s->b1DA = 3;
    s->b171 = 0xC;
    s->b172 = 0xC;
    s->b1CC = 0;
    s->b1CD = 0;
    s->b1D8 = 3;
    s->b1D9 = 3;
    s->f190 = 0.8f;
    s->f194 = 1.2f;
    s->f19C = 0.15f;
    s->b1D7 = 1;
    s->b1DB = 0xFF;
    s->f17C = 0.33333334f;
    s->f184 = 0.0069444445f;
    s->f180 = 0.016666668f;
    s->f188 = 0.009722223f;
    s->f18C = 0.0013888889f;
    s->f1A0 = 5.0f;
    s->f208 = 0.5f;
    if (s->w2E4 == 0) {
        s->b1A9 = 1;
    }
    if (s->w350 != -1) {
        s->w1DC = s->w350;
    }
    if (s->w2E4 == 0) {
        *(f32 *)(obj + 0x18) = func_003BE7F0(obj + 0x10, 0, obj, 0.5f);
    }
    s->q310 = *(vu0_q *)(obj + 0x10);
    if (s->w350 != -1) {
        s->wAC = s->w350;
    }
    s->f15C = 0.8f;
    s->f78 = 1.2f;
    s->f70 = 1.1f;
    s->f74 = 0.4f;
    s->f7C = 1.5f;
    s->f80 = 1.5707964f;
    s->fA0 = 0.2443461f;
    s->f9C = 0.083333336f;
    func_L01_00458A70(obj, D_L24_001DD55C_00353F00 * 0.00027777778f, D_L24_001DD558_00353F00 * 0.016666668f, D_L24_001DD564_00353F00 * 0.017453292f * 0.00027777778f, D_L24_001DD560_00353F00 * 0.017453292f * 0.016666668f);
    s->b58 = 0x14;
    s->b5A = 0xE;
    if (s->h34 == 0) {
        s->h34 = 10;
        s->f30 = 10.0f;
    }
    s->f40 = 1.2f;
    s->b39 = 1;
    s->b3E = 1;
    s->w2DC = 0;
    func_L01_00441FB8(obj, 1, 0);
    if (obj[0x43] != 0) {
        func_003BE4F0(obj, 0, 0, 0);
    }
    if (s->w2F4 != -1) {
        if (obj[0x43] != 4) {
            func_003BE4F0(obj, 4, 0, 0);
        }
        func_L01_00441FB8(obj, 2, -1);
    } else if (s->w2E4 == 0 && s->w338 == 0) {
        if (obj[0x43] != 4) {
            func_003BE4F0(obj, 4, func_0037E1D8(3), func_0037E1D8(6));
        }
        func_L01_00441FB8(obj, 6, -1);
    }
    if (s->w2E4 != 0) {
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004A6DF8(obj, 1);
        if (s->w2E4 != 0 && s->w2EC != -1) {
            func_L01_00441FB8(obj, 7, 5);
        }
    }
    return 0;
}
/* localdecomp:end func_L24_00353F00 */
