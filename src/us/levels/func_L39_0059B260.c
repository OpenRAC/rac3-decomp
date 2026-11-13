#include "common.h"

/* NTSC-U counterpart of func_L39_0059C5F0 (src/levels/shared/L39_0059C5F0.c): 8 -> 10 */
/* localdecomp:start func_L39_0059B260 */
extern u8 D_L39_00498BD0[];
extern s32 D_L39_0024BDE4;
__asm__(".extern D_L39_0024BDE4, 16");
extern void func_00393450_0059B260(void *);
s32 func_L39_0059B260(s32 a0) {
    s32 n = 0;
    u8 *e = D_L39_00498BD0;
    s32 v;
    do {
        if ((*(s32 *)(e + 4) & 0x10) || D_L39_0024BDE4 != 0) {
            if (*(s32 *)(e + 0x7C) < 10) {
                *(s32 *)(e + 0x7C) = 10;
            }
        }
        v = *(s32 *)(e + 0x7C);
        if (v > 0 && (*(s32 *)(e + 0x7C) = v - 1, v - 1 > 0)) {
            n++;
            if (*(s32 *)(e + 0x6C) < 30) {
                *(s32 *)(e + 0x6C) = *(s32 *)(e + 0x6C) + 1;
            }
        } else if (*(s32 *)(e + 0x6C) >= -5) {
            *(s32 *)(e + 0x6C) = *(s32 *)(e + 0x6C) - 1;
        }
        if (*(s32 *)(e + 0x68) != 0 && *(s32 *)(e + 0x6C) == -6) {
            func_00393450_0059B260(e);
        }
        if (a0 != 0 && *(void **)(e + 0x14) != 0) {
            ((void (*)(void *))*(void **)(e + 0x14))(e);
        }
        e += 0x90;
    } while ((s32)e < (s32)D_L39_00498BD0 + 0x750);
    return n;
}
/* localdecomp:end func_L39_0059B260 */
