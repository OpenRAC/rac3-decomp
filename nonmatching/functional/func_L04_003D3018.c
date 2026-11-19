/* functional: high. Plain init; typedef line is from the source file's context (func_L04_003D1128). float*float tuning tables D_L04_002F1F70/002F1D90 indexed by the game id (D_001D545C); game 7 with D_0014275B set uses gp floats instead. 128 diffs. */
#include "common.h"
typedef void (*Fn_003CF2A0)(u8 *); /* also in the file context; drop this line when merging */
extern s32 func_L01_0041A4F0(void);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_001A30F4;
__asm__(".extern D_001A30F4, 4");
extern u8 D_0014275B[];
__asm__(".extern D_0014275B, 16");
extern f32 D_L04_002F1F70[];
__asm__(".extern D_L04_002F1F70, 16");
extern f32 D_L04_002F1D90[];
__asm__(".extern D_L04_002F1D90, 16");
extern f32 D_L04_001DA8B8;
__asm__(".extern D_L04_001DA8B8, 4");
extern f32 D_L04_001DA8B0;
__asm__(".extern D_L04_001DA8B0, 4");
extern s32 D_001D545C;

void func_L04_003D3018(u8 *a0, u8 *pv) {
    f32 f0;
    s32 v, g;
    Fn_003CF2A0 *c;

    a0[0xBC] = 0;
    *(s32 *)(pv + 0xC8) = -1;
    *(f32 *)(pv + 0xB8) = *(f32 *)(a0 + 0x18);
    *(f32 *)(pv + 0x8C) = 1.0f;
    *(s32 *)(pv + 0xA0) = 0;
    *(s32 *)(pv + 0x94) = 0;
    *(s32 *)(pv + 0x98) = 0;
    *(s32 *)(pv + 0xA4) = 0;
    *(s32 *)(pv + 0xA8) = 0;
    *(s32 *)(pv + 0x88) = 0;
    *(s32 *)(pv + 0xD4) = 0;
    D_001A30F4 = a0;
    *(f32 *)(pv + 0x9C) = func_00382538();
    if (*(s16 *)(pv + 0x34) == 0) {
        *(s16 *)(pv + 0x34) = 0x32;
        if (func_L01_0041A4F0() != 0) {
            g = D_001D545C;
            if (g == 7 && D_0014275B[0] != 0) {
                f0 = D_L04_001DA8B8;
            } else {
                f0 = D_L04_002F1F70[g];
            }
            *(s16 *)(pv + 0x34) = (s32)((f32)*(s16 *)(pv + 0x34) * f0);
        }
    }
    *(f32 *)(pv + 0x30) = (f32)*(s16 *)(pv + 0x34);
    if (pv[0x44] == 0) {
        pv[0x44] = 9;
        if (func_L01_0041A4F0() != 0) {
            g = D_001D545C;
            if (g == 7 && D_0014275B[0] != 0) {
                f0 = D_L04_001DA8B0;
            } else {
                f0 = D_L04_002F1D90[g];
            }
            v = (s32)((f32)pv[0x44] * f0);
            if (v >= 0x100) v = 0xFF;
            pv[0x44] = v;
        }
    }
    *(s32 *)(pv + 0x84) = 0;
    *(s32 *)(pv + 0x90) = 0;
    func_L01_004450F0(a0, 1, -1);
    func_L01_00456230(a0, 0);
    if (*(s32 *)(pv + 0x70) > 0) {
        c = func_L01_0043B548(0x19E1, 0x6C);
        pv[0x7E] = 4;
        *(s32 *)(pv + 0x70) = -1;
        (*c)(a0);
        return;
    }
    if (pv[0x80] != 0) {
        func_L01_004450F0(a0, 5, -1);
        return;
    }
    if (*(s32 *)(pv + 0xD0) != -1) {
        func_L01_004450F0(a0, 3, -1);
    }
}
