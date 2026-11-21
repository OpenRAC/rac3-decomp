#include "common.h"

/* NTSC-U counterpart of func_L01_004F45F0 (src/levels/shared/L01_004EF3A8.c): spring constants 0.015f/0.3f/5 degrees for PAL's 0.0216f/0.432f/6 degrees */
/* localdecomp:start func_L01_004F07E8 */
#include "vu0.h"
typedef int s128_004F07E8 __attribute__((mode(TI)));
typedef struct {
    u8 pad[128];
    s128_004F07E8 out;
    u8 pad2[9972 - 144];
    s32 idx;
    s32 count;
} St_004F07E8;
extern St_004F07E8 D_001A4BE0;
extern f32 func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern void func_L01_004EAEC0(f32, f32, f32);
extern void func_L01_004F0608(void);
void func_L01_004F07E8(void) {
    vu0_q v;
    u8 *h = (u8 *)&D_001A4BE0;
    s32 mode = h[0x25F4];
    if (*(s16 *)(h + 0x218)) mode = 1;
    switch (mode) {
    case 0: {
        s32 state = *(s32 *)(h + 0x25C4);
        if (state == 36 || state == 37 || *(s32 *)(h + 0x25CC) == 17 || state == 121 || state == 48 || state == 44 || state == 43) return;
        v = *(vu0_q *)(h + 0x90);
        func_L01_004455F0(&v, 0.0f, h + 0xA0, 0.015f, 0.3f, 0.0872664675116539f, 0);
        func_L01_004455F0((u8 *)&v + 4, 0.0f, h + 0xA4, 0.015f, 0.3f, 0.0872664675116539f, 0);
        func_L01_004EAEC0(*(f32 *)(h + 0xA0), *(f32 *)(h + 0xA4), 0.0f);
        break;
    }
    case 1:
    case 2:
        ((void (*)(s32))func_L01_004F0608)(mode);
        break;
    }
}
/* localdecomp:end func_L01_004F07E8 */
