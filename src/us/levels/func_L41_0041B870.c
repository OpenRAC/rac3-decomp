#include "common.h"

/* NTSC-U counterpart of func_L41_0041C170 (src/levels/shared/L41_0041B308.c) */
/* localdecomp:start func_L41_0041B870 */
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x120];
    s32 w128;
    u8 pad12C[0x44];
    s32 w170;
    u8 pad174[0x660];
    u8 b7D4;
} S_0041B870;

extern S_0041B870 D_001A5E50;
extern u8 *D_L41_002487DC;
__asm__(".extern D_L41_002487DC, 16");
extern s32 D_L41_00240754;
__asm__(".extern D_L41_00240754, 16");
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L41_0041B870(u8 *a0, s32 a1) {
    s32 buf[2];
    s32 *p;

    p = *(s32 **)(a0 + 0x68);
    *p = D_001A5E50.w128 + a1;
    buf[0] = ((a0 - D_L41_002487DC) >> 8) & 0xFF;
    buf[1] = *p;
    if (D_001A5E50.w170 == 0) {
        func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.w4, -1, D_L41_00240754, 8, buf);
    }
}
/* localdecomp:end func_L41_0041B870 */
