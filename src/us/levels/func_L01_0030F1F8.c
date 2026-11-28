#include "common.h"
/* localdecomp:start func_L01_0030F1F8 */
#include "vu0.h"
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5640[];
extern s32 D_L01_001DFBC0_0030F1F8;
extern s32 D_L01_001E17A8_0030F1F8;
extern s32 func_L01_0050D978(s32);
extern s32 func_L01_0050D980(s32, s32);
extern void func_L01_0044ED38(s32, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);

typedef struct { u8 pad0[0x70]; f32 f70; } Vars_0030F4E8;

s32 func_L01_0030F1F8(u8 *m) {
    u8 *v;
    s32 *tbl;
    s32 a;
    s32 diff;
    f32 lim;
    s32 d;
    s32 arg;
    u8 *row;
    s32 r;

    v = *(u8 **)(m + 0x68);
    if (m[0x20] == 2) {
        return 0;
    }
    tbl = D_001427F0;
    a = tbl[func_L01_0050D978(*(s32 *)(v + 0x68))];
    lim = (f32)func_L01_0050D980(*(s32 *)(v + 0x68), *(s32 *)(v + 0x60));
    if (a < tbl[func_L01_0050D978(*(s32 *)(v + 0x68))]) {
        diff = tbl[func_L01_0050D978(*(s32 *)(v + 0x68))] - a;
        if (diff == 1) {
            row = D_L01_002C5640 + D_001425C0[func_L01_0050D978(*(s32 *)(v + 0x68))] * 0xF0;
            arg = *(s16 *)(row + 0x36);
        } else {
            row = D_L01_002C5640 + D_001425C0[func_L01_0050D978(*(s32 *)(v + 0x68))] * 0xF0;
            arg = *(s16 *)(row + 0x34);
        }
        func_L01_0044ED38(arg, diff, -1, 0);
        if (lim < (f32)*(s32 *)(v + 0x60)) {
            m[0x20] = 2;
            *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * 1.20000005f;
            qzero(v);
            ((Vars_0030F4E8 *)v)->f70 = 0.13333334f;
            d = D_L01_001DFBC0_0030F1F8 - D_L01_001E17A8_0030F1F8;
            if (abs_asm(d) >= 11) {
                func_0039FE80(0, 0, m);
                D_L01_001E17A8_0030F1F8 = D_L01_001DFBC0_0030F1F8;
            }
        }
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L01_0030F1F8 */
