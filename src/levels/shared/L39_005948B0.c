#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005948B0);

/* localdecomp:start func_L39_005948D0 */
extern s32 D_001D5D60_sda;
extern void func_0038E150(s32);
extern void func_0038F9E0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_L39_00593468(void *, f32, f32, s32, char *, s32, unsigned long);

s32 func_L39_005948D0(s32 x, s32 y, s32 w, s32 h, s32 c, char *text, s32 d) {
    s16 buf[12];
    s32 saved = D_001D5D60_sda;
    func_0038E150(1);
    func_0038F9E0(buf, y, y + h, x, x + w, x, y, 16, 0);
    func_L39_00593468(buf, 1.0f, 1.0f, c, text, d, 0x80000000UL);
    func_0038E150(saved);
    return buf[7];
}
/* localdecomp:end func_L39_005948D0 */
