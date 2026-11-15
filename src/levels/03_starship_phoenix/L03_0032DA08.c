#include "common.h"

/* localdecomp:start func_L03_0032DA08 */
extern u8 *func_L03_0032F6A8(u8 *a0);
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;

void func_L03_0032DA08(u8 *a0) {
    u8 *self;
    u8 *e;
    u16 *p;
    s32 h;

    self = func_L03_0032F6A8(a0);
    h = *(s16 *)(self + 0x1A);
    if (h == -1) return;
    p = D_L03_0021C620[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L03_001DF9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L03_0021C620[a0[0x21]])) {
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA) && e[0x20] != 1) {
            u8 *r = func_L03_0032F6A8(e);
            if (r[0x1C] == 1) {
                s16 v = *(s16 *)(r + 0x1A);
                if (v != -1 && v >= h) *(s16 *)(r + 0x1A) = *(u16 *)(r + 0x1A) - 1;
            }
        }
        p++;
    }
    *(s16 *)(self + 0x1A) = -1;
}
/* localdecomp:end func_L03_0032DA08 */
