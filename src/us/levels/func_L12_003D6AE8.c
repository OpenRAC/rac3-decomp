#include "common.h"

/* NTSC-U counterpart of func_L12_003D88C8 (src/levels/shared/L12_003D8808.c): field 0x28 set to 45, not 37; NTSC-U data addresses */
/* localdecomp:start func_L12_003D6AE8 */
typedef struct { u8 pad[0x60]; u8 x60; } V_003D6AE8;
typedef struct { u8 pad[0x68]; V_003D6AE8 *x68; } M_003D6AE8;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_003D6AE8 *x18C; } B_003D6AE8;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_003D6AE8;

extern s32 D_L12_001DF11C;
__asm__(".extern D_L12_001DF11C, 4");
extern f32 D_L12_001DF120;
__asm__(".extern D_L12_001DF120, 4");
extern u8 D_L12_001E2800[];
extern u8 D_L12_001D6700[8];
__asm__(".extern D_L12_001D6700, 16");
extern void func_L07_003D6D60(void *, f32, f32, f32, f32, s32, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004412D0(void *, s32, s32);

void func_L12_003D6AE8(O_003D6AE8 *a0, B_003D6AE8 *a1) {
    f32 f;
    s32 i;
    u8 *p;

    f = *(f32 *)((u8 *)a0 + 0x2C) / *(f32 *)(*(u8 **)((u8 *)a0 + 0x24) + 0x24);
    for (i = 0; i < D_L12_001DF11C; i++) {
        func_L07_003D6D60(a0, 0.0f, D_L12_001DF120, 1.5f, f, 5, 0x32, 4);
    }
    p = D_L12_001E2800;
    *(s32 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x28) = 0x2D;
    *(f32 *)(p + 0x20) = 1.5f;
    func_0039FE80(1, 0, a0);
    func_L01_0044ED60(a0, 0x1FF, D_L12_001D6700, 3.0f, 7.0f, 3.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    func_L01_004412D0(a0, 0, 3);
}
/* localdecomp:end func_L12_003D6AE8 */
