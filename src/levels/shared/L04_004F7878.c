#include "common.h"

/* localdecomp:start func_L04_004F7878 */
extern u8 D_001A4BE0[];
extern s32 D_00142668[];
extern u8 D_00142CAD[];
extern void func_0038CBA0(void *, s32);
extern void func_L01_004DFEA0(s32);
extern void func_L01_004E7C88(void);
extern s32 func_L04_0050CB28(s32, s32);

/* from func_L19_004DC2E8 (rac3), func_L08_004C9B28 and func_L09_005012D8 */
void func_L04_004F7878(void)
{
    u8 *p = D_001A4BE0;
    s16 mode = *(s16 *)(p + 0x1470);
    u8 keep = *(u8 *)(p + 0x147F);
    s32 active;
    func_0038CBA0(p + 0x1470, 16);
    *(u8 *)(p + 0x147F) = keep;
    *(s16 *)(p + 0x1470) = mode;
    *(u8 *)(p + 0x25EA) = 0;
    *(s16 *)(p + 0x368) = 0;
    if (*(u8 *)(p + 0x25EE) != 0)
        return;
    active = 0;
    if (*(s32 *)(p + 0x360) != 0 || (*(s32 *)(p + 0x25C4) == 0x80 && *(f32 *)(p + 0x33C) < 0.4f))
        active = 1;
    if (mode == -1)
        return;
    if (mode == 2 || mode == 0x11 || mode == 0x12) {
        u8 *m = D_001A4BE0;
        if (*(s16 *)(m + 0x1DE) == 0 && (*(s16 *)(m + 0x36C) == 0 || *(f32 *)(m + 0x33C) < 2.5f)) {
            *(u8 *)(m + 0x1479) = 1;
            if (*(u8 *)(m + 0x25E4) == 0 && D_00142CAD[0] != 0)
                *(s16 *)(m + 0x368) = 1;
        }
    }
    if (mode == 0x11) {
        u8 *h = D_001A4BE0;
        if (*(s16 *)(h + 0x1DC) == 0 && *(s16 *)(h + 0x36C) == 0) {
            if (*(s32 *)(h + 0x25CC) != 7) {
                func_L01_004DFEA0(D_00142668[0] / 8);
                *(s16 *)(h + 0x1DC) = 0x4B;
                func_L04_0050CB28(0xB1, 1);
            }
        }
    }
    if (mode == 0xE) {
        u8 *h = D_001A4BE0;
        *(u8 *)(h + 0x1476) = 1;
        *(f32 *)(h + 0x2848) = 0.2f;
        *(f32 *)(h + 0x350) = *(f32 *)(h + 0x338) + 0.2f;
    }
    if (mode == 0) {
        f32 d;
        u8 *h = D_001A4BE0;
        d = *(f32 *)(h + 0x350) - *(f32 *)(h + 0x338);
        *(f32 *)(h + 0x2848) = d;
        if (d < 0.85f && d > 0.25f)
            *(u8 *)(h + 0x25EA) = 1;
        h = D_001A4BE0;
        *(u8 *)(h + 0x1476) = 1;
    }
    if (mode == 3) {
        u8 *h = D_001A4BE0;
        *(u8 *)(h + 0x1478) = 1;
    }
    if (mode == 0xB) {
        u8 *h = D_001A4BE0;
        *(u8 *)(h + 0x147D) = 1;
    }
    if (mode == 8 || mode == 0x12) {
        u8 *h = D_001A4BE0;
        *(u8 *)(h + 0x147C) = 1;
    }
    if (mode == 0xC) {
        u8 *h = D_001A4BE0;
        *(u8 *)(h + 0x147C) = 1;
    }
    {
        u8 *h = D_001A4BE0;
        if (*(u8 *)(h + 0x1478) != 0 && *(s32 *)(h + 0x25C4) != 0x6A) {
            s32 c = *(s32 *)(h + 0x25C4);
            if (c != 0x7D) {
                f32 a = *(f32 *)(h + 0x88);
                f32 b = *(f32 *)(h + 0x354);
                if (__builtin_fabsf(b - (a + 0.25f)) < 1.0f && 0.0f < b - a) {
                    if (!(c == 0x6B && *(u8 *)(h + 0x46E) == 0) && (*(f32 *)(h + 0x118) < 0.0f || c == 0x80)) {
                        func_L01_004E7C88();
                        if (*(s32 *)(h + 0x2850) == 0) {
                            func_L04_0050CB28(0x7D, 1);
                            return;
                        }
                        func_L04_0050CB28(0x6A, 1);
                        return;
                    }
                }
            }
        }
    }
    {
        u8 *h = D_001A4BE0;
        if (*(u8 *)(h + 0x147D) != 0 && *(s32 *)(h + 0x25C4) != 0x7D && *(s32 *)(h + 0x25C4) != 0x79) {
            f32 a = *(f32 *)(h + 0x88);
            f32 b = *(f32 *)(h + 0x354);
            if (__builtin_fabsf(b - (a + 0.25f)) < 1.0f && 0.0f < b - a && (*(f32 *)(h + 0x118) < 0.0f || *(s32 *)(h + 0x25C4) == 0x80)) {
                func_L01_004E7C88();
                func_L04_0050CB28(0x7D, 1);
            }
        }
    }
}
/* localdecomp:end func_L04_004F7878 */
