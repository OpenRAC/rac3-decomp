/*
 * PAL near miss, P02 wave 1, 2026-11-16.
 * Owning file: src/levels/20_final_boss/L20_003D6F30.c.
 * Exact file flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *                  -mno-check-zero-division @ps2as.
 * Stock check.py: 4 differences on attempts 3, 4 and 6.
 * The final drawing call swaps each zero-coordinate argument move with the
 * adjacent dimension halfword load. All other instructions compare equal.
 * Stopped after return-type and explicit-dimension-local formulations left
 * identical residual bytes. Six compiles total; attempt 5 was worse.
 * Separate final texture storage fixes the original saved-register rotation.
 * Uses the owning file's earlier types, prototypes and extern declarations
 * through check.py's normal context. No flag or metadata changes were tested.
 */
#include "common.h"
extern void func_L01_004C5E28(void *, s32, f32, f32, f32, f32);
extern void func_003D1030(void);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern s32 D_001D5520;
typedef struct { u8 pad[8]; s32 f8; } S_1A1ED0_7220;
extern S_1A1ED0_7220 D_001A1ED0;
extern s32 D_L20_001DEC10;
extern s32 D_L20_001DEC14;
extern s32 D_L20_001DEC18;
extern s32 D_L20_001DEC1C;
extern s32 D_L20_001DEC20;
extern s32 D_L20_001DEC24;
extern s32 D_L20_001DEC28;
extern s32 D_L20_001DEC2C;
extern s32 D_L20_001DEC30;
extern s32 D_L20_001DEC34;
extern s32 D_L20_001DEC38;
extern s32 D_L20_001DEC3C;
extern s32 D_L20_001DEC40;
extern s32 D_L20_001DEC44;
extern s32 D_L20_001DEC48;
__asm__(".extern D_L20_001DEC10, 4");
__asm__(".extern D_L20_001DEC14, 4");
__asm__(".extern D_L20_001DEC18, 4");
__asm__(".extern D_L20_001DEC1C, 4");
__asm__(".extern D_L20_001DEC20, 4");
__asm__(".extern D_L20_001DEC24, 4");
__asm__(".extern D_L20_001DEC28, 4");
__asm__(".extern D_L20_001DEC2C, 4");
__asm__(".extern D_L20_001DEC30, 4");
__asm__(".extern D_L20_001DEC34, 4");
__asm__(".extern D_L20_001DEC38, 4");
__asm__(".extern D_L20_001DEC3C, 4");
__asm__(".extern D_L20_001DEC40, 4");
__asm__(".extern D_L20_001DEC44, 4");
__asm__(".extern D_L20_001DEC48, 4");

void func_L20_003D7220(void *p, s32 kind, s32 alpha, f32 r, f32 g, f32 b, f32 a) {
    long texture;
    long texture2;
    s32 color;
    func_L01_004C5E28(p, kind, r, g, b, a);
    if (D_001D5520 != 0) {
        D_L20_001DEC48 = -1;
        D_L20_001DEC40 = 0xEC;
        D_L20_001DEC44 = 0xF0;
    }
    func_003A9440(0x4E, (D_001A1ED0.f8 >> 13) | 0x1000000 | 0x100000000L);
    func_003A9440(0x42, D_L20_001DEC18 | ((long)D_L20_001DEC1C << 2) |
        ((long)D_L20_001DEC20 << 4) | ((long)D_L20_001DEC24 << 6) | 0x8000000000L);
    func_003D1030();
    texture = func_00389598(D_L20_001DEC10);
    color = (alpha << 24) | 0x7F7F7F;
    func_0038B4D0(0, 0, (s32)(D_001CFEC0_003D6F30->h150 * 0.5f),
        (s32)(D_001CFEC0_003D6F30->h152 * 0.5f), 0, 0, 255, 255, color, texture);
    func_0038B4D0(D_001CFEC0_003D6F30->h150, 0, -(s32)(D_001CFEC0_003D6F30->h150 * 0.5f),
        (s32)(D_001CFEC0_003D6F30->h152 * 0.5f), 0, 0, 255, 255, color, texture);
    func_0038B4D0(0, D_001CFEC0_003D6F30->h152, (s32)(D_001CFEC0_003D6F30->h150 * 0.5f),
        -(s32)(D_001CFEC0_003D6F30->h152 * 0.5f), 0, 0, 255, 255, color, texture);
    func_0038B4D0(D_001CFEC0_003D6F30->h150, D_001CFEC0_003D6F30->h152, -(s32)(D_001CFEC0_003D6F30->h150 * 0.5f),
        -(s32)(D_001CFEC0_003D6F30->h152 * 0.5f), 0, 0, 255, 255, color, texture);
    func_003A9440(0x42, D_L20_001DEC18 | ((long)D_L20_001DEC1C << 2) |
        ((long)D_L20_001DEC20 << 4) | ((long)D_L20_001DEC24 << 6) | 0x8000000000L);
    func_003A9440(0x42, D_L20_001DEC28 | ((long)D_L20_001DEC2C << 2) |
        ((long)D_L20_001DEC30 << 4) | ((long)D_L20_001DEC34 << 6) | 0x8000000000L);
    texture2 = func_00389598(D_L20_001DEC48);
    {
        s32 width = D_001CFEC0_003D6F30->h150;
        s32 height = D_001CFEC0_003D6F30->h152;
        func_0038B4D0(0, 0, width, height, D_L20_001DEC38, D_L20_001DEC3C,
            D_L20_001DEC40, D_L20_001DEC44, D_L20_001DEC14, texture2);
    }
    func_003A9440(0x4E, 0x1000000 | (D_001A1ED0.f8 >> 13));
}
