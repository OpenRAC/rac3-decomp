#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B0048.c's earlier functions */
extern void func_003B0950(s32 *);
extern void func_003B0728(u8 *o, s32 a, s32 b, s32 c);

typedef struct { s32 x0; u8 p4[0x14]; s32 x18; s32 x1C; u8 p20[0x14]; s32 x34; s32 x38; s32 x3C; s32 x40; u8 p44[0xC]; s32 x50; u8 p54[0xC]; s32 x60; } S_3AB3A8;
extern s32 func_13D1B0();
typedef struct { u8 pad[0x7F00]; u8 buf[0x100]; } S_2224A0;
extern S_2224A0 D_00222420;
extern u8 D_0022E320[];
/* localdecomp:start func_003B0950 */
extern void func_003B0728(u8 *, s32, s32, s32);
extern S_2224A0 D_00226420;
void func_003B0950(s32 *arg0) {
    S_3AB3A8 *o = (S_3AB3A8 *)arg0;
    s32 n = 0;
    s32 i, j, k;
    u8 *src, *dst;
    switch (o->x0) {
    case 1:
        if (o->x3C < 0x1000) return;
        n = 0x1000 - o->x50;
        break;
    case 2:
        n = (func_13D1B0() - o->x60) & 0xFFF;
        break;
    case 3:
        return;
    }
    while (n >= 0x100 && o->x3C >= o->x18 << 8) {
        s32 m = n - 0x100;
        for (i = 0; i < o->x18; i++) {
            S_2224A0 *hdr = &D_00226420;
            u8 *h = hdr->buf;
            dst = &D_0022E320[0];
            k = 0;
            src = (u8 *)o->x34 + (o->x38 - o->x3C + o->x40) % o->x40;
            src += i * o->x1C;
            do {
                for (j = 0; j < o->x1C; j++) {
                    *dst++ = *src++;
                    k++;
                }
                src += o->x1C * (o->x18 - 1);
            } while (k < 0x100);
            if (o->x60 + 0x100 == 0x1000) hdr->buf[0xF1] = 3;
            if (o->x60 == 0) {
                h[1] = 6;
                h[0x11] = 2;
            }
            func_003B0728((u8 *)o, (s32)&D_0022E320[0], 0x100, (i << 12) + o->x60);
        }
        o->x60 = (o->x60 + 0x100) % 0x1000;
        o->x3C -= o->x18 << 8;
        o->x50 += 0x100;
        n = m;
    }
}
/* localdecomp:end func_003B0950 */
