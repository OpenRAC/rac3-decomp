#include "common.h"

/* localdecomp:start func_L39_006086F8 */
extern void func_001264E0(s32);
extern s32 func_00126620(s32 *, s32);

s32 func_L39_006086F8(void *a0, s32 a1, s32 a2, s32 a3) {
    s32 dma[4];
    s32 id;

    if (a3 <= 0) {
        return 0;
    }
    func_001264E0(0);
    dma[0] = a2;
    dma[1] = a1;
    dma[2] = a3;
    dma[3] = 0;
    do {
        id = func_00126620(dma, 1);
    } while (id == 0);
    return a3;
}
/* localdecomp:end func_L39_006086F8 */

/* localdecomp:start func_L39_00608778 */
extern void func_001264E0(s32 a0);
extern s32 func_00126620(s32 *a0, s32 a1);
extern s32 func_00126600(s32 a0);
extern void func_00194DC8(s32 a0, s32 a1);

void func_L39_00608778(void *obj, u8 *buf, s32 size, s32 off) {
    s32 dma[4], id;
    func_001264E0(0);
    dma[0] = (s32)buf; dma[1] = *(s32 *)((u8 *)obj + 0x48); dma[2] = size; dma[3] = 0;
    do { id = func_00126620(dma, 1); } while (id == 0);
    while (func_00126600(id) >= 0) {}
    func_00194DC8(size, off);
}
/* localdecomp:end func_L39_00608778 */

INCLUDE_ASM("asm/levels", func_L39_00608818);

/* localdecomp:start func_L39_006089A0 */
extern u8 D_L39_002DD4E0[];
extern u8 D_L39_002E53E0[];
extern s32 func_00194DF8(void);
extern void func_L39_00608778(void *obj, u8 *buf, s32 size, s32 off);

void func_L39_006089A0(void *object) {
    s32 *o = object;
    s32 t = 0;
    s32 next, i, count;
    u8 *src;
    u8 *dst;

    switch (o[0]) {
    case 1:
        if (o[15] < 0x1000)
            return;
        t = 0x1000 - o[20];
        break;
    case 2:
        t = (func_00194DF8() - o[24]) & 0xFFF;
        break;
    case 3:
        return;
    default:
        break;
    }
    while (t >= 0x100 && o[15] >= o[6] * 256) {
        next = t - 0x100;
        for (i = 0; i < o[6]; i++) {
            dst = D_L39_002E53E0;
            count = 0;
            src = (u8 *)o[13] + (o[14] - o[15] + o[16]) % o[16];
            src += i * o[7];
            do {
                s32 k;
                for (k = 0; k < o[7]; k++) {
                    *dst++ = *src++;
                    count++;
                }
                src += o[7] * (o[6] - 1);
            } while (count < 0x100);
            if (o[24] + 0x100 == 0x1000)
                D_L39_002DD4E0[0x7FF1] = 3;
            if (o[24] == 0) {
                u8 *p = D_L39_002DD4E0 + 0x7F00;
                p[1] = 6;
                p[0x11] = 2;
            }
            func_L39_00608778(o, D_L39_002E53E0, 0x100, (i << 12) + o[24]);
        }
        t = next;
        o[15] -= o[6] * 256;
        o[24] = (o[24] + 0x100) % 0x1000;
        o[20] += 0x100;
    }
}
/* localdecomp:end func_L39_006089A0 */
