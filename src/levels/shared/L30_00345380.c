#include "common.h"

/* localdecomp:start func_L30_00345380 */
__asm__(".extern D_L30_001DF2C0, 16");
extern s32 D_L30_001DF2C0;
__asm__(".extern D_L30_001DCF18, 4");
extern s32 D_L30_001DCF18;
__asm__(".extern D_L30_001DCF1C, 4");
extern s32 D_L30_001DCF1C;
__asm__(".extern D_L30_001DCF20, 4");
extern s32 D_L30_001DCF20;
__asm__(".extern D_L30_001DCF24, 4");
extern s32 D_L30_001DCF24;
__asm__(".extern D_L30_001DCF28, 4");
extern s32 D_L30_001DCF28;
extern u8 D_001A30B0[];
extern s32 func_L01_00451CD8(s32, s32, s32, s32);
extern s32 func_L05_00328FF8(u8 *);
extern void func_003A52A0(s32, s32, u8 *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L30_00343798(u8 *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003A4F28(s32);

void func_L30_00345380(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 t = (D_L30_001DF2C0 + *(s32 *)(v + 0x188)) % ((*(s32 *)(v + 0x17C) + *(s32 *)(v + 0x18C)) * 2);
    s32 a = func_L01_00451CD8(D_L30_001DF2C0, D_L30_001DCF28, D_L30_001DCF18, D_L30_001DCF1C);
    s32 b = func_L01_00451CD8(D_L30_001DF2C0, D_L30_001DCF28, D_L30_001DCF20, D_L30_001DCF24);

    if (v[0x1B8] == 0 && func_L05_00328FF8(a0)) {
        if (*(s16 *)(a0 + 0xAA) == 0x1745) {
            func_003A52A0(0, 0, a0);
        }
        if (*(s16 *)(a0 + 0xAA) == 0x19B9) {
            func_003A52A0(4, 0, a0);
        }
    }

    if (t < *(s32 *)(v + 0x17C)) {
        *(f32 *)(v + 0x160) = func_L03_0034B148(*(s32 *)(v + 0x17C) - t, *(s32 *)(v + 0x17C), 0.0f);
        func_L30_00343798(a0, func_0038D0B0(*(f32 *)(v + 0x160) * 3.1415927f + -1.5707964f) * 0.5f + 0.5f);
        if (*(s16 *)(a0 + 0xAA) == 0x1AEF) {
            s32 h = *(s32 *)(v + 0x1A0);
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(0, 4, a0);
            }
        }
        if (*(s16 *)(a0 + 0xAA) == 0x19B7) {
            s32 h = *(s32 *)(v + 0x1A0);
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(1, 4, a0);
            }
            *(s32 *)(a0 + 0x78) = func_0038DBD8(a, b, *(f32 *)(v + 0x160));
        }
        if (*(s16 *)(a0 + 0xAA) == 0x19B9) {
            s32 h = *(s32 *)(v + 0x1A0);
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(0, 4, a0);
            }
        }
        if (*(s16 *)(a0 + 0xAA) == 0x1745) {
            if (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) >= 0.99f) {
                if (v[0x1B1] == 0 || *(s32 *)(v + 0x19C) != 0) {
                    s32 h = *(s32 *)(v + 0x1A0);
                    u8 *e;
                    if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                        *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(4, 4, a0);
                    }
                }
            }
        }
        return;
    }
    t -= *(s32 *)(v + 0x17C);
    if (t < *(s32 *)(v + 0x18C)) {
        *(f32 *)(v + 0x160) = func_L03_0034B148(*(s32 *)(v + 0x18C) - t, *(s32 *)(v + 0x18C), 0.0f);
        func_L30_00343798(a0, 1.0f);
        if (*(s16 *)(a0 + 0xAA) == 0x19B7 || *(s16 *)(a0 + 0xAA) == 0x19B9 ||
            *(s16 *)(a0 + 0xAA) == 0x1745 || *(s16 *)(a0 + 0xAA) == 0x1AEF) {
            s32 h = *(s32 *)(v + 0x1A0);
            u8 *e;
            if (h != -1 && (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) == a0) && e[0xD0] != 0) {
                func_003A4F28(h);
            }
            *(s32 *)(v + 0x1A0) = -1;
            *(s32 *)(a0 + 0x78) = b;
        }
        return;
    }
    t -= *(s32 *)(v + 0x18C);
    if (t < *(s32 *)(v + 0x17C)) {
        *(f32 *)(v + 0x160) = func_L03_0034B148(*(s32 *)(v + 0x17C) - t, *(s32 *)(v + 0x17C), 0.0f);
        func_L30_00343798(a0, func_0038D0B0(1.5707964f - *(f32 *)(v + 0x160) * 3.1415927f) * 0.5f + 0.5f);
        if (*(s16 *)(a0 + 0xAA) == 0x1AEF) {
            s32 h = *(s32 *)(v + 0x1A0);
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(0, 4, a0);
            }
        }
        if (*(s16 *)(a0 + 0xAA) == 0x19B7) {
            s32 h = *(s32 *)(v + 0x1A0);
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(0, 4, a0);
            }
            *(s32 *)(a0 + 0x78) = func_0038DBD8(b, a, *(f32 *)(v + 0x160));
        }
        if (*(s16 *)(a0 + 0xAA) == 0x19B9) {
            s32 h = *(s32 *)(v + 0x1A0);
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(0, 4, a0);
            }
        }
        if (*(s16 *)(a0 + 0xAA) == 0x1745) {
            if (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) >= 0.99f) {
                s32 h = *(s32 *)(v + 0x1A0);
                u8 *e;
                if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                    *(s32 *)(v + 0x1A0) = ((s32 (*)(s32, s32, u8 *))func_003A52A0)(4, 4, a0);
                }
            }
        }
        return;
    }
    t -= *(s32 *)(v + 0x17C);
    *(f32 *)(v + 0x160) = func_L03_0034B148(*(s32 *)(v + 0x18C) - t, *(s32 *)(v + 0x18C), 0.0f);
    func_L30_00343798(a0, 0.0f);
    if (*(s16 *)(a0 + 0xAA) == 0x19B7 || *(s16 *)(a0 + 0xAA) == 0x19B9 ||
        *(s16 *)(a0 + 0xAA) == 0x1745 || *(s16 *)(a0 + 0xAA) == 0x1AEF) {
        s32 h = *(s32 *)(v + 0x1A0);
        u8 *e;
        if (h != -1 && (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) == a0) && e[0xD0] != 0) {
            func_003A4F28(h);
        }
        *(s32 *)(v + 0x1A0) = -1;
        *(s32 *)(a0 + 0x78) = a;
    }
}
/* localdecomp:end func_L30_00345380 */
