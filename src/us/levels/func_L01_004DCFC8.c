#include "common.h"

/* NTSC-U counterpart of func_L01_004E0CD8 (src/levels/shared/L01_004DF428.c) */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
extern G_4DD4B0 D_001A4BE0;
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_004DF4A0(void);

/* localdecomp:start func_L01_004DCFC8 */
typedef struct {
    u8 pad0[0x80]; u128_t pos; u128_t rot;
    u8 padA0[0x1A24-0xA0]; u8 *effect; f32 phase;
    u8 pad1A2C[0x22C0-0x1A2C]; u128_t joint;
    u8 pad22D0[0x25C0-0x22D0]; u8 *moby;
    u8 pad25C4[0x28A8-0x25C4]; s16 timer; s16 type; s32 color;
} Hero_004E0CD8;
typedef struct { unsigned char active:1; } Flag_004E0CD8;
extern G_4DD4B0 D_001A4BE0;
extern u8 D_001D5470;
void func_L01_004DCFC8(void) {
    extern u8 *func_003BCFB0(s32, s32);
    extern void func_003C26C8(void *);
    extern void func_003BDA38(u8 *, s32, void *);
    extern void func_003BD9A0(u8 *, s32, void *);
    extern void func_00388E58(void *, void *);
    extern void func_L01_004DF4A0(void);
    extern f32 func_003BEBF8(f32 *, f32, f32);
    extern f32 func_00389380(f32, f32);
    extern s32 func_003883C8(void *);
    extern void func_0039FE80(s32, s32, u8 *);
    extern f32 func_00388978(f32);
    extern s32 func_003894A0(s32, s32, f32);
    struct { u128_t joint; u128_t matrix[4]; } work;
    s32 color0, color1, color;
    f32 scale;
    if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect == 0) {
        (*(Hero_004E0CD8 *)&D_001A4BE0).effect = func_003BCFB0(0x4B4, 0x80);
        if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect) {
            *(s32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x78) = 0x801432D7;
            (*(Hero_004E0CD8 *)&D_001A4BE0).color = 0x301432D7;
            *(u128_t *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x10) = (*(Hero_004E0CD8 *)&D_001A4BE0).pos;
            *(u128_t *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0xF0) = (*(Hero_004E0CD8 *)&D_001A4BE0).rot;
            *(s16 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x32) = 64;
            (*(Hero_004E0CD8 *)&D_001A4BE0).effect[0x31] = 1;
            (*(Hero_004E0CD8 *)&D_001A4BE0).effect[0x30] = 0;
            *(s16 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x34) = 0;
            *(f32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x2C) *= 1.7f;
            *(u16 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x34) |= 0x10;
            func_003C26C8((*(Hero_004E0CD8 *)&D_001A4BE0).effect);
        }
    }
    if (((*(Hero_004E0CD8 *)&D_001A4BE0).moby[0x34] ^ 1) & 1) {
        func_003BDA38((*(Hero_004E0CD8 *)&D_001A4BE0).moby, 7, &work.joint);
        (*(Hero_004E0CD8 *)&D_001A4BE0).joint = work.joint;
        func_L01_004DF4A0();
        if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect) {
            u128_t *mat = work.matrix;
            func_003BD9A0((*(Hero_004E0CD8 *)&D_001A4BE0).moby, 7, mat);
            *(u128_t *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x10) = work.matrix[3];
            func_00388E58((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0xC0, mat);
            func_003C26C8((*(Hero_004E0CD8 *)&D_001A4BE0).effect);
            scale = 1.7f;
            if (D_001D5470) scale = 3.1f;
            if ((*(Hero_004E0CD8 *)&D_001A4BE0).timer) scale *= 1.4f;
            func_003BEBF8((f32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x2C), *(f32 *)(*(u8 **)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x24) + 0x24) * scale, 0.02f);
        }
    }
    (*(Hero_004E0CD8 *)&D_001A4BE0).phase = func_00389380((*(Hero_004E0CD8 *)&D_001A4BE0).phase, 0.04945099726319313f);
    color0 = 0x281414C8;
    color1 = 0x1E00004B;
    if (!func_003883C8(&(*(Hero_004E0CD8 *)&D_001A4BE0).timer)) {
        (*(Hero_004E0CD8 *)&D_001A4BE0).phase = func_00389380((*(Hero_004E0CD8 *)&D_001A4BE0).phase, 0.2036217451095581f);
        switch ((*(Hero_004E0CD8 *)&D_001A4BE0).type) {
            case 1: color0 = 0x2814C814; color1 = 0x1E004B00; break;
            case 2: color0 = 0x2814C8C8; color1 = 0x1E004B4B; break;
            case 3: color0 = 0x323232FA; color1 = 0x1E000078; break;
            case 4: color0 = 0x28F01414; color1 = 0x1E4B0000; break;
        }
        if ((*(Hero_004E0CD8 *)&D_001A4BE0).timer >= 50 && ((*(Hero_004E0CD8 *)&D_001A4BE0).timer & 1)) {
            func_0039FE80((*(Hero_004E0CD8 *)&D_001A4BE0).type + 16, 0, (*(Hero_004E0CD8 *)&D_001A4BE0).moby);
        }
    }
    color = func_003894A0(color0, color1, func_00388978((*(Hero_004E0CD8 *)&D_001A4BE0).phase) * 0.5f + 0.5f);
    if ((*(Hero_004E0CD8 *)&D_001A4BE0).effect) {
        *(s32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x78) = func_003894A0(*(s32 *)((*(Hero_004E0CD8 *)&D_001A4BE0).effect + 0x78), color, 0.1f);
    }
    (*(Hero_004E0CD8 *)&D_001A4BE0).color = func_003894A0((*(Hero_004E0CD8 *)&D_001A4BE0).color, color, 0.1f);
}
/* localdecomp:end func_L01_004DCFC8 */
