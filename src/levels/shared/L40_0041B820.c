#include "common.h"

/* localdecomp:start func_L40_0041B820 */
/* scramble shaped after func_L39_0055AD78 in L39_005598D8.c (same 0x19E4 check-byte scramble) */
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
__asm__(".extern D_L40_00249330, 32");
extern u8 D_L40_003BFE20[];
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L40_0041B6B8(void *moby, s32 type, s32 val, f32 f);

typedef struct { f32 f0; u8 pad4[0x10]; s32 f14; u8 pad18[0x1C]; s32 f34; s32 f38; u8 pad3C[0x14]; s32 f50; } V_0041B820;

void func_L40_0041B820(u8 *moby, s32 a1) {
    V_0041B820 *pvars;
    u8 *g;
    u8 *w;
    s16 flag;
    long t;
    s32 x;
    s32 i;

    pvars = *(V_0041B820 **)(moby + 0x68);
    g = 0;
    if (pvars->f50 >= 0) {
        g = D_L40_00249330[pvars->f50];
    }
    if (g != 0) {
        w = *(u8 **)(g + 0x2524);
        *(u16 *)(w + 0x34) &= 0x7FFF;
        if (*(u8 **)(g + 0x2530) != 0 && (*(u8 **)(g + 0x2530))[0x27B] != 0) {
            u32 buf[2];
            u8 *b;
            u8 *p;
            flag = 0;
            p = g + 0x19E4;
            t = *p;
            x = 0;
            if (t != 0) {
                s32 m;
                s32 k;
                s32 n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                x = buf[1];
            }
            if ((x ^ 0x31) == 0) {
                flag++;
            }
        } else {
            flag = 0;
        }
        if (!(u8)flag) {
            (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0, 1, 0, 1);
        }
        func_L01_004450F0(moby, 1, -1);
        if (g[0x1A14] != 0) {
            func_L01_003EB5E0(g[0x24C9], 2);
        }
        if (a1 != 0 && g[0x1A14] != 0) {
            ((void (*)(void *, s32, s32, s32, f32))func_L40_0041B6B8)(moby, 1, 1, 250, pvars->f0);
            if (pvars->f34 != 0) {
                ((void (*)(void *, s32, s32, s32, f32))func_L40_0041B6B8)(moby, 1, 1, pvars->f38 * 1000, 0.0f);
            }
        }
    }
    pvars->f14 = 0;
    pvars->f50 = -1;
}
/* localdecomp:end func_L40_0041B820 */

INCLUDE_ASM("asm/levels", func_L40_0041B9F0);
