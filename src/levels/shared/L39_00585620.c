#include "common.h"

/* localdecomp:start func_L39_00585620 */
typedef struct {
    u8 pad0[0x20];
    s32 height;
    u8 pad24[0x28 - 0x24];
} L_585620;

typedef struct {
    u8 pad0[0x22];
    s16 layout;
    u8 pad24[0x378 - 0x24];
    f32 slide;
    u8 pad37C[0x388 - 0x37C];
    s32 style;
} T_585620;

extern T_585620 D_L39_0025C600;
extern L_585620 D_L39_0025C990[];
extern s32 D_00240300;
extern s32 func_00120884(char *);
extern s32 func_L39_005947A0(char *, s32);
extern s32 func_L39_00585F98(f32, f32, f32);
extern void func_L39_00594DF8(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L39_00593468(void *, f32, f32, s32, char *, s32, unsigned long);
extern void func_L39_0058B2C8(s32, s32, s32, s32, unsigned long);

/* from rac2-decomp's func_L00_002E30B8 */
void func_L39_00585620(char *text, f32 t, s32 mode, s32 color, s32 y, s32 pass) {
    s32 box[8];
    s32 x = 0;
    f32 alpha = 0.0f;
    s32 width = func_L39_005947A0(text, func_00120884(text));
    switch (mode) {
    case 1:
        x = (s32)t;
    case 0:
        alpha = 1.0f;
        x += D_00240300 / 2;
        break;
    case 2:
        x = func_L39_00585F98(D_L39_0025C600.slide, (f32)(D_00240300 / 2) + (f32)width, t) - width;
        alpha = t;
        break;
    case 3:
        x = width + D_00240300 - func_L39_00585F98(D_L39_0025C600.slide, (f32)(D_00240300 / 2) + (f32)width, 1.0f - t);
        alpha = 1.0f - t;
        break;
    }
    if (pass == 0) {
        func_L39_00594DF8(box, y, y + D_L39_0025C990[D_L39_0025C600.layout].height, -D_00240300, D_00240300 * 2,
                      x, y + D_L39_0025C990[D_L39_0025C600.layout].height / 2, D_L39_0025C600.style, 3);
        func_L39_00593468(box, 1.0f, 1.0f, color, text, -1, 0x80000000UL);
    } else if (pass == 1) {
        s32 shade = (s32)(alpha * 96.0f) << 24;
        func_L39_0058B2C8(y + 2, y + D_L39_0025C990[D_L39_0025C600.layout].height - 2, -D_00240300,
                      D_00240300 * 2, shade);
    }
}
/* localdecomp:end func_L39_00585620 */
