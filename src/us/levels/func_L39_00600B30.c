#include "common.h"

/* NTSC-U counterpart of func_L39_00603230 (src/levels/shared/L39_00603230.c): 150 -> 180 */
/* localdecomp:start func_L39_00600B30 */
__asm__(".extern D_L39_002412A0, 16");
__asm__(".extern D_L39_002412C0, 16");
__asm__(".extern D_L39_002412D0, 16");
extern s32 *D_L39_002412A0;
extern f32 D_L39_002412C0[] __attribute__((section(".sdata")));
extern f32 D_L39_002412D0[] __attribute__((section(".sdata")));
extern char *func_00120D28(char *, const char *, s32);
extern void func_L39_005FFF20(void *, s32, f32, f32, s32);

void func_L39_00600B30(char *a0, s32 a1, char *a2, s32 a3) {
    f32 x = 255.0f;
    f32 y = 135.0f;
    s32 flag;
    s32 alpha = 180;
    s32 n;
    n = a1 * 0x230;
    if (a3 != -1) {
        alpha = a3;
    }
    func_00120D28(a0 + n + 0x4668, a2, 0xFE);
    flag = 1;
    n = *D_L39_002412A0;
    if (n >= 2) {
        n--;
        x = (s32)(x / D_L39_002412C0[0] * D_L39_002412C0[n]);
        y = (s32)(y / D_L39_002412D0[0] * D_L39_002412D0[n]);
        flag = 0;
    }
    func_L39_005FFF20(a0 + (a1 * 0x230 + 0x45E0), flag, x, y, alpha);
}
/* localdecomp:end func_L39_00600B30 */
