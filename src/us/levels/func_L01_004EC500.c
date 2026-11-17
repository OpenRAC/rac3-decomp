#include "common.h"

/* NTSC-U counterpart of func_L01_004F02D8 (src/levels/shared/L01_004EF3A8.c) */
#include "vu0.h"

/* localdecomp:start func_L01_004EC500 */
#include "vu0.h"
extern u8 D_001A4BE0_004F0558[];
typedef struct { u8 pad[0x364]; s32 value; } Clear_004F02D8;
extern f32 D_001A4C68[];
void func_L01_004EC500(void) {
    extern f32 func_L01_0050D4D8(void *);
    extern f32 func_00388800(void *, void *);
    extern void func_L01_00445208_004EC500(void *, void *, void *, f32, f32, f32);
    extern void func_L01_00445168(void *, f32, void *, f32, f32, f32);
    u8 *h = D_001A4BE0_004F0558;
    if (h[0x25F4]) {
        if (*(s16 *)(D_001A4BE0_004F0558 + 0x36E) != 0) goto clear;
        if (*(f32 *)(h + 0x33C) < 0.0f) {
            if (fabs_asm(*(f32 *)(h + 0x33C)) < fabs_asm(func_L01_0050D4D8(h + 0xF0)) + 0.01f) {
                if (!h[0x2A7] || func_00388800(h + 0x260, h + 0x80) > *(f32 *)(h + 0x284) * 0.5f) {
                    *(vu0_q *)(h + 0x80) = *(vu0_q *)(h + 0x2F0);
                } else {
                    func_L01_00445208_004EC500(h + 0x80, h + 0x2F0, &((Clear_004F02D8 *)h)->value, 0.05f, 0.21f, 0.083333336f);
                }
            } else {
                func_L01_00445208_004EC500(h + 0x80, h + 0x2F0, &((Clear_004F02D8 *)h)->value, 0.05f, 0.21f, 0.083333336f);
            }
        } else {
            goto clear;
        }
    } else {
        if (*(s16 *)(D_001A4BE0_004F0558 + 0x36E) != 0) goto clear;
        if (*(f32 *)(h + 0x88) < *(f32 *)(h + 0x338)) {
            if (fabs_asm(*(f32 *)(h + 0x88) - *(f32 *)(h + 0x338)) < fabs_asm(*(f32 *)(h + 0xF8)) + 0.01f) {
                if (!h[0x2A7] || func_00388800(h + 0x260, h + 0x80) > *(f32 *)(h + 0x284) * 0.5f) {
                    *(f32 *)(h + 0x88) = *(f32 *)(h + 0x338);
                } else {
                    func_L01_00445168(h + 0x88, *(f32 *)(D_001A4BE0_004F0558 + 0x338), &((Clear_004F02D8 *)h)->value, 0.05f, 0.17f, 0.083333336f);
                }
            } else {
                if (*(f32 *)(h + 0x128) < 0.0f) {
                    *(f32 *)(h + 0x88) -= *(f32 *)(h + 0x128);
                    if (*(f32 *)(h + 0x88) > *(f32 *)(h + 0x338)) *(f32 *)(h + 0x88) = *(f32 *)(h + 0x338);
                }
                func_L01_00445168(D_001A4C68, *(f32 *)((u8 *)D_001A4C68 + 0x2B0), (u8 *)D_001A4C68 + 0x2DC, 0.05f, 0.17f, 0.083333336f);
            }
        } else {
            goto clear;
        }
    }
    return;
clear:
    ((Clear_004F02D8 *)D_001A4BE0_004F0558)->value = 0;
}
/* localdecomp:end func_L01_004EC500 */
