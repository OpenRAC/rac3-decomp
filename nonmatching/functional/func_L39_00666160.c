/* functional: high. Same reads, writes and calls in the same order; the 128-bit copies are plain lq/sq via vu0_q, and the 8-byte unscramble uses the game address of self+0x19E4 as retail does. Only register allocation and scheduling can differ. */
#include "vu0.h"

extern u8 D_001A58D0[];
extern u8 D_001A5930[];
extern u8 D_001A5990[];
extern s32 D_L39_00352940[];
extern s32 D_001A5DF8[];
extern u8 D_L39_004997E0[];
extern void func_L39_00628428(void *);
extern void func_L39_00667700(void *, void *, s32);
extern void func_L39_006673E8(void *, void *, s32);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_0063A030(void *, s32, s32);

void func_L39_00666160(u8 *self) {
    f32 buf[8];
    u8 *p;
    u8 *q;
    u8 *e;
    s32 i;
    s32 t;
    s32 now;
    s32 thr;
    s32 state;
    s32 h;
    u32 fl;

    q = *(u8 **)(*(u8 **)(self + 0x2558) + 4);
    if (q == 0) return;
    for (i = 0; i < 3; i++) {
        *(s32 *)(D_001A58D0 + *(s32 *)(self + 0x2544) * 4 + i * 32) = *(s32 *)(q + 0x58 + i * 4);
        *(s32 *)(D_001A5930 + *(s32 *)(self + 0x2544) * 4 + i * 32) = *(s32 *)(q + 0x64 + i * 4);
        *(s32 *)(D_001A5990 + *(s32 *)(self + 0x2544) * 4 + i * 32) = *(s32 *)(q + 0x70 + i * 4);
    }
    t = D_L39_00352940[1];
    if (t > 0 && t + 0x7530 < D_001A5DF8[0]) {
        thr = D_001A5DF8[0] - 0x1C20;
        if (*(s32 *)(*(u8 **)(*(u8 **)(self + 0x2558) + 4) + 0x4C) < thr) {
            if (*(u32 *)(self + 0x4D84) & 1) return;
            *(u32 *)(self + 0x4D84) |= 1;
            return;
        }
    }
    *(u32 *)(self + 0x4D84) &= ~1;
    p = *(u8 **)(self + 0x2558);
    fl = *(u32 *)(p + 0x1AC);
    e = p + 0x1D0;
    if (fl & 2) {
        s32 c34 = *(s32 *)(p + 0xC34);
        s32 b3 = e[3];
        if (c34 >= b3 || c34 + 0x64 < b3) {
            *(u32 *)(p + 0x1AC) = fl & ~2;
            self[0x1A15] = e[1];
            buf[0] = *(f32 *)(p + 0x1D4);
            buf[1] = *(f32 *)(p + 0x1D8);
            buf[2] = *(f32 *)(p + 0x1DC);
            buf[3] = 1.0f;
            buf[4] = *(f32 *)(p + 0x1E0);
            buf[5] = *(f32 *)(p + 0x1E4);
            buf[6] = *(f32 *)(p + 0x1E8);
            buf[7] = 0.0f;
            if (e[0x1E]) func_L39_00628428(self);
            state = *(s32 *)(self + 0x254C);
            if (state == 5 || state == 3) {
                func_L39_00667700(*(void **)(self + 0x2528), self, 1);
            } else if (state == 6 || state == 4) {
                func_L39_006673E8(*(void **)(self + 0x2528), self, 1);
            }
            h = *(s16 *)(e + 0x1C);
            if (h == 0x31) {
                u8 flag = 0;
                u8 *obj = *(u8 **)(self + 0x2530);
                if (obj != 0 && obj[0x27B] != 0) {
                    u8 *key = self + 0x19E4;
                    u32 c = self[0x19E4];
                    u32 w = 0;
                    if (c != 0) {
                        u32 base = (u32)key - c;
                        s32 k;
                        u32 tmp[2];
                        u8 *tb = (u8 *)tmp;
                        for (k = 0; k < 8; k++) {
                            u32 r = (base + k * 5) & 7;
                            tb[k] = D_L39_004997E0[c + 1 + r * 255];
                        }
                        tmp[0] ^= (u32)key;
                        tmp[1] ^= tmp[0];
                        w = tmp[1];
                    }
                    if ((w ^ 0x31) == 0) flag = 1;
                }
                if (flag) {
                    func_L39_00637EC8(self, buf, buf + 4, (s16)h, 0, e[2], 0);
                    self[0x1A0A] = 1;
                } else {
                    func_L39_00637EC8(self, buf, buf + 4, (s16)h, 0, e[2], 0);
                }
            } else {
                func_L39_00637EC8(self, buf, buf + 4, (s16)h, 0, e[2], 0);
            }
            if (e[0x1E]) func_L39_0063A030(self, 0x1A, 0);
        }
    }
    p = *(u8 **)(self + 0x2558);
    if (*(s32 *)(p + 0x16C) >= 0 && !(D_001A5DF8[0] < *(s32 *)(p + 0x16C))) {
        *(vu0_q *)(p + 0x190) = *(vu0_q *)(p + 0x180);
        p = *(u8 **)(self + 0x2558);
        *(s32 *)(p + 0x160) = *(s32 *)(p + 0x164);
        p = *(u8 **)(self + 0x2558);
        *(vu0_q *)(p + 0x190) = *(vu0_q *)(p + 0x180);
        p = *(u8 **)(self + 0x2558);
        *(vu0_q *)(p + 0x180) = *(vu0_q *)(p + 0x170);
        p = *(u8 **)(self + 0x2558);
        *(s32 *)(p + 0x164) = *(s32 *)(p + 0x16C) - 0xF5;
        p = *(u8 **)(self + 0x2558);
        *(s32 *)(p + 0x16C) = -1;
    }
    (*(void (**)(void *))(*(u8 **)(self + 0x14) + 0xC))(self);
}
