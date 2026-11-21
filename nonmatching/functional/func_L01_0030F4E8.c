/* functional: high. Codex PAL near miss; verified against PAL asm; exit-layout and flag-line differences only. */
#include "vu0.h"
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1728;
extern s32 func_L01_00511950(s32);
extern s32 func_L01_00511958(s32, s32);
extern void func_L01_00451FB8(s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);

s32 func_L01_0030F4E8(u8 *m) {
    u8 *v;
    s32 *tbl;
    s32 a;
    s32 diff;
    f32 lim;
    s32 d;
    s32 arg;
    u8 *row;

    v = *(u8 **)(m + 0x68);
    if (m[0x20] == 2) {
        return 0;
    }
    tbl = D_001427F0;
    a = tbl[func_L01_00511950(*(s32 *)(v + 0x68))];
    lim = (f32)func_L01_00511958(*(s32 *)(v + 0x68), *(s32 *)(v + 0x60));
    if (a >= tbl[func_L01_00511950(*(s32 *)(v + 0x68))]) {
        return 0;
    }
    diff = tbl[func_L01_00511950(*(s32 *)(v + 0x68))] - a;
    if (diff == 1) {
        row = D_L01_002C5600 + D_001425C0[func_L01_00511950(*(s32 *)(v + 0x68))] * 0xF0;
        arg = *(s16 *)(row + 0x36);
    } else {
        row = D_L01_002C5600 + D_001425C0[func_L01_00511950(*(s32 *)(v + 0x68))] * 0xF0;
        arg = *(s16 *)(row + 0x34);
    }
    func_L01_00451FB8(arg, diff, -1, 0);
    if (lim < (f32)*(s32 *)(v + 0x60)) {
        *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * 1.24f;
        qzero(v);
        m[0x20] = 2;
        *(f32 *)(v + 0x70) = 0.16000001f;
        d = abs_asm(D_L01_001DFB40 - D_L01_001E1728);
        if (d >= 9) {
            func_003A52A0(0, 0, m);
            D_L01_001E1728 = D_L01_001DFB40;
        }
    }
    return 1;
}
