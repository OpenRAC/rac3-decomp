#include "common.h"

/* NTSC-U counterpart of func_L24_0035A300 (src/levels/24_insomniac_museum/L24_00359248.c) */
extern u16 *D_L24_0021C360_00359228[];
extern u8 *D_L24_001DF51C_00359228;
extern s32 D_L24_001DF558_00359228;

/* localdecomp:start func_L24_00359228 */
__asm__(".extern D_L24_001DF558_00359228, 4");
extern u16 *D_L24_0021C360_00359228[];
extern u8 *D_L24_001DF51C_00359228;
extern s32 D_L24_001DF558_00359228;
s32 func_0037E208(s32, s32);
void func_L24_00359228(u8 *arg0)
{
    u16 *p;
    s32 n;

    if (arg0[0x21] == 0xFF)
        return;
    n = 0;
    p = D_L24_0021C360_00359228[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L24_001DF558_00359228 && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L24_0021C360_00359228[arg0[0x21]])) {
        u8 *e = D_L24_001DF51C_00359228 + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(arg0 + 0xAA)) {
            u8 t = e[0x20];
            if (t == 0xFE) {
            } else if (t == 0xFD) {
            } else {
                u8 *s = *(u8 **)(e + 0x68);
                if (*(s16 *)(s + 0x222) != 0)
                    return;
                *(s16 *)(s + 0x220) = n;
                *(s16 *)(s + 0x222) = n;
                *(s16 *)(s + 0x224) = n;
                n += func_0037E208(2, 4);
            }
        }
        p++;
    }
}
/* localdecomp:end func_L24_00359228 */
