#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AC1D8 */
typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern char D_001D8388[], D_001D8398[], D_001D83A8[], D_001D83E0[], D_001D8418[], D_001D8420[], D_001D8430[];
extern s32 func_11B2E8();
extern void func_00391130();
extern void func_003911B8();
extern void func_0038FA18();
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_003AC638(s32, s32, s32, f32, f32, f32, f32);
void func_003AC1D8(s32 a0, W_3A6C30 *p, s32 a2, s32 a3, s32 mode, s32 center, s32 a6, s32 a7, s32 x, s32 y, u8 b) {
    char buf[0x200];
    s32 saved = (s16)p->h12;
    s32 dx, dy, l, r, t, bo, cx, cy;
    p->h12 |= 3;
    if (x != 0) {
        if (y != 0) {
            if (b != 0) {
                if (a7 != 0) func_11B2E8(buf, D_001D8388, a3, 1, x, 1, y);
                else func_11B2E8(buf, D_001D8398, a3, 1, 1, x, 1, y);
            } else {
                if (a7 != 0) func_11B2E8(buf, D_001D83A8, a3, 1, x, y);
                else func_11B2E8(buf, D_001D83E0, a3, 1, 1, x, y);
            }
        } else {
            if (a7 != 0) func_11B2E8(buf, D_001D8418, a3, 1, x);
            else func_11B2E8(buf, D_001D8420, a3, 1, 1, x);
        }
    } else {
        func_11B2E8(buf, D_001D8430, a3);
    }
    p->h12 |= 4;
    switch (mode) {
    case 0: func_00391130(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FA18)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_003911B8(p, a2, buf, a6); break;
    }
    if (center != 0) {
        s32 c = (*(s32 *)0x1D4BC4 - p->hE) >> 1;
        p->h0 = c;
        p->h2 = p->h0 + p->hE;
        p->hA = c + (p->hE >> 1);
    }
    switch (mode) {
    case 0: func_00391130(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FA18)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_003911B8(p, a2, buf, a6); break;
    }
    dx = (p->hC >> 1) + 10;
    dy = (p->hE >> 1) + 5;
    p->h12 &= ~4;
    cx = p->h8;
    cy = p->hA;
    t = cy - dy;
    l = cx - dx;
    r = cx + dx;
    bo = cy + dy;
    func_0038C3B0(t, bo, l, r, 0x60, 0x600E5092);
    func_003AC638(a0, 0x60, 0x332299DE, t, bo, l, r);
    p->h18 = 2;
    p->h12 |= 0x20;
    p->h1A = 2;
    switch (mode) {
    case 0: func_00391130(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038FA18)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_003911B8(p, a2, buf, a6); break;
    }
    p->h12 = saved;
}
/* localdecomp:end func_003AC1D8 */
