#include "common.h"

/* NTSC-U counterpart of func_L01_0039F0F8 (src/levels/shared/L01_0039E1B0.c) */
#include "vu0.h"

/* localdecomp:start func_L01_0039DB60 */
extern s32 D_L01_001DB02C_0039DB60;
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA80_0039DB60[];
extern s32 D_L01_001D673C_0039DB60_b;
extern s32 D_L01_001D6740_0039DB60_b;
extern s32 D_L01_001D673C_0039DB60;
extern s32 D_L01_001D6740_0039DB60;
__asm__(".extern D_L01_001D673C_0039DB60, 4");
__asm__(".extern D_L01_001DB02C_0039DB60, 16");
__asm__(".extern D_L01_001D673C_0039DB60_b, 16");
__asm__(".extern D_L01_001D6740_0039DB60_b, 16");
__asm__(".extern D_L01_001D6740_0039DB60, 4");

extern void func_00388E38(void *, void *);
extern void func_003BF360(void *, void *);
extern void func_L01_004493C0(u8 *, s32, void *, void *, void *, void *);
extern void func_00388BD0(void *, void *);
extern void *func_L01_00444358(u8 *, s32, s32);
extern s32 func_00388398(void *);
extern void func_L01_0039E8A0(u8 *);
extern void func_L01_00444070(u8 *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_004424B0(u8 *, f32, f32, void *, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_0039FE80(s32, s32, u8 *);
extern void func_L01_0039EF18(u8 *);
extern s32 func_L01_004425F0(u8 *, void *, void *, f32, f32, f32, f32, s32);
extern u8 *func_L01_0044CD90(void *, s32, f32, f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BE860(void *, void *, f32, s32, s32);
extern s32 func_003D00C0(void);
extern void func_L01_003D2870(u8 *);
extern void func_L01_0044E010(u8 *, void *, s32);
extern s32 func_003CE740(void *, void *, s32, u8 *, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);

void func_L01_0039DB60(u8 *self) {
    struct { vu0_v4 a, b, c, d, e, g; } L;
    u8 *h;
    u8 *t;
    f32 d;
    u8 *rec = *(u8 **)(self + 0x68);
    f32 ang;
    f32 f;
    s32 r;
    void *p;

    if (self[0x20] != 0 && D_L01_001DB02C_0039DB60 != 0) {
        func_00388E38(&L.c, self + 0xC0);
        func_003BF360(&L.c, &L.a);
        func_L01_004493C0(self, D_L01_001DB02C_0039DB60, self + 0x10, &L.a, self + 0x10, &L.b);
        func_00388BD0(self + 0xC0, &L.b);
        *(vu0_q *)(self + 0xF0) = *(vu0_q *)&L.b;
    }
    p = func_L01_00444358(self, 0x8010000, 0);
    if ((func_00388398(rec + 0xA8) && D_L01_001D673C_0039DB60) || p != 0) {
        func_L01_0039E8A0(self);
    }
    func_L01_00444070(self, 0.400000006f);
    h = D_001A4BE0;
    *(s32 *)(rec + 0x98) += 1;
    ang = func_00388A28(*(f32 *)(self + 0x10) - *(f32 *)(h + 0x80),
                        *(f32 *)(self + 0x14) - *(f32 *)(h + 0x84));
    switch (self[0x20]) {
    case 1:
        if (self[0x60] & 2) {
            ang = func_0037E250(0.0f, 100.0f);
            if (0.0f <= ang && ang < 10.0f) func_003BE4F0(self, 0, 0, 10);
            if (10.0f <= ang && ang < 20.0f) func_003BE4F0(self, 1, 0, 10);
            if (20.0f <= ang && ang < 40.0f) func_003BE4F0(self, 2, 0, 10);
            if (40.0f <= ang && ang < 100.0f && D_L01_001D6740_0039DB60 == 0 && D_L01_001D673C_0039DB60_b == 0) {
                *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
                t = func_L01_0044CD90(&L.c, 0, 1.57079637f, 999.0f, -1.0f, -1.0f);
                *(u8 **)(rec + 0x9C) = t;
                if (t != 0) {
                    func_L01_00441FB8(self, 8, -1);
                    func_003BE4F0(self, 4, 0, 1);
                    *(f32 *)(self + 0x48) = 1.0f;
                }
            }
        }
        if (func_00388800(self + 0x10, D_001A4BE0 + 0x80) < 2.0f && D_L01_001D6740_0039DB60 == 0 && D_L01_001D673C_0039DB60 == 0) {
            func_L01_00441FB8(self, 2, -1);
            func_003BE4F0(self, 4, 0, 1);
            *(f32 *)(self + 0x48) = 1.0f;
        }
        if (func_00388398(rec + 0x90)) {
            if (D_L01_001D6740_0039DB60 != 0) return;
            if (D_L01_001D673C_0039DB60_b == 0) {
                if (func_0037E1D8(2)) {
                    func_L01_00441FB8(self, 5, -1);
                    *(s32 *)(rec + 0x90) = func_0037E208(400, 600);
                    func_003BE4F0(self, 3, 0, 10);
                } else {
                    func_L01_00441FB8(self, 6, -1);
                    *(s32 *)(rec + 0x90) = func_0037E208(180, 360);
                    func_003BE4F0(self, 4, 0, 10);
                }
            }
        }
        break;
    case 8:
        t = *(u8 **)(rec + 0x9C);
        d = func_00388A28(*(f32 *)(t + 0x10) - *(f32 *)(self + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(self + 0x14));
        func_L01_004424B0(self, d, 0.00021816617f, rec + 0x78, 0.00043633234f, 0.017453294f);
        func_00388830(&L.b, self + 0xC0, 0.041666668f);
        vec_add_ba(&L.a, self + 0x10, &L.b);
        if (func_00388398(rec + 0xA0)) {
            func_0039FE80(0, 0, self);
            func_L01_0039EF18(self);
        }
        if (!func_L01_004425F0(self, self + 0x10, &L.a, 0.5f, 0.6f, 0.25f, 0.52359879f, 0))
            func_L01_0039E8A0(self);
        break;
    case 6:
        if (self[0x60] & 2) func_003BE4F0(self, 4, 0, 10);
        if (func_00388398(rec + 0x90)) {
            func_L01_00441FB8(self, 1, -1);
            *(s32 *)(rec + 0x90) = func_0037E208(120, 600);
            func_003BE4F0(self, func_0037E1D8(2), 0, 10);
        }
        break;
    case 5:
        if (self[0x60] & 2) func_003BE4F0(self, 3, 0, 2);
        if (func_00388800(self + 0x10, D_001A4BE0 + 0x80) < 2.0f) {
            func_L01_00441FB8(self, 2, -1);
            func_003BE4F0(self, 4, 0, 1);
        }
        if (func_00388398(rec + 0x90)) {
            func_L01_00441FB8(self, 1, -1);
            *(s32 *)(rec + 0x90) = func_0037E208(400, 600);
        }
        f = func_0037E250(-30.0f, 30.0f);
        func_L01_004424B0(self, func_00389380(*(f32 *)(self + 0xF8), f * 0.0174532924f), 0.00014544411f, rec + 0x78, 0.00043633234f, 0.013089971f);
        func_00388830(&L.b, self + 0xC0, 0.004166667f);
        vec_add_ba(&L.a, self + 0x10, &L.b);
        if (!func_L01_004425F0(self, self + 0x10, &L.a, 0.1f, 0.5f, 0.25f, 0.52359879f, 0)) {
            f = func_0037E250(20.0f, 135.0f);
            func_L01_004424B0(self, func_00389380(*(f32 *)(self + 0xF8), f * 0.0174532924f), 4.8481368e-05f, rec + 0x78, 0.00043633234f, 0.013089971f);
        }
        break;
    case 2:
        *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
        t = func_L01_0044CD90(&L.c, 0, 1.57079637f, 999.0f, -1.0f, -1.0f);
        *(u8 **)(rec + 0x9C) = t;
        if (t != 0) {
            d = func_00388A28(*(f32 *)(t + 0x10) - *(f32 *)(self + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(self + 0x14));
            func_L01_004424B0(self, d, 0.00021816617f, rec + 0x78, 0.00043633234f, 0.017453294f);
            func_00388830(&L.b, self + 0xC0, 0.041666668f);
            vec_add_ba(&L.a, self + 0x10, &L.b);
        }
        if (!func_L01_004425F0(self, self + 0x10, &L.a, 0.5f, 0.6f, 0.25f, 0.52359879f, 0)) {
            func_L01_0039E8A0(self);
        } else if (func_00389468(ang, *(f32 *)(self + 0xF8)) > 0.52359879f) {
            func_L01_004424B0(self, ang, 0.00038785095f, rec + 0x78, 0.00043633234f, 0.013089971f);
        }
        break;
    case 10:
        func_003BE860(self + 0x10, self + 0x10, 0.5f, 0, 0);
        r = func_003D00C0();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039DB60 == 0) {
            func_L01_003D2870(self);
            return;
        }
    case 0:
        func_L01_00441FB8(self, 1, -1);
        break;
    case 4:
        func_L01_0044E010(self, &L.c, 0);
        func_00388830(&L.c, &L.c, 4.0f);
        vec_add_ba(&L.d, self + 0x10, &L.c);
        func_00388830(&L.c, &L.c, -1.0f);
        vec_add_ba(&L.e, self + 0x10, &L.c);
        if (func_003CE740(&L.e, &L.d, 0, self, 0)) {
            u8 *h2 = D_001A4BE0;
            u8 *q = D_L01_001EAA80_0039DB60;
            if (*(s32 *)(q + 0x18) != *(s32 *)(h2 + 0x25C0)) {
                *(vu0_q *)(self + 0x10) = *(vu0_q *)(q + 0x20);
            }
        }
        r = func_003D00C0();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039DB60 == 0) {
            func_L01_0039E8A0(self);
            return;
        }
        func_L01_00441FB8(self, 1, -1);
        break;
    }
    if (D_L01_001D6740_0039DB60_b == 0 && D_L01_001D673C_0039DB60_b == 0) {
        *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
        *(f32 *)((u8 *)&L.c + 8) += 0.5f;
        *(f32 *)(self + 0x18) = func_003BE7F0(&L.c, 0, 0, 0.5f);
        r = func_003D00C0();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039DB60 == 0) func_L01_0039E8A0(self);
    }
}
/* localdecomp:end func_L01_0039DB60 */
