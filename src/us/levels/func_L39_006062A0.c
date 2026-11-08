#include "common.h"

/* localdecomp:start func_L39_006062A0 */
extern u8 D_L39_002DD5E0[];
extern u8 D_L39_002E54E0[];
extern s32 func_00194EE8(void);
extern void func_L39_00606078(void *obj, u8 *buf, s32 size, s32 off);

void func_L39_006062A0(void *object) {
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
        t = (func_00194EE8() - o[24]) & 0xFFF;
        break;
    case 3:
        return;
    default:
        break;
    }
    while (t >= 0x100 && o[15] >= o[6] * 256) {
        next = t - 0x100;
        for (i = 0; i < o[6]; i++) {
            dst = D_L39_002E54E0;
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
                D_L39_002DD5E0[0x7FF1] = 3;
            if (o[24] == 0) {
                u8 *p = D_L39_002DD5E0 + 0x7F00;
                p[1] = 6;
                p[0x11] = 2;
            }
            func_L39_00606078(o, D_L39_002E54E0, 0x100, (i << 12) + o[24]);
        }
        t = next;
        o[15] -= o[6] * 256;
        o[24] = (o[24] + 0x100) % 0x1000;
        o[20] += 0x100;
    }
}
/* localdecomp:end func_L39_006062A0 */
