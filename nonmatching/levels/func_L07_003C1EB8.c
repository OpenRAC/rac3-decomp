/* PAL near miss (Codex wave 10): near miss: 63 words differ with the file's flags.
 * Worker's note: 63 diff in func_L07_003C1EB8.05.log; message switch matches; screen-coordinate conversion differs (retail has unused D_L07_001E05A0 loads); no volatile workaround
 */
#include "common.h"
/* localdecomp:start func_L07_003C1EB8 */
typedef struct { u8 pad[8]; s16 x,y; u16 width,height; u16 p10,flags; u8 p14[4]; s16 h18,h1A; u32 p1C; } Text_003C1EB8;
extern char D_L07_001DE598[];
extern char D_L07_001DE5A0[];
extern char D_L07_001DE5B0[];
extern u8 D_00143A07[];
extern f32 D_L07_001E05A4[];
extern s32 D_001D4BC8[];
extern s32 D_L07_001D64E8;
__asm__(".extern D_L07_001D64E8, 16");
void func_L07_003C1EB8(u8 *self) {
    extern s32 func_00381FF0(s32);
    extern s32 func_0011B2E8(char *, const char *, ...);
    extern char *func_0011B4E4(char *, const char *);
    extern void func_003910C0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_0038FA18(void *, unsigned long, void *, s32, unsigned long, f32, f32);
    extern void func_0038C3B0(s32, s32, s32, s32, s32, u32);
    extern void func_L01_00436020(s32, u32, f32, f32, f32, f32);
    char text[1024];
    Text_003C1EB8 draw;
    u8 *p = *(u8 **)(self + 0x68);
    u32 y;
    s32 sx,sy;
    s32 hx,hy;
    switch (*(s32 *)(p + 0x30)) {
    case 0: func_0011B2E8(text, D_L07_001DE598, func_00381FF0(0x58B)); break;
    case -1: func_0011B2E8(text, D_L07_001DE598, func_00381FF0(0x269)); break;
    case -2: func_0011B2E8(text, D_L07_001DE598, func_00381FF0(0x185E)); break;
    case -3: func_0011B2E8(text, D_L07_001DE598, func_00381FF0(0x1660)); break;
    default: func_0011B2E8(text, D_L07_001DE5A0, func_00381FF0(0x269), func_00381FF0(0x125C), *(s32 *)(p + 0x30), func_00381FF0(0x282)); break;
    }
    if (p[0x3B]) {
        func_0011B4E4(text, D_L07_001DE5B0);
        func_0011B4E4(text, (char *)func_00381FF0(0x12B3));
    }
    hx = 144;
    y = D_00143A07[0] == 2 ? hx : 128;
    draw.h18 = 2;
    draw.h1A = 2;
    sx = (s32)(D_L07_001E05A4[0] * 256.0f + 0.5f + 0.0f);
    sy = (s32)((f32)(y + 256) * D_L07_001E05A4[0] + 0.5f + 0.0f);
    func_003910C0(&draw, sx, sy, D_001D4BC8[0] - 144, D_001D4BC8[0] + 144, D_001D4BC8[0], (y >> 1) | 0x100, 16, 39);
    func_0038FA18(&draw, 0x8066CCFFUL, text, -1, 0x80000000UL, 1.0f, 1.0f);
    hx = ((s16)draw.width >> 1) + 8;
    hy = ((s16)draw.height >> 1) + 8;
    func_0038C3B0(draw.y - hy, draw.y + hy, draw.x - hx, draw.x + hx, 0x33, 0x331465B7);
    func_L01_00436020(0x33, 0x332299DE, draw.y - hy, draw.y + hy, draw.x - hx, draw.x + hx);
    draw.flags &= ~4;
    func_0038FA18(&draw, 0x8066CCFFUL, text, -1, 0x80000000UL, 1.0f, 1.0f);
    D_L07_001D64E8 = 1;
}
/* localdecomp:end func_L07_003C1EB8 */
