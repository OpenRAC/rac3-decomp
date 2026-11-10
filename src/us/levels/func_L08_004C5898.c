#include "common.h"

/* localdecomp:start func_L08_004C5898 */
extern u8 D_1A4BE0[];
extern s32 D_00142668[];
extern u8 D_00142CAD[];
extern void func_00388468(void *, s32);
extern void func_L01_004DC1C0(s32);
extern void func_L08_004D8D78(s32, s32);

void func_L08_004C5898(void)
{
    u8 *p = D_1A4BE0;
    s16 mode = *(s16 *)(p + 0x1470);
    u8 keep = *(u8 *)(p + 0x147F);
    func_00388468(p + 0x1470, 16);
    *(u8 *)(p + 0x147F) = keep;
    *(s16 *)(p + 0x1470) = mode;
    *(u8 *)(p + 0x25EA) = 0;
    *(s16 *)(p + 0x368) = 0;
    if (*(u8 *)(p + 0x25EE) != 0)
        return;
    if (*(s32 *)(p + 0x360) != 0) {
        if (mode == -1)
            return;
    } else {
        if (mode == -1)
            return;
    }
    if (mode == 2 || mode == 0x11 || mode == 0x12) {
        u8 *m = D_1A4BE0;
        if (*(s16 *)(m + 0x1DE) == 0 && (*(s16 *)(m + 0x36C) == 0 || *(f32 *)(m + 0x33C) < 2.5f)) {
            *(u8 *)(m + 0x1479) = 1;
            if (*(u8 *)(m + 0x25E4) == 0 && D_00142CAD[0] != 0)
                *(s16 *)(m + 0x368) = 1;
        }
    }
    if (mode == 0x11) {
        u8 *h = D_1A4BE0;
        if (*(s16 *)(h + 0x1DC) == 0 && *(s16 *)(h + 0x36C) == 0) {
            if (*(s32 *)(h + 0x25CC) != 7) {
                func_L01_004DC1C0(D_00142668[0] / 8);
                *(s16 *)(h + 0x1DC) = 0x5A;
                func_L08_004D8D78(0xB1, 1);
            }
        }
    }
    if (mode == 0xE) {
        u8 *h = D_1A4BE0;
        *(u8 *)(h + 0x1476) = 1;
        *(f32 *)(h + 0x2848) = 0.2f;
        *(f32 *)(h + 0x350) = *(f32 *)(h + 0x338) + 0.2f;
    }
    if (mode == 0) {
        f32 d;
        u8 *h = D_1A4BE0;
        d = *(f32 *)(h + 0x350) - *(f32 *)(h + 0x338);
        *(f32 *)(h + 0x2848) = d;
        if (d < 0.85f && d > 0.25f)
            *(u8 *)(h + 0x25EA) = 1;
        h = D_1A4BE0;
        *(u8 *)(h + 0x1476) = 1;
    }
    if (mode == 8 || mode == 0x12) {
        u8 *h = D_1A4BE0;
        *(u8 *)(h + 0x147C) = 1;
    }
    if (mode == 0xC) {
        u8 *h = D_1A4BE0;
        *(u8 *)(h + 0x147C) = 1;
    }
}
/* localdecomp:end func_L08_004C5898 */
