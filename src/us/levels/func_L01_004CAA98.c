#include "common.h"

/* NTSC-U counterpart of func_L01_004CE758 (src/levels/shared/L01_004CE670.c): default colour 0xB4 for 0x96 */
/* localdecomp:start func_L01_004CAA98 */
extern char *func_0011BB58(char *, char *, s32);
extern void func_L01_004C9F98(void *, s32, s32, f32, f32);

/* copies a string into a label's text buffer (label + 0x88, 0xFE bytes) */
static __inline__ void setText_004CAA98(u8 *label, char *src) {
    func_0011BB58((char *)label + 0x88, src, 0xFE);
}

void func_L01_004CAA98(u8 *p, s32 i, char *text, s32 color) {
    if (color == -1) {
        color = 0xB4;
    }
    setText_004CAA98(p + (i * 0x230 + 0x4610), text);
    func_L01_004C9F98(p + (i * 0x230 + 0x4610), 1, color, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CAA98 */
