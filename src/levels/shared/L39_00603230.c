#include "common.h"

/* localdecomp:start func_L39_00603230 */
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_00241140, 16");
__asm__(".extern D_L39_00241150, 16");
extern s32 *D_L39_00241120;
extern f32 D_L39_00241140[] __attribute__((section(".sdata")));
extern f32 D_L39_00241150[] __attribute__((section(".sdata")));
extern char *func_00120D28(char *, const char *, s32);
extern void func_L39_006025F0(void *, s32, f32, f32, s32);

void func_L39_00603230(char *a0, s32 a1, char *a2, s32 a3) {
    f32 x = 255.0f;
    f32 y = 135.0f;
    s32 flag;
    s32 alpha = 150;
    s32 n;
    n = a1 * 0x230;
    if (a3 != -1) {
        alpha = a3;
    }
    func_00120D28(a0 + n + 0x4668, a2, 0xFE);
    flag = 1;
    n = *D_L39_00241120;
    if (n >= 2) {
        n--;
        x = (s32)(x / D_L39_00241140[0] * D_L39_00241140[n]);
        y = (s32)(y / D_L39_00241150[0] * D_L39_00241150[n]);
        flag = 0;
    }
    func_L39_006025F0(a0 + (a1 * 0x230 + 0x45E0), flag, x, y, alpha);
}
/* localdecomp:end func_L39_00603230 */
