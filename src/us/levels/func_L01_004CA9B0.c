#include "common.h"

/* NTSC-U counterpart of func_L01_004CE670 (src/levels/shared/L01_004CE670.c): 100 -> 120 */
/* localdecomp:start func_L01_004CA9B0 */
extern s32 func_0037DF98(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_L01_004C9EF8(u8 *, s32, s32, f32, f32);

/* prints a localised format string into a label's text buffer (label + 0x88) */
static __inline__ void setTextf_004CE670(u8 *label, s32 id, s32 arg) {
    func_0011B2E8((char *)label + 0x88, (char *)func_0037DF98(id), arg);
}

void func_L01_004CA9B0(u8 *p, s32 i, s32 id, s32 arg, s32 color) {
    if (color == -1) {
        color = 0x78;
    }
    setTextf_004CE670(p + (i * 0x230 + 0x4610), id, arg);
    func_L01_004C9EF8(p + (i * 0x230 + 0x4610), 1, color, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CA9B0 */
