#include "common.h"

/* declared by functions of L21_00336EF0.c, which this file was cut from */
extern s32 func_L01_0043B568(s32, s32, s32);

/* localdecomp:start func_L21_00338B00 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern u8 *D_L21_001DED9C_00338B00;
extern s32 D_L21_001DEDD8;
extern u16 *D_L21_0021B860[];
void func_L21_00338B00(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *r = (u8 *)func_L01_0043B568(0x1C18, 0, 0x44);
    u16 *q;
    s32 k;
    u8 *e;

    if (r == 0)
        return;
    q = D_L21_0021B860[*(s32 *)(p + 0x28)];
    while (1) {
        k = *(s32 *)(p + 0x28);
        if ((k & 0xFF) == 0xFF) break;
        if (D_L21_001DEDD8 < k) break;
        if (q == 0) break;
        if (!((s16)q[-1] >= 0 || q == D_L21_0021B860[k])) break;
        e = D_L21_001DED9C_00338B00 + ((*q & 0x7FFF) << 8);
        if (e == 0) break;
        if (((s32 (*)(u8 *))(*(void **)(r + 0x1C)))(e) == 3)
            if (((s32 (*)(u8 *))(*(void **)(r + 0x40)))(e) != 0)
                ((void (*)(u8 *, s32))(*(void **)(r + 0x0)))(e, 0);
        q++;
    }
}
/* localdecomp:end func_L21_00338B00 */

INCLUDE_ASM("asm/levels", func_L21_00338C20);
