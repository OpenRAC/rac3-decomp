#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005872D8);

/* localdecomp:start func_L39_00587A30 */
typedef struct { s32 display, depth, draw, tex_base, f10, f14, f18, f1C, f20; } Vram_00587A30;
typedef struct { u8 pad[0x150]; s16 display_width, display_height, psm, fbp0, storage_width, storage_height; } FsAa_00587A30;
typedef struct { s32 x0, x1, y0, y1; } Rect_00587A30;
typedef struct { u8 pad[0x240]; Rect_00587A30 scissor; } View_00587A30;
typedef struct {
    unsigned long pad0[2];
    unsigned long frame1, pad18, frame2, pad28, zbuf1, pad38, zbuf2, pad48, xyoffset1, pad58, xyoffset2;
} DrawEnv_00587A30;
typedef struct { u8 b[0x60]; } LoadImage_00587A30;

extern Vram_00587A30 D_001FC450;
extern FsAa_00587A30 D_00228580;
extern s32 D_001A5810[];
extern s32 D_L39_002413A0; __asm__(".extern D_L39_002413A0, 16");
extern View_00587A30 D_L39_0025D6C0;
extern DrawEnv_00587A30 D_001A40D0;
extern unsigned long D_001A42A0[];
extern unsigned long D_001A4310[];
extern unsigned long D_L39_002411B0[];
extern u8 D_L39_0025F7C0[];
extern s32 D_L39_002402F0; __asm__(".extern D_L39_002402F0, 16");
extern s32 D_L39_002402F4; __asm__(".extern D_L39_002402F4, 16");
typedef struct { s32 width, height, half_width, half_height, left, top, right, bottom; } Extent_00587A30;
extern Extent_00587A30 D_L39_00240300 __attribute__((section(".sdata")));
extern void func_001264E0(s32);
extern s32 func_001331A0(s32, s32);
extern void func_00139EA0(LoadImage_00587A30 *, s16, s16, s16, s16, s16, s16, s16);
extern void func_0013A1C8(LoadImage_00587A30 *, u8 *);
extern void func_L39_00597230(s32, s32, s32, s32, s32, s32);
extern void func_L39_00597E70(void);
extern void func_00392350(s32);
extern void func_L39_00597E48(void);
extern void func_0038CB78(void *, s32, s32);
extern void func_003D9338(void);

/* from rac2-decomp's func_0027B440 (SetPalMode) */
void func_L39_00587A30(s32 clear) {
    LoadImage_00587A30 image;
    s32 n;
    s32 i;
    unsigned long zbuf;
    unsigned long frame;

    func_001264E0(0);
    if (D_001A5810[0] != 0) {
        D_001FC450.draw = 0x100000;
        D_001FC450.depth = 0x1E0000;
        D_001FC450.display = 0;
        D_001FC450.tex_base = 0x2C0000;
        func_L39_00597230(0x200, 0x1C0, 0x200, 0x200, 4, 0);
    } else if (D_L39_002413A0 != 0) {
        D_001FC450.draw = 0x118000;
        D_001FC450.depth = 0x1E8000;
        D_001FC450.display = 0;
        D_001FC450.tex_base = 0x2C0000;
        func_L39_00597230(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        D_001FC450.draw = 0x118000;
        D_001FC450.depth = 0x1E8000;
        D_001FC450.display = 0;
        D_001FC450.tex_base = 0x2C0000;
        func_L39_00597230(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    D_001FC450.f10 = D_001FC450.tex_base;
    D_001FC450.f14 = D_001FC450.tex_base + 0x1000;
    D_001FC450.f18 = D_001FC450.tex_base + 0x1400;
    D_001FC450.f1C = D_001FC450.tex_base + 0x1800;
    D_001FC450.f20 = D_001FC450.tex_base + 0x1C00;
    D_L39_00240300.width = D_00228580.display_width;
    D_L39_00240300.height = D_00228580.display_height;
    D_L39_00240300.half_width = D_L39_00240300.width >> 1;
    D_L39_00240300.half_height = D_L39_00240300.height >> 1;
    D_L39_00240300.left = (0x800 - D_L39_00240300.half_width) << 4;
    D_L39_00240300.top = (0x800 - D_L39_00240300.half_height) << 4;
    D_L39_00240300.right = (D_L39_00240300.half_width + 0x800) << 4;
    D_L39_00240300.bottom = (D_L39_00240300.half_height + 0x800) << 4;
    D_L39_0025D6C0.scissor.x0 = 0;
    D_L39_0025D6C0.scissor.x1 = D_L39_00240300.width - 1;
    D_L39_0025D6C0.scissor.y0 = 0;
    D_L39_0025D6C0.scissor.y1 = D_L39_00240300.height - 1;
    frame = (D_001FC450.depth >> 13) | ((unsigned long)(D_L39_00240300.width >> 6) << 16);
    D_001A40D0.frame1 = frame;
    zbuf = (D_001FC450.draw >> 13) | 0x1000000;
    D_001A40D0.frame2 = frame;
    D_001A40D0.xyoffset1 = D_L39_00240300.left | ((unsigned long)D_L39_00240300.top << 32);
    D_001A40D0.zbuf1 = zbuf;
    D_001A40D0.zbuf2 = zbuf;
    D_001A40D0.xyoffset2 = D_L39_00240300.left | ((unsigned long)D_L39_00240300.top << 32);
    D_L39_002411B0[2] = D_L39_0025D6C0.scissor.x0 | ((unsigned long)D_L39_0025D6C0.scissor.x1 << 16) | ((unsigned long)D_L39_0025D6C0.scissor.y0 << 32) | ((unsigned long)D_L39_0025D6C0.scissor.y1 << 48);
    D_001A4310[0] = zbuf | ((unsigned long)0x8000 << 17);
    D_001A42A0[0] = zbuf;
    D_L39_002411B0[4] = D_L39_0025D6C0.scissor.x0 | ((unsigned long)D_L39_0025D6C0.scissor.x1 << 16) | ((unsigned long)D_L39_0025D6C0.scissor.y0 << 32) | ((unsigned long)D_L39_0025D6C0.scissor.y1 << 48);
    if (clear) {
        D_L39_002402F0 = D_001FC450.tex_base;
        D_L39_002402F4 = D_001FC450.tex_base;
        func_001264E0(0);
        func_001331A0(0, 0);
        func_001264E0(0);
        func_L39_00597E70();
        func_00392350(0);
        func_001264E0(0);
        func_001331A0(0, 0);
        func_L39_00597E48();
        func_0038CB78(D_L39_0025F7C0, 0, 0x1000);
        n = (D_00228580.storage_width * D_00228580.storage_height) >> 10;
        for (i = 0; i < n; i++) {
            func_00139EA0(&image, i << 4, 1, 0, 0, 0, 32, 32);
            func_001264E0(0);
            func_0013A1C8(&image, D_L39_0025F7C0);
            func_001331A0(0, 0);
        }
    }
    func_003D9338();
}
/* localdecomp:end func_L39_00587A30 */
