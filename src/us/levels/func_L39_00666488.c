#include "common.h"

/* NTSC-U counterpart of func_L39_00668D60 (src/levels/shared/L39_00668D60.c): 0.1 -> 0.0833333 */
/* localdecomp:start func_L39_00666488 */
typedef struct Vt_00668D60 { u8 pad0[0x34]; void (*f34)(void *, s32, s32, s32, s32); } Vt_00668D60;
typedef struct Sub_00668D60 { u8 pad0[0x98]; s32 w98; } Sub_00668D60;
typedef struct Ply_00668D60 {
    u8 pad0[0x14];
    Vt_00668D60 *vt;
    u8 pad18[0x1A0A - 0x18];
    u8 b1A0A;
    u8 pad1A0B[0x1A14 - 0x1A0B];
    u8 b1A14;
    u8 pad1A15[0x2524 - 0x1A15];
    Sub_00668D60 *p2524;
    u8 pad2528[0x2534 - 0x2528];
    s32 w2534;
} Ply_00668D60;
typedef struct Obj_00668D60 {
    u8 pad0[0x10];
    u8 pos10[0x24];
    u16 h34;
    u8 pad36[0x96 - 0x36];
    s16 h96;
    s32 w98;
    u8 pad9C[0xA8 - 0x9C];
    u8 bA8;
    u8 padA9;
    s16 hAA;
    u8 padAC[0xBC - 0xAC];
    u8 bBC;
} Obj_00668D60;
typedef struct Tgt_00668D60 {
    u8 pad0[0x20];
    Obj_00668D60 *o20;
    u8 pad24[5];
    u8 b29;
} Tgt_00668D60;
typedef struct Slf_00668D60 {
    u8 pad0[0x270];
    u8 pos270[0x60];
    Obj_00668D60 *o2D0;
    u8 pad2D4[4];
    Ply_00668D60 *p2D8;
    Ply_00668D60 *p2DC;
    u8 pad2E0[8];
    s32 w2E8;
    u8 pad2EC[0x2F8 - 0x2EC];
    s32 w2F8;
    u8 pad2FC[0x308 - 0x2FC];
    f32 f308;
    u8 pad30C[0x328 - 0x30C];
    s32 w328;
} Slf_00668D60;

extern Tgt_00668D60 *func_L01_00444358(void *, s32, s32);
extern f32 func_L01_004443B0(void *, void *);
extern s32 func_L39_006241C0(void *, void *, s32);
extern s32 func_00132100(f32);
extern void func_L39_00664930(void *, u32, s32, s32);
extern s32 func_L39_006197F0(void *);
extern void func_L01_003EFFE0(s32, s32);
extern s32 func_L39_005F0D88(s32, s32, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F090(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
extern u8 D_001A5FB8[];
extern s32 D_001A5FBC[];
extern s32 D_001A5F78[];
extern f32 D_001DAAEC_sda_00666488;
extern f32 D_001DAAF0_sda_00666488;
__asm__(".extern D_001DAAEC_sda_00666488, 4");
__asm__(".extern D_001DAAF0_sda_00666488, 4");

void func_L39_00666488(Slf_00668D60 *s) {
    Tgt_00668D60 *t;
    f32 f;
    f32 g;
    f32 vec[4];
    Ply_00668D60 *x;
    s32 r;

    t = func_L01_00444358(s->o2D0, -1, 0);
    if (t != 0 && t->o20 != 0) {
        if ((s->p2D8 != 0 && func_L39_006241C0(s->p2D8, t->o20, 0) == 0) ||
            (s->p2DC != 0 && func_L39_006241C0(s->p2DC, t->o20, 0) == 0)) {
            s->o2D0->bA8 = 0xFF;
            return;
        }
    }
    f = func_L01_004443B0(s->o2D0, t);
    if (f != 0.0f) {
        if ((s->p2D8 == 0 && s->p2DC == 0 && D_001A5FB8[0] != 0) || (s->p2D8 != 0 && s->p2D8->b1A14 != 0) ||
            (s->p2DC != 0 && s->p2DC->b1A14 != 0)) {
            if (t->b29 >= 3 && (t->o20 == 0 || t->o20->hAA != 0x15A5)) {
                f *= 2.2f;
            }
            g = s->f308 - f;
            if (s->p2D8 != 0) {
                func_L39_006241C0(s->p2D8, t->o20, 0);
            }
            if (s->p2DC != 0) {
                func_L39_006241C0(s->p2DC, t->o20, 0);
            }
            func_L39_00664930(s, func_00132100(g), 0xF, -1);
        }
    }
    if (s->f308 < 0.0f) {
        s->f308 = 0.0f;
    }
    if (s->f308 <= 0.0f) {
        func_L39_00664930(s, 0xFFFFFFFF, 6, D_001A5FBC[0]);
    }
    s->o2D0->bA8 = 0xFF;
    if ((s->o2D0->bBC == 9 && D_001A5F78[0] >= s->w2E8) || (s->o2D0->bBC == 0xB && s->w2E8 <= 0)) {
        s->o2D0->w98 = 0;
        s->o2D0->h34 |= 0x41;
        if (s->p2D8 != 0) {
            r = func_L39_006197F0(s->p2D8);
            if (r >= 0) {
                s->w328 = r + 1;
            }
            if (s->w2F8 & 0x4000000) {
                s->p2D8->vt->f34(s->p2D8, 0x39, 1, 0, 1);
            } else {
                s->p2D8->p2524->w98 = 0;
                s->p2D8->b1A0A = 1;
            }
            if (s->p2D8->b1A14 != 0) {
                func_L01_003EFFE0(0x1C, s->p2D8->w2534);
            }
        }
        if (s->p2DC != 0) {
            r = func_L39_006197F0(s->p2DC);
            if (r >= 0) {
                s->w328 = r + 1;
            }
            if (s->w2F8 & 0x4000000) {
                s->p2DC->vt->f34(s->p2DC, 0x39, 1, 0, 1);
            } else {
                s->p2DC->p2524->w98 = 0;
                s->p2DC->b1A0A = 1;
            }
            if (s->p2DC->b1A14 != 0) {
                func_L01_003EFFE0(0x1C, s->p2DC->w2534);
            }
        }
        if (s->o2D0->hAA == 0x10C2) {
            func_L39_005F0D88(0, 0, s->o2D0, 0x10C2);
        }
        func_00388830(vec, s->pos270, 0.0833333358f);
        if (s->o2D0->bBC != 0xB) {
            func_L01_0032FE90(s->o2D0->pos10, 1, 25, 20, 20, 20, 45, 2, 1.5f, 10.0f, D_001DAAEC_sda_00666488, D_001DAAF0_sda_00666488,
                              0, 0, 0, 0, 1, 0, 0x1010001, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_0044F090(s->o2D0, 0x3FF, vec, 1, 35, -1.0f, 3.0f, 6.0f, 5.0f, 15.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
        } else {
            func_L01_0044ED60(s->o2D0, 0x3FF, vec, 0xFF, 1.0f, 1.5f, 0.5f, 0.75f, 1.0f, 0xB4, 0, 0, 0x23, -1.0f, 1.0f, 1.0f, 0, 3);
        }
        s->o2D0->bBC = 0xA;
        s->o2D0->h96 = 0;
    }
}
/* localdecomp:end func_L39_00666488 */
