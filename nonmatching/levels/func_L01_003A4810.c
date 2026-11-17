/* PAL near miss (b8-s4): 6 differences, all one register swap: retail keeps the flag halfword in $v1 and the 0xFF byte in $v0 around the sw 0x98 / sb 0xA8 / sh 0x34 group, this C has them the other way; about 14 compiles (statement orders, |= and &= forms, temporaries) did not move it. The four stores before it needed the order 0x38, 7, 9, 8.
 */
#include "common.h"
/* localdecomp:start func_L01_003A4810 */
typedef struct {
    f32 f0;
    s16 h4;
    u8 pad6[0x1];
    u8 b7;
    u8 b8;
    u8 b9;
    u8 pad_a[0x2E];
    s16 h38;
} S_003A4810;

extern S_003A4810 *func_L01_00443828(u8 *);
extern S_003A4810 *func_L01_00448FF0(u8 *);
extern void func_L01_00456C98(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern s32 func_L01_004AA710(u8 *, s32);
extern void func_L01_004AA878(s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L01_003A4810(u8 *a0) {
    S_003A4810 *p;
    S_003A4810 *q;
    s32 i = 0;
    *(u8 *)(a0 + 0x7F) = 0;
    p = func_L01_00443828(a0);
    p->f0 = p->h4;
    q = func_L01_00448FF0(a0);
    q->h38 = 0;
    q->b7 = 0;
    q->b9 = 0;
    q->b8 = 0;
    func_L01_00456C98(a0, -1, 0, 0, 0, 0, 3, 0, 0.0f, 0.0f, 1.0f, 0, 0);
    *(s32 *)(a0 + 0x98) = 0;
    *(u8 *)(a0 + 0xA8) = 0xFF;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x43) & 0xEFFF;
    func_L01_004AA7E8(a0, 1);
    for (; i < 0x34; i++) {
        if (func_L01_004AA710(a0, i) != 0) {
            func_L01_004AA878(i);
        }
    }
    func_L01_004450F0(a0, 0x10, 6);
}
/* localdecomp:end func_L01_003A4810 */
