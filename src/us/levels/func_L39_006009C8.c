#include "common.h"

/* NTSC-U counterpart of func_L39_006030C8 (src/levels/shared/L39_00602D90.c): 100 -> 120 */
/* localdecomp:start func_L39_006009C8 */
extern s32 *D_L39_002412A0;
extern f32 D_L39_002412C0;
extern f32 D_L39_002412D0;
extern s32 func_0037DF98(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_005FFE38(void *, s32, f32, f32, s32);

void func_L39_006009C8(char *a0, s32 a1, s32 id, s32 val, s32 a4) {
    f32 x;
    f32 y;
    s32 flag;
    s32 n;
    flag = 1;
    x = 255.0f;
    y = 135.0f;
    if (a4 == -1) {
        a4 = 120;
    }
    n = a1 * 0x230;
    func_00120048((u8 *)(a0 + n + 0x4668), (u8 *)func_0037DF98(id), val);
    n = *D_L39_002412A0;
    if (n >= 2) {
        s32 i = n - 1;
        x = (s32)(x / D_L39_002412C0 * (&D_L39_002412C0)[i]);
        y = (s32)(y / D_L39_002412D0 * (&D_L39_002412D0)[i]);
        flag = 0;
    }
    func_L39_005FFE38(a0 + (a1 * 0x230 + 0x45E0), flag, x, y, a4);
}
/* localdecomp:end func_L39_006009C8 */
