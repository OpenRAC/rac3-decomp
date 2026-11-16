#include "common.h"

/* NTSC-U counterpart of func_L20_003F3FF8 (src/levels/20_final_boss/L20_003F3FF8.c) */
/* localdecomp:start func_L20_003F1EC0 */
#include "vu0.h"

typedef int q_003F3FF8 __attribute__((mode(TI)));

extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003D3FA0(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_0037E2A8(void);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004084B0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);
extern f32 D_L20_001E2E00_003F1EC0[];
__asm__(".extern D_L20_001E2E00_003F1EC0, 16");
__asm__(".extern D_L20_001DF450_003F1EC0, 4");
__asm__(".extern D_L20_001DF454_003F1EC0, 4");
__asm__(".extern D_L20_001DF458_003F1EC0, 4");
__asm__(".extern D_L20_001DF45C_003F1EC0, 4");
__asm__(".extern D_L20_001DF460_003F1EC0, 4");
__asm__(".extern D_L20_001DF464_003F1EC0, 4");
__asm__(".extern D_L20_001DF468_003F1EC0, 4");
__asm__(".extern D_L20_001DF46C_003F1EC0, 4");
extern s32 D_L20_001DF450_003F1EC0;
extern s32 D_L20_001DF454_003F1EC0;
extern f32 D_L20_001DF458_003F1EC0;
extern f32 D_L20_001DF45C_003F1EC0;
extern f32 D_L20_001DF460_003F1EC0;
extern f32 D_L20_001DF464_003F1EC0;
extern u32 D_L20_001DF468_003F1EC0;
extern u32 D_L20_001DF46C_003F1EC0;

typedef struct {
    u8 p0[0x20];
    f32 x20;
    f32 x24;
    u8 p28[0x4C - 0x28];
    f32 x4C;
    u8 p50[0xC70 - 0x50];
    f32 xC70[12][4];
    f32 xD30[12];
    f32 xD60;
} S_003F3FF8;

void func_L20_003F1EC0(u8 *obj) {
    S_003F3FF8 *s = *(S_003F3FF8 **)(obj + 0x68);
    f32 d[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    u32 col;
    s32 i;

    col = func_003894A0(D_L20_001DF450_003F1EC0, D_L20_001DF454_003F1EC0, func_00388978(D_L20_001DF458_003F1EC0) * 0.5f + 0.5f);
    D_L20_001DF458_003F1EC0 = func_00389380(D_L20_001DF458_003F1EC0, func_0037E250(D_L20_001DF45C_003F1EC0, D_L20_001DF460_003F1EC0) * 0.017453292f * 0.016666668f);
    func_003D3FA0(obj + 0x10, 0x43, col, 1, 2.25f, -0.1f, s->x20);
    func_003D3FA0(obj + 0x10, 0x4B, 0x7FFFFFFF, 3, 2.0f, 0.025f, -s->x20);
    func_003D3FA0(obj + 0x10, 0x31, 0x7FFFFFFF, 3, 4.0f, 0.0f, -s->x24);
    func_003D3FA0(obj + 0x10, 0x31, 0x4FFFFFFF, 1, 4.0f, 0.08f, s->x24);
    func_003D3FA0(obj + 0x10, 0x31, 0x7FFFFFFF, 3, 4.0f, 0.0f, func_0037E2A8());
    func_003D3FA0(obj + 0x10, 0x31, 0x4FFFFFFF, 1, 4.0f, 0.0f, func_0037E2A8());
    for (i = 0; i < 12; i++) {
        vec_sub_ab(d, D_L20_001E2E00_003F1EC0, obj + 0x10);
        func_00389158(s->xC70[i], s->xC70[i], d, s->xD30[i]);
        s->x4C = s->x4C + 0.03f;
        if (2.5f < s->x4C) {
            s->x4C = 2.5f;
        }
        func_00388830(s->xC70[i], s->xC70[i], s->x4C);
        vec_add_ab(a, s->xC70[i], obj + 0x10);
        *(q_003F3FF8 *)b = *(q_003F3FF8 *)(obj + 0x10);
        func_L01_004084B0(a, b, 0x12, 1, D_L20_001DF464_003F1EC0, 3.0f, s->xD60, D_L20_001DF468_003F1EC0, D_L20_001DF468_003F1EC0, D_L20_001DF46C_003F1EC0, D_L20_001DF46C_003F1EC0);
    }
    s->xD60 = s->xD60 - func_0037E250(0.025f, 0.035f);
    if (s->xD60 <= -8.0f) {
        s->xD60 = s->xD60 + 8.0f;
    }
}
/* localdecomp:end func_L20_003F1EC0 */
