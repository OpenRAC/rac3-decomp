/* NTSC-U draft (Claude wave C2): C of func_L12_003D6AE8, the NTSC-U twin of func_L12_003D88C8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L12_003D6AE8", whose code is not the PAL one).
 * Worker's note: 9 aligned words (arg-move/delay-slot order only): call 1 (func_L07_003D6D60) arg order a1 vs f15, and the 18-arg func_L01_0044ED60 call ends with mov.s f15,f13 in the delay slot instead of retail's addiu a3,0xFF; no divs row needed (div.s without nops); ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L12_003D88C8 (src/levels/shared/L12_003D7BE8.c) */
/* localdecomp:start func_L12_003D6AE8 */
extern s32 D_001DF11C_sda;
__asm__(".extern D_001DF11C_sda, 4");
extern f32 D_001DF120_sda;
__asm__(".extern D_001DF120_sda, 4");
extern u8 D_L12_001E2800[];
extern u8 D_L12_001D6700[8];
__asm__(".extern D_L12_001D6700, 16");
extern void func_L07_003D6D60(void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_004412D0(void *, s32, s32);

void func_L12_003D6AE8(u8 *a0) {
    f32 f;
    s32 i;
    u8 *p;

    f = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    for (i = 0; i < D_001DF11C_sda; i++) {
        func_L07_003D6D60(a0, 5, 0x32, 0.0f, D_001DF120_sda, 1.5f, f, 4);
    }
    p = D_L12_001E2800;
    *(s32 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x28) = 0x2D;
    *(f32 *)(p + 0x20) = 1.5f;
    func_0039FE80(1, 0, a0);
    func_L01_0044ED60(a0, 0x1FF, D_L12_001D6700, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 7.0f, 3.0f, 7.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_L01_004412D0(a0, 0, 3);
}
/* localdecomp:end func_L12_003D6AE8 */
