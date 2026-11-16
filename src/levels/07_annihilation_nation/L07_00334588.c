#include "common.h"

/* localdecomp:start func_L07_00334588 */
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_001DF458_sda;
__asm__(".extern D_001DF458_sda, 4");

extern u8 *func_L07_00333918(u8 *);

void func_L07_00334588(u8 *a0) {
    u8 *s = func_L07_00333918(a0);
    s16 v = *(s16 *)(s + 0xC);
    u16 *p;
    u8 *e;
    u8 *t;
    s16 h;

    if (v == -1) return;
    p = D_L07_0021C020[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_001DF458_sda && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L07_0021C020[a0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA) && e[0x20] != 1) {
            t = func_L07_00333918(e);
            if (t[0x1C] == 1) {
                h = *(s16 *)(t + 0xC);
                if (h != -1 && h >= v) {
                    *(u16 *)(t + 0xC) = *(u16 *)(t + 0xC) - 1;
                }
            }
        }
        p++;
    }
    *(s16 *)(s + 0xC) = -1;
}
/* localdecomp:end func_L07_00334588 */
