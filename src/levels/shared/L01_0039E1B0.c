#include "common.h"
#include "vu0.h"

typedef void (*fn_3A2780)(u8 *);

INCLUDE_ASM("asm/levels", func_L01_0039E1B0);

LINKER_REMNANT("asm/levels", func_L01_0039F0F0);

/* localdecomp:start func_L01_0039F0F8 */
extern s32 D_L01_001DAFEC_0039F0F8;
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA00_0039F0F8[];
extern s32 D_L01_001D673C_0039F0F8_b;
extern s32 D_L01_001D6740_0039F0F8_b;
extern s32 D_L01_001D673C_0039F0F8;
extern s32 D_L01_001D6740_0039F0F8;
__asm__(".extern D_L01_001D673C_0039F0F8, 4");
__asm__(".extern D_L01_001DAFEC_0039F0F8, 16");
__asm__(".extern D_L01_001D673C_0039F0F8_b, 16");
__asm__(".extern D_L01_001D6740_0039F0F8_b, 16");
__asm__(".extern D_L01_001D6740_0039F0F8, 4");

extern void func_0038D570(void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_L01_0044C638(u8 *, s32, void *, void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void *func_L01_00447490(u8 *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0039FEB0(u8 *);
extern void func_L01_004471A8(u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004455E8(u8 *, f32, f32, void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_003A0528(u8 *);
extern s32 func_L01_00445728(u8 *, void *, void *, f32, f32, f32, f32, s32);
extern u8 *func_L01_00450010(void *, s32, f32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C3DA0(void *, void *, f32, s32, s32);
extern s32 func_003D5630(void);
extern void func_L01_003D42D0(u8 *);
extern void func_L01_00451290(u8 *, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L01_0039F0F8(u8 *self) {
    struct { vu0_v4 a, b, c, d, e, g; } L;
    u8 *h;
    u8 *t;
    f32 d;
    u8 *rec = *(u8 **)(self + 0x68);
    f32 ang;
    f32 f;
    s32 r;
    void *p;

    if (self[0x20] != 0 && D_L01_001DAFEC_0039F0F8 != 0) {
        func_0038D570(&L.c, self + 0xC0);
        func_003C48A8(&L.c, &L.a);
        func_L01_0044C638(self, D_L01_001DAFEC_0039F0F8, self + 0x10, &L.a, self + 0x10, &L.b);
        func_0038D308(self + 0xC0, &L.b);
        *(vu0_q *)(self + 0xF0) = *(vu0_q *)&L.b;
    }
    p = func_L01_00447490(self, 0x8010000, 0);
    if ((func_0038CAD0(rec + 0xA8) && D_L01_001D673C_0039F0F8) || p != 0) {
        func_L01_0039FEB0(self);
    }
    func_L01_004471A8(self, 0.400000006f);
    h = D_001A4BE0;
    *(s32 *)(rec + 0x98) += 1;
    ang = func_0038D160(*(f32 *)(self + 0x10) - *(f32 *)(h + 0x80),
                        *(f32 *)(self + 0x14) - *(f32 *)(h + 0x84));
    switch (self[0x20]) {
    case 1:
        if (self[0x60] & 2) {
            ang = func_003824E0(0.0f, 100.0f);
            if (0.0f <= ang && ang < 10.0f) func_003C3A10(self, 0, 0, 8);
            if (10.0f <= ang && ang < 20.0f) func_003C3A10(self, 1, 0, 8);
            if (20.0f <= ang && ang < 40.0f) func_003C3A10(self, 2, 0, 8);
            if (40.0f <= ang && ang < 100.0f && D_L01_001D6740_0039F0F8 == 0 && D_L01_001D673C_0039F0F8_b == 0) {
                *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
                t = func_L01_00450010(&L.c, 0, 1.57079637f, 999.0f, -1.0f, -1.0f);
                *(u8 **)(rec + 0x9C) = t;
                if (t != 0) {
                    func_L01_004450F0(self, 8, -1);
                    func_003C3A10(self, 4, 0, 1);
                    *(f32 *)(self + 0x48) = 1.0f;
                }
            }
        }
        if (func_0038CF38(self + 0x10, D_001A4BE0 + 0x80) < 2.0f && D_L01_001D6740_0039F0F8 == 0 && D_L01_001D673C_0039F0F8 == 0) {
            func_L01_004450F0(self, 2, -1);
            func_003C3A10(self, 4, 0, 1);
            *(f32 *)(self + 0x48) = 1.0f;
        }
        if (func_0038CAD0(rec + 0x90)) {
            if (D_L01_001D6740_0039F0F8 != 0) return;
            if (D_L01_001D673C_0039F0F8_b == 0) {
                if (func_00382468(2)) {
                    func_L01_004450F0(self, 5, -1);
                    *(s32 *)(rec + 0x90) = (func_00382498(400, 600) * 5 + 2) / 6;
                    func_003C3A10(self, 3, 0, 8);
                } else {
                    func_L01_004450F0(self, 6, -1);
                    *(s32 *)(rec + 0x90) = (func_00382498(180, 360) * 5 + 2) / 6;
                    func_003C3A10(self, 4, 0, 8);
                }
            }
        }
        break;
    case 8:
        t = *(u8 **)(rec + 0x9C);
        d = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(self + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(self + 0x14));
        func_L01_004455E8(self, d, 0.00031415929f, rec + 0x78, 0.000628318579f, 0.0209439527f);
        func_0038CF68(&L.b, self + 0xC0, 0.0500000045f);
        vec_add_ba(&L.a, self + 0x10, &L.b);
        if (func_0038CAD0(rec + 0xA0)) {
            func_003A52A0(0, 0, self);
            func_L01_003A0528(self);
        }
        if (!func_L01_00445728(self, self + 0x10, &L.a, 0.5f, 0.6f, 0.25f, 0.52359879f, 0))
            func_L01_0039FEB0(self);
        break;
    case 6:
        if (self[0x60] & 2) func_003C3A10(self, 4, 0, 8);
        if (func_0038CAD0(rec + 0x90)) {
            func_L01_004450F0(self, 1, -1);
            *(s32 *)(rec + 0x90) = (func_00382498(120, 600) * 5 + 2) / 6;
            func_003C3A10(self, func_00382468(2), 0, 8);
        }
        break;
    case 5:
        if (self[0x60] & 2) func_003C3A10(self, 3, 0, 2);
        if (func_0038CF38(self + 0x10, D_001A4BE0 + 0x80) < 2.0f) {
            func_L01_004450F0(self, 2, -1);
            func_003C3A10(self, 4, 0, 1);
        }
        if (func_0038CAD0(rec + 0x90)) {
            func_L01_004450F0(self, 1, -1);
            *(s32 *)(rec + 0x90) = (func_00382498(400, 600) * 5 + 2) / 6;
        }
        f = func_003824E0(-30.0f, 30.0f);
        func_L01_004455E8(self, func_0038DAB8(*(f32 *)(self + 0xF8), f * 0.0174532924f), 0.000209439531f, rec + 0x78, 0.000628318579f, 0.0157079641f);
        func_0038CF68(&L.b, self + 0xC0, 0.00500000035f);
        vec_add_ba(&L.a, self + 0x10, &L.b);
        if (!func_L01_00445728(self, self + 0x10, &L.a, 0.1f, 0.5f, 0.25f, 0.52359879f, 0)) {
            f = func_003824E0(20.0f, 135.0f);
            func_L01_004455E8(self, func_0038DAB8(*(f32 *)(self + 0xF8), f * 0.0174532924f), 6.98131698e-05f, rec + 0x78, 0.000628318579f, 0.0157079641f);
        }
        break;
    case 2:
        *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
        t = func_L01_00450010(&L.c, 0, 1.57079637f, 999.0f, -1.0f, -1.0f);
        *(u8 **)(rec + 0x9C) = t;
        if (t != 0) {
            d = func_0038D160(*(f32 *)(t + 0x10) - *(f32 *)(self + 0x10), *(f32 *)(t + 0x14) - *(f32 *)(self + 0x14));
            func_L01_004455E8(self, d, 0.00031415929f, rec + 0x78, 0.000628318579f, 0.0209439527f);
            func_0038CF68(&L.b, self + 0xC0, 0.0500000045f);
            vec_add_ba(&L.a, self + 0x10, &L.b);
        }
        if (!func_L01_00445728(self, self + 0x10, &L.a, 0.5f, 0.6f, 0.25f, 0.52359879f, 0)) {
            func_L01_0039FEB0(self);
        } else if (func_0038DBA0(ang, *(f32 *)(self + 0xF8)) > 0.52359879f) {
            func_L01_004455E8(self, ang, 0.000558505359f, rec + 0x78, 0.000628318579f, 0.0157079641f);
        }
        break;
    case 10:
        func_003C3DA0(self + 0x10, self + 0x10, 0.5f, 0, 0);
        r = func_003D5630();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039F0F8 == 0) {
            func_L01_003D42D0(self);
            return;
        }
    case 0:
        func_L01_004450F0(self, 1, -1);
        break;
    case 4:
        func_L01_00451290(self, &L.c, 0);
        func_0038CF68(&L.c, &L.c, 4.0f);
        vec_add_ba(&L.d, self + 0x10, &L.c);
        func_0038CF68(&L.c, &L.c, -1.0f);
        vec_add_ba(&L.e, self + 0x10, &L.c);
        if (func_003D3CB0(&L.e, &L.d, 0, self, 0)) {
            u8 *h2 = D_001A4BE0;
            u8 *q = D_L01_001EAA00_0039F0F8;
            if (*(s32 *)(q + 0x18) != *(s32 *)(h2 + 0x25C0)) {
                *(vu0_q *)(self + 0x10) = *(vu0_q *)(q + 0x20);
            }
        }
        r = func_003D5630();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039F0F8 == 0) {
            func_L01_0039FEB0(self);
            return;
        }
        func_L01_004450F0(self, 1, -1);
        break;
    }
    if (D_L01_001D6740_0039F0F8_b == 0 && D_L01_001D673C_0039F0F8_b == 0) {
        *(vu0_q *)&L.c = *(vu0_q *)(self + 0x10);
        *(f32 *)((u8 *)&L.c + 8) += 0.5f;
        *(f32 *)(self + 0x18) = func_003C3D30(&L.c, 0, 0, 0.5f);
        r = func_003D5630();
        if (r > 0 && r != 10 && r != 7 && D_L01_001D6740_0039F0F8 == 0) func_L01_0039FEB0(self);
    }
}
/* localdecomp:end func_L01_0039F0F8 */

INCLUDE_ASM("asm/levels", func_L01_0039FBD0);

INCLUDE_ASM("asm/levels", func_L01_0039FEB0);
